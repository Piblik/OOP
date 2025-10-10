#include "Money.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

Money::Money(int first, int second) {
    set_first(first);
    set_second(second);
}

void Money::set_first(int first) {
    if (first != 1 && first != 2 && first != 5 && first != 10 && first != 20 && first != 50 && first != 100) {
        throw std::invalid_argument("the denomination of banknotes isn't real");
    }
    first_ = first;
}

void Money::set_second(int second) {
    if (second < 0) {
        throw std::invalid_argument("the number of bills cannot be less than zero");
    }
    second_ = second;
}

void Money::print() const {
    std::cout << "denomination of bills: " << first_
        << ", count of bills: " << second_ << "\n";
}

void inputInfo(int& s, int& f) {
    bool valid = false;
    while (!valid) {
        std::cout << "Hello\nEnter denomination of bills: ";
        std::cin >> f;
        std::cout << "Enter count of bills: ";
        std::cin >> s;

        try {
            Money tmp;
            tmp.set_first(f);
            tmp.set_second(s);
            valid = true;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\nTry again!\n";
        }
    }
}

Money& Money::operator++() {
    ++second_;
    switch (first_) {
    case 1: {
        first_ = 2;
        break;
    }
    case 2: {
        first_ = 5;
        break;
    }
    case 5: {
        first_ = 10;
        break;
    }
    case 10: {
        first_ = 20;
        break;
    }
    case 20: {
        first_ = 50;
        break;
    }
    case 50: {
        first_ = 100;
        break;
    }
    case 100: {
        std::cout << "100 = max value for first";
        break;
    }
    default: {
        std::cout << "Eror, incorrect first";
    }
    }
    return *this;
}

Money Money::operator++(int) {
    Money temp = *this;
    ++(*this);
    return temp;
}

Money& Money::operator--() {
    --second_;
    switch (first_) {
    case 1: {
        std::cout << "1 = min value for first";
        break;
    }
    case 2: {
        first_ = 1;
        break;
    }
    case 5: {
        first_ = 2;
        break;
    }
    case 10: {
        first_ = 5;
        break;
    }
    case 20: {
        first_ = 10;
        break;
    }
    case 50: {
        first_ = 20;
        break;
    }
    case 100: {
        first_ = 50;
        break;
    }
    default: {
        std::cout << "Eror, incorrect first";
    }
    }
    return *this;
}

Money Money::operator--(int) {
    Money temp = *this;
    --(*this);
    return temp;
}

bool Money::operator!() const {
    return second_ != 0;
}

Money Money::operator+(int scalar) const {
    return Money(first_, second_ + scalar);
}

Money::operator std::string() const {
    std::ostringstream oss;
    oss << first_ << " " << second_;
    return oss.str();
}

Money Money::fromString(const std::string& str) {
    std::istringstream iss(str);
    int f, s;
    iss >> f >> s;
    return Money(f, s);
}
