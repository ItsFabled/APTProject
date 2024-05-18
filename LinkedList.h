#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <functional>
#include "CashRegister.h"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    // more functions to be added perhaps...
    void add(FoodItem* foodItem);
    std::string getMaxCode();
    void addNewFoodItem();
    void remove(const std::string& id);
    void forEach(std::function<void(FoodItem*)> callback) const;
    void displayFoods();
    bool purchaseMeal(const std::string& id, CashRegister* cashRegister);
public:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


