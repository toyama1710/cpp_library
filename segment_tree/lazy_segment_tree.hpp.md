---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2F.test.cpp
    title: test/aoj/DSL2F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2G.test.cpp
    title: test/aoj/DSL2G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2H.test.cpp
    title: test/aoj/DSL2H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2I.test.cpp
    title: test/aoj/DSL2I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/lazy_segment_tree.hpp\"\n\n\n\n#include <vector>\n\
    #include <cstdint>\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\n\
    inline int msb32(uint32_t x) {\n        if (x == 0) return -1;\n#ifndef __has_builtin\n\
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
    \ + size());\n        return tree[k + size()].dat;\n    };\n};\n//===\n\n\n"
  code: "#ifndef LAZY_SEGMENT_TREE_HPP\n#define LAZY_SEGMENT_TREE_HPP\n\n#include\
    \ <vector>\n#include <cstdint>\n#include \"../bit/msb.hpp\"\n\n//===\ntemplate<class\
    \ MonoidwithOperator>\nstruct LazySegmentTree {\n    using M = MonoidwithOperator;\n\
    \    using V = typename M::value_structure;\n    using T = typename V::value_type;\n\
    \    using O = typename M::operator_structure;\n    using E = typename O::value_type;\n\
    \n    // mergeMonoid V::operation\n    // applyOperator M::operation\n    // mergeOperator\
    \ O::operation\n\n    struct Node {\n        T dat;\n        E lazy;\n       \
    \ Node (T dat, E lazy): dat(dat), lazy(lazy) {};\n    };\n\n    std::vector<Node>\
    \ tree;\n\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(uint32_t\
    \ n):\n        tree(n * 2 + 2, Node(V::identity(), O::identity())) {};\n\n   \
    \ int size() {\n        return tree.size() >> 1;\n    };\n    \n    void propagation(uint32_t\
    \ k) {\n        const uint32_t l = (k << 1) | 0;\n        const uint32_t r = (k\
    \ << 1) | 1;\n        tree[l].lazy = O::operation(tree[l].lazy, tree[k].lazy);\n\
    \        tree[r].lazy = O::operation(tree[r].lazy, tree[k].lazy);\n        tree[l].dat\
    \ = M::operation(tree[l].dat, tree[k].lazy);\n        tree[r].dat = M::operation(tree[r].dat,\
    \ tree[k].lazy);\n        tree[k].lazy = O::identity();\n    };\n    void push_down(uint32_t\
    \ k) {\n        if (k == 0) return;\n        uint32_t w = msb32(k);\n        for\
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
    \ + size());\n        return tree[k + size()].dat;\n    };\n};\n//===\n\n#endif\n"
  dependsOn:
  - bit/msb.hpp
  isVerificationFile: false
  path: segment_tree/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2020-06-08 22:41:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2F.test.cpp
  - test/aoj/DSL2H.test.cpp
  - test/aoj/DSL2G.test.cpp
  - test/aoj/DSL2I.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: segment_tree/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/lazy_segment_tree.hpp
- /library/segment_tree/lazy_segment_tree.hpp.html
title: segment_tree/lazy_segment_tree.hpp
---