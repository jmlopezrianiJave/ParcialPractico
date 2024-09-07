#ifndef RoundRobin_HPP
#define RoundRobin_HPP   
#include <algorithm>
#include "Queue.hpp"
#include <queue>



class RoundRobin : public Queue{
    public:
        RoundRobin();
        RoundRobin(vector<Process>& p, int* curr, int q);
        void schedule() override;
        void waitIn() override;
        void waitOut() override;
        void tat() override;
        bool isEmpty() override;
        void printQ() override;
        int getAt() override;

    private:
        int quantum;
        int spent;
        queue<int>rrQueue;

};

#endif //RoundRobin_HPP