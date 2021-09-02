---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/avl_array.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <optional>\n#include <utility>\n\ntemplate <class Monoid>\n\
    struct AVLArray {\n    using M = Monoid;\n    using T = typename Monoid::value_type;\n\
    \    struct Node {\n        T val;\n        T sum;\n        int hi;\n        int\
    \ sz;\n        Node *ch[2];\n\n        Node(const T &val = M::identity())\n  \
    \          : val(val), sum(val), hi(1), sz(1), ch{nullptr, nullptr} {};\n    };\n\
    \n    Node *root;\n\n    explicit AVLArray(Node *root = nullptr) : root(root){};\n\
    \    AVLArray(const AVLArray &x) : root(x.root){};\n    AVLArray &operator=(const\
    \ AVLArray &x) {\n        root = x.root;\n        return *this;\n    };\n\n  \
    \  static int height(const Node *u) {\n        if (u == nullptr)\n           \
    \ return 0;\n        else\n            return u->hi;\n    };\n    static int balance_factor(const\
    \ Node *u) {\n        return height(u->ch[0]) - height(u->ch[1]);\n    };\n  \
    \  int size() { return size(root); };\n    static int size(const Node *u) {\n\
    \        if (u == nullptr)\n            return 0;\n        else\n            return\
    \ u->sz;\n    };\n    static T sum(const Node *u) {\n        if (u == nullptr)\n\
    \            return M::identity();\n        else\n            return u->sum;\n\
    \    };\n    static Node *recalc(Node *u) {\n        u->sz = size(u->ch[0]) +\
    \ size(u->ch[1]) + 1;\n        u->hi = std::max(height(u->ch[0]), height(u->ch[1]))\
    \ + 1;\n        u->sum =\n            M::operation(M::operation(sum(u->ch[0]),\
    \ u->val), sum(u->ch[1]));\n        return u;\n    };\n    template <int d>\n\
    \    static Node *rotate(Node *u) {\n        assert(u != nullptr && u->ch[d] !=\
    \ nullptr);\n        Node *v = u->ch[d];\n        u->ch[d] = v->ch[d ^ 1];\n \
    \       v->ch[d ^ 1] = u;\n        recalc(u);\n        recalc(v);\n        return\
    \ v;\n    };\n    static Node *balance(Node *u) {\n        if (u == nullptr) return\
    \ nullptr;\n        if (balance_factor(u) == 2) {\n            if (balance_factor(u->ch[0])\
    \ == -1) u->ch[0] = rotate<1>(u->ch[0]);\n            u = rotate<0>(u);\n    \
    \    } else if (balance_factor(u) == -2) {\n            if (balance_factor(u->ch[1])\
    \ == 1) u->ch[1] = rotate<0>(u->ch[1]);\n            u = rotate<1>(u);\n     \
    \   }\n        return u;\n    };\n    static std::pair<Node *, Node *> split_rightest_node(Node\
    \ *u) {\n        if (u->ch[1] != nullptr) {\n            auto [l, ret] = split_rightest_node(u->ch[1]);\n\
    \            u->ch[1] = l;\n            return {balance(recalc(u)), ret};\n  \
    \      } else {\n            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n\
    \            return {ret, u};\n        }\n    };\n\n    AVLArray &append(AVLArray\
    \ &r) {\n        root = merge(root, r.root);\n        r.root = nullptr;\n    \
    \    return *this;\n    };\n    static Node *merge(Node *l, Node *r) {\n     \
    \   if (l == nullptr) {\n            return r;\n        } else {\n           \
    \ auto [left, mid] = split_rightest_node(l);\n            return merge(mid, left,\
    \ r);\n        }\n    }\n    static Node *merge(Node *mid, Node *l, Node *r) {\n\
    \        if (abs(height(l) - height(r)) <= 2) {\n            mid->ch[0] = l;\n\
    \            mid->ch[1] = r;\n            return balance(recalc(mid));\n     \
    \   } else if (height(l) > height(r)) {\n            l->ch[1] = merge(mid, l->ch[1],\
    \ r);\n            return balance(recalc(l));\n        } else {\n            r->ch[0]\
    \ = merge(mid, l, r->ch[0]);\n            return balance(recalc(r));\n       \
    \ }\n    };\n\n    // first: [0, k), second: [k, n)\n    std::pair<AVLArray, AVLArray>\
    \ split_at(int k) {\n        assert(0 <= k && k <= size());\n        auto [l,\
    \ r] = split();\n        root = nullptr;\n        return {AVLArray(l), AVLArray(r)};\n\
    \    };\n    static std::pair<Node *, Node *> split(Node *u, int k) {\n      \
    \  if (u == nullptr) return {nullptr, nullptr};\n        Node *l = u->ch[0];\n\
    \        Node *r = u->ch[1];\n        u->ch[0] = u->ch[1] = nullptr;\n       \
    \ int lsize = size(l);\n        if (lsize == k) {\n            return {l, merge(recalc(u),\
    \ nullptr, r)};\n        } else if (k < lsize) {\n            auto [x, y] = split(l,\
    \ k);\n            return {x, merge(recalc(u), y, r)};\n        } else {\n   \
    \         auto [x, y] = split(r, k - lsize - 1);\n            return {merge(recalc(u),\
    \ l, x), y};\n        }\n    };\n\n    // sum [l, r)\n    T fold(int l, int r)\
    \ {\n        auto [tmp, right] = split(root, r);\n        auto [left, mid] = split(tmp,\
    \ l);\n        T ret = sum(mid);\n        root = merge(merge(left, mid), right);\n\
    \        return ret;\n    };\n\n    AVLArray &insert_at(int k, const T &dat) {\n\
    \        assert(0 <= k && k <= size());\n        Node *nv = new Node(dat);\n \
    \       auto [l, r] = split(root, k);\n        root = merge(nv, l, r);\n     \
    \   return *this;\n    };\n    AVLArray &update_at(int k, const T &dat) {\n  \
    \      assert(0 <= k && k < size());\n        auto [tmp, r] = split(root, k +\
    \ 1);\n        auto [l, mid] = split_rightest_node(tmp);\n        mid->val = dat;\n\
    \        root = merge(recalc(mid), l, r);\n        return *this;\n    };\n   \
    \ AVLArray &erase_at(int k) {\n        assert(0 <= k && k < size());\n       \
    \ auto [tmp, r] = split(root, k + 1);\n        auto [l, mid] = split_rightest_node(tmp);\n\
    \        delete mid;\n        root = merge(l, r);\n        return *this;\n   \
    \ };\n\n    AVLArray &rotate(int l, int mid, int r) {\n        auto [tmp1, right]\
    \ = split(root, r);\n        auto [tmp2, m2] = split(tmp1, mid);\n        auto\
    \ [left, m1] = split(tmp2, l);\n        root = merge(left, merge(m2, merge(m1,\
    \ right)));\n        return *this;\n    };\n\n    const T operator[](int k) {\
    \ return at(root, k); };\n    const T at(Node *u, int k) {\n        assert(0 <=\
    \ k && k < size(u));\n        if (size(u->ch[0]) == k)\n            return u->val;\n\
    \        else if (k < size(u->ch[0]))\n            return at(u->ch[0], k);\n \
    \       else\n            return at(u->ch[1], k - size(u->ch[0]) - 1);\n    };\n\
    };\n\n\n"
  code: "#ifndef AVL_ARRAY_HPP\n#define AVL_ARRAY_HPP\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <optional>\n#include <utility>\n\ntemplate <class Monoid>\n\
    struct AVLArray {\n    using M = Monoid;\n    using T = typename Monoid::value_type;\n\
    \    struct Node {\n        T val;\n        T sum;\n        int hi;\n        int\
    \ sz;\n        Node *ch[2];\n\n        Node(const T &val = M::identity())\n  \
    \          : val(val), sum(val), hi(1), sz(1), ch{nullptr, nullptr} {};\n    };\n\
    \n    Node *root;\n\n    explicit AVLArray(Node *root = nullptr) : root(root){};\n\
    \    AVLArray(const AVLArray &x) : root(x.root){};\n    AVLArray &operator=(const\
    \ AVLArray &x) {\n        root = x.root;\n        return *this;\n    };\n\n  \
    \  static int height(const Node *u) {\n        if (u == nullptr)\n           \
    \ return 0;\n        else\n            return u->hi;\n    };\n    static int balance_factor(const\
    \ Node *u) {\n        return height(u->ch[0]) - height(u->ch[1]);\n    };\n  \
    \  int size() { return size(root); };\n    static int size(const Node *u) {\n\
    \        if (u == nullptr)\n            return 0;\n        else\n            return\
    \ u->sz;\n    };\n    static T sum(const Node *u) {\n        if (u == nullptr)\n\
    \            return M::identity();\n        else\n            return u->sum;\n\
    \    };\n    static Node *recalc(Node *u) {\n        u->sz = size(u->ch[0]) +\
    \ size(u->ch[1]) + 1;\n        u->hi = std::max(height(u->ch[0]), height(u->ch[1]))\
    \ + 1;\n        u->sum =\n            M::operation(M::operation(sum(u->ch[0]),\
    \ u->val), sum(u->ch[1]));\n        return u;\n    };\n    template <int d>\n\
    \    static Node *rotate(Node *u) {\n        assert(u != nullptr && u->ch[d] !=\
    \ nullptr);\n        Node *v = u->ch[d];\n        u->ch[d] = v->ch[d ^ 1];\n \
    \       v->ch[d ^ 1] = u;\n        recalc(u);\n        recalc(v);\n        return\
    \ v;\n    };\n    static Node *balance(Node *u) {\n        if (u == nullptr) return\
    \ nullptr;\n        if (balance_factor(u) == 2) {\n            if (balance_factor(u->ch[0])\
    \ == -1) u->ch[0] = rotate<1>(u->ch[0]);\n            u = rotate<0>(u);\n    \
    \    } else if (balance_factor(u) == -2) {\n            if (balance_factor(u->ch[1])\
    \ == 1) u->ch[1] = rotate<0>(u->ch[1]);\n            u = rotate<1>(u);\n     \
    \   }\n        return u;\n    };\n    static std::pair<Node *, Node *> split_rightest_node(Node\
    \ *u) {\n        if (u->ch[1] != nullptr) {\n            auto [l, ret] = split_rightest_node(u->ch[1]);\n\
    \            u->ch[1] = l;\n            return {balance(recalc(u)), ret};\n  \
    \      } else {\n            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n\
    \            return {ret, u};\n        }\n    };\n\n    AVLArray &append(AVLArray\
    \ &r) {\n        root = merge(root, r.root);\n        r.root = nullptr;\n    \
    \    return *this;\n    };\n    static Node *merge(Node *l, Node *r) {\n     \
    \   if (l == nullptr) {\n            return r;\n        } else {\n           \
    \ auto [left, mid] = split_rightest_node(l);\n            return merge(mid, left,\
    \ r);\n        }\n    }\n    static Node *merge(Node *mid, Node *l, Node *r) {\n\
    \        if (abs(height(l) - height(r)) <= 2) {\n            mid->ch[0] = l;\n\
    \            mid->ch[1] = r;\n            return balance(recalc(mid));\n     \
    \   } else if (height(l) > height(r)) {\n            l->ch[1] = merge(mid, l->ch[1],\
    \ r);\n            return balance(recalc(l));\n        } else {\n            r->ch[0]\
    \ = merge(mid, l, r->ch[0]);\n            return balance(recalc(r));\n       \
    \ }\n    };\n\n    // first: [0, k), second: [k, n)\n    std::pair<AVLArray, AVLArray>\
    \ split_at(int k) {\n        assert(0 <= k && k <= size());\n        auto [l,\
    \ r] = split();\n        root = nullptr;\n        return {AVLArray(l), AVLArray(r)};\n\
    \    };\n    static std::pair<Node *, Node *> split(Node *u, int k) {\n      \
    \  if (u == nullptr) return {nullptr, nullptr};\n        Node *l = u->ch[0];\n\
    \        Node *r = u->ch[1];\n        u->ch[0] = u->ch[1] = nullptr;\n       \
    \ int lsize = size(l);\n        if (lsize == k) {\n            return {l, merge(recalc(u),\
    \ nullptr, r)};\n        } else if (k < lsize) {\n            auto [x, y] = split(l,\
    \ k);\n            return {x, merge(recalc(u), y, r)};\n        } else {\n   \
    \         auto [x, y] = split(r, k - lsize - 1);\n            return {merge(recalc(u),\
    \ l, x), y};\n        }\n    };\n\n    // sum [l, r)\n    T fold(int l, int r)\
    \ {\n        auto [tmp, right] = split(root, r);\n        auto [left, mid] = split(tmp,\
    \ l);\n        T ret = sum(mid);\n        root = merge(merge(left, mid), right);\n\
    \        return ret;\n    };\n\n    AVLArray &insert_at(int k, const T &dat) {\n\
    \        assert(0 <= k && k <= size());\n        Node *nv = new Node(dat);\n \
    \       auto [l, r] = split(root, k);\n        root = merge(nv, l, r);\n     \
    \   return *this;\n    };\n    AVLArray &update_at(int k, const T &dat) {\n  \
    \      assert(0 <= k && k < size());\n        auto [tmp, r] = split(root, k +\
    \ 1);\n        auto [l, mid] = split_rightest_node(tmp);\n        mid->val = dat;\n\
    \        root = merge(recalc(mid), l, r);\n        return *this;\n    };\n   \
    \ AVLArray &erase_at(int k) {\n        assert(0 <= k && k < size());\n       \
    \ auto [tmp, r] = split(root, k + 1);\n        auto [l, mid] = split_rightest_node(tmp);\n\
    \        delete mid;\n        root = merge(l, r);\n        return *this;\n   \
    \ };\n\n    AVLArray &rotate(int l, int mid, int r) {\n        auto [tmp1, right]\
    \ = split(root, r);\n        auto [tmp2, m2] = split(tmp1, mid);\n        auto\
    \ [left, m1] = split(tmp2, l);\n        root = merge(left, merge(m2, merge(m1,\
    \ right)));\n        return *this;\n    };\n\n    const T operator[](int k) {\
    \ return at(root, k); };\n    const T at(Node *u, int k) {\n        assert(0 <=\
    \ k && k < size(u));\n        if (size(u->ch[0]) == k)\n            return u->val;\n\
    \        else if (k < size(u->ch[0]))\n            return at(u->ch[0], k);\n \
    \       else\n            return at(u->ch[1], k - size(u->ch[0]) - 1);\n    };\n\
    };\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bbst/avl_array.hpp
  requiredBy: []
  timestamp: '2021-09-02 20:50:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_range_sum.test.cpp
  - test/aoj/1508.test.cpp
documentation_of: bbst/avl_array.hpp
layout: document
redirect_from:
- /library/bbst/avl_array.hpp
- /library/bbst/avl_array.hpp.html
title: bbst/avl_array.hpp
---
