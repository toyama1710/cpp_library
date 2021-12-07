---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2270.test.cpp
    title: test/aoj/2270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL5C_doubling.test.cpp
    title: test/aoj/GRL5C_doubling.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca_doubling.test.cpp
    title: test/yosupo/lca_doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/doubling_tree.hpp\"\n\n\n#include <iterator>\n#include\
    \ <optional>\n#include <vector>\n\n// 0-indexed\n// climb(u, d): climb d steps\
    \ towards root\n// fold(u, v):\nstruct DoublingTree {\n    std::vector<std::vector<std::optional<int>>>\
    \ parent;\n    std::vector<int> depth;\n    int logn;\n\n    template <class InputItr>\n\
    \    DoublingTree(InputItr first, InputItr last) {\n        int n = std::distance(first,\
    \ last);\n        std::vector<std::optional<int>> p(n, std::nullopt);\n      \
    \  int i = 0;\n        for (auto itr = first; itr != last; itr++, i++) {\n   \
    \         if (itr->has_value()) p[i] = (int)itr->value();\n        }\n       \
    \ build(p);\n    };\n    void build(const std::vector<std::optional<int>> &p)\
    \ {\n        int n = p.size();\n        logn = 1;\n        while ((1 << logn)\
    \ < n) logn++;\n\n        parent.assign(logn, std::vector<std::optional<int>>(n,\
    \ std::nullopt));\n        for (int i = 0; i < n; i++) parent[0][i] = p[i];\n\
    \        std::vector<std::vector<int>> tree(n);\n        std::vector<int> root;\n\
    \        for (int i = 0; i < n; i++) {\n            if (parent[0][i].has_value())\n\
    \                tree[parent[0][i].value()].push_back(i);\n            else\n\
    \                root.push_back(i);\n        }\n\n        depth.assign(n, -1);\n\
    \        auto calc_depth = [&](int u, int d, auto &&f) -> void {\n           \
    \ depth[u] = d;\n            for (auto v : tree[u]) {\n                f(v, d\
    \ + 1, f);\n            }\n            return;\n        };\n        for (int u\
    \ : root) {\n            calc_depth(u, 0, calc_depth);\n        }\n\n        for\
    \ (int k = 1; k < logn; k++) {\n            for (int u = 0; u < n; u++) {\n  \
    \              if (parent[k - 1][u].has_value())\n                    parent[k][u]\
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
    \    };\n    inline int distance(int u, int v) {\n        return depth[u] + depth[v]\
    \ - depth[lca(u, v)] * 2;\n    };\n};\n\nstruct DoublingTreeBuilder {\n    std::vector<std::vector<int>>\
    \ g;\n    DoublingTreeBuilder(int n) : g(n){};\n    void add_edge(int a, int b)\
    \ {\n        g[a].push_back(b);\n        g[b].push_back(a);\n    };\n    DoublingTree\
    \ build(const std::vector<int> &root = {0}) {\n        std::vector<std::optional<int>>\
    \ parent(g.size(), std::nullopt);\n        auto dfs = [&](int u, int p, auto &&f)\
    \ -> void {\n            for (auto v : g[u]) {\n                if (v == p) continue;\n\
    \                parent[v] = u;\n                f(v, u, f);\n            }\n\
    \            return;\n        };\n        for (auto v : root) dfs(v, -1, dfs);\n\
    \        return DoublingTree(parent.begin(), parent.end());\n    };\n};\n\n\n"
  code: "#ifndef DOUBLING_TREE_HPP\n#define DOUBLING_TREE_HPP\n#include <iterator>\n\
    #include <optional>\n#include <vector>\n\n// 0-indexed\n// climb(u, d): climb\
    \ d steps towards root\n// fold(u, v):\nstruct DoublingTree {\n    std::vector<std::vector<std::optional<int>>>\
    \ parent;\n    std::vector<int> depth;\n    int logn;\n\n    template <class InputItr>\n\
    \    DoublingTree(InputItr first, InputItr last) {\n        int n = std::distance(first,\
    \ last);\n        std::vector<std::optional<int>> p(n, std::nullopt);\n      \
    \  int i = 0;\n        for (auto itr = first; itr != last; itr++, i++) {\n   \
    \         if (itr->has_value()) p[i] = (int)itr->value();\n        }\n       \
    \ build(p);\n    };\n    void build(const std::vector<std::optional<int>> &p)\
    \ {\n        int n = p.size();\n        logn = 1;\n        while ((1 << logn)\
    \ < n) logn++;\n\n        parent.assign(logn, std::vector<std::optional<int>>(n,\
    \ std::nullopt));\n        for (int i = 0; i < n; i++) parent[0][i] = p[i];\n\
    \        std::vector<std::vector<int>> tree(n);\n        std::vector<int> root;\n\
    \        for (int i = 0; i < n; i++) {\n            if (parent[0][i].has_value())\n\
    \                tree[parent[0][i].value()].push_back(i);\n            else\n\
    \                root.push_back(i);\n        }\n\n        depth.assign(n, -1);\n\
    \        auto calc_depth = [&](int u, int d, auto &&f) -> void {\n           \
    \ depth[u] = d;\n            for (auto v : tree[u]) {\n                f(v, d\
    \ + 1, f);\n            }\n            return;\n        };\n        for (int u\
    \ : root) {\n            calc_depth(u, 0, calc_depth);\n        }\n\n        for\
    \ (int k = 1; k < logn; k++) {\n            for (int u = 0; u < n; u++) {\n  \
    \              if (parent[k - 1][u].has_value())\n                    parent[k][u]\
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
    \    };\n    inline int distance(int u, int v) {\n        return depth[u] + depth[v]\
    \ - depth[lca(u, v)] * 2;\n    };\n};\n\nstruct DoublingTreeBuilder {\n    std::vector<std::vector<int>>\
    \ g;\n    DoublingTreeBuilder(int n) : g(n){};\n    void add_edge(int a, int b)\
    \ {\n        g[a].push_back(b);\n        g[b].push_back(a);\n    };\n    DoublingTree\
    \ build(const std::vector<int> &root = {0}) {\n        std::vector<std::optional<int>>\
    \ parent(g.size(), std::nullopt);\n        auto dfs = [&](int u, int p, auto &&f)\
    \ -> void {\n            for (auto v : g[u]) {\n                if (v == p) continue;\n\
    \                parent[v] = u;\n                f(v, u, f);\n            }\n\
    \            return;\n        };\n        for (auto v : root) dfs(v, -1, dfs);\n\
    \        return DoublingTree(parent.begin(), parent.end());\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/doubling_tree.hpp
  requiredBy: []
  timestamp: '2021-09-08 22:35:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca_doubling.test.cpp
  - test/aoj/2270.test.cpp
  - test/aoj/GRL5C_doubling.test.cpp
documentation_of: tree/doubling_tree.hpp
layout: document
redirect_from:
- /library/tree/doubling_tree.hpp
- /library/tree/doubling_tree.hpp.html
title: tree/doubling_tree.hpp
---
