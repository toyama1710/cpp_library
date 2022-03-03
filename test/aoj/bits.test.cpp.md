---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/clz.hpp
    title: bit/clz.hpp
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
    \n\n#include <bits/stdc++.h>\n\n#line 1 \"bit/clz.hpp\"\n\n\n\n#line 5 \"bit/clz.hpp\"\
    \n\ninline int clz32_(uint32_t bit) {\n    static const int table[] = {\n    \
    \    31, 30, 29, 25, 28, 20, 24, 15, 27, 17, 19, 10, 23, 8,  14, 5,\n        0,\
    \  26, 21, 16, 18, 11, 9,  6,  1,  22, 12, 7,  2,  13, 3,  4,\n    };\n    static\
    \ const uint32_t de_bruijn = 0x04653adf;\n\n    bit |= bit >> 1;\n    bit |= bit\
    \ >> 2;\n    bit |= bit >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n \
    \   bit ^= bit >> 1;\n    return table[(bit * de_bruijn) >> 27];\n};\ninline int\
    \ clz32(uint32_t bit) {\n    if (bit == 0) return 32;\n#ifdef __has_builtin\n\
    \    return __builtin_clz(bit);\n#else\n    return clz32_(bit);\n#endif\n};\n\n\
    inline int clz64_(uint64_t bit) {\n    static const int table[] = {\n        63,\
    \ 62, 61, 56, 60, 50, 55, 44, 59, 38, 49, 35, 54, 29, 43, 23,\n        58, 46,\
    \ 37, 25, 48, 17, 34, 15, 53, 32, 28, 9,  42, 13, 22, 6,\n        0,  57, 51,\
    \ 45, 39, 36, 30, 24, 47, 26, 18, 16, 33, 10, 14, 7,\n        1,  52, 40, 31,\
    \ 27, 19, 11, 8,  2,  41, 20, 12, 3,  21, 4,  5,\n    };\n    static const uint64_t\
    \ de_bruijn = 0x0218a392cd3d5dbfull;\n    bit |= bit >> 1;\n    bit |= bit >>\
    \ 2;\n    bit |= bit >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n    bit\
    \ |= bit >> 32;\n    bit ^= bit >> 1;\n    return table[(bit * de_bruijn) >> 58];\n\
    };\ninline int clz64(uint64_t bit) {\n    if (bit == 0) return 64;\n#ifdef __has_builtin\n\
    \    return __builtin_clzll(bit);\n#else\n    return clz64_(bit);\n#endif\n};\n\
    \n\n#line 1 \"bit/ctz.hpp\"\n\n\n\n#line 5 \"bit/ctz.hpp\"\n\ninline int ctz32_(uint32_t\
    \ bit) {\n    static const int table[] = {\n        0,  1, 2,  6,  3,  11, 7,\
    \  16, 4,  14, 12, 21, 8,  23, 17, 26,\n        31, 5, 10, 15, 13, 20, 22, 25,\
    \ 30, 9,  19, 24, 29, 18, 28, 27,\n    };\n    static const uint32_t de_bruijn\
    \ = 0x04653adf;\n    bit &= ~bit + 1;\n    return table[(bit * de_bruijn) >> 27];\n\
    };\ninline int ctz32(uint32_t bit) {\n    if (bit == 0) return 32;\n#ifdef __has_builtin\n\
    \    return __builtin_ctz(bit);\n#else\n    return ctz32_(bit);\n#endif\n};\n\n\
    inline int ctz64_(uint64_t bit) {\n    static const int table[] = {\n        0,\
    \  1,  2,  7,  3,  13, 8,  19, 4,  25, 14, 28, 9,  34, 20, 40,\n        5,  17,\
    \ 26, 38, 15, 46, 29, 48, 10, 31, 35, 54, 21, 50, 41, 57,\n        63, 6,  12,\
    \ 18, 24, 27, 33, 39, 16, 37, 45, 47, 30, 53, 49, 56,\n        62, 11, 23, 32,\
    \ 36, 44, 52, 55, 61, 22, 43, 51, 60, 42, 59, 58,\n    };\n    static const uint64_t\
    \ de_bruijn = 0x0218a392cd3d5dbfull;\n    bit &= ~bit + 1;\n    return table[(bit\
    \ * de_bruijn) >> 58];\n};\ninline int ctz64(uint64_t bit) {\n    if (bit == 0)\
    \ return 64;\n#ifdef __has_builtin\n    return __builtin_ctzll(bit);\n#else\n\
    \    return ctz64_(bit);\n#endif\n};\n\n\n#line 1 \"bit/lsb.hpp\"\n\n\n\n#line\
    \ 5 \"bit/lsb.hpp\"\n\ninline uint64_t lsb32(uint32_t bits) { return bits & (~bits\
    \ + 1); };\ninline uint64_t lsb64(uint64_t bits) { return bits & (~bits + 1);\
    \ };\n\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\ninline uint32_t\
    \ msb32_(uint32_t bit) {\n    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit\
    \ |= bit >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n    return bit ^\
    \ (bit >> 1);\n};\ninline uint32_t msb32(uint32_t x) {\n    if (x == 0) return\
    \ 0;\n#ifdef __has_builtin\n    return 1u << (31 - __builtin_clz(x));\n#else\n\
    \    return msb32_(x);\n#endif\n};\n\ninline uint64_t msb64_(uint64_t bit) {\n\
    \    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit >> 4;\n    bit |=\
    \ bit >> 8;\n    bit |= bit >> 16;\n    bit |= bit >> 32;\n    return bit ^ (bit\
    \ >> 1);\n};\ninline uint64_t msb64(uint64_t x) {\n    if (x == 0) return 0;\n\
    #ifdef __has_builtin\n    return 1ull << (63 - __builtin_clzll(x));\n#else\n \
    \   return msb64_(x);\n#endif\n};\n\n\n#line 1 \"bit/pop_count.hpp\"\n\n\n\n#line\
    \ 5 \"bit/pop_count.hpp\"\n\ninline int popcnt64_(uint64_t bits) {\n    bits =\
    \ (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);\n    bits =\
    \ (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);\n    bits =\
    \ (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);\n    bits =\
    \ (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);\n    bits =\
    \ (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);\n    bits =\
    \ (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);\n    return\
    \ bits;\n};\ninline int popcnt64(uint64_t bits) {\n#ifdef __has_builtin\n    return\
    \ __builtin_popcountll(bits);\n#else\n    return popcnt64_(bits);\n#endif\n};\n\
    \ninline int popcnt32_(uint32_t bits) {\n    bits = (bits & 0x55555555) + (bits\
    \ >> 1 & 0x55555555);\n    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);\n\
    \    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);\n    bits = (bits\
    \ & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);\n    bits = (bits & 0x0000ffff) +\
    \ (bits >> 16 & 0x0000ffff);\n    return bits;\n};\ninline int popcnt32(uint32_t\
    \ bits) {\n#ifdef __has_builtin\n    return __builtin_popcount(bits);\n#else\n\
    \    return popcnt32_(bits);\n#endif\n};\n\n\n#line 1 \"util/xorshift.hpp\"\n\n\
    \n\n#line 5 \"util/xorshift.hpp\"\n\nstruct xorshift32 {\n    uint32_t seed;\n\
    \    xorshift32(uint32_t seed = 1710) : seed(seed){};\n    void set_seed(uint32_t\
    \ s) { seed = s; };\n    uint32_t gen() {\n        seed = seed ^ (seed << 13);\n\
    \        seed = seed ^ (seed >> 17);\n        seed = seed ^ (seed << 5);\n   \
    \     return seed;\n    };\n    uint32_t operator()() { return gen(); };\n};\n\
    \nstruct xorshift64 {\n    uint64_t seed;\n    xorshift64(uint64_t seed = 1710)\
    \ : seed(seed){};\n    void set_seed(uint64_t s) { seed = s; };\n    uint64_t\
    \ gen() {\n        seed = seed ^ (seed << 13);\n        seed = seed ^ (seed >>\
    \ 7);\n        seed = seed ^ (seed << 17);\n        return seed;\n    };\n   \
    \ uint64_t operator()() { return gen(); };\n};\n\n\n#line 12 \"test/aoj/bits.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = int64_t;\n\
    using u64 = uint64_t;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    xorshift64 rnd64(1);\n    xorshift32 rnd32(1);\n\n    rep(i, 1 << 25) {\n\
    \        u64 bit64 = rnd64();\n        unsigned bit32 = rnd32();\n\n        assert(ctz32_(bit32)\
    \ == __builtin_ctz(bit32));\n        assert(ctz64(bit64) == __builtin_ctzll(bit64));\n\
    \n        assert(clz32_(bit32) == __builtin_clz(bit32));\n        assert(clz64(bit64)\
    \ == __builtin_clzll(bit64));\n\n        assert(popcnt32_(bit32) == __builtin_popcount(bit32));\n\
    \        assert(popcnt64_(bit64) == __builtin_popcountll(bit64));\n\n        assert(msb32_(bit32)\
    \ == 1u << (31 - __builtin_clz(bit32)));\n        assert(msb64_(bit64) == 1ull\
    \ << (63 - __builtin_clzll(bit64)));\n    }\n\n    rep(i, 32) {\n        assert(msb32_(rnd32()\
    \ | (1u << i)) >= 1u << i);\n        assert(msb64_(rnd64() | (1ull << i)) >= 1ull\
    \ << i);\n\n        assert(ctz32_(1u << i) == i);\n        assert(ctz32_(3u <<\
    \ i) == i);\n\n        assert(ctz32_(21u << i) == i);\n        assert(clz32_(1u\
    \ << i) == 31 - i);\n    }\n    rep(i, 64) {\n        assert(msb64_(rnd32() |\
    \ (1ull << i)) >= 1ull << i);\n        assert(msb64_(rnd64() | (1ull << i)) >=\
    \ 1ull << i);\n\n        assert(ctz64_(1ull << i) == i);\n        assert(ctz64_(3ull\
    \ << i) == i);\n\n        assert(ctz64_(21ull << i) == i);\n        assert(clz64_(1ull\
    \ << i) == 63 - i);\n    }\n\n    cout << \"Hello World\" << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../bit/clz.hpp\"\n#include \"../../bit/ctz.hpp\"\
    \n#include \"../../bit/lsb.hpp\"\n#include \"../../bit/msb.hpp\"\n#include \"\
    ../../bit/pop_count.hpp\"\n#include \"../../util/xorshift.hpp\"\n\n#define _overload(_1,\
    \ _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define\
    \ _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64\
    \ Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__, _rep3,\
    \ _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n#define\
    \ ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = int64_t;\nusing\
    \ u64 = uint64_t;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    xorshift64 rnd64(1);\n    xorshift32 rnd32(1);\n\n    rep(i, 1 << 25) {\n\
    \        u64 bit64 = rnd64();\n        unsigned bit32 = rnd32();\n\n        assert(ctz32_(bit32)\
    \ == __builtin_ctz(bit32));\n        assert(ctz64(bit64) == __builtin_ctzll(bit64));\n\
    \n        assert(clz32_(bit32) == __builtin_clz(bit32));\n        assert(clz64(bit64)\
    \ == __builtin_clzll(bit64));\n\n        assert(popcnt32_(bit32) == __builtin_popcount(bit32));\n\
    \        assert(popcnt64_(bit64) == __builtin_popcountll(bit64));\n\n        assert(msb32_(bit32)\
    \ == 1u << (31 - __builtin_clz(bit32)));\n        assert(msb64_(bit64) == 1ull\
    \ << (63 - __builtin_clzll(bit64)));\n    }\n\n    rep(i, 32) {\n        assert(msb32_(rnd32()\
    \ | (1u << i)) >= 1u << i);\n        assert(msb64_(rnd64() | (1ull << i)) >= 1ull\
    \ << i);\n\n        assert(ctz32_(1u << i) == i);\n        assert(ctz32_(3u <<\
    \ i) == i);\n\n        assert(ctz32_(21u << i) == i);\n        assert(clz32_(1u\
    \ << i) == 31 - i);\n    }\n    rep(i, 64) {\n        assert(msb64_(rnd32() |\
    \ (1ull << i)) >= 1ull << i);\n        assert(msb64_(rnd64() | (1ull << i)) >=\
    \ 1ull << i);\n\n        assert(ctz64_(1ull << i) == i);\n        assert(ctz64_(3ull\
    \ << i) == i);\n\n        assert(ctz64_(21ull << i) == i);\n        assert(clz64_(1ull\
    \ << i) == 63 - i);\n    }\n\n    cout << \"Hello World\" << endl;\n    return\
    \ 0;\n}"
  dependsOn:
  - bit/clz.hpp
  - bit/ctz.hpp
  - bit/lsb.hpp
  - bit/msb.hpp
  - bit/pop_count.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: test/aoj/bits.test.cpp
  requiredBy: []
  timestamp: '2022-03-04 02:20:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/bits.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/bits.test.cpp
- /verify/test/aoj/bits.test.cpp.html
title: test/aoj/bits.test.cpp
---
