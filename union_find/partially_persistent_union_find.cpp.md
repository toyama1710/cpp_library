---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"union_find/partially_persistent_union_find.cpp\"\n#include\
    \ <algorithm>\n#include <cmath>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <functional>\n#include <iostream>\n#include <map>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <vector>\n\
    using namespace std;\n\ntemplate <class T, class Compare = greater<T> >\nusing\
    \ MinHeap = priority_queue<T, vector<T>, Compare>;\ntemplate <class T, class Compare\
    \ = less<T> >\nusing MaxHeap = priority_queue<T, vector<T>, Compare>;\nusing llong\
    \ = long long;\n\n//===\nstruct PartiallyPersistentUnionFind {\n    int turn;\n\
    \    vector<int> t;\n    vector<int> par;\n    vector<vector<pair<int, int> >\
    \ > sz;\n\n    PartiallyPersistentUnionFind(int n)\n        : turn(0),\n     \
    \     t(n, -1),\n          par(n, -1),\n          sz(n, vector<pair<int, int>\
    \ >(1, make_pair(0, 1))){};\n\n    bool unite(int x, int y) {\n        x = find(turn,\
    \ x);\n        y = find(turn, y);\n        turn++;\n\n        if (x == y) return\
    \ false;\n\n        if (par[y] < par[x]) swap(x, y);\n        par[x] += par[y];\n\
    \        par[y] = x;\n\n        t[y] = turn;\n        sz[x].push_back(make_pair(turn,\
    \ -par[x]));\n\n        return true;\n    };\n\n    int find(int time, int x)\
    \ {\n        if (par[x] < 0 || t[x] > time) return x;\n        return find(time,\
    \ par[x]);\n    };\n\n    bool same(int time, int x, int y) {\n        return\
    \ find(time, x) == find(time, y);\n    };\n\n    int size(int time, int x) {\n\
    \        x = find(time, x);\n        return (upper_bound(sz[x].begin(), sz[x].end(),\n\
    \                            make_pair(time, 1 << 30)) -\n                1)\n\
    \            ->second;\n    };\n};\n//===\n\nint CodeThanksFes2017H() {\n    int\
    \ n, m;\n    int a, b;\n    int q;\n    int x, y;\n\n    cin >> n >> m;\n    PartiallyPersistentUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < m; i++) {\n        cin >> a >> b;\n      \
    \  --a, --b;\n\n        uf.unite(a, b);\n    }\n\n    cin >> q;\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> x >> y;\n        --x, --y;\n\n        int\
    \ valid = m + 1;\n        int invalid = 0;\n\n        while (valid - invalid >\
    \ 1) {\n            int mid = (valid + invalid) / 2;\n\n            if (uf.same(mid,\
    \ x, y)) {\n                valid = mid;\n            } else {\n             \
    \   invalid = mid;\n            }\n        }\n\n        if (invalid == m) {\n\
    \            cout << -1 << endl;\n        } else {\n            cout << valid\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n\nint AGC002D() {\n    int n,\
    \ m;\n    int a, b;\n    int q;\n    int x, y, z;\n\n    cin >> n >> m;\n    PartiallyPersistentUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < m; i++) {\n        cin >> a >> b;\n      \
    \  a--, b--;\n\n        uf.unite(a, b);\n    }\n\n    auto f = [&](int t) {\n\
    \        llong xs = uf.size(t, x);\n        llong ys = uf.size(t, y);\n\n    \
    \    if (uf.same(t, x, y))\n            return xs;\n        else\n           \
    \ return xs + ys;\n    };\n\n    cin >> q;\n    for (int i = 0; i < q; i++) {\n\
    \        cin >> x >> y >> z;\n        x--, y--;\n\n        llong valid, invalid;\n\
    \        llong mid;\n\n        valid = m;\n        invalid = 0;\n        while\
    \ (valid - invalid > 1) {\n            mid = (valid + invalid) / 2;\n\n      \
    \      if (f(mid) >= z)\n                valid = mid;\n            else\n    \
    \            invalid = mid;\n        }\n\n        cout << valid << endl;\n   \
    \ }\n\n    return 0;\n}\n\nint main() {\n    // return CodeThanksFes2017H();\n\
    \    return AGC002D();\n}\n"
  code: "#include <algorithm>\n#include <cmath>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <functional>\n#include <iostream>\n#include <map>\n\
    #include <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate <class T, class Compare = greater<T>\
    \ >\nusing MinHeap = priority_queue<T, vector<T>, Compare>;\ntemplate <class T,\
    \ class Compare = less<T> >\nusing MaxHeap = priority_queue<T, vector<T>, Compare>;\n\
    using llong = long long;\n\n//===\nstruct PartiallyPersistentUnionFind {\n   \
    \ int turn;\n    vector<int> t;\n    vector<int> par;\n    vector<vector<pair<int,\
    \ int> > > sz;\n\n    PartiallyPersistentUnionFind(int n)\n        : turn(0),\n\
    \          t(n, -1),\n          par(n, -1),\n          sz(n, vector<pair<int,\
    \ int> >(1, make_pair(0, 1))){};\n\n    bool unite(int x, int y) {\n        x\
    \ = find(turn, x);\n        y = find(turn, y);\n        turn++;\n\n        if\
    \ (x == y) return false;\n\n        if (par[y] < par[x]) swap(x, y);\n       \
    \ par[x] += par[y];\n        par[y] = x;\n\n        t[y] = turn;\n        sz[x].push_back(make_pair(turn,\
    \ -par[x]));\n\n        return true;\n    };\n\n    int find(int time, int x)\
    \ {\n        if (par[x] < 0 || t[x] > time) return x;\n        return find(time,\
    \ par[x]);\n    };\n\n    bool same(int time, int x, int y) {\n        return\
    \ find(time, x) == find(time, y);\n    };\n\n    int size(int time, int x) {\n\
    \        x = find(time, x);\n        return (upper_bound(sz[x].begin(), sz[x].end(),\n\
    \                            make_pair(time, 1 << 30)) -\n                1)\n\
    \            ->second;\n    };\n};\n//===\n\nint CodeThanksFes2017H() {\n    int\
    \ n, m;\n    int a, b;\n    int q;\n    int x, y;\n\n    cin >> n >> m;\n    PartiallyPersistentUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < m; i++) {\n        cin >> a >> b;\n      \
    \  --a, --b;\n\n        uf.unite(a, b);\n    }\n\n    cin >> q;\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> x >> y;\n        --x, --y;\n\n        int\
    \ valid = m + 1;\n        int invalid = 0;\n\n        while (valid - invalid >\
    \ 1) {\n            int mid = (valid + invalid) / 2;\n\n            if (uf.same(mid,\
    \ x, y)) {\n                valid = mid;\n            } else {\n             \
    \   invalid = mid;\n            }\n        }\n\n        if (invalid == m) {\n\
    \            cout << -1 << endl;\n        } else {\n            cout << valid\
    \ << endl;\n        }\n    }\n\n    return 0;\n}\n\nint AGC002D() {\n    int n,\
    \ m;\n    int a, b;\n    int q;\n    int x, y, z;\n\n    cin >> n >> m;\n    PartiallyPersistentUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < m; i++) {\n        cin >> a >> b;\n      \
    \  a--, b--;\n\n        uf.unite(a, b);\n    }\n\n    auto f = [&](int t) {\n\
    \        llong xs = uf.size(t, x);\n        llong ys = uf.size(t, y);\n\n    \
    \    if (uf.same(t, x, y))\n            return xs;\n        else\n           \
    \ return xs + ys;\n    };\n\n    cin >> q;\n    for (int i = 0; i < q; i++) {\n\
    \        cin >> x >> y >> z;\n        x--, y--;\n\n        llong valid, invalid;\n\
    \        llong mid;\n\n        valid = m;\n        invalid = 0;\n        while\
    \ (valid - invalid > 1) {\n            mid = (valid + invalid) / 2;\n\n      \
    \      if (f(mid) >= z)\n                valid = mid;\n            else\n    \
    \            invalid = mid;\n        }\n\n        cout << valid << endl;\n   \
    \ }\n\n    return 0;\n}\n\nint main() {\n    // return CodeThanksFes2017H();\n\
    \    return AGC002D();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: union_find/partially_persistent_union_find.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: union_find/partially_persistent_union_find.cpp
layout: document
redirect_from:
- /library/union_find/partially_persistent_union_find.cpp
- /library/union_find/partially_persistent_union_find.cpp.html
title: union_find/partially_persistent_union_find.cpp
---
