#pragma once
#include <iostream>
#include "StoreManager.cpp"
using namespace std;

class Customer {
    string name;

public:
    Customer(const string& name) : name(name) {}

    void buyBook(StoreManager& manager, const string& itemName, int qty) {
        StoreItem* item = manager.findItem(itemName);
        if (item && item->getQuantity() >= qty) {
            item->reduceQuantity(qty);
            cout << name << " bought " << qty << " units of " << itemName << ".\n";
        } else if (item) {
            cout << "Not enough quantity available for " << itemName << ".\n";
        } else {
            cout << "Item " << itemName << " not found.\n";
        }
    }
};
