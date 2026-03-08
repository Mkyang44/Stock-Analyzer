#ifndef STOCK_HPP
#define STOCK_HPP

#include <string>

struct Stock {
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;
    double volume;
};


#endif // STOCK_HPP