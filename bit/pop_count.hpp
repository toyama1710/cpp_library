#ifndef POP_COUNT_HPP
#define POP_COUNT_HPP

#include <cstdint>

inline int popcnt64_(uint64_t bits) {
    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
    return bits;
};
inline int popcnt64(uint64_t bits) {
#ifdef __has_builtin
    return __builtin_popcountll(bits);
#else
    return popcnt64_(bits);
#endif
};

inline int popcnt32_(uint32_t bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    bits = (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
    return bits;
};
inline int popcnt32(uint32_t bits) {
#ifdef __has_builtin
    return __builtin_popcount(bits);
#else
    return popcnt32_(bits);
#endif
};

#endif
