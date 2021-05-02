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
  bundledCode: "#line 1 \"disjoint_set/partially_persitent_union_find.cpp\"\n#include\
    \ <iostream>\n#include <cstdio>\n#include <cstdlib>\n#include <cmath>\n#include\
    \ <cstring>\n#include <functional>\n#include <algorithm>\n#include <vector>\n\
    #include <string>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\nusing namespace std;\n\ntemplate<class T, class Compare = greater<T>\
    \ >\nusing MinHeap = priority_queue<T, vector<T>, Compare>;\ntemplate<class T,\
    \ class Compare = less<T> >\nusing MaxHeap = priority_queue<T, vector<T>, Compare>;\n\
    using llong = long long;\n\n//===\nstruct PartiallyPersistentUnionFind {\n   \
    \ int turn;\n    vector<int> t;\n    vector<int> par;\n    vector<vector<pair<int,\
    \ int> > > sz;\n\n    PartiallyPersistentUnionFind(int n):\n        turn(0),\n\
    \        t(n, -1),\n        par(n, -1),\n        sz(n, vector<pair<int, int> >(1,\
    \ make_pair(0, 1)))\n    {};\n\n    bool unite(int x, int y) {\n        x = find(turn,\
    \ x);\n        y = find(turn, y);\n        turn++;\n\n        if (x == y) return\
    \ false;\n                        \n        if (par[y] < par[x]) swap(x, y);\n\
    \        par[x] += par[y];\n        par[y] = x;\n        \n        t[y] = turn;\n\
    \        sz[x].push_back(make_pair(turn, -par[x]));\n\n        return true;\n\
    \    };\n\n    int find (int time, int x) {\n        if (par[x] < 0 || t[x] >\
    \ time) return x;\n        return find(time, par[x]);\n    };\n\n    bool same(int\
    \ time, int x, int y) {\n        return find(time, x) == find(time, y);\n    };\n\
    \n    int size(int time, int x) {\n        x = find(time, x);\n        return\
    \ (upper_bound(sz[x].begin(), sz[x].end(), make_pair(time, 1<<30)) - 1)->second;\n\
    \    };\n};\n//===\n\nint CodeThanksFes2017H() {\n    int n, m;\n    int a, b;\n\
    \    int q;\n    int x, y;\n\n    cin >> n >> m;\n    PartiallyPersistentUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < m; i++) {\n        cin >> a >> b;\n      \
    \  --a, --b;\n\n        uf.unite(a, b);\n    }\n\n    cin >> q;\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> x >> y;\n        --x, --y;\n\n        int\
    \ valid = m + 1;\n        int invalid = 0;\n\n        while (valid - invalid >\
    \ 1) {\n            int mid = (valid + invalid) / 2;\n\n            if (uf.same(mid,\
    \ x, y)) {\n                valid = mid;\n            }\n            else {\n\
    \                invalid = mid;\n            }\n        }\n\n        if (invalid\
    \ == m) {\n            cout << -1 << endl;\n        }\n        else {\n      \
    \      cout << valid << endl;\n        }\n    }\n\n    return 0;\n}\n\nint AGC002D()\
    \ {\n    int n, m;\n    int a, b;\n    int q;\n    int x, y, z;\n\n    cin >>\
    \ n >> m;\n    PartiallyPersistentUnionFind uf(n);\n\n    for (int i = 0; i <\
    \ m; i++) {\n        cin >> a >> b;\n        a--, b--;\n        \n        uf.unite(a,\
    \ b);\n    }\n\n    auto f = [&](int t) {\n                 llong xs = uf.size(t,\
    \ x);\n                 llong ys = uf.size(t, y);\n\n                 if (uf.same(t,\
    \ x, y)) return xs;\n                 else return xs + ys;\n             };\n\n\
    \    cin >> q;\n    for (int i = 0; i < q; i++) {\n        cin >> x >> y >> z;\n\
    \        x--, y--;\n\n        llong valid, invalid;\n        llong mid;\n\n  \
    \      valid = m;\n        invalid = 0;\n        while (valid - invalid > 1) {\n\
    \            mid = (valid + invalid) / 2;\n\n            if (f(mid) >= z) valid\
    \ = mid;\n            else invalid = mid;\n        }\n        \n        cout <<\
    \ valid << endl;\n    }\n\n    return 0;\n}\n\nint main() {\n    //return CodeThanksFes2017H();\n\
    \    return AGC002D();\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <cstdlib>\n#include <cmath>\n\
    #include <cstring>\n#include <functional>\n#include <algorithm>\n#include <vector>\n\
    #include <string>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\nusing namespace std;\n\ntemplate<class T, class Compare = greater<T>\
    \ >\nusing MinHeap = priority_queue<T, vector<T>, Compare>;\ntemplate<class T,\
    \ class Compare = less<T> >\nusing MaxHeap = priority_queue<T, vector<T>, Compare>;\n\
    using llong = long long;\n\n//===\nstruct PartiallyPersistentUnionFind {\n   \
    \ int turn;\n    vector<int> t;\n    vector<int> par;\n    vector<vector<pair<int,\
    \ int> > > sz;\n\n    PartiallyPersistentUnionFind(int n):\n        turn(0),\n\
    \        t(n, -1),\n        par(n, -1),\n        sz(n, vector<pair<int, int> >(1,\
    \ make_pair(0, 1)))\n    {};\n\n    bool unite(int x, int y) {\n        x = find(turn,\
    \ x);\n        y = find(turn, y);\n        turn++;\n\n        if (x == y) return\
    \ false;\n                        \n        if (par[y] < par[x]) swap(x, y);\n\
    \        par[x] += par[y];\n        par[y] = x;\n        \n        t[y] = turn;\n\
    \        sz[x].push_back(make_pair(turn, -par[x]));\n\n        return true;\n\
    \    };\n\n    int find (int time, int x) {\n        if (par[x] < 0 || t[x] >\
    \ time) return x;\n        return find(time, par[x]);\n    };\n\n    bool same(int\
    \ time, int x, int y) {\n        return find(time, x) == find(time, y);\n    };\n\
    \n    int size(int time, int x) {\n        x = find(time, x);\n        return\
    \ (upper_bound(sz[x].begin(), sz[x].end(), make_pair(time, 1<<30)) - 1)->second;\n\
    \    };\n};\n//===\n\nint CodeThanksFes2017H() {\n    int n, m;\n    int a, b;\n\
    \    int q;\n    int x, y;\n\n    cin >> n >> m;\n    PartiallyPersistentUnionFind\
    \ uf(n);\n\n    for (int i = 0; i < m; i++) {\n        cin >> a >> b;\n      \
    \  --a, --b;\n\n        uf.unite(a, b);\n    }\n\n    cin >> q;\n    for (int\
    \ i = 0; i < q; i++) {\n        cin >> x >> y;\n        --x, --y;\n\n        int\
    \ valid = m + 1;\n        int invalid = 0;\n\n        while (valid - invalid >\
    \ 1) {\n            int mid = (valid + invalid) / 2;\n\n            if (uf.same(mid,\
    \ x, y)) {\n                valid = mid;\n            }\n            else {\n\
    \                invalid = mid;\n            }\n        }\n\n        if (invalid\
    \ == m) {\n            cout << -1 << endl;\n        }\n        else {\n      \
    \      cout << valid << endl;\n        }\n    }\n\n    return 0;\n}\n\nint AGC002D()\
    \ {\n    int n, m;\n    int a, b;\n    int q;\n    int x, y, z;\n\n    cin >>\
    \ n >> m;\n    PartiallyPersistentUnionFind uf(n);\n\n    for (int i = 0; i <\
    \ m; i++) {\n        cin >> a >> b;\n        a--, b--;\n        \n        uf.unite(a,\
    \ b);\n    }\n\n    auto f = [&](int t) {\n                 llong xs = uf.size(t,\
    \ x);\n                 llong ys = uf.size(t, y);\n\n                 if (uf.same(t,\
    \ x, y)) return xs;\n                 else return xs + ys;\n             };\n\n\
    \    cin >> q;\n    for (int i = 0; i < q; i++) {\n        cin >> x >> y >> z;\n\
    \        x--, y--;\n\n        llong valid, invalid;\n        llong mid;\n\n  \
    \      valid = m;\n        invalid = 0;\n        while (valid - invalid > 1) {\n\
    \            mid = (valid + invalid) / 2;\n\n            if (f(mid) >= z) valid\
    \ = mid;\n            else invalid = mid;\n        }\n        \n        cout <<\
    \ valid << endl;\n    }\n\n    return 0;\n}\n\nint main() {\n    //return CodeThanksFes2017H();\n\
    \    return AGC002D();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: disjoint_set/partially_persitent_union_find.cpp
  requiredBy: []
  timestamp: '2019-09-22 01:10:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: disjoint_set/partially_persitent_union_find.cpp
layout: document
redirect_from:
- /library/disjoint_set/partially_persitent_union_find.cpp
- /library/disjoint_set/partially_persitent_union_find.cpp.html
title: disjoint_set/partially_persitent_union_find.cpp
---
