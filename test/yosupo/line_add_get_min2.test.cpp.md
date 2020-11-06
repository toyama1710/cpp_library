---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cht/dynamic_li_chao_tree.hpp
    title: cht/dynamic_li_chao_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/line_add_get_min2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include <iostream>\n\
    #include <vector>\n#include <tuple>\n#include <algorithm>\n#line 1 \"cht/dynamic_li_chao_tree.hpp\"\
    \n\n\n\n#line 5 \"cht/dynamic_li_chao_tree.hpp\"\n#include <limits>\n\ntemplate\
    \ <class T, T lower, T upper>\nstruct DynamicLiChaoTree {\n\n    struct Line {\n\
    \        T a, b;\n        T get(T x) {\n            return a * x + b;\n      \
    \  };\n        Line (T a, T b) : a(a), b(b) {};\n    };\n\n    struct Node {\n\
    \        Line x;\n        Node *l, *r;\n        Node (const Node &u) : x(u.x),\
    \ l(u.l), r(u.r) {};\n        Node (const Line &x) : x(x), l(nullptr), r(nullptr)\
    \ {};\n    };\n\n    Node *root;\n\n    DynamicLiChaoTree() : root(nullptr) {};\n\
    \n    void add_line(T a, T b) {\n        auto x = Line(a, b);\n        root =\
    \ update(root, x, lower, upper);\n    };\n\n    Node *update(Node *u, Line &x,\
    \ T lx, T rx) {\n        if (u == nullptr) return new Node(x);\n        if (x.get(lx)\
    \ <= u->x.get(lx) && x.get(rx) <= u->x.get(rx)) {\n            u->x = x;\n   \
    \         return u;\n        }\n\n        // T mx = std::midpoint(lx, rx);\n \
    \       T mx = (lx + rx) / 2;\n        if (x.get(mx) < u->x.get(mx)) std::swap(x,\
    \ u->x);\n        if (x.get(lx) < u->x.get(lx)) u->l = update(u->l, x, lx, mx);\n\
    \        else u->r = update(u->r, x, mx + 1, rx);\n\n        return u;\n    };\n\
    \n    T get(T x) {\n        return get(x, root, lower, upper);\n    };\n    T\
    \ get(T x, Node *u, T lx, T rx) {\n        if (u == nullptr) return std::numeric_limits<T>::max();\n\
    \n        T mx = (lx + rx) / 2;\n        if (x < mx) return std::min(u->x.get(x),\
    \ get(x, u->l, lx, mx));\n        else return std::min(u->x.get(x), get(x, u->r,\
    \ mx + 1, rx));\n    };\n};\n\n\n#line 8 \"test/yosupo/line_add_get_min2.test.cpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nllong n, q;\n\nconst llong\
    \ INF = 1ll << 60ll;\nDynamicLiChaoTree<llong, -1 * INF, INF> cht;\n\nint main()\
    \ {\n    cin >> n >> q;\n    for (int i = 0; i < n; i++) {\n        llong a, b;\n\
    \        cin >> a >> b;\n        cht.add_line(a, b);\n    }\n\n    for (int i\
    \ = 0; i < q; i++) {\n        llong com, x, y;\n\n        cin >> com;\n      \
    \  if (com == 0) {\n            cin >> x >> y;\n            cht.add_line(x, y);\n\
    \        }\n        else {\n            cin >> x;\n            cout << cht.get(x)\
    \ << '\\n';\n        }\n    }\n\n    return 0;\n};\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <vector>\n#include <tuple>\n#include <algorithm>\n\
    #include \"../../cht/dynamic_li_chao_tree.hpp\"\n\nusing namespace std;\nusing\
    \ llong = long long;\n\nllong n, q;\n\nconst llong INF = 1ll << 60ll;\nDynamicLiChaoTree<llong,\
    \ -1 * INF, INF> cht;\n\nint main() {\n    cin >> n >> q;\n    for (int i = 0;\
    \ i < n; i++) {\n        llong a, b;\n        cin >> a >> b;\n        cht.add_line(a,\
    \ b);\n    }\n\n    for (int i = 0; i < q; i++) {\n        llong com, x, y;\n\n\
    \        cin >> com;\n        if (com == 0) {\n            cin >> x >> y;\n  \
    \          cht.add_line(x, y);\n        }\n        else {\n            cin >>\
    \ x;\n            cout << cht.get(x) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n};\n\n"
  dependsOn:
  - cht/dynamic_li_chao_tree.hpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min2.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 08:58:53+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min2.test.cpp
- /verify/test/yosupo/line_add_get_min2.test.cpp.html
title: test/yosupo/line_add_get_min2.test.cpp
---
