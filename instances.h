#ifndef ACO_INSTANCES_H
#define ACO_INSTANCES_H
#include <regex>
#include <fstream>
#include "SpecialAnt.h"

std::vector<std::string> Split(const std::string &str, const std::regex &reg);

Miasto *wczytajMiasta(const std::string &fileName, int &len);
#endif // ACO_INSTANCES_H