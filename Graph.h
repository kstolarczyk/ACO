//
// Created by kamil on 28.06.18.
//

#ifndef ACO_GRAPH_H
#define ACO_GRAPH_H

#include <cstdio>
#include "Edge.h"

struct Miasto {
    int x;
    int y;
};

class Graph {
public:
    Edge *edges;
    Edge ***edgesAccess;
    size_t size;

    Graph(Miasto *miasta, int v);

    ~Graph();
};


#endif //ACO_GRAPH_H
