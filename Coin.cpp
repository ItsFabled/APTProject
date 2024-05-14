#include "Coin.h"
 
// implement functions for managing coins; this may depend on your design.
Coin::Coin() {
    this->denom = FIVE_CENTS;
    this->count = 0;
    this->cents = denominationCents[FIVE_CENTS];
}

Coin::Coin(Denomination denom, unsigned count) {
    this->denom = denom;
    this->count = count;
    this->cents = denominationCents[denom];
}

void Coin::setDenomination(Denomination denom) {
    this->denom = denom;
    this->cents = denominationCents[this->denom];
}
