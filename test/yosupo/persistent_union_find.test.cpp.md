---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: array/persistent_array.hpp
    title: array/persistent_array.hpp
  - icon: ':heavy_check_mark:'
    path: union_find/persistent_union_find.hpp
    title: union_find/persistent_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_union_find.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include <iostream>\n\
    #include <cstdio>\n#include <cstdlib>\n#include <cmath>\n#include <cassert>\n\
    #include <functional>\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    #include <set>\n#include <map>\n#include <queue>\n#include <stack>\n#line 1 \"\
    union_find/persistent_union_find.hpp\"\n\n\n\n#line 1 \"array/persistent_array.hpp\"\
    \n\n\n\n#include <memory>\n#include <cstring>\n#line 7 \"array/persistent_array.hpp\"\
    \n\n//===\n// LIBRARY SECTION\n\n// #include <memory>\n// #include <cstring>\n\
    // #include <algorithm>\n// K-ary tree\ntemplate<class T, int K = 2>\nstruct PersistentArray\
    \ {\n    struct Node;\n    using Leaf = T;\n    struct Node {\n        T dat;\n\
    \        Node* ch[K] = {};\n\n        Node() = default;\n        Node(Node *np)\
    \ {\n            dat = np->dat;\n            std::memcpy(ch, np->ch, sizeof(Node\
    \ *) * K);\n        };\n    };\n\n    Node *root = nullptr;\n    int arr_size\
    \ = 0;\n\n    PersistentArray() = default;\n    PersistentArray (Node *root, int\
    \ arr_size):root(root), arr_size(arr_size) {};\n    PersistentArray(int size,\
    \ const T &d = T()):arr_size(size) {\n        root = new Node();\n        init(root,\
    \ size, d);\n    };\n    Node *init(Node *np, int size, T d) {\n        np->dat\
    \ = d;\n                             \n        if (size == 1) return np;\n   \
    \     for (int i = 0; i < std::min(K, size); i++) {\n            np->ch[i] = init(new\
    \ Node(), (size + K - 1) / K, d);\n        }\n        return np;\n    };\n\n \
    \   const T get(int idx) const {\n        return get(idx, root);\n    };\n   \
    \ const T get(int idx, Node *np) const {\n        if (idx == 0) return np->dat;\n\
    \        return get((idx - 1) / K, np->ch[idx % K]);\n    };\n    \n    PersistentArray\
    \ set(int idx, const T &val) {\n        return {set(idx, val, root), arr_size};\n\
    \    };\n    Node *set(int idx, const T &val, Node *np) {\n        if (idx ==\
    \ 0) {\n            Node *node = new Node(np);\n            node->dat = val;\n\
    \            return node;\n        }\n        else {\n            Node *node =\
    \ new Node(np);\n            node->ch[idx % K] = set((idx - 1) / K, val, np->ch[idx\
    \ % K]);\n            return node;\n        }\n    };\n\n    void destructive_set(int\
    \ idx, const T &val) {\n        destructive_set(idx, val, root);\n    };\n   \
    \ void destructive_set(int idx, const T &val, Node *np) {\n        if (idx ==\
    \ 0) np->dat = val;\n        else destructive_set((idx - 1) / K, val, np->ch[idx\
    \ % K]);\n    };\n\n    int size() {\n        return arr_size;\n    };\n    PersistentArray\
    \ get_array() {\n        return *this;\n    };\n    \n    const T operator []\
    \ (int idx) const {\n        return get(idx, root);\n    };\n};\n//===\n\n\n#line\
    \ 5 \"union_find/persistent_union_find.hpp\"\n\n//===\n// LIBRARY SECTION\n\n\
    // 0-indexed\ntemplate<int K = 2>\nstruct PersistentUnionFind {\n    PersistentArray<int,\
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
    \    int size(int x) {\n        return -par[root(x)];\n    };\n};\n//===\n\n\n\
    #line 17 \"test/yosupo/persistent_union_find.test.cpp\"\n\nusing namespace std;\n\
    using llong = long long;\nusing UF = PersistentUnionFind<32>;\n\nllong n, q;\n\
    llong t, k, u, v;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    \n    cin >> n >> q;\n\n    vector<UF> uf(q);\n    uf[0] = UF(n);\n    \n\
    \    for (int i = 1; i <= q; i++) {\n        cin >> t >> k >> u >> v;\n      \
    \  k++;\n\n        if (t == 0) {\n            uf[i] = uf[k].unite(u, v);\n   \
    \     }\n        else if (t == 1) {\n            if (uf[k].same(u, v)) {\n   \
    \             cout << 1 << '\\n';\n            }\n            else {\n       \
    \         cout << 0 << '\\n';\n            }\n        }\n    }\n     \n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <iostream>\n#include <cstdio>\n#include <cstdlib>\n#include <cmath>\n\
    #include <cassert>\n#include <functional>\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n#include <set>\n#include <map>\n#include <queue>\n#include\
    \ <stack>\n#include \"../../union_find/persistent_union_find.hpp\"\n\nusing namespace\
    \ std;\nusing llong = long long;\nusing UF = PersistentUnionFind<32>;\n\nllong\
    \ n, q;\nllong t, k, u, v;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    \n    cin >> n >> q;\n\n    vector<UF> uf(q);\n    uf[0] = UF(n);\n    \n\
    \    for (int i = 1; i <= q; i++) {\n        cin >> t >> k >> u >> v;\n      \
    \  k++;\n\n        if (t == 0) {\n            uf[i] = uf[k].unite(u, v);\n   \
    \     }\n        else if (t == 1) {\n            if (uf[k].same(u, v)) {\n   \
    \             cout << 1 << '\\n';\n            }\n            else {\n       \
    \         cout << 0 << '\\n';\n            }\n        }\n    }\n     \n    return\
    \ 0;\n}\n"
  dependsOn:
  - union_find/persistent_union_find.hpp
  - array/persistent_array.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_union_find.test.cpp
  requiredBy: []
  timestamp: '2021-09-09 19:48:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_union_find.test.cpp
- /verify/test/yosupo/persistent_union_find.test.cpp.html
title: test/yosupo/persistent_union_find.test.cpp
---
