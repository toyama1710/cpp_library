---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/heavy_light_decomposition.hpp\"\n#include <iostream>\n\
    #include <cstdio>\n#include <cstdlib>\n#include <cmath>\n#include <cassert>\n\
    #include <functional>\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    #include <set>\n#include <map>\n#include <queue>\n#include <stack>\nusing namespace\
    \ std;\ntemplate<class T, class Compare = less<T> >\nusing MaxHeap = priority_queue<T,\
    \ vector<T>, Compare>;\ntemplate<class T, class Compare = greater<T> >\nusing\
    \ MinHeap = priority_queue<T, vector<T>, Compare>;\nusing llong = long long;\n\
    \n//===\nstruct HeavyLightDecomposition {\nprivate:\n    vector<vector<int> >\
    \ G; // UnWeightedGraph\n    vector<int> head; // root of heavy-edge\n    vector<int>\
    \ par;\n    vector<int> sz;\n\n    void convert_rooted_tree(int v) {\n       \
    \ int sz[v] = 1;\n        for (int u:G[v]) {\n            if (par[v] == u) continue;\n\
    \            par[u] = v;\n            convert_rooted_tree(u);\n            sz[v]\
    \ += sz[u];\n        }\n    };\n\npublic:\n    HeavyLightDecomposition(int n):\n\
    \        G(n)\n    {};\n    \n    void build(vector<int> rs = {0}) {\n       \
    \ for (int r:rs) {\n            convert_rooted_tree(r);\n            head[r] =\
    \ r;\n            dfs(r);\n        }\n    };\n    \n    void add_edge(int u, int\
    \ v) {\n        G[u].push_back(v);\n        G[v].push_back(u);\n    };\n    int\
    \ lca(int u, int v) {\n    };\n    int distance(int u, int v) {\n    };\n\n  \
    \  //return range on EulerTour\n    vector<pair<int, int> > get_ranges(int u,\
    \ int v) { //vertex\n    };\n};\n//===\n\nint main() {\n\n    return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <cstdlib>\n#include <cmath>\n\
    #include <cassert>\n#include <functional>\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n#include <set>\n#include <map>\n#include <queue>\n#include\
    \ <stack>\nusing namespace std;\ntemplate<class T, class Compare = less<T> >\n\
    using MaxHeap = priority_queue<T, vector<T>, Compare>;\ntemplate<class T, class\
    \ Compare = greater<T> >\nusing MinHeap = priority_queue<T, vector<T>, Compare>;\n\
    using llong = long long;\n\n//===\nstruct HeavyLightDecomposition {\nprivate:\n\
    \    vector<vector<int> > G; // UnWeightedGraph\n    vector<int> head; // root\
    \ of heavy-edge\n    vector<int> par;\n    vector<int> sz;\n\n    void convert_rooted_tree(int\
    \ v) {\n        int sz[v] = 1;\n        for (int u:G[v]) {\n            if (par[v]\
    \ == u) continue;\n            par[u] = v;\n            convert_rooted_tree(u);\n\
    \            sz[v] += sz[u];\n        }\n    };\n\npublic:\n    HeavyLightDecomposition(int\
    \ n):\n        G(n)\n    {};\n    \n    void build(vector<int> rs = {0}) {\n \
    \       for (int r:rs) {\n            convert_rooted_tree(r);\n            head[r]\
    \ = r;\n            dfs(r);\n        }\n    };\n    \n    void add_edge(int u,\
    \ int v) {\n        G[u].push_back(v);\n        G[v].push_back(u);\n    };\n \
    \   int lca(int u, int v) {\n    };\n    int distance(int u, int v) {\n    };\n\
    \n    //return range on EulerTour\n    vector<pair<int, int> > get_ranges(int\
    \ u, int v) { //vertex\n    };\n};\n//===\n\nint main() {\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2020-05-07 13:13:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy_light_decomposition.hpp
- /library/tree/heavy_light_decomposition.hpp.html
title: tree/heavy_light_decomposition.hpp
---
