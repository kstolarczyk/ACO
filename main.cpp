#include <iostream>
#include "headers.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Miasto *miasta = new Miasto[6]{
            {.x = 1, .y = 3},
            {.x = 3, .y = 4},
            {.x = 2, .y = 1},
            {.x = 4, .y = 0},
            {.x = 0, .y = 4},
            {.x = 2, .y = 2}
    };
    Graph g(miasta, 6);
    delete[] miasta;
    std::cout << g.edges[0].d << std::endl;
    std::cout << g.edgesAccess[0][1]->d << std::endl;
    return 0;
}