#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

using namespace std;
#include "Process.hpp"

class Queue{
    protected:
    vector<Process> processes;

    public:
    //contructores
    Queue();
    Queue(vector<Process>& i_processes) : processes( i_processes ){};

    //method defined by subclasses
    virtual void schedule() = 0;

    //destructor
    virtual ~Queue();

};

#endif //QUEUE_H