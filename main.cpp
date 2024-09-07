#include <iostream>
#include <sstream>
#include <fstream>
#include "FCFS.hpp"
#include "RoundRobin.hpp"
#include "MLQ.hpp"
#include <string>

using namespace std;
vector<Process> p;
int currentTime = 0;

void readFile(){
    ifstream file("prueba.txt");
    string line;
    while(getline(file, line)){
        istringstream iss(line);
        int pid, bt, at, prio;
        if (iss >> pid >> bt >> at >> prio) {
            p.push_back(Process(pid, at, bt, prio));
        } else {
            cerr << "Error: Malformed line in file: " << line << endl;
        }
    }
}

int main(){
    readFile();
    vector<Process> p = {
        Process(0, 0, 5, 1),  
        Process(1, 2, 3, 0), 
        Process(2, 4, 2, 2)   
    };
    vector<Process> p1 = {
        Process(0, 1, 4, 3),  
        Process(1, 5, 2, 1),  
        Process(2, 3, 6, 0)  
    };
    vector<Process> p2 = {
        Process(0, 0, 7, 2), 
        Process(1, 1, 5, 3),  
        Process(2, 6, 3, 1)   
    };
    vector<Process> p3 = {
        Process(0, 3, 4, 0),  
        Process(1, 0, 2, 2),  
        Process(2, 5, 1, 1)   
    };
    vector<Process> p4 = {
        Process(0, 0, 6, 1), 
        Process(1, 4, 3, 2),  
        Process(2, 2, 2, 0)   
    };
    vector<Process> p5 = {
        Process(0, 2, 8, 1),  
        Process(1, 0, 3, 0),  
        Process(2, 1, 5, 2)  
    };

    vector<Queue*> t = {new FCFS(p3, &currentTime), new FCFS(p1, &currentTime), new RoundRobin(p4, &currentTime, 3), new RoundRobin(p5, &currentTime, 5) };
    vector<Queue*> t1 = {new RoundRobin(p2, &currentTime, 1), new FCFS(p1, &currentTime), new RoundRobin(p3, &currentTime, 3), new FCFS(p5, &currentTime) };
    vector<Queue*> t2 = {new FCFS(p2, &currentTime), new RoundRobin(p4, &currentTime, 4), new RoundRobin(p4, &currentTime, 3), new RoundRobin(p5, &currentTime, 5) };
    vector<Queue*> t3 = {new FCFS(p3, &currentTime), new FCFS(p1, &currentTime), new FCFS(p4, &currentTime), new FCFS(p5, &currentTime) };
    RoundRobin q = RoundRobin(p, &currentTime, 4);
    MLQ test = MLQ(t, &currentTime);
    test.schedule();
}