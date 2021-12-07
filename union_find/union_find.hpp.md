---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/union_find.test.cpp
    title: test/yosupo/union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"union_find/union_find.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <utility>\n\n//===\nstruct UnionFind {\n    std::vector<int> parent;\n\n   \
    \ UnionFind() = default;\n    UnionFind(int nmemb) {\n        init(nmemb);\n \
    \   };\n\n    void init(int nmemb) {\n        parent.clear();\n        parent.resize(nmemb,\
    \ -1);\n    };\n\n    int represent(int x) {\n        if (parent[x] < 0) return\
    \ x;\n        return parent[x] = represent(parent[x]);\n    };\n\n    void unite(int\
    \ x, int y) {\n        x = represent(x);\n        y = represent(y);\n\n      \
    \  if (x == y) return;\n\n        if (parent[y] < parent[x]) std::swap(x, y);\n\
    \n        parent[x] += parent[y];\n        parent[y] = x;\n        \n        return;\n\
    \    };\n    \n    bool same(int x, int y) {\n        return represent(x) == represent(y);\n\
    \    };\n    int size(int x) {\n        return -(parent[represent(x)]);\n    };\n\
    };\n//===\n\n\n"
  code: "#ifndef UNION_FIND_HPP\n#define UNION_FIND_HPP\n\n#include <vector>\n#include\
    \ <utility>\n\n//===\nstruct UnionFind {\n    std::vector<int> parent;\n\n   \
    \ UnionFind() = default;\n    UnionFind(int nmemb) {\n        init(nmemb);\n \
    \   };\n\n    void init(int nmemb) {\n        parent.clear();\n        parent.resize(nmemb,\
    \ -1);\n    };\n\n    int represent(int x) {\n        if (parent[x] < 0) return\
    \ x;\n        return parent[x] = represent(parent[x]);\n    };\n\n    void unite(int\
    \ x, int y) {\n        x = represent(x);\n        y = represent(y);\n\n      \
    \  if (x == y) return;\n\n        if (parent[y] < parent[x]) std::swap(x, y);\n\
    \n        parent[x] += parent[y];\n        parent[y] = x;\n        \n        return;\n\
    \    };\n    \n    bool same(int x, int y) {\n        return represent(x) == represent(y);\n\
    \    };\n    int size(int x) {\n        return -(parent[represent(x)]);\n    };\n\
    };\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: union_find/union_find.hpp
  requiredBy: []
  timestamp: '2021-09-09 19:48:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/union_find.test.cpp
documentation_of: union_find/union_find.hpp
layout: document
redirect_from:
- /library/union_find/union_find.hpp
- /library/union_find/union_find.hpp.html
title: union_find/union_find.hpp
---