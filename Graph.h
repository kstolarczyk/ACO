//
// Created by kamil on 28.06.18.
//

#ifndef ACO_GRAPH_H
#define ACO_GRAPH_H

#include <cmath>
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
	std::mutex mtx;
    double bestDistance;
    Graph(Miasto *miasta, int v);
    ~Graph();
};


#endif //ACO_GRAPH_H