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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL2F_1.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n#include <iostream>\n#include <algorithm>\n#line 1 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <cstdint>\n#include <vector>\n\n#line 1 \"bit/ctz.hpp\"\n\n\n\
    \n#line 5 \"bit/ctz.hpp\"\n\ninline int ctz32(uint32_t x) {\n#ifdef __has_builtin\n\
    \    if (x == 0)\n        return 32;\n    else\n        return __builtin_ctz(x);\n\
    #else\n    int r = 0;\n    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x\
    \ & 0x00ff)) x >>= 8, r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x\
    \ & 0x3)) x >>= 2, r |= 2;\n    if (!(x & 1)) x >>= 1, r |= 1;\n    return r +\
    \ ((x & 1) ^ 1);\n#endif\n};\ninline int ctz64(uint64_t x) {\n#ifdef __has_builtin\n\
    \    if (x == 0)\n        return 64;\n    else\n        return __builtin_ctzll(x);\n\
    #else\n    int r = 0;\n    if (!(x & 0x00000000ffffffff)) x >>= 32, r |= 32;\n\
    \    if (!(x & 0x0000ffff)) x >>= 16, r |= 16;\n    if (!(x & 0x00ff)) x >>= 8,\
    \ r |= 8;\n    if (!(x & 0x0f)) x >>= 4, r |= 4;\n    if (!(x & 0x3)) x >>= 2,\
    \ r |= 2;\n    if (!(x & 1)) x >>= 1, r |= 1;\n    return r + ((x & 1) ^ 1);\n\
    #endif\n};\n\n\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\ninline\
    \ uint32_t msb32(uint32_t x) {\n    if (x == 0) return 0;\n#ifdef __has_builtin\n\
    \    return 1 << (31 - __builtin_clz(x));\n#else\n    int r = 0;\n    if (x >>\
    \ 16) x >>= 16, r |= 16;\n    if (x >> 8) x >>= 8, r |= 8;\n    if (x >> 4) x\
    \ >>= 4, r |= 4;\n    if (x >> 2) x >>= 2, r |= 2;\n    return 1 << (r | (x >>\
    \ 1));\n#endif\n};\n\ninline uint64_t msb64(uint64_t x) {\n    if (x == 0) return\
    \ 0;\n#ifdef __has_builtin\n    return 1 << (63 - __builtin_clzll(x));\n#else\n\
    \    int r = 0;\n    if (x >> 32) x >>= 32, r |= 32;\n    if (x >> 16) x >>= 16,\
    \ r |= 16;\n    if (x >> 8) x >>= 8, r |= 8;\n    if (x >> 4) x >>= 4, r |= 4;\n\
    \    if (x >> 2) x >>= 2, r |= 2;\n    return 1 << (r | (x >> 1));\n#endif\n};\n\
    \n\n#line 9 \"segment_tree/lazy_segment_tree.hpp\"\n\n//===\ntemplate <class MonoidwithOperator>\n\
    struct LazySegmentTree {\n    using M = MonoidwithOperator;\n    using V = typename\
    \ M::value_structure;\n    using T = typename V::value_type;\n    using O = typename\
    \ M::operator_structure;\n    using E = typename O::value_type;\n\n    // mergeMonoid\
    \ V::operation\n    // applyOperator M::operation\n    // mergeOperator O::operation\n\
    \n    struct Node {\n        T dat;\n        E lazy;\n        Node(T dat, E lazy)\
    \ : dat(dat), lazy(lazy){};\n    };\n\n    std::vector<Node> tree;\n\n    LazySegmentTree()\
    \ = default;\n    explicit LazySegmentTree(uint32_t n)\n        : tree(n * 2 +\
    \ 2, Node(V::identity(), O::identity())){};\n\n    int size() { return tree.size()\
    \ >> 1; };\n\n    void propagation(uint32_t k) {\n        const uint32_t l = (k\
    \ << 1) | 0;\n        const uint32_t r = (k << 1) | 1;\n        tree[l].lazy =\
    \ O::operation(tree[l].lazy, tree[k].lazy);\n        tree[r].lazy = O::operation(tree[r].lazy,\
    \ tree[k].lazy);\n        tree[l].dat = M::operation(tree[l].dat, tree[k].lazy);\n\
    \        tree[r].dat = M::operation(tree[r].dat, tree[k].lazy);\n        tree[k].lazy\
    \ = O::identity();\n    };\n    void push_down(uint32_t k) {\n        if (k ==\
    \ 0) return;\n        uint32_t w = ctz32(msb32(k));\n        for (int i = w; i\
    \ > 0; i--) propagation(k >> i);\n    };\n    void recalc(uint32_t k) {\n    \
    \    while (k > 1) {\n            k >>= 1;\n            tree[k].dat =\n      \
    \          V::operation(tree[(k << 1) | 0].dat, tree[(k << 1) | 1].dat);\n   \
    \     }\n    };\n\n    // [l, r) += op\n    void update(uint32_t l, uint32_t r,\
    \ E op) {\n        l += size();\n        r += size();\n        uint32_t tmpl =\
    \ l;\n        uint32_t tmpr = r;\n        push_down(l);\n        push_down(r -\
    \ 1);\n\n        while (l < r) {\n            if (l & 1) {\n                tree[l].lazy\
    \ = O::operation(tree[l].lazy, op);\n                tree[l].dat = M::operation(tree[l].dat,\
    \ op);\n                l++;\n            }\n            if (r & 1) {\n      \
    \          --r;\n                tree[r].lazy = O::operation(tree[r].lazy, op);\n\
    \                tree[r].dat = M::operation(tree[r].dat, op);\n            }\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n\n        push_down(tmpl);\n\
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
    \    };\n};\n//===\n\n\n#line 5 \"test/aoj/DSL2F_1.test.cpp\"\nusing namespace\
    \ std;\nusing llong = long long;\n\nstruct M {\n    struct Monoid {\n        using\
    \ T = llong;\n        using value_type = T;\n\n        inline static T identity()\
    \ {\n            return (1ll << 31) - 1;\n        };\n        inline static T\
    \ operation(T a, T b) {\n            return min(a, b);\n        };\n    };\n \
    \   struct Operator {\n        using E = llong;\n        using value_type = E;\n\
    \n        inline static E identity() {\n            return (1ll << 31) - 1;\n\
    \        };\n        inline static E operation(E a, E b) {\n            if (a\
    \ == identity()) return b;\n            else if (b == identity()) return a;\n\
    \            else return b;\n        };\n    };\n\n    using value_structure =\
    \ Monoid;\n    using operator_structure = Operator;\n    using T = typename Monoid::T;\n\
    \    using E = typename Operator::E;\n\n    inline static T operation(T dat, E\
    \ op) {\n        if (op == operator_structure::identity()) return dat;\n     \
    \   else return op;\n    };\n};\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    \n    llong n, q;\n    llong com, s, t, x;\n\n    cin >> n >> q;\n\n    LazySegmentTree<M>\
    \ seg(n);\n\n    for (int i = 0; i < q; i++) {\n\n        cin >> com;\n\n    \
    \    if (com == 0) {\n            cin >> s >> t >> x;\n            seg.update(s,\
    \ t + 1, x);\n        }\n        else if (com == 1) {\n            cin >> s >>\
    \ t;\n            cout << seg.fold(s, t + 1) << endl;\n        }\n\n    }\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n#include <iostream>\n#include <algorithm>\n#include \"../../segment_tree/lazy_segment_tree.hpp\"\
    \nusing namespace std;\nusing llong = long long;\n\nstruct M {\n    struct Monoid\
    \ {\n        using T = llong;\n        using value_type = T;\n\n        inline\
    \ static T identity() {\n            return (1ll << 31) - 1;\n        };\n   \
    \     inline static T operation(T a, T b) {\n            return min(a, b);\n \
    \       };\n    };\n    struct Operator {\n        using E = llong;\n        using\
    \ value_type = E;\n\n        inline static E identity() {\n            return\
    \ (1ll << 31) - 1;\n        };\n        inline static E operation(E a, E b) {\n\
    \            if (a == identity()) return b;\n            else if (b == identity())\
    \ return a;\n            else return b;\n        };\n    };\n\n    using value_structure\
    \ = Monoid;\n    using operator_structure = Operator;\n    using T = typename\
    \ Monoid::T;\n    using E = typename Operator::E;\n\n    inline static T operation(T\
    \ dat, E op) {\n        if (op == operator_structure::identity()) return dat;\n\
    \        else return op;\n    };\n};\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    \n    llong n, q;\n    llong com, s, t,\
    \ x;\n\n    cin >> n >> q;\n\n    LazySegmentTree<M> seg(n);\n\n    for (int i\
    \ = 0; i < q; i++) {\n\n        cin >> com;\n\n        if (com == 0) {\n     \
    \       cin >> s >> t >> x;\n            seg.update(s, t + 1, x);\n        }\n\
    \        else if (com == 1) {\n            cin >> s >> t;\n            cout <<\
    \ seg.fold(s, t + 1) << endl;\n        }\n\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - segment_tree/lazy_segment_tree.hpp
  - bit/ctz.hpp
  - bit/msb.hpp
  isVerificationFile: true
  path: test/aoj/DSL2F_1.test.cpp
  requiredBy: []
  timestamp: '2021-12-07 22:49:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL2F_1.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2F_1.test.cpp
- /verify/test/aoj/DSL2F_1.test.cpp.html
title: test/aoj/DSL2F_1.test.cpp
---
