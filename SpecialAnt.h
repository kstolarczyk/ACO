//
// Created by kamil on 30.06.18.
//

#ifndef ACO_SPECIALANT_H
#define ACO_SPECIALANT_H


#include "Ant.h"
#include "Edge.h"

class SpecialAnt : public Ant {
protected:
    int count;
public:
    SpecialAnt(Graph *graph1);

    void updateFeromons(double wspolczynnik);
    void Parowanie(Edge *edges);
};


#endif //ACO_SPECIALANT_H
