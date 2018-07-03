//
// Created by kamil on 26.06.18.
//

#ifndef ACO_ANT_H
#define ACO_ANT_H

#include "Graph.h"
#include <vector>
class Ant {
protected:
    Graph *graph;
    int *trace;
    std::vector<int> neighbours;
    double *bestDistance;
public:
    Ant(Graph *graph1);
    ~Ant();

    Ant(const Ant &ant);

    Ant(Ant &&ant);

    virtual void Run();

    virtual void updateFeromons(double wspolczynnik);
    double *Probability(int current);
};


#endif //ACO_ANT_H
