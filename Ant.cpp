//
// Created by kamil on 26.06.18.
//

#include <algorithm>
#include "Ant.h"

Ant::Ant(int len, double **graf) {
    this->graf = graf;
    this->visited = new bool[len];
    std::fill(&this->visited[0], &this->visited[len-1], false);
}
Ant::~Ant() {
    delete this->graf;
    delete [] this->visited;
}
void Ant::Run() {

}
