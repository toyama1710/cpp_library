---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/avl_set.hpp
    title: bbst/avl_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_9_C_AVLset.test.cpp\"\n#define PROBLEM \\\
    \n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\n\
    \n#include <iostream>\n#include <queue>\n#include <string>\n#include <tuple>\n\
    \n#line 1 \"bbst/avl_set.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #line 7 \"bbst/avl_set.hpp\"\n#include <optional>\n#include <utility>\n#include\
    \ <vector>\n\n// insert/erase base AVLtree\n// multiset\ntemplate <class T>\n\
    struct AVLSet {\n    struct Node {\n        int sz, hi;\n        T dat;\n    \
    \    Node *ch[2];\n        Node(const Node *x)\n            : sz(x->sz), hi(x->hi),\
    \ dat(x->dat), ch{x->ch[0], x->ch[1]} {};\n        Node(T dat) : sz(1), hi(1),\
    \ dat(dat), ch{nullptr, nullptr} {};\n    };\n\n    Node *root;\n\n    AVLSet(Node\
    \ *r = nullptr) : root(r){};\n    AVLSet(const AVLSet &x) : root(x.root){};\n\n\
    \    AVLSet &operator=(const AVLSet &x) {\n        root = x.root;\n        return\
    \ *this;\n    };\n\n    int size() const {\n        return size(root);\n    };\n\
    \n    static int size(Node *u) {\n        if (u != nullptr)\n            return\
    \ u->sz;\n        else\n            return 0;\n    };\n\n    static int height(Node\
    \ *u) {\n        if (u != nullptr)\n            return u->hi;\n        else\n\
    \            return 0;\n    };\n\n    template <int d>  // 0: left, 1: right\n\
    \    static Node *rotate(Node *u) {\n        assert(u != nullptr && u->ch[d] !=\
    \ nullptr);\n        Node *v = u->ch[d];\n        u->ch[d] = v->ch[d ^ 1];\n \
    \       v->ch[d ^ 1] = u;\n        recalc(u);\n        recalc(v);\n        return\
    \ v;\n    };\n\n    static int balance_factor(Node *u) {\n        if (u == nullptr)\
    \ return 0;\n        return height(u->ch[0]) - height(u->ch[1]);\n    };\n\n \
    \   static Node *balance(Node *u) {\n        if (u == nullptr) return nullptr;\n\
    \        assert(-2 <= balance_factor(u) && balance_factor(u) <= 2);\n        if\
    \ (balance_factor(u) == 2) {\n            if (balance_factor(u->ch[0]) == -1)\
    \ u->ch[0] = rotate<1>(u->ch[0]);\n            u = rotate<0>(u);\n        } else\
    \ if (balance_factor(u) == -2) {\n            if (balance_factor(u->ch[1]) ==\
    \ 1) u->ch[1] = rotate<0>(u->ch[1]);\n            u = rotate<1>(u);\n        }\n\
    \        return u;\n    };\n\n    static Node *recalc(Node *u) {\n        if (u\
    \ == nullptr) return nullptr;\n        u->sz = size(u->ch[0]) + size(u->ch[1])\
    \ + 1;\n        u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;\n  \
    \      return u;\n    };\n\n    AVLSet &insert(const T &dat) {\n        Node *u\
    \ = new Node(dat);\n        root = insert(root, u);\n        return *this;\n \
    \   };\n\n    Node *insert(Node *u, Node *nv) {\n        if (u == nullptr) return\
    \ nv;\n        if (u->dat < nv->dat)\n            u->ch[1] = insert(u->ch[1],\
    \ nv);\n        else\n            u->ch[0] = insert(u->ch[0], nv);\n\n       \
    \ return balance(recalc(u));\n    };\n\n    AVLSet &erase(const T &dat) {\n  \
    \      root = erase(root, dat);\n        return *this;\n    };\n\n    Node *erase(Node\
    \ *u, const T &dat) {\n        if (u == nullptr) return nullptr;\n        if (u->dat\
    \ < dat) {\n            u->ch[1] = erase(u->ch[1], dat);\n        } else if (dat\
    \ < u->dat) {\n            u->ch[0] = erase(u->ch[0], dat);\n        } else {\n\
    \            Node *del = u;\n            u = isolate_node(u);\n            delete\
    \ del;\n        }\n        return balance(recalc(u));\n    };\n\n    Node *isolate_node(Node\
    \ *u) {\n        if (u->ch[0] == nullptr || u->ch[1] == nullptr) {\n         \
    \   Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n            return\
    \ ret;\n        } else {\n            auto [l, nv] = split_rightest_node(u->ch[0]);\n\
    \            nv->ch[0] = l;\n            nv->ch[1] = u->ch[1];\n            return\
    \ balance(recalc(nv));\n        }\n    };\n\n    std::pair<Node *, Node *> split_rightest_node(Node\
    \ *v) {\n        if (v->ch[1] != nullptr) {\n            auto [l, ret] = split_rightest_node(v->ch[1]);\n\
    \            v->ch[1] = l;\n            return {balance(recalc(v)), ret};\n  \
    \      } else {\n            return {isolate_node(v), v};\n        }\n    };\n\
    \n    bool contains(const T &dat) const {\n        Node *u = root;\n        while\
    \ (u != nullptr) {\n            if (dat < u->dat) {\n                u = u->ch[0];\n\
    \            } else if (u->dat < dat) {\n                u = u->ch[1];\n     \
    \       } else {\n                return true;\n            }\n        }\n   \
    \     return false;\n    };\n\n    std::optional<T> lower_bound(const T &x) const\
    \ {\n        return lower_bound(root, x);\n    };\n\n    std::optional<T> lower_bound(Node\
    \ *u, const T &x) const {\n        if (u == nullptr) return std::nullopt;\n  \
    \      if (u->dat < x) {\n            return lower_bound(u->ch[1], x);\n     \
    \   } else {\n            auto ret = lower_bound(u->ch[0], x);\n            if\
    \ (ret)\n                return ret;\n            else\n                return\
    \ u->dat;\n        }\n    };\n\n    std::optional<T> upper_bound(const T &x) const\
    \ {\n        return upper_bound(root, x);\n    };\n\n    std::optional<T> upper_bound(Node\
    \ *u, const T &x) const {\n        if (u == nullptr) return std::nullopt;\n  \
    \      if (x < u->dat) {\n            auto ret = upper_bound(u->ch[0], x);\n \
    \           if (ret)\n                return ret;\n            else\n        \
    \        return u->dat;\n        } else {\n            return upper_bound(u->ch[1],\
    \ x);\n        }\n    };\n\n    // 0-indexed\n    std::optional<T> find_Kth(int\
    \ k) const {\n        if (size() <= k || k < 0)\n            return std::nullopt;\n\
    \        else\n            return find_Kth(root, k)->dat;\n    };\n\n    Node\
    \ *find_Kth(Node *u, int k) const {\n        if (size(u->ch[0]) == k)\n      \
    \      return u;\n        else if (size(u->ch[0]) > k)\n            return find_Kth(u->ch[0],\
    \ k);\n        else\n            return find_Kth(u->ch[1], k - size(u->ch[0])\
    \ - 1);\n    };\n\n    int count(const T &x) const {\n        return size() -\
    \ count_upper(x) - count_lower(x);\n    };\n\n    int count_lower(const T &x)\
    \ const {\n        return count_lower(x, root);\n    };\n\n    int count_lower(const\
    \ T &x, Node *u) const {\n        if (u == nullptr) return 0;\n        if (u->dat\
    \ < x)\n            return count_lower(x, u->ch[1]) + size(u->ch[0]) + 1;\n  \
    \      else\n            return count_lower(x, u->ch[0]);\n    };\n\n    int count_upper(const\
    \ T &x) const {\n        return count_upper(x, root);\n    };\n\n    int count_upper(const\
    \ T &x, Node *u) const {\n        if (u == nullptr) return 0;\n        if (x <\
    \ u->dat)\n            return count_upper(x, u->ch[0]) + size(u->ch[1]) + 1;\n\
    \        else\n            return count_upper(x, u->ch[1]);\n    };\n\n    AVLSet\
    \ &merge_with(AVLSet &r) {\n        if (r.size() == 0) {\n            return *this;\n\
    \        } else if (size() == 0) {\n            root = r.root;\n        } else\
    \ {\n            auto [l, tmp] = split_rightest_node(root);\n            root\
    \ = merge(tmp, l, r.root);\n            r.root = nullptr;\n        }\n       \
    \ return *this;\n    };\n\n    Node *merge(Node *root, Node *l, Node *r) {\n \
    \       if (abs(height(l) - height(r)) <= 2) {\n            root->ch[0] = l;\n\
    \            root->ch[1] = r;\n            return balance(recalc(root));\n   \
    \     } else if (height(l) > height(r)) {\n            l->ch[1] = merge(root,\
    \ l->ch[1], r);\n            return balance(recalc(l));\n        } else {\n  \
    \          r->ch[0] = merge(root, l, r->ch[0]);\n            return balance(recalc(r));\n\
    \        }\n    };\n\n    std::pair<AVLSet, AVLSet> split(int k) {\n        assert(k\
    \ >= 0 && k <= size());\n        auto [l, r] = split(root, k);\n        root =\
    \ nullptr;\n        return {AVLSet(l), AVLSet(r)};\n    };\n\n    std::pair<Node\
    \ *, Node *> split(Node *u, int k) {\n        if (u == nullptr) return {nullptr,\
    \ nullptr};\n        int lsize = size(u->ch[0]);\n        Node *l = u->ch[0];\n\
    \        Node *r = u->ch[1];\n        u->ch[0] = u->ch[1] = nullptr;\n       \
    \ if (lsize == k) {\n            return {l, insert(r, recalc(u))};\n        }\
    \ else if (k < lsize) {\n            auto [x, y] = split(l, k);\n            return\
    \ {x, merge(recalc(u), y, r)};\n        } else {\n            auto [x, y] = split(r,\
    \ k - lsize - 1);\n            return {merge(recalc(u), l, x), y};\n        }\n\
    \    };\n\n    std::vector<T> list() const {\n        std::vector<T> ret;\n  \
    \      ret.reserve(size());\n        auto dfs = [&](Node *u, auto &&f) {\n   \
    \         if (u == nullptr) return;\n            f(u->ch[0], f);\n           \
    \ ret.emplace_back(u->dat);\n            f(u->ch[1], f);\n        };\n       \
    \ dfs(root, dfs);\n        return ret;\n    };\n\n    void dump() const {\n  \
    \      auto f = [](auto &&f, int d, Node *u) -> void {\n            if (u == nullptr)\
    \ return;\n            f(f, d + 1, u->ch[1]);\n            for (int i = 0; i <\
    \ d; i++) {\n                std::cout << \"      \";\n            }\n       \
    \     std::cout << \"(\" << u->dat << \", \" << u->sz << \", \" << u->hi << \"\
    )\"\n                      << std::endl;\n            f(f, d + 1, u->ch[0]);\n\
    \        };\n        f(f, 0, root);\n    };\n};\n\n\n#line 10 \"test/aoj/ALDS1_9_C_AVLset.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    AVLSet<i64> le;\n    priority_queue<i64> que;\n\n    string s;\n    while\
    \ (cin >> s, s != \"end\") {\n        if (s == \"insert\") {\n            i64\
    \ k;\n            cin >> k;\n            le.insert(k);\n            que.push(k);\n\
    \        } else {\n            auto [x, y, z] =\n                tuple(le.find_Kth(le.size()\
    \ - 1), le.upper_bound(que.top()),\n                      le.lower_bound(que.top()));\n\
    \n            assert(x && !y && z);\n            assert(x.value() == z.value()\
    \ && x.value() == que.top());\n\n            cout << x.value() << '\\n';\n\n \
    \           le.erase(x.value());\n            que.pop();\n        }\n    }\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <queue>\n#include <string>\n#include <tuple>\n\
    \n#include \"../../bbst/avl_set.hpp\"\n\n#define _overload(_1, _2, _3, _4, name,\
    \ ...) name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define _rep2(Itr, a,\
    \ b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr\
    \ < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2,\
    \ _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n#define ALL(X)\
    \ begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\nusing u64\
    \ = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    AVLSet<i64> le;\n    priority_queue<i64> que;\n\n    string s;\n    while\
    \ (cin >> s, s != \"end\") {\n        if (s == \"insert\") {\n            i64\
    \ k;\n            cin >> k;\n            le.insert(k);\n            que.push(k);\n\
    \        } else {\n            auto [x, y, z] =\n                tuple(le.find_Kth(le.size()\
    \ - 1), le.upper_bound(que.top()),\n                      le.lower_bound(que.top()));\n\
    \n            assert(x && !y && z);\n            assert(x.value() == z.value()\
    \ && x.value() == que.top());\n\n            cout << x.value() << '\\n';\n\n \
    \           le.erase(x.value());\n            que.pop();\n        }\n    }\n\n\
    \    return 0;\n}"
  dependsOn:
  - bbst/avl_set.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_9_C_AVLset.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 22:01:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_9_C_AVLset.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_9_C_AVLset.test.cpp
- /verify/test/aoj/ALDS1_9_C_AVLset.test.cpp.html
title: test/aoj/ALDS1_9_C_AVLset.test.cpp
---
