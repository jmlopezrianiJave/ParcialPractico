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
    int quantumQ = -1;
    int spentQ = -1;
    public:
    //contructores
    Queue(){
        i = 0;
    };
    Queue(int* curr) : currentTime(curr){
        i = 0;
    };
    Queue(vector<Process>& i_processes, int* i_currentTime) : processes( i_processes ), currentTime( i_currentTime ){
        i = 0;
    };
    vector<Process> getProcesses(){
        return processes;
    }
    Process getProcess(){
        return processes[ i ];
    }
int getQuantumQ(){
    return quantumQ;
}
int getSpentQ(){
    return spentQ;
}
    virtual bool getType() = 0;
    virtual void addProcess(Process p) = 0;
    virtual void deleteProcess() = 0;
    //method defined by subclasses
    virtual void schedule() = 0;
    virtual void waitIn() = 0;
    virtual void waitOut() = 0;
    virtual void tat() = 0;
    virtual void printQ() = 0;
    virtual bool isEmpty() = 0;
    virtual int getAt() = 0;
    virtual vector<float> getAvg() = 0;
};

#endif //QUEUE_H