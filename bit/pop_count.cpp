#include <iostream>
#include <cstdio>
#include <cstdint>
using namespace std;

//===
// #include<cstdint>
/*
int popcnt32(uint32_t bits) {
    int ret;
    __asm__ ("popcntl %[input], %[output]" : [output] "=r"(ret) : [input] "r"(bits));
    return ret;
}
*/
int popcnt32(uint32_t bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    bits = (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
    return bits;
}
//===

int main() {
    uint32_t a;

    cin >> a;
    cout << popcnt32(a) << endl;

    return 0;
}
