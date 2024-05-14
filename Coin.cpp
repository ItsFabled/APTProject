#include "Coin.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
 
 // implement functions for managing coins; this may depend on your design.

void loadCoins(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open coins file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string denominationStr, quantityStr;
        std::getline(iss, denominationStr, ',');
        std::getline(iss, quantityStr, ',');


    }
}