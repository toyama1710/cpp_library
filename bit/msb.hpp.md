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
  bundledCode: "#line 1 \"bit/msb.hpp\"\n\n\n\n#include <cstdint>\n\ninline int msb32(uint32_t\
    \ x) {\n        if (x == 0) return -1;\n#ifndef __has_builtin\n        int r =\
    \ 0;\n        if (x >> 16) x >>= 16, r |= 16;\n        if (x >> 8) x >>= 8, r\
    \ |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n        if (x >> 2) x >>= 2, r\
    \ |= 2;\n        return r | (x >> 1);\n#else\n        return 31 - __builtin_clz(x);\n\
    #endif\n};\n\ninline int msb64(uint64_t x) {\n    if (x == 0) return -1;\n\n \
    \   #ifndef __has_builtin\n        int r = 0;\n        if (x >> 32) x >>= 32,\
    \ r |= 32;\n        if (x >> 16) x >>= 16, r |= 16;\n        if (x >> 8) x >>=\
    \ 8, r |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n        if (x >> 2) x >>=\
    \ 2, r |= 2;\n        return r | (x >> 1);\n#else\n    return 63 - __builtin_clzll(x);\n\
    #endif\n};\n\n\n"
  code: "#ifndef MSB_HPP\n#define MSB_HPP\n\n#include <cstdint>\n\ninline int msb32(uint32_t\
    \ x) {\n        if (x == 0) return -1;\n#ifndef __has_builtin\n        int r =\
    \ 0;\n        if (x >> 16) x >>= 16, r |= 16;\n        if (x >> 8) x >>= 8, r\
    \ |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n        if (x >> 2) x >>= 2, r\
    \ |= 2;\n        return r | (x >> 1);\n#else\n        return 31 - __builtin_clz(x);\n\
    #endif\n};\n\ninline int msb64(uint64_t x) {\n    if (x == 0) return -1;\n\n \
    \   #ifndef __has_builtin\n        int r = 0;\n        if (x >> 32) x >>= 32,\
    \ r |= 32;\n        if (x >> 16) x >>= 16, r |= 16;\n        if (x >> 8) x >>=\
    \ 8, r |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n        if (x >> 2) x >>=\
    \ 2, r |= 2;\n        return r | (x >> 1);\n#else\n    return 63 - __builtin_clzll(x);\n\
    #endif\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bit/msb.hpp
  requiredBy:
  - sparse_table/disjoint_sparse_table.hpp
  - segment_tree/lazy_segment_tree.hpp
  timestamp: '2020-06-05 23:20:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2H.test.cpp
  - test/aoj/DSL2G.test.cpp
  - test/aoj/DSL2F_1.test.cpp
  - test/aoj/DSL2I.test.cpp
  - test/yosupo/static_range_sum.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: bit/msb.hpp
layout: document
redirect_from:
- /library/bit/msb.hpp
- /library/bit/msb.hpp.html
title: bit/msb.hpp
---
