module;

#include <functional>
#include <mutex>

module task;

Task::Task(Task::delegation_cr delegation) : delegation{ delegation }, status{ READY } {}

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