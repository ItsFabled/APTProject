#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

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
    std::cout << "Select your option (1-7): ";
}

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <foodsfile> <coinsfile>" << std::endl;
        return EXIT_FAILURE;
    }

    const char* foodsfile = argv[1];
    const char* coinsfile = argv[2];

    LinkedList foodList;
    foodList.loadFoodItems(foodsfile);

    loadCoins(coinsfile);

    char choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch(choice) {
            case '1':
                foodList.displayFoodMenu();
                break;
            case '2':
                // Purchase Meal - Implement this functionality
                break;
            case '3':
                // Save and Exit - Implement this functionality
                break;
            case '4':
                // Add Food - Implement this functionality
                break;
            case '5':
                // Remove Food - Implement this functionality
                break;
            case '6':
                // Display Balance - Implement this functionality
                break;
            case '7':
                std::cout << "Aborting program." << std::endl;
                return EXIT_SUCCESS;
            default:
                std::cout << "Invalid option. Please select a number between 1 and 7." << std::endl;
                break;
        }
    } while(choice != '3');

    return EXIT_SUCCESS;
}