#include "Trans.h"
#include <iostream>

using namespace std;

Car::Car(const string& b, const string& n, int s, int l)
    : brand(b), number(n), speed(s), load(l) {
}

void Car::display() const {
    cout << "Car: brand=" << brand
        << ", number=" << number
        << ", speed=" << speed
        << ", load capacity=" << load << endl;
}

int Car::getLoadCapacity() const {
    return load;
}

Motorcycle::Motorcycle(const string& b, const string& n, int s, int l, bool sidecar)
    : brand(b), number(n), speed(s), load(l), hasSidecar(sidecar) {
}

void Motorcycle::display() const {
    cout << "Motorcycle: brand=" << brand
        << ", number=" << number
        << ", speed=" << speed
        << ", load capacity=" << getLoadCapacity()
        << ", sidecar=" << (hasSidecar ? "yes" : "no") << endl;
}

int Motorcycle::getLoadCapacity() const {
    return hasSidecar ? load : load / 2;
}

Truck::Truck(const string& b, const string& n, int s, int l, bool trailer)
    : brand(b), number(n), speed(s), load(l), hasTrailer(trailer) {
}

void Truck::display() const {
    cout << "Truck: brand=" << brand
        << ", number=" << number
        << ", speed=" << speed
        << ", load capacity=" << getLoadCapacity()
        << ", trailer=" << (hasTrailer ? "yes" : "no") << endl;
}

int Truck::getLoadCapacity() const {
    return hasTrailer ? load * 2 : load;
}
