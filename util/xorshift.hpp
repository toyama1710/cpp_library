#include <iostream>
#include <cstdint>
#include <ctime>

//===
static uint32_t __seed__ = 1710;
uint32_t xorshift32() {
    __seed__ = __seed__ ^ (__seed__ << 13);
    __seed__ = __seed__ ^ (__seed__ >> 17);
    __seed__ = __seed__ ^ (__seed__ << 5);
    return __seed__;
}
void set_seed(uint32_t s) {
    __seed__ = s;
};
//===