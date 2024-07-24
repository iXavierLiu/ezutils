module;

#include <functional>
#include <shared_mutex>

module thread_pool;

void ThreadPool::Expand(size_t number)
{
    std::lock_guard lck(threads_mtx);

    for (size_t i = 0; i < number; ++i)
    {
        threads.emplace_back(std::make_shared<Thread>([this]() -> void { Job(); }));
    }
}

void ThreadPool::Shrink(size_t number)
{
    std::lock_guard lck(threads_mtx);
    // TODO
}

void ThreadPool::Job()
{
    Task::ptr task = nullptr;
    while (true)
    {
        if (task = GetNext(); !task) break;
        task->Execute();
    }
}

void ThreadPool::Stop()
{
    std::lock_guard lck(threads_mtx);

    status = Status::stopped;
    tasks_cv.notify_all();

    for (size_t i = 0; i < threads.size(); ++i)
    {
        threads[i]->Wait();
    }
}

void ThreadPool::Terminate()
{
    std::lock_guard lck(threads_mtx);

    status = Status::terminated;
    tasks_cv.notify_all();

    for (size_t i = 0; i < threads.size(); ++i)
    {
        threads[i]->Wait();
    }
};

Task::ptr ThreadPool::GetNext()
{
    std::unique_lock lck(tasks_mtx);

    tasks_cv.wait(lck, [this]() -> bool { return (!tasks.empty()) || IsStopped(); });

    if (IsTerminated()) return nullptr;

    // stopped (not terminated), the task queue continues
    if (tasks.empty()) return nullptr;
    auto task = tasks.front();
    tasks.pop();
    return task;
}

void ThreadPool::Add(Task::ptr task)
{
    std::unique_lock lck(tasks_mtx);
    tasks.push(task);
    tasks_cv.notify_one();
}

void ThreadPool::Add(Task::delegation_cr task)
{
    Add(std::make_shared<Task>(task));
}