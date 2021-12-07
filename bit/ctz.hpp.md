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
  bundledCode: "#line 1 \"bit/ctz.hpp\"\n\n\n\n#include <cstdint>\n\ninline int ctz32_(uint64_t\
    \ x) {\n    int r = 0;\n    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if\
    \ (!(x & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n  \
    \  if (!(x & 0x3)) x >>= 2, r |= 2;\n    return r | ((x & 1) ^ 1);\n};\ninline\
    \ int ctz32(uint32_t x) {\n    if (x == 0) return 32;\n#ifdef __has_builtin\n\
    \    return __builtin_ctz(x);\n#else\n    return ctz32_(x);\n#endif\n};\n\ninline\
    \ int ctz64_(uint64_t x) {\n    int r = 0;\n    if (!(x & 0x00000000ffffffff))\
    \ x >>= 32, r |= 32;\n    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x\
    \ & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x\
    \ & 0x3)) x >>= 2, r |= 2;\n    return r | ((x & 1) ^ 1);\n};\ninline int ctz64(uint64_t\
    \ x) {\n    if (x == 0) return 64;\n#ifdef __has_builtin\n    return __builtin_ctzll(x);\n\
    #else\n    return ctz64_(x);\n#endif\n};\n\n\n"
  code: "#ifndef CTZ_HPP\n#define CTZ_HPP\n\n#include <cstdint>\n\ninline int ctz32_(uint64_t\
    \ x) {\n    int r = 0;\n    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if\
    \ (!(x & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n  \
    \  if (!(x & 0x3)) x >>= 2, r |= 2;\n    return r | ((x & 1) ^ 1);\n};\ninline\
    \ int ctz32(uint32_t x) {\n    if (x == 0) return 32;\n#ifdef __has_builtin\n\
    \    return __builtin_ctz(x);\n#else\n    return ctz32_(x);\n#endif\n};\n\ninline\
    \ int ctz64_(uint64_t x) {\n    int r = 0;\n    if (!(x & 0x00000000ffffffff))\
    \ x >>= 32, r |= 32;\n    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x\
    \ & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x\
    \ & 0x3)) x >>= 2, r |= 2;\n    return r | ((x & 1) ^ 1);\n};\ninline int ctz64(uint64_t\
    \ x) {\n    if (x == 0) return 64;\n#ifdef __has_builtin\n    return __builtin_ctzll(x);\n\
    #else\n    return ctz64_(x);\n#endif\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bit/ctz.hpp
  requiredBy:
  - segment_tree/lazy_segment_tree.hpp
  - sparse_table/disjoint_sparse_table.hpp
  timestamp: '2021-12-07 23:48:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/static_range_sum.test.cpp
  - test/aoj/DSL2G.test.cpp
  - test/aoj/DSL2F_1.test.cpp
  - test/aoj/bits.test.cpp
  - test/aoj/DSL2H.test.cpp
  - test/aoj/DSL2I.test.cpp
documentation_of: bit/ctz.hpp
layout: document
redirect_from:
- /library/bit/ctz.hpp
- /library/bit/ctz.hpp.html
title: bit/ctz.hpp
---
