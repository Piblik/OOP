#pragma once

#include <string>

class Product {
private:
	std::string title_;
	std::string cypher_;
	int count_;
public:
	Product() = default;
	Product(std::string title, std::string cypher, int count);

	const std::string& get_title() { return title_; }
	const std::string& get_cypher() { return cypher_; }
	int get_count()const noexcept { return count_; }

	void set_title(std::string name);
	void set_cypher(std::string cypher);
	void set_count(int count);

	void print() const;
};