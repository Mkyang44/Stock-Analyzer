#include "CSVReader.hpp"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<Stock> readCSV(const std::string& filename) {
    std::vector<Stock> data;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        std::getline(file, line); // Skip header line

        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;
            Stock stock;

            std::getline(ss, token, ',');
            stock.timestamp = token;

            std::getline(ss, token, ',');
            stock.open = std::stod(token);

            std::getline(ss, token, ',');
            stock.high = std::stod(token);

            std::getline(ss, token, ',');
            stock.low = std::stod(token);

            std::getline(ss, token, ',');
            stock.close = std::stod(token);

            std::getline(ss, token, ',');
            stock.volume = std::stod(token);

            data.push_back(stock);
        }

        file.close();
    }

    return data;
}
    