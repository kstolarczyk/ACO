#include <thread>
#include "headers.h"
#include <chrono>

#define MAX_TIMEOUT 60
void wykonaj(Ant *ant) {
    ant->Run();
}

void wykonaj2(SpecialAnt *ant) {
    ant->Run();
}


int main() {
    srand(time(NULL));
    int size = 0;
    Miasto *m = wczytajMiasta(F_NAME, size);
    Graph g(m, size);
    delete[] m;
    /*for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                std::cout << g.edgesAccess[i][j]->d << "\t\t";
            } else {
                std::cout << "---" << "\t\t";
            }
        }
        std::cout << std::endl;
    }
*/
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
	double d = DBL_MAX;
	for (int i = 0; i < MAX_TIMEOUT; i++) {
		if (g.bestDistance < d) {
			std::cout << "Dystans: " << g.bestDistance << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}

	for (auto &th : threads) th.~thread();
	std::cout << "Koniec" << std::endl;
    return 0;
}