#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"
#include "Coin.h"
#include "CashRegister.h"

/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/

using namespace std;


LinkedList readDataAndPopulateList(CashRegister *cashRegister, const std::string& foodFileName, const std::string& coinFileName) {
    LinkedList list;

    // Read food data and populate the list
    std::ifstream foodFile(foodFileName);
    if (foodFile.is_open()) {
        std::string line;
        while (std::getline(foodFile, line)) {
            std::istringstream iss(line);
            std::string id, name, description;
            double price;
            if (std::getline(iss, id, '|') && std::getline(iss, name, '|') &&
                std::getline(iss, description, '|') && iss >> price) {
                FoodItem* foodItem = new FoodItem();
                foodItem->id = id;
                foodItem->name = name;
                foodItem->description = description;
                foodItem->price.dollars = static_cast<unsigned>(price);
                foodItem->price.cents = static_cast<unsigned>((price - static_cast<double>(foodItem->price.dollars)) * 100);
                foodItem->on_hand = DEFAULT_FOOD_STOCK_LEVEL;
                list.add(foodItem);
            }
        }
        foodFile.close();
    } else {
        std::cerr << "Error opening food file: " << foodFileName << std::endl;
    }

    // Read coin data
    std::ifstream coinFile(coinFileName);
    if (coinFile.is_open()) {
        std::string line;
        while (std::getline(coinFile, line)) {
            std::istringstream iss(line);
            std::string denominationStr;
            unsigned count;
            if (std::getline(iss, denominationStr, ',') && iss >> count) {
                Coin* coin = new Coin();
                if (denominationStr == "5") {
                    coin->setDenomination(FIVE_CENTS);
                } else if (denominationStr == "10") {
                    coin->setDenomination(TEN_CENTS);
                } else if (denominationStr == "20") {
                    coin->setDenomination(TWENTY_CENTS);
                } else if (denominationStr == "50") {
                    coin->setDenomination(FIFTY_CENTS);
                } else if (denominationStr == "100") {
                    coin->setDenomination(ONE_DOLLAR);
                } else if (denominationStr == "200") {
                    coin->setDenomination(TWO_DOLLARS);
                } else if (denominationStr == "500") {
                    coin->setDenomination(FIVE_DOLLARS);
                } else if (denominationStr == "1000") {
                    coin->setDenomination(TEN_DOLLARS);
                } else if (denominationStr == "2000") {
                    coin->setDenomination(TWENTY_DOLLARS);
                } else if (denominationStr == "5000") {
                    coin->setDenomination(FIFTY_DOLLARS);
                }
                
                coin->count = count;
                cashRegister->updateDenomination(coin->denom, coin->count);  // Add coin to cash register
            }
        }
        coinFile.close();
    } else {
        std::cerr << "Error opening coin file: " << coinFileName << std::endl;
    }

    return list;
}

void saveData(const LinkedList& list, const std::string& foodFileName) {
    // Save food data
    std::ofstream foodFile(foodFileName);
    if (foodFile.is_open()) {
        list.forEach([&foodFile](FoodItem* foodItem) {
            foodFile << foodItem->id << "|" << foodItem->name << "|" << foodItem->description << "|" << foodItem->price.dollars + (foodItem->price.cents / 100.0) << std::endl;
        });
        foodFile.close();
    } else {
        std::cerr << "Error opening food file: " << foodFileName << std::endl;
    }
}


void displayMainMenu() {
    std::cout << "Main Menu:" << std::endl;
    std::cout << "1. Display Meal Options" << std::endl;
    std::cout << "2. Purchase Meal" << std::endl;
    std::cout << "3. Save and Exit" << std::endl;
    std::cout << "Administrator-Only Menu:" << std::endl;
    std::cout << "4. Add Food" << std::endl;
    std::cout << "5. Remove Food" << std::endl;
    std::cout << "6. Display Balance" << std::endl;
    std::cout << "7. Abort Program" << std::endl;
    std::cout << "Select your option (1-7) : ";
}

int main(int argc, char **argv)
{
    string foodsFilename = "foods.dat";
    string coinsFilename = "coins.dat";
    /* validate command line arguments */
     if (argc != 3) {
         cout << "Invalid number of arguments, correct syntax is as follows:" << endl;
         cout << "./ftt <foodsfile> <coinsfile>" << endl;
         return -1;
     }
    // TODO
    
    // Initialize the cash register
    CashRegister cashRegsiter;
    LinkedList list = readDataAndPopulateList(&cashRegsiter,foodsFilename, coinsFilename);
    
    string id;
    int choice;
    
    do {
        displayMainMenu();
        cin>>choice;
        switch (choice) {
        case 1:
            list.displayFoods();
            break;
        case 2:
            cout<<"Purchase Meal"<<endl<<"---------------"<<endl;
            cout<<"Please enter the ID of the food you wish to purchase: ";
            cin>>id;
            list.purchaseMeal(id);
            break;
        case 3:
            // Save and Exit
            saveData(list, foodsFilename);
            cashRegsiter.saveRegister(coinsFilename);   
            break;
        case 4:
            // Add Food
            break;
        case 5:
            // Remove Food
            cout<<"Enter the food id of the food to remove from the menu: ";
            cin>>id;
            list.remove(id);
            break;
        case 6:
            // Display Balance
            cashRegsiter.printBalanceSummary();
            break;
        case 7:
            // Abort Program
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
        }
	}
	while (choice != 3 && choice != 7);

    // For example, you can print the denomination and count of each coin in the cash register
    saveData(list, foodsFilename);
    cashRegsiter.saveRegister(coinsFilename);    
    return EXIT_SUCCESS;
}
