module;
#include <memory>
export module thread:interface;

enum THREAD_STATUS
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
    using enum THREAD_STATUS;

public:
    virtual ~IThread() = default;
    virtual void Wait() = 0;
};