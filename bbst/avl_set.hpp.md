---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/avl_set.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <iostream>\n#include <optional>\n\
    #include <utility>\n\n// insert/erase base AVLtree\n// multiset\ntemplate <class\
    \ T, class Compare = std::less<T>>\nstruct AVLSet {\n    struct Node {\n     \
    \   int sz, hi;\n        T dat;\n        Node *ch[2];\n        Node(T dat) : sz(1),\
    \ hi(1), dat(dat), ch{nullptr, nullptr} {};\n    };\n\n    Node *root;\n    const\
    \ Compare cmp;\n\n    AVLSet(const Compare &cmp = Compare()) : root(nullptr),\
    \ cmp(cmp){};\n    AVLSet(Node *r, Compare &cmp) : root(r), cmp(cmp){};\n    AVLSet(const\
    \ AVLSet &) = default;\n\n    int size(Node *u) {\n        if (u != nullptr)\n\
    \            return u->sz;\n        else\n            return 0;\n    };\n    int\
    \ size() { return size(root); };\n\n    int height(Node *u) {\n        if (u !=\
    \ nullptr)\n            return u->hi;\n        else\n            return 0;\n \
    \   };\n\n    template <int d>  // 0: left, 1: right\n    Node *rotate(Node *u)\
    \ {\n        assert(u != nullptr && u->ch[d] != nullptr);\n        Node *v = u->ch[d];\n\
    \        u->ch[d] = v->ch[d ^ 1];\n        v->ch[d ^ 1] = u;\n\n        recalc(u);\n\
    \        recalc(v);\n        return v;\n    };\n    int balance_factor(Node *u)\
    \ {\n        if (u == nullptr) return 0;\n        return height(u->ch[0]) - height(u->ch[1]);\n\
    \    };\n    Node *balance(Node *u) {\n        if (u == nullptr) return nullptr;\n\
    \        assert(-2 <= balance_factor(u) && balance_factor(u) <= 2);\n        if\
    \ (balance_factor(u) == 2) {\n            if (balance_factor(u->ch[0]) == -1)\
    \ u->ch[0] = rotate<1>(u->ch[0]);\n            u = rotate<0>(u);\n        } else\
    \ if (balance_factor(u) == -2) {\n            if (balance_factor(u->ch[1]) ==\
    \ 1) u->ch[1] = rotate<0>(u->ch[1]);\n            u = rotate<1>(u);\n        }\n\
    \        return u;\n    };\n    Node *recalc(Node *u) {\n        if (u == nullptr)\
    \ return nullptr;\n        u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;\n    \
    \    u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;\n        return\
    \ u;\n    };\n\n    void insert(T dat) {\n        Node *u = new Node(dat);\n \
    \       root = insert(root, u);\n    };\n    Node *insert(Node *u, Node *nv) {\n\
    \        if (u == nullptr) return nv;\n        if (cmp(u->dat, nv->dat))\n   \
    \         u->ch[1] = insert(u->ch[1], nv);\n        else\n            u->ch[0]\
    \ = insert(u->ch[0], nv);\n\n        return balance(recalc(u));\n    };\n\n  \
    \  void erase(T dat) { root = erase(root, dat); };\n    Node *erase(Node *u, const\
    \ T &dat) {\n        if (u == nullptr) return nullptr;\n        if (cmp(u->dat,\
    \ dat)) {\n            u->ch[1] = erase(u->ch[1], dat);\n        } else if (cmp(dat,\
    \ u->dat)) {\n            u->ch[0] = erase(u->ch[0], dat);\n        } else {\n\
    \            u = erase_node(u);\n        }\n        return balance(recalc(u));\n\
    \    };\n    Node *erase_node(Node *u) {\n        if (u->ch[0] == nullptr || u->ch[1]\
    \ == nullptr) {\n            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n\
    \            delete u;\n            return ret;\n        } else {\n          \
    \  auto dfs = [&](auto &&f, Node *v) -> Node * {\n                if (v->ch[1]\
    \ != nullptr) {\n                    v->ch[1] = f(f, v->ch[1]);\n            \
    \        return balance(recalc(v));\n                } else {\n              \
    \      std::swap(u->dat, v->dat);\n                    return erase_node(v);\n\
    \                }\n            };\n            u->ch[0] = dfs(dfs, u->ch[0]);\n\
    \            return balance(recalc(u));\n        }\n    };\n\n    bool contains(T\
    \ dat) {\n        Node *u = root;\n        while (u != nullptr) {\n          \
    \  if (cmp(dat, u->dat)) {\n                u = u->ch[0];\n            } else\
    \ if (cmp(u->dat, dat)) {\n                u = u->ch[1];\n            } else {\n\
    \                return true;\n            }\n        }\n        return false;\n\
    \    };\n\n    void dump() {\n        auto f = [](auto &&f, int d, Node *u) ->\
    \ void {\n            if (u == nullptr) return;\n            f(f, d + 1, u->ch[1]);\n\
    \            for (int i = 0; i < d; i++) {\n                std::cout << \"  \
    \    \";\n            }\n            std::cout << \"(\" << u->dat << \", \" <<\
    \ u->sz << \", \" << u->hi << \")\"\n                      << std::endl;\n   \
    \         f(f, d + 1, u->ch[0]);\n        };\n        f(f, 0, root);\n    };\n\
    \n    /*\n    std::optional<T> lower_bound(T x){};\n    std::optional<T> upper_bound(T\
    \ x){};\n\n    T find_Kth(int k);\n    int count(T x) { return size() - count_upper(x)\
    \ - count_lower(x); };\n    int count_lower(T x);\n    int count_upper(T x);\n\
    \    */\n};\n\n\n"
  code: "#ifndef AVL_SET\n#define AVL_SET\n\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <iostream>\n#include <optional>\n#include <utility>\n\
    \n// insert/erase base AVLtree\n// multiset\ntemplate <class T, class Compare\
    \ = std::less<T>>\nstruct AVLSet {\n    struct Node {\n        int sz, hi;\n \
    \       T dat;\n        Node *ch[2];\n        Node(T dat) : sz(1), hi(1), dat(dat),\
    \ ch{nullptr, nullptr} {};\n    };\n\n    Node *root;\n    const Compare cmp;\n\
    \n    AVLSet(const Compare &cmp = Compare()) : root(nullptr), cmp(cmp){};\n  \
    \  AVLSet(Node *r, Compare &cmp) : root(r), cmp(cmp){};\n    AVLSet(const AVLSet\
    \ &) = default;\n\n    int size(Node *u) {\n        if (u != nullptr)\n      \
    \      return u->sz;\n        else\n            return 0;\n    };\n    int size()\
    \ { return size(root); };\n\n    int height(Node *u) {\n        if (u != nullptr)\n\
    \            return u->hi;\n        else\n            return 0;\n    };\n\n  \
    \  template <int d>  // 0: left, 1: right\n    Node *rotate(Node *u) {\n     \
    \   assert(u != nullptr && u->ch[d] != nullptr);\n        Node *v = u->ch[d];\n\
    \        u->ch[d] = v->ch[d ^ 1];\n        v->ch[d ^ 1] = u;\n\n        recalc(u);\n\
    \        recalc(v);\n        return v;\n    };\n    int balance_factor(Node *u)\
    \ {\n        if (u == nullptr) return 0;\n        return height(u->ch[0]) - height(u->ch[1]);\n\
    \    };\n    Node *balance(Node *u) {\n        if (u == nullptr) return nullptr;\n\
    \        assert(-2 <= balance_factor(u) && balance_factor(u) <= 2);\n        if\
    \ (balance_factor(u) == 2) {\n            if (balance_factor(u->ch[0]) == -1)\
    \ u->ch[0] = rotate<1>(u->ch[0]);\n            u = rotate<0>(u);\n        } else\
    \ if (balance_factor(u) == -2) {\n            if (balance_factor(u->ch[1]) ==\
    \ 1) u->ch[1] = rotate<0>(u->ch[1]);\n            u = rotate<1>(u);\n        }\n\
    \        return u;\n    };\n    Node *recalc(Node *u) {\n        if (u == nullptr)\
    \ return nullptr;\n        u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;\n    \
    \    u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;\n        return\
    \ u;\n    };\n\n    void insert(T dat) {\n        Node *u = new Node(dat);\n \
    \       root = insert(root, u);\n    };\n    Node *insert(Node *u, Node *nv) {\n\
    \        if (u == nullptr) return nv;\n        if (cmp(u->dat, nv->dat))\n   \
    \         u->ch[1] = insert(u->ch[1], nv);\n        else\n            u->ch[0]\
    \ = insert(u->ch[0], nv);\n\n        return balance(recalc(u));\n    };\n\n  \
    \  void erase(T dat) { root = erase(root, dat); };\n    Node *erase(Node *u, const\
    \ T &dat) {\n        if (u == nullptr) return nullptr;\n        if (cmp(u->dat,\
    \ dat)) {\n            u->ch[1] = erase(u->ch[1], dat);\n        } else if (cmp(dat,\
    \ u->dat)) {\n            u->ch[0] = erase(u->ch[0], dat);\n        } else {\n\
    \            u = erase_node(u);\n        }\n        return balance(recalc(u));\n\
    \    };\n    Node *erase_node(Node *u) {\n        if (u->ch[0] == nullptr || u->ch[1]\
    \ == nullptr) {\n            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n\
    \            delete u;\n            return ret;\n        } else {\n          \
    \  auto dfs = [&](auto &&f, Node *v) -> Node * {\n                if (v->ch[1]\
    \ != nullptr) {\n                    v->ch[1] = f(f, v->ch[1]);\n            \
    \        return balance(recalc(v));\n                } else {\n              \
    \      std::swap(u->dat, v->dat);\n                    return erase_node(v);\n\
    \                }\n            };\n            u->ch[0] = dfs(dfs, u->ch[0]);\n\
    \            return balance(recalc(u));\n        }\n    };\n\n    bool contains(T\
    \ dat) {\n        Node *u = root;\n        while (u != nullptr) {\n          \
    \  if (cmp(dat, u->dat)) {\n                u = u->ch[0];\n            } else\
    \ if (cmp(u->dat, dat)) {\n                u = u->ch[1];\n            } else {\n\
    \                return true;\n            }\n        }\n        return false;\n\
    \    };\n\n    void dump() {\n        auto f = [](auto &&f, int d, Node *u) ->\
    \ void {\n            if (u == nullptr) return;\n            f(f, d + 1, u->ch[1]);\n\
    \            for (int i = 0; i < d; i++) {\n                std::cout << \"  \
    \    \";\n            }\n            std::cout << \"(\" << u->dat << \", \" <<\
    \ u->sz << \", \" << u->hi << \")\"\n                      << std::endl;\n   \
    \         f(f, d + 1, u->ch[0]);\n        };\n        f(f, 0, root);\n    };\n\
    \n    /*\n    std::optional<T> lower_bound(T x){};\n    std::optional<T> upper_bound(T\
    \ x){};\n\n    T find_Kth(int k);\n    int count(T x) { return size() - count_upper(x)\
    \ - count_lower(x); };\n    int count_lower(T x);\n    int count_upper(T x);\n\
    \    */\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bbst/avl_set.hpp
  requiredBy: []
  timestamp: '2021-08-27 00:26:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bbst/avl_set.hpp
layout: document
redirect_from:
- /library/bbst/avl_set.hpp
- /library/bbst/avl_set.hpp.html
title: bbst/avl_set.hpp
---
