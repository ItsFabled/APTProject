#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() : head(nullptr), count(0) {}

LinkedList::~LinkedList() {
    // Deallocate memory for all nodes in the list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->data;  // Assuming data is dynamically allocated
        delete current;
        current = next;
    }
}

void LinkedList::add(FoodItem* foodItem) {
    // Create a new node with the given data
    Node* newNode = new Node();
    newNode->data = foodItem;
    newNode->next = nullptr;

    // If the list is empty, set the new node as the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        // Add the new node to the end of the list
        current->next = newNode;
    }
    // Increment the count of nodes in the list
    count++;
}

void LinkedList::remove(const std::string& id) {
    Node* current = head;
    Node* prev = nullptr;

    // Traverse the list to find the node with the given ID
    while (current != nullptr) {
        if (current->data->id == id) {
            // Remove the node from the list
            if (prev == nullptr) {
                // If the node to be removed is the head
                head = current->next;
            } else {
                prev->next = current->next;
            }

            cout << current->data->id << " - " << current->data->description << "has been removed from the system." << endl;

            delete current->data; // Free memory allocated for FoodItem
            delete current; // Free memory allocated for Node
            count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void LinkedList::forEach(std::function<void(FoodItem*)> callback) const {
    Node* current = head;
    while (current != nullptr) {
        callback(current->data);
        current = current->next;
    }
}

void printFoodItem(FoodItem* food) {
    //std::cout << "ID: " << food->id << ", Name: " << food->name << ", Description: " << food->description << ", Price: $" 
    //          << food->price.dollars << "." << food->price.cents << std::endl;
    
    std::cout<< food->id << "|" << food->name << "								|$"<< food->price.dollars << "." << food->price.cents << std::endl;
}

void LinkedList::displayFoods() {
	std::cout <<"Food Menu" << std::endl << "---------"<< std::endl<<"ID   |Name								|Price"<<endl;
	cout<<"------------------------------------------------------------------------------------"<<endl;    
    this->forEach(printFoodItem);
}


bool LinkedList::purchaseMeal(const std::string& id){
	Node* current = head;
	while(current != NULL){
		if(current->data->id == id){
			std::cout << "You selected: "; 
			std::cout << current->data->name << "-" 
                      << current->data->description << " This will cost you $" << current->data->price.dollars << "." 
                      << current->data->price.cents << std::endl;
			int totalPrice = (current->data->price.dollars * 100) + (current->data->price.cents);
			int payment=0;
			string paid="0";
			int paidAmount =0;
			std::cout << "Please hand over the mony - type in the value of each note/coin in cents."<<endl;
			cout<<"Please enter ctrl-D or enter on a new line to cancel this purchase."<<endl;
			while (payment < totalPrice)
			{
				cout<<"You still need to give us $"<< (totalPrice - payment) / 100 << "." << (totalPrice - payment) % 100<<": ";
				cin >> paid;
				
				if (paid == "\x4"){
					std::cout<<"Purchased Canceled."<< std::endl;
					return false;
				}
				paidAmount = stoi(paid);

				if(paidAmount == 5 || paidAmount == 10 || paidAmount == 20 || paidAmount == 50 || paidAmount == 100 || paidAmount == 200 || paidAmount == 500 || paidAmount == 1000 || paidAmount == 2000 || paidAmount == 5000)
				{
					payment = payment + paidAmount;
				}
				else 
				{
					cout<<"Invalid denomination encountered."<<endl;
				}
			}
			// int change = totalPrice - payment;
            return true;
		}
		current = current->next;
	}
	std::cout << "Invalid food item ID. Please try again." << std::endl;
    return false;
}