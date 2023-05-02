---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1068.test.cpp
    title: test/aoj/1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.test.cpp
    title: test/aoj/2842.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/segment_tree2d.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n//===\n// memory: O(HW)\n// time: O(logH * logW)\ntemplate\
    \ <class CommutativeMonoid>\nstruct SegmentTree2D {\n    using M = CommutativeMonoid;\n\
    \    using T = typename M::value_type;\n    const std::size_t H, W;\n    std::vector<std::vector<T>>\
    \ tree;\n\n    SegmentTree2D(size_t H, size_t W) : H(H), W(W) {\n        tree.assign(H\
    \ << 1, std::vector<T>(W << 1, M::identity()));\n    };\n\n    void update(int\
    \ sy, int sx, T dat) {\n        sy += H;\n        sx += W;\n        int ty, tx;\n\
    \        tree[sy][sx] = dat;\n        tx = sx;\n        while (tx > 1) {\n   \
    \         tx >>= 1;\n            tree[sy][tx] =\n                M::operation(tree[sy][(tx\
    \ << 1)], tree[sy][(tx << 1) | 1]);\n        }\n\n        ty = sy;\n        while\
    \ (ty > 1) {\n            ty >>= 1;\n            tx = sx;\n            tree[ty][tx]\
    \ =\n                M::operation(tree[(ty << 1)][tx], tree[(ty << 1) | 1][tx]);\n\
    \            while (tx > 1) {\n                tx >>= 1;\n                tree[ty][tx]\
    \ =\n                    M::operation(tree[(ty << 1)][tx], tree[(ty << 1) | 1][tx]);\n\
    \            }\n        }\n    };\n\n    T fold(int sy, int sx, int ty, int tx)\
    \ {\n        sy += H;\n        ty += H;\n\n        T ret = M::identity();\n  \
    \      while (sy < ty) {\n            if (sy & 1) ret = M::operation(ret, fold_x(sy++,\
    \ sx, tx));\n            if (ty & 1) ret = M::operation(fold_x(--ty, sx, tx),\
    \ ret);\n            sy >>= 1;\n            ty >>= 1;\n        }\n        return\
    \ ret;\n    };\n    T fold_x(int y, int l, int r) {\n        l += W;\n       \
    \ r += W;\n        T ret = M::identity();\n        while (l < r) {\n         \
    \   if (l & 1) ret = M::operation(ret, tree[y][l++]);\n            if (r & 1)\
    \ ret = M::operation(tree[y][--r], ret);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return ret;\n    };\n\n    T at(int sy, int sx) const\
    \ {\n        return tree[sy + H][sx + W];\n    };\n};\n//===\n"
  code: "#include <cassert>\n#include <vector>\n\n//===\n// memory: O(HW)\n// time:\
    \ O(logH * logW)\ntemplate <class CommutativeMonoid>\nstruct SegmentTree2D {\n\
    \    using M = CommutativeMonoid;\n    using T = typename M::value_type;\n   \
    \ const std::size_t H, W;\n    std::vector<std::vector<T>> tree;\n\n    SegmentTree2D(size_t\
    \ H, size_t W) : H(H), W(W) {\n        tree.assign(H << 1, std::vector<T>(W <<\
    \ 1, M::identity()));\n    };\n\n    void update(int sy, int sx, T dat) {\n  \
    \      sy += H;\n        sx += W;\n        int ty, tx;\n        tree[sy][sx] =\
    \ dat;\n        tx = sx;\n        while (tx > 1) {\n            tx >>= 1;\n  \
    \          tree[sy][tx] =\n                M::operation(tree[sy][(tx << 1)], tree[sy][(tx\
    \ << 1) | 1]);\n        }\n\n        ty = sy;\n        while (ty > 1) {\n    \
    \        ty >>= 1;\n            tx = sx;\n            tree[ty][tx] =\n       \
    \         M::operation(tree[(ty << 1)][tx], tree[(ty << 1) | 1][tx]);\n      \
    \      while (tx > 1) {\n                tx >>= 1;\n                tree[ty][tx]\
    \ =\n                    M::operation(tree[(ty << 1)][tx], tree[(ty << 1) | 1][tx]);\n\
    \            }\n        }\n    };\n\n    T fold(int sy, int sx, int ty, int tx)\
    \ {\n        sy += H;\n        ty += H;\n\n        T ret = M::identity();\n  \
    \      while (sy < ty) {\n            if (sy & 1) ret = M::operation(ret, fold_x(sy++,\
    \ sx, tx));\n            if (ty & 1) ret = M::operation(fold_x(--ty, sx, tx),\
    \ ret);\n            sy >>= 1;\n            ty >>= 1;\n        }\n        return\
    \ ret;\n    };\n    T fold_x(int y, int l, int r) {\n        l += W;\n       \
    \ r += W;\n        T ret = M::identity();\n        while (l < r) {\n         \
    \   if (l & 1) ret = M::operation(ret, tree[y][l++]);\n            if (r & 1)\
    \ ret = M::operation(tree[y][--r], ret);\n            l >>= 1;\n            r\
    \ >>= 1;\n        }\n        return ret;\n    };\n\n    T at(int sy, int sx) const\
    \ {\n        return tree[sy + H][sx + W];\n    };\n};\n//===\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/segment_tree2d.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2842.test.cpp
  - test/aoj/1068.test.cpp
documentation_of: segment_tree/segment_tree2d.hpp
layout: document
redirect_from:
- /library/segment_tree/segment_tree2d.hpp
- /library/segment_tree/segment_tree2d.hpp.html
title: segment_tree/segment_tree2d.hpp
---
