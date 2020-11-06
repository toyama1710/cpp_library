---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/line_add_get_min2.test.cpp
    title: test/yosupo/line_add_get_min2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cht/dynamic_li_chao_tree.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n\ntemplate <class T, T lower, T upper>\nstruct DynamicLiChaoTree\
    \ {\n\n    struct Line {\n        T a, b;\n        T get(T x) {\n            return\
    \ a * x + b;\n        };\n        Line (T a, T b) : a(a), b(b) {};\n    };\n\n\
    \    struct Node {\n        Line x;\n        Node *l, *r;\n        Node (const\
    \ Node &u) : x(u.x), l(u.l), r(u.r) {};\n        Node (const Line &x) : x(x),\
    \ l(nullptr), r(nullptr) {};\n    };\n\n    Node *root;\n\n    DynamicLiChaoTree()\
    \ : root(nullptr) {};\n\n    void add_line(T a, T b) {\n        auto x = Line(a,\
    \ b);\n        root = update(root, x, lower, upper);\n    };\n\n    Node *update(Node\
    \ *u, Line &x, T lx, T rx) {\n        if (u == nullptr) return new Node(x);\n\
    \        if (x.get(lx) <= u->x.get(lx) && x.get(rx) <= u->x.get(rx)) {\n     \
    \       u->x = x;\n            return u;\n        }\n\n        // T mx = std::midpoint(lx,\
    \ rx);\n        T mx = (lx + rx) / 2;\n        if (x.get(mx) < u->x.get(mx)) std::swap(x,\
    \ u->x);\n        if (x.get(lx) < u->x.get(lx)) u->l = update(u->l, x, lx, mx);\n\
    \        else u->r = update(u->r, x, mx + 1, rx);\n\n        return u;\n    };\n\
    \n    T get(T x) {\n        return get(x, root, lower, upper);\n    };\n    T\
    \ get(T x, Node *u, T lx, T rx) {\n        if (u == nullptr) return std::numeric_limits<T>::max();\n\
    \n        T mx = (lx + rx) / 2;\n        if (x < mx) return std::min(u->x.get(x),\
    \ get(x, u->l, lx, mx));\n        else return std::min(u->x.get(x), get(x, u->r,\
    \ mx + 1, rx));\n    };\n};\n\n\n"
  code: "#ifndef DYNAMIC_LI_CHAO_TREE_H\n#define DYNAMIC_LI_CHAO_TREE_H\n\n#include\
    \ <algorithm>\n#include <limits>\n\ntemplate <class T, T lower, T upper>\nstruct\
    \ DynamicLiChaoTree {\n\n    struct Line {\n        T a, b;\n        T get(T x)\
    \ {\n            return a * x + b;\n        };\n        Line (T a, T b) : a(a),\
    \ b(b) {};\n    };\n\n    struct Node {\n        Line x;\n        Node *l, *r;\n\
    \        Node (const Node &u) : x(u.x), l(u.l), r(u.r) {};\n        Node (const\
    \ Line &x) : x(x), l(nullptr), r(nullptr) {};\n    };\n\n    Node *root;\n\n \
    \   DynamicLiChaoTree() : root(nullptr) {};\n\n    void add_line(T a, T b) {\n\
    \        auto x = Line(a, b);\n        root = update(root, x, lower, upper);\n\
    \    };\n\n    Node *update(Node *u, Line &x, T lx, T rx) {\n        if (u ==\
    \ nullptr) return new Node(x);\n        if (x.get(lx) <= u->x.get(lx) && x.get(rx)\
    \ <= u->x.get(rx)) {\n            u->x = x;\n            return u;\n        }\n\
    \n        // T mx = std::midpoint(lx, rx);\n        T mx = (lx + rx) / 2;\n  \
    \      if (x.get(mx) < u->x.get(mx)) std::swap(x, u->x);\n        if (x.get(lx)\
    \ < u->x.get(lx)) u->l = update(u->l, x, lx, mx);\n        else u->r = update(u->r,\
    \ x, mx + 1, rx);\n\n        return u;\n    };\n\n    T get(T x) {\n        return\
    \ get(x, root, lower, upper);\n    };\n    T get(T x, Node *u, T lx, T rx) {\n\
    \        if (u == nullptr) return std::numeric_limits<T>::max();\n\n        T\
    \ mx = (lx + rx) / 2;\n        if (x < mx) return std::min(u->x.get(x), get(x,\
    \ u->l, lx, mx));\n        else return std::min(u->x.get(x), get(x, u->r, mx +\
    \ 1, rx));\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: cht/dynamic_li_chao_tree.hpp
  requiredBy: []
  timestamp: '2020-07-31 08:58:53+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/line_add_get_min2.test.cpp
documentation_of: cht/dynamic_li_chao_tree.hpp
layout: document
redirect_from:
- /library/cht/dynamic_li_chao_tree.hpp
- /library/cht/dynamic_li_chao_tree.hpp.html
title: cht/dynamic_li_chao_tree.hpp
---
