#include <iostream>
#include "B1.h"
#include "B2.h"
#include "B3.h"
#include "D1.h"
#include "D2.h"

using namespace std;

void menu() {
    cout << "\n============== M E N U ==============\n";
    cout << "1 Show B1\n";
    cout << "2 Show B2\n";
    cout << "3 Show B3\n";
    cout << "4 Show D1\n";
    cout << "5 Show D2\n";
    cout << "0 Exit\n";
    cout << "Your choice: ";
}

int main() {
    int choice;

    do {
        menu();
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            B1 o;
            o.show();
            break;
        }
        case 2: {
            B2 o;
            o.show();
            break;
        }
        case 3: {
            B3 o;
            o.show();
            break;
        }
        case 4: {
            D1 o;
            o.show();
            break;
        }
        case 5: {
            D2 o;
            o.show();
            break;
        }
        case 0:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

        cout << "\n-------------------------------------\n";

    } while (choice != 0);

    return 0;
}
