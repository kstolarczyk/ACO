//
// Created by kamil on 28.06.18.
//

#ifndef ACO_CONFIG_H
#define ACO_CONFIG_H
#include <string>
const double START_FEROMON = 0.5; // początkowa wartość feromonów na każdej krawędzi
const double ALPHA = 1.0; // parametr istotnoEci feromonC3w
const double BETA = 5.0; // parametr istotnoEci odległości
const double QF = 100.0; // wartości feromonów pozostawiana po przebyciu trasy przez mrówki
const double PF = 0.5; // prędkość parowania feromonów
const int ANT_COUNT = 49;
const std::string F_NAME = "bier127.txt";
#endif //ACO_CONFIG_H