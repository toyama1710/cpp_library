---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL2F_2.test.cpp
    title: test/aoj/DSL2F_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/persistent_lazy_segment_tree.hpp\"\n\n\n\n\
    #include <iostream>\ntemplate <class MonoidwithOperator>\nstruct PersistentLazySegmentTree\
    \ {\n    using A = MonoidwithOperator;\n    using M = typename A::value_structure;\n\
    \    using O = typename A::operator_structure;\n    using T = typename M::value_type;\n\
    \    using E = typename O::value_type;\n\n    struct Node {\n        T v;\n  \
    \      E op;\n        Node *left, *right;\n        Node()\n            : v(M::identity()),\n\
    \              op(O::identity()),\n              left(nullptr),\n            \
    \  right(nullptr){};\n        Node(T v, E op, Node *left = nullptr, Node *right\
    \ = nullptr)\n            : v(v), op(op), left(left), right(right){};\n      \
    \  Node(const Node &) = default;\n    };\n\n    Node *root;\n    int sz;\n\n \
    \   PersistentLazySegmentTree() = default;\n    PersistentLazySegmentTree(const\
    \ PersistentLazySegmentTree &) = default;\n    explicit PersistentLazySegmentTree(int\
    \ n)\n        : root(alloc(0, n, M::identity())), sz(n){};\n    PersistentLazySegmentTree(int\
    \ n, T init_v)\n        : root(alloc(0, n, init_v)), sz(n){};\n    PersistentLazySegmentTree(Node\
    \ *u, int sz) : root(u), sz(sz){};\n    PersistentLazySegmentTree &operator=(const\
    \ PersistentLazySegmentTree &) =\n        default;\n\n    Node *alloc(int nl,\
    \ int nr, T init_v) {\n        if (nr - nl <= 1) return new Node(init_v, O::identity());\n\
    \        Node *ret = new Node();\n        ret->left = alloc(nl, (nl + nr) / 2,\
    \ init_v);\n        ret->right = alloc((nl + nr) / 2, nr, init_v);\n        ret->v\
    \ = M::operation(ret->left->v, ret->right->v);\n        return ret;\n    };\n\n\
    \    void push_down(Node *u) {\n        if (u->op == O::identity()) return;\n\
    \        u->v = A::operation(u->v, u->op);\n\n        if (u->left != nullptr)\
    \ {\n            u->left = new Node(*u->left);\n            u->left->op = O::operation(u->left->op,\
    \ u->op);\n        }\n        if (u->right != nullptr) {\n            u->right\
    \ = new Node(*u->right);\n            u->right->op = O::operation(u->right->op,\
    \ u->op);\n        }\n\n        u->op = O::identity();\n    };\n\n    T fold(int\
    \ l, int r) {\n        if (r <= l) return M::identity();\n        return fold(root,\
    \ O::identity(), 0, sz, l, r);\n    };\n    T fold(Node *u, E op, int nl, int\
    \ nr, int ql, int qr) {\n        op = O::operation(u->op, op);\n        if (ql\
    \ <= nl && nr <= qr) return A::operation(u->v, op);\n\n        int mid = (nl +\
    \ nr) / 2;\n        if (qr <= mid) {\n            return fold(u->left, op, nl,\
    \ mid, ql, qr);\n        } else if (mid <= ql) {\n            return fold(u->right,\
    \ op, mid, nr, ql, qr);\n        } else {\n            return M::operation(fold(u->left,\
    \ op, nl, mid, ql, qr),\n                                fold(u->right, op, mid,\
    \ nr, ql, qr));\n        }\n    };\n\n    PersistentLazySegmentTree update(int\
    \ l, int r, E op) {\n        if (r <= l) return PersistentLazySegmentTree(*this);\n\
    \        return PersistentLazySegmentTree(update(root, op, 0, sz, l, r), sz);\n\
    \    };\n    Node *update(Node *u, E op, int nl, int nr, int ql, int qr) {\n \
    \       Node *ret = new Node(*u);\n        if (ql <= nl && nr <= qr) {\n     \
    \       ret->op = O::operation(ret->op, op);\n            return ret;\n      \
    \  }\n\n        push_down(ret);\n        int mid = (nl + nr) / 2;\n        if\
    \ (qr <= mid) {\n            ret->left = update(ret->left, op, nl, mid, ql, qr);\n\
    \        } else if (mid <= ql) {\n            ret->right = update(ret->right,\
    \ op, mid, nr, ql, qr);\n        } else {\n            ret->left = update(ret->left,\
    \ op, nl, mid, ql, qr);\n            ret->right = update(ret->right, op, mid,\
    \ nr, ql, qr);\n        }\n        ret->v = M::operation(A::operation(ret->left->v,\
    \ ret->left->op),\n                              A::operation(ret->right->v, ret->right->op));\n\
    \        return ret;\n    };\n\n    void dump() {\n        dump(root, 0);\n  \
    \  };\n    void dump(Node *u, int d) {\n        if (u == nullptr) return;\n  \
    \      dump(u->right, d + 1);\n        for (int i = 0; i < d; i++) std::cout <<\
    \ \"\\t\\t\";\n        std::cout << \"(\" << u->v << \", \" << u->op << \")\"\
    \ << std::endl;\n        dump(u->left, d + 1);\n    };\n};\n\n\n"
  code: "#ifndef PERSISTENT_LAZY_SEGMENT_TREE_HPP\n#define PERSISTENT_LAZY_SEGMENT_TREE_HPP\n\
    \n#include <iostream>\ntemplate <class MonoidwithOperator>\nstruct PersistentLazySegmentTree\
    \ {\n    using A = MonoidwithOperator;\n    using M = typename A::value_structure;\n\
    \    using O = typename A::operator_structure;\n    using T = typename M::value_type;\n\
    \    using E = typename O::value_type;\n\n    struct Node {\n        T v;\n  \
    \      E op;\n        Node *left, *right;\n        Node()\n            : v(M::identity()),\n\
    \              op(O::identity()),\n              left(nullptr),\n            \
    \  right(nullptr){};\n        Node(T v, E op, Node *left = nullptr, Node *right\
    \ = nullptr)\n            : v(v), op(op), left(left), right(right){};\n      \
    \  Node(const Node &) = default;\n    };\n\n    Node *root;\n    int sz;\n\n \
    \   PersistentLazySegmentTree() = default;\n    PersistentLazySegmentTree(const\
    \ PersistentLazySegmentTree &) = default;\n    explicit PersistentLazySegmentTree(int\
    \ n)\n        : root(alloc(0, n, M::identity())), sz(n){};\n    PersistentLazySegmentTree(int\
    \ n, T init_v)\n        : root(alloc(0, n, init_v)), sz(n){};\n    PersistentLazySegmentTree(Node\
    \ *u, int sz) : root(u), sz(sz){};\n    PersistentLazySegmentTree &operator=(const\
    \ PersistentLazySegmentTree &) =\n        default;\n\n    Node *alloc(int nl,\
    \ int nr, T init_v) {\n        if (nr - nl <= 1) return new Node(init_v, O::identity());\n\
    \        Node *ret = new Node();\n        ret->left = alloc(nl, (nl + nr) / 2,\
    \ init_v);\n        ret->right = alloc((nl + nr) / 2, nr, init_v);\n        ret->v\
    \ = M::operation(ret->left->v, ret->right->v);\n        return ret;\n    };\n\n\
    \    void push_down(Node *u) {\n        if (u->op == O::identity()) return;\n\
    \        u->v = A::operation(u->v, u->op);\n\n        if (u->left != nullptr)\
    \ {\n            u->left = new Node(*u->left);\n            u->left->op = O::operation(u->left->op,\
    \ u->op);\n        }\n        if (u->right != nullptr) {\n            u->right\
    \ = new Node(*u->right);\n            u->right->op = O::operation(u->right->op,\
    \ u->op);\n        }\n\n        u->op = O::identity();\n    };\n\n    T fold(int\
    \ l, int r) {\n        if (r <= l) return M::identity();\n        return fold(root,\
    \ O::identity(), 0, sz, l, r);\n    };\n    T fold(Node *u, E op, int nl, int\
    \ nr, int ql, int qr) {\n        op = O::operation(u->op, op);\n        if (ql\
    \ <= nl && nr <= qr) return A::operation(u->v, op);\n\n        int mid = (nl +\
    \ nr) / 2;\n        if (qr <= mid) {\n            return fold(u->left, op, nl,\
    \ mid, ql, qr);\n        } else if (mid <= ql) {\n            return fold(u->right,\
    \ op, mid, nr, ql, qr);\n        } else {\n            return M::operation(fold(u->left,\
    \ op, nl, mid, ql, qr),\n                                fold(u->right, op, mid,\
    \ nr, ql, qr));\n        }\n    };\n\n    PersistentLazySegmentTree update(int\
    \ l, int r, E op) {\n        if (r <= l) return PersistentLazySegmentTree(*this);\n\
    \        return PersistentLazySegmentTree(update(root, op, 0, sz, l, r), sz);\n\
    \    };\n    Node *update(Node *u, E op, int nl, int nr, int ql, int qr) {\n \
    \       Node *ret = new Node(*u);\n        if (ql <= nl && nr <= qr) {\n     \
    \       ret->op = O::operation(ret->op, op);\n            return ret;\n      \
    \  }\n\n        push_down(ret);\n        int mid = (nl + nr) / 2;\n        if\
    \ (qr <= mid) {\n            ret->left = update(ret->left, op, nl, mid, ql, qr);\n\
    \        } else if (mid <= ql) {\n            ret->right = update(ret->right,\
    \ op, mid, nr, ql, qr);\n        } else {\n            ret->left = update(ret->left,\
    \ op, nl, mid, ql, qr);\n            ret->right = update(ret->right, op, mid,\
    \ nr, ql, qr);\n        }\n        ret->v = M::operation(A::operation(ret->left->v,\
    \ ret->left->op),\n                              A::operation(ret->right->v, ret->right->op));\n\
    \        return ret;\n    };\n\n    void dump() {\n        dump(root, 0);\n  \
    \  };\n    void dump(Node *u, int d) {\n        if (u == nullptr) return;\n  \
    \      dump(u->right, d + 1);\n        for (int i = 0; i < d; i++) std::cout <<\
    \ \"\\t\\t\";\n        std::cout << \"(\" << u->v << \", \" << u->op << \")\"\
    \ << std::endl;\n        dump(u->left, d + 1);\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/persistent_lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL2F_2.test.cpp
documentation_of: segment_tree/persistent_lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/persistent_lazy_segment_tree.hpp
- /library/segment_tree/persistent_lazy_segment_tree.hpp.html
title: segment_tree/persistent_lazy_segment_tree.hpp
---
