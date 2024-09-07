#include "RoundRobin.hpp"

RoundRobin::RoundRobin() : quantum(1), spent(0){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });
}
RoundRobin::RoundRobin(std::vector<Process>& p, int* curr, int q) : Queue(p, curr), quantum(q), spent(0){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });
        for(int j = 0; j < processes.size(); j++) {
                rrQueue.push(j);
        }
}

void RoundRobin::waitIn() {
    for (int j = 0; j < processes.size(); j++) {
        if (j != i && processes[j].getArrivalTime() <= *currentTime && processes[j].getBurstTime() > 0) {
            processes[j].setWaitTime(processes[j].getWaitTime() + 1);
        }
    }
}

void RoundRobin::waitOut(){
    for ( int j = 0; j < processes.size(); j++ ) {
        if (processes[ j ].getArrivalTime() <= *currentTime && processes[ j ].getBurstTime() > 0) {
            processes[ j ].setWaitTime(processes[ j ].getWaitTime() + 1);
        }
    }
}

void RoundRobin::schedule() {
    i = rrQueue.front();
    
    if(processes[ i ].getBurstTime() == 0 && processes[ i ].getCompletionTime() == -1){
        processes[ i ].setCompletionTime( *currentTime );
        rrQueue.pop();
        spent = 0;
        i = rrQueue.front();
    }else if(spent == quantum || processes[ i ].getArrivalTime() > *currentTime){
        rrQueue.push( rrQueue.front() );
        rrQueue.pop();
        spent = 0;
        i = rrQueue.front();
    }
    
    if(processes[ i ].getResponseTime() == -1){
        processes[ i ].setResponseTime( *currentTime );
    }
    
    processes[ i ].setBurstTime( processes[ i ].getBurstTime() - 1);
    spent++;
    waitIn();
}

void RoundRobin::tat() {
    for (Process& p : processes) {
        p.setTurnAroundTime(p.getCompletionTime() - p.getArrivalTime());
    }
}

void RoundRobin::printQ() {
    for (Process& p : processes) {
        std::cout << p.getProcessID() << ". CT: " << p.getCompletionTime() 
                  << ", WT: " << p.getWaitTime() 
                  << ", RT: " << p.getResponseTime() 
                  << ", TAT: " << p.getTurnAroundTime() << std::endl;
    }
    std::cout << "\n\n" << std::endl;
}

bool RoundRobin::isEmpty(){
    return rrQueue.empty();
}

int RoundRobin::getAt(){
    return processes[i].getArrivalTime();
}