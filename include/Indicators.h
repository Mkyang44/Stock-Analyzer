#indef INDICATORS_H
#define INDICATORS_H

#include <vector>
#include "Stock.h"

double calculateSMA(const std::vector<Stock>& stocks, size_t period);
double calculateEMA(const std::vector<Stock>& stocks, size_t period);
double calculateRSI(const std::vector<Stock>& stocks, size_t period);

#endif // INDICATORS_H