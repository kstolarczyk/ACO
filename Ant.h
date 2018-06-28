//
// Created by kamil on 26.06.18.
//

#ifndef ACO_ANT_H
#define ACO_ANT_H
#include "headers.h"

class Ant {
protected:
    bool * visited;
    double ** graf;
public:
    Ant(int len, double ** graf);
    ~Ant();
    void Run();
};


#endif //ACO_ANT_H
