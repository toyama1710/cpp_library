#ifndef ROLLING_HASH_MONOID_HPP
#define ROLLING_HASH_MONOID_HPP

#include <vector>

//===
template<unsigned long long base, unsigned long long mod>
struct RollingHashMonoid {
    using ull = unsigned long long;
    using value_type = ull;

    struct Str {
        ull hash;
        ull len;
    };

    static std::vector<ull> pow_table;
    inline static Str identitiy() {
        return {0, 0};
    };
    inline static Str operation(const Str a, const Str b) {
        Str ret;
        ret.hash = a.hash * power(b.len) % mod + b.hash % mod;
        ret.len = a.len + b.len;
        return ret;
    };

    inline static ull power(ull n) {
        while (pow_table.size() <= n) pow_table.push_back(pow_table.back() * base % mod);
        return pow_table[n];
    };
};
template<unsigned long long base, unsigned long long mod>
std::vector<unsigned long long> RollingHashMonoid<base, mod>::pow_table(1, 1);
//===
#endif
