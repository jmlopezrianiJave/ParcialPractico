#include "Process.hpp"

Process::Process(){
    startTime = -1;
    completionTime = 0;
    waitTime = 0;
    responseTime = 0;
}

Process::Process(int processID_i, int arrivalTime_i, int burstTime_i, int priority_i) : processID(processID_i), arrivalTime(arrivalTime_i), burstTime(burstTime_i), priority(priority_i){
    startTime = -1;
    completionTime = 0;
    waitTime = 0;
    responseTime = 0;
}

//Getters
int Process::getProcessID(){
    return this->processID;
}

int Process::getArrivalTime(){
    return this->arrivalTime;
}

int Process::getBurstTime(){
    return this->burstTime;
}

int Process::getPriority(){
    return this->priority;
}

int Process::getStartTime()  {
    return this->startTime;
}

int Process::getCompletionTime()  {
    return this->completionTime;
}

int Process::getWaitTime()  {
    return this->waitTime;
}

int Process::getTurnAroundTime()  {
    return this->turnAroundTime;
}

int Process::getResponseTime()  {
    return this->responseTime;
}

//Setters
void Process::setProcessID(int id){
    this->processID = id;
}

void Process::setArrivalTime(int time){
    this->arrivalTime = time;
}

void Process::setBurstTime(int time){
    this->burstTime = time;
}

void Process::setPriority(int prio){
    this->priority = prio;
}

void Process::setStartTime(int time){
    this->startTime = time;
}

void Process::setCompletionTime(int time){
    this->completionTime = time;
}

void Process::setWaitTime(int time){
    this->waitTime = time;
}

void Process::setResponseTime(int time){
    this->responseTime = time;
}

void Process::setTurnAroundTime(int time){
    this->turnAroundTime = time;
}