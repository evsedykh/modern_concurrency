#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <atomic>

class Spinlock
{
public:
    void lock()
    {
        while(flag_.test_and_set());
    }

    void unlock()
    {
        flag_.clear();
    }
private:
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
};

#endif // SPINLOCK_H
