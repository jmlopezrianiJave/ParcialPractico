#ifndef MLQ_HPP
#define MLQ_HPP

#include "Queue.hpp"

class MLQ{
    public:
        MLQ();
        MLQ(vector<Queue*>& colas, int* curr);
        void schedule();
    private:
        vector<Queue*> queues;
        int* currentTime;
        bool isEmpty();
};

#endif //MLQ_HPP