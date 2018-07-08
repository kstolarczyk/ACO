//
// Created by kamil on 28.06.18.
//

#include "Graph.h"

Graph::Graph(Miasto *miasta, int v) {
    this->size = v;
    this->bestDistance = 99999999.0;
    this->edges = new Edge[(v * (v - 1)) / 2];
    this->edgesAccess = [v] {
        Edge ***e = new Edge **[v];
        for (auto i = 0; i < v; i++) {
            e[i] = new Edge *[v];
        }
        return e;
    }();
    for (int i = 0, k = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++, k++) {
            double distance = sqrt(pow((miasta[i].x - miasta[j].x), 2) + pow((miasta[i].y - miasta[j].y), 2));
            this->edges[k].d = distance;
            this->edgesAccess[i][j] = &this->edges[k];
            this->edgesAccess[j][i] = &this->edges[k];
        }
    }
}

Graph::~Graph() {
    for (auto i = 0; i < this->size; i++) {
        delete[] this->edgesAccess[i];
    }
    delete[] this->edgesAccess;
    delete[] this->edges;
}