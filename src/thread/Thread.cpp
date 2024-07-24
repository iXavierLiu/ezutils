module;
#include <memory>
module thread;

Thread::Thread(const Task& task)
    : task{ task }
    , thread{ std::make_shared<std::thread>([this]() -> void {
        this->task.Execute();
    }) }
{
}

Thread::Thread(Task::delegation_cr func)
    : Thread(Task(func))
{
}

void Thread::Wait()
{
    if (thread->joinable()) thread->join();
}
