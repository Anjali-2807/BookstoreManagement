#pragma once
#include <iostream>
using namespace std;

class Cashier {
public:
    void processTransaction(const string& itemName, int qty) {
        cout << "Processing transaction for " << qty << " unit(s) of " << itemName << ".\n";
    }
};
