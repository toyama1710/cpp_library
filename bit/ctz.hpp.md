---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: segment_tree/lazy_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: sparse_table/disjoint_sparse_table.hpp
    title: sparse_table/disjoint_sparse_table.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2F_1.test.cpp
    title: test/aoj/DSL2F_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2G.test.cpp
    title: test/aoj/DSL2G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2H.test.cpp
    title: test/aoj/DSL2H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2I.test.cpp
    title: test/aoj/DSL2I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/bits.test.cpp
    title: test/aoj/bits.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bit/ctz.hpp\"\n\n\n\n#include <cstdint>\n\ninline int ctz32_(uint32_t\
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
    \    return ctz64_(bit);\n#endif\n};\n\n\n"
  code: "#ifndef CTZ_HPP\n#define CTZ_HPP\n\n#include <cstdint>\n\ninline int ctz32_(uint32_t\
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
    \    return ctz64_(bit);\n#endif\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bit/ctz.hpp
  requiredBy:
  - sparse_table/disjoint_sparse_table.hpp
  - segment_tree/lazy_segment_tree.hpp
  timestamp: '2021-12-09 20:34:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_sum.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/aoj/bits.test.cpp
  - test/aoj/DSL2G.test.cpp
  - test/aoj/DSL2I.test.cpp
  - test/aoj/DSL2F_1.test.cpp
  - test/aoj/DSL2H.test.cpp
documentation_of: bit/ctz.hpp
layout: document
redirect_from:
- /library/bit/ctz.hpp
- /library/bit/ctz.hpp.html
title: bit/ctz.hpp
---
