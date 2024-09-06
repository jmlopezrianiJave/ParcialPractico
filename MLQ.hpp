#ifndef MLQ_HPP
#define MLQ_HPP

#include "Queue.hpp"
#include <map>

class MLQ{
    public:

    private:
    vector<Queue> queues;
    //Stores shceduling algorithm used by each queue. The second value corresponds to quantum if 
    map<int, int> types;
};

#endif //MLQ_HPP