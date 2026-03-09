#ifndef INDICATORS_H
#define INDICATORS_H

#include <vector>
#include "Stock.h"

double movingAverage(const std::vector<Stock>& data, int period, int index);

#endif // INDICATORS_H