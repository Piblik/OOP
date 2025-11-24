#include "B1.h"

B1::B1() {
    cout << "Class B1, no base classes\n";
    n = "B1";
}

void B1::show() {
    cout << "Object of " << n << endl;
}
