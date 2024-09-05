#include "FCFS.hpp"

void FCFS::schedule(){
    int currentTime = 0;
    for(auto& p : processes){
        p.setStartTime( currentTime );
        p.setResponseTime( currentTime );
        currentTime = currentTime + p.getBurstTime();
        p.setCompletionTime( currentTime );
        p.set
    }
}