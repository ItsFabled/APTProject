#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "CashRegister.h"


CashRegister::CashRegister() {
    this->emptyCashRegister();
}

// Add coins to the register
void CashRegister::addCoins(const std::vector<Coin>& coins) {
    for (const Coin& coin : coins) {
        // Check if coin with the same denomination already exists
        auto it = std::find_if(register_.begin(), register_.end(), [&](const Coin& c) { return c.denom == coin.denom; });
        if (it != register_.end()) {
            // Update count of existing coin
            it->count += coin.count;
        } else {
            // Add new coin to register
            register_.push_back(coin);
        }
    }
}

// Update count of a specific denomination
void CashRegister::updateDenomination(Denomination denom, unsigned count) {
    auto it = std::find_if(register_.begin(), register_.end(), [&](const Coin& c) { return c.denom == denom; });
    if (it != register_.end()) {
        // Update count of existing coin
        it->count = count;
    } else {
        // Add new coin to register if not found
        register_.push_back({denom, count});
    }
}

// adjust count of a specific denomination
void CashRegister::adjustDenomination(Denomination denom, unsigned count) {
    auto it = std::find_if(register_.begin(), register_.end(), [&](const Coin& c) { return c.denom == denom; });
    if (it != register_.end()) {
        // Update count of existing coin
        it->count += count;
    } else {
        // Add new coin to register if not found
        register_.push_back({denom, count});
    }
}

// Get the cash register
const std::vector<Coin>& CashRegister::getRegister() const {
    return register_;
}

void CashRegister::emptyCashRegister()
{
    register_.clear();
    // Add coins for each denomination to the cash register
    register_.push_back(Coin(FIFTY_DOLLARS, 0));
    register_.push_back(Coin(TWENTY_DOLLARS, 0));
    register_.push_back(Coin(TEN_DOLLARS, 0));
    register_.push_back(Coin(FIVE_DOLLARS, 0));
    register_.push_back(Coin(TWO_DOLLARS, 0));
    register_.push_back(Coin(ONE_DOLLAR, 0));
    register_.push_back(Coin(FIFTY_CENTS, 0));
    register_.push_back(Coin(TWENTY_CENTS, 0));
    register_.push_back(Coin(TEN_CENTS, 0));
    register_.push_back(Coin(FIVE_CENTS, 0));
}

// Save the cash register to a file
void CashRegister::saveRegister(const std::string& fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (const Coin& coin : register_) {
            std::string denominationStr;
            switch (coin.denom) {
                case FIVE_CENTS: denominationStr = "5"; break;
                case TEN_CENTS: denominationStr = "10"; break;
                case TWENTY_CENTS: denominationStr = "20"; break;
                case FIFTY_CENTS: denominationStr = "50"; break;
                case ONE_DOLLAR: denominationStr = "100"; break;
                case TWO_DOLLARS: denominationStr = "200"; break;
                case FIVE_DOLLARS: denominationStr = "500"; break;
                case TEN_DOLLARS: denominationStr = "1000"; break;
                case TWENTY_DOLLARS: denominationStr = "2000"; break;
                case FIFTY_DOLLARS: denominationStr = "5000"; break;
                // Add more cases for other denominations
                default: break;
            }
            file << denominationStr << "," << coin.count << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

void CashRegister::printBalanceSummary() {
    std::cout << "Balance Summary" << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Denom | Quantity | Value" << std::endl;
    std::cout << "---------------------------" << std::endl;
    
    double totalValue = 0;
    for (Coin& coin : register_) {
        std::cout << std::setw(5) << coin.getCents() << " | " << std::setw(8) << coin.count << " | $ ";
        double value = coin.getCents() * coin.count / 100.0;
        totalValue += value;
        std::cout << std::fixed << std::setprecision(2) << std::setw(6) << static_cast<double>(value) << std::endl;
    }
    
    std::cout << "---------------------------" << std::endl;
    std::cout << std::setw(20) << "$ " << totalValue << std::endl;
}
