module;
#include <atomic>
#include <thread>
export module thread;
export import :interface;
export import task;

export class Thread : virtual public IThread
{
public:
    using ptr = std::shared_ptr<Thread>;

public:
    explicit Thread(const Task& task);
    explicit Thread(Task::delegation_cr func);

    virtual void Wait() override;

private:
    Task task;
    std::shared_ptr<std::thread> thread;
    std::atomic<status_type> status;
};
