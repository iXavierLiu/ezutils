module;

#include <memory>

export module thread_pool:interface;

export class IThreadPool
{
public:
    using Ptr = std::shared_ptr<IThreadPool>;

public:
    virtual ~IThreadPool() = default;
    virtual void Expand(size_t number = 1) = 0;
    virtual void Shrink(size_t number = 1) = 0;
    virtual void Stop() = 0;
    virtual void Terminate() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
};