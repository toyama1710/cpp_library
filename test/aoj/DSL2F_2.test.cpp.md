---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment_tree/persistent_lazy_segment_tree.hpp
    title: segment_tree/persistent_lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL2F_2.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#line 1 \"segment_tree/persistent_lazy_segment_tree.hpp\"\n\n\n\n#include\
    \ <iostream>\ntemplate <class MonoidwithOperator>\nstruct PersistentLazySegmentTree\
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
    \        return ret;\n    };\n\n    void dump() { dump(root, 0); };\n    void\
    \ dump(Node *u, int d) {\n        if (u == nullptr) return;\n        dump(u->right,\
    \ d + 1);\n        for (int i = 0; i < d; i++) std::cout << \"\\t\\t\";\n    \
    \    std::cout << \"(\" << u->v << \", \" << u->op << \")\" << std::endl;\n  \
    \      dump(u->left, d + 1);\n    };\n};\n\n\n#line 4 \"test/aoj/DSL2F_2.test.cpp\"\
    \n#include <bits/stdc++.h>\n\n#define _overload(_1, _2, _3, _4, name, ...) name\n\
    #define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr,\
    \ a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)\n\
    #define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define rep(...) repeat(__VA_ARGS__)\n\nusing namespace std;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\n\nstruct M {\n    struct Monoid {\n\
    \        using T = uint;\n        using value_type = T;\n        inline static\
    \ T identity() { return (1ll << 31) - 1; };\n        inline static T operation(T\
    \ a, T b) { return min(a, b); };\n    };\n    struct Operator {\n        using\
    \ E = uint;\n        using value_type = E;\n        inline static E identity()\
    \ { return (1ll << 31) - 1; };\n        inline static E operation(E a, E b) {\n\
    \            if (b == identity())\n                return a;\n            else\n\
    \                return b;\n        };\n    };\n\n    using value_structure =\
    \ Monoid;\n    using operator_structure = Operator;\n    using T = typename Monoid::T;\n\
    \    using E = typename Operator::E;\n\n    inline static T operation(T dat, E\
    \ op) {\n        if (op == operator_structure::identity())\n            return\
    \ dat;\n        else\n            return op;\n    };\n};\n\nint main() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int n, q;\n    cin\
    \ >> n >> q;\n    vector<PersistentLazySegmentTree<M>> v(q + 1);\n\n    v[0] =\
    \ PersistentLazySegmentTree<M>(n, (1ll << 31) - 1);\n    queue<pair<int, pair<int,\
    \ int>>> que;\n\n    rep(i, 1, q + 1) {\n        v[i] = v[i - 1];\n\n        i64\
    \ ty;\n        i64 s, t, x;\n        cin >> ty;\n\n        if (ty == 0) {\n  \
    \          cin >> s >> t >> x;\n            v[i] = v[i].update(s, t + 1, x);\n\
    \        } else {\n            cin >> s >> t;\n            que.push({i, {s, t\
    \ + 1}});\n        }\n        // v[i].dump();\n    }\n\n    while (!que.empty())\
    \ {\n        auto a = que.front();\n        que.pop();\n        i64 idx = a.first;\n\
    \        i64 s = a.second.first;\n        i64 t = a.second.second;\n        cout\
    \ << v[idx].fold(s, t) << endl;\n        // v[idx].dump();\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include \"../../segment_tree/persistent_lazy_segment_tree.hpp\"\n#include\
    \ <bits/stdc++.h>\n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define\
    \ _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b,\
    \ 1)\n#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)\n\
    #define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define rep(...) repeat(__VA_ARGS__)\n\nusing namespace std;\nusing i64 = long\
    \ long;\nusing u64 = unsigned long long;\n\nstruct M {\n    struct Monoid {\n\
    \        using T = uint;\n        using value_type = T;\n        inline static\
    \ T identity() { return (1ll << 31) - 1; };\n        inline static T operation(T\
    \ a, T b) { return min(a, b); };\n    };\n    struct Operator {\n        using\
    \ E = uint;\n        using value_type = E;\n        inline static E identity()\
    \ { return (1ll << 31) - 1; };\n        inline static E operation(E a, E b) {\n\
    \            if (b == identity())\n                return a;\n            else\n\
    \                return b;\n        };\n    };\n\n    using value_structure =\
    \ Monoid;\n    using operator_structure = Operator;\n    using T = typename Monoid::T;\n\
    \    using E = typename Operator::E;\n\n    inline static T operation(T dat, E\
    \ op) {\n        if (op == operator_structure::identity())\n            return\
    \ dat;\n        else\n            return op;\n    };\n};\n\nint main() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int n, q;\n    cin\
    \ >> n >> q;\n    vector<PersistentLazySegmentTree<M>> v(q + 1);\n\n    v[0] =\
    \ PersistentLazySegmentTree<M>(n, (1ll << 31) - 1);\n    queue<pair<int, pair<int,\
    \ int>>> que;\n\n    rep(i, 1, q + 1) {\n        v[i] = v[i - 1];\n\n        i64\
    \ ty;\n        i64 s, t, x;\n        cin >> ty;\n\n        if (ty == 0) {\n  \
    \          cin >> s >> t >> x;\n            v[i] = v[i].update(s, t + 1, x);\n\
    \        } else {\n            cin >> s >> t;\n            que.push({i, {s, t\
    \ + 1}});\n        }\n        // v[i].dump();\n    }\n\n    while (!que.empty())\
    \ {\n        auto a = que.front();\n        que.pop();\n        i64 idx = a.first;\n\
    \        i64 s = a.second.first;\n        i64 t = a.second.second;\n        cout\
    \ << v[idx].fold(s, t) << endl;\n        // v[idx].dump();\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - segment_tree/persistent_lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL2F_2.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 17:23:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL2F_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2F_2.test.cpp
- /verify/test/aoj/DSL2F_2.test.cpp.html
title: test/aoj/DSL2F_2.test.cpp
---
