//
// Created by kamil on 28.06.18.
//

#include "Edge.h"

Edge::Edge() {
    this->f = START_FEROMON;
}

Edge::Edge(double d) {
    this->d = d;
    this->f = START_FEROMON;
}