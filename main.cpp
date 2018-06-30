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
    std::vector<int> test;
    for (int i = 0; i < 10; i++) {
        test.push_back(i);
    }
    int *x = &test[3];
    std::cout << test[3] << " " << &test[3] << std::endl;
    std::cout << *x << " " << x << std::endl;
    test.erase(test.begin() + 1);
    std::cout << *x << " " << x << std::endl;
    std::cout << test[2] << " " << &test[2] << std::endl;
    std::cout << test[3] << " " << &test[3] << std::endl;
    return 0;
}