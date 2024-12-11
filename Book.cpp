#pragma once
#include <iostream>
#include "StoreItem.cpp"
using namespace std;

class Book : public StoreItem {
    string author;

public:
    Book(const string& title, int quantity, double price, double cost, const string& author)
        : StoreItem(title, quantity, price, cost), author(author) {}

    void display() const override {
        StoreItem::display();
        cout << "Author: " << author << endl;
    }
};
