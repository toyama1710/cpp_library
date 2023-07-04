#ifndef MOD_BINOMIAL_HPP
#define MOD_BINOMIAL_HPP

#include <cassert>
#include <cstdint>
#include <vector>

#include "modint.hpp"

// nCr mod p
// p is prime
template <uint64_t p>
ModInt<p> binomial(uint64_t n, uint64_t r) {
    assert(r <= n);
    static std::vector<ModInt<p>> fact;
    auto f = [&](auto &&f, uint64_t n) -> ModInt<p> {
        if (fact.size() > n) return fact[n];

        if (n == 0)
            fact.push_back(1);
        else
            fact.push_back(f(f, n - 1) * n);

        return fact[n];
    };

    return f(f, n) / f(f, r) / f(f, n - r);
};

#endif
