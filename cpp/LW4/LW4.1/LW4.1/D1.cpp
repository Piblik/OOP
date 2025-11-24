#include "D1.h"

D1::D1() {
    cout << "Class D1, base: public B1, public B2, private B3\n";
    n = "D1";
}

void D1::show() {
    cout << "Object of " << n << endl;
}
