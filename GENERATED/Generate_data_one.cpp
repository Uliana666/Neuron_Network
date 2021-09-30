#include "iostream"
#include "random"

std::mt19937 rnd(444);
using namespace std;
typedef long double ld;

#include "bits/stdc++.h"

int main() {
    ofstream tt("test_one");
    for (int i = 0; i < 5000000; ++i) {
        ld a = ld(rnd()) / rnd.max();
        if (rnd() & 1) a = -a;
        tt << a << '\n';
        if (a < 0) tt << "0\n";
        else tt << "1\n";
    }
}


