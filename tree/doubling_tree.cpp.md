---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/doubling_tree.cpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\nusing llong = long long;\n\n//===\n// call build()\
    \ before other query (except add_edge)\n// 0-indexed\n// climb(u, d): climb d\
    \ steps towards root\n// fold(u, v):\nstruct DoublingTree {\n    vector<vector<int>\
    \ > G;\n    vector<vector<int> > parent;\n    vector<int> depth;\n    int logn;\n\
    \n    DoublingTree(int n) {\n        logn = 1;\n        while ((1 << logn) < n)\
    \ logn++;\n\n        G.resize(n);\n        parent.assign(logn, vector<int>(n,\
    \ -1));\n        depth.assign(n, -1);\n    };\n\n    template<class Graph>\n \
    \   DoublingTree(Graph &g) {\n        DoublingTree(g.size());\n        for (int\
    \ i = 0; i < g.size(); i++) {\n            G[i].resize(g[i].size());\n       \
    \     for (int j = 0; j < g[i].size(); j++) {\n                G[i][j] = g[i][j];\n\
    \            }\n        }\n    };\n\n    void calc_depth(int u, int d, int par)\
    \ {\n        depth[u] = d++;\n        parent[0][u] = par;\n        for (int v:G[u])\
    \ {\n            if (v == par) continue;\n            calc_depth(v, d, u);\n \
    \       }\n    };\n    \n    void build(vector<int> root = {0}) {\n        for\
    \ (int i = 0; i < root.size(); i++) {\n            calc_depth(root[i], 0, -1);\n\
    \        }\n        for (int k = 1; k < logn; k++) {\n            for (int u =\
    \ 0; u < size(); u++) {\n                if (parent[k - 1][u] == -1) continue;\n\
    \                parent[k][u] = parent[k - 1][parent[k - 1][u]];\n           \
    \ }\n        }\n    };\n    \n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    };\n    int climb(int u, int d) {\n        int\
    \ cnt = 0;\n        while (d) {\n            if (d & 1) u = parent[cnt][u];\n\
    \            d >>= 1;\n            cnt++;\n        }\n        return u;\n    };\n\
    \    // LowestCommonAncestor\n    int lca(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n        v = climb(v, depth[v] - depth[u]);\n\n    \
    \    if (u == v) return u;\n        for (int k = logn - 1; k >= 0; k--) {\n  \
    \          if (parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n\
    \                v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    };\n    inline int distance(int u, int v) {\n        return depth[u] + depth[v]\
    \ - depth[lca(u, v)] * 2;\n    };\n    inline int size() {\n        return G.size();\n\
    \    };\n};\n//===\n\n// verify lca()\nint AOJ_GRL_5_C() {\n    int n;\n    int\
    \ k, c;\n    int q;\n    int u, v;\n\n    cin >> n;\n    DoublingTree t(n);\n\n\
    \    for (int i = 0; i < n; i++) {\n        cin >> k;\n        for (int j = 0;\
    \ j < k; j++) {\n            cin >> c;\n            t.add_edge(i, c);\n      \
    \  }\n    }\n\n    t.build();\n    cin >> q;\n    for (int i = 0; i < q; i++)\
    \ {\n        cin >> u >> v;\n        cout << t.lca(u, v) << endl;\n    }\n\n \
    \   return 0;\n};\n\nint main() {\n    return AOJ_GRL_5_C();\n};\n"
  code: "#include <iostream>\n#include <vector>\nusing namespace std;\nusing llong\
    \ = long long;\n\n//===\n// call build() before other query (except add_edge)\n\
    // 0-indexed\n// climb(u, d): climb d steps towards root\n// fold(u, v):\nstruct\
    \ DoublingTree {\n    vector<vector<int> > G;\n    vector<vector<int> > parent;\n\
    \    vector<int> depth;\n    int logn;\n\n    DoublingTree(int n) {\n        logn\
    \ = 1;\n        while ((1 << logn) < n) logn++;\n\n        G.resize(n);\n    \
    \    parent.assign(logn, vector<int>(n, -1));\n        depth.assign(n, -1);\n\
    \    };\n\n    template<class Graph>\n    DoublingTree(Graph &g) {\n        DoublingTree(g.size());\n\
    \        for (int i = 0; i < g.size(); i++) {\n            G[i].resize(g[i].size());\n\
    \            for (int j = 0; j < g[i].size(); j++) {\n                G[i][j]\
    \ = g[i][j];\n            }\n        }\n    };\n\n    void calc_depth(int u, int\
    \ d, int par) {\n        depth[u] = d++;\n        parent[0][u] = par;\n      \
    \  for (int v:G[u]) {\n            if (v == par) continue;\n            calc_depth(v,\
    \ d, u);\n        }\n    };\n    \n    void build(vector<int> root = {0}) {\n\
    \        for (int i = 0; i < root.size(); i++) {\n            calc_depth(root[i],\
    \ 0, -1);\n        }\n        for (int k = 1; k < logn; k++) {\n            for\
    \ (int u = 0; u < size(); u++) {\n                if (parent[k - 1][u] == -1)\
    \ continue;\n                parent[k][u] = parent[k - 1][parent[k - 1][u]];\n\
    \            }\n        }\n    };\n    \n    void add_edge(int u, int v) {\n \
    \       G[u].push_back(v);\n        G[v].push_back(u);\n    };\n    int climb(int\
    \ u, int d) {\n        int cnt = 0;\n        while (d) {\n            if (d &\
    \ 1) u = parent[cnt][u];\n            d >>= 1;\n            cnt++;\n        }\n\
    \        return u;\n    };\n    // LowestCommonAncestor\n    int lca(int u, int\
    \ v) {\n        if (depth[u] > depth[v]) swap(u, v);\n        v = climb(v, depth[v]\
    \ - depth[u]);\n\n        if (u == v) return u;\n        for (int k = logn - 1;\
    \ k >= 0; k--) {\n            if (parent[k][u] != parent[k][v]) {\n          \
    \      u = parent[k][u];\n                v = parent[k][v];\n            }\n \
    \       }\n        return parent[0][u];\n    };\n    inline int distance(int u,\
    \ int v) {\n        return depth[u] + depth[v] - depth[lca(u, v)] * 2;\n    };\n\
    \    inline int size() {\n        return G.size();\n    };\n};\n//===\n\n// verify\
    \ lca()\nint AOJ_GRL_5_C() {\n    int n;\n    int k, c;\n    int q;\n    int u,\
    \ v;\n\n    cin >> n;\n    DoublingTree t(n);\n\n    for (int i = 0; i < n; i++)\
    \ {\n        cin >> k;\n        for (int j = 0; j < k; j++) {\n            cin\
    \ >> c;\n            t.add_edge(i, c);\n        }\n    }\n\n    t.build();\n \
    \   cin >> q;\n    for (int i = 0; i < q; i++) {\n        cin >> u >> v;\n   \
    \     cout << t.lca(u, v) << endl;\n    }\n\n    return 0;\n};\n\nint main() {\n\
    \    return AOJ_GRL_5_C();\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/doubling_tree.cpp
  requiredBy: []
  timestamp: '2020-04-13 08:01:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/doubling_tree.cpp
layout: document
redirect_from:
- /library/tree/doubling_tree.cpp
- /library/tree/doubling_tree.cpp.html
title: tree/doubling_tree.cpp
---
