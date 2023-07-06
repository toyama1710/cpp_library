---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2D.test.cpp
    title: test/aoj/DSL2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2E.test.cpp
    title: test/aoj/DSL2E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/dual_segment_tree.hpp\"\n\n\n\n#include <cstdint>\n\
    #include <vector>\n\n//===\ntemplate <class Monoid>\nstruct DualSegmentTree {\n\
    \    using T = typename Monoid::value_type;\n    std::vector<T> lazy;\n\n    DualSegmentTree()\
    \ = default;\n    explicit DualSegmentTree(uint32_t n) : lazy(n << 1, Monoid::identity()){};\n\
    \n    inline int size() {\n        return (int)(lazy.size() >> 1);\n    };\n\n\
    \    inline void propagate(uint32_t k) {\n        if (k >= size()) return;\n \
    \       lazy[(k << 1) | 0] = Monoid::operation(lazy[(k << 1) | 0], lazy[k]);\n\
    \        lazy[(k << 1) | 1] = Monoid::operation(lazy[(k << 1) | 1], lazy[k]);\n\
    \        lazy[k] = Monoid::identity();\n    };\n\n    inline void push_down(uint32_t\
    \ k) {\n        for (uint32_t i = 31; i > 0; i--) propagate(k >> i);\n    };\n\
    \n    // [l, r)\n    void update(uint32_t l, uint32_t r, T op) {\n        l +=\
    \ size();\n        r += size();\n        push_down(l);\n        push_down(r -\
    \ 1);\n\n        while (l < r) {\n            if (l & 1) lazy[l] = Monoid::operation(lazy[l],\
    \ op), l++;\n            if (r & 1) --r, lazy[r] = Monoid::operation(lazy[r],\
    \ op);\n\n            l >>= 1;\n            r >>= 1;\n        }\n    };\n\n  \
    \  T get(uint32_t k) {\n        k += size();\n        push_down(k);\n        return\
    \ lazy[k];\n    };\n\n    T operator[](uint32_t k) {\n        return get(k);\n\
    \    };\n};\n//===\n\n\n"
  code: "#ifndef DUAL_SEGMENT_TREE_HPP\n#define DUAL_SEGMENT_TREE_HPP\n\n#include\
    \ <cstdint>\n#include <vector>\n\n//===\ntemplate <class Monoid>\nstruct DualSegmentTree\
    \ {\n    using T = typename Monoid::value_type;\n    std::vector<T> lazy;\n\n\
    \    DualSegmentTree() = default;\n    explicit DualSegmentTree(uint32_t n) :\
    \ lazy(n << 1, Monoid::identity()){};\n\n    inline int size() {\n        return\
    \ (int)(lazy.size() >> 1);\n    };\n\n    inline void propagate(uint32_t k) {\n\
    \        if (k >= size()) return;\n        lazy[(k << 1) | 0] = Monoid::operation(lazy[(k\
    \ << 1) | 0], lazy[k]);\n        lazy[(k << 1) | 1] = Monoid::operation(lazy[(k\
    \ << 1) | 1], lazy[k]);\n        lazy[k] = Monoid::identity();\n    };\n\n   \
    \ inline void push_down(uint32_t k) {\n        for (uint32_t i = 31; i > 0; i--)\
    \ propagate(k >> i);\n    };\n\n    // [l, r)\n    void update(uint32_t l, uint32_t\
    \ r, T op) {\n        l += size();\n        r += size();\n        push_down(l);\n\
    \        push_down(r - 1);\n\n        while (l < r) {\n            if (l & 1)\
    \ lazy[l] = Monoid::operation(lazy[l], op), l++;\n            if (r & 1) --r,\
    \ lazy[r] = Monoid::operation(lazy[r], op);\n\n            l >>= 1;\n        \
    \    r >>= 1;\n        }\n    };\n\n    T get(uint32_t k) {\n        k += size();\n\
    \        push_down(k);\n        return lazy[k];\n    };\n\n    T operator[](uint32_t\
    \ k) {\n        return get(k);\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-07-03 22:10:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2E.test.cpp
  - test/aoj/DSL2D.test.cpp
documentation_of: segment_tree/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/dual_segment_tree.hpp
- /library/segment_tree/dual_segment_tree.hpp.html
title: segment_tree/dual_segment_tree.hpp
---
