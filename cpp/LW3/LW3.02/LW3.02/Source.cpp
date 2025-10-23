#include "Header.h"

// ===== Detail =====
Detail::Detail(std::string name, double weight, double cost)
    : name_(name), weight_(weight), cost_(cost) {
}

std::string Detail::getName() const { return name_; }
double Detail::getWeight() const { return weight_; }
double Detail::getCost() const { return cost_; }

void Detail::print() const {
    std::cout << "   - " << std::setw(15) << std::left << name_
        << " | Weight: " << std::setw(6) << weight_
        << " kg | Cost: " << cost_ << " $\n";
}

// ===== Mechanism =====
Mechanism::Mechanism(std::string name)
    : name_(name), detailCount_(0) {
}

void Mechanism::addDetail(const Detail& d) {
    if (detailCount_ < MAX_DETAILS) {
        details_[detailCount_++] = d;
    }
    else {
        std::cout << "Cannot add more details (limit reached: " << MAX_DETAILS << ")\n";
    }
}

double Mechanism::totalWeight() const {
    double sum = 0;
    for (int i = 0; i < detailCount_; ++i)
        sum += details_[i].getWeight();
    return sum;
}

double Mechanism::totalCost() const {
    double sum = 0;
    for (int i = 0; i < detailCount_; ++i)
        sum += details_[i].getCost();
    return sum;
}

void Mechanism::print() const {
    std::cout << "\n--- Mechanism: " << name_ << " ---\n";
    for (int i = 0; i < detailCount_; ++i)
        details_[i].print();
    std::cout << "  Total mechanism weight: " << totalWeight() << " kg\n";
    std::cout << "  Total mechanism cost: " << totalCost() << " $\n";
}

std::string Mechanism::getName() const {
    return name_;
}

// ===== Product =====
Product::Product(std::string name)
    : name_(name), mechanismCount_(0) {
}

void Product::addMechanism(const Mechanism& m) {
    if (mechanismCount_ < MAX_MECHANISMS) {
        mechanisms_[mechanismCount_++] = m;
    }
    else {
        std::cout << "Cannot add more mechanisms (limit reached: " << MAX_MECHANISMS << ")\n";
    }
}

double Product::totalWeight() const {
    double sum = 0;
    for (int i = 0; i < mechanismCount_; ++i)
        sum += mechanisms_[i].totalWeight();
    return sum;
}

double Product::totalCost() const {
    double sum = 0;
    for (int i = 0; i < mechanismCount_; ++i)
        sum += mechanisms_[i].totalCost();
    return sum;
}

void Product::print() const {
    std::cout << "\n===== PRODUCT: " << name_ << " =====\n";
    for (int i = 0; i < mechanismCount_; ++i)
        mechanisms_[i].print();
    std::cout << "--------------------------------------\n";
    std::cout << "Total product weight: " << totalWeight() << " kg\n";
    std::cout << "Total product cost: " << totalCost() << " $\n";
}
