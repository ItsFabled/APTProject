#ifndef COIN_H
#define COIN_H

// Coin.h defines the coin structure for managing currency in the system. 
#define DELIM ","  // delimiter 

// enumeration representing the various types of currency available in the system. 
enum Denomination
{
    FIVE_CENTS, TEN_CENTS, TWENTY_CENTS, FIFTY_CENTS, ONE_DOLLAR, 
    TWO_DOLLARS, FIVE_DOLLARS, TEN_DOLLARS, TWENTY_DOLLARS, FIFTY_DOLLARS
};

const int denominationCents[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000};

// represents a coin type stored in the cash register perhaps. Each demonination
// will have exactly one of these in the cash register.
class Coin
{
private:
    int cents;
public:
    // the denomination type
    enum Denomination denom;
    
    // the count of how many of these are in the cash register
    unsigned count;
    Coin();
    Coin(Denomination denom, unsigned count);
    void setDenomination(Denomination denom);
    int getCents() {
        return this->cents;
    }
};

#endif // COIN_H
