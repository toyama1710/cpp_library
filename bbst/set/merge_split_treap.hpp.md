---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ARC033C_2.cpp
    title: test/atcoder/ARC033C_2.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3117_1.test.cpp
    title: test/aoj/3117_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3117_2.test.cpp
    title: test/aoj/3117_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/set/merge_split_treap.hpp\"\n\n\n\n#include <iostream>\n\
    #include <cstdint>\n#include <random>\n#include <functional>\n#include <cassert>\n\
    #include <memory>\n#include <utility>\n\n//===\ntemplate <class T, class Compare\
    \ = std::less<T>,\n         class A = std::allocator<T>>\nstruct Treap {\n   \
    \ using uint = uint_fast32_t;\n    using uint64 = uint_fast64_t;\n    struct Node;\n\
    \    using pn = std::pair<Node *, Node *>;\n    \n    struct Node {\n        T\
    \ dat;\n        uint64 p;\n\n        uint sz = 1;\n        Node *lch;\n      \
    \  Node *rch;\n\n        Node(T dat, uint64 p):\n            dat(dat), p(p), lch(nullptr),\
    \ rch(nullptr) {}\n    };\n    \n    Node *root;\n    const Compare cmp;\n   \
    \ std::mt19937 rnd;\n    \n    using Alloc = typename std::allocator_traits<A>::template\
    \ rebind_alloc<Node>;\n    using Traits = typename std::allocator_traits<Alloc>;\n\
    \    Alloc alc;\n    \n    Treap(const Compare &cmp = Compare()):\n        root(nullptr),\
    \ cmp(cmp), rnd(std::mt19937(std::random_device()())), alc() {};\n    \n    void\
    \ clear(Node *u) {\n        if (u == nullptr) return;\n        clear(u->lch);\n\
    \        clear(u->rch);\n        Traits::deallocate(alc, u, 1);\n    };\n    ~Treap()\
    \ {\n        clear(root);\n    };\n\n    int size() {\n        return size(root);\n\
    \    }\n    int size(Node *u) {\n        if (u == nullptr) return 0;\n       \
    \ else return u->sz;\n    };\n    void update(Node *u) {\n        u->sz = size(u->lch)\
    \ + size(u->rch) + 1;\n    };\n    Node *merge(Node *l, Node *r) {\n        if\
    \ (l == nullptr) return r;\n        if (r == nullptr) return l;\n\n        if\
    \ (l->p > r->p) {\n            l->rch = merge(l->rch, r);\n            update(l);\n\
    \            return l;\n        }\n        else {\n            r->lch = merge(l,\
    \ r->lch);\n            update(r);\n            return r;\n        }\n    };\n\
    \    pn split(Node *t, T dat) { // first->dat <= dat, dat < second->dat\n    \
    \    if (t == nullptr) return std::make_pair(nullptr, nullptr);\n        if (cmp(dat,\
    \ t->dat)) {\n            pn s = split(t->lch, dat);\n            t->lch = s.second;\n\
    \            update(t);\n            return std::make_pair(s.first, t);\n    \
    \    }\n        else {\n            pn s = split(t->rch, dat);\n            t->rch\
    \ = s.first;\n            update(t);\n            return std::make_pair(t, s.second);\n\
    \        }\n    };\n    \n    bool find(T dat) {\n        Node *u = root;\n  \
    \      while (u != nullptr && (cmp(u->dat, dat) || cmp(dat, u->dat))) {\n    \
    \        if (cmp(dat, u->dat)) u = u->lch;\n            else u = u->rch;\n   \
    \     }\n        return u != nullptr;\n    };\n\n    void insert(T dat) {\n  \
    \      Node *u = Traits::allocate(alc, 1);\n        Traits::construct(alc, u,\
    \ dat, (uint64)rnd());\n        pn t = split(root, dat);\n        root = merge(t.first,\
    \ merge(u, t.second));\n    };\n    void erase(T dat) {\n        assert(find(dat));\n\
    \        pn t = split(root, dat);\n        root = merge(erase_rightist(t.first),\
    \ t.second);\n    };\n    Node *erase_rightist(Node *u) {\n        if (u->rch\
    \ == nullptr) {\n            Node *ret = u->lch;\n            Traits::deallocate(alc,\
    \ u, 1);\n            return ret;\n        }\n        u->rch = erase_rightist(u->rch);\n\
    \        update(u);\n        return u;\n    }\n\n    int order_of(T x) { // 0-index\n\
    \        Node *u = root;\n        int k = 0;\n        while (u != nullptr && (cmp(u->dat,\
    \ x) || cmp(x, u->dat))) {\n            if (cmp(x, u->dat)) {\n              \
    \  u = u->lch;\n            }\n            else {\n                k = k + size(u->lch)\
    \ + 1;\n                u = u->rch;\n            }\n        }\n\n        if (u\
    \ == nullptr) return -1;\n        k += size(u->lch);\n        return k;\n    };\n\
    \    T find_Kth_element(uint k) { // 0-index\n        assert(k < size());\n  \
    \      assert(k >= 0);\n        \n        Node *u = root;\n        int idx = size(u->lch);\n\
    \        while (idx != k) {\n            if (idx > k) {\n                u = u->lch;\n\
    \                idx -= size(u->rch) + 1;\n            }\n            else {\n\
    \                u = u->rch;\n                idx += size(u->lch) + 1;\n     \
    \       }\n        }\n\n        return u->dat;\n    };\n};\n//===\n\n\n"
  code: "#ifndef SET_TREAP_HPP\n#define SET_TREAP_HPP\n\n#include <iostream>\n#include\
    \ <cstdint>\n#include <random>\n#include <functional>\n#include <cassert>\n#include\
    \ <memory>\n#include <utility>\n\n//===\ntemplate <class T, class Compare = std::less<T>,\n\
    \         class A = std::allocator<T>>\nstruct Treap {\n    using uint = uint_fast32_t;\n\
    \    using uint64 = uint_fast64_t;\n    struct Node;\n    using pn = std::pair<Node\
    \ *, Node *>;\n    \n    struct Node {\n        T dat;\n        uint64 p;\n\n\
    \        uint sz = 1;\n        Node *lch;\n        Node *rch;\n\n        Node(T\
    \ dat, uint64 p):\n            dat(dat), p(p), lch(nullptr), rch(nullptr) {}\n\
    \    };\n    \n    Node *root;\n    const Compare cmp;\n    std::mt19937 rnd;\n\
    \    \n    using Alloc = typename std::allocator_traits<A>::template rebind_alloc<Node>;\n\
    \    using Traits = typename std::allocator_traits<Alloc>;\n    Alloc alc;\n \
    \   \n    Treap(const Compare &cmp = Compare()):\n        root(nullptr), cmp(cmp),\
    \ rnd(std::mt19937(std::random_device()())), alc() {};\n    \n    void clear(Node\
    \ *u) {\n        if (u == nullptr) return;\n        clear(u->lch);\n        clear(u->rch);\n\
    \        Traits::deallocate(alc, u, 1);\n    };\n    ~Treap() {\n        clear(root);\n\
    \    };\n\n    int size() {\n        return size(root);\n    }\n    int size(Node\
    \ *u) {\n        if (u == nullptr) return 0;\n        else return u->sz;\n   \
    \ };\n    void update(Node *u) {\n        u->sz = size(u->lch) + size(u->rch)\
    \ + 1;\n    };\n    Node *merge(Node *l, Node *r) {\n        if (l == nullptr)\
    \ return r;\n        if (r == nullptr) return l;\n\n        if (l->p > r->p) {\n\
    \            l->rch = merge(l->rch, r);\n            update(l);\n            return\
    \ l;\n        }\n        else {\n            r->lch = merge(l, r->lch);\n    \
    \        update(r);\n            return r;\n        }\n    };\n    pn split(Node\
    \ *t, T dat) { // first->dat <= dat, dat < second->dat\n        if (t == nullptr)\
    \ return std::make_pair(nullptr, nullptr);\n        if (cmp(dat, t->dat)) {\n\
    \            pn s = split(t->lch, dat);\n            t->lch = s.second;\n    \
    \        update(t);\n            return std::make_pair(s.first, t);\n        }\n\
    \        else {\n            pn s = split(t->rch, dat);\n            t->rch =\
    \ s.first;\n            update(t);\n            return std::make_pair(t, s.second);\n\
    \        }\n    };\n    \n    bool find(T dat) {\n        Node *u = root;\n  \
    \      while (u != nullptr && (cmp(u->dat, dat) || cmp(dat, u->dat))) {\n    \
    \        if (cmp(dat, u->dat)) u = u->lch;\n            else u = u->rch;\n   \
    \     }\n        return u != nullptr;\n    };\n\n    void insert(T dat) {\n  \
    \      Node *u = Traits::allocate(alc, 1);\n        Traits::construct(alc, u,\
    \ dat, (uint64)rnd());\n        pn t = split(root, dat);\n        root = merge(t.first,\
    \ merge(u, t.second));\n    };\n    void erase(T dat) {\n        assert(find(dat));\n\
    \        pn t = split(root, dat);\n        root = merge(erase_rightist(t.first),\
    \ t.second);\n    };\n    Node *erase_rightist(Node *u) {\n        if (u->rch\
    \ == nullptr) {\n            Node *ret = u->lch;\n            Traits::deallocate(alc,\
    \ u, 1);\n            return ret;\n        }\n        u->rch = erase_rightist(u->rch);\n\
    \        update(u);\n        return u;\n    }\n\n    int order_of(T x) { // 0-index\n\
    \        Node *u = root;\n        int k = 0;\n        while (u != nullptr && (cmp(u->dat,\
    \ x) || cmp(x, u->dat))) {\n            if (cmp(x, u->dat)) {\n              \
    \  u = u->lch;\n            }\n            else {\n                k = k + size(u->lch)\
    \ + 1;\n                u = u->rch;\n            }\n        }\n\n        if (u\
    \ == nullptr) return -1;\n        k += size(u->lch);\n        return k;\n    };\n\
    \    T find_Kth_element(uint k) { // 0-index\n        assert(k < size());\n  \
    \      assert(k >= 0);\n        \n        Node *u = root;\n        int idx = size(u->lch);\n\
    \        while (idx != k) {\n            if (idx > k) {\n                u = u->lch;\n\
    \                idx -= size(u->rch) + 1;\n            }\n            else {\n\
    \                u = u->rch;\n                idx += size(u->lch) + 1;\n     \
    \       }\n        }\n\n        return u->dat;\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/set/merge_split_treap.hpp
  requiredBy:
  - test/atcoder/ARC033C_2.cpp
  timestamp: '2020-06-11 07:44:37+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3117_2.test.cpp
  - test/aoj/3117_1.test.cpp
documentation_of: bbst/set/merge_split_treap.hpp
layout: document
redirect_from:
- /library/bbst/set/merge_split_treap.hpp
- /library/bbst/set/merge_split_treap.hpp.html
title: bbst/set/merge_split_treap.hpp
---
