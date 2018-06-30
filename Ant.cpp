//
// Created by kamil on 26.06.18.
//
#include <algorithm>
#include <random>
#include <iostream>
#include "Ant.h"

Ant::Ant(Graph *graph1) : bestDistance(graph1->bestDistance) {
    this->trace = new int[graph1->size + 1];
    this->graph = graph1;
}

Ant::~Ant() {
}

double *Ant::Probability(int current) {
    std::vector<int> &n = this->neighbours;
    Edge ***e = this->graph->edgesAccess;
    double sum = 0.0;
    double *prob = new double[this->graph->size];
    for (auto const &value : n) {
        prob[value] = pow(e[current][value]->f, ALPHA) * pow(e[current][value]->d, BETA);
        sum += prob[value];
    }
    prob[*n.begin()] /= sum;
    for (auto it = n.begin() + 1; it != n.end(); ++it) {
        prob[*it] /= sum;
        prob[*it] += prob[*(it - 1)];
    }

    prob[*(n.end() - 1)] = 1.0;

    return prob;
}

void Ant::Run() {
    int len = this->graph->size;
    int start = std::rand() % len;
    while (true) {
        int index = 0;
        this->trace[index++] = start;
        int s = start;
        double distance = 0.0;
        for (auto i = 0; i < len; i++) {
            if (i != start)
                this->neighbours.push_back(i);
        }
        while (!this->neighbours.empty()) {
            double *p = this->Probability(s);
            double r = (double) std::rand() / RAND_MAX;
            for (auto const &vertic : this->neighbours) {
                if (r < p[vertic]) {
                    distance += this->graph->edgesAccess[s][vertic]->d;
                    s = vertic;
                    break;
                }
            }
            this->trace[index++] = s;
            this->neighbours.erase(std::find(this->neighbours.begin(), this->neighbours.end(), s));
            delete[] p;
        }
        if (distance < this->graph->bestDistance) {
            std::cout << "Dystans: " << distance << std::endl;
            std::cout << "Trasa: ";
            for (int i = 0; i < this->graph->size; i++) {
                std::cout << this->trace[i] << " ";
            }
            std::cout << std::endl;
        }
    }
}
