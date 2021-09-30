#include "iostream"
#include "random"

std::mt19937 rnd(444);
using namespace std;
typedef long double ld;

#include "bits/stdc++.h"

int main() {
    ofstream tt("test_multi");
    for (int i = 0; i < 5000000; ++i) {
        ld a = ld(rnd()) / rnd.max(), b = ld(rnd()) / rnd.max();
        if (rnd() & 1) a = -a;
        if (rnd() & 1) b = -b;
        tt << a << ' ' << b << '\n';
        if (a * b < 0) tt << "0 1\n";
        else tt << "1 0\n";
    }
}
