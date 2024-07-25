module;

#include <atomic>
#include <functional>
#include <memory>

export module task;
export import :interface;

export class Task : virtual public ITask
{
public:
    using ptr = std::shared_ptr<Task>;

public:
    explicit Task(delegation_cr delegation);
    Task(const Task& task);
    ~Task() override = default;

    // 通过 ITask 继承
    virtual status_type GetStatus() override;
    virtual status_type Execute() override;
    virtual delegation_type What() const override;
    virtual void Disable() override;
    virtual void Reset() override;
    virtual void Reset(delegation_cr delegation) override;

private:
    delegation_type delegation;
    std::atomic<status_type> status;
};
