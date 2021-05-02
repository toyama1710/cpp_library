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
  bundledCode: "#line 1 \"tree/euler_tour_vertex.cpp\"\n#include <iostream>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cmath>\n#include <cassert>\n#include\
    \ <functional>\n#include <algorithm>\n#include <string>\n#include <vector>\n#include\
    \ <set>\n#include <map>\n#include <queue>\n#include <stack>\nusing namespace std;\n\
    using llong = long long;\n\n//===\nstruct EulerTour4Vertex {\n    vector<int>\
    \ ls, rs;\n    vector<vector<int> > G;\n\n    EulerTour4Vertex(int n):\n     \
    \   ls(n), rs(n), G(n) {};\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    };\n    void build(int root = 0) {\n        int\
    \ pos = 0;\n        dfs(root, -1, pos);\n    };\n    void dfs(int v, int par,\
    \ int &pos) {\n        ls[v] = pos++;\n        for (int u:G[v]) {\n          \
    \  if (u != par) dfs(u, v, pos);\n        }\n        rs[v] = pos;\n    };\n\n\
    \    int idx(int u) {\n        return ls[u];\n    };\n\n    //fold(subTree(r))\n\
    \    //f folds [l, r)\n    template<class F>\n    void exec(int r, F f) {\n  \
    \      f(ls[r], rs[r]);\n    };\n};\nusing EulerTourForVertex = EulerTour4Vertex;\n\
    //===\n\ntemplate<typename Monoid, typename OP = function<Monoid(Monoid, Monoid)>\
    \ >\nstruct SegmentTree {\n    //    using OP = function<Monoid(Monoid, Monoid)>;\n\
    \    \n    vector<Monoid> tree;\n    int size;\n    const OP merge_monoid; //\
    \ bin' operation\n    const Monoid e; // neutral element\n                   \
    \                        \n    SegmentTree(int nmemb, const Monoid &e, const OP\
    \ &f):\n        size(nmemb), merge_monoid(f), e(e)\n    {\n        tree.assign(size\
    \ << 1, e);\n    }\n\n    template<class InputIterator>\n    SegmentTree(InputIterator\
    \ first, InputIterator last,\n                const Monoid &e, const OP &f):\n\
    \        size(distance(first, last)), merge_monoid(f), e(e)\n    {\n        tree.resize(size\
    \ << 1);\n        int i;\n\n        i = size;\n        for (InputIterator itr\
    \ = first; itr != last; itr++) {\n            tree[i++] = *itr;\n        }\n\n\
    \        for (i = size - 1; i > 0; i--) {\n            tree[i] = merge_monoid(tree[(i\
    \ << 1)], tree[(i << 1) | 1]);\n        }\n    }\n\n    inline void update(int\
    \ k, Monoid dat) {\n        k += size;\n        tree[k] = dat;\n        \n   \
    \     while(k > 1) {\n            k >>= 1;\n            tree[k] = merge_monoid(tree[(k\
    \ << 1)], tree[(k << 1) | 1]);\n        }\n    }\n\n    // [l, r)\n    inline\
    \ Monoid fold(int l, int r) {\n        l += size; //points leaf\n        r +=\
    \ size;\n\n        Monoid lv = e;\n        Monoid rv = e;\n        while (l <\
    \ r) {\n            if (l & 1) lv = merge_monoid(lv, tree[l++]);\n           \
    \ if (r & 1) rv = merge_monoid(tree[--r], rv);\n\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n\n        return merge_monoid(lv, rv);\n    };\n\n\
    \    inline Monoid operator[] (const int k) const {\n        return tree[k + size];\n\
    \    };\n};\n//===\n\nint yosupo_vertex_add_subtree_sum() {\n    return 0;\n};\n\
    \nint main() {\n    return yosupo_vertex_add_subtree_sum();\n};\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <cstdlib>\n#include <cmath>\n\
    #include <cassert>\n#include <functional>\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n#include <set>\n#include <map>\n#include <queue>\n#include\
    \ <stack>\nusing namespace std;\nusing llong = long long;\n\n//===\nstruct EulerTour4Vertex\
    \ {\n    vector<int> ls, rs;\n    vector<vector<int> > G;\n\n    EulerTour4Vertex(int\
    \ n):\n        ls(n), rs(n), G(n) {};\n    void add_edge(int u, int v) {\n   \
    \     G[u].push_back(v);\n        G[v].push_back(u);\n    };\n    void build(int\
    \ root = 0) {\n        int pos = 0;\n        dfs(root, -1, pos);\n    };\n   \
    \ void dfs(int v, int par, int &pos) {\n        ls[v] = pos++;\n        for (int\
    \ u:G[v]) {\n            if (u != par) dfs(u, v, pos);\n        }\n        rs[v]\
    \ = pos;\n    };\n\n    int idx(int u) {\n        return ls[u];\n    };\n\n  \
    \  //fold(subTree(r))\n    //f folds [l, r)\n    template<class F>\n    void exec(int\
    \ r, F f) {\n        f(ls[r], rs[r]);\n    };\n};\nusing EulerTourForVertex =\
    \ EulerTour4Vertex;\n//===\n\ntemplate<typename Monoid, typename OP = function<Monoid(Monoid,\
    \ Monoid)> >\nstruct SegmentTree {\n    //    using OP = function<Monoid(Monoid,\
    \ Monoid)>;\n    \n    vector<Monoid> tree;\n    int size;\n    const OP merge_monoid;\
    \ // bin' operation\n    const Monoid e; // neutral element\n                \
    \                           \n    SegmentTree(int nmemb, const Monoid &e, const\
    \ OP &f):\n        size(nmemb), merge_monoid(f), e(e)\n    {\n        tree.assign(size\
    \ << 1, e);\n    }\n\n    template<class InputIterator>\n    SegmentTree(InputIterator\
    \ first, InputIterator last,\n                const Monoid &e, const OP &f):\n\
    \        size(distance(first, last)), merge_monoid(f), e(e)\n    {\n        tree.resize(size\
    \ << 1);\n        int i;\n\n        i = size;\n        for (InputIterator itr\
    \ = first; itr != last; itr++) {\n            tree[i++] = *itr;\n        }\n\n\
    \        for (i = size - 1; i > 0; i--) {\n            tree[i] = merge_monoid(tree[(i\
    \ << 1)], tree[(i << 1) | 1]);\n        }\n    }\n\n    inline void update(int\
    \ k, Monoid dat) {\n        k += size;\n        tree[k] = dat;\n        \n   \
    \     while(k > 1) {\n            k >>= 1;\n            tree[k] = merge_monoid(tree[(k\
    \ << 1)], tree[(k << 1) | 1]);\n        }\n    }\n\n    // [l, r)\n    inline\
    \ Monoid fold(int l, int r) {\n        l += size; //points leaf\n        r +=\
    \ size;\n\n        Monoid lv = e;\n        Monoid rv = e;\n        while (l <\
    \ r) {\n            if (l & 1) lv = merge_monoid(lv, tree[l++]);\n           \
    \ if (r & 1) rv = merge_monoid(tree[--r], rv);\n\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n\n        return merge_monoid(lv, rv);\n    };\n\n\
    \    inline Monoid operator[] (const int k) const {\n        return tree[k + size];\n\
    \    };\n};\n//===\n\nint yosupo_vertex_add_subtree_sum() {\n    return 0;\n};\n\
    \nint main() {\n    return yosupo_vertex_add_subtree_sum();\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler_tour_vertex.cpp
  requiredBy: []
  timestamp: '2020-04-27 13:16:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/euler_tour_vertex.cpp
layout: document
redirect_from:
- /library/tree/euler_tour_vertex.cpp
- /library/tree/euler_tour_vertex.cpp.html
title: tree/euler_tour_vertex.cpp
---
