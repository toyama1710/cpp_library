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
  bundledCode: "#line 1 \"graph/bellman_ford.cpp\"\n#include <functional>\n#include\
    \ <iostream>\n#include <limits>\n#include <queue>\n#include <vector>\nusing namespace\
    \ std;\n\n//===\ntemplate <class T>\nstruct Edge {\n    int src, to;\n    T cost;\n\
    \n    Edge(int to, T cost) : src(-1), to(to), cost(cost){};\n    Edge(int src,\
    \ int to, T cost) : src(src), to(to), cost(cost){};\n\n    operator int() const\
    \ {\n        return to;\n    };\n};\n\ntemplate <class T>\nusing WeightedGraph\
    \ = vector<vector<Edge<T>>>;\nusing UnWeightedGraph = vector<vector<int>>;\n//===\n\
    \n//===\n// require graph/basic.cpp\n// #inlcude <limits>\n\n// when g has negative\
    \ cycle, it returns empty vector<>\n// time: O(|E||V|)\ntemplate <class T>\nvector<T>\
    \ bellman_ford(WeightedGraph<T> &g, int from) {\n    const T INF = numeric_limits<T>::max();\n\
    \    const int V = g.size();\n    vector<T> min_cost(g.size(), INF);\n\n    min_cost[from]\
    \ = 0;\n    for (int k = 0; k < V; k++) {\n        for (int i = 0; i < V; i++)\
    \ {\n            for (auto &e : g[i]) {\n                if (min_cost[i] == INF)\
    \ break;\n                if (min_cost[i] + e.cost < min_cost[e.to]) {\n     \
    \               min_cost[e.to] = min_cost[i] + e.cost;\n                    if\
    \ (k == V - 1) return vector<T>();\n                }\n            }\n       \
    \ }\n    }\n\n    return min_cost;\n};\n\n// when some negative cycles is into\
    \ from->to path has, it returns empty\n// vector<T>\ntemplate <class T>\nvector<T>\
    \ bellman_ford(WeightedGraph<T> &g, int from, int to) {\n    const T INF = numeric_limits<T>::max();\n\
    \    const int V = g.size();\n    vector<T> min_cost(g.size(), INF);\n    vector<bool>\
    \ used(g.size(), 0);\n    vector<bool> reach(g.size(), 0);\n\n    auto dfs = [&](auto\
    \ &&f, int u) -> bool {\n        if (used[u]) return reach[u];\n        used[u]\
    \ = true;\n        for (int v : g[u]) reach[u] = reach[u] | f(f, v);\n       \
    \ return reach[u];\n    };\n\n    reach[to] = true;\n    for (int i = 0; i < V;\
    \ i++) dfs(dfs, i);\n\n    min_cost[from] = 0;\n    for (int k = 0; k < V; k++)\
    \ {\n        for (int i = 0; i < V; i++) {\n            for (auto &e : g[i]) {\n\
    \                if (min_cost[i] == INF) break;\n                if (min_cost[i]\
    \ + e.cost < min_cost[e.to]) {\n                    min_cost[e.to] = min_cost[i]\
    \ + e.cost;\n                    if (k == V - 1 && reach[i]) return vector<T>();\n\
    \                }\n            }\n        }\n    }\n\n    return min_cost;\n\
    };\n//===\n\nint AOJ_GRL_1_B() {\n    int V, E, R;\n    int s, t, d;\n\n    cin\
    \ >> V >> E >> R;\n    WeightedGraph<int> G(V);\n    for (int i = 0; i < E; i++)\
    \ {\n        cin >> s >> t >> d;\n        G[s].emplace_back(t, d);\n    }\n\n\
    \    auto dist = bellman_ford(G, R);\n\n    if (dist.empty()) cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n    for (auto &e : dist) {\n        if (e == numeric_limits<int>::max())\n\
    \            cout << \"INF\" << endl;\n        else\n            cout << e <<\
    \ endl;\n    }\n\n    return 0;\n};\n\nint ABC137_E() {\n    using llong = long\
    \ long;\n\n    llong n, m, p;\n    llong a, b, c;\n    WeightedGraph<llong> G(2505);\n\
    \n    cin >> n >> m >> p;\n    for (int i = 0; i < m; i++) {\n        cin >> a\
    \ >> b >> c;\n        G[a].emplace_back(b, p - c);\n    }\n\n    auto dist = bellman_ford(G,\
    \ 1, n);\n\n    if (dist.empty())\n        cout << -1 << endl;\n    else\n   \
    \     cout << max(0ll, -dist[n]) << endl;\n\n    return 0;\n};\n\nint main() {\n\
    \    return ABC137_E();\n    // return AOJ_GRL_1_B();\n};\n"
  code: "#include <functional>\n#include <iostream>\n#include <limits>\n#include <queue>\n\
    #include <vector>\nusing namespace std;\n\n//===\ntemplate <class T>\nstruct Edge\
    \ {\n    int src, to;\n    T cost;\n\n    Edge(int to, T cost) : src(-1), to(to),\
    \ cost(cost){};\n    Edge(int src, int to, T cost) : src(src), to(to), cost(cost){};\n\
    \n    operator int() const {\n        return to;\n    };\n};\n\ntemplate <class\
    \ T>\nusing WeightedGraph = vector<vector<Edge<T>>>;\nusing UnWeightedGraph =\
    \ vector<vector<int>>;\n//===\n\n//===\n// require graph/basic.cpp\n// #inlcude\
    \ <limits>\n\n// when g has negative cycle, it returns empty vector<>\n// time:\
    \ O(|E||V|)\ntemplate <class T>\nvector<T> bellman_ford(WeightedGraph<T> &g, int\
    \ from) {\n    const T INF = numeric_limits<T>::max();\n    const int V = g.size();\n\
    \    vector<T> min_cost(g.size(), INF);\n\n    min_cost[from] = 0;\n    for (int\
    \ k = 0; k < V; k++) {\n        for (int i = 0; i < V; i++) {\n            for\
    \ (auto &e : g[i]) {\n                if (min_cost[i] == INF) break;\n       \
    \         if (min_cost[i] + e.cost < min_cost[e.to]) {\n                    min_cost[e.to]\
    \ = min_cost[i] + e.cost;\n                    if (k == V - 1) return vector<T>();\n\
    \                }\n            }\n        }\n    }\n\n    return min_cost;\n\
    };\n\n// when some negative cycles is into from->to path has, it returns empty\n\
    // vector<T>\ntemplate <class T>\nvector<T> bellman_ford(WeightedGraph<T> &g,\
    \ int from, int to) {\n    const T INF = numeric_limits<T>::max();\n    const\
    \ int V = g.size();\n    vector<T> min_cost(g.size(), INF);\n    vector<bool>\
    \ used(g.size(), 0);\n    vector<bool> reach(g.size(), 0);\n\n    auto dfs = [&](auto\
    \ &&f, int u) -> bool {\n        if (used[u]) return reach[u];\n        used[u]\
    \ = true;\n        for (int v : g[u]) reach[u] = reach[u] | f(f, v);\n       \
    \ return reach[u];\n    };\n\n    reach[to] = true;\n    for (int i = 0; i < V;\
    \ i++) dfs(dfs, i);\n\n    min_cost[from] = 0;\n    for (int k = 0; k < V; k++)\
    \ {\n        for (int i = 0; i < V; i++) {\n            for (auto &e : g[i]) {\n\
    \                if (min_cost[i] == INF) break;\n                if (min_cost[i]\
    \ + e.cost < min_cost[e.to]) {\n                    min_cost[e.to] = min_cost[i]\
    \ + e.cost;\n                    if (k == V - 1 && reach[i]) return vector<T>();\n\
    \                }\n            }\n        }\n    }\n\n    return min_cost;\n\
    };\n//===\n\nint AOJ_GRL_1_B() {\n    int V, E, R;\n    int s, t, d;\n\n    cin\
    \ >> V >> E >> R;\n    WeightedGraph<int> G(V);\n    for (int i = 0; i < E; i++)\
    \ {\n        cin >> s >> t >> d;\n        G[s].emplace_back(t, d);\n    }\n\n\
    \    auto dist = bellman_ford(G, R);\n\n    if (dist.empty()) cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n    for (auto &e : dist) {\n        if (e == numeric_limits<int>::max())\n\
    \            cout << \"INF\" << endl;\n        else\n            cout << e <<\
    \ endl;\n    }\n\n    return 0;\n};\n\nint ABC137_E() {\n    using llong = long\
    \ long;\n\n    llong n, m, p;\n    llong a, b, c;\n    WeightedGraph<llong> G(2505);\n\
    \n    cin >> n >> m >> p;\n    for (int i = 0; i < m; i++) {\n        cin >> a\
    \ >> b >> c;\n        G[a].emplace_back(b, p - c);\n    }\n\n    auto dist = bellman_ford(G,\
    \ 1, n);\n\n    if (dist.empty())\n        cout << -1 << endl;\n    else\n   \
    \     cout << max(0ll, -dist[n]) << endl;\n\n    return 0;\n};\n\nint main() {\n\
    \    return ABC137_E();\n    // return AOJ_GRL_1_B();\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman_ford.cpp
layout: document
redirect_from:
- /library/graph/bellman_ford.cpp
- /library/graph/bellman_ford.cpp.html
title: graph/bellman_ford.cpp
---
