#include <iostream>
#include "FCFS.hpp"

int main(){
    vector<Process> p = {Process(0, 7, 10, 0), Process(1, 0, 3, 0), Process(2, 5, 6, 0), Process(3, 6, 8, 0), Process(4, 2, 2, 0)};
    int currentTime = 0;
    FCFS q = FCFS(p, &currentTime);
    q.printQ();
    while(!q.isEmpty()){
        q.schedule();
    }
    q.tat();
    q.printQ();
}