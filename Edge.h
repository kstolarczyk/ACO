//
// Created by kamil on 28.06.18.
//

#ifndef ACO_EDGE_H
#define ACO_EDGE_H

#include "config.h"
#include <mutex>
class Edge {
public:
    double d;
    double f;
    std::mutex mtx;
    Edge();
    Edge(double d);
};


#endif //ACO_EDGE_H
