---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ctz.hpp
    title: bit/ctz.hpp
  - icon: ':heavy_check_mark:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: segment_tree/lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL2G.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include <iostream>\n#include <utility>\n#line 1 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <cstdint>\n#include <vector>\n\n#line 1 \"bit/ctz.hpp\"\n\n\n\
    \n#line 5 \"bit/ctz.hpp\"\n\ninline int ctz32_(uint64_t x) {\n    int r = 0;\n\
    \    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x & 0x00ff)) x >>= 8,\
    \ r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x & 0x3)) x >>= 2,\
    \ r |= 2;\n    return r | ((x & 1) ^ 1);\n};\ninline int ctz32(uint32_t x) {\n\
    \    if (x == 0) return 32;\n#ifdef __has_builtin\n    return __builtin_ctz(x);\n\
    #else\n    return ctz32_(x);\n#endif\n};\n\ninline int ctz64_(uint64_t x) {\n\
    \    int r = 0;\n    if (!(x & 0x00000000ffffffff)) x >>= 32, r |= 32;\n    if\
    \ (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x & 0x00ff)) x >>= 8, r |=\
    \ 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x & 0x3)) x >>= 2, r |=\
    \ 2;\n    return r | ((x & 1) ^ 1);\n};\ninline int ctz64(uint64_t x) {\n    if\
    \ (x == 0) return 64;\n#ifdef __has_builtin\n    return __builtin_ctzll(x);\n\
    #else\n    return ctz64_(x);\n#endif\n};\n\n\n#line 1 \"bit/msb.hpp\"\n\n\n\n\
    #line 5 \"bit/msb.hpp\"\n\ninline uint64_t msb32_(uint64_t x) {\n    int r = 0;\n\
    \    if (x >> 16) x >>= 16, r |= 16;\n    if (x >> 8) x >>= 8, r |= 8;\n    if\
    \ (x >> 4) x >>= 4, r |= 4;\n    if (x >> 2) x >>= 2, r |= 2;\n    return 1u <<\
    \ (r | (x >> 1));\n};\ninline uint32_t msb32(uint32_t x) {\n    if (x == 0) return\
    \ 0;\n#ifdef __has_builtin\n    return 1u << (31 - __builtin_clz(x));\n#else\n\
    \    return msb32_(x);\n#endif\n};\n\ninline uint64_t msb64_(uint64_t x) {\n \
    \   int r = 0;\n    if (x >> 32) x >>= 32, r |= 32;\n    if (x >> 16) x >>= 16,\
    \ r |= 16;\n    if (x >> 8) x >>= 8, r |= 8;\n    if (x >> 4) x >>= 4, r |= 4;\n\
    \    if (x >> 2) x >>= 2, r |= 2;\n    return 1ull << (r | (x >> 1));\n};\ninline\
    \ uint64_t msb64(uint64_t x) {\n    if (x == 0) return 0;\n#ifdef __has_builtin\n\
    \    return 1ull << (63 - __builtin_clzll(x));\n#else\n    return msb64_(x);\n\
    #endif\n};\n\n\n#line 9 \"segment_tree/lazy_segment_tree.hpp\"\n\n//===\ntemplate\
    \ <class MonoidwithOperator>\nstruct LazySegmentTree {\n    using M = MonoidwithOperator;\n\
    \    using V = typename M::value_structure;\n    using T = typename V::value_type;\n\
    \    using O = typename M::operator_structure;\n    using E = typename O::value_type;\n\
    \n    // mergeMonoid V::operation\n    // applyOperator M::operation\n    // mergeOperator\
    \ O::operation\n\n    struct Node {\n        T dat;\n        E lazy;\n       \
    \ Node(T dat, E lazy) : dat(dat), lazy(lazy){};\n    };\n\n    std::vector<Node>\
    \ tree;\n\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(uint32_t\
    \ n)\n        : tree(n * 2 + 2, Node(V::identity(), O::identity())){};\n\n   \
    \ int size() { return tree.size() >> 1; };\n\n    void propagation(uint32_t k)\
    \ {\n        const uint32_t l = (k << 1) | 0;\n        const uint32_t r = (k <<\
    \ 1) | 1;\n        tree[l].lazy = O::operation(tree[l].lazy, tree[k].lazy);\n\
    \        tree[r].lazy = O::operation(tree[r].lazy, tree[k].lazy);\n        tree[l].dat\
    \ = M::operation(tree[l].dat, tree[k].lazy);\n        tree[r].dat = M::operation(tree[r].dat,\
    \ tree[k].lazy);\n        tree[k].lazy = O::identity();\n    };\n    void push_down(uint32_t\
    \ k) {\n        if (k == 0) return;\n        uint32_t w = ctz32(msb32(k));\n \
    \       for (int i = w; i > 0; i--) propagation(k >> i);\n    };\n    void recalc(uint32_t\
    \ k) {\n        while (k > 1) {\n            k >>= 1;\n            tree[k].dat\
    \ =\n                V::operation(tree[(k << 1) | 0].dat, tree[(k << 1) | 1].dat);\n\
    \        }\n    };\n\n    // [l, r) += op\n    void update(uint32_t l, uint32_t\
    \ r, E op) {\n        l += size();\n        r += size();\n        uint32_t tmpl\
    \ = l;\n        uint32_t tmpr = r;\n        push_down(l);\n        push_down(r\
    \ - 1);\n\n        while (l < r) {\n            if (l & 1) {\n               \
    \ tree[l].lazy = O::operation(tree[l].lazy, op);\n                tree[l].dat\
    \ = M::operation(tree[l].dat, op);\n                l++;\n            }\n    \
    \        if (r & 1) {\n                --r;\n                tree[r].lazy = O::operation(tree[r].lazy,\
    \ op);\n                tree[r].dat = M::operation(tree[r].dat, op);\n       \
    \     }\n            l >>= 1;\n            r >>= 1;\n        }\n\n        push_down(tmpl);\n\
    \        push_down(tmpr - 1);\n        recalc(tmpl);\n        recalc(tmpr - 1);\n\
    \    };\n    void update(uint32_t idx, T x) {\n        idx += size();\n      \
    \  push_down(idx);\n        tree[idx].dat = x;\n        recalc(idx);\n    };\n\
    \    void set(uint32_t idx, T x) { update(idx, x); };\n\n    // foldl[l, r)\n\
    \    T fold(uint32_t l, uint32_t r) {\n        l += size();\n        r += size();\n\
    \        push_down(l);\n        push_down(r - 1);\n\n        T lv = V::identity();\n\
    \        T rv = V::identity();\n\n        while (l < r) {\n            if (l &\
    \ 1) lv = V::operation(lv, tree[l].dat), l++;\n            if (r & 1) --r, rv\
    \ = V::operation(tree[r].dat, rv);\n\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n\n        return V::operation(lv, rv);\n    };\n\n    T operator[](const\
    \ uint32_t &k) {\n        push_down(k + size());\n        return tree[k + size()].dat;\n\
    \    };\n};\n//===\n\n\n#line 5 \"test/aoj/DSL2G.test.cpp\"\nusing namespace std;\n\
    using llong = long long;\n\nstruct Monoid {\n    using T = pair<llong, llong>;\n\
    \    using value_type = pair<llong, llong>;\n    inline static T identity() {\n\
    \        return {0ll, 0ll};\n    };\n    inline static T operation(T &a, T &b)\
    \ {\n        return {a.first + b.first, a.second + b.second};\n    };\n};\nstruct\
    \ Operator {\n    using E = llong;\n    using value_type = llong;\n    inline\
    \ static E identity() {\n        return 0;\n    };\n    inline static E operation(E\
    \ &a, E &b) {\n        return a + b;\n    };\n};\nstruct A {\n    using value_structure\
    \ = Monoid;\n    using operator_structure = Operator;\n    using T = typename\
    \ value_structure::T;\n    using E = typename operator_structure::E;\n    inline\
    \ static T operation(T &a, E &b) {\n        return {a.first + b * a.second, a.second};\n\
    \    };\n};\n\nllong n, q;\nllong com, s, t, x;\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    cin >> n >> q;\n    LazySegmentTree<A>\
    \ seg(n);\n\n    for (int i = 0; i < n; i++) seg.set(i, {0ll, 1ll});\n\n    while\
    \ (q--) {\n        cin >> com;\n        if (com == 0) {\n            cin >> s\
    \ >> t >> x;\n            seg.update(s - 1, t, x);\n        }\n        else {\n\
    \            cin >> s >> t;\n            cout << seg.fold(s - 1, t).first << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n#include <iostream>\n#include <utility>\n#include \"../../segment_tree/lazy_segment_tree.hpp\"\
    \nusing namespace std;\nusing llong = long long;\n\nstruct Monoid {\n    using\
    \ T = pair<llong, llong>;\n    using value_type = pair<llong, llong>;\n    inline\
    \ static T identity() {\n        return {0ll, 0ll};\n    };\n    inline static\
    \ T operation(T &a, T &b) {\n        return {a.first + b.first, a.second + b.second};\n\
    \    };\n};\nstruct Operator {\n    using E = llong;\n    using value_type = llong;\n\
    \    inline static E identity() {\n        return 0;\n    };\n    inline static\
    \ E operation(E &a, E &b) {\n        return a + b;\n    };\n};\nstruct A {\n \
    \   using value_structure = Monoid;\n    using operator_structure = Operator;\n\
    \    using T = typename value_structure::T;\n    using E = typename operator_structure::E;\n\
    \    inline static T operation(T &a, E &b) {\n        return {a.first + b * a.second,\
    \ a.second};\n    };\n};\n\nllong n, q;\nllong com, s, t, x;\n\nint main() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    cin >> n >> q;\n\
    \    LazySegmentTree<A> seg(n);\n\n    for (int i = 0; i < n; i++) seg.set(i,\
    \ {0ll, 1ll});\n\n    while (q--) {\n        cin >> com;\n        if (com == 0)\
    \ {\n            cin >> s >> t >> x;\n            seg.update(s - 1, t, x);\n \
    \       }\n        else {\n            cin >> s >> t;\n            cout << seg.fold(s\
    \ - 1, t).first << '\\n';\n        }\n    }\n}"
  dependsOn:
  - segment_tree/lazy_segment_tree.hpp
  - bit/ctz.hpp
  - bit/msb.hpp
  isVerificationFile: true
  path: test/aoj/DSL2G.test.cpp
  requiredBy: []
  timestamp: '2021-12-07 23:48:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL2G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2G.test.cpp
- /verify/test/aoj/DSL2G.test.cpp.html
title: test/aoj/DSL2G.test.cpp
---
