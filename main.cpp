#include <iostream>
#include <thread>
#include "headers.h"
#include "SpecialAnt.h"

void wykonaj(Ant *ant) {
    ant->Run();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(NULL));
    Miasto *miasta = new Miasto[6]{
            {.x = 10, .y = 3},
            {.x = 15, .y = 5},
            {.x = 7, .y = 9},
            {.x = 8, .y = 13},
            {.x = 2, .y = 1},
            {.x = 4, .y = 8}
    };
    Graph g(miasta, 6);
    delete[] miasta;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i != j) {
                std::cout << g.edgesAccess[i][j]->d << "\t\t";
            } else {
                std::cout << "---" << "\t\t";
            }
        }
        std::cout << std::endl;
    }

    std::vector<Ant> ants;
    ants.reserve(5);
    std::thread threads[6];

    for (int i = 0; i < 5; i++) {
        ants.emplace_back(&g);
    }
    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(wykonaj, &ants[i]);
    }
    threads[5] = std::thread(wykonaj, new SpecialAnt(&g));
    for (auto &th : threads) th.join();
    return 0;
}