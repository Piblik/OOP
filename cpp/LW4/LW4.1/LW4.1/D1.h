#pragma once
#include "B1.h"
#include "B2.h"
#include "B3.h"

class D1 : public B1, public B2, private B3 {
public:
    string n;
    D1();
    void show();
};
