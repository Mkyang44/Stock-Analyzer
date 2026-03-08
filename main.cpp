#include <iostream>
#include "CSVReader.hpp"
#include "Indicators.hpp"
#include <vector>

int main() {
    std::vector<Stock> data = readCSV("stock_data.csv");

    int period = 5; // Example period for moving average
    
    for (size_t i = 0; i < data.size(); ++i) {
        double ma = movingAverage(data, period, i);


        std::cout << "Date: " << data[i].timestamp 
        << ", Close: " << data[i].close << ", "         
        << period << "-day MA: " << ma << std::endl;
    }

    return 0;
}