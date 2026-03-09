#include <iostream>
#include "CSVReader.h"
#include "Backtester.h"
#include <vector>

int main() {
    std::vector<Stock> data = readCSV("data/AAPL.csv");

    if (data.empty()) {
        std::cout << "Failed to read data from CSV file.\n";
        return 1;
    }

    std::cout << "Data loaded successfully. Total records: " << data.size() << "\n";
    runBacktest(data, 3, 5);
    return 0;
}