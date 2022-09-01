---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: bit/ctz.hpp
    title: bit/ctz.hpp
  - icon: ':x:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  - icon: ':x:'
    path: sparse_table/disjoint_sparse_table.hpp
    title: sparse_table/disjoint_sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include <iostream>\n\n\
    #line 1 \"sparse_table/disjoint_sparse_table.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\n#line 1 \"bit/ctz.hpp\"\n\n\n\n#include <cstdint>\n\ninline\
    \ int ctz32_(uint32_t bit) {\n    static const int table[] = {\n        0,  1,\
    \ 2,  6,  3,  11, 7,  16, 4,  14, 12, 21, 8,  23, 17, 26,\n        31, 5, 10,\
    \ 15, 13, 20, 22, 25, 30, 9,  19, 24, 29, 18, 28, 27,\n    };\n    static const\
    \ uint32_t de_bruijn = 0x04653adf;\n    bit &= ~bit + 1;\n    return table[(bit\
    \ * de_bruijn) >> 27];\n};\ninline int ctz32(uint32_t bit) {\n    if (bit == 0)\
    \ return 32;\n#ifdef __has_builtin\n    return __builtin_ctz(bit);\n#else\n  \
    \  return ctz32_(bit);\n#endif\n};\n\ninline int ctz64_(uint64_t bit) {\n    static\
    \ const int table[] = {\n        0,  1,  2,  7,  3,  13, 8,  19, 4,  25, 14, 28,\
    \ 9,  34, 20, 40,\n        5,  17, 26, 38, 15, 46, 29, 48, 10, 31, 35, 54, 21,\
    \ 50, 41, 57,\n        63, 6,  12, 18, 24, 27, 33, 39, 16, 37, 45, 47, 30, 53,\
    \ 49, 56,\n        62, 11, 23, 32, 36, 44, 52, 55, 61, 22, 43, 51, 60, 42, 59,\
    \ 58,\n    };\n    static const uint64_t de_bruijn = 0x0218a392cd3d5dbfull;\n\
    \    bit &= ~bit + 1;\n    return table[(bit * de_bruijn) >> 58];\n};\ninline\
    \ int ctz64(uint64_t bit) {\n    if (bit == 0) return 64;\n#ifdef __has_builtin\n\
    \    return __builtin_ctzll(bit);\n#else\n    return ctz64_(bit);\n#endif\n};\n\
    \n\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\ninline uint32_t\
    \ msb32_(uint32_t bit) {\n    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit\
    \ |= bit >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n    return bit ^\
    \ (bit >> 1);\n};\ninline uint32_t msb32(uint32_t x) {\n    if (x == 0) return\
    \ 0;\n#ifdef __has_builtin\n    return 1u << (31 - __builtin_clz(x));\n#else\n\
    \    return msb32_(x);\n#endif\n};\n\ninline uint64_t msb64_(uint64_t bit) {\n\
    \    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit >> 4;\n    bit |=\
    \ bit >> 8;\n    bit |= bit >> 16;\n    bit |= bit >> 32;\n    return bit ^ (bit\
    \ >> 1);\n};\ninline uint64_t msb64(uint64_t x) {\n    if (x == 0) return 0;\n\
    #ifdef __has_builtin\n    return 1ull << (63 - __builtin_clzll(x));\n#else\n \
    \   return msb64_(x);\n#endif\n};\n\n\n#line 9 \"sparse_table/disjoint_sparse_table.hpp\"\
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
    \ r);\n    };\n\n    int size() {\n        return table[0].size();\n    };\n \
    \   const T operator[](int k) {\n        return fold(k, k + 1);\n    };\n};\n\
    //===\n\n#line 5 \"test/yosupo/static_range_sum.test.cpp\"\nusing namespace std;\n\
    using llong = long long;\n\nstruct Sum {\n    using T = llong;\n    using value_type\
    \ = T;\n\n    inline static T operation(T x, T y) {\n        return x + y;\n \
    \   };\n};\n\nllong n, q;\nvector<llong> a;\nDisjointSparseTable<Sum> dst;\n\n\
    int main() {\n    cin >> n >> q;\n    a.resize(n);\n    for (auto &v : a) cin\
    \ >> v;\n\n    dst.build(a.begin(), a.end());\n\n    while (q--) {\n        llong\
    \ l, r;\n        cin >> l >> r;\n        cout << dst.fold(l, r) << '\\n';\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <iostream>\n\n#include \"../../sparse_table/disjoint_sparse_table.hpp\"\nusing\
    \ namespace std;\nusing llong = long long;\n\nstruct Sum {\n    using T = llong;\n\
    \    using value_type = T;\n\n    inline static T operation(T x, T y) {\n    \
    \    return x + y;\n    };\n};\n\nllong n, q;\nvector<llong> a;\nDisjointSparseTable<Sum>\
    \ dst;\n\nint main() {\n    cin >> n >> q;\n    a.resize(n);\n    for (auto &v\
    \ : a) cin >> v;\n\n    dst.build(a.begin(), a.end());\n\n    while (q--) {\n\
    \        llong l, r;\n        cin >> l >> r;\n        cout << dst.fold(l, r) <<\
    \ '\\n';\n    }\n}"
  dependsOn:
  - sparse_table/disjoint_sparse_table.hpp
  - bit/ctz.hpp
  - bit/msb.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_sum.test.cpp
- /verify/test/yosupo/static_range_sum.test.cpp.html
title: test/yosupo/static_range_sum.test.cpp
---
