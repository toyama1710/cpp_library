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
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n#include <algorithm>\n#include <functional>\n\
    #include <iostream>\n#include <limits>\n#include <queue>\n#include <vector>\n\
    using namespace std;\ntemplate <class T, class Compare = less<T>>\nusing MaxHeap\
    \ = priority_queue<T, vector<T>, Compare>;\ntemplate <class T, class Compare =\
    \ greater<T>>\nusing MinHeap = priority_queue<T, vector<T>, Compare>;\nusing llong\
    \ = long long;\n\n//===\ntemplate <class T>\nstruct Edge {\n    int src, to;\n\
    \    T cost;\n\n    Edge(int to, T cost) : src(-1), to(to), cost(cost){};\n  \
    \  Edge(int src, int to, T cost) : src(src), to(to), cost(cost){};\n\n    operator\
    \ int() const {\n        return to;\n    };\n};\n\ntemplate <class T>\nusing WeightedGraph\
    \ = vector<vector<Edge<T>>>;\nusing UnWeightedGraph = vector<vector<int>>;\n//===\n\
    \n//===\n// require graph/basic.cpp\n// #include <limits>\n// #include <queue>\n\
    // if s->u path is nothing, min_cost[u] = numeric_limits<T>::max()\n// time:O((V+E)\
    \ log V)\ntemplate <class T>\nvector<T> dijkstra(WeightedGraph<T> &g, int s) {\n\
    \    const T INF = numeric_limits<T>::max();\n    using P = pair<T, int>;\n\n\
    \    vector<T> min_cost(g.size(), INF);\n    // vector<T> restore(g.size(), -1);\n\
    \    priority_queue<P, vector<P>, greater<P>> que;\n    que.emplace(0, s);\n\n\
    \    while (!que.empty()) {\n        T cost = que.top().first;\n        int pos\
    \ = que.top().second;\n        que.pop();\n\n        if (min_cost[pos] != INF)\
    \ continue;\n        min_cost[pos] = cost;\n        for (Edge<T> e : g[pos]) {\n\
    \            if (min_cost[e.to] <= cost + e.cost) continue;\n            que.emplace(cost\
    \ + e.cost, e.to);\n            // restore[npos] = pos;\n        }\n    }\n\n\
    \    return min_cost;\n};\n//===\n\nint AOJ_GRL_1_A() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, m, r;\n    int s, t, d;\n    const llong\
    \ INF = numeric_limits<int>::max();\n\n    cin >> n >> m >> r;\n\n    WeightedGraph<int>\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        cin >> s >> t >> d;\n\n  \
    \      g[s].emplace_back(t, d);\n    }\n\n    vector<int> dist = dijkstra(g, r);\n\
    \    for (int i = 0; i < n; i++) {\n        if (dist[i] == INF)\n            cout\
    \ << \"INF\" << '\\n';\n        else\n            cout << dist[i] << '\\n';\n\
    \    }\n\n    return 0;\n}\n\nint main() {\n    AOJ_GRL_1_A();\n    return 0;\n\
    }\n"
  code: "#include <algorithm>\n#include <functional>\n#include <iostream>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\nusing namespace std;\ntemplate\
    \ <class T, class Compare = less<T>>\nusing MaxHeap = priority_queue<T, vector<T>,\
    \ Compare>;\ntemplate <class T, class Compare = greater<T>>\nusing MinHeap = priority_queue<T,\
    \ vector<T>, Compare>;\nusing llong = long long;\n\n//===\ntemplate <class T>\n\
    struct Edge {\n    int src, to;\n    T cost;\n\n    Edge(int to, T cost) : src(-1),\
    \ to(to), cost(cost){};\n    Edge(int src, int to, T cost) : src(src), to(to),\
    \ cost(cost){};\n\n    operator int() const {\n        return to;\n    };\n};\n\
    \ntemplate <class T>\nusing WeightedGraph = vector<vector<Edge<T>>>;\nusing UnWeightedGraph\
    \ = vector<vector<int>>;\n//===\n\n//===\n// require graph/basic.cpp\n// #include\
    \ <limits>\n// #include <queue>\n// if s->u path is nothing, min_cost[u] = numeric_limits<T>::max()\n\
    // time:O((V+E) log V)\ntemplate <class T>\nvector<T> dijkstra(WeightedGraph<T>\
    \ &g, int s) {\n    const T INF = numeric_limits<T>::max();\n    using P = pair<T,\
    \ int>;\n\n    vector<T> min_cost(g.size(), INF);\n    // vector<T> restore(g.size(),\
    \ -1);\n    priority_queue<P, vector<P>, greater<P>> que;\n    que.emplace(0,\
    \ s);\n\n    while (!que.empty()) {\n        T cost = que.top().first;\n     \
    \   int pos = que.top().second;\n        que.pop();\n\n        if (min_cost[pos]\
    \ != INF) continue;\n        min_cost[pos] = cost;\n        for (Edge<T> e : g[pos])\
    \ {\n            if (min_cost[e.to] <= cost + e.cost) continue;\n            que.emplace(cost\
    \ + e.cost, e.to);\n            // restore[npos] = pos;\n        }\n    }\n\n\
    \    return min_cost;\n};\n//===\n\nint AOJ_GRL_1_A() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int n, m, r;\n    int s, t, d;\n    const llong\
    \ INF = numeric_limits<int>::max();\n\n    cin >> n >> m >> r;\n\n    WeightedGraph<int>\
    \ g(n);\n    for (int i = 0; i < m; i++) {\n        cin >> s >> t >> d;\n\n  \
    \      g[s].emplace_back(t, d);\n    }\n\n    vector<int> dist = dijkstra(g, r);\n\
    \    for (int i = 0; i < n; i++) {\n        if (dist[i] == INF)\n            cout\
    \ << \"INF\" << '\\n';\n        else\n            cout << dist[i] << '\\n';\n\
    \    }\n\n    return 0;\n}\n\nint main() {\n    AOJ_GRL_1_A();\n    return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: graph/dijkstra.cpp
---
