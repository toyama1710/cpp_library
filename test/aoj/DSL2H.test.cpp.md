---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: bit/ctz.hpp
    title: bit/ctz.hpp
  - icon: ':x:'
    path: bit/msb.hpp
    title: bit/msb.hpp
  - icon: ':x:'
    path: segment_tree/lazy_segment_tree.hpp
    title: segment_tree/lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL2H.test.cpp\"\n#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n#include <algorithm>\n#include <iostream>\n\n#line 1 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <cstdint>\n#include <vector>\n\n#line 1 \"bit/ctz.hpp\"\n\n\n\
    \n#line 5 \"bit/ctz.hpp\"\n\ninline int ctz32_(uint32_t bit) {\n    static const\
    \ int table[] = {\n        0,  1, 2,  6,  3,  11, 7,  16, 4,  14, 12, 21, 8, \
    \ 23, 17, 26,\n        31, 5, 10, 15, 13, 20, 22, 25, 30, 9,  19, 24, 29, 18,\
    \ 28, 27,\n    };\n    static const uint32_t de_bruijn = 0x04653adf;\n    bit\
    \ &= ~bit + 1;\n    return table[(bit * de_bruijn) >> 27];\n};\ninline int ctz32(uint32_t\
    \ bit) {\n    if (bit == 0) return 32;\n#ifdef __has_builtin\n    return __builtin_ctz(bit);\n\
    #else\n    return ctz32_(bit);\n#endif\n};\n\ninline int ctz64_(uint64_t bit)\
    \ {\n    static const int table[] = {\n        0,  1,  2,  7,  3,  13, 8,  19,\
    \ 4,  25, 14, 28, 9,  34, 20, 40,\n        5,  17, 26, 38, 15, 46, 29, 48, 10,\
    \ 31, 35, 54, 21, 50, 41, 57,\n        63, 6,  12, 18, 24, 27, 33, 39, 16, 37,\
    \ 45, 47, 30, 53, 49, 56,\n        62, 11, 23, 32, 36, 44, 52, 55, 61, 22, 43,\
    \ 51, 60, 42, 59, 58,\n    };\n    static const uint64_t de_bruijn = 0x0218a392cd3d5dbfull;\n\
    \    bit &= ~bit + 1;\n    return table[(bit * de_bruijn) >> 58];\n};\ninline\
    \ int ctz64(uint64_t bit) {\n    if (bit == 0) return 64;\n#ifdef __has_builtin\n\
    \    return __builtin_ctzll(bit);\n#else\n    return ctz64_(bit);\n#endif\n};\n\
    \n\n#line 1 \"bit/msb.hpp\"\n\n\n\n#line 5 \"bit/msb.hpp\"\n\ninline uint32_t\
    \ msb32_(uint32_t bit) {\n    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit\
    \ |= bit >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n    return bit ^\
    \ (bit >> 1);\n};\ninline uint32_t msb32(uint32_t x) {\n    if (x == 0) return\
    \ 0;\n#ifdef __has_builtin\n    return 1u << (31 - __builtin_clz(x));\n#else\n\
    \    return msb32_(x);\n#endif\n};\n\ninline uint64_t msb64_(uint64_t bit) {\n\
    \    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit >> 4;\n    bit |=\
    \ bit >> 8;\n    bit |= bit >> 16;\n    bit |= bit >> 32;\n    return bit ^ (bit\
    \ >> 1);\n};\ninline uint64_t msb64(uint64_t x) {\n    if (x == 0) return 0;\n\
    #ifdef __has_builtin\n    return 1ull << (63 - __builtin_clzll(x));\n#else\n \
    \   return msb64_(x);\n#endif\n};\n\n\n#line 9 \"segment_tree/lazy_segment_tree.hpp\"\
    \n\n//===\ntemplate <class MonoidwithOperator>\nstruct LazySegmentTree {\n   \
    \ using M = MonoidwithOperator;\n    using V = typename M::value_structure;\n\
    \    using T = typename V::value_type;\n    using O = typename M::operator_structure;\n\
    \    using E = typename O::value_type;\n\n    // mergeMonoid V::operation\n  \
    \  // applyOperator M::operation\n    // mergeOperator O::operation\n\n    struct\
    \ Node {\n        T dat;\n        E lazy;\n        Node(T dat, E lazy) : dat(dat),\
    \ lazy(lazy){};\n    };\n\n    std::vector<Node> tree;\n\n    LazySegmentTree()\
    \ = default;\n    explicit LazySegmentTree(uint32_t n)\n        : tree(n * 2 +\
    \ 2, Node(V::identity(), O::identity())){};\n\n    int size() {\n        return\
    \ tree.size() >> 1;\n    };\n\n    void propagation(uint32_t k) {\n        const\
    \ uint32_t l = (k << 1) | 0;\n        const uint32_t r = (k << 1) | 1;\n     \
    \   tree[l].lazy = O::operation(tree[l].lazy, tree[k].lazy);\n        tree[r].lazy\
    \ = O::operation(tree[r].lazy, tree[k].lazy);\n        tree[l].dat = M::operation(tree[l].dat,\
    \ tree[k].lazy);\n        tree[r].dat = M::operation(tree[r].dat, tree[k].lazy);\n\
    \        tree[k].lazy = O::identity();\n    };\n    void push_down(uint32_t k)\
    \ {\n        if (k == 0) return;\n        uint32_t w = ctz32(msb32(k));\n    \
    \    for (int i = w; i > 0; i--) propagation(k >> i);\n    };\n    void recalc(uint32_t\
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
    \    void set(uint32_t idx, T x) {\n        update(idx, x);\n    };\n\n    //\
    \ foldl[l, r)\n    T fold(uint32_t l, uint32_t r) {\n        l += size();\n  \
    \      r += size();\n        push_down(l);\n        push_down(r - 1);\n\n    \
    \    T lv = V::identity();\n        T rv = V::identity();\n\n        while (l\
    \ < r) {\n            if (l & 1) lv = V::operation(lv, tree[l].dat), l++;\n  \
    \          if (r & 1) --r, rv = V::operation(tree[r].dat, rv);\n\n           \
    \ l >>= 1;\n            r >>= 1;\n        }\n\n        return V::operation(lv,\
    \ rv);\n    };\n\n    T operator[](const uint32_t &k) {\n        push_down(k +\
    \ size());\n        return tree[k + size()].dat;\n    };\n};\n//===\n\n\n#line\
    \ 7 \"test/aoj/DSL2H.test.cpp\"\nusing namespace std;\nusing llong = long long;\n\
    \nstruct Monoid {\n    using T = llong;\n    using value_type = T;\n    inline\
    \ static T identity() {\n        return 1ll << 60ll;\n    };\n    inline static\
    \ T operation(const T a, const T b) {\n        return min(a, b);\n    };\n};\n\
    \nstruct Operator {\n    using T = llong;\n    using value_type = T;\n    inline\
    \ static T identity() {\n        return 0;\n    };\n    inline static T operation(const\
    \ T a, const T b) {\n        return a + b;\n    };\n};\n\ntemplate <class Monoid,\
    \ class Op>\nstruct MO {\n    using value_structure = Monoid;\n    using operator_structure\
    \ = Op;\n    using T = typename Monoid::value_type;\n    using E = typename Op::value_type;\n\
    \    inline static T operation(T a, E b) {\n        return a + b;\n    };\n};\n\
    \nllong n, q;\nllong com, s, t, x;\n\nint main() {\n    cin.tie(nullptr);\n  \
    \  ios::sync_with_stdio(false);\n\n    cin >> n >> q;\n    LazySegmentTree<MO<Monoid,\
    \ Operator>> seg(n);\n    for (int i = 0; i < n; i++) seg.set(i, 0);\n\n    while\
    \ (q--) {\n        cin >> com;\n\n        if (com == 0) {\n            cin >>\
    \ s >> t >> x;\n            seg.update(s, t + 1, x);\n        } else {\n     \
    \       cin >> s >> t;\n            cout << seg.fold(s, t + 1) << '\\n';\n   \
    \     }\n    }\n};\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H\"\
    \n#include <algorithm>\n#include <iostream>\n\n#include \"../../segment_tree/lazy_segment_tree.hpp\"\
    \nusing namespace std;\nusing llong = long long;\n\nstruct Monoid {\n    using\
    \ T = llong;\n    using value_type = T;\n    inline static T identity() {\n  \
    \      return 1ll << 60ll;\n    };\n    inline static T operation(const T a, const\
    \ T b) {\n        return min(a, b);\n    };\n};\n\nstruct Operator {\n    using\
    \ T = llong;\n    using value_type = T;\n    inline static T identity() {\n  \
    \      return 0;\n    };\n    inline static T operation(const T a, const T b)\
    \ {\n        return a + b;\n    };\n};\n\ntemplate <class Monoid, class Op>\n\
    struct MO {\n    using value_structure = Monoid;\n    using operator_structure\
    \ = Op;\n    using T = typename Monoid::value_type;\n    using E = typename Op::value_type;\n\
    \    inline static T operation(T a, E b) {\n        return a + b;\n    };\n};\n\
    \nllong n, q;\nllong com, s, t, x;\n\nint main() {\n    cin.tie(nullptr);\n  \
    \  ios::sync_with_stdio(false);\n\n    cin >> n >> q;\n    LazySegmentTree<MO<Monoid,\
    \ Operator>> seg(n);\n    for (int i = 0; i < n; i++) seg.set(i, 0);\n\n    while\
    \ (q--) {\n        cin >> com;\n\n        if (com == 0) {\n            cin >>\
    \ s >> t >> x;\n            seg.update(s, t + 1, x);\n        } else {\n     \
    \       cin >> s >> t;\n            cout << seg.fold(s, t + 1) << '\\n';\n   \
    \     }\n    }\n};"
  dependsOn:
  - segment_tree/lazy_segment_tree.hpp
  - bit/ctz.hpp
  - bit/msb.hpp
  isVerificationFile: true
  path: test/aoj/DSL2H.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL2H.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2H.test.cpp
- /verify/test/aoj/DSL2H.test.cpp.html
title: test/aoj/DSL2H.test.cpp
---
