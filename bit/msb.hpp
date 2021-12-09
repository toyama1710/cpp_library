#ifndef MSB_HPP
#define MSB_HPP

#include <cstdint>

inline uint32_t msb32_(uint32_t bit) {
    bit |= bit >> 1;
    bit |= bit >> 2;
    bit |= bit >> 4;
    bit |= bit >> 8;
    bit |= bit >> 16;
    return bit ^ (bit >> 1);
};
inline uint32_t msb32(uint32_t x) {
    if (x == 0) return 0;
#ifdef __has_builtin
    return 1u << (31 - __builtin_clz(x));
#else
    return msb32_(x);
#endif
};

inline uint64_t msb64_(uint64_t bit) {
    bit |= bit >> 1;
    bit |= bit >> 2;
    bit |= bit >> 4;
    bit |= bit >> 8;
    bit |= bit >> 16;
    bit |= bit >> 32;
    return bit ^ (bit >> 1);
};
inline uint64_t msb64(uint64_t x) {
    if (x == 0) return 0;
#ifdef __has_builtin
    return 1ull << (63 - __builtin_clzll(x));
#else
    return msb64_(x);
#endif
};

#endif
