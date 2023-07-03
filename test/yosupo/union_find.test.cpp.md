---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: union_find/union_find.hpp
    title: union_find/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/union_find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n// header file section\n#include <algorithm>\n#include <bitset>\n#include <cfloat>\n\
    #include <cstdio>\n#include <functional>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <vector>\n\n#line 1 \"union_find/union_find.hpp\"\n\n\n\n#include <utility>\n\
    #line 6 \"union_find/union_find.hpp\"\n\n//===\nstruct UnionFind {\n    std::vector<int>\
    \ parent;\n\n    UnionFind() = default;\n    UnionFind(int nmemb) {\n        init(nmemb);\n\
    \    };\n\n    void init(int nmemb) {\n        parent.clear();\n        parent.resize(nmemb,\
    \ -1);\n    };\n\n    int represent(int x) {\n        if (parent[x] < 0) return\
    \ x;\n        return parent[x] = represent(parent[x]);\n    };\n\n    void unite(int\
    \ x, int y) {\n        x = represent(x);\n        y = represent(y);\n\n      \
    \  if (x == y) return;\n\n        if (parent[y] < parent[x]) std::swap(x, y);\n\
    \n        parent[x] += parent[y];\n        parent[y] = x;\n\n        return;\n\
    \    };\n\n    bool same(int x, int y) {\n        return represent(x) == represent(y);\n\
    \    };\n\n    int size(int x) {\n        return -(parent[represent(x)]);\n  \
    \  };\n};\n//===\n\n\n#line 17 \"test/yosupo/union_find.test.cpp\"\n\nusing namespace\
    \ std;\nusing llong = long long;\n\nllong n, q;\nllong com, u, v;\nUnionFind uf;\n\
    \nint main() {\n    cin >> n >> q;\n    uf.init(n);\n\n    while (q--) {\n   \
    \     cin >> com >> u >> v;\n\n        if (com == 0) {\n            uf.unite(u,\
    \ v);\n        } else {\n            cout << (uf.same(u, v) ? 1 : 0) << endl;\n\
    \        }\n    }\n\n    return 0;\n};\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n// header\
    \ file section\n#include <algorithm>\n#include <bitset>\n#include <cfloat>\n#include\
    \ <cstdio>\n#include <functional>\n#include <iostream>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <vector>\n\
    \n#include \"../../union_find/union_find.hpp\"\n\nusing namespace std;\nusing\
    \ llong = long long;\n\nllong n, q;\nllong com, u, v;\nUnionFind uf;\n\nint main()\
    \ {\n    cin >> n >> q;\n    uf.init(n);\n\n    while (q--) {\n        cin >>\
    \ com >> u >> v;\n\n        if (com == 0) {\n            uf.unite(u, v);\n   \
    \     } else {\n            cout << (uf.same(u, v) ? 1 : 0) << endl;\n       \
    \ }\n    }\n\n    return 0;\n};\n"
  dependsOn:
  - union_find/union_find.hpp
  isVerificationFile: true
  path: test/yosupo/union_find.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 22:11:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/union_find.test.cpp
- /verify/test/yosupo/union_find.test.cpp.html
title: test/yosupo/union_find.test.cpp
---
