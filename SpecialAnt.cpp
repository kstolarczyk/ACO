//
// Created by kamil on 30.06.18.
//

#include "SpecialAnt.h"

SpecialAnt::SpecialAnt(Graph *graph1) : Ant(graph1) {
    this->count = graph1->size * (graph1->size - 1) / 2;
}

void SpecialAnt::updateFeromons(double wspolczynnik) {
    Ant::updateFeromons(wspolczynnik);
    this->Parowanie(this->graph->edges);
}

void SpecialAnt::Parowanie(Edge *edges) {
    for (auto i = 0; i < this->count; i++) {
        edges[i].mtx.lock();
        edges[i].f *= PF;
        edges[i].mtx.unlock();
    }
}
