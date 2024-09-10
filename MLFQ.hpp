#ifndef MLFQ_HPP
#define MLFQ_HPP

#include <queue>
#include "Queue.hpp"

class MLFQ{
    public:
    MLFQ();
    MLFQ(vector<Queue*>& colas, vector<Process> p, int* curr);
        void schedule();
    private:
        vector<Queue*> queues;
        vector<Process> process;
        int* currentTime;
        bool isEmpty();
};

#endif //MLFQ_HPP