module;

#include <atomic>
#include <functional>
#include <memory>

export module task;
export import :interface;

export class Task : virtual public ITask
{
public:
    Task(delegation_cr delegation);

    // 通过 ITask 继承
    virtual TASK_STATUS GetStatus() override;
    virtual TASK_STATUS Execute() override;
    virtual delegation_type What() const override;
    virtual void Reset() override;
    virtual void Reset(delegation_cr delegation) override;

private:
    std::atomic<TASK_STATUS> status;
    delegation_type delegation;
};
