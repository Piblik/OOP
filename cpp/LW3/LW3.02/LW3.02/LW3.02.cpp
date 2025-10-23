#include <iostream>
#include "Header.h"

void showMenu() {
    std::cout << "\n========== MENU ==========\n";
    std::cout << "1. Add a mechanism\n";
    std::cout << "2. Add a detail to a mechanism\n";
    std::cout << "3. Show product info\n";
    std::cout << "4. Show total weight and cost\n";
    std::cout << "0. Exit\n";
    std::cout << "==========================\n";
    std::cout << "Your choice: ";
}

int main() {
    Product product("My Product");
    Mechanism mechanisms[MAX_MECHANISMS];
    int mechCount = 0;

    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            if (mechCount >= MAX_MECHANISMS) {
                std::cout << "Cannot add more mechanisms!\n";
                break;
            }
            std::string mechName;
            std::cout << "Enter mechanism name: ";
            std::cin >> mechName;
            mechanisms[mechCount++] = Mechanism(mechName);
            std::cout << "Mechanism added!\n";
            break;
        }

        case 2: {
            if (mechCount == 0) {
                std::cout << "Add a mechanism first!\n";
                break;
            }
            std::cout << "Select a mechanism:\n";
            for (int i = 0; i < mechCount; ++i)
                std::cout << i + 1 << ". " << mechanisms[i].getName() << "\n";

            int idx;
            std::cin >> idx;
            if (idx < 1 || idx > mechCount) {
                std::cout << "Invalid index!\n";
                break;
            }

            std::string name;
            double w, c;
            std::cout << "Detail name: "; std::cin >> name;
            std::cout << "Weight (kg): "; std::cin >> w;
            std::cout << "Cost ($): "; std::cin >> c;

            mechanisms[idx - 1].addDetail(Detail(name, w, c));
            break;
        }

        case 3: {
            Product temp("My Product");
            for (int i = 0; i < mechCount; ++i)
                temp.addMechanism(mechanisms[i]);
            temp.print();
            break;
        }

        case 4: {
            Product temp("My Product");
            for (int i = 0; i < mechCount; ++i)
                temp.addMechanism(mechanisms[i]);
            std::cout << "\nTotal product weight: " << temp.totalWeight() << " kg\n";
            std::cout << "Total product cost: " << temp.totalCost() << " $\n";
            break;
        }

        case 0:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid option!\n";
        }

    } while (choice != 0);

    return 0;
}
