#include "iostream"
#include "random"

std::mt19937 rnd(444);
using namespace std;
typedef long double ld;
#include "bits/stdc++.h"

int main() {
    ofstream tt("test_3");
    for (int i = 0; i < 5000000; ++i) {
        ld a = ld(rnd()) / rnd.max(), b = ld(rnd()) / rnd.max(), c = ld(rnd()) / rnd.max();
        tt << a << ' ' << b << ' ' << c << '\n';
        if (a > b && a > c) tt << "1 0 0\n";
        else if (b > a && b > c) tt << "0 1 0\n";
        else tt << "0 0 1\n";
    }
}

