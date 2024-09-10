#include "RoundRobin.hpp"

RoundRobin::RoundRobin() : quantum(1), spent(0){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });
    quantumQ = 1;
}
RoundRobin::RoundRobin(std::vector<Process>& p, int* curr, int q) : Queue(p, curr), quantum(q), spent(0){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });
    for(int j = 0; j < processes.size(); j++) {
            rrQueue.push(j);
    }
    quantumQ = quantum;
}

RoundRobin::RoundRobin(int* curr, int q) : Queue(curr), quantum(q), spent(0){
    quantumQ = quantum;
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
        spentQ = 0;
        i = rrQueue.front();
    }else if(spent == quantum || processes[ i ].getArrivalTime() > *currentTime){
        rrQueue.push( rrQueue.front() );
        rrQueue.pop();
        spent = 0;
        spentQ = 0;
        i = rrQueue.front();
    }
    
    if(processes[ i ].getResponseTime() == -1){
        processes[ i ].setResponseTime( *currentTime );
    }
    
    processes[ i ].setBurstTime( processes[ i ].getBurstTime() - 1);
    spent++;
    spentQ = spent;
    waitIn();
}

void RoundRobin::tat() {
    for (Process& p : processes) {
        p.setTurnAroundTime(p.getCompletionTime() - p.getArrivalTime());
    }
}

void RoundRobin::printQ() {
    cout << "Round Robin, Quantum = " << quantum << endl;
    for (Process& p : processes) {
        cout << p.getProcessID() 
            << ". CT: " << p.getCompletionTime() 
            << ", WT: " << p.getWaitTime() 
            << ", RT: " << p.getResponseTime() 
            << ", TAT: " << p.getTurnAroundTime() << std::endl;
    }
    float avgCT = 0.0, avgWT = 0.0, avgRT = 0.0, avgTAT = 0.0;
    for (Process& p : processes){
        avgCT += p.getCompletionTime();
        avgWT += p.getWaitTime();
        avgRT += p.getResponseTime();
        avgTAT += p.getTurnAroundTime();
    }
    avgCT = avgCT / processes.size();
    avgWT = avgWT / processes.size();
    avgRT = avgRT / processes.size();
    avgTAT = avgTAT / processes.size();
    cout << endl;
    cout << "Average Completion Time: " << avgCT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;
    cout << "Average Response Time: " << avgRT << endl;
    cout << "Average Turn Around Time: " << avgTAT << endl;
    cout << "\n\n" << std::endl;
}

bool RoundRobin::isEmpty(){
    return rrQueue.empty();
}

int RoundRobin::getAt(){
    return processes[i].getArrivalTime();
}

vector<float> RoundRobin::getAvg(){
    float avgCT = 0.0, avgWT = 0.0, avgRT = 0.0, avgTAT = 0.0;
    for (Process& p : processes){
        avgCT += p.getCompletionTime();
        avgWT += p.getWaitTime();
        avgRT += p.getResponseTime();
        avgTAT += p.getTurnAroundTime();
    }
    cout << endl;
    avgCT = avgCT / processes.size();
    avgWT = avgWT / processes.size();
    avgRT = avgRT / processes.size();
    avgTAT = avgTAT / processes.size();
    vector<float> avg = {avgCT, avgWT, avgRT, avgTAT};
    return avg;
}

void RoundRobin::addProcess(Process p){
    processes.push_back(p);
    rrQueue.push(processes.size() - 1);
}
void RoundRobin::deleteProcess(){
    processes.erase(processes.begin() + i);
    queue<int>temp;
    for(int j = 0; j < processes.size(); j++) {
            temp.push(j);
    }
    rrQueue = temp;
}

bool RoundRobin::getType(){
    return true;
}