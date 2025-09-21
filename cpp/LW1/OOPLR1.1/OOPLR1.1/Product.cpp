#include "Product.h"
#include <iostream>
#include <stdexcept>

Product::Product(std::string title, std::string cypher, int count)

{
	set_title(title_);
	set_cypher(cypher_);
	set_count(count_);
}

void Product::set_title(std::string title) {
	if (title.empty())
		throw std::invalid_argument("Title cannot be empty");
	title_ = std::move(title);
}

void Product::set_cypher(std::string cypher) {
	if (cypher.empty())
		throw std::invalid_argument("Cypher cannot be empty");
	cypher_ = std::move(cypher);
}

void Product::set_count(int count) {
	if (count < 0)
		throw std::invalid_argument("the number cannot be less than zero");
	count_ = count;
}

void Product::print() const {
	std::cout << "Product{title=\"" << title_
		<< "\", cypher=\"" << cypher_
		<< "\", count=" << count_
		<< "\n";
}