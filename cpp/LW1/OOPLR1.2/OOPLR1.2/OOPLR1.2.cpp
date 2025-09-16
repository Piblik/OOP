#include <iostream>
#include "Money.h"


int main()
{
    int f = 0, s = 0;
    std::cout << "Enter denomination of bills: ";
    std::cin >> f;
    std::cout << "Enter count of bills: ";
    std::cin >> s;
    try {
        Money m1;
        m1.set_first(f);
        m1.set_second(s);
        Money m2(f, s);
        std::cout << "denomination of bills: " << m2.first() << "count of bills: " << m2.second() << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Eror" << ex.what() << "\n";
    }
    
}