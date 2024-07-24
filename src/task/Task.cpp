module;

#include <functional>
#include <mutex>

module task;

Task::Task(delegation_cr delegation)
    : delegation{ delegation }
    , status{ READY }
{
}

Task::Task(const Task& task)
    : Task(task.What())
{
}

Task::TASK_STATUS Task::GetStatus()
{
    return status;
}

Task::TASK_STATUS Task::Execute()
{
    auto expected = READY;
    status.compare_exchange_strong(expected, RUNNING);
    if (expected != READY) return expected == FINISHED ? UNKNOWN : expected;

    delegation();

    status = FINISHED;
    status.notify_all();

    return FINISHED;
}

Task::delegation_type Task::What() const
{
    return delegation;
}

void Task::Disable()
{
    auto expected = READY;
    status.compare_exchange_strong(expected, DISABLED);

    status.wait(RUNNING);
}

void Task::Reset()
{
    status.wait(RUNNING);
    status = READY;
}

void Task::Reset(delegation_cr delegation)
{
    status.wait(RUNNING);
    this->delegation = delegation;
    status = READY;
}