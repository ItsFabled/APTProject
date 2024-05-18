#include <algorithm>

#include <iostream>
#include "LinkedList.h"
#include <iomanip>
#include <sstream>
#include "CashRegister.h"

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
void LinkedList::addNewFoodItem() {
    std::string nextID = getMaxCode();

    std::string name, description;
    double price;
    std::cout << " This new meal item will have the Item id of "<< nextID <<"."<<endl;
    std::cout << "Enter the item name: ";
    std::cin.ignore(); 
    std::getline(std::cin, name);
    std::cout << "Enter the item description: ";
    std::getline(std::cin, description);
    std::cout << " Enter the price for this item (incents): ";
    std::cin >> price;
    price = price / 100;
    FoodItem* newFood = new FoodItem(nextID, name, description);
    newFood->price.dollars = static_cast<int>(price);
    newFood->price.cents = static_cast<int>((price - static_cast<int>(price)) * 100);

    add(newFood);

    std::cout << "This item \"" << name << " - " << description << "\" has now been added to the food menu." << std::endl;
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
        if (current->data != nullptr)
        {
            callback(current->data);
        }
        current = current->next;
    }
}

void printFoodItem(FoodItem* food) {
     std::cout << food->id << "|" << food->name << "						|$" << std::setw(3) << food->price.dollars << "." << food->price.cents << std::endl;
}

void LinkedList::displayFoods() {
	std::cout <<"Food Menu" << std::endl << "---------"<< std::endl<<"ID   |Name						|Price"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;    
    this->forEach(printFoodItem);
    cout << endl;
}
int extractIntegerPart(const std::string& input) {
    size_t pos = input.find_first_not_of("0123456789");
    std::string integerPart = input.substr(1, pos - 1);
    int result = stoi(integerPart);
    return result;
}

string LinkedList::getMaxCode() {
    
    Node* current = head;
    int max = 0;
    while (current != NULL) {
        int code = extractIntegerPart(current->data->id);
        if (max < extractIntegerPart(current->data->id))
        {
            max = code;
        }
        current = current->next;
    }
    ostringstream foodCode;
    max++;
    foodCode << "F" << std::setw(4) << std::setfill('0') << max;

    return foodCode.str();
}

bool LinkedList::purchaseMeal(const std::string& id, CashRegister* cashRegister){
    unsigned FIVE_CENTS_Add = 0;
    unsigned TEN_CENTS_Add = 0;
    unsigned TWENTY_CENTS_Add = 0;
    unsigned FIFTY_CENTS_Add = 0;
    unsigned ONE_DOLLAR_Add = 0;
    unsigned TWO_DOLLARS_Add = 0;
    unsigned FIVE_DOLLARS_Add = 0;
    unsigned TEN_DOLLARS_Add = 0;
    unsigned TWENTY_DOLLARS_Add = 0;
    unsigned FIFTY_DOLLARS_Add = 0;


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
                    if (paidAmount == 5000)
                    {
                        FIFTY_DOLLARS_Add++;
                    }
                    else if (paidAmount == 2000)
                    {
                        TWENTY_DOLLARS_Add++;
                    }
                    else if (paidAmount == 1000)
                    {
                        TEN_DOLLARS_Add++;
                    }
                    else if (paidAmount == 500)
                    {
                        FIVE_DOLLARS_Add++;
                    }
                    else if (paidAmount == 200)
                    {
                        TWO_DOLLARS_Add++;
                    }
                    else if (paidAmount == 100)
                    {
                        ONE_DOLLAR_Add++;
                    }
                    else if (paidAmount == 50)
                    {
                        FIFTY_CENTS_Add++;
                    }
                    else if (paidAmount == 20)
                    {
                        TWENTY_CENTS_Add++;
                    }
                    else if (paidAmount == 10)
                    {
                        TEN_CENTS_Add++;
                    }
                    else
                    {
                        FIVE_CENTS_Add++;
                    }
					payment = payment + paidAmount;
				}
				else 
				{
					cout<<"Invalid denomination encountered."<<endl;
				}
			}
			int change = payment - totalPrice;
            cout <<"Your change is " << cashRegister->updateAllDenominations(FIVE_CENTS_Add, TEN_CENTS_Add, TWENTY_CENTS_Add, FIFTY_CENTS_Add,
                ONE_DOLLAR_Add, TWO_DOLLARS_Add, FIVE_DOLLARS_Add, TEN_DOLLARS_Add,
                TWENTY_DOLLARS_Add, FIFTY_DOLLARS_Add, payment, change, cashRegister) << endl;
            return true;
		}
		current = current->next;
	}
	std::cout << "Invalid food item ID. Please try again." << std::endl;
    return false;
}