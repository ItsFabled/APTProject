#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <vector>
#include "Coin.h"


// CashRegister class to manage the cash register
class CashRegister {
private:
    std::vector<Coin> register_;

public:
    // Constructor
    CashRegister();

    const std::vector<Coin>& getRegister() const;
    void emptyCashRegister();
    void addCoins(const std::vector<Coin>& coins);
    void updateDenomination(Denomination denom, unsigned count);
    void adjustDenomination(Denomination denom, unsigned count);
    void saveRegister(const std::string& fileName);
    void printBalanceSummary();
};

#endif