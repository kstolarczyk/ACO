//
// Created by kamil on 26.06.18.
//

#include "Ant.h"
#include <sstream>
Ant::Ant(Graph *graph1) {
    std::cout << "Tworzenie" << std::endl;
    this->graph = graph1;
    this->trace = new int[graph1->size + 1];
    this->bestDistance = &graph1->bestDistance;
    this->neighbours.reserve(graph1->size);
}

Ant::Ant(const Ant &ant) : graph(ant.graph), bestDistance(ant.bestDistance), neighbours(ant.neighbours) {
    std::cout << "Kopiowanie" << std::endl;
    this->trace = new int[this->graph->size + 1];
}

Ant::Ant(Ant &&ant) : bestDistance(ant.bestDistance), graph(ant.graph), trace(ant.trace), neighbours(ant.neighbours) {
    std::cout << "Przeniesienie" << std::endl;
    ant.graph = nullptr;
    ant.trace = nullptr;
    ant.bestDistance = nullptr;
}
Ant::~Ant() {
    std::cout << "Niszczenie" << std::endl;
    delete[] this->trace;
}


double *Ant::Probability(int current) {
    std::vector<int> &n = this->neighbours;
    Edge ***e = this->graph->edgesAccess;
    double sum = 0.0;
    double *prob = new double[this->graph->size];
    for (auto const &value : n) {
        prob[value] = pow(e[current][value]->f, ALPHA) * pow(1.0 / e[current][value]->d, BETA);
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

void Ant::updateFeromons(double wspolczynnik) {
    for (int i = 0; i < this->graph->size; i++) {
        int x = this->trace[i], y = this->trace[i + 1];
        double feromon = QF * wspolczynnik / pow(this->graph->edgesAccess[x][y]->d, 2);
        this->graph->edgesAccess[x][y]->mtx.lock();
        this->graph->edgesAccess[x][y]->f += feromon;
        this->graph->edgesAccess[y][x]->mtx.unlock();
    }
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
            int left = 0, k;
			int right = this->neighbours.size();
			while (true) {
				k = (left + right) / 2;
				if (r <= p[this->neighbours[k]])
				{
					if (k == left) break;
					right = k;
				}
				else
				{
					if (k == left) { k = right; break; }
					left = k;
				}
			}
	
			distance += this->graph->edgesAccess[s][this->neighbours[k]]->d;
			
			s = this->neighbours[k];
            this->trace[index++] = s;
            this->neighbours.erase(this->neighbours.begin()+k);
            delete[] p;
        }
        this->trace[index++] = start;
        distance += this->graph->edgesAccess[s][start]->d;

        if (distance < *this->bestDistance) {
         /*   std::cout << "Trasa: ";
            for (int i = 0; i < len + 1; i++) {
                std::cout << this->trace[i] << " ";
            }
            std::cout << std::endl;
            */
			this->graph->mtx.lock();
			*this->bestDistance = (distance < *this->bestDistance) ? distance : *this->bestDistance;
			this->graph->mtx.unlock();
        }

		double wspolczynnik = this->graph->bestDistance / distance;
        this->updateFeromons(wspolczynnik);
    }
}