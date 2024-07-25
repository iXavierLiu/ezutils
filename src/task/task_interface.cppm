module;

#include <functional>
#include <memory>

export module task:interface;

enum class ITaskStatus
{
    UNKNOWN,
    READY,
    RUNNING,
    FINISHED,
    DISABLED
};

export class ITask
{
public:
    using ptr = std::shared_ptr<ITask>;
    using delegation_type = std::function<void()>;
    using delegation_cr = const delegation_type&;
    using status_type = ITaskStatus;

public:
    virtual ~ITask() = default;
    [[nodiscard]] virtual status_type GetStatus() = 0;
    [[nodiscard]] virtual status_type Execute() = 0;
    [[nodiscard]] virtual delegation_type What() const = 0;
    virtual void Disable() = 0;
    virtual void Reset() = 0;
    virtual void Reset(delegation_cr func) = 0;
};