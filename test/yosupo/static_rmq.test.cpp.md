---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_type/min_monoid.hpp
    title: data_type/min_monoid.hpp
  - icon: ':x:'
    path: sparse_table/sparse_table.hpp
    title: sparse_table/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/static_rmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <iostream>\n#include <limits>\n\n#line 1 \"data_type/min_monoid.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"data_type/min_monoid.hpp\"\n#include <numeric>\n\
    \n//===\ntemplate <class T>\nstruct MinMonoid {\n    using value_type = T;\n \
    \   inline static T identity() {\n        return std::numeric_limits<T>::max();\n\
    \    };\n    inline static T operation(const T a, const T b) {\n        return\
    \ std::min(a, b);\n    };\n};\n//===\n\n\n#line 1 \"sparse_table/sparse_table.hpp\"\
    \n\n\n\n#include <functional>\n#include <iterator>\n#include <vector>\n\n//===\n\
    template <class SemiLattice>\nstruct SparseTable {\n    using S = SemiLattice;\n\
    \    using T = typename SemiLattice::value_type;\n\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<size_t> log2;\n\n    SparseTable() = default;\n\n  \
    \  template <class InputItr>\n    SparseTable(InputItr first, InputItr last) {\n\
    \        int n = std::distance(first, last);\n        log2.assign(n + 1, 0);\n\
    \        for (int i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;\n\n        table.reserve(log2[n]\
    \ + 1);\n        table.emplace_back(first, last);\n\n        for (int i = 1; (1\
    \ << i) <= n; i++) {\n            int w = 1 << (i - 1);\n            table.emplace_back();\n\
    \            table.back().reserve(n - (1 << i) + 1);\n            for (int j =\
    \ 0; j + (1 << i) <= n; j++) {\n                table[i].emplace_back(\n     \
    \               S::operation(table[i - 1][j], table[i - 1][j + w]));\n       \
    \     }\n        }\n    };\n\n    //[l, r)\n    T fold(int l, int r) {\n     \
    \   int k = log2[r - l];\n        return S::operation(table[k][l], table[k][r\
    \ - (1 << k)]);\n    };\n\n    int size() {\n        return table[0].size();\n\
    \    };\n\n    T operator[](const int k) {\n        return table[0][k];\n    };\n\
    };\n//===\n\n\n#line 8 \"test/yosupo/static_rmq.test.cpp\"\nusing namespace std;\n\
    using llong = long long;\n\nllong n, q;\nvector<llong> a;\n\nint main() {\n  \
    \  cin >> n >> q;\n    a.resize(n);\n    for (auto &v : a) cin >> v;\n\n    SparseTable<MinMonoid<llong>>\
    \ rmq(a.begin(), a.end());\n\n    while (q--) {\n        llong l, r;\n       \
    \ cin >> l >> r;\n        cout << rmq.fold(l, r) << '\\n';\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <iostream>\n#include <limits>\n\n#include \"../../data_type/min_monoid.hpp\"\
    \n#include \"../../sparse_table/sparse_table.hpp\"\nusing namespace std;\nusing\
    \ llong = long long;\n\nllong n, q;\nvector<llong> a;\n\nint main() {\n    cin\
    \ >> n >> q;\n    a.resize(n);\n    for (auto &v : a) cin >> v;\n\n    SparseTable<MinMonoid<llong>>\
    \ rmq(a.begin(), a.end());\n\n    while (q--) {\n        llong l, r;\n       \
    \ cin >> l >> r;\n        cout << rmq.fold(l, r) << '\\n';\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - data_type/min_monoid.hpp
  - sparse_table/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_rmq.test.cpp
- /verify/test/yosupo/static_rmq.test.cpp.html
title: test/yosupo/static_rmq.test.cpp
---
