#include <iostream>
#include <memory>
#include "StoreManager.cpp"
#include "Customer.cpp"
#include "Cashier.cpp"

using namespace std;

int main() {
    StoreManager manager("Anjali");

    auto book1 = make_unique<Book>("The Alchemist", 50, 350, 150, "Paulo Coelho");
    auto book2 = make_unique<Book>("Pride and Prejudice", 30, 399, 180, "Jane Austen");
    auto mag1 = make_unique<Magazine>("Time Magazine", 100, 200, 90, 2023);

    manager.addItemToInventory(std::move(book1));  
    manager.addItemToInventory(std::move(book2));  
    manager.addItemToInventory(std::move(mag1));   

    cout << "Welcome to " << manager.getName() << "'s Bookstore!" << endl;

    while (true) {
        int choice;
        cout << "--- Menu ---\n";
        cout << "1. Display Inventory\n";
        cout << "2. Buy an Item\n";
        cout << "3. Add a New Book\n";
        cout << "4. Add a New Magazine\n";
        cout << "5. Restock an Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();  

        if (choice == 1) {
            manager.displayInventory();
        } else if (choice == 2) {
            string itemName, name;
            int qty;
            cout << "Enter the name of the item you want to buy: ";
            getline(cin, itemName);
            cout << "Enter the quantity: ";
            cin >> qty;
            cin.ignore();  
            cout << "Enter your name: ";
            getline(cin, name);
            Customer customer(name);
            customer.buyBook(manager, itemName, qty);
        } else if (choice == 3) {
            string title, author;
            int quantity;
            double price, cost;
            cout << "Enter title of the book: ";
            getline(cin, title);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter cost: ";
            cin >> cost;
            cin.ignore();  
            cout << "Enter author: ";
            getline(cin, author);

            auto newBook = make_unique<Book>(title, quantity, price, cost, author);
            manager.addItemToInventory(std::move(newBook));  
        } else if (choice == 4) {
            string title;
            int quantity, year;
            double price, cost;
            cout << "Enter title of the magazine: ";
            getline(cin, title);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter cost: ";
            cin >> cost;
            cout << "Enter year: ";
            cin >> year;
            cin.ignore();  

            auto newMagazine = make_unique<Magazine>(title, quantity, price, cost, year);
            manager.addItemToInventory(std::move(newMagazine));  
        } else if (choice == 5) {
            string itemName;
            int restockQty;
            cout << "Enter the name of the item to restock: ";
            getline(cin, itemName);
            cout << "Enter the quantity to add: ";
            cin >> restockQty;
            cin.ignore();  

            StoreItem* item = manager.findItem(itemName);
            if (item) {
                item->restock(restockQty);
                cout << "Restocked " << restockQty << " units of " << itemName << ".\n";
            } else {
                cout << "Item not found in inventory!\n";
            }
        } else if (choice == 6) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
