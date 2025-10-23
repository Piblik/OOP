#pragma once
#include <iostream>
#include <string>

class Transport {
public:
    virtual void display() const = 0;
    virtual int getLoadCapacity() const = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
private:
    std::string brand;
    std::string number;
    int speed;
    int load;
public:
    Car(const std::string& b, const std::string& n, int s, int l);
    void display() const override;
    int getLoadCapacity() const override;
};

class Motorcycle : public Transport {
private:
    std::string brand;
    std::string number;
    int speed;
    int load;
    bool hasSidecar;
public:
    Motorcycle(const std::string& b, const std::string& n, int s, int l, bool sidecar);
    void display() const override;
    int getLoadCapacity() const override;
};

class Truck : public Transport {
private:
    std::string brand;
    std::string number;
    int speed;
    int load;
    bool hasTrailer;
public:
    Truck(const std::string& b, const std::string& n, int s, int l, bool trailer);
    void display() const override;
    int getLoadCapacity() const override;
};
