#include "MLQ.hpp"

MLQ::MLQ(){}
MLQ::MLQ(vector<Queue*>& colas, int* curr) : queues(colas), currentTime(curr){}

bool MLQ::isEmpty(){
    for(int i = 0; i < queues.size(); i++){
      if(!queues[ i ]->isEmpty()){
        return false;
      }
    }
  return true;
}

void MLQ::schedule(){
  int i = 0;
  int flag = -1;
  while(!isEmpty()){
    flag = i;
      if(!queues[ i ]->isEmpty() && queues[i]->getAt() <= *currentTime){
        queues[ i ]->schedule();
        for(int j = 0; j < queues.size(); j++){
          if(!queues[ j ]->isEmpty() && j != i){
            queues[j]->waitOut();
          }
        }
      }
    for(i = 0; i < queues.size(); i++){
      if(!queues[ i ]->isEmpty() && queues[ i ]->getAt() <= *currentTime){
        break;
      }
    }
    if(flag == i){
      *currentTime = *currentTime + 1;
    }
    
    
  }
  for(Queue* q : queues){
    cout << "cola " << q << endl;
    q->tat();
    q->printQ();
  }
}
