#include "B2.h"

B2::B2() {
    cout << "Class B2, no base classes\n";
    n = "B2";
}

void B2::show() {
    cout << "Object of " << n << endl;
}
