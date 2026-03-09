#indef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include "Stock.h"

std::vector<Stock> readCSV(const std::string& filename);

#endif // CSVREADER_H