#ifndef MSB_HPP
#define MSB_HPP

#include <cstdint>

inline uint64_t msb32_(uint64_t x) {
    int r = 0;
    if (x >> 16) x >>= 16, r |= 16;
    if (x >> 8) x >>= 8, r |= 8;
    if (x >> 4) x >>= 4, r |= 4;
    if (x >> 2) x >>= 2, r |= 2;
    return 1u << (r | (x >> 1));
};
inline uint32_t msb32(uint32_t x) {
    if (x == 0) return 0;
#ifdef __has_builtin
    return 1u << (31 - __builtin_clz(x));
#else
    return msb32_(x);
#endif
};

inline uint64_t msb64_(uint64_t x) {
    int r = 0;
    if (x >> 32) x >>= 32, r |= 32;
    if (x >> 16) x >>= 16, r |= 16;
    if (x >> 8) x >>= 8, r |= 8;
    if (x >> 4) x >>= 4, r |= 4;
    if (x >> 2) x >>= 2, r |= 2;
    return 1ull << (r | (x >> 1));
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