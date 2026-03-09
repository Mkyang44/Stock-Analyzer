#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

std::vector<Stock> readCSV(const std::string& filename) {
    std::vector<Stock> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: could not open file: " << filename << "\n";
        return data;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string item;
        Stock stock{};

        std::getline(ss, stock.timestamp, ',');

        std::getline(ss, item, ',');
        stock.open = std::stod(item);

        std::getline(ss, item, ',');
        stock.high = std::stod(item);

        std::getline(ss, item, ',');
        stock.low = std::stod(item);

        std::getline(ss, item, ',');
        stock.close = std::stod(item);

        std::getline(ss, item, ',');
        stock.volume = std::stoll(item);

        data.push_back(stock);   

    }

 
    return data;
    }