#include "D2.h"

D2::D2() {
    cout << "Class D2, base: public D1\n";
    n = "D2";
}

void D2::show() {
    cout << "Object of " << n << endl;
}
