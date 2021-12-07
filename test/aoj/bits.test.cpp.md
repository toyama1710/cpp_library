---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ctz.hpp
    title: bit/ctz.hpp
  - icon: ':heavy_check_mark:'
    path: bit/lsb.hpp
    title: bit/lsb.hpp
  - icon: ':heavy_check_mark:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  - icon: ':heavy_check_mark:'
    path: bit/pop_count.hpp
    title: bit/pop_count.hpp
  - icon: ':heavy_check_mark:'
    path: util/xorshift.hpp
    title: util/xorshift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/aoj/bits.test.cpp\"\n#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#line 1 \"bit/ctz.hpp\"\n\n\n\n#line 5 \"bit/ctz.hpp\"\
    \n\ninline int ctz32_(uint64_t x) {\n    int r = 0;\n    if (!(x & 0x0000ffff))\
    \ x >>= 16, r |= 16;\n    if (!(x & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f))\
    \ x >>= 4, r |= 4;\n    if (!(x & 0x3)) x >>= 2, r |= 2;\n    return r | ((x &\
    \ 1) ^ 1);\n};\ninline int ctz32(uint32_t x) {\n    if (x == 0) return 32;\n#ifdef\
    \ __has_builtin\n    return __builtin_ctz(x);\n#else\n    return ctz32_(x);\n\
    #endif\n};\n\ninline int ctz64_(uint64_t x) {\n    int r = 0;\n    if (!(x & 0x00000000ffffffff))\
    \ x >>= 32, r |= 32;\n    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x\
    \ & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x\
    \ & 0x3)) x >>= 2, r |= 2;\n    return r | ((x & 1) ^ 1);\n};\ninline int ctz64(uint64_t\
    \ x) {\n    if (x == 0) return 64;\n#ifdef __has_builtin\n    return __builtin_ctzll(x);\n\
    #else\n    return ctz64_(x);\n#endif\n};\n\n\n#line 1 \"bit/lsb.hpp\"\n\n\n\n\
    #line 5 \"bit/lsb.hpp\"\n\ninline uint64_t lsb32(uint32_t bits) { return bits\
    \ & (~bits + 1); };\ninline uint64_t lsb64(uint64_t bits) { return bits & (~bits\
    \ + 1); };\n\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\ninline\
    \ uint64_t msb32_(uint64_t x) {\n    int r = 0;\n    if (x >> 16) x >>= 16, r\
    \ |= 16;\n    if (x >> 8) x >>= 8, r |= 8;\n    if (x >> 4) x >>= 4, r |= 4;\n\
    \    if (x >> 2) x >>= 2, r |= 2;\n    return 1u << (r | (x >> 1));\n};\ninline\
    \ uint32_t msb32(uint32_t x) {\n    if (x == 0) return 0;\n#ifdef __has_builtin\n\
    \    return 1u << (31 - __builtin_clz(x));\n#else\n    return msb32_(x);\n#endif\n\
    };\n\ninline uint64_t msb64_(uint64_t x) {\n    int r = 0;\n    if (x >> 32) x\
    \ >>= 32, r |= 32;\n    if (x >> 16) x >>= 16, r |= 16;\n    if (x >> 8) x >>=\
    \ 8, r |= 8;\n    if (x >> 4) x >>= 4, r |= 4;\n    if (x >> 2) x >>= 2, r |=\
    \ 2;\n    return 1ull << (r | (x >> 1));\n};\ninline uint64_t msb64(uint64_t x)\
    \ {\n    if (x == 0) return 0;\n#ifdef __has_builtin\n    return 1ull << (63 -\
    \ __builtin_clzll(x));\n#else\n    return msb64_(x);\n#endif\n};\n\n\n#line 1\
    \ \"bit/pop_count.hpp\"\n\n\n\n#line 5 \"bit/pop_count.hpp\"\n\ninline int popcnt64_(uint64_t\
    \ bits) {\n    bits = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);\n\
    \    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);\n\
    \    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);\n\
    \    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);\n\
    \    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);\n\
    \    bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);\n\
    \    return bits;\n};\ninline int popcnt64(uint64_t bits) {\n#ifdef __has_builtin\n\
    \    return __builtin_popcountll(bits);\n#else\n    return popcnt64_(bits);\n\
    #endif\n};\n\ninline int popcnt32_(uint32_t bits) {\n    bits = (bits & 0x55555555)\
    \ + (bits >> 1 & 0x55555555);\n    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);\n\
    \    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);\n    bits = (bits\
    \ & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);\n    bits = (bits & 0x0000ffff) +\
    \ (bits >> 16 & 0x0000ffff);\n    return bits;\n};\ninline int popcnt32(uint32_t\
    \ bits) {\n#ifdef __has_builtin\n    return __builtin_popcount(bits);\n#else\n\
    \    return popcnt32_(bits);\n#endif\n};\n\n\n#line 1 \"util/xorshift.hpp\"\n\n\
    \n\n#line 5 \"util/xorshift.hpp\"\n\nstruct xorshift32 {\n    uint32_t seed =\
    \ 1710;\n    xorshift32(uint32_t seed) : seed(seed){};\n    void set_seed(uint32_t\
    \ s) { seed = s; };\n    uint32_t gen() {\n        seed = seed ^ (seed << 13);\n\
    \        seed = seed ^ (seed >> 17);\n        seed = seed ^ (seed << 5);\n   \
    \     return seed;\n    };\n    uint32_t operator()() { return gen(); };\n};\n\
    \nstruct xorshift64 {\n    uint64_t seed = 1710;\n    xorshift64(uint64_t seed)\
    \ : seed(seed){};\n    void set_seed(uint64_t s) { seed = s; };\n    uint64_t\
    \ gen() {\n        seed = seed ^ (seed << 13);\n        seed = seed ^ (seed >>\
    \ 7);\n        seed = seed ^ (seed << 17);\n        return seed;\n    };\n   \
    \ uint64_t operator()() { return gen(); };\n};\n\n\n#line 11 \"test/aoj/bits.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    xorshift64 rnd64(1);\n    xorshift32 rnd32(1);\n\n    rep(i, 1 << 25) {\n\
    \        u64 bit64 = rnd64();\n        unsigned bit32 = rnd32();\n        assert(ctz32_(bit32)\
    \ == __builtin_ctz(bit32));\n        assert(ctz64(bit64) == __builtin_ctzll(bit64));\n\
    \        assert(popcnt32_(bit32) == __builtin_popcount(bit32));\n        assert(popcnt64_(bit64)\
    \ == __builtin_popcountll(bit64));\n        assert(msb32_(bit32) == 1u << (31\
    \ - __builtin_clz(bit32)));\n        assert(msb64_(bit64) == 1ull << (63 - __builtin_clzll(bit64)));\n\
    \    }\n\n    rep(i, 32) {\n        assert(msb32_(rnd32() | (1u << i)) >= 1u <<\
    \ i);\n        assert(msb64_(rnd64() | (1ull << i)) >= 1ull << i);\n        assert(ctz32_(1u\
    \ << i) == i);\n    }\n    rep(i, 64) {\n        assert(msb64_(rnd32() | (1ull\
    \ << i)) >= 1ull << i);\n        assert(msb64_(rnd64() | (1ull << i)) >= 1ull\
    \ << i);\n        assert(ctz64_(1ull << i) == i);\n    }\n\n    cout << \"Hello\
    \ World\" << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../bit/ctz.hpp\"\n#include \"../../bit/lsb.hpp\"\
    \n#include \"../../bit/msb.hpp\"\n#include \"../../bit/pop_count.hpp\"\n#include\
    \ \"../../util/xorshift.hpp\"\n\n#define _overload(_1, _2, _3, _4, name, ...)\
    \ name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr,\
    \ a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)\n\
    #define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define rep(...) repeat(__VA_ARGS__)\n\n#define ALL(X) begin(X), end(X)\n\nusing\
    \ namespace std;\nusing i64 = int64_t;\nusing u64 = uint64_t;\n\nint main() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    xorshift64 rnd64(1);\n\
    \    xorshift32 rnd32(1);\n\n    rep(i, 1 << 25) {\n        u64 bit64 = rnd64();\n\
    \        unsigned bit32 = rnd32();\n        assert(ctz32_(bit32) == __builtin_ctz(bit32));\n\
    \        assert(ctz64(bit64) == __builtin_ctzll(bit64));\n        assert(popcnt32_(bit32)\
    \ == __builtin_popcount(bit32));\n        assert(popcnt64_(bit64) == __builtin_popcountll(bit64));\n\
    \        assert(msb32_(bit32) == 1u << (31 - __builtin_clz(bit32)));\n       \
    \ assert(msb64_(bit64) == 1ull << (63 - __builtin_clzll(bit64)));\n    }\n\n \
    \   rep(i, 32) {\n        assert(msb32_(rnd32() | (1u << i)) >= 1u << i);\n  \
    \      assert(msb64_(rnd64() | (1ull << i)) >= 1ull << i);\n        assert(ctz32_(1u\
    \ << i) == i);\n    }\n    rep(i, 64) {\n        assert(msb64_(rnd32() | (1ull\
    \ << i)) >= 1ull << i);\n        assert(msb64_(rnd64() | (1ull << i)) >= 1ull\
    \ << i);\n        assert(ctz64_(1ull << i) == i);\n    }\n\n    cout << \"Hello\
    \ World\" << endl;\n    return 0;\n}"
  dependsOn:
  - bit/ctz.hpp
  - bit/lsb.hpp
  - bit/msb.hpp
  - bit/pop_count.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: test/aoj/bits.test.cpp
  requiredBy: []
  timestamp: '2021-12-07 23:48:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/bits.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/bits.test.cpp
- /verify/test/aoj/bits.test.cpp.html
title: test/aoj/bits.test.cpp
---
