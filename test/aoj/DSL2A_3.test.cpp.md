---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_type/max_monoid.hpp
    title: data_type/max_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/dynamic_segment_tree.hpp
    title: segment_tree/dynamic_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL2A_3.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#line 1 \"segment_tree/dynamic_segment_tree.hpp\"\n//===\ntemplate<class\
    \ Monoid>\nstruct DynamicSegmentTree {\n    using T = typename Monoid::value_type;\n\
    \    using llong = long long;\n\n    struct Node {\n        Node *left, *right;\n\
    \        T v;\n        Node(T v):v(v), left(nullptr), right(nullptr) {};\n   \
    \ };\n\n    Node *root = nullptr;\n    llong L = 0, R = 0;\n\n    DynamicSegmentTree()\
    \ = default;\n\n    inline void eval(Node &u) {\n        T lv = Monoid::identity(),\
    \ rv = Monoid::identity();\n        if (u.left) lv = u.left->v;\n        if (u.right)\
    \ rv = u.right->v;\n        u.v = Monoid::operation(lv, rv);\n    };\n\n    inline\
    \ void expand(llong i) {\n        if (L == R) {\n            R++;\n          \
    \  while (i >= R) R += R - L;\n            while (i < L) L -= R - L;\n       \
    \     root = new Node(Monoid::identity());\n        }\n        else {\n      \
    \      Node *tmp;\n            while (i >= R) {\n                R += R - L;\n\
    \                tmp = new Node(root->v);\n                tmp->left = root;\n\
    \                root = tmp;\n            }\n            while (i < L) {\n   \
    \             L -= R - L;\n                tmp = new Node(root->v);\n        \
    \        tmp->right = root;\n                root = tmp;\n            }\n    \
    \    }\n    };\n\n    inline void update(llong i, T v) {\n        if (i < L ||\
    \ R <= i) expand(i);\n        update(root, L, R, i, v);\n    };\n\n    void update(Node\
    \ *node, llong nl, llong nr, llong k, T v) {\n        if (nr - nl <= 1) {\n  \
    \          node->v = v;\n            return;\n        }\n\n        llong mid =\
    \ (nl + nr) / 2;\n        if (k < mid) {\n            if (!node->left) node->left\
    \ = new Node(Monoid::identity());\n            update(node->left, nl, (nl + nr)\
    \ / 2, k, v);\n        }\n        else {\n            if (!node->right) node->right\
    \ = new Node(Monoid::identity());\n            update(node->right, (nl + nr) /\
    \ 2, nr, k, v);\n        }\n\n        eval(*node);\n        return;\n    }\n\n\
    \    // [l, r)\n    inline T fold(llong l, llong r) {\n        if (l < L) expand(l);\n\
    \        if (r > R) expand(r);\n        return fold(root, L, R, l, r);\n    };\n\
    \    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {\n        if\
    \ (ql <= nl && nr <= qr) return node->v;\n\n        T lv = Monoid::identity(),\
    \ rv = Monoid::identity();\n        llong mid = (nl + nr) / 2;\n        if (node->left\
    \ && ql < mid && nl < qr) {\n            lv = fold(node->left, nl, mid, ql, qr);\n\
    \        }\n        if (node->right && ql < nr && mid < qr) {\n            rv\
    \ = fold(node->right, mid, nr, ql, qr);\n        }\n\n        return Monoid::operation(lv,\
    \ rv);\n    };\n    \n    T operator[] (const llong k) {\n        return fold(k,\
    \ k + 1);\n    };\n};\n//===\n#line 1 \"data_type/max_monoid.hpp\"\n\n\n\n#line\
    \ 6 \"data_type/max_monoid.hpp\"\n\n//===\ntemplate<class T>\nstruct MinMonoid\
    \ {\n    using value_type = T;\n    inline static T identity() {\n        return\
    \ std::numeric_limits<T>::min();\n    };\n    inline static T operation(const\
    \ T a, const T b) {\n        return std::max(a, b);\n    };\n};\n//===\n\n\n#line\
    \ 18 \"test/aoj/DSL2A_3.test.cpp\"\n\nusing namespace std;\nusing llong = long\
    \ long;\n\nllong n, q;\nllong com, x, y;\n\nint main() {\n    cin >> n >> q;\n\
    \n    vector<llong> v(n, -1 * ((1ll << 31) - 1));\n    DynamicSegmentTree<MinMonoid<llong>>\
    \ seg;\n    for (int i = 0; i < n; i++) {\n        seg.update(i, v[i]);\n    }\n\
    \n    for (int i = 0; i < q; i++) {\n        cin >> com >> x >> y;\n\n       \
    \ if (com == 0) {\n            seg.update(x, -y);\n        }\n        else {\n\
    \            cout << -seg.fold(x, y + 1) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n};\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#include \"../../segment_tree/dynamic_segment_tree.hpp\"\n#include\
    \ \"../../data_type/max_monoid.hpp\"\n\nusing namespace std;\nusing llong = long\
    \ long;\n\nllong n, q;\nllong com, x, y;\n\nint main() {\n    cin >> n >> q;\n\
    \n    vector<llong> v(n, -1 * ((1ll << 31) - 1));\n    DynamicSegmentTree<MinMonoid<llong>>\
    \ seg;\n    for (int i = 0; i < n; i++) {\n        seg.update(i, v[i]);\n    }\n\
    \n    for (int i = 0; i < q; i++) {\n        cin >> com >> x >> y;\n\n       \
    \ if (com == 0) {\n            seg.update(x, -y);\n        }\n        else {\n\
    \            cout << -seg.fold(x, y + 1) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n};\n\n"
  dependsOn:
  - segment_tree/dynamic_segment_tree.hpp
  - data_type/max_monoid.hpp
  isVerificationFile: true
  path: test/aoj/DSL2A_3.test.cpp
  requiredBy: []
  timestamp: '2020-07-06 02:53:34+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL2A_3.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2A_3.test.cpp
- /verify/test/aoj/DSL2A_3.test.cpp.html
title: test/aoj/DSL2A_3.test.cpp
---
