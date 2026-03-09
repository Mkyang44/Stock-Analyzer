#include <iostream>
#include "../include/CSVReader.hpp"
#include "../include/Backtester.hpp"
#include <vector>

int main() {
    std::vector<Stock> data = readCSV("data/AAPL.csv");

    if (data.empty()) {
        std::cout << "Failed to read data from CSV file.\n";
        return 1;
    }

    std::cout << "Data loaded successfully. Total records: " << data.size() << "\n";
    runBacktest(data, 5, 20);
    return 0;
}