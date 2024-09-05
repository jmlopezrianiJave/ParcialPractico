#ifndef FCFS_H
#define FCFS_H

#include "Queue.hpp"

class FCFS : public Queue {
    public:
        FCFS();
        FCFS(vector<Process>& i_processes) : Queue( i_processes ){};

        void schedule() override;
};

#endif FCFS_H