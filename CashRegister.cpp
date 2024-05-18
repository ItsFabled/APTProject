#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "CashRegister.h"


CashRegister::CashRegister() {
    this->emptyCashRegister();
}

// Add coins to the register
void CashRegister::addCoins(Denomination denom, unsigned count) {
    auto it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == denom; });
    if (it != register_.end()) {
        it->count += count;
    }
    else {
        register_.push_back({ TWENTY_DOLLARS, count });
    }
}

// Subtract coins to the register
void CashRegister::SubtractCoins(Denomination denom, unsigned count) {
    auto it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == denom; });
    if (it != register_.end()) {
        it->count -= count;
    }
    else {
        register_.push_back({ TWENTY_DOLLARS, count });
    }
}

// Update count of a specific denomination
void CashRegister::updateDenomination(Denomination denom, unsigned count) {
    auto it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == denom; });
    if (it != register_.end()) {
        it->count = count;
    } else {
        register_.push_back({denom, count});
    }
}

// adjust count of a specific denomination
void CashRegister::adjustDenomination(Denomination denom, unsigned count) {
    auto it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == denom; });
    if (it != register_.end()) {
        it->count = it->count + count;
    } else {
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

void subtractCoins_AllDenom(unsigned FIVE_CENTS_Add, unsigned TEN_CENTS_Add, unsigned TWENTY_CENTS_Add, unsigned FIFTY_CENTS_Add,
    unsigned ONE_DOLLAR_Add, unsigned TWO_DOLLARS_Add, unsigned FIVE_DOLLARS_Add, unsigned TEN_DOLLARS_Add, 
    unsigned TWENTY_DOLLARS_Add, unsigned FIFTY_DOLLARS_Add, CashRegister* cashRegister)
{
    if (FIVE_CENTS_Add > 0)
    {
        cashRegister->SubtractCoins(FIVE_CENTS, FIVE_CENTS_Add);
    }
    if (TEN_CENTS_Add > 0)
    {
        cashRegister->SubtractCoins(TEN_CENTS, TEN_CENTS_Add);
    }
    if (TWENTY_CENTS_Add > 0)
    {
        cashRegister->SubtractCoins(TWENTY_CENTS, TWENTY_CENTS_Add);
    }
    if (FIFTY_CENTS_Add > 0)
    {
        cashRegister->SubtractCoins(FIFTY_CENTS, FIFTY_CENTS_Add);
    }
    if (ONE_DOLLAR_Add > 0)
    {
        cashRegister->SubtractCoins(ONE_DOLLAR, ONE_DOLLAR_Add);
    }
    if (TWO_DOLLARS_Add > 0)
    {
        cashRegister->SubtractCoins(TWO_DOLLARS, TWO_DOLLARS_Add);
    }
    if (FIVE_DOLLARS_Add > 0)
    {
        cashRegister->SubtractCoins(FIVE_DOLLARS, FIVE_DOLLARS_Add);
    }
    if (TEN_DOLLARS_Add > 0)
    {
        cashRegister->SubtractCoins(TEN_DOLLARS, TEN_DOLLARS_Add);
    }
    if (TWENTY_DOLLARS_Add > 0)
    {
        cashRegister->SubtractCoins(TWENTY_DOLLARS, TWENTY_DOLLARS_Add);
    }
    if (FIFTY_DOLLARS_Add > 0)
    {
        cashRegister->SubtractCoins(FIFTY_DOLLARS, FIFTY_DOLLARS_Add);
    }
}


void addCoins_AllDenom(unsigned FIVE_CENTS_Add, unsigned TEN_CENTS_Add, unsigned TWENTY_CENTS_Add, unsigned FIFTY_CENTS_Add,
    unsigned ONE_DOLLAR_Add, unsigned TWO_DOLLARS_Add, unsigned FIVE_DOLLARS_Add, unsigned TEN_DOLLARS_Add,
    unsigned TWENTY_DOLLARS_Add, unsigned FIFTY_DOLLARS_Add, CashRegister* cashRegister)
{
    if (FIVE_CENTS_Add > 0)
    {
        cashRegister->addCoins(FIVE_CENTS, FIVE_CENTS_Add);
    }
    if (TEN_CENTS_Add > 0)
    {
        cashRegister->addCoins(TEN_CENTS, TEN_CENTS_Add);
    }
    if (TWENTY_CENTS_Add > 0)
    {
        cashRegister->addCoins(TWENTY_CENTS, TWENTY_CENTS_Add);
    }
    if (FIFTY_CENTS_Add > 0)
    {
        cashRegister->addCoins(FIFTY_CENTS, FIFTY_CENTS_Add);
    }
    if (ONE_DOLLAR_Add > 0)
    {
        cashRegister->addCoins(ONE_DOLLAR, ONE_DOLLAR_Add);
    }
    if (TWO_DOLLARS_Add > 0)
    {
        cashRegister->addCoins(TWO_DOLLARS, TWO_DOLLARS_Add);
    }
    if (FIVE_DOLLARS_Add > 0)
    {
        cashRegister->addCoins(FIVE_DOLLARS, FIVE_DOLLARS_Add);
    }
    if (TEN_DOLLARS_Add > 0)
    {
        cashRegister->addCoins(TEN_DOLLARS, TEN_DOLLARS_Add);
    }
    if (TWENTY_DOLLARS_Add > 0)
    {
        cashRegister->addCoins(TWENTY_DOLLARS, TWENTY_DOLLARS_Add);
    }
    if (FIFTY_DOLLARS_Add > 0)
    {
        cashRegister->addCoins(FIFTY_DOLLARS, FIFTY_DOLLARS_Add);
    }
}


std::string CashRegister::updateAllDenominations(unsigned FIVE_CENTS_Add, unsigned TEN_CENTS_Add, unsigned TWENTY_CENTS_Add, unsigned FIFTY_CENTS_Add,
    unsigned ONE_DOLLAR_Add, unsigned TWO_DOLLARS_Add, unsigned FIVE_DOLLARS_Add, unsigned TEN_DOLLARS_Add,
    unsigned TWENTY_DOLLARS_Add, unsigned FIFTY_DOLLARS_Add, int PaidAmount, int ChangeAmount, CashRegister* cashRegister) {

    unsigned FIVE_CENTS_Sub = 0;
    unsigned TEN_CENTS_Sub = 0;
    unsigned TWENTY_CENTS_Sub = 0;
    unsigned FIFTY_CENTS_Sub = 0;
    unsigned ONE_DOLLAR_Sub = 0;
    unsigned TWO_DOLLARS_Sub = 0;
    unsigned FIVE_DOLLARS_Sub = 0;
    unsigned TEN_DOLLARS_Sub = 0;
    unsigned TWENTY_DOLLARS_Sub = 0;
    unsigned FIFTY_DOLLARS_Sub = 0;

    addCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
        ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
        TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

    // Change Amount 

    std::string Change = "";
    unsigned count = ChangeAmount / 5000;
    auto it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == FIFTY_DOLLARS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                FIFTY_DOLLARS_Sub = count;
                cashRegister->SubtractCoins(FIFTY_DOLLARS, count);
            }
        }
    }
    
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "$50 ";
    }
    
    ChangeAmount = ChangeAmount % 5000;

    count = ChangeAmount / 2000;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == TWENTY_DOLLARS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                TWENTY_DOLLARS_Sub = count;
                cashRegister->SubtractCoins(TWENTY_DOLLARS, count);
            }
        }
    }
    
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "$20 ";
    }
    
    ChangeAmount = ChangeAmount % 2000;

    count = ChangeAmount / 1000;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == TEN_DOLLARS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                TEN_DOLLARS_Sub = count;
                cashRegister->SubtractCoins(TEN_DOLLARS, count);
            }
        }
    }
    
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "$10 ";
    }
    ChangeAmount = ChangeAmount % 1000;

    count = ChangeAmount / 500;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == FIVE_DOLLARS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                FIVE_DOLLARS_Sub = count;
                cashRegister->SubtractCoins(FIVE_DOLLARS, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "$5 ";
    }
    ChangeAmount = ChangeAmount % 500;

     count = ChangeAmount / 200;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == TWO_DOLLARS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                TWO_DOLLARS_Sub = count;
                cashRegister->SubtractCoins(TWO_DOLLARS, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "$2 ";
    }
    ChangeAmount = ChangeAmount % 200;

    count = ChangeAmount / 100;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == ONE_DOLLAR; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                ONE_DOLLAR_Sub = count;
                cashRegister->SubtractCoins(ONE_DOLLAR, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "$1 ";
    }
    ChangeAmount = ChangeAmount % 100;

    count = ChangeAmount / 50;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == FIFTY_CENTS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                FIFTY_CENTS_Sub = count;
                cashRegister->SubtractCoins(FIFTY_CENTS, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "50c ";
    }
    ChangeAmount = ChangeAmount % 50;

    count = ChangeAmount / 20;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == TWENTY_CENTS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                TWENTY_CENTS_Sub = count;
                cashRegister->SubtractCoins(TWENTY_CENTS, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "20c ";
    }
    ChangeAmount = ChangeAmount % 20;

    count = ChangeAmount / 10;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == TEN_CENTS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                TEN_CENTS_Sub = count;
                cashRegister->SubtractCoins(TEN_CENTS, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "10c ";
    }
    ChangeAmount = ChangeAmount % 10;

    count = ChangeAmount / 5;
    it = std::find_if(register_.begin(), register_.end(), [&](Coin& c) { return c.denom == FIVE_CENTS; });
    if (it != register_.end()) {
        if (it->count < count) {
            subtractCoins_AllDenom(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, cashRegister);

            addCoins_AllDenom(FIVE_CENTS_Sub, TEN_CENTS_Sub, TWENTY_CENTS_Sub, FIFTY_CENTS_Sub,
                ONE_DOLLAR_Sub, TWO_DOLLARS_Sub, FIVE_DOLLARS_Sub, TEN_DOLLARS_Sub,
                TWENTY_DOLLARS_Sub, FIFTY_DOLLARS_Sub, cashRegister);

            return "Your Purchase has been canceled due to low balance.";
        } else {
            if (count > 0) {
                FIVE_CENTS_Sub = count;
                cashRegister->SubtractCoins(FIVE_CENTS, count);
            }
        }
    }
    for (unsigned int i = 0; i < count; i++) {
        Change = Change + "5c ";
    }
    ChangeAmount = ChangeAmount % 5;

    return Change;
}
