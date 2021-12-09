#ifndef CLZ_HPP
#define CLZ_HPP

#include <cstdint>

inline int clz32_(uint32_t bit) {
    static const int table[] = {
        31, 30, 29, 25, 28, 20, 24, 15, 27, 17, 19, 10, 23, 8,  14, 5,
        0,  26, 21, 16, 18, 11, 9,  6,  1,  22, 12, 7,  2,  13, 3,  4,
    };
    static const uint32_t de_bruijn = 0x04653adf;

    bit |= bit >> 1;
    bit |= bit >> 2;
    bit |= bit >> 4;
    bit |= bit >> 8;
    bit |= bit >> 16;
    bit ^= bit >> 1;
    return table[(bit * de_bruijn) >> 27];
};
inline int clz32(uint32_t bit) {
    if (bit == 0) return 32;
#ifdef __has_builtin
    return __builtin_clz(bit);
#else
    return clz32_(bit);
#endif
};

inline int clz64_(uint64_t bit) {
    static const int table[] = {
        63, 62, 61, 56, 60, 50, 55, 44, 59, 38, 49, 35, 54, 29, 43, 23,
        58, 46, 37, 25, 48, 17, 34, 15, 53, 32, 28, 9,  42, 13, 22, 6,
        0,  57, 51, 45, 39, 36, 30, 24, 47, 26, 18, 16, 33, 10, 14, 7,
        1,  52, 40, 31, 27, 19, 11, 8,  2,  41, 20, 12, 3,  21, 4,  5,
    };
    static const uint64_t de_bruijn = 0x0218a392cd3d5dbfull;
    bit |= bit >> 1;
    bit |= bit >> 2;
    bit |= bit >> 4;
    bit |= bit >> 8;
    bit |= bit >> 16;
    bit |= bit >> 32;
    bit ^= bit >> 1;
    return table[(bit * de_bruijn) >> 58];
};
inline int clz64(uint64_t bit) {
    if (bit == 0) return 64;
#ifdef __has_builtin
    return __builtin_clzll(bit);
#else
    return clz64_(bit);
#endif
};

#endif
