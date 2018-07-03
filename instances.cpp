#include "instances.h"

std::vector<std::string> Split(const std::string &str, const std::regex & reg) {
  return {std::sregex_token_iterator(str.begin(), str.end(), reg, -1), std::sregex_token_iterator()};
}

Miasto *wczytajMiasta(const std::string &fileName, int &len) {
  std::fstream file(fileName, std::ios::in);
  std::string tmp;
  std::getline(file, tmp);
  std::regex reg("[^\\d]+");
  len = atoi(std::regex_replace(tmp, reg, "").c_str());
  Miasto * miasta = new Miasto[len];
  for(int i = 0; i < len; i++) {
    std::getline(file, tmp);
    auto splitted = Split(tmp, reg);
    miasta[i].y = atoi((*(splitted.end() - 1)).c_str());
    miasta[i].x = atoi((*(splitted.end() - 2)).c_str());
  }
  file.close();
  return miasta;
}
