---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/lazy_segment_tree.hpp
    title: segment_tree/lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#include <iostream>\n\
    #include <utility>\n#line 1 \"segment_tree/lazy_segment_tree.hpp\"\n\n\n\n#include\
    \ <vector>\n#include <cstdint>\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\
    \n\ninline int msb32(uint32_t x) {\n        if (x == 0) return -1;\n#ifndef __has_builtin\n\
    \        int r = 0;\n        if (x >> 16) x >>= 16, r |= 16;\n        if (x >>\
    \ 8) x >>= 8, r |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n        if (x >>\
    \ 2) x >>= 2, r |= 2;\n        return r | (x >> 1);\n#else\n        return 31\
    \ - __builtin_clz(x);\n#endif\n};\n\ninline int msb64(uint64_t x) {\n    if (x\
    \ == 0) return -1;\n\n    #ifndef __has_builtin\n        int r = 0;\n        if\
    \ (x >> 32) x >>= 32, r |= 32;\n        if (x >> 16) x >>= 16, r |= 16;\n    \
    \    if (x >> 8) x >>= 8, r |= 8;\n        if (x >> 4) x >>= 4, r |= 4;\n    \
    \    if (x >> 2) x >>= 2, r |= 2;\n        return r | (x >> 1);\n#else\n    return\
    \ 63 - __builtin_clzll(x);\n#endif\n};\n\n\n#line 7 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n//===\ntemplate<class MonoidwithOperator>\nstruct LazySegmentTree {\n    using\
    \ M = MonoidwithOperator;\n    using V = typename M::value_structure;\n    using\
    \ T = typename V::value_type;\n    using O = typename M::operator_structure;\n\
    \    using E = typename O::value_type;\n\n    // mergeMonoid V::operation\n  \
    \  // applyOperator M::operation\n    // mergeOperator O::operation\n\n    struct\
    \ Node {\n        T dat;\n        E lazy;\n        Node (T dat, E lazy): dat(dat),\
    \ lazy(lazy) {};\n    };\n\n    std::vector<Node> tree;\n\n    LazySegmentTree()\
    \ = default;\n    explicit LazySegmentTree(uint32_t n):\n        tree(n * 2 +\
    \ 2, Node(V::identity(), O::identity())) {};\n\n    int size() {\n        return\
    \ tree.size() >> 1;\n    };\n    \n    void propagation(uint32_t k) {\n      \
    \  const uint32_t l = (k << 1) | 0;\n        const uint32_t r = (k << 1) | 1;\n\
    \        tree[l].lazy = O::operation(tree[l].lazy, tree[k].lazy);\n        tree[r].lazy\
    \ = O::operation(tree[r].lazy, tree[k].lazy);\n        tree[l].dat = M::operation(tree[l].dat,\
    \ tree[k].lazy);\n        tree[r].dat = M::operation(tree[r].dat, tree[k].lazy);\n\
    \        tree[k].lazy = O::identity();\n    };\n    void push_down(uint32_t k)\
    \ {\n        if (k == 0) return;\n        uint32_t w = msb32(k);\n        for\
    \ (int i = w; i > 0; i--) propagation(k >> i);\n    };\n    void recalc(uint32_t\
    \ k) {\n        while (k > 1) {\n            k >>= 1;\n            tree[k].dat\
    \ = V::operation(tree[(k << 1) | 0].dat,\n                                   \
    \    tree[(k << 1) | 1].dat);\n        }\n    };\n    \n    // [l, r) += op\n\
    \    void update(uint32_t l, uint32_t r, E op) {\n        l += size();\n     \
    \   r += size();\n        uint32_t tmpl = l;\n        uint32_t tmpr = r;\n   \
    \     push_down(l);\n        push_down(r - 1);\n\n        while (l < r) {\n  \
    \          if (l & 1) {\n                tree[l].lazy = O::operation(tree[l].lazy,\
    \ op);\n                tree[l].dat = M::operation(tree[l].dat, op);\n       \
    \         l++;\n            }\n            if (r & 1) {\n                --r;\n\
    \                tree[r].lazy = O::operation(tree[r].lazy, op);\n            \
    \    tree[r].dat = M::operation(tree[r].dat, op);\n            }\n           \
    \ l >>= 1;\n            r >>= 1;\n        }\n\n        push_down(tmpl);\n    \
    \    push_down(tmpr - 1);\n        recalc(tmpl);\n        recalc(tmpr - 1);\n\
    \    };\n    void update(uint32_t idx, T x) {\n        idx += size();\n      \
    \  push_down(idx);\n        tree[idx].dat = x;\n        recalc(idx);\n    };\n\
    \    void set(uint32_t idx, T x) {\n        update(idx, x);\n    };\n\n    //\
    \ foldl[l, r)\n    T fold(uint32_t l, uint32_t r) {\n        l += size();\n  \
    \      r += size();\n        push_down(l);\n        push_down(r - 1);\n\n    \
    \    T lv = V::identity();\n        T rv = V::identity();\n\n        while (l\
    \ < r) {\n            if (l & 1) lv = V::operation(lv, tree[l].dat), l++;\n  \
    \          if (r & 1) --r, rv = V::operation(tree[r].dat, rv);\n\n           \
    \ l >>= 1;\n            r >>= 1;\n        }\n\n        return V::operation(lv,\
    \ rv);\n    };\n\n    T operator [](const uint32_t &k) {\n        push_down(k\
    \ + size());\n        return tree[k + size()].dat;\n    };\n};\n//===\n\n\n#line\
    \ 5 \"test/yosupo/range_affine_range_sum.test.cpp\"\nusing llong = long long;\n\
    using namespace std;\n\nstruct A {\n    struct M {\n        using value_type =\
    \ pair<llong, llong>;\n        inline static value_type identity() {\n       \
    \     return {0, 0};\n        };\n        inline static value_type operation(value_type\
    \ a, value_type b) {\n            return {(a.first + b.first) % 998244353, a.second\
    \ + b.second};\n        };\n    };\n    struct O {\n        using value_type =\
    \ pair<llong, llong>;\n        inline static value_type identity() {\n       \
    \     return {1ll, 0ll};\n        };\n        inline static value_type operation(value_type\
    \ x, value_type y) {\n            auto ret = identity();\n            ret.first\
    \ = (x.first * y.first) % 998244353;\n            ret.second = (y.first * x.second\
    \ + y.second) % 998244353;\n            return ret;\n        };\n    };\n    using\
    \ value_structure = M;\n    using operator_structure = O;\n    inline static M::value_type\
    \ operation(M::value_type a, O::value_type b) {\n        return {(b.first * a.first\
    \ + b.second * a.second) % 998244353, a.second};\n    };\n};\n\nllong n, q;\n\
    llong a;\nllong com, s, t, b, c;\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    cin >> n >> q;\n    LazySegmentTree<A> seg(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        cin >> a;\n        seg.set(i, {a, 1});\n    }\n\n    while\
    \ (q--) {\n        cin >> com;\n\n        if (com == 0) {\n            cin >>\
    \ s >> t >> b >> c;\n            seg.update(s, t, {b, c});\n        }\n      \
    \  else {\n            cin >> s >> t;\n            cout << seg.fold(s, t).first\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <iostream>\n#include <utility>\n#include \"../../segment_tree/lazy_segment_tree.hpp\"\
    \nusing llong = long long;\nusing namespace std;\n\nstruct A {\n    struct M {\n\
    \        using value_type = pair<llong, llong>;\n        inline static value_type\
    \ identity() {\n            return {0, 0};\n        };\n        inline static\
    \ value_type operation(value_type a, value_type b) {\n            return {(a.first\
    \ + b.first) % 998244353, a.second + b.second};\n        };\n    };\n    struct\
    \ O {\n        using value_type = pair<llong, llong>;\n        inline static value_type\
    \ identity() {\n            return {1ll, 0ll};\n        };\n        inline static\
    \ value_type operation(value_type x, value_type y) {\n            auto ret = identity();\n\
    \            ret.first = (x.first * y.first) % 998244353;\n            ret.second\
    \ = (y.first * x.second + y.second) % 998244353;\n            return ret;\n  \
    \      };\n    };\n    using value_structure = M;\n    using operator_structure\
    \ = O;\n    inline static M::value_type operation(M::value_type a, O::value_type\
    \ b) {\n        return {(b.first * a.first + b.second * a.second) % 998244353,\
    \ a.second};\n    };\n};\n\nllong n, q;\nllong a;\nllong com, s, t, b, c;\nint\
    \ main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    cin\
    \ >> n >> q;\n    LazySegmentTree<A> seg(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        cin >> a;\n        seg.set(i, {a, 1});\n    }\n\n    while (q--)\
    \ {\n        cin >> com;\n\n        if (com == 0) {\n            cin >> s >> t\
    \ >> b >> c;\n            seg.update(s, t, {b, c});\n        }\n        else {\n\
    \            cin >> s >> t;\n            cout << seg.fold(s, t).first << '\\n';\n\
    \        }\n    }\n}"
  dependsOn:
  - segment_tree/lazy_segment_tree.hpp
  - bit/msb.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-06-09 00:16:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
