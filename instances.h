#ifndef ACO_INSTANCES_H
#define ACO_INSTANCES_H
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include "Graph.h"

std::vector<std::string> Split(const std::string &str, const std::regex &reg);

Miasto *wczytajMiasta(const std::string &fileName, int &len);
#endif // ACO_INSTANCES_H
