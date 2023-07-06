---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/doubling_tree.hpp
    title: tree/doubling_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL5C_doubling.test.cpp\"\n#define PROBLEM \\\n\
    \    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\n#include\
    \ <iostream>\n#include <vector>\n\n#line 1 \"tree/doubling_tree.hpp\"\n\n\n#include\
    \ <iterator>\n#include <optional>\n#line 6 \"tree/doubling_tree.hpp\"\n\n// 0-indexed\n\
    // climb(u, d): climb d steps towards root\n// fold(u, v):\nstruct DoublingTree\
    \ {\n    std::vector<std::vector<std::optional<int>>> parent;\n    std::vector<int>\
    \ depth;\n    int logn;\n\n    template <class InputItr>\n    DoublingTree(InputItr\
    \ first, InputItr last) {\n        int n = std::distance(first, last);\n     \
    \   std::vector<std::optional<int>> p(n, std::nullopt);\n        int i = 0;\n\
    \        for (auto itr = first; itr != last; itr++, i++) {\n            if (itr->has_value())\
    \ p[i] = (int)itr->value();\n        }\n        build(p);\n    };\n\n    void\
    \ build(const std::vector<std::optional<int>> &p) {\n        int n = p.size();\n\
    \        logn = 1;\n        while ((1 << logn) < n) logn++;\n\n        parent.assign(logn,\
    \ std::vector<std::optional<int>>(n, std::nullopt));\n        for (int i = 0;\
    \ i < n; i++) parent[0][i] = p[i];\n        std::vector<std::vector<int>> tree(n);\n\
    \        std::vector<int> root;\n        for (int i = 0; i < n; i++) {\n     \
    \       if (parent[0][i].has_value())\n                tree[parent[0][i].value()].push_back(i);\n\
    \            else\n                root.push_back(i);\n        }\n\n        depth.assign(n,\
    \ -1);\n        auto calc_depth = [&](int u, int d, auto &&f) -> void {\n    \
    \        depth[u] = d;\n            for (auto v : tree[u]) {\n               \
    \ f(v, d + 1, f);\n            }\n            return;\n        };\n\n        for\
    \ (int u : root) {\n            calc_depth(u, 0, calc_depth);\n        }\n\n \
    \       for (int k = 1; k < logn; k++) {\n            for (int u = 0; u < n; u++)\
    \ {\n                if (parent[k - 1][u].has_value())\n                    parent[k][u]\
    \ = parent[k - 1][parent[k - 1][u].value()];\n            }\n        }\n    };\n\
    \n    std::optional<int> climb(int u, int d) {\n        if (d > depth[u]) return\
    \ std::nullopt;\n        int cnt = 0;\n        while (d > 0) {\n            if\
    \ (d & 1) u = parent[cnt][u].value();\n            d >>= 1;\n            cnt++;\n\
    \        }\n        return u;\n    };\n\n    // LowestCommonAncestor\n    int\
    \ lca(int u, int v) {\n        if (depth[u] > depth[v]) std::swap(u, v);\n   \
    \     v = climb(v, depth[v] - depth[u]).value();\n\n        if (u == v) return\
    \ u;\n        for (int k = logn - 1; k >= 0; k--) {\n            if (parent[k][u]\
    \ != parent[k][v]) {\n                u = parent[k][u].value();\n            \
    \    v = parent[k][v].value();\n            }\n        }\n        return parent[0][u].value();\n\
    \    };\n\n    inline int distance(int u, int v) {\n        return depth[u] +\
    \ depth[v] - depth[lca(u, v)] * 2;\n    };\n};\n\nstruct DoublingTreeBuilder {\n\
    \    std::vector<std::vector<int>> g;\n    DoublingTreeBuilder(int n) : g(n){};\n\
    \    void add_edge(int a, int b) {\n        g[a].push_back(b);\n        g[b].push_back(a);\n\
    \    };\n\n    DoublingTree build(const std::vector<int> &root = {0}) {\n    \
    \    std::vector<std::optional<int>> parent(g.size(), std::nullopt);\n       \
    \ auto dfs = [&](int u, int p, auto &&f) -> void {\n            for (auto v :\
    \ g[u]) {\n                if (v == p) continue;\n                parent[v] =\
    \ u;\n                f(v, u, f);\n            }\n            return;\n      \
    \  };\n        for (auto v : root) dfs(v, -1, dfs);\n        return DoublingTree(parent.begin(),\
    \ parent.end());\n    };\n};\n\n\n#line 7 \"test/aoj/GRL5C_doubling.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    i64 n;\n    cin >> n;\n    DoublingTreeBuilder builder(n);\n    rep(i, n)\
    \ {\n        i64 k, c;\n        cin >> k;\n        rep(j, k) {\n            cin\
    \ >> c;\n            builder.add_edge(i, c);\n        }\n    }\n\n    auto t =\
    \ builder.build({0});\n    i64 q;\n    cin >> q;\n    rep(i, q) {\n        i64\
    \ u, v;\n        cin >> u >> v;\n\n        cout << t.lca(u, v) << '\\n';\n   \
    \ }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include <iostream>\n#include <vector>\n\n#include \"../../tree/doubling_tree.hpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    i64 n;\n    cin >> n;\n    DoublingTreeBuilder builder(n);\n    rep(i, n)\
    \ {\n        i64 k, c;\n        cin >> k;\n        rep(j, k) {\n            cin\
    \ >> c;\n            builder.add_edge(i, c);\n        }\n    }\n\n    auto t =\
    \ builder.build({0});\n    i64 q;\n    cin >> q;\n    rep(i, q) {\n        i64\
    \ u, v;\n        cin >> u >> v;\n\n        cout << t.lca(u, v) << '\\n';\n   \
    \ }\n\n    return 0;\n}"
  dependsOn:
  - tree/doubling_tree.hpp
  isVerificationFile: true
  path: test/aoj/GRL5C_doubling.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 22:12:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL5C_doubling.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL5C_doubling.test.cpp
- /verify/test/aoj/GRL5C_doubling.test.cpp.html
title: test/aoj/GRL5C_doubling.test.cpp
---
