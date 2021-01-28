#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include <concepts>

template<typename T>
concept SynchronizationDevice =
        requires (T d){
        d.lock();
        d.unlock();
        };

template<SynchronizationDevice Synchro>
class Worker
{
public:
    void work()
    {
        synchro_.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        synchro_.unlock();
    }
private:
    Synchro synchro_;
};

#endif // WORKER_H
