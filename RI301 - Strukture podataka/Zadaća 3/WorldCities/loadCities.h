#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <cstring>
#include <iterator>
#include "City.h"
#include "Country.h"

void loadCities(std::vector<City>&, std::vector<Country>&, std::map<std::string, City*>&, std::ifstream&);