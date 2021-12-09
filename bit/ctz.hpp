#ifndef CTZ_HPP
#define CTZ_HPP

#include <cstdint>

inline int ctz32_(uint32_t bit) {
    static const int table[] = {
        0,  1, 2,  6,  3,  11, 7,  16, 4,  14, 12, 21, 8,  23, 17, 26,
        31, 5, 10, 15, 13, 20, 22, 25, 30, 9,  19, 24, 29, 18, 28, 27,
    };
    static const uint32_t de_bruijn = 0x04653adf;
    bit &= ~bit + 1;
    return table[(bit * de_bruijn) >> 27];
};
inline int ctz32(uint32_t bit) {
    if (bit == 0) return 32;
#ifdef __has_builtin
    return __builtin_ctz(bit);
#else
    return ctz32_(bit);
#endif
};

inline int ctz64_(uint64_t bit) {
    static const int table[] = {
        0,  1,  2,  7,  3,  13, 8,  19, 4,  25, 14, 28, 9,  34, 20, 40,
        5,  17, 26, 38, 15, 46, 29, 48, 10, 31, 35, 54, 21, 50, 41, 57,
        63, 6,  12, 18, 24, 27, 33, 39, 16, 37, 45, 47, 30, 53, 49, 56,
        62, 11, 23, 32, 36, 44, 52, 55, 61, 22, 43, 51, 60, 42, 59, 58,
    };
    static const uint64_t de_bruijn = 0x0218a392cd3d5dbfull;
    bit &= ~bit + 1;
    return table[(bit * de_bruijn) >> 58];
};
inline int ctz64(uint64_t bit) {
    if (bit == 0) return 64;
#ifdef __has_builtin
    return __builtin_ctzll(bit);
#else
    return ctz64_(bit);
#endif
};

#endif
