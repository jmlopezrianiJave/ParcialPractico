#ifndef FCFS_HPP
#define FCFS_HPP   
#include <algorithm>
#include "Queue.hpp"


class FCFS : public Queue{
    public:
    FCFS();
    FCFS(vector<Process>& p, int* curr);
    void schedule() override;
    void waitIn() override;
    void waitOut() override;
    bool isEmpty() override;
    void tat() override;
    void printQ() override;
    int getAt() override;
};

#endif //FCFS_HPP