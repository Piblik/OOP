#pragma once
#include <iostream>
#include <iomanip>
#include <string>

const int MAX_DETAILS = 10;
const int MAX_MECHANISMS = 10;

class Detail {
private:
    std::string name_;
    double weight_;
    double cost_;
public:
    Detail(std::string name = "None", double weight = 0, double cost = 0);
    std::string getName() const;
    double getWeight() const;
    double getCost() const;
    void print() const;
};

class Mechanism {
private:
    std::string name_;
    Detail details_[MAX_DETAILS];
    int detailCount_;
public:
    Mechanism(std::string name = "Mechanism");
    void addDetail(const Detail& d);
    double totalWeight() const;
    double totalCost() const;
    void print() const;
    std::string getName() const;
};

class Product {
private:
    std::string name_;
    Mechanism mechanisms_[MAX_MECHANISMS];
    int mechanismCount_;
public:
    Product(std::string name = "Product");
    void addMechanism(const Mechanism& m);
    double totalWeight() const;
    double totalCost() const;
    void print() const;
};
