#ifndef CTZ_HPP
#define CTZ_HPP

#include <cstdint>

inline int ctz32_(uint64_t x) {
    int r = 0;
    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;
    if (!(x & 0x00ff)) x >>= 8, r |= 8;
    if (!(x & 0x0f)) x >>= 4, r |= 4;
    if (!(x & 0x3)) x >>= 2, r |= 2;
    return r | ((x & 1) ^ 1);
};
inline int ctz32(uint32_t x) {
    if (x == 0) return 32;
#ifdef __has_builtin
    return __builtin_ctz(x);
#else
    return ctz32_(x);
#endif
};

inline int ctz64_(uint64_t x) {
    int r = 0;
    if (!(x & 0x00000000ffffffff)) x >>= 32, r |= 32;
    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;
    if (!(x & 0x00ff)) x >>= 8, r |= 8;
    if (!(x & 0x0f)) x >>= 4, r |= 4;
    if (!(x & 0x3)) x >>= 2, r |= 2;
    return r | ((x & 1) ^ 1);
};
inline int ctz64(uint64_t x) {
    if (x == 0) return 64;
#ifdef __has_builtin
    return __builtin_ctzll(x);
#else
    return ctz64_(x);
#endif
};

#endif