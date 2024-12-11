#pragma once
#include<iostream>
#include <string>
using namespace std;

class StoreItem {
protected:
    string title;
    int quantity;
    double price;
    double cost;

public:
    StoreItem(const string& title, int quantity, double price, double cost)
        : title(title), quantity(quantity), price(price), cost(cost) {}

    virtual ~StoreItem() = default;

    virtual void display() const {
        cout << "Title: " << title << ", Quantity: " << quantity << ", Price: Rs. " << price << ", Cost: Rs. " << cost << endl;
    }

    void restock(int amount) {
        quantity += amount;
    }

    string getTitle() const {
        return title;
    }

    int getQuantity() const {
        return quantity;
    }

    void reduceQuantity(int amount) {
        if (amount <= quantity) {
            quantity -= amount;
        }
    }
};
