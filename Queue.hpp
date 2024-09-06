#ifndef QUEUE_H
#define QUEUE_H
#include <vector>

using namespace std;
#include "Process.hpp"

class Queue{
    protected:
    vector<Process> processes;
    int* currentTime;
    int i;
    bool exec;

    public:
    //contructores
    Queue(){
        i = 0;
    };
    Queue(vector<Process>& i_processes, int* i_currentTime) : processes( i_processes ), currentTime( i_currentTime ){
        i = 0;
    };
    bool isEmpty(){ 
        return i >= processes.size();
    };
    //method defined by subclasses
    virtual void schedule() = 0;
    virtual void waitIn() = 0;
    virtual void waitOut() = 0;
    virtual void tat() = 0;
};

#endif //QUEUE_H