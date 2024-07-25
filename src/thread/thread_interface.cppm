module;
#include <memory>
export module thread:interface;

enum class IThreadStatus
{
    UNKNOWN,
    READY,
    RUNNING,
    FINISHED,
};

export class IThread
{
public:
    using ptr = std::shared_ptr<IThread>;
    using status_type = IThreadStatus;

public:
    virtual ~IThread() = default;
    virtual void Wait() = 0;
};