---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: math/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1501.test.cpp
    title: test/aoj/1501.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/mod_binomial.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cstdint>\n\n#line 1 \"math/modint.hpp\"\n\n\n\n#include <iostream>\n\ntemplate\
    \ <uint64_t p>\nstruct ModInt {\n    using u64 = unsigned long long;\n    using\
    \ i64 = long long;\n    u64 d;\n\n    ModInt(const i64 x = 0) : d((x % p + p)\
    \ % p){};\n    ModInt(const ModInt &) = default;\n\n    ModInt operator+(ModInt\
    \ x) const {\n        if (d + x.d >= p)\n            return ModInt(d + x.d - p);\n\
    \        else\n            return ModInt(d + x.d);\n    };\n    ModInt operator-(ModInt\
    \ x) const {\n        if (d - x.d < 0)\n            return ModInt(d - x.d + p);\n\
    \        else\n            return ModInt(d - x.d);\n    };\n    ModInt operator*(ModInt\
    \ x) const { return ModInt(d * x.d); }\n    ModInt operator/(ModInt x) const {\
    \ return ModInt(*this * x.inv()); }\n\n    static ModInt pow(ModInt x, uint64_t\
    \ a) {\n        ModInt ret = 1;\n        while (a) {\n            if (a & 1) ret\
    \ *= x;\n            x *= x;\n            a >>= 1;\n        }\n        return\
    \ ret;\n    };\n    ModInt inv() { return pow(*this, p - 2); };\n\n    ModInt\
    \ operator+() { return *this; };\n    ModInt operator-() { return ModInt(-d);\
    \ };\n\n    ModInt &operator+=(ModInt x) { return *this = *this + x; };\n    ModInt\
    \ &operator-=(ModInt x) { return *this = *this - x; };\n    ModInt &operator*=(ModInt\
    \ x) { return *this = *this * x; };\n    ModInt &operator/=(ModInt x) { return\
    \ *this = *this / x; };\n\n    ModInt operator+(const i64 x) const { return *this\
    \ + ModInt(x); };\n    ModInt operator-(const i64 x) const { return *this - ModInt(x);\
    \ };\n    ModInt operator*(const i64 x) const { return *this * ModInt(x); };\n\
    \    ModInt operator/(const i64 x) const { return *this / ModInt(x); };\n\n  \
    \  ModInt operator+=(const i64 x) { return *this = *this + x; };\n    ModInt operator-=(const\
    \ i64 x) { return *this = *this - x; };\n    ModInt operator*=(const i64 x) {\
    \ return *this = *this * x; };\n    ModInt operator/=(const i64 x) { return *this\
    \ = *this / x; };\n};\n\ntemplate <uint64_t p>\nModInt<p> operator+(const long\
    \ long x, const ModInt<p> y) {\n    return ModInt<p>(x) + y;\n};\ntemplate <uint64_t\
    \ p>\nModInt<p> operator-(const long long x, const ModInt<p> y) {\n    return\
    \ ModInt<p>(x) - y;\n};\ntemplate <uint64_t p>\nModInt<p> operator*(const long\
    \ long x, const ModInt<p> y) {\n    return ModInt<p>(x) * y;\n};\ntemplate <uint64_t\
    \ p>\nModInt<p> operator/(const long long x, const ModInt<p> y) {\n    return\
    \ ModInt<p>(x) / y;\n};\n\ntemplate <uint64_t p>\nstd::ostream &operator<<(std::ostream\
    \ &stream, const ModInt<p> mi) {\n    return stream << mi.d;\n};\ntemplate <uint64_t\
    \ p>\nstd::istream &operator>>(std::istream &stream, ModInt<p> &mi) {\n    long\
    \ long a;\n    stream >> a;\n    mi = ModInt<p>(a);\n    return stream;\n};\n\n\
    #line 8 \"math/mod_binomial.hpp\"\n\n// nCr mod p\n// p is prime\ntemplate <uint64_t\
    \ p>\nModInt<p> binomial(uint64_t n, uint64_t r) {\n    assert(r <= n);\n    static\
    \ std::vector<ModInt<p>> fact;\n    auto f = [&](auto &&f, uint64_t n) -> ModInt<p>\
    \ {\n        if (fact.size() > n) return fact[n];\n\n        if (n == 0)\n   \
    \         fact.push_back(1);\n        else\n            fact.push_back(f(f, n\
    \ - 1) * n);\n\n        return fact[n];\n    };\n\n    return f(f, n) / f(f, r)\
    \ / f(f, n - r);\n};\n\n\n"
  code: "#ifndef MOD_BINOMIAL_HPP\n#define MOD_BINOMIAL_HPP\n\n#include <cassert>\n\
    #include <cstdint>\n\n#include \"modint.hpp\"\n\n// nCr mod p\n// p is prime\n\
    template <uint64_t p>\nModInt<p> binomial(uint64_t n, uint64_t r) {\n    assert(r\
    \ <= n);\n    static std::vector<ModInt<p>> fact;\n    auto f = [&](auto &&f,\
    \ uint64_t n) -> ModInt<p> {\n        if (fact.size() > n) return fact[n];\n\n\
    \        if (n == 0)\n            fact.push_back(1);\n        else\n         \
    \   fact.push_back(f(f, n - 1) * n);\n\n        return fact[n];\n    };\n\n  \
    \  return f(f, n) / f(f, r) / f(f, n - r);\n};\n\n#endif"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/mod_binomial.hpp
  requiredBy: []
  timestamp: '2021-11-23 23:13:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1501.test.cpp
documentation_of: math/mod_binomial.hpp
layout: document
redirect_from:
- /library/math/mod_binomial.hpp
- /library/math/mod_binomial.hpp.html
title: math/mod_binomial.hpp
---