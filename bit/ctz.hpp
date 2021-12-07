#ifndef CTZ_HPP
#define CTZ_HPP

#include <cstdint>

inline int ctz32(uint32_t x) {
#ifdef __has_builtin
    if (x == 0)
        return 32;
    else
        return __builtin_ctz(x);
#else
    int r = 0;
    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;
    if (!(x & 0x00ff)) x >>= 8, r |= 8;
    if (!(x & 0x0f)) x >>= 4, r |= 4;
    if (!(x & 0x3)) x >>= 2, r |= 2;
    if (!(x & 1)) x >>= 1, r |= 1;
    return r + ((x & 1) ^ 1);
#endif
};
inline int ctz64(uint64_t x) {
#ifdef __has_builtin
    if (x == 0)
        return 64;
    else
        return __builtin_ctzll(x);
#else
    int r = 0;
    if (!(x & 0x00000000ffffffff)) x >>= 32, r |= 32;
    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;
    if (!(x & 0x00ff)) x >>= 8, r |= 8;
    if (!(x & 0x0f)) x >>= 4, r |= 4;
    if (!(x & 0x3)) x >>= 2, r |= 2;
    if (!(x & 1)) x >>= 1, r |= 1;
    return r + ((x & 1) ^ 1);
#endif
};

#endif