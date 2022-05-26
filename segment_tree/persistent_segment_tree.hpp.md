---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1418.test.cpp
    title: test/aoj/1418.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum1.test.cpp
    title: test/yosupo/rectangle_sum1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"segment_tree/persistent_segment_tree.hpp\"\n\n\n\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <functional>\n#include <iterator>\n\
    #include <vector>\n\ntemplate <class Monoid>\nstruct PersistentSegmentTree {\n\
    \    using uint = size_t;\n    using T = typename Monoid::value_type;\n\n    struct\
    \ Node {\n        T dat;\n        Node *l = nullptr, *r = nullptr;\n\n       \
    \ Node(T dat) : dat(dat){};\n    };\n\n    Node *root;\n    uint n;\n\n    Node\
    \ *merge_node(Node *lch, Node *rch) {\n        T l = (lch ? lch->dat : Monoid::identity());\n\
    \        T r = (rch ? rch->dat : Monoid::identity());\n        Node *ret = new\
    \ Node(Monoid::operation(l, r));\n        ret->l = lch;\n        ret->r = rch;\n\
    \n        return ret;\n    };\n\n    PersistentSegmentTree(const PersistentSegmentTree\
    \ &) = default;\n    PersistentSegmentTree &operator=(const PersistentSegmentTree\
    \ &) = default;\n    PersistentSegmentTree(uint n, Node *r) : root(r), n(n){};\n\
    \    PersistentSegmentTree(uint n)\n        : root(alloc(0, n, std::vector<T>(n,\
    \ Monoid::identity()))), n(n){};\n    template <class InputItr>\n    PersistentSegmentTree(const\
    \ InputItr first, const InputItr last)\n        : n(std::distance(first, last)),\n\
    \          root(alloc(0, n, std::vector<T>(first, last))){};\n\n    Node *alloc(uint\
    \ nl, uint nr, const std::vector<T> &v) {\n        if (nr - nl <= 1)\n       \
    \     return new Node(v[nl]);\n        else\n            return merge_node(alloc(nl,\
    \ (nl + nr) / 2, v),\n                              alloc((nl + nr) / 2, nr, v));\n\
    \    };\n\n    const T fold(uint l, uint r) const { return fold(l, r, 0, n, root);\
    \ };\n    const T fold(uint ql, uint qr, uint nl, uint nr, const Node *np) const\
    \ {\n        if (np == nullptr || qr <= nl || nr <= ql)\n            return Monoid::identity();\n\
    \        else if (ql <= nl && nr <= qr)\n            return np->dat;\n       \
    \ else\n            return Monoid::operation(fold(ql, qr, nl, (nl + nr) / 2, np->l),\n\
    \                                     fold(ql, qr, (nl + nr) / 2, nr, np->r));\n\
    \    };\n\n    PersistentSegmentTree update(uint idx, T d) { return set(idx, d);\
    \ };\n    PersistentSegmentTree set(uint idx, T d) {\n        return PersistentSegmentTree(n,\
    \ update(0, n, idx, d, root));\n    };\n    Node *update(uint nl, uint nr, uint\
    \ idx, T d, Node *np) {\n        if (idx < nl || nr <= idx)\n            return\
    \ np;\n        else if (nr - nl == 1)\n            return new Node(d);\n     \
    \   else\n            return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l),\n\
    \                              update((nl + nr) / 2, nr, idx, d, np->r));\n  \
    \  };\n\n    PersistentSegmentTree get_tree() { return *this; };\n\n    T operator[](uint\
    \ idx) { return fold(idx, idx + 1, 0, n, root); };\n};\n\n\n"
  code: "#ifndef PERSISTENT_SEGMENT_TREE_HPP\n#define PERSISTENT_SEGMENT_TREE_HPP\n\
    \n#include <cstddef>\n#include <cstdint>\n#include <functional>\n#include <iterator>\n\
    #include <vector>\n\ntemplate <class Monoid>\nstruct PersistentSegmentTree {\n\
    \    using uint = size_t;\n    using T = typename Monoid::value_type;\n\n    struct\
    \ Node {\n        T dat;\n        Node *l = nullptr, *r = nullptr;\n\n       \
    \ Node(T dat) : dat(dat){};\n    };\n\n    Node *root;\n    uint n;\n\n    Node\
    \ *merge_node(Node *lch, Node *rch) {\n        T l = (lch ? lch->dat : Monoid::identity());\n\
    \        T r = (rch ? rch->dat : Monoid::identity());\n        Node *ret = new\
    \ Node(Monoid::operation(l, r));\n        ret->l = lch;\n        ret->r = rch;\n\
    \n        return ret;\n    };\n\n    PersistentSegmentTree(const PersistentSegmentTree\
    \ &) = default;\n    PersistentSegmentTree &operator=(const PersistentSegmentTree\
    \ &) = default;\n    PersistentSegmentTree(uint n, Node *r) : root(r), n(n){};\n\
    \    PersistentSegmentTree(uint n)\n        : root(alloc(0, n, std::vector<T>(n,\
    \ Monoid::identity()))), n(n){};\n    template <class InputItr>\n    PersistentSegmentTree(const\
    \ InputItr first, const InputItr last)\n        : n(std::distance(first, last)),\n\
    \          root(alloc(0, n, std::vector<T>(first, last))){};\n\n    Node *alloc(uint\
    \ nl, uint nr, const std::vector<T> &v) {\n        if (nr - nl <= 1)\n       \
    \     return new Node(v[nl]);\n        else\n            return merge_node(alloc(nl,\
    \ (nl + nr) / 2, v),\n                              alloc((nl + nr) / 2, nr, v));\n\
    \    };\n\n    const T fold(uint l, uint r) const { return fold(l, r, 0, n, root);\
    \ };\n    const T fold(uint ql, uint qr, uint nl, uint nr, const Node *np) const\
    \ {\n        if (np == nullptr || qr <= nl || nr <= ql)\n            return Monoid::identity();\n\
    \        else if (ql <= nl && nr <= qr)\n            return np->dat;\n       \
    \ else\n            return Monoid::operation(fold(ql, qr, nl, (nl + nr) / 2, np->l),\n\
    \                                     fold(ql, qr, (nl + nr) / 2, nr, np->r));\n\
    \    };\n\n    PersistentSegmentTree update(uint idx, T d) { return set(idx, d);\
    \ };\n    PersistentSegmentTree set(uint idx, T d) {\n        return PersistentSegmentTree(n,\
    \ update(0, n, idx, d, root));\n    };\n    Node *update(uint nl, uint nr, uint\
    \ idx, T d, Node *np) {\n        if (idx < nl || nr <= idx)\n            return\
    \ np;\n        else if (nr - nl == 1)\n            return new Node(d);\n     \
    \   else\n            return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l),\n\
    \                              update((nl + nr) / 2, nr, idx, d, np->r));\n  \
    \  };\n\n    PersistentSegmentTree get_tree() { return *this; };\n\n    T operator[](uint\
    \ idx) { return fold(idx, idx + 1, 0, n, root); };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/persistent_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-04-17 00:51:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_sum1.test.cpp
  - test/aoj/1418.test.cpp
documentation_of: segment_tree/persistent_segment_tree.hpp
layout: document
redirect_from:
- /library/segment_tree/persistent_segment_tree.hpp
- /library/segment_tree/persistent_segment_tree.hpp.html
title: segment_tree/persistent_segment_tree.hpp
---
