#ifndef MODINT_HPP
#define MODINT_HPP

#include <iostream>

template <uint64_t p>
struct ModInt {
    using u64 = unsigned long long;
    using i64 = long long;
    u64 d;

    ModInt(const i64 x = 0) : d((x % i64(p) + p) % p){};
    ModInt(const ModInt &) = default;

    ModInt operator+(ModInt x) const {
        if (d + x.d >= p)
            return ModInt(d + x.d - p);
        else
            return ModInt(d + x.d);
    };

    ModInt operator-(ModInt x) const {
        if (d >= x.d)
            return ModInt(d - x.d);
        else
            return ModInt(d + p - x.d);
    };

    ModInt operator*(ModInt x) const {
        return ModInt(d * x.d);
    }

    ModInt operator/(ModInt x) const {
        return ModInt(*this * x.inv());
    }

    static ModInt pow(ModInt x, uint64_t a) {
        ModInt ret = 1;
        while (a) {
            if (a & 1) ret *= x;
            x *= x;
            a >>= 1;
        }
        return ret;
    };

    ModInt inv() {
        return pow(*this, p - 2);
    };

    ModInt operator+() {
        return *this;
    };

    ModInt operator-() {
        return ModInt(-d);
    };

    ModInt &operator+=(ModInt x) {
        return *this = *this + x;
    };
    ModInt &operator-=(ModInt x) {
        return *this = *this - x;
    };
    ModInt &operator*=(ModInt x) {
        return *this = *this * x;
    };
    ModInt &operator/=(ModInt x) {
        return *this = *this / x;
    };

    ModInt operator+(const i64 x) const {
        return *this + ModInt(x);
    };
    ModInt operator-(const i64 x) const {
        return *this - ModInt(x);
    };
    ModInt operator*(const i64 x) const {
        return *this * ModInt(x);
    };
    ModInt operator/(const i64 x) const {
        return *this / ModInt(x);
    };

    ModInt operator+=(const i64 x) {
        return *this = *this + x;
    };
    ModInt operator-=(const i64 x) {
        return *this = *this - x;
    };
    ModInt operator*=(const i64 x) {
        return *this = *this * x;
    };
    ModInt operator/=(const i64 x) {
        return *this = *this / x;
    };
};

template <uint64_t p>
ModInt<p> operator+(const long long x, const ModInt<p> y) {
    return ModInt<p>(x) + y;
};

template <uint64_t p>
ModInt<p> operator-(const long long x, const ModInt<p> y) {
    return ModInt<p>(x) - y;
};

template <uint64_t p>
ModInt<p> operator*(const long long x, const ModInt<p> y) {
    return ModInt<p>(x) * y;
};

template <uint64_t p>
ModInt<p> operator/(const long long x, const ModInt<p> y) {
    return ModInt<p>(x) / y;
};

template <uint64_t p>
std::ostream &operator<<(std::ostream &stream, const ModInt<p> mi) {
    return stream << mi.d;
};

template <uint64_t p>
std::istream &operator>>(std::istream &stream, ModInt<p> &mi) {
    long long a;
    stream >> a;
    mi = ModInt<p>(a);
    return stream;
};
#endif
