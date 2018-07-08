#include <thread>
#include "headers.h"

void wykonaj(Ant *ant) {
    ant->Run();
}

void wykonaj2(SpecialAnt *ant) {
    ant->Run();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(NULL));
    int size = 0;
    Miasto *m = wczytajMiasta(F_NAME, size);
    Graph g(m, size);
    delete[] m;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                std::cout << g.edgesAccess[i][j]->d << "\t\t";
            } else {
                std::cout << "---" << "\t\t";
            }
        }
        std::cout << std::endl;
    }

    std::vector<Ant> ants;
    ants.reserve(ANT_COUNT);
    std::thread threads[ANT_COUNT + 1];

    for (int i = 0; i < ANT_COUNT; i++) {
        ants.emplace_back(&g);
    }
    for (int i = 0; i < ANT_COUNT; i++) {
        threads[i] = std::thread(wykonaj, &ants[i]);
    }
    threads[ANT_COUNT] = std::thread(wykonaj2, new SpecialAnt(&g));
    for (auto &th : threads) th.join();
    return 0;
}