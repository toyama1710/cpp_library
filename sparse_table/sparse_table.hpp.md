---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/static_rmq.test.cpp
    title: test/yosupo/static_rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"sparse_table/sparse_table.hpp\"\n\n\n\n#include <functional>\n\
    #include <iterator>\n#include <vector>\n\n//===\ntemplate <class SemiLattice>\n\
    struct SparseTable {\n    using S = SemiLattice;\n    using T = typename SemiLattice::value_type;\n\
    \n    std::vector<std::vector<T>> table;\n    std::vector<size_t> log2;\n\n  \
    \  SparseTable() = default;\n\n    template <class InputItr>\n    SparseTable(InputItr\
    \ first, InputItr last) {\n        int n = std::distance(first, last);\n     \
    \   log2.assign(n + 1, 0);\n        for (int i = 2; i <= n; i++) log2[i] = log2[i\
    \ / 2] + 1;\n\n        table.reserve(log2[n] + 1);\n        table.emplace_back(first,\
    \ last);\n\n        for (int i = 1; (1 << i) <= n; i++) {\n            int w =\
    \ 1 << (i - 1);\n            table.emplace_back();\n            table.back().reserve(n\
    \ - (1 << i) + 1);\n            for (int j = 0; j + (1 << i) <= n; j++) {\n  \
    \              table[i].emplace_back(\n                    S::operation(table[i\
    \ - 1][j], table[i - 1][j + w]));\n            }\n        }\n    };\n\n    //[l,\
    \ r)\n    T fold(int l, int r) {\n        int k = log2[r - l];\n        return\
    \ S::operation(table[k][l], table[k][r - (1 << k)]);\n    };\n\n    int size()\
    \ {\n        return table[0].size();\n    };\n\n    T operator[](const int k)\
    \ {\n        return table[0][k];\n    };\n};\n//===\n\n\n"
  code: "#ifndef SPARSE_TABLE_HPP\n#define SPARSE_TABLE_HPP\n\n#include <functional>\n\
    #include <iterator>\n#include <vector>\n\n//===\ntemplate <class SemiLattice>\n\
    struct SparseTable {\n    using S = SemiLattice;\n    using T = typename SemiLattice::value_type;\n\
    \n    std::vector<std::vector<T>> table;\n    std::vector<size_t> log2;\n\n  \
    \  SparseTable() = default;\n\n    template <class InputItr>\n    SparseTable(InputItr\
    \ first, InputItr last) {\n        int n = std::distance(first, last);\n     \
    \   log2.assign(n + 1, 0);\n        for (int i = 2; i <= n; i++) log2[i] = log2[i\
    \ / 2] + 1;\n\n        table.reserve(log2[n] + 1);\n        table.emplace_back(first,\
    \ last);\n\n        for (int i = 1; (1 << i) <= n; i++) {\n            int w =\
    \ 1 << (i - 1);\n            table.emplace_back();\n            table.back().reserve(n\
    \ - (1 << i) + 1);\n            for (int j = 0; j + (1 << i) <= n; j++) {\n  \
    \              table[i].emplace_back(\n                    S::operation(table[i\
    \ - 1][j], table[i - 1][j + w]));\n            }\n        }\n    };\n\n    //[l,\
    \ r)\n    T fold(int l, int r) {\n        int k = log2[r - l];\n        return\
    \ S::operation(table[k][l], table[k][r - (1 << k)]);\n    };\n\n    int size()\
    \ {\n        return table[0].size();\n    };\n\n    T operator[](const int k)\
    \ {\n        return table[0][k];\n    };\n};\n//===\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: sparse_table/sparse_table.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static_rmq.test.cpp
documentation_of: sparse_table/sparse_table.hpp
layout: document
redirect_from:
- /library/sparse_table/sparse_table.hpp
- /library/sparse_table/sparse_table.hpp.html
title: sparse_table/sparse_table.hpp
---
