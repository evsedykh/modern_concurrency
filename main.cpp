
#include <iostream>
#include <thread>
#include <mutex>

#include "spinlock.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    using WorkerT = Worker<Spinlock>;
    //using WorkerT = Worker<std::mutex>;
    //using WorkerT = Worker<std::string>; // doesn't compile

    WorkerT worker;

    std::jthread t1([&worker]{
        worker.work();
    });
    std::jthread t2([&worker]{
        worker.work();
    });
    return 0;
}
