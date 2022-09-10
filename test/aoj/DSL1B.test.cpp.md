---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: union_find/weighted_union_find.hpp
    title: union_find/weighted_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL1B.test.cpp\"\n#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n// header file section\n#include <algorithm>\n#include <bitset>\n#include\
    \ <cfloat>\n#include <cstdio>\n#include <functional>\n#include <iostream>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <vector>\n\n#line 1 \"union_find/weighted_union_find.hpp\"\n\n\n#line\
    \ 4 \"union_find/weighted_union_find.hpp\"\n\n//===\ntemplate <class Abel>\nstruct\
    \ WeightedUnionFind {\n    using T = typename Abel::value_type;\n\n    std::vector<int>\n\
    \        parent;  // [i] = i-th node's parent. if [i] < 0, i-th node is root.\n\
    \    std::vector<T> diff_weight;  // distance from parent\n\n    WeightedUnionFind()\
    \ = default;\n    WeightedUnionFind(int nmemb) {\n        init(nmemb);\n    };\n\
    \n    void init(int nmemb) {\n        parent.resize(nmemb, -1);\n        diff_weight.resize(nmemb,\
    \ Abel::identity());\n    };\n\n    int root(int x) {\n        if (parent[x] <\
    \ 0) return x;\n\n        int p = root(parent[x]);\n        diff_weight[x] =\n\
    \            Abel::operation(diff_weight[x], diff_weight[parent[x]]);\n      \
    \  parent[x] = p;\n\n        return p;\n    };\n\n    // unite x, y; weight(y)\
    \ - weight(x) = w\n    bool unite(int x, int y, T w) {\n        T wx = weight(x);\n\
    \        T wy = weight(y);\n        x = root(x);\n        y = root(y);\n\n   \
    \     if (x == y) return false;\n        w = Abel::operation(w, wx);\n       \
    \ w = Abel::operation(w, Abel::inverse(wy));\n        if (size(x) < size(y)) std::swap(x,\
    \ y), w = Abel::inverse(w);\n\n        parent[x] += parent[y];\n        parent[y]\
    \ = x;\n        diff_weight[y] = w;\n\n        return true;\n    };\n\n    bool\
    \ same(int x, int y) {\n        return root(x) == root(y);\n    };\n\n    T weight(int\
    \ x) {\n        root(x);\n        return diff_weight[x];\n    };\n\n    T diff(int\
    \ x, int y) {\n        return Abel::operation(weight(y), Abel::inverse(weight(x)));\n\
    \    };\n\n    int size(int x) {\n        return -parent[root(x)];\n    };\n};\n\
    //===\n\n\n#line 19 \"test/aoj/DSL1B.test.cpp\"\n\nusing namespace std;\nusing\
    \ llong = long long;\n\nstruct A {\n    using T = llong;\n    using value_type\
    \ = T;\n\n    static inline T identity() {\n        return 0;\n    };\n\n    static\
    \ inline T operation(T x, T y) {\n        return x + y;\n    };\n\n    static\
    \ inline T inverse(T x) {\n        return -x;\n    };\n};\n\nllong n, q;\nllong\
    \ com, x, y, w;\n\nint main() {\n    cin >> n >> q;\n    WeightedUnionFind<A>\
    \ uf(n);\n\n    while (q--) {\n        cin >> com;\n\n        if (com == 0) {\n\
    \            cin >> x >> y >> w;\n            uf.unite(x, y, w);\n        } else\
    \ {\n            cin >> x >> y;\n\n            if (uf.same(x, y)) {\n        \
    \        cout << uf.diff(x, y) << '\\n';\n            } else {\n             \
    \   cout << \"?\\n\";\n            }\n        }\n    }\n\n    return 0;\n};\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n// header file section\n#include <algorithm>\n#include <bitset>\n#include\
    \ <cfloat>\n#include <cstdio>\n#include <functional>\n#include <iostream>\n#include\
    \ <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n\
    #include <vector>\n\n#include \"../../union_find/weighted_union_find.hpp\"\n\n\
    using namespace std;\nusing llong = long long;\n\nstruct A {\n    using T = llong;\n\
    \    using value_type = T;\n\n    static inline T identity() {\n        return\
    \ 0;\n    };\n\n    static inline T operation(T x, T y) {\n        return x +\
    \ y;\n    };\n\n    static inline T inverse(T x) {\n        return -x;\n    };\n\
    };\n\nllong n, q;\nllong com, x, y, w;\n\nint main() {\n    cin >> n >> q;\n \
    \   WeightedUnionFind<A> uf(n);\n\n    while (q--) {\n        cin >> com;\n\n\
    \        if (com == 0) {\n            cin >> x >> y >> w;\n            uf.unite(x,\
    \ y, w);\n        } else {\n            cin >> x >> y;\n\n            if (uf.same(x,\
    \ y)) {\n                cout << uf.diff(x, y) << '\\n';\n            } else {\n\
    \                cout << \"?\\n\";\n            }\n        }\n    }\n\n    return\
    \ 0;\n};\n"
  dependsOn:
  - union_find/weighted_union_find.hpp
  isVerificationFile: true
  path: test/aoj/DSL1B.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL1B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL1B.test.cpp
- /verify/test/aoj/DSL1B.test.cpp.html
title: test/aoj/DSL1B.test.cpp
---
