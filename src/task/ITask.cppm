module;

#include <functional>
#include <memory>

export module task:interface;

export class ITask
{
public:
    using ptr = std::shared_ptr<ITask>;
    using delegation_type = std::function<void()>;
    using delegation_cr = const delegation_type&;

    enum TASK_STATUS
    {
        UNKNOWN,
        READY,
        RUNNING,
        FINISHED,
        DISABLED
    };

public:
    virtual ~ITask() = default;
    [[nodiscard]] virtual TASK_STATUS GetStatus() = 0;
    [[nodiscard]] virtual TASK_STATUS Execute() = 0;
    [[nodiscard]] virtual delegation_type What() const = 0;
    virtual void Disable() = 0;
    virtual void Reset() = 0;
    virtual void Reset(delegation_cr func) = 0;
};