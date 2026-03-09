#include "Indicators.h"

double movingAverage(const std::vector<Stock>& data, int period, int index) {
    if (index < period - 1) {
        return 0.0; // Not enough data to calculate the moving average
    }

    double sum = 0.0;
    for (int i = index - period + 1; i <= index; ++i) {
        sum += data[i].close;
    }
    return sum / period;
}

