#include "Money.h"
#include <iostream>
#include <stdexcept>

Money::Money(int first, int second)
{
	set_first(first);
	set_second(second);
}

void Money::set_first(int first) {
    if (first != 1 && first != 2 && first != 5 && first != 10 && first != 20 && first != 50 && first != 100) {
        throw std::invalid_argument("the denomination of banknotes isn`t real");
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
	std::cout << "denomination of bills: " << first_ << ", count of bills: " << second_ << "\n";
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