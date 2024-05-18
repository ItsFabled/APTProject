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
    void addCoins(Denomination denom, unsigned count);
    void SubtractCoins(Denomination denom, unsigned count);
    void updateDenomination(Denomination denom, unsigned count);
    void adjustDenomination(Denomination denom, unsigned count);
    void saveRegister(const std::string& fileName);
    void printBalanceSummary();
    std::string updateAllDenominations(unsigned FIVE_CENTS_Add, unsigned TEN_CENTS_Add, unsigned TWENTY_CENTS_Add, unsigned FIFTY_CENTS_Add,
    unsigned ONE_DOLLAR_Add, unsigned TWO_DOLLARS_Add, unsigned FIVE_DOLLARS_Add, unsigned TEN_DOLLARS_Add,
    unsigned TWENTY_DOLLARS_Add, unsigned FIFTY_DOLLARS_Add, int PaidAmount, int ChangeAmount, CashRegister* cashRegister);
};

#endif