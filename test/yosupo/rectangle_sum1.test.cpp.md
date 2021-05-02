---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment_tree/persistent_segment_tree.hpp
    title: segment_tree/persistent_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: util/coordinate_compression.hpp
    title: util/coordinate_compression.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/rectangle_sum1.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/rectangle_sum\"\n// header file section\n#include\
    \ <iostream>\n#include <cstdio>\n#include <cfloat>\n#include <vector>\n#include\
    \ <queue>\n#include <stack>\n#include <map>\n#include <set>\n#include <bitset>\n\
    #include <functional>\n#include <numeric>\n#include <algorithm>\n#include <tuple>\n\
    #line 1 \"segment_tree/persistent_segment_tree.hpp\"\n\n\n\n#include <iterator>\n\
    #line 7 \"segment_tree/persistent_segment_tree.hpp\"\n#include <cstdint>\n#include\
    \ <cstddef>\n\n//===\n// LIBRARY SECTION\ntemplate<class Monoid>\nstruct PersistentSegmentTree\
    \ {\n    using uint = size_t;\n    using T = typename Monoid::value_type;\n  \
    \  \n    struct Node {\n        T dat;\n        Node *l = nullptr, *r = nullptr;\n\
    \n        Node (T dat):dat(dat) {};\n    };\n    \n    Node *root;\n    uint n;\n\
    \n    Node *merge_node(Node *lch, Node *rch) {\n        T l = (lch ? lch->dat\
    \ : Monoid::identity());\n        T r = (rch ? rch->dat : Monoid::identity());\n\
    \        Node *ret = new Node(Monoid::operation(l, r));\n        ret->l = lch;\n\
    \        ret->r = rch;\n\n        return ret;\n    };\n\n    PersistentSegmentTree(const\
    \ PersistentSegmentTree &) = default;\n    PersistentSegmentTree &operator = (const\
    \ PersistentSegmentTree &) = default;\n    PersistentSegmentTree(uint n, Node\
    \ *r):n(n), root(r) {};\n    PersistentSegmentTree(uint n)\n        :n(n), root(alloc(0,\
    \ n, std::vector<T>(n, Monoid::identity()))) {};\n    template<class InputItr>\n\
    \    PersistentSegmentTree(const InputItr first, const InputItr last)\n      \
    \  :n(std::distance(first, last)), root(alloc(0, n, std::vector<T>(first, last)))\
    \ {};\n\n    Node *alloc(uint nl, uint nr, const std::vector<T> &v) {\n      \
    \  if (nr - nl <= 1) return new Node(v[nl]);\n        else return merge_node(alloc(nl,\
    \ (nl + nr) / 2, v),\n                alloc((nl + nr) / 2, nr, v));\n    };\n\n\
    \    const T fold(uint l, uint r) const {\n        return fold(l, r, 0, n, root);\n\
    \    };\n    const T fold(uint ql, uint qr, uint nl, uint nr, const Node *np)\
    \ const {\n        if (np == nullptr || qr <= nl || nr <= ql) return Monoid::identity();\n\
    \        else if (ql <= nl && nr <= qr) return np->dat;\n        else return Monoid::operation(fold(ql,\
    \ qr, nl, (nl + nr) / 2, np->l), fold(ql, qr, (nl + nr) / 2, nr, np->r));\n  \
    \  };\n\n    PersistentSegmentTree update(uint idx, T d) {\n        return set(idx,\
    \ d);\n    };\n    PersistentSegmentTree set(uint idx, T d) {\n        return\
    \ PersistentSegmentTree(n, update(0, n, idx, d, root));\n    };\n    Node *update(uint\
    \ nl, uint nr, uint idx, T d, Node *np) {\n        if (idx < nl || nr <= idx)\
    \ return np;\n        else if (nr - nl == 1) return new Node(d);\n        else\
    \ return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l), update((nl + nr)\
    \ / 2, nr, idx, d, np->r));\n    };\n\n    PersistentSegmentTree get_tree() {\n\
    \        return *this;\n    };\n\n    T operator [] (uint idx) {\n        return\
    \ fold(idx, idx + 1, 0, n, root);\n    };\n\n};\n//===\n\n\n#line 1 \"util/coordinate_compression.hpp\"\
    \n\n\n// header file section\n#line 7 \"util/coordinate_compression.hpp\"\n#include\
    \ <cassert>\n\n//===\n// library section\n// <iterator>\nstruct CoordinateCompression\
    \ {\n    using llong = long long;\n    std::vector<llong> p;\n\n#ifndef NDEBUG\n\
    \    bool builded = false;\n#endif\n\n    CoordinateCompression () {};\n    template\
    \ <class InputItr>\n    CoordinateCompression (InputItr first, InputItr last)\
    \ {\n        p.reserve(std::distance(first, last));\n        for (auto itr = first;\
    \ itr != last; itr++) {\n            p.push_back(*itr);\n        }\n        build();\n\
    \    };\n\n    void build() {\n        std::sort(p.begin(), p.end());\n      \
    \  p.erase(unique(p.begin(), p.end()), p.end());\n#ifndef NDEBUG\n        builded\
    \ = true;\n#endif\n    };\n\n    void add(llong a) {\n        p.push_back(a);\n\
    #ifndef NDEBUG\n        builded = false;\n#endif\n    };\n    void push(llong\
    \ a) {\n        add(a);\n    }\n\n    llong zip(llong x) {\n#ifndef NDEBUG\n \
    \       assert(builded);\n#endif\n        return std::lower_bound(p.begin(), p.end(),\
    \ x) - p.begin();\n    };\n    llong unzip(llong x) {\n#ifndef NDEBUG\n      \
    \  assert(builded);\n#endif\n        return p[x];\n    };\n\n    llong size()\
    \ {\n        return p.size();\n    };\n};\n//===\n\n#line 18 \"test/yosupo/rectangle_sum1.test.cpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nstruct Monoid {\n    using\
    \ value_type = llong;\n    static llong operation(llong a, llong b) {\n      \
    \  return a + b;\n    };\n    static llong identity() {\n        return 0;\n \
    \   }\n};\n\nllong n, q;\nvector<PersistentSegmentTree<Monoid>> v;\nvector<tuple<llong,\
    \ llong, llong>> p;\nCoordinateCompression x_axis;\nCoordinateCompression y_axis;\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cin\
    \ >> n >> q;\n\n    for (int i = 0; i < n; i++) {\n        llong x, y, w;\n  \
    \      cin >> x >> y >> w;\n        p.push_back(tie(y, x, w));\n        x_axis.add(x);\n\
    \        y_axis.add(y);\n    }\n\n    sort(p.begin(), p.end());\n    x_axis.build();\n\
    \    y_axis.build();\n\n    v.push_back(PersistentSegmentTree<Monoid>(x_axis.size()));\n\
    \n    for (int i = 0; i < p.size(); i++) {\n        llong x, y, w;\n        tie(y,\
    \ x, w) = p[i];\n        x = x_axis.zip(x);\n        y = y_axis.zip(y);\n\n  \
    \      if (v.size() <= y) {\n            v.push_back(v[y - 1]);\n        }\n\n\
    \        v[y] = v[y].update(x, v[y][x] + w);\n    }\n\n    for (int i = 0; i <\
    \ q; i++) {\n        llong l, d, r, u;\n        cin >> l >> d >> r >> u;\n\n \
    \       l = x_axis.zip(l);\n        r = x_axis.zip(r);\n        d = y_axis.zip(d)\
    \ - 1;\n        u = y_axis.zip(u) - 1;\n\n        if (d >= 0) \n            cout\
    \ << v[u].fold(l, r) - v[d].fold(l, r) << '\\n';\n        else if (u >= 0)\n \
    \           cout << v[u].fold(l, r) << '\\n';\n        else\n            cout\
    \ << 0 << '\\n';\n    }\n\n    return 0;\n};\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n// header\
    \ file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n#include\
    \ <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include <set>\n\
    #include <bitset>\n#include <functional>\n#include <numeric>\n#include <algorithm>\n\
    #include <tuple>\n#include \"../../segment_tree/persistent_segment_tree.hpp\"\n\
    #include \"../../util/coordinate_compression.hpp\"\n\nusing namespace std;\nusing\
    \ llong = long long;\n\nstruct Monoid {\n    using value_type = llong;\n    static\
    \ llong operation(llong a, llong b) {\n        return a + b;\n    };\n    static\
    \ llong identity() {\n        return 0;\n    }\n};\n\nllong n, q;\nvector<PersistentSegmentTree<Monoid>>\
    \ v;\nvector<tuple<llong, llong, llong>> p;\nCoordinateCompression x_axis;\nCoordinateCompression\
    \ y_axis;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cin >> n >> q;\n\n    for (int i = 0; i < n; i++) {\n        llong x, y,\
    \ w;\n        cin >> x >> y >> w;\n        p.push_back(tie(y, x, w));\n      \
    \  x_axis.add(x);\n        y_axis.add(y);\n    }\n\n    sort(p.begin(), p.end());\n\
    \    x_axis.build();\n    y_axis.build();\n\n    v.push_back(PersistentSegmentTree<Monoid>(x_axis.size()));\n\
    \n    for (int i = 0; i < p.size(); i++) {\n        llong x, y, w;\n        tie(y,\
    \ x, w) = p[i];\n        x = x_axis.zip(x);\n        y = y_axis.zip(y);\n\n  \
    \      if (v.size() <= y) {\n            v.push_back(v[y - 1]);\n        }\n\n\
    \        v[y] = v[y].update(x, v[y][x] + w);\n    }\n\n    for (int i = 0; i <\
    \ q; i++) {\n        llong l, d, r, u;\n        cin >> l >> d >> r >> u;\n\n \
    \       l = x_axis.zip(l);\n        r = x_axis.zip(r);\n        d = y_axis.zip(d)\
    \ - 1;\n        u = y_axis.zip(u) - 1;\n\n        if (d >= 0) \n            cout\
    \ << v[u].fold(l, r) - v[d].fold(l, r) << '\\n';\n        else if (u >= 0)\n \
    \           cout << v[u].fold(l, r) << '\\n';\n        else\n            cout\
    \ << 0 << '\\n';\n    }\n\n    return 0;\n};\n\n"
  dependsOn:
  - segment_tree/persistent_segment_tree.hpp
  - util/coordinate_compression.hpp
  isVerificationFile: true
  path: test/yosupo/rectangle_sum1.test.cpp
  requiredBy: []
  timestamp: '2020-07-09 16:11:51+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rectangle_sum1.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rectangle_sum1.test.cpp
- /verify/test/yosupo/rectangle_sum1.test.cpp.html
title: test/yosupo/rectangle_sum1.test.cpp
---
