#include "Money.h"
#include <iostream>
#include <stdexcept>

Money::Money(int first, int second)
{
	set_first(first);
	set_second(second);
}

void Money::set_first(int first) {
	if (first <= 0)
		throw std::invalid_argument("the denomination of banknotes cannot be less than zero");
	first_ = first;
}

void Money::set_second(int second) {
	if (second < 0)
		throw std::invalid_argument("the number of bills cannot be less than zero");
	second_ = second;
}

void Money::print() const {
	std::cout << "denomination of bills: " << first_ << ", count of bills: " << second_ << "\n";
}