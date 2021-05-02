---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: array/persistent_array.hpp
    title: array/persistent_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_union_find.test.cpp
    title: test/yosupo/persistent_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"disjoint_set/persistent_union_find.hpp\"\n\n\n\n#line 1\
    \ \"array/persistent_array.hpp\"\n\n\n\n#include <memory>\n#include <cstring>\n\
    #include <algorithm>\n\n//===\n// LIBRARY SECTION\n\n// #include <memory>\n//\
    \ #include <cstring>\n// #include <algorithm>\n// K-ary tree\ntemplate<class T,\
    \ int K = 2>\nstruct PersistentArray {\n    struct Node;\n    using Leaf = T;\n\
    \    struct Node {\n        T dat;\n        Node* ch[K] = {};\n\n        Node()\
    \ = default;\n        Node(Node *np) {\n            dat = np->dat;\n         \
    \   std::memcpy(ch, np->ch, sizeof(Node *) * K);\n        };\n    };\n\n    Node\
    \ *root = nullptr;\n    int arr_size = 0;\n\n    PersistentArray() = default;\n\
    \    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size)\
    \ {};\n    PersistentArray(int size, const T &d = T()):arr_size(size) {\n    \
    \    root = new Node();\n        init(root, size, d);\n    };\n    Node *init(Node\
    \ *np, int size, T d) {\n        np->dat = d;\n                             \n\
    \        if (size == 1) return np;\n        for (int i = 0; i < std::min(K, size);\
    \ i++) {\n            np->ch[i] = init(new Node(), (size + K - 1) / K, d);\n \
    \       }\n        return np;\n    };\n\n    const T get(int idx) const {\n  \
    \      return get(idx, root);\n    };\n    const T get(int idx, Node *np) const\
    \ {\n        if (idx == 0) return np->dat;\n        return get((idx - 1) / K,\
    \ np->ch[idx % K]);\n    };\n    \n    PersistentArray set(int idx, const T &val)\
    \ {\n        return {set(idx, val, root), arr_size};\n    };\n    Node *set(int\
    \ idx, const T &val, Node *np) {\n        if (idx == 0) {\n            Node *node\
    \ = new Node(np);\n            node->dat = val;\n            return node;\n  \
    \      }\n        else {\n            Node *node = new Node(np);\n           \
    \ node->ch[idx % K] = set((idx - 1) / K, val, np->ch[idx % K]);\n            return\
    \ node;\n        }\n    };\n\n    void destructive_set(int idx, const T &val)\
    \ {\n        destructive_set(idx, val, root);\n    };\n    void destructive_set(int\
    \ idx, const T &val, Node *np) {\n        if (idx == 0) np->dat = val;\n     \
    \   else destructive_set((idx - 1) / K, val, np->ch[idx % K]);\n    };\n\n   \
    \ int size() {\n        return arr_size;\n    };\n    PersistentArray get_array()\
    \ {\n        return *this;\n    };\n    \n    const T operator [] (int idx) const\
    \ {\n        return get(idx, root);\n    };\n};\n//===\n\n\n#line 5 \"disjoint_set/persistent_union_find.hpp\"\
    \n\n//===\n// LIBRARY SECTION\n\n// 0-indexed\ntemplate<int K = 2>\nstruct PersistentUnionFind\
    \ {\n    PersistentArray<int, K> par;\n\n    PersistentUnionFind() = default;\n\
    \    PersistentUnionFind(int n): par(n, -1) {};\n    PersistentUnionFind(PersistentArray<int,\
    \ K> arr):par(arr) {};\n\n    PersistentUnionFind unite(int x, int y) {\n    \
    \    x = root(x);\n        y = root(y);\n\n        if (x == y) return *this;\n\
    \n        if (size(x) > size(y)) {\n            auto tmp = par.set(x, par[x] +\
    \ par[y]);\n            return tmp.set(y, x);\n        }\n        else {\n   \
    \         auto tmp = par.set(y, par[y] + par[x]);\n            return tmp.set(x,\
    \ y);\n        }\n    };\n\n    int root(int x) {\n        if (par[x] < 0) return\
    \ x;\n        int res = root(par[x]);\n        return res;\n    };\n\n    bool\
    \ same(int x, int y) {\n        return root(x) == root(y);\n    };\n\n    // return\
    \ size of set\n    int size(int x) {\n        return -par[root(x)];\n    };\n\
    };\n//===\n\n\n"
  code: "#ifndef PERSISTENT_UNION_FIND_HPP\n#define PERSISTENT_UNION_FIND_HPP\n\n\
    #include \"../array/persistent_array.hpp\"\n\n//===\n// LIBRARY SECTION\n\n//\
    \ 0-indexed\ntemplate<int K = 2>\nstruct PersistentUnionFind {\n    PersistentArray<int,\
    \ K> par;\n\n    PersistentUnionFind() = default;\n    PersistentUnionFind(int\
    \ n): par(n, -1) {};\n    PersistentUnionFind(PersistentArray<int, K> arr):par(arr)\
    \ {};\n\n    PersistentUnionFind unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n\n        if (x == y) return *this;\n\n        if (size(x)\
    \ > size(y)) {\n            auto tmp = par.set(x, par[x] + par[y]);\n        \
    \    return tmp.set(y, x);\n        }\n        else {\n            auto tmp =\
    \ par.set(y, par[y] + par[x]);\n            return tmp.set(x, y);\n        }\n\
    \    };\n\n    int root(int x) {\n        if (par[x] < 0) return x;\n        int\
    \ res = root(par[x]);\n        return res;\n    };\n\n    bool same(int x, int\
    \ y) {\n        return root(x) == root(y);\n    };\n\n    // return size of set\n\
    \    int size(int x) {\n        return -par[root(x)];\n    };\n};\n//===\n\n#endif\n"
  dependsOn:
  - array/persistent_array.hpp
  isVerificationFile: false
  path: disjoint_set/persistent_union_find.hpp
  requiredBy: []
  timestamp: '2020-06-11 21:13:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_union_find.test.cpp
documentation_of: disjoint_set/persistent_union_find.hpp
layout: document
redirect_from:
- /library/disjoint_set/persistent_union_find.hpp
- /library/disjoint_set/persistent_union_find.hpp.html
title: disjoint_set/persistent_union_find.hpp
---
