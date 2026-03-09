#include "Backtester.h"
#include "Indicators.h"
#include <iostream>
#include <iomanip>

void runBacktest(const std::vector<Stock>& data, int shortPeriod, int longPeriod){
    if (data.empty() || shortPeriod >= longPeriod){
        std::cout << "Invalid data or periods.\n";
        return;
    }

    double cash = 10000.0;
    int shares = 0;
    double buyPrice = 0.0;
    int trades = 0;
    int wins = 0;

    for (int i = longPeriod; i < static_cast<int>(data.size()); i++){
        double shortMA = movingAverage(data, shortPeriod, i);
        double longMA = movingAverage(data, longPeriod, i);

        double prevShortMA = movingAverage(data, shortPeriod, i - 1);
        double prevLongMA = movingAverage(data, longPeriod, i - 1);

        bool buySignal = (prevShortMA <= prevLongMA) && (shortMA > longMA);
        bool sellSignal = (prevShortMA >= prevLongMA) && (shortMA < longMA);


        std::cout << data[i].timestamp
        << " | Short MA: " << shortMA
        << " | Long MA: " << longMA
        << " | Buy: " << buySignal
        << " | Sell: " << sellSignal << "\n";


        if (buySignal && shares == 0){
            shares = static_cast<int>(cash / data[i].close);
            if (shares > 0){
                buyPrice = data[i].close;
                cash -= shares * buyPrice;
                std::cout << "BUY | " << data[i].timestamp
                            << " | Price: " << std::fixed << std::setprecision(2) << buyPrice
                            << " | Shares: " << shares << "\n";
            }
        }

        else if (sellSignal && shares > 0){
            double sellPrice = data[i].close;
            cash += shares * sellPrice;
            double profit = (sellPrice - buyPrice) * shares;
            trades++;

            if(profit > 0){
                wins++;
            }

            std::cout << "SELL | " << data[i].timestamp
                        << " | Price: " << sellPrice
                        << " | SHares: " << shares
                        << " | Profit: " << profit << "\n";
            shares = 0;
            buyPrice = 0.0;
        }
    }

    if (shares > 0){
        double finalPrice = data.back().close;
        cash += shares * finalPrice;
        double profit = (finalPrice - buyPrice) * shares;
        trades++;

        if (profit > 0){
            wins++;
        }

        std::cout << "FINAL SELL | " << data.back().timestamp
                    << " | Price: " << finalPrice
                    << " | Shares: " << shares
                    << " | Profit: " << profit << "\n";
    }

    double winRate = trades > 0 ? static_cast<double>(wins) / trades * 100.0 : 0.0;

    std::cout << "\n ====== BACKTEST RESULTS ====== \n";
    std::cout << "Starting Cash: $10000.00\n";
    std::cout << "Ending Cash: $" << std::fixed << std::setprecision(2) << cash << "\n";
    std::cout << "Total Trades: " << trades << "\n";
    std::cout << "Total Returns: " << std::fixed << std::setprecision(2) << (cash - 10000.0) << "\n";
    std::cout << "Win Rate: " << std::fixed << std::setprecision(2) << winRate << "%\n";
}