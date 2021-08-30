---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C.test.cpp
    title: test/aoj/ALDS1_9_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/associative_array.test.cpp
    title: test/yosupo/associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/avl_set.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <iostream>\n#include <optional>\n\
    #include <utility>\n\n// insert/erase base AVLtree\n// multiset\ntemplate <class\
    \ T>\nstruct AVLSet {\n    struct Node {\n        int sz, hi;\n        T dat;\n\
    \        Node *ch[2];\n        Node(T dat) : sz(1), hi(1), dat(dat), ch{nullptr,\
    \ nullptr} {};\n    };\n\n    Node *root;\n\n    AVLSet(Node *r = nullptr) : root(r){};\n\
    \    AVLSet(const AVLSet &x) : root(x.root){};\n    AVLSet &operator=(const AVLSet\
    \ &x) {\n        root = x.root;\n        return *this;\n    };\n\n    int size(Node\
    \ *u) {\n        if (u != nullptr)\n            return u->sz;\n        else\n\
    \            return 0;\n    };\n    int size() { return size(root); };\n\n   \
    \ int height(Node *u) {\n        if (u != nullptr)\n            return u->hi;\n\
    \        else\n            return 0;\n    };\n\n    template <int d>  // 0: left,\
    \ 1: right\n    Node *rotate(Node *u) {\n        assert(u != nullptr && u->ch[d]\
    \ != nullptr);\n        Node *v = u->ch[d];\n        u->ch[d] = v->ch[d ^ 1];\n\
    \        v->ch[d ^ 1] = u;\n        recalc(u);\n        recalc(v);\n        return\
    \ v;\n    };\n    int balance_factor(Node *u) {\n        if (u == nullptr) return\
    \ 0;\n        return height(u->ch[0]) - height(u->ch[1]);\n    };\n    Node *balance(Node\
    \ *u) {\n        if (u == nullptr) return nullptr;\n        assert(-2 <= balance_factor(u)\
    \ && balance_factor(u) <= 2);\n        if (balance_factor(u) == 2) {\n       \
    \     if (balance_factor(u->ch[0]) == -1) u->ch[0] = rotate<1>(u->ch[0]);\n  \
    \          u = rotate<0>(u);\n        } else if (balance_factor(u) == -2) {\n\
    \            if (balance_factor(u->ch[1]) == 1) u->ch[1] = rotate<0>(u->ch[1]);\n\
    \            u = rotate<1>(u);\n        }\n        return u;\n    };\n    Node\
    \ *recalc(Node *u) {\n        if (u == nullptr) return nullptr;\n        u->sz\
    \ = size(u->ch[0]) + size(u->ch[1]) + 1;\n        u->hi = std::max(height(u->ch[0]),\
    \ height(u->ch[1])) + 1;\n        return u;\n    };\n\n    void insert(T dat)\
    \ {\n        Node *u = new Node(dat);\n        root = insert(root, u);\n    };\n\
    \    Node *insert(Node *u, Node *nv) {\n        if (u == nullptr) return nv;\n\
    \        if (u->dat < nv->dat)\n            u->ch[1] = insert(u->ch[1], nv);\n\
    \        else\n            u->ch[0] = insert(u->ch[0], nv);\n\n        return\
    \ balance(recalc(u));\n    };\n\n    void erase(const T &dat) { root = erase(root,\
    \ dat); };\n    Node *erase(Node *u, const T &dat) {\n        if (u == nullptr)\
    \ return nullptr;\n        if (u->dat < dat) {\n            u->ch[1] = erase(u->ch[1],\
    \ dat);\n        } else if (dat < u->dat) {\n            u->ch[0] = erase(u->ch[0],\
    \ dat);\n        } else {\n            Node *del = u;\n            u = isolate_node(u);\n\
    \            delete del;\n        }\n        return balance(recalc(u));\n    };\n\
    \    Node *isolate_node(Node *u) {\n        if (u->ch[0] == nullptr || u->ch[1]\
    \ == nullptr) {\n            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n\
    \            return ret;\n        } else {\n            Node *l = isolate_node(&u,\
    \ u->ch[0]);\n            u->ch[0] = l;\n            return balance(recalc(u));\n\
    \        }\n    };\n    Node *isolate_node(Node **dst, Node *v) {\n        if\
    \ (v->ch[1] != nullptr) {\n            v->ch[1] = isolate_node(dst, v->ch[1]);\n\
    \            return balance(recalc(v));\n        } else {\n            std::swap((*dst)->ch[0],\
    \ v->ch[0]);\n            std::swap((*dst)->ch[1], v->ch[1]);\n            std::swap(*dst,\
    \ v);\n            return isolate_node(v);\n        }\n    };\n\n    bool contains(T\
    \ dat) {\n        Node *u = root;\n        while (u != nullptr) {\n          \
    \  if (dat < u->dat) {\n                u = u->ch[0];\n            } else if (u->dat\
    \ < dat) {\n                u = u->ch[1];\n            } else {\n            \
    \    return true;\n            }\n        }\n        return false;\n    };\n\n\
    \    std::optional<T> lower_bound(const T &x) { return lower_bound(root, x); };\n\
    \    std::optional<T> lower_bound(Node *u, const T &x) {\n        if (u == nullptr)\
    \ return std::nullopt;\n        if (u->dat < x) {\n            return lower_bound(u->ch[1],\
    \ x);\n        } else {\n            auto ret = lower_bound(u->ch[0], x);\n  \
    \          if (ret)\n                return ret;\n            else\n         \
    \       return u->dat;\n        }\n    };\n    std::optional<T> upper_bound(const\
    \ T &x) { return upper_bound(root, x); };\n    std::optional<T> upper_bound(Node\
    \ *u, const T &x) {\n        if (u == nullptr) return std::nullopt;\n        if\
    \ (x < u->dat) {\n            auto ret = upper_bound(u->ch[0], x);\n         \
    \   if (ret)\n                return ret;\n            else\n                return\
    \ u->dat;\n        } else {\n            return upper_bound(u->ch[1], x);\n  \
    \      }\n    };\n\n    // 0-indexed\n    std::optional<T> find_Kth(int k) {\n\
    \        if (size() <= k || k < 0)\n            return std::nullopt;\n       \
    \ else\n            return find_Kth(root, k)->dat;\n    };\n    Node *find_Kth(Node\
    \ *u, int k) {\n        if (size(u->ch[0]) == k)\n            return u;\n    \
    \    else if (size(u->ch[0]) > k)\n            return find_Kth(u->ch[0], k);\n\
    \        else\n            return find_Kth(u->ch[1], k - size(u->ch[0]) - 1);\n\
    \    };\n\n    int count(const T &x) { return size() - count_upper(x) - count_lower(x);\
    \ };\n    int count_lower(const T &x) { return count_lower(x, root); };\n    int\
    \ count_lower(const T &x, Node *u) {\n        if (u == nullptr) return 0;\n  \
    \      if (u->dat < x)\n            return count_lower(x, u->ch[1]) + size(u->ch[0])\
    \ + 1;\n        else\n            return count_lower(x, u->ch[0]);\n    };\n \
    \   int count_upper(const T &x) { return count_upper(x, root); };\n    int count_upper(const\
    \ T &x, Node *u) {\n        if (u == nullptr) return 0;\n        if (x < u->dat)\n\
    \            return count_upper(x, u->ch[0]) + size(u->ch[1]) + 1;\n        else\n\
    \            return count_upper(x, u->ch[1]);\n    };\n\n    AVLSet merge_with(AVLSet\
    \ r) {\n        if (size() == 0) {\n            root = r.root;\n        } else\
    \ if (r.size() > 0) {\n            Node dummy = *root;\n            root = merge(&dummy,\
    \ root, r.root);\n        }\n        return *this;\n    };\n    Node *merge(Node\
    \ *dummy, Node *l, Node *r) {\n        if (abs(height(l) - height(r)) <= 2) {\n\
    \            dummy->ch[0] = l;\n            dummy->ch[1] = r;\n            return\
    \ isolate_node(dummy);\n        } else if (height(l) > height(r)) {\n        \
    \    l->ch[1] = merge(dummy, l->ch[1], r);\n            return balance(recalc(l));\n\
    \        } else {\n            r->ch[0] = merge(dummy, l, r->ch[0]);\n       \
    \     return balance(recalc(r));\n        }\n    };\n\n    std::pair<AVLSet, AVLSet>\
    \ split(int k) {\n        assert(k > 0 && k <= size());\n        auto [l, r] =\
    \ split(root, k);\n        root = nullptr;\n        return {AVLSet(l), AVLSet(r)};\n\
    \    };\n    std::pair<Node *, Node *> split(Node *u, int k) {\n        int lsize\
    \ = size(u->ch[0]);\n        if (lsize == k) {\n            Node *l = u->ch[0];\n\
    \            u->ch[0] = u->ch[1] = nullptr;\n            return {l, insert(u->ch[1],\
    \ balance(recalc(u)))};\n        } else if (lsize > k) {\n            auto [x,\
    \ y] = split(u->ch[0], k);\n            u->ch[0] = y;\n            return {x,\
    \ balance((recalc(u)))};\n        } else {\n            auto [x, y] = split(u->ch[1],\
    \ k - size(u->ch[0]) - 1);\n            u->ch[1] = x;\n            return {balance(recalc(u)),\
    \ y};\n        }\n    };\n\n    void dump() {\n        auto f = [](auto &&f, int\
    \ d, Node *u) -> void {\n            if (u == nullptr) return;\n            f(f,\
    \ d + 1, u->ch[1]);\n            for (int i = 0; i < d; i++) {\n             \
    \   std::cout << \"      \";\n            }\n            std::cout << \"(\" <<\
    \ u->dat << \", \" << u->sz << \", \" << u->hi << \")\"\n                    \
    \  << std::endl;\n            f(f, d + 1, u->ch[0]);\n        };\n        f(f,\
    \ 0, root);\n    };\n};\n\n\n"
  code: "#ifndef AVL_SET\n#define AVL_SET\n\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <iostream>\n#include <optional>\n#include <utility>\n\
    \n// insert/erase base AVLtree\n// multiset\ntemplate <class T>\nstruct AVLSet\
    \ {\n    struct Node {\n        int sz, hi;\n        T dat;\n        Node *ch[2];\n\
    \        Node(T dat) : sz(1), hi(1), dat(dat), ch{nullptr, nullptr} {};\n    };\n\
    \n    Node *root;\n\n    AVLSet(Node *r = nullptr) : root(r){};\n    AVLSet(const\
    \ AVLSet &x) : root(x.root){};\n    AVLSet &operator=(const AVLSet &x) {\n   \
    \     root = x.root;\n        return *this;\n    };\n\n    int size(Node *u) {\n\
    \        if (u != nullptr)\n            return u->sz;\n        else\n        \
    \    return 0;\n    };\n    int size() { return size(root); };\n\n    int height(Node\
    \ *u) {\n        if (u != nullptr)\n            return u->hi;\n        else\n\
    \            return 0;\n    };\n\n    template <int d>  // 0: left, 1: right\n\
    \    Node *rotate(Node *u) {\n        assert(u != nullptr && u->ch[d] != nullptr);\n\
    \        Node *v = u->ch[d];\n        u->ch[d] = v->ch[d ^ 1];\n        v->ch[d\
    \ ^ 1] = u;\n        recalc(u);\n        recalc(v);\n        return v;\n    };\n\
    \    int balance_factor(Node *u) {\n        if (u == nullptr) return 0;\n    \
    \    return height(u->ch[0]) - height(u->ch[1]);\n    };\n    Node *balance(Node\
    \ *u) {\n        if (u == nullptr) return nullptr;\n        assert(-2 <= balance_factor(u)\
    \ && balance_factor(u) <= 2);\n        if (balance_factor(u) == 2) {\n       \
    \     if (balance_factor(u->ch[0]) == -1) u->ch[0] = rotate<1>(u->ch[0]);\n  \
    \          u = rotate<0>(u);\n        } else if (balance_factor(u) == -2) {\n\
    \            if (balance_factor(u->ch[1]) == 1) u->ch[1] = rotate<0>(u->ch[1]);\n\
    \            u = rotate<1>(u);\n        }\n        return u;\n    };\n    Node\
    \ *recalc(Node *u) {\n        if (u == nullptr) return nullptr;\n        u->sz\
    \ = size(u->ch[0]) + size(u->ch[1]) + 1;\n        u->hi = std::max(height(u->ch[0]),\
    \ height(u->ch[1])) + 1;\n        return u;\n    };\n\n    void insert(T dat)\
    \ {\n        Node *u = new Node(dat);\n        root = insert(root, u);\n    };\n\
    \    Node *insert(Node *u, Node *nv) {\n        if (u == nullptr) return nv;\n\
    \        if (u->dat < nv->dat)\n            u->ch[1] = insert(u->ch[1], nv);\n\
    \        else\n            u->ch[0] = insert(u->ch[0], nv);\n\n        return\
    \ balance(recalc(u));\n    };\n\n    void erase(const T &dat) { root = erase(root,\
    \ dat); };\n    Node *erase(Node *u, const T &dat) {\n        if (u == nullptr)\
    \ return nullptr;\n        if (u->dat < dat) {\n            u->ch[1] = erase(u->ch[1],\
    \ dat);\n        } else if (dat < u->dat) {\n            u->ch[0] = erase(u->ch[0],\
    \ dat);\n        } else {\n            Node *del = u;\n            u = isolate_node(u);\n\
    \            delete del;\n        }\n        return balance(recalc(u));\n    };\n\
    \    Node *isolate_node(Node *u) {\n        if (u->ch[0] == nullptr || u->ch[1]\
    \ == nullptr) {\n            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n\
    \            return ret;\n        } else {\n            Node *l = isolate_node(&u,\
    \ u->ch[0]);\n            u->ch[0] = l;\n            return balance(recalc(u));\n\
    \        }\n    };\n    Node *isolate_node(Node **dst, Node *v) {\n        if\
    \ (v->ch[1] != nullptr) {\n            v->ch[1] = isolate_node(dst, v->ch[1]);\n\
    \            return balance(recalc(v));\n        } else {\n            std::swap((*dst)->ch[0],\
    \ v->ch[0]);\n            std::swap((*dst)->ch[1], v->ch[1]);\n            std::swap(*dst,\
    \ v);\n            return isolate_node(v);\n        }\n    };\n\n    bool contains(T\
    \ dat) {\n        Node *u = root;\n        while (u != nullptr) {\n          \
    \  if (dat < u->dat) {\n                u = u->ch[0];\n            } else if (u->dat\
    \ < dat) {\n                u = u->ch[1];\n            } else {\n            \
    \    return true;\n            }\n        }\n        return false;\n    };\n\n\
    \    std::optional<T> lower_bound(const T &x) { return lower_bound(root, x); };\n\
    \    std::optional<T> lower_bound(Node *u, const T &x) {\n        if (u == nullptr)\
    \ return std::nullopt;\n        if (u->dat < x) {\n            return lower_bound(u->ch[1],\
    \ x);\n        } else {\n            auto ret = lower_bound(u->ch[0], x);\n  \
    \          if (ret)\n                return ret;\n            else\n         \
    \       return u->dat;\n        }\n    };\n    std::optional<T> upper_bound(const\
    \ T &x) { return upper_bound(root, x); };\n    std::optional<T> upper_bound(Node\
    \ *u, const T &x) {\n        if (u == nullptr) return std::nullopt;\n        if\
    \ (x < u->dat) {\n            auto ret = upper_bound(u->ch[0], x);\n         \
    \   if (ret)\n                return ret;\n            else\n                return\
    \ u->dat;\n        } else {\n            return upper_bound(u->ch[1], x);\n  \
    \      }\n    };\n\n    // 0-indexed\n    std::optional<T> find_Kth(int k) {\n\
    \        if (size() <= k || k < 0)\n            return std::nullopt;\n       \
    \ else\n            return find_Kth(root, k)->dat;\n    };\n    Node *find_Kth(Node\
    \ *u, int k) {\n        if (size(u->ch[0]) == k)\n            return u;\n    \
    \    else if (size(u->ch[0]) > k)\n            return find_Kth(u->ch[0], k);\n\
    \        else\n            return find_Kth(u->ch[1], k - size(u->ch[0]) - 1);\n\
    \    };\n\n    int count(const T &x) { return size() - count_upper(x) - count_lower(x);\
    \ };\n    int count_lower(const T &x) { return count_lower(x, root); };\n    int\
    \ count_lower(const T &x, Node *u) {\n        if (u == nullptr) return 0;\n  \
    \      if (u->dat < x)\n            return count_lower(x, u->ch[1]) + size(u->ch[0])\
    \ + 1;\n        else\n            return count_lower(x, u->ch[0]);\n    };\n \
    \   int count_upper(const T &x) { return count_upper(x, root); };\n    int count_upper(const\
    \ T &x, Node *u) {\n        if (u == nullptr) return 0;\n        if (x < u->dat)\n\
    \            return count_upper(x, u->ch[0]) + size(u->ch[1]) + 1;\n        else\n\
    \            return count_upper(x, u->ch[1]);\n    };\n\n    AVLSet merge_with(AVLSet\
    \ r) {\n        if (size() == 0) {\n            root = r.root;\n        } else\
    \ if (r.size() > 0) {\n            Node dummy = *root;\n            root = merge(&dummy,\
    \ root, r.root);\n        }\n        return *this;\n    };\n    Node *merge(Node\
    \ *dummy, Node *l, Node *r) {\n        if (abs(height(l) - height(r)) <= 2) {\n\
    \            dummy->ch[0] = l;\n            dummy->ch[1] = r;\n            return\
    \ isolate_node(dummy);\n        } else if (height(l) > height(r)) {\n        \
    \    l->ch[1] = merge(dummy, l->ch[1], r);\n            return balance(recalc(l));\n\
    \        } else {\n            r->ch[0] = merge(dummy, l, r->ch[0]);\n       \
    \     return balance(recalc(r));\n        }\n    };\n\n    std::pair<AVLSet, AVLSet>\
    \ split(int k) {\n        assert(k > 0 && k <= size());\n        auto [l, r] =\
    \ split(root, k);\n        root = nullptr;\n        return {AVLSet(l), AVLSet(r)};\n\
    \    };\n    std::pair<Node *, Node *> split(Node *u, int k) {\n        int lsize\
    \ = size(u->ch[0]);\n        if (lsize == k) {\n            Node *l = u->ch[0];\n\
    \            u->ch[0] = u->ch[1] = nullptr;\n            return {l, insert(u->ch[1],\
    \ balance(recalc(u)))};\n        } else if (lsize > k) {\n            auto [x,\
    \ y] = split(u->ch[0], k);\n            u->ch[0] = y;\n            return {x,\
    \ balance((recalc(u)))};\n        } else {\n            auto [x, y] = split(u->ch[1],\
    \ k - size(u->ch[0]) - 1);\n            u->ch[1] = x;\n            return {balance(recalc(u)),\
    \ y};\n        }\n    };\n\n    void dump() {\n        auto f = [](auto &&f, int\
    \ d, Node *u) -> void {\n            if (u == nullptr) return;\n            f(f,\
    \ d + 1, u->ch[1]);\n            for (int i = 0; i < d; i++) {\n             \
    \   std::cout << \"      \";\n            }\n            std::cout << \"(\" <<\
    \ u->dat << \", \" << u->sz << \", \" << u->hi << \")\"\n                    \
    \  << std::endl;\n            f(f, d + 1, u->ch[0]);\n        };\n        f(f,\
    \ 0, root);\n    };\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bbst/avl_set.hpp
  requiredBy: []
  timestamp: '2021-08-30 13:49:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/associative_array.test.cpp
  - test/aoj/0343.test.cpp
  - test/aoj/ALDS1_9_C.test.cpp
documentation_of: bbst/avl_set.hpp
layout: document
redirect_from:
- /library/bbst/avl_set.hpp
- /library/bbst/avl_set.hpp.html
title: bbst/avl_set.hpp
---
