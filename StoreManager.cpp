#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Book.cpp"
#include "Magazine.cpp"
using namespace std;

class StoreManager {
    string name;
    vector<unique_ptr<StoreItem>> inventory;

public:
    StoreManager(const string& name) : name(name) {}
    string getName() const {
    return name;
}


    void addItemToInventory(unique_ptr<StoreItem> item) {
        inventory.push_back(std::move(item));
    }

    void displayInventory() const {
        if (inventory.empty()) {
            cout << "Inventory is empty.\n";
        } else {
            for (const auto& item : inventory) {
                item->display();
                cout << endl;
            }
        }
    }

    StoreItem* findItem(const string& itemName) {
        for (auto& item : inventory) {
            if (item->getTitle() == itemName) {
                return item.get();
            }
        }
        return nullptr;
    }
};
