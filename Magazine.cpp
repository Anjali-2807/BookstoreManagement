#pragma once
#include <iostream>
#include "StoreItem.cpp"
using namespace std;

class Magazine : public StoreItem {
    int year;

public:
    Magazine(const string& title, int quantity, double price, double cost, int year)
        : StoreItem(title, quantity, price, cost), year(year) {}

    void display() const override {
        StoreItem::display();
        cout << "Year: " << year << endl;
    }
};
