#ifndef Backtester_H
#define Backtester_H

#include <vector>
#include "Stock.h"

void runBacktest(const std::vector<Stock>& data, int shortPeriod, int longPeriod);

#endif // Backtester_H