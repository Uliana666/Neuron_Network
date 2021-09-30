#include "iostream"
#include "random"

std::mt19937 rnd(444);
using namespace std;
typedef long double ld;

#include "bits/stdc++.h"

int main() {
    ofstream tt("test_sphere_output3");
    for (int i = 0; i < 5000000; ++i) {
        ld a = ld(rnd()) / rnd.max();
        ld b = ld(rnd()) / rnd.max();
        ld c = ld(rnd()) / rnd.max();
        //if (rnd() & 1) a = -a;
        //if (rnd() & 1) b = -b;
        if (rnd() & 1) a /= 3;
        if (rnd() & 1) b /= 3;
        if (rnd() & 1) c /= 3;
        tt << a << ' ' << b << ' ' << c << '\n';
        if (sqrt(a * a + b * b + c * c) <= 0.6) tt << "1 0 0\n";
        else
            tt << "0 1 0\n";
    }
}




