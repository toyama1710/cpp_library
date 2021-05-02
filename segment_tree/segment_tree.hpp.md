---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ARC033C.cpp
    title: test/atcoder/ARC033C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2444_1.test.cpp
    title: test/aoj/2444_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2A_1.test.cpp
    title: test/aoj/DSL2A_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2A_2.test.cpp
    title: test/aoj/DSL2A_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2B.test.cpp
    title: test/aoj/DSL2B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/segment_tree.hpp\"\n\n\n\n#include <vector>\n\
    #include <functional>\n#include <iterator>\n\n//===\ntemplate<class Monoid>\n\
    struct SegmentTree {\n    using T = typename Monoid::value_type;\n\n    std::vector<T>\
    \ tree;\n\n    SegmentTree() = default;\n    explicit SegmentTree(int n)\n   \
    \     :tree(n << 1, Monoid::identity()) {};\n\n    template<class InputIterator>\n\
    \    SegmentTree(InputIterator first, InputIterator last) {\n        tree.assign(distance(first,\
    \ last) << 1, Monoid::identity());\n\n        int i;\n        i = size();\n  \
    \      for (InputIterator itr = first; itr != last; itr++) {\n            tree[i++]\
    \ = *itr;\n        }\n        for (i = size() - 1; i > 0; i--) {\n           \
    \ tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);\n        }\n\
    \    };\n\n    inline int size() {\n        return tree.size() >> 1;\n    };\n\
    \n    inline T operator[] (int k) {\n        return tree[k + size()];\n    };\n\
    \n    void update(int k, const T dat) {\n        k += size();\n        tree[k]\
    \ = dat;\n        \n        while(k > 1) {\n            k >>= 1;\n           \
    \ tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);\n        }\n\
    \    };\n\n    // [l, r)\n    T fold(int l, int r) {\n        l += size(); //points\
    \ leaf\n        r += size();\n\n        T lv = Monoid::identity();\n        T\
    \ rv = Monoid::identity();\n        while (l < r) {\n            if (l & 1) lv\
    \ = Monoid::operation(lv, tree[l++]);\n            if (r & 1) rv = Monoid::operation(tree[--r],\
    \ rv);\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ Monoid::operation(lv, rv);\n    };\n\n    template<class F>\n    inline int\
    \ sub_tree_search(int i, T sum, F f) {\n        while (i < size()) {\n       \
    \     T x = Monoid::operation(sum, tree[i << 1]);\n            if (f(x)) {\n \
    \               i = i << 1;\n            }\n            else {\n             \
    \   sum = x;\n                i = (i << 1) | 1;\n            }\n        }\n  \
    \      return i - size();\n    }\n\n    template<class F>\n    int search(int\
    \ l, F f) {\n        l += size();\n        int r = size() * 2; //r = n;\n    \
    \    int tmpr = r;\n        int shift = 0;\n\n        T sum = Monoid::identity();\n\
    \        while (l < r) {\n            if (l & 1) {\n                if (f(Monoid::operation(sum,\
    \ tree[l]))) {\n                    return sub_tree_search(l, sum, f);\n     \
    \           }\n                sum = Monoid::operation(sum, tree[l]);\n      \
    \          l++;\n            }\n            l >>= 1;\n            r >>= 1;\n \
    \           shift++;\n        }\n\n        while (shift > 0) {\n            shift--;\n\
    \            r = tmpr >> shift;\n            if (r & 1) {\n                r--;\n\
    \                if (f(Monoid::operation(sum, tree[r]))) {\n                 \
    \   return sub_tree_search(r, sum, f);\n                }\n                sum\
    \ = Monoid::operation(sum, tree[r]);\n            }\n        }\n\n        return\
    \ -1;\n    };\n};\n//===\n\n\n"
  code: "#ifndef SEGMENT_TREE_HPP\n#define SEGMENT_TREE_HPP\n\n#include <vector>\n\
    #include <functional>\n#include <iterator>\n\n//===\ntemplate<class Monoid>\n\
    struct SegmentTree {\n    using T = typename Monoid::value_type;\n\n    std::vector<T>\
    \ tree;\n\n    SegmentTree() = default;\n    explicit SegmentTree(int n)\n   \
    \     :tree(n << 1, Monoid::identity()) {};\n\n    template<class InputIterator>\n\
    \    SegmentTree(InputIterator first, InputIterator last) {\n        tree.assign(distance(first,\
    \ last) << 1, Monoid::identity());\n\n        int i;\n        i = size();\n  \
    \      for (InputIterator itr = first; itr != last; itr++) {\n            tree[i++]\
    \ = *itr;\n        }\n        for (i = size() - 1; i > 0; i--) {\n           \
    \ tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);\n        }\n\
    \    };\n\n    inline int size() {\n        return tree.size() >> 1;\n    };\n\
    \n    inline T operator[] (int k) {\n        return tree[k + size()];\n    };\n\
    \n    void update(int k, const T dat) {\n        k += size();\n        tree[k]\
    \ = dat;\n        \n        while(k > 1) {\n            k >>= 1;\n           \
    \ tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);\n        }\n\
    \    };\n\n    // [l, r)\n    T fold(int l, int r) {\n        l += size(); //points\
    \ leaf\n        r += size();\n\n        T lv = Monoid::identity();\n        T\
    \ rv = Monoid::identity();\n        while (l < r) {\n            if (l & 1) lv\
    \ = Monoid::operation(lv, tree[l++]);\n            if (r & 1) rv = Monoid::operation(tree[--r],\
    \ rv);\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ Monoid::operation(lv, rv);\n    };\n\n    template<class F>\n    inline int\
    \ sub_tree_search(int i, T sum, F f) {\n        while (i < size()) {\n       \
    \     T x = Monoid::operation(sum, tree[i << 1]);\n            if (f(x)) {\n \
    \               i = i << 1;\n            }\n            else {\n             \
    \   sum = x;\n                i = (i << 1) | 1;\n            }\n        }\n  \
    \      return i - size();\n    }\n\n    template<class F>\n    int search(int\
    \ l, F f) {\n        l += size();\n        int r = size() * 2; //r = n;\n    \
    \    int tmpr = r;\n        int shift = 0;\n\n        T sum = Monoid::identity();\n\
    \        while (l < r) {\n            if (l & 1) {\n                if (f(Monoid::operation(sum,\
    \ tree[l]))) {\n                    return sub_tree_search(l, sum, f);\n     \
    \           }\n                sum = Monoid::operation(sum, tree[l]);\n      \
    \          l++;\n            }\n            l >>= 1;\n            r >>= 1;\n \
    \           shift++;\n        }\n\n        while (shift > 0) {\n            shift--;\n\
    \            r = tmpr >> shift;\n            if (r & 1) {\n                r--;\n\
    \                if (f(Monoid::operation(sum, tree[r]))) {\n                 \
    \   return sub_tree_search(r, sum, f);\n                }\n                sum\
    \ = Monoid::operation(sum, tree[r]);\n            }\n        }\n\n        return\
    \ -1;\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/segment_tree.hpp
  requiredBy:
  - test/atcoder/ARC033C.cpp
  timestamp: '2020-06-10 22:44:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2B.test.cpp
  - test/aoj/DSL2A_2.test.cpp
  - test/aoj/DSL2A_1.test.cpp
  - test/aoj/2444_1.test.cpp
documentation_of: segment_tree/segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/segment_tree.hpp
- /library/segment_tree/segment_tree.hpp.html
title: segment_tree/segment_tree.hpp
---
