#include <iostream>
#include <sstream>
#include <fstream>
#include "FCFS.hpp"
#include "RoundRobin.hpp"
#include "MLQ.hpp"
#include "MLFQ.hpp"
#include <string>

using namespace std;
vector<Queue*> q;
vector<Process> p;
int currentTime = 0;

void readFile(){
    ifstream file("prueba2.txt");
    string type, qType;
    int nq, np, quantum;
    Queue* temp;
    file >> qType;
    file >> nq;
    cout << qType << endl;
    if(qType == "MLQ"){
        while(nq--){
            file >> type;
            if(type == "FCFS"){
                file >> np;
                for (int i = 0; i < np; i++) {
                    int pid, bt, at, prio;
                    file >> pid >> at >> bt >> prio;
                    p.push_back(Process(pid, at, bt, prio));
                }
                temp = new FCFS(p, &currentTime);
                q.push_back(temp);
                p.clear();
            }
            else if(type == "RR"){
                file >> np >> quantum;
                for (int i = 0; i < np; i++) {
                    int pid, bt, at, prio;
                    file >> pid >> at >> bt >> prio;
                    p.push_back(Process(pid, at, bt, prio));
                }
                temp = new RoundRobin(p, &currentTime, quantum);
                q.push_back(temp);
                p.clear();
            }

        }
    } else if (qType == "MLFQ"){
        for(int j = 0; j < nq; j++){
            file >> type;
            if(type == "FCFS"){
                temp = new FCFS(&currentTime);
                q.push_back(temp);
            }
            else if(type == "RR"){
                file >> quantum;
                temp = new RoundRobin(&currentTime, quantum);
                q.push_back(temp);
            }
        }
        file >> np;
        for (int i = 0; i < np; i++){
            int pid, bt, at, prio;
            file >> pid >> at >> bt >> prio;
            p.push_back(Process(pid, at, bt, prio));
        }
    }
    
    cout << "Lectura completa.\n" << endl;
    file.close();
}

int main(){
    readFile();
    MLQ test = MLQ(q, &currentTime);
    // MLFQ test = MLFQ(q, p, &currentTime);
    test.schedule();
}