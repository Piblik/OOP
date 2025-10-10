#include <iostream>
#include <string>
#include "Money.h"

int main()
{
    const int laptopPrice = 700, pcPrice = 1200, mousePrice = 150;
    int product = 0;
    int f = 0, s = 0;

    try {
        Money m1;
        bool running = true;

        while (running) {
            int menu = 0;
            std::cout << "\nSelect a menu item:\n"
                << "1. Update information\n"
                << "2. Current information\n"
                << "3. Has enough money\n"
                << "4. Items can buy\n"
                << "5. LW2\n"
                << "0. Exit\n";
            std::cin >> menu;

            switch (menu) {
            case 1: {
                inputInfo(s, f);
                m1.set_first(f);
                m1.set_second(s);
                m1.print();
                break;
            }
            case 2: {
                m1.print();
                break;
            }
            case 3: {
                std::cout << "Select a product:\n"
                    << "1. Laptop (" << laptopPrice << ")\n"
                    << "2. PC (" << pcPrice << ")\n"
                    << "3. Mouse (" << mousePrice << ")\n";
                std::cin >> product;

                int total = f * s;

                switch (product) {
                case 1:
                    if (total >= laptopPrice)
                        std::cout << "You have enough money for laptop\n";
                    else
                        std::cout << "You don't have enough money for a laptop\n";
                    break;
                case 2:
                    if (total >= pcPrice)
                        std::cout << "You have enough money for PC\n";
                    else
                        std::cout << "You don't have enough money for a PC\n";
                    break;
                case 3:
                    if (total >= mousePrice)
                        std::cout << "You have enough money for mouse\n";
                    else
                        std::cout << "You don't have enough money for a mouse\n";
                    break;
                default:
                    std::cout << "Incorrect input\n";
                    break;
                }
                break;
            }
            case 4: {
                int sum = f * s;
                int ICBCount = 0;
                std::cout << "Select a product:\n"
                    << "1. Laptop (" << laptopPrice << ")\n"
                    << "2. PC (" << pcPrice << ")\n"
                    << "3. Mouse (" << mousePrice << ")\n";
                std::cin >> product;

                switch (product) {
                case 1:
                    if (sum >= laptopPrice) {
                        while (sum >= laptopPrice) {
                            ICBCount++;
                            sum -= laptopPrice;
                        }
                    }
                    else
                        std::cout << "You don't have enough money for a laptop\n";
                    break;
                case 2:
                    if (sum >= pcPrice) {
                        while (sum >= pcPrice) {
                            ICBCount++;
                            sum -= pcPrice;
                        }
                    }
                    else
                        std::cout << "You don't have enough money for a PC\n";
                    break;
                case 3:
                    if (sum >= mousePrice) {
                        while (sum >= mousePrice) {
                            ICBCount++;
                            sum -= mousePrice;
                        }
                    }
                    else
                        std::cout << "You don't have enough money for a mouse\n";
                    break;
                default:
                    std::cout << "Incorrect input\n";
                    break;
                }

                std::cout << "You can buy " << ICBCount << "\n";
                break;
            }
            case 5: {
                ++m1;
                std::cout << "After ++: ";
                m1.print();

                m1--;
                std::cout << "After --: ";
                m1.print();

                if (!m1)
                    std::cout << "second is not zero\n";
                else
                    std::cout << "Second is zero\n";

                int scalar = 0;
                std::cout << "Enter Scalar: ";
                std::cin >> scalar;
                Money m3 = m1 + scalar;
                m3.print();

                std::string str = (std::string)m3;
                std::cout << "As string: " << str << "\n";

                Money m4 = Money::fromString("50 7");
                std::cout << "From string: ";
                m4.print();
                break;
            }
            case 0: {
                running = false;
                break;
            }
            default: {
                std::cout << "Incorrect input\n";
                break;
            }
            }
        }

        Money m2(f, s);
        std::cout << "denomination of bills: " << m2.get_first()
            << ", count of bills: " << m2.get_second() << "\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}
