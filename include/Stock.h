#ifndef STOCK_H
#define STOCK_H

#include <string>

struct Stock
{
    std::string timestamp;
    double open;
    double high;
    double low;
    double close;
    long long volume;
};

#endif // STOCK_H