---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/basic.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\nusing llong = long long;\n\n//===\ntemplate<class\
    \ T>\nstruct Edge {\n    int src, to;\n    T cost;\n\n    Edge (int to, T cost):\n\
    \        src(-1), to(to), cost(cost) {};\n    Edge (int src, int to, T cost):\n\
    \        src(src), to(to), cost(cost) {};\n\n    operator int() const {\n    \
    \    return to;\n    };\n};\n\ntemplate <class T>\nusing WeightedGraph = vector<vector<Edge<T>>>;\n\
    using UnWeightedGraph = vector<vector<int> >;\n//===\n\nint main() {\n\n    return\
    \ 0;\n}\n"
  code: "#include <iostream>\n#include <algorithm>\n#include <vector>\nusing namespace\
    \ std;\nusing llong = long long;\n\n//===\ntemplate<class T>\nstruct Edge {\n\
    \    int src, to;\n    T cost;\n\n    Edge (int to, T cost):\n        src(-1),\
    \ to(to), cost(cost) {};\n    Edge (int src, int to, T cost):\n        src(src),\
    \ to(to), cost(cost) {};\n\n    operator int() const {\n        return to;\n \
    \   };\n};\n\ntemplate <class T>\nusing WeightedGraph = vector<vector<Edge<T>>>;\n\
    using UnWeightedGraph = vector<vector<int> >;\n//===\n\nint main() {\n\n    return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/basic.cpp
  requiredBy: []
  timestamp: '2020-01-03 13:26:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/basic.cpp
layout: document
redirect_from:
- /library/graph/basic.cpp
- /library/graph/basic.cpp.html
title: graph/basic.cpp
---
