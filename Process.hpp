#ifndef PROCESS_HPP
#define PROCESS_HPP
#include<iostream>

class Process{
    public:
        //Constructors
        Process();
        Process(int processID_i, int arrivalTime_i, int burstTime_i, int priority_i);
        //Getters
        int getProcessID();
        int getArrivalTime() const;
        int getBurstTime();
        int getPriority();
        int getStartTime();
        int getCompletionTime();
        int getWaitTime();
        int getResponseTime();
        int getTurnAroundTime();
        int getLastRun();
        //Setters
        void setProcessID(int id);
        void setArrivalTime(int time);
        void setBurstTime(int time);
        void setPriority(int prio);
        void setStartTime(int time);
        void setCompletionTime(int time);
        void setWaitTime(int time);
        void setResponseTime(int time);
        void setTurnAroundTime(int time);
        void setLastRun(int time);
        

    private:
        //Parameters for runtime
        int processID;
        int arrivalTime;
        int burstTime;
        int priority;
        int lastRun;//int to keep track of time waiting

        //Tickers for stats after excecuting
        int completionTime;
        int waitTime;
        int responseTime;
        int turnAroundTime;
};


#endif //PROCESS_HPP