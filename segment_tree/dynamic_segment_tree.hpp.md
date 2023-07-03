---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1418_2.test.cpp
    title: test/aoj/1418_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2A_3.test.cpp
    title: test/aoj/DSL2A_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/dynamic_segment_tree.hpp\"\n\n\n\ntemplate\
    \ <class Monoid>\nstruct DynamicSegmentTree {\n    using T = typename Monoid::value_type;\n\
    \    using llong = long long;\n\n    struct Node {\n        T v;\n        Node\
    \ *left, *right;\n        Node(T v) : v(v), left(nullptr), right(nullptr){};\n\
    \    };\n\n    Node *root = nullptr;\n    llong L = 0, R = 0;\n\n    DynamicSegmentTree()\
    \ = default;\n\n    inline void eval(Node &u) {\n        T lv = Monoid::identity(),\
    \ rv = Monoid::identity();\n        if (u.left) lv = u.left->v;\n        if (u.right)\
    \ rv = u.right->v;\n        u.v = Monoid::operation(lv, rv);\n    };\n\n    inline\
    \ void expand(llong i) {\n        if (L == R) {\n            R++;\n          \
    \  while (i >= R) R += R - L;\n            while (i < L) L -= R - L;\n       \
    \     root = new Node(Monoid::identity());\n        } else {\n            Node\
    \ *tmp;\n\n            while (i >= R) {\n                R += R - L;\n       \
    \         tmp = new Node(root->v);\n                tmp->left = root;\n      \
    \          root = tmp;\n            }\n\n            while (i < L) {\n       \
    \         L -= R - L;\n                tmp = new Node(root->v);\n            \
    \    tmp->right = root;\n                root = tmp;\n            }\n        }\n\
    \    };\n\n    inline void update(llong i, T v) {\n        if (i < L || R <= i)\
    \ expand(i);\n        update(root, L, R, i, v);\n    };\n\n    void update(Node\
    \ *node, llong nl, llong nr, llong k, T v) {\n        if (nr - nl <= 1) {\n  \
    \          node->v = v;\n            return;\n        }\n\n        llong mid =\
    \ (nl + nr) / 2;\n        if (k < mid) {\n            if (!node->left) node->left\
    \ = new Node(Monoid::identity());\n\n            update(node->left, nl, (nl +\
    \ nr) / 2, k, v);\n        } else {\n            if (!node->right) node->right\
    \ = new Node(Monoid::identity());\n\n            update(node->right, (nl + nr)\
    \ / 2, nr, k, v);\n        }\n\n        eval(*node);\n        return;\n    }\n\
    \n    // [l, r)\n    inline T fold(llong l, llong r) {\n        if (l < L) expand(l);\n\
    \        if (r > R) expand(r);\n        return fold(root, L, R, l, r);\n    };\n\
    \n    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {\n        if\
    \ (ql <= nl && nr <= qr) return node->v;\n\n        T lv = Monoid::identity(),\
    \ rv = Monoid::identity();\n        llong mid = (nl + nr) / 2;\n\n        if (node->left\
    \ && ql < mid && nl < qr)\n            lv = fold(node->left, nl, mid, ql, qr);\n\
    \n        if (node->right && ql < nr && mid < qr)\n            rv = fold(node->right,\
    \ mid, nr, ql, qr);\n\n        return Monoid::operation(lv, rv);\n    };\n\n \
    \   T operator[](const llong k) {\n        return fold(k, k + 1);\n    };\n};\n\
    \n\n"
  code: "#ifndef DYNAMIC_SEGMENT_TREE_HPP\n#define DYNAMIC_SEGMENT_TREE_HPP\n\ntemplate\
    \ <class Monoid>\nstruct DynamicSegmentTree {\n    using T = typename Monoid::value_type;\n\
    \    using llong = long long;\n\n    struct Node {\n        T v;\n        Node\
    \ *left, *right;\n        Node(T v) : v(v), left(nullptr), right(nullptr){};\n\
    \    };\n\n    Node *root = nullptr;\n    llong L = 0, R = 0;\n\n    DynamicSegmentTree()\
    \ = default;\n\n    inline void eval(Node &u) {\n        T lv = Monoid::identity(),\
    \ rv = Monoid::identity();\n        if (u.left) lv = u.left->v;\n        if (u.right)\
    \ rv = u.right->v;\n        u.v = Monoid::operation(lv, rv);\n    };\n\n    inline\
    \ void expand(llong i) {\n        if (L == R) {\n            R++;\n          \
    \  while (i >= R) R += R - L;\n            while (i < L) L -= R - L;\n       \
    \     root = new Node(Monoid::identity());\n        } else {\n            Node\
    \ *tmp;\n\n            while (i >= R) {\n                R += R - L;\n       \
    \         tmp = new Node(root->v);\n                tmp->left = root;\n      \
    \          root = tmp;\n            }\n\n            while (i < L) {\n       \
    \         L -= R - L;\n                tmp = new Node(root->v);\n            \
    \    tmp->right = root;\n                root = tmp;\n            }\n        }\n\
    \    };\n\n    inline void update(llong i, T v) {\n        if (i < L || R <= i)\
    \ expand(i);\n        update(root, L, R, i, v);\n    };\n\n    void update(Node\
    \ *node, llong nl, llong nr, llong k, T v) {\n        if (nr - nl <= 1) {\n  \
    \          node->v = v;\n            return;\n        }\n\n        llong mid =\
    \ (nl + nr) / 2;\n        if (k < mid) {\n            if (!node->left) node->left\
    \ = new Node(Monoid::identity());\n\n            update(node->left, nl, (nl +\
    \ nr) / 2, k, v);\n        } else {\n            if (!node->right) node->right\
    \ = new Node(Monoid::identity());\n\n            update(node->right, (nl + nr)\
    \ / 2, nr, k, v);\n        }\n\n        eval(*node);\n        return;\n    }\n\
    \n    // [l, r)\n    inline T fold(llong l, llong r) {\n        if (l < L) expand(l);\n\
    \        if (r > R) expand(r);\n        return fold(root, L, R, l, r);\n    };\n\
    \n    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {\n        if\
    \ (ql <= nl && nr <= qr) return node->v;\n\n        T lv = Monoid::identity(),\
    \ rv = Monoid::identity();\n        llong mid = (nl + nr) / 2;\n\n        if (node->left\
    \ && ql < mid && nl < qr)\n            lv = fold(node->left, nl, mid, ql, qr);\n\
    \n        if (node->right && ql < nr && mid < qr)\n            rv = fold(node->right,\
    \ mid, nr, ql, qr);\n\n        return Monoid::operation(lv, rv);\n    };\n\n \
    \   T operator[](const llong k) {\n        return fold(k, k + 1);\n    };\n};\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/dynamic_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-07-03 22:10:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2A_3.test.cpp
  - test/aoj/1418_2.test.cpp
documentation_of: segment_tree/dynamic_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/dynamic_segment_tree.hpp
- /library/segment_tree/dynamic_segment_tree.hpp.html
title: segment_tree/dynamic_segment_tree.hpp
---
