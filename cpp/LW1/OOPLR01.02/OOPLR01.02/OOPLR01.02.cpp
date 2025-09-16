#include <iostream>
#include "Money.h"


int main()
{
    const int laptopPrice = 700, pcPrice = 1200, mousePrice = 150;
    int product = 0;
    int f = 0, s = 0;
    std::cout << "Hello\nEnter denomination of bills: ";
    std::cin >> f;
    std::cout << "Enter count of bills: ";
    std::cin >> s;
    try {
        while (true) {
            int menu = 0;
            std::cout << "Select a menu item:\n1.Update information\n2.Current information\n3.Has enough money\n4.Items can buy\n0.Exit\n";
            std::cin >> menu;
            Money m1;
            m1.set_first(f);
            m1.set_second(s);
            switch (menu) {
            case 1:
                std::cout << "Enter denomination of bills: ";
                std::cin >> f;
                std::cout << "Enter count of bills: ";
                std::cin >> s;
                m1.set_first(f);
                m1.set_second(s);
                m1.print();
                break;
            case 2:
                m1.print();
                break;
            case 3: 
                std::cout << "Select a product:\n1.Laptop\n2.PC\n3.Mouse\n";
                std::cin >> product;
                switch (product) {
                case 1:
                    if (laptopPrice < (f * s)) 
                        std::cout << "You have enough money for laptop\n";
                    else
                        std::cout << "You don't have enough money for a laptop\n";
                    break;
                case 2:
                    if (pcPrice < (f * s))
                        std::cout << "You have enough money for PC\n";
                    else
                        std::cout << "You don't have enough money for a PC\n";
                    break;
                case 3:
                    if (mousePrice < (f * s))
                        std::cout << "You have enough money for mouse\n";
                    else
                        std::cout << "You don't have enough money for a mouse\n";
                    break;
                }
                break;
            case 4:
                int sum = 0;
                int ICBCount = 0;
                std::cout << "Select a product:\n1.Laptop\n2.PC\n3.Mouse\n";
                std::cin >> product;
                sum = f * s;
                switch (product) {
                case 1:
                    if (laptopPrice < (f * s)) {
                        while (sum > laptopPrice) {
                            ICBCount++;
                            sum -= laptopPrice;
                        }
                    }
                    else
                        std::cout << "You don't have enough money for a laptop\n";
                    break;
                case 2:
                    if (pcPrice < (f * s)) {
                        while (sum > pcPrice) {
                            ICBCount++;
                            sum -= pcPrice;
                        }
                    }
                    else
                        std::cout << "You don't have enough money for a PC\n";
                    break;
                case 3:
                    if (pcPrice < (f * s)) {
                        while (sum > mousePrice) {
                            ICBCount++;
                            sum -= mousePrice;
                        }
                    }
                    else
                        std::cout << "You don't have enough money for a mouse\n";
                    break;
                }
                std::cout << "You can buy " << ICBCount;
                break;

            }
        }
        Money m2(f, s);
        std::cout << "denomination of bills: " << m2.get_first() << ", count of bills: " << m2.get_second() << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error" << ex.what() << "\n";
    }

}