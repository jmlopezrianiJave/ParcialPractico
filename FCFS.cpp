#include "FCFS.hpp"

FCFS::FCFS(){}
FCFS::FCFS(vector<Process>& p, int* curr) : Queue(p, curr){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime() < b.getArrivalTime();
    });
}
FCFS::FCFS(int* curr) : Queue(curr){}

void FCFS::waitIn(){
    for(int j = 0; j < processes.size(); j++){
        // Process has arrived and is not the current process
        if (j != i && processes[j].getArrivalTime() <= *currentTime && processes[j].getBurstTime() > 0){
            processes[j].setWaitTime(processes[j].getWaitTime() + 1);
        }
    }
}

void FCFS::waitOut(){
    for(int j = 0; j < processes.size(); j++){
        if(processes[j].getArrivalTime() <= *currentTime && processes[j].getBurstTime() > 0){
            processes[ j ].setWaitTime( processes[ j ].getWaitTime() + 1 );
        }
    }
}

void FCFS::schedule(){
    if(processes[ i ].getBurstTime() == 0){
        processes[ i ].setCompletionTime( *currentTime );
        i++;
    }
        if( processes[ i ].getResponseTime() == -1 ){
            processes[ i ].setResponseTime( *currentTime );
        }
        processes[ i ].setBurstTime(processes[ i ].getBurstTime() - 1);
        waitIn();
    
}

void FCFS::tat(){
    for(Process& p : processes){
        p.setTurnAroundTime( p.getCompletionTime() - p.getArrivalTime() );
    }
}

void FCFS::printQ(){
    cout << "First Come First Serve" << endl;
    for(Process& p : processes){
        cout << p.getProcessID() <<".CT: "
            << p.getCompletionTime()<< ", WT: " 
            << p.getWaitTime() << ", RT: " 
            << p.getResponseTime() << ", TAT: " 
            << p.getTurnAroundTime() << endl;
    }
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
    cout << "Average Completion Time: " << avgCT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;
    cout << "Average Response Time: " << avgRT << endl;
    cout << "Average Turn Around Time: " << avgTAT << endl;
    cout << "\n\n" << endl;
}

bool FCFS::isEmpty(){
    return i >= processes.size();
}

int FCFS::getAt(){
    return processes[i].getArrivalTime();
}

vector<float> FCFS::getAvg(){
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

void FCFS::addProcess(Process p){
    processes.push_back(p);
}
void FCFS::deleteProcess(){
    processes.erase(processes.begin() + i);
}

bool FCFS::getType(){
    return false;
}