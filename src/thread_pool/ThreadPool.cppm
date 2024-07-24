module;

#include <atomic>
#include <memory>
#include <queue>
#include <shared_mutex>

export module thread_pool;
export import :interface;

export import thread;

export class ThreadPool : virtual public IThreadPool
{
public:
    ThreadPool() = default;
    ~ThreadPool() override = default;

    virtual void Expand(size_t number = 1) override;
    virtual void Shrink(size_t number = 1) override;
    virtual void Stop() override;
    virtual void Terminate() override;
    // todo
    virtual void Pause() override{};
    virtual void Resume() override{};

    void Add(Task::ptr task);
    void Add(Task::delegation_cr task);

private:
    void Job();
    Task::ptr GetNext();

    bool IsStopped() const
    {
        return status == Status::stopped || IsTerminated();
    };

    bool IsTerminated() const
    {
        return status == Status::terminated;
    };

private:
    enum class Status
    {
        ready,
        stopped,
        terminated
    };
    std::atomic<Status> status{ Status::ready };

    std::mutex threads_mtx;
    std::vector<Thread::ptr> threads;

    std::queue<Task::ptr> tasks;
    std::shared_mutex tasks_mtx;
    std::condition_variable_any tasks_cv;
};