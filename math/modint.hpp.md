---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3209.test.cpp
    title: test/aoj/3209.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\n\n\n\n#include <iostream>\n\ntemplate\
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
    \ long a;\n    stream >> a;\n    mi = ModInt<p>(a);\n    return stream;\n};\n\n"
  code: "#ifndef MODINT_HPP\n#define MODINT_HPP\n\n#include <iostream>\n\ntemplate\
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
    \ long a;\n    stream >> a;\n    mi = ModInt<p>(a);\n    return stream;\n};\n\
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2021-11-23 21:40:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3209.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: math/modint.hpp
---
