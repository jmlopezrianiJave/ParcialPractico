#include "MLFQ.hpp"

MLFQ::MLFQ(){}
MLFQ::MLFQ(vector<Queue*>& colas, vector<Process> p, int* curr) : queues(colas), process(p),currentTime(curr){}

bool MLFQ::isEmpty(){
    for(int i = 0; i < process.size(); i++){
      if(process[ i ].getBurstTime() != 0){
        return false;
      }
    }
  return true;
}

void MLFQ::schedule(){
  Process temp;
  for(Process p : process){
    queues[0]->addProcess(p);
  }
  while(!isEmpty()){
    int highestPrio = -1;

    for(int i = 0; i < queues.size(); i++){
      if(!queues[ i ]->isEmpty() && queues[ i ]->getAt() <= *currentTime){
        highestPrio = i;
        break;
      }
    }

    if(highestPrio != -1){
      queues[ highestPrio ]->schedule();
      if(queues[highestPrio]->getProcess().getBurstTime() != 0 && highestPrio != queues.size() - 1){
        if(queues[highestPrio]->getType()){
          if(queues[highestPrio]->getSpentQ() == queues[highestPrio]->getQuantumQ()){
            temp = queues[highestPrio]->getProcess();
            queues[highestPrio]->deleteProcess();
            queues[highestPrio + 1]->addProcess(temp);
          }
        }
        else{
          temp = queues[highestPrio]->getProcess();
          queues[highestPrio]->deleteProcess();
          queues[highestPrio + 1]->addProcess(temp);
        }
      }
      if(queues[ highestPrio ]->isEmpty()){
        continue;
      }
      *currentTime = *currentTime + 1;
      for(int j = 0; j < queues.size(); j++){
        if(j != highestPrio && !queues[ j ]->isEmpty()){
          queues[j]->waitOut();
        }
      }
    }

  }
  
  float avgCT = 0.0, avgWT = 0.0, avgRT = 0.0, avgTAT = 0.0;
  vector<float>avg;
  for(int j = 0; j < queues.size(); j++){
    cout << "Cola #" << j << endl;
    queues[ j ]->tat();
    queues[ j ]->printQ();
    avg = queues[ j ]->getAvg();
    avgCT += avg[ 0 ];
    avgWT += avg[ 1 ];
    avgRT += avg[ 2 ];
    avgTAT += avg[ 3 ];
  }

  avgCT = avgCT / queues.size();
  avgWT = avgWT / queues.size();
  avgRT = avgRT / queues.size();
  avgTAT = avgTAT / queues.size();

  cout << "Averages for MLFQ: " << endl;
  cout << "Average Completion Time: " << avgCT << endl;
  cout << "Average Waiting Time: " << avgWT << endl;
  cout << "Average Response Time: " << avgRT << endl;
  cout << "Average Turn Around Time: " << avgTAT << endl;
}
