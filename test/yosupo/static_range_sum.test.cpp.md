---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ctz.hpp
    title: bit/ctz.hpp
  - icon: ':heavy_check_mark:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  - icon: ':heavy_check_mark:'
    path: sparse_table/disjoint_sparse_table.hpp
    title: sparse_table/disjoint_sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include <iostream>\n\
    #line 1 \"sparse_table/disjoint_sparse_table.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\n#line 1 \"bit/ctz.hpp\"\n\n\n\n#include <cstdint>\n\ninline\
    \ int ctz32(uint32_t x) {\n#ifdef __has_builtin\n    if (x == 0)\n        return\
    \ 32;\n    else\n        return __builtin_ctz(x);\n#else\n    int r = 0;\n   \
    \ if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x & 0x00ff)) x >>= 8, r\
    \ |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x & 0x3)) x >>= 2, r\
    \ |= 2;\n    if (!(x & 1)) x >>= 1, r |= 1;\n    return r + ((x & 1) ^ 1);\n#endif\n\
    };\ninline int ctz64(uint64_t x) {\n#ifdef __has_builtin\n    if (x == 0)\n  \
    \      return 64;\n    else\n        return __builtin_ctzll(x);\n#else\n    int\
    \ r = 0;\n    if (!(x & 0x00000000ffffffff)) x >>= 32, r |= 32;\n    if (!(x &\
    \ 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x & 0x00ff)) x >>= 8, r |= 8;\n \
    \   if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x & 0x3)) x >>= 2, r |= 2;\n\
    \    if (!(x & 1)) x >>= 1, r |= 1;\n    return r + ((x & 1) ^ 1);\n#endif\n};\n\
    \n\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\ninline uint32_t\
    \ msb32(uint32_t x) {\n    if (x == 0) return 0;\n#ifdef __has_builtin\n    return\
    \ 1 << (31 - __builtin_clz(x));\n#else\n    int r = 0;\n    if (x >> 16) x >>=\
    \ 16, r |= 16;\n    if (x >> 8) x >>= 8, r |= 8;\n    if (x >> 4) x >>= 4, r |=\
    \ 4;\n    if (x >> 2) x >>= 2, r |= 2;\n    return 1 << (r | (x >> 1));\n#endif\n\
    };\n\ninline uint64_t msb64(uint64_t x) {\n    if (x == 0) return 0;\n#ifdef __has_builtin\n\
    \    return 1 << (63 - __builtin_clzll(x));\n#else\n    int r = 0;\n    if (x\
    \ >> 32) x >>= 32, r |= 32;\n    if (x >> 16) x >>= 16, r |= 16;\n    if (x >>\
    \ 8) x >>= 8, r |= 8;\n    if (x >> 4) x >>= 4, r |= 4;\n    if (x >> 2) x >>=\
    \ 2, r |= 2;\n    return 1 << (r | (x >> 1));\n#endif\n};\n\n\n#line 9 \"sparse_table/disjoint_sparse_table.hpp\"\
    \n\n//===\ntemplate <class SemiGroup>\nstruct DisjointSparseTable {\n    using\
    \ T = typename SemiGroup::value_type;\n    using G = SemiGroup;\n\n    std::vector<std::vector<T>>\
    \ table;\n\n    DisjointSparseTable() = default;\n    template <class InputItr>\n\
    \    DisjointSparseTable(InputItr first, InputItr last) {\n        build(first,\
    \ last);\n    };\n\n    template <class InputItr>\n    void build(InputItr first,\
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
    \ == 0)\n            return table[0][l];\n        else\n            return G::operation(table[ctz32(msb32(x))][l],\n\
    \                                table[ctz32(msb32(x))][r]);\n    };\n    T fold(int\
    \ l, int r, SemiGroup e) {\n        if (l >= r) return e;\n        return fold(l,\
    \ r);\n    };\n\n    int size() { return table[0].size(); };\n    const T operator[](int\
    \ k) { return fold(k, k + 1); };\n};\n//===\n\n#line 4 \"test/yosupo/static_range_sum.test.cpp\"\
    \nusing namespace std;\nusing llong = long long;\n\nstruct Sum {\n    using T\
    \ = llong;\n    using value_type = T;\n\n    inline static T operation(T x, T\
    \ y) {\n        return x + y;\n    };\n};\n\nllong n, q;\nvector<llong> a;\nDisjointSparseTable<Sum>\
    \ dst;\n\nint main() {\n    cin >> n >> q;\n    a.resize(n);\n    for (auto &v:a)\
    \ cin >> v;\n\n    dst.build(a.begin(), a.end());\n\n    while (q--) {\n     \
    \   llong l, r;\n        cin >> l >> r;\n        cout << dst.fold(l, r) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <iostream>\n#include \"../../sparse_table/disjoint_sparse_table.hpp\"\nusing\
    \ namespace std;\nusing llong = long long;\n\nstruct Sum {\n    using T = llong;\n\
    \    using value_type = T;\n\n    inline static T operation(T x, T y) {\n    \
    \    return x + y;\n    };\n};\n\nllong n, q;\nvector<llong> a;\nDisjointSparseTable<Sum>\
    \ dst;\n\nint main() {\n    cin >> n >> q;\n    a.resize(n);\n    for (auto &v:a)\
    \ cin >> v;\n\n    dst.build(a.begin(), a.end());\n\n    while (q--) {\n     \
    \   llong l, r;\n        cin >> l >> r;\n        cout << dst.fold(l, r) << '\\\
    n';\n    }\n}"
  dependsOn:
  - sparse_table/disjoint_sparse_table.hpp
  - bit/ctz.hpp
  - bit/msb.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-07 22:49:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_sum.test.cpp
- /verify/test/yosupo/static_range_sum.test.cpp.html
title: test/yosupo/static_range_sum.test.cpp
---
