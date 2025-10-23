#include <iostream>
#include <limits>
#include "Trans.h"

using namespace std;

class VehicleDatabase {
private:
    Transport** vehicles;
    int size;
    int capacity;

    bool inputBool(const string& prompt) {
        int value;
        while (true) {
            cout << prompt;
            if (!(cin >> value)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter 0 or 1.\n";
                continue;
            }
            if (value == 0 || value == 1)
                return static_cast<bool>(value);
            cout << "Invalid value! Please enter 0 (no) or 1 (yes).\n";
        }
    }

public:
    VehicleDatabase(int initialCapacity = 10)
        : size(0), capacity(initialCapacity) {
        vehicles = new Transport * [capacity];
    }

    ~VehicleDatabase() {
        for (int i = 0; i < size; i++) {
            delete vehicles[i];
        }
        delete[] vehicles;
    }

    void addVehicle() {
        if (size >= capacity) {
            int newCapacity = capacity * 2;
            Transport** newVehicles = new Transport * [newCapacity];
            for (int i = 0; i < size; i++) {
                newVehicles[i] = vehicles[i];
            }
            delete[] vehicles;
            vehicles = newVehicles;
            capacity = newCapacity;
        }

        int type;
        cout << "\nSelect vehicle type:" << endl;
        cout << "1 - Car" << endl;
        cout << "2 - Motorcycle" << endl;
        cout << "3 - Truck" << endl;
        cout << "Enter choice (1-3): ";

        if (!(cin >> type)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Must be a number." << endl;
            return;
        }

        string brand, number;
        int speed, baseLoad;

        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter number: ";
        cin >> number;

        cout << "Enter speed: ";
        if (!(cin >> speed)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        cout << "Enter base load capacity: ";
        if (!(cin >> baseLoad)) {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        switch (type) {
        case 1:
            vehicles[size] = new Car(brand, number, speed, baseLoad);
            cout << "Car added successfully!" << endl;
            break;

        case 2: {
            bool hasSidecar = inputBool("Has sidecar? (1 - yes, 0 - no): ");
            vehicles[size] = new Motorcycle(brand, number, speed, baseLoad, hasSidecar);
            cout << "Motorcycle added successfully!" << endl;
            break;
        }

        case 3: {
            bool hasTrailer = inputBool("Has trailer? (1 - yes, 0 - no): ");
            vehicles[size] = new Truck(brand, number, speed, baseLoad, hasTrailer);
            cout << "Truck added successfully!" << endl;
            break;
        }

        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        size++;
    }

    void displayAll() const {
        if (size == 0) {
            cout << "\nDatabase is empty!" << endl;
            return;
        }

        cout << "\n=== ALL VEHICLES ===" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Vehicle " << (i + 1) << ":" << endl;
            vehicles[i]->display();
            cout << endl;
        }
    }

    void searchByLoadCapacity() const {
        if (size == 0) {
            cout << "\nDatabase is empty!" << endl;
            return;
        }

        int minLoad;
        cout << "\nEnter minimum load capacity: ";
        if (!(cin >> minLoad)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            return;
        }

        cout << "\n=== VEHICLES WITH LOAD CAPACITY >= " << minLoad << " ===" << endl;
        bool found = false;

        for (int i = 0; i < size; i++) {
            if (vehicles[i]->getLoadCapacity() >= minLoad) {
                cout << "Vehicle " << (i + 1) << ":" << endl;
                vehicles[i]->display();
                cout << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No vehicles found with the specified load capacity!" << endl;
        }
    }

    int getSize() const {
        return size;
    }
};

// ------------------------------------------------------------

int main() {
    VehicleDatabase db;
    int choice;

    cout << "=== VEHICLE DATABASE MANAGEMENT SYSTEM ===" << endl;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Add vehicle" << endl;
        cout << "2. Display all vehicles" << endl;
        cout << "3. Search vehicles by load capacity" << endl;
        cout << "4. Show database size" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        switch (choice) {
        case 1:
            db.addVehicle();
            break;
        case 2:
            db.displayAll();
            break;
        case 3:
            db.searchByLoadCapacity();
            break;
        case 4:
            cout << "\nTotal vehicles in database: " << db.getSize() << endl;
            break;
        case 0:
            cout << "\nGoodbye!" << endl;
            break;
        default:
            cout << "\nInvalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
