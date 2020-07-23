#include <iostream>
#include <cstdint>
#include <ctime>

//===
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ (s << 5);
    return s;
}
//===