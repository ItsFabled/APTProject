#include "LinkedList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>


LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
    // TODO
}

void LinkedList::loadFoodItems(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open food file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, name, description, priceStr;
        std::getline(iss, id, '|');
        std::getline(iss, name, '|');
        std::getline(iss, description, '|');
        std::getline(iss, priceStr, '|');

        size_t dotPos = priceStr.find('.');
        if (dotPos == std::string::npos) {
            std::cerr << "Error: Invalid price format in food file." << std::endl;
            exit(EXIT_FAILURE);
        }
        unsigned dollars = std::stoi(priceStr.substr(0, dotPos));
        unsigned cents = std::stoi(priceStr.substr(dotPos + 1));

        FoodItem* newItem = new FoodItem{id, name, description, {dollars, cents}, 0};
        insertSorted(newItem);
    }
}

void LinkedList::insertSorted(FoodItem* newItem) {
    Node* newNode = new Node();
    newNode->data = newItem;

    if (head == nullptr || newItem->name < head->data->name) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data->name < newItem->name) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::displayFoodMenu() {
    std::cout << "Food Menu" << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << std::left << std::setw(6) << "ID" << "| "
              << std::left << std::setw(15) << "Name" << "| "
              << std::left << std::setw(10) << "Price" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    Node* current = head;
    while (current != nullptr) {
        std::cout << std::left << std::setw(6) << current->data->id << "| "
                  << std::left << std::setw(15) << current->data->name << "| $"
                  << std::left << std::setw(2) << current->data->price.dollars << "."
                  << std::setw(2) << std::setfill('0') << current->data->price.cents << std::setfill(' ') << std::endl;
        current = current->next;
    }
}