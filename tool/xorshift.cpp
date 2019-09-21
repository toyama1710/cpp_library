#include <iostream>
#include <cstdint>
#include <ctime>
using namespace std;

//===
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ ( s << 5);
    return s;
}
//===

int main() {
    uint32_t n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << xorshift32() << endl;
    }

    return 0;
};
