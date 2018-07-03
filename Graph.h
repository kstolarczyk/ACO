//
// Created by kamil on 28.06.18.
//

#ifndef ACO_GRAPH_H
#define ACO_GRAPH_H

#include <cstdio>
#include "Edge.h"
#include <mutex>
struct Miasto {
    int x;
    int y;
};

class Graph {
public:
    Edge *edges;
    Edge ***edgesAccess;
    size_t size;
    double bestDistance;
    std::mutex mtx;
    Graph(Miasto *miasta, int v);
    ~Graph();
};


#endif //ACO_GRAPH_H
