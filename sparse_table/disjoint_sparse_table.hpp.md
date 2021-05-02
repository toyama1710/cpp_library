---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum.test.cpp
    title: test/yosupo/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"sparse_table/disjoint_sparse_table.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n#line 1 \"bit/msb.hpp\"\n\n\n\n#include <cstdint>\n\
    \ninline int msb32(uint32_t x) {\n        if (x == 0) return -1;\n#ifndef __has_builtin\n\
    \        int r = 0;\n        if (x >> 16) x >>= 16, r |= 16;\n        if (x >>\
    \ 8) x >>= 8, r |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n        if (x >>\
    \ 2) x >>= 2, r |= 2;\n        return r | (x >> 1);\n#else\n        return 31\
    \ - __builtin_clz(x);\n#endif\n};\n\ninline int msb64(uint64_t x) {\n    if (x\
    \ == 0) return -1;\n\n    #ifndef __has_builtin\n        int r = 0;\n        if\
    \ (x >> 32) x >>= 32, r |= 32;\n        if (x >> 16) x >>= 16, r |= 16;\n    \
    \    if (x >> 8) x >>= 8, r |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n    \
    \    if (x >> 2) x >>= 2, r |= 2;\n        return r | (x >> 1);\n#else\n    return\
    \ 63 - __builtin_clzll(x);\n#endif\n};\n\n\n#line 8 \"sparse_table/disjoint_sparse_table.hpp\"\
    \n\n//===\ntemplate <class SemiGroup>\nstruct DisjointSparseTable {\n    using\
    \ T = typename SemiGroup::value_type;\n    using G = SemiGroup;\n\n    std::vector<std::vector<T>>\
    \ table;\n\n    DisjointSparseTable() = default;\n    template<class InputItr>\n\
    \    DisjointSparseTable(InputItr first, InputItr last) {\n        build(first,\
    \ last);\n    };\n\n    template<class InputItr>\n    void build(InputItr first,\
    \ InputItr last) {\n        int n = std::distance(first, last);\n        int logn\
    \ = 1;\n        while ((1 << logn) < n) logn++;\n\n        table.reserve(logn);\n\
    \        table.emplace_back(first, last);\n\n        for (int i = 1; i < logn;\
    \ i++) {\n            table.emplace_back(first, last);\n            int w = 1\
    \ << i;\n\n            for (int k = w; k < n; k += 2 * w) {\n                for\
    \ (int j = k - 2; j >= k - w; j--) {\n                    table[i][j] = G::operation(table[i][j],\
    \ table[i][j + 1]);\n                }\n                for (int j = k + 1; j\
    \ < std::min(n, k + w); j++) {\n                    table[i][j] = G::operation(table[i][j],\
    \ table[i][j - 1]);\n                }\n            }\n        }\n    };\n\n \
    \   // [l, r)\n    T fold(int l, int r) {\n        assert(l < r);\n        assert(l\
    \ >= 0 && r <= size());\n        r--;\n        int x = l ^ r;\n\n        if (x\
    \ == 0) return table[0][l];\n        else return G::operation(table[msb32(x)][l],\
    \ table[msb32(x)][r]);\n    };\n    T fold(int l, int r, SemiGroup e) {\n    \
    \    if (l >= r) return e;\n        return fold(l, r);\n    };\n\n    int size()\
    \ {\n        return table[0].size();\n    };\n    const T operator [] (int k)\
    \ {\n        return fold(k, k + 1);\n    };\n};\n//===\n\n"
  code: "#ifndef DISJOINT_SPARSE_TABLE_HPP\n#define DISJOINT_SPARSE_TABLE_HPP\n\n\
    #include <cassert>\n#include <vector>\n#include <cassert>\n#include \"../bit/msb.hpp\"\
    \n\n//===\ntemplate <class SemiGroup>\nstruct DisjointSparseTable {\n    using\
    \ T = typename SemiGroup::value_type;\n    using G = SemiGroup;\n\n    std::vector<std::vector<T>>\
    \ table;\n\n    DisjointSparseTable() = default;\n    template<class InputItr>\n\
    \    DisjointSparseTable(InputItr first, InputItr last) {\n        build(first,\
    \ last);\n    };\n\n    template<class InputItr>\n    void build(InputItr first,\
    \ InputItr last) {\n        int n = std::distance(first, last);\n        int logn\
    \ = 1;\n        while ((1 << logn) < n) logn++;\n\n        table.reserve(logn);\n\
    \        table.emplace_back(first, last);\n\n        for (int i = 1; i < logn;\
    \ i++) {\n            table.emplace_back(first, last);\n            int w = 1\
    \ << i;\n\n            for (int k = w; k < n; k += 2 * w) {\n                for\
    \ (int j = k - 2; j >= k - w; j--) {\n                    table[i][j] = G::operation(table[i][j],\
    \ table[i][j + 1]);\n                }\n                for (int j = k + 1; j\
    \ < std::min(n, k + w); j++) {\n                    table[i][j] = G::operation(table[i][j],\
    \ table[i][j - 1]);\n                }\n            }\n        }\n    };\n\n \
    \   // [l, r)\n    T fold(int l, int r) {\n        assert(l < r);\n        assert(l\
    \ >= 0 && r <= size());\n        r--;\n        int x = l ^ r;\n\n        if (x\
    \ == 0) return table[0][l];\n        else return G::operation(table[msb32(x)][l],\
    \ table[msb32(x)][r]);\n    };\n    T fold(int l, int r, SemiGroup e) {\n    \
    \    if (l >= r) return e;\n        return fold(l, r);\n    };\n\n    int size()\
    \ {\n        return table[0].size();\n    };\n    const T operator [] (int k)\
    \ {\n        return fold(k, k + 1);\n    };\n};\n//===\n#endif"
  dependsOn:
  - bit/msb.hpp
  isVerificationFile: false
  path: sparse_table/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2020-06-06 02:26:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_sum.test.cpp
documentation_of: sparse_table/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/sparse_table/disjoint_sparse_table.hpp
- /library/sparse_table/disjoint_sparse_table.hpp.html
title: sparse_table/disjoint_sparse_table.hpp
---
