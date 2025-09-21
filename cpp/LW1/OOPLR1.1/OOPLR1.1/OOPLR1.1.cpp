#include <iostream>
#include "Product.h"

int main()
{
    try {
        Product p1;
        p1.set_title("Beer");
        p1.set_cypher("12L5HG03");
        p1.set_count(52);
        p1.print();

        Product p2("Ice scream", "13LSH6J0", 112);
        std::cout << p2.get_title() << " Cypher: " << p2.get_cypher() << " Count: " << p2.get_count() << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Eror: " << ex.what() << "\n";
    }
    return 0;
}