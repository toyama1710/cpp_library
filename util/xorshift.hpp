#ifndef XORSHIFT_HPP
#define XORSHIFT_HPP

#include <cstdint>

struct xorshift32 {
    uint32_t seed;
    xorshift32(uint32_t seed = 1710) : seed(seed){};
    void set_seed(uint32_t s) { seed = s; };
    uint32_t gen() {
        seed = seed ^ (seed << 13);
        seed = seed ^ (seed >> 17);
        seed = seed ^ (seed << 5);
        return seed;
    };
    uint32_t operator()() { return gen(); };
};

struct xorshift64 {
    uint64_t seed;
    xorshift64(uint64_t seed = 1710) : seed(seed){};
    void set_seed(uint64_t s) { seed = s; };
    uint64_t gen() {
        seed = seed ^ (seed << 13);
        seed = seed ^ (seed >> 7);
        seed = seed ^ (seed << 17);
        return seed;
    };
    uint64_t operator()() { return gen(); };
};

#endif