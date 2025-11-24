#include "B3.h"

B3::B3() {
    cout << "Class B3, no base classes\n";
    n = "B3";
}

void B3::show() {
    cout << "Object of " << n << endl;
}
