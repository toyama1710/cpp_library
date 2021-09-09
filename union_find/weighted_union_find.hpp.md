---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL1B.test.cpp
    title: test/aoj/DSL1B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"union_find/weighted_union_find.hpp\"\n\n\n#include <vector>\n\
    \n//===\ntemplate<class Abel>\nstruct WeightedUnionFind {\n    using T = typename\
    \ Abel::value_type;\n\n    std::vector<int> parent; // [i] = i-th node's parent.\
    \ if [i] < 0, i-th node is root.\n    std::vector<T> diff_weight; // distance\
    \ from parent\n    \n    WeightedUnionFind() = default;\n    WeightedUnionFind(int\
    \ nmemb) {\n        init(nmemb);\n    };\n\n    void init(int nmemb) {\n     \
    \   parent.resize(nmemb, -1);\n        diff_weight.resize(nmemb, Abel::identity());\n\
    \    };\n\n    int root(int x) {\n        if (parent[x] < 0) return x;\n     \
    \   \n        int p = root(parent[x]);\n        diff_weight[x] = Abel::operation(diff_weight[x],\
    \ diff_weight[parent[x]]);\n        parent[x] = p;\n\n        return p;\n    };\n\
    \n    // unite x, y; weight(y) - weight(x) = w\n    bool unite(int x, int y, T\
    \ w) {\n        T wx = weight(x);\n        T wy = weight(y);\n        x = root(x);\n\
    \        y = root(y);\n\n        if (x == y) return false;\n        w = Abel::operation(w,\
    \ wx);\n        w = Abel::operation(w, Abel::inverse(wy));\n        if (size(x)\
    \ < size(y)) std::swap(x, y), w = Abel::inverse(w);\n\n        parent[x] += parent[y];\n\
    \        parent[y] = x;\n        diff_weight[y] = w;\n        \n        return\
    \ true;\n    };\n    \n    bool same(int x, int y) {\n        return root(x) ==\
    \ root(y);\n    };\n\n    T weight(int x) {\n        root(x);\n        return\
    \ diff_weight[x];\n    };\n\n    T diff(int x, int y) {\n        return Abel::operation(weight(y),\n\
    \                Abel::inverse(weight(x)));\n    };\n\n    int size(int x) {\n\
    \        return -parent[root(x)];\n    };\n};\n//===\n\n\n"
  code: "#ifndef WEIGHTED_UNION_FIND_HPP\n#define WEIGHTED_UNION_FIND_HPP\n#include\
    \ <vector>\n\n//===\ntemplate<class Abel>\nstruct WeightedUnionFind {\n    using\
    \ T = typename Abel::value_type;\n\n    std::vector<int> parent; // [i] = i-th\
    \ node's parent. if [i] < 0, i-th node is root.\n    std::vector<T> diff_weight;\
    \ // distance from parent\n    \n    WeightedUnionFind() = default;\n    WeightedUnionFind(int\
    \ nmemb) {\n        init(nmemb);\n    };\n\n    void init(int nmemb) {\n     \
    \   parent.resize(nmemb, -1);\n        diff_weight.resize(nmemb, Abel::identity());\n\
    \    };\n\n    int root(int x) {\n        if (parent[x] < 0) return x;\n     \
    \   \n        int p = root(parent[x]);\n        diff_weight[x] = Abel::operation(diff_weight[x],\
    \ diff_weight[parent[x]]);\n        parent[x] = p;\n\n        return p;\n    };\n\
    \n    // unite x, y; weight(y) - weight(x) = w\n    bool unite(int x, int y, T\
    \ w) {\n        T wx = weight(x);\n        T wy = weight(y);\n        x = root(x);\n\
    \        y = root(y);\n\n        if (x == y) return false;\n        w = Abel::operation(w,\
    \ wx);\n        w = Abel::operation(w, Abel::inverse(wy));\n        if (size(x)\
    \ < size(y)) std::swap(x, y), w = Abel::inverse(w);\n\n        parent[x] += parent[y];\n\
    \        parent[y] = x;\n        diff_weight[y] = w;\n        \n        return\
    \ true;\n    };\n    \n    bool same(int x, int y) {\n        return root(x) ==\
    \ root(y);\n    };\n\n    T weight(int x) {\n        root(x);\n        return\
    \ diff_weight[x];\n    };\n\n    T diff(int x, int y) {\n        return Abel::operation(weight(y),\n\
    \                Abel::inverse(weight(x)));\n    };\n\n    int size(int x) {\n\
    \        return -parent[root(x)];\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: union_find/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2021-09-09 19:48:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL1B.test.cpp
documentation_of: union_find/weighted_union_find.hpp
layout: document
redirect_from:
- /library/union_find/weighted_union_find.hpp
- /library/union_find/weighted_union_find.hpp.html
title: union_find/weighted_union_find.hpp
---
