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
  bundledCode: "#line 1 \"segment_tree/dynamic_starry_sky.cpp\"\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <functional>\n#include <climits>\n\
    using namespace std;\n\n//===\n// T:monoid, E:operator\ntemplate<class T, class\
    \ E>\nstruct DynamicStarrySky {\n    using llong = long long;\n    using MergeT\
    \ = function<T(T, T)>;\n    using ApplyE = function<T(T, E, llong)>;\n    using\
    \ MergeE = function<E(E, E)>;\n    \n    struct Node {\n        Node *left, *right;\n\
    \        T v;\n        E lazy;\n        Node(T t, E e):v(t), lazy(e), left(nullptr),\
    \ right(nullptr) {}\n    };\n\n    Node *root = nullptr;\n    llong L = 0, R =\
    \ 0;\n\n    const MergeT merge_monoid;\n    const ApplyE apply_lazy;\n    const\
    \ MergeE merge_lazy;\n\n    const T ti;\n    const E ei;\n\n    DynamicStarrySky(const\
    \ T &ti, const E &ei,\n                     const MergeT &f, const ApplyE &g,\
    \ const MergeE &h):\n        ti(ti), ei(ei), merge_monoid(f), apply_lazy(g), merge_lazy(h)\
    \ {};\n\n    inline void eval(Node &u, llong l, llong r) {\n        T lv = ti,\
    \ rv = ti;\n        if (u.left) lv = apply_lazy(u.left->v, u.left->lazy, (r -\
    \ l) / 2);\n        if (u.right) rv = apply_lazy(u.right->v, u.right->lazy, (r\
    \ - l) / 2);\n        u.v = merge_monoid(lv, rv);\n    };\n\n    inline void expand(llong\
    \ i) {\n        if (L == R) {\n            R++;\n            while (i >= R) R\
    \ += R - L;\n            while (i < L) L -= R - L;\n            root = new Node(ti,\
    \ ei);\n        }\n        else {\n            Node *tmp;\n            while (i\
    \ >= R) {\n                tmp = new Node(apply_lazy(root->v, root->lazy, R -\
    \ L), ei);\n                tmp->left = root;\n                R += R - L;\n \
    \               root = tmp;\n            }\n            while (i < L) {\n    \
    \            tmp = new Node(apply_lazy(root->v, root->lazy, R - L), ei);\n   \
    \             tmp->right = root;\n                L -= R - L;\n              \
    \  root = tmp;\n            }\n        }\n    };\n\n    // [l, r)\n    inline\
    \ void update(llong l, llong r, E x) {\n        if (l < L) expand(l);\n      \
    \  if (r > R) expand(r);\n        update(root, L, R, l, r, x);\n    };\n    void\
    \ update(Node *node, llong nl, llong nr, llong ql, llong qr, E x) {\n        if\
    \ (nr <= ql || qr <= nl) return;\n\n        if (ql <= nl && nr <= qr) {\n    \
    \        node->lazy = merge_lazy(node->lazy, x);\n            return;\n      \
    \  }\n\n        if (!node->left) node->left = new Node(ti, ei);\n        if (!node->right)\
    \ node->right = new Node(ti, ei);\n        \n        update(node->left, nl, (nl\
    \ + nr) / 2, ql, qr, x);\n        update(node->right, (nl + nr) / 2, nr, ql, qr,\
    \ x);\n        \n        eval(*node, nl, nr);\n        return;\n    };\n    \n\
    \    // [l, r)\n    inline T fold(llong l, llong r) {\n        if (l < L) expand(l);\n\
    \        if (r > R) expand(r);\n        return fold(root, L, R, l, r);\n    };\n\
    \    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {\n        if\
    \ (nr <= ql || qr <= nl) return ti;\n        if (ql <= nl && nr <= qr) return\
    \ apply_lazy(node->v, node->lazy, nr - nl);\n\n        T lv = ti, rv = ti;\n \
    \       llong mid = (nl + nr) / 2;\n        if (node->left) lv = fold(node->left,\
    \ nl, mid, ql, qr);\n        if (node->right) rv = fold(node->right, mid, nr,\
    \ ql, qr);\n\n        T v;\n        v = merge_monoid(lv, rv);\n        v = apply_lazy(v,\
    \ node->lazy, min(nr, qr) - max(nl, ql));\n\n        return v;\n    };\n    \n\
    \    T operator[] (const llong k) {\n        return fold(k, k + 1);\n    };\n\
    };\n//===\n\nint AOJ_DSL_2G() {\n    using llong = long long;\n    llong n, q;\n\
    \    llong com;\n    llong s, t, x;\n    DynamicStarrySky<llong, llong> RSQ(0,\
    \ 0,\n                                       [](auto l, auto r) { return l + r;\
    \ },\n                                       [](auto l, auto r, llong L) { return\
    \ l + r * L; },\n                                       [](auto l, auto r) { return\
    \ l + r; });\n\n    cin >> n >> q;\n\n    while (q--) {\n        cin >> com;\n\
    \n        if (com == 0) {\n            cin >> s >> t >> x;\n            --s;\n\
    \n            RSQ.update(s, t, x);\n        }\n        else if (com == 1) {\n\
    \            cin >> s >> t;\n            --s;\n            \n            cout\
    \ << RSQ.fold(s, t) << '\\n';\n        }\n\n    }\n\n    return 0;\n}\n\nint AOJ_DSL_2H()\
    \ {\n    using llong = long long;\n    const llong INF = 1ll << 40ll;\n    llong\
    \ n, q;\n    llong com;\n    llong s, t, x;\n    DynamicStarrySky<llong, llong>\
    \ RMQ(INF, 0,\n                                       [](auto l, auto r){ return\
    \ min(l, r); },\n                                       [](auto l, auto r, llong\
    \ len){ return l + r; },\n                                       [](auto l, auto\
    \ r){ return l + r; }\n                                       );\n    cin >> n\
    \ >> q;\n    for (int i = 0; i < n; i++) RMQ.update(i, i + 1, -INF);\n    for\
    \ (int i = 0; i < q; i++) {\n        cin >> com;\n\n        if (com == 0) {\n\
    \            cin >> s >> t >> x;\n            RMQ.update(s, t + 1, x);\n     \
    \   }\n        else {\n            cin >> s >> t;\n            cout << RMQ.fold(s,\
    \ t + 1) << '\\n';\n        }\n    }\n\n    return 0;\n}\n\nint main() {\n   \
    \ return AOJ_DSL_2H();\n    //return AOJ_DSL_2G();\n}\n"
  code: "#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <functional>\n\
    #include <climits>\nusing namespace std;\n\n//===\n// T:monoid, E:operator\ntemplate<class\
    \ T, class E>\nstruct DynamicStarrySky {\n    using llong = long long;\n    using\
    \ MergeT = function<T(T, T)>;\n    using ApplyE = function<T(T, E, llong)>;\n\
    \    using MergeE = function<E(E, E)>;\n    \n    struct Node {\n        Node\
    \ *left, *right;\n        T v;\n        E lazy;\n        Node(T t, E e):v(t),\
    \ lazy(e), left(nullptr), right(nullptr) {}\n    };\n\n    Node *root = nullptr;\n\
    \    llong L = 0, R = 0;\n\n    const MergeT merge_monoid;\n    const ApplyE apply_lazy;\n\
    \    const MergeE merge_lazy;\n\n    const T ti;\n    const E ei;\n\n    DynamicStarrySky(const\
    \ T &ti, const E &ei,\n                     const MergeT &f, const ApplyE &g,\
    \ const MergeE &h):\n        ti(ti), ei(ei), merge_monoid(f), apply_lazy(g), merge_lazy(h)\
    \ {};\n\n    inline void eval(Node &u, llong l, llong r) {\n        T lv = ti,\
    \ rv = ti;\n        if (u.left) lv = apply_lazy(u.left->v, u.left->lazy, (r -\
    \ l) / 2);\n        if (u.right) rv = apply_lazy(u.right->v, u.right->lazy, (r\
    \ - l) / 2);\n        u.v = merge_monoid(lv, rv);\n    };\n\n    inline void expand(llong\
    \ i) {\n        if (L == R) {\n            R++;\n            while (i >= R) R\
    \ += R - L;\n            while (i < L) L -= R - L;\n            root = new Node(ti,\
    \ ei);\n        }\n        else {\n            Node *tmp;\n            while (i\
    \ >= R) {\n                tmp = new Node(apply_lazy(root->v, root->lazy, R -\
    \ L), ei);\n                tmp->left = root;\n                R += R - L;\n \
    \               root = tmp;\n            }\n            while (i < L) {\n    \
    \            tmp = new Node(apply_lazy(root->v, root->lazy, R - L), ei);\n   \
    \             tmp->right = root;\n                L -= R - L;\n              \
    \  root = tmp;\n            }\n        }\n    };\n\n    // [l, r)\n    inline\
    \ void update(llong l, llong r, E x) {\n        if (l < L) expand(l);\n      \
    \  if (r > R) expand(r);\n        update(root, L, R, l, r, x);\n    };\n    void\
    \ update(Node *node, llong nl, llong nr, llong ql, llong qr, E x) {\n        if\
    \ (nr <= ql || qr <= nl) return;\n\n        if (ql <= nl && nr <= qr) {\n    \
    \        node->lazy = merge_lazy(node->lazy, x);\n            return;\n      \
    \  }\n\n        if (!node->left) node->left = new Node(ti, ei);\n        if (!node->right)\
    \ node->right = new Node(ti, ei);\n        \n        update(node->left, nl, (nl\
    \ + nr) / 2, ql, qr, x);\n        update(node->right, (nl + nr) / 2, nr, ql, qr,\
    \ x);\n        \n        eval(*node, nl, nr);\n        return;\n    };\n    \n\
    \    // [l, r)\n    inline T fold(llong l, llong r) {\n        if (l < L) expand(l);\n\
    \        if (r > R) expand(r);\n        return fold(root, L, R, l, r);\n    };\n\
    \    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {\n        if\
    \ (nr <= ql || qr <= nl) return ti;\n        if (ql <= nl && nr <= qr) return\
    \ apply_lazy(node->v, node->lazy, nr - nl);\n\n        T lv = ti, rv = ti;\n \
    \       llong mid = (nl + nr) / 2;\n        if (node->left) lv = fold(node->left,\
    \ nl, mid, ql, qr);\n        if (node->right) rv = fold(node->right, mid, nr,\
    \ ql, qr);\n\n        T v;\n        v = merge_monoid(lv, rv);\n        v = apply_lazy(v,\
    \ node->lazy, min(nr, qr) - max(nl, ql));\n\n        return v;\n    };\n    \n\
    \    T operator[] (const llong k) {\n        return fold(k, k + 1);\n    };\n\
    };\n//===\n\nint AOJ_DSL_2G() {\n    using llong = long long;\n    llong n, q;\n\
    \    llong com;\n    llong s, t, x;\n    DynamicStarrySky<llong, llong> RSQ(0,\
    \ 0,\n                                       [](auto l, auto r) { return l + r;\
    \ },\n                                       [](auto l, auto r, llong L) { return\
    \ l + r * L; },\n                                       [](auto l, auto r) { return\
    \ l + r; });\n\n    cin >> n >> q;\n\n    while (q--) {\n        cin >> com;\n\
    \n        if (com == 0) {\n            cin >> s >> t >> x;\n            --s;\n\
    \n            RSQ.update(s, t, x);\n        }\n        else if (com == 1) {\n\
    \            cin >> s >> t;\n            --s;\n            \n            cout\
    \ << RSQ.fold(s, t) << '\\n';\n        }\n\n    }\n\n    return 0;\n}\n\nint AOJ_DSL_2H()\
    \ {\n    using llong = long long;\n    const llong INF = 1ll << 40ll;\n    llong\
    \ n, q;\n    llong com;\n    llong s, t, x;\n    DynamicStarrySky<llong, llong>\
    \ RMQ(INF, 0,\n                                       [](auto l, auto r){ return\
    \ min(l, r); },\n                                       [](auto l, auto r, llong\
    \ len){ return l + r; },\n                                       [](auto l, auto\
    \ r){ return l + r; }\n                                       );\n    cin >> n\
    \ >> q;\n    for (int i = 0; i < n; i++) RMQ.update(i, i + 1, -INF);\n    for\
    \ (int i = 0; i < q; i++) {\n        cin >> com;\n\n        if (com == 0) {\n\
    \            cin >> s >> t >> x;\n            RMQ.update(s, t + 1, x);\n     \
    \   }\n        else {\n            cin >> s >> t;\n            cout << RMQ.fold(s,\
    \ t + 1) << '\\n';\n        }\n    }\n\n    return 0;\n}\n\nint main() {\n   \
    \ return AOJ_DSL_2H();\n    //return AOJ_DSL_2G();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/dynamic_starry_sky.cpp
  requiredBy: []
  timestamp: '2019-11-03 22:38:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/dynamic_starry_sky.cpp
layout: document
redirect_from:
- /library/segment_tree/dynamic_starry_sky.cpp
- /library/segment_tree/dynamic_starry_sky.cpp.html
title: segment_tree/dynamic_starry_sky.cpp
---
