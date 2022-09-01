#ifndef LSB_HPP
#define LSB_HPP

#include <cstdint>

inline uint64_t lsb32(uint32_t bits) {
    return bits & (~bits + 1);
};
inline uint64_t lsb64(uint64_t bits) {
    return bits & (~bits + 1);
};
#endif