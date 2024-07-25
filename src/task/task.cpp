module;

#include <functional>
#include <mutex>

module task;

Task::Task(delegation_cr delegation)
    : delegation{ delegation }
    , status{ status_type::READY }
{
}

Task::Task(const Task& task)
    : Task(task.What())
{
}

Task::status_type Task::GetStatus()
{
    return status;
}

Task::status_type Task::Execute()
{
    auto expected = status_type::READY;
    status.compare_exchange_strong(expected, status_type::RUNNING);
    if (expected != status_type::READY) return expected == status_type::FINISHED ? status_type::UNKNOWN : expected;

    delegation();

    status = status_type::FINISHED;
    status.notify_all();

    return status_type::FINISHED;
}

Task::delegation_type Task::What() const
{
    return delegation;
}

void Task::Disable()
{
    auto expected = status_type::READY;
    status.compare_exchange_strong(expected, status_type::DISABLED);

    status.wait(status_type::RUNNING);
}

void Task::Reset()
{
    status.wait(status_type::RUNNING);
    status = status_type::READY;
}

void Task::Reset(delegation_cr delegation)
{
    status.wait(status_type::RUNNING);
    this->delegation = delegation;
    status = status_type::READY;
}