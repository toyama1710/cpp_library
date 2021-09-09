---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: union_find/union_find.hpp
    title: union_find/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/union_find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#line 1 \"union_find/union_find.hpp\"\n\n\n\n#line 5 \"union_find/union_find.hpp\"\
    \n#include <utility>\n\n//===\nstruct UnionFind {\n    std::vector<int> parent;\n\
    \n    UnionFind() = default;\n    UnionFind(int nmemb) {\n        init(nmemb);\n\
    \    };\n\n    void init(int nmemb) {\n        parent.clear();\n        parent.resize(nmemb,\
    \ -1);\n    };\n\n    int represent(int x) {\n        if (parent[x] < 0) return\
    \ x;\n        return parent[x] = represent(parent[x]);\n    };\n\n    void unite(int\
    \ x, int y) {\n        x = represent(x);\n        y = represent(y);\n\n      \
    \  if (x == y) return;\n\n        if (parent[y] < parent[x]) std::swap(x, y);\n\
    \n        parent[x] += parent[y];\n        parent[y] = x;\n        \n        return;\n\
    \    };\n    \n    bool same(int x, int y) {\n        return represent(x) == represent(y);\n\
    \    };\n    int size(int x) {\n        return -(parent[represent(x)]);\n    };\n\
    };\n//===\n\n\n#line 16 \"test/yosupo/union_find.test.cpp\"\n\nusing namespace\
    \ std;\nusing llong = long long;\n\nllong n, q;\nllong com, u, v;\nUnionFind uf;\n\
    \nint main() {\n    cin >> n >> q;\n    uf.init(n);\n\n    while (q--) {\n   \
    \     cin >> com >> u >> v;\n\n        if (com == 0) {\n            uf.unite(u,\
    \ v);\n        }\n        else {\n            cout << (uf.same(u, v) ? 1 : 0)\
    \ << endl;\n        }\n    }\n\n    return 0;\n};\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n// header\
    \ file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n#include\
    \ <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include <set>\n\
    #include <bitset>\n#include <functional>\n#include <numeric>\n#include <algorithm>\n\
    #include \"../../union_find/union_find.hpp\"\n\nusing namespace std;\nusing llong\
    \ = long long;\n\nllong n, q;\nllong com, u, v;\nUnionFind uf;\n\nint main() {\n\
    \    cin >> n >> q;\n    uf.init(n);\n\n    while (q--) {\n        cin >> com\
    \ >> u >> v;\n\n        if (com == 0) {\n            uf.unite(u, v);\n       \
    \ }\n        else {\n            cout << (uf.same(u, v) ? 1 : 0) << endl;\n  \
    \      }\n    }\n\n    return 0;\n};\n\n"
  dependsOn:
  - union_find/union_find.hpp
  isVerificationFile: true
  path: test/yosupo/union_find.test.cpp
  requiredBy: []
  timestamp: '2021-09-09 19:48:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/union_find.test.cpp
- /verify/test/yosupo/union_find.test.cpp.html
title: test/yosupo/union_find.test.cpp
---
