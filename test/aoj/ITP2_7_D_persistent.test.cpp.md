---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bbst/avl_set.hpp
    title: bbst/avl_set.hpp
  - icon: ':question:'
    path: bbst/persistent_avl_set.hpp
    title: bbst/persistent_avl_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D
  bundledCode: "#line 1 \"test/aoj/ITP2_7_D_persistent.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D\"\
    \n#include <iostream>\n\n#line 1 \"bbst/persistent_avl_set.hpp\"\n\n\n\n#line\
    \ 1 \"bbst/avl_set.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n#line\
    \ 7 \"bbst/avl_set.hpp\"\n#include <optional>\n#include <utility>\n#include <vector>\n\
    \n// insert/erase base AVLtree\n// multiset\ntemplate <class T>\nstruct AVLSet\
    \ {\n    struct Node {\n        int sz, hi;\n        T dat;\n        Node *ch[2];\n\
    \        Node(const Node *x)\n            : sz(x->sz), hi(x->hi), dat(x->dat),\
    \ ch{x->ch[0], x->ch[1]} {};\n        Node(T dat) : sz(1), hi(1), dat(dat), ch{nullptr,\
    \ nullptr} {};\n    };\n\n    Node *root;\n\n    AVLSet(Node *r = nullptr) : root(r){};\n\
    \    AVLSet(const AVLSet &x) : root(x.root){};\n    AVLSet &operator=(const AVLSet\
    \ &x) {\n        root = x.root;\n        return *this;\n    };\n\n    int size()\
    \ const {\n        return size(root);\n    };\n    static int size(Node *u) {\n\
    \        if (u != nullptr)\n            return u->sz;\n        else\n        \
    \    return 0;\n    };\n\n    static int height(Node *u) {\n        if (u != nullptr)\n\
    \            return u->hi;\n        else\n            return 0;\n    };\n\n  \
    \  template <int d>  // 0: left, 1: right\n    static Node *rotate(Node *u) {\n\
    \        assert(u != nullptr && u->ch[d] != nullptr);\n        Node *v = u->ch[d];\n\
    \        u->ch[d] = v->ch[d ^ 1];\n        v->ch[d ^ 1] = u;\n        recalc(u);\n\
    \        recalc(v);\n        return v;\n    };\n    static int balance_factor(Node\
    \ *u) {\n        if (u == nullptr) return 0;\n        return height(u->ch[0])\
    \ - height(u->ch[1]);\n    };\n    static Node *balance(Node *u) {\n        if\
    \ (u == nullptr) return nullptr;\n        assert(-2 <= balance_factor(u) && balance_factor(u)\
    \ <= 2);\n        if (balance_factor(u) == 2) {\n            if (balance_factor(u->ch[0])\
    \ == -1) u->ch[0] = rotate<1>(u->ch[0]);\n            u = rotate<0>(u);\n    \
    \    } else if (balance_factor(u) == -2) {\n            if (balance_factor(u->ch[1])\
    \ == 1) u->ch[1] = rotate<0>(u->ch[1]);\n            u = rotate<1>(u);\n     \
    \   }\n        return u;\n    };\n    static Node *recalc(Node *u) {\n       \
    \ if (u == nullptr) return nullptr;\n        u->sz = size(u->ch[0]) + size(u->ch[1])\
    \ + 1;\n        u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;\n  \
    \      return u;\n    };\n\n    AVLSet &insert(const T &dat) {\n        Node *u\
    \ = new Node(dat);\n        root = insert(root, u);\n        return *this;\n \
    \   };\n    Node *insert(Node *u, Node *nv) {\n        if (u == nullptr) return\
    \ nv;\n        if (u->dat < nv->dat)\n            u->ch[1] = insert(u->ch[1],\
    \ nv);\n        else\n            u->ch[0] = insert(u->ch[0], nv);\n\n       \
    \ return balance(recalc(u));\n    };\n\n    AVLSet &erase(const T &dat) {\n  \
    \      root = erase(root, dat);\n        return *this;\n    };\n    Node *erase(Node\
    \ *u, const T &dat) {\n        if (u == nullptr) return nullptr;\n        if (u->dat\
    \ < dat) {\n            u->ch[1] = erase(u->ch[1], dat);\n        } else if (dat\
    \ < u->dat) {\n            u->ch[0] = erase(u->ch[0], dat);\n        } else {\n\
    \            Node *del = u;\n            u = isolate_node(u);\n            delete\
    \ del;\n        }\n        return balance(recalc(u));\n    };\n    Node *isolate_node(Node\
    \ *u) {\n        if (u->ch[0] == nullptr || u->ch[1] == nullptr) {\n         \
    \   Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];\n            return\
    \ ret;\n        } else {\n            auto [l, nv] = split_rightest_node(u->ch[0]);\n\
    \            nv->ch[0] = l;\n            nv->ch[1] = u->ch[1];\n            return\
    \ balance(recalc(nv));\n        }\n    };\n    std::pair<Node *, Node *> split_rightest_node(Node\
    \ *v) {\n        if (v->ch[1] != nullptr) {\n            auto [l, ret] = split_rightest_node(v->ch[1]);\n\
    \            v->ch[1] = l;\n            return {balance(recalc(v)), ret};\n  \
    \      } else {\n            return {isolate_node(v), v};\n        }\n    };\n\
    \n    bool contains(const T &dat) const {\n        Node *u = root;\n        while\
    \ (u != nullptr) {\n            if (dat < u->dat) {\n                u = u->ch[0];\n\
    \            } else if (u->dat < dat) {\n                u = u->ch[1];\n     \
    \       } else {\n                return true;\n            }\n        }\n   \
    \     return false;\n    };\n\n    std::optional<T> lower_bound(const T &x) const\
    \ {\n        return lower_bound(root, x);\n    };\n    std::optional<T> lower_bound(Node\
    \ *u, const T &x) const {\n        if (u == nullptr) return std::nullopt;\n  \
    \      if (u->dat < x) {\n            return lower_bound(u->ch[1], x);\n     \
    \   } else {\n            auto ret = lower_bound(u->ch[0], x);\n            if\
    \ (ret)\n                return ret;\n            else\n                return\
    \ u->dat;\n        }\n    };\n    std::optional<T> upper_bound(const T &x) const\
    \ {\n        return upper_bound(root, x);\n    };\n    std::optional<T> upper_bound(Node\
    \ *u, const T &x) const {\n        if (u == nullptr) return std::nullopt;\n  \
    \      if (x < u->dat) {\n            auto ret = upper_bound(u->ch[0], x);\n \
    \           if (ret)\n                return ret;\n            else\n        \
    \        return u->dat;\n        } else {\n            return upper_bound(u->ch[1],\
    \ x);\n        }\n    };\n\n    // 0-indexed\n    std::optional<T> find_Kth(int\
    \ k) const {\n        if (size() <= k || k < 0)\n            return std::nullopt;\n\
    \        else\n            return find_Kth(root, k)->dat;\n    };\n    Node *find_Kth(Node\
    \ *u, int k) const {\n        if (size(u->ch[0]) == k)\n            return u;\n\
    \        else if (size(u->ch[0]) > k)\n            return find_Kth(u->ch[0], k);\n\
    \        else\n            return find_Kth(u->ch[1], k - size(u->ch[0]) - 1);\n\
    \    };\n\n    int count(const T &x) const {\n        return size() - count_upper(x)\
    \ - count_lower(x);\n    };\n    int count_lower(const T &x) const {\n       \
    \ return count_lower(x, root);\n    };\n    int count_lower(const T &x, Node *u)\
    \ const {\n        if (u == nullptr) return 0;\n        if (u->dat < x)\n    \
    \        return count_lower(x, u->ch[1]) + size(u->ch[0]) + 1;\n        else\n\
    \            return count_lower(x, u->ch[0]);\n    };\n    int count_upper(const\
    \ T &x) const {\n        return count_upper(x, root);\n    };\n    int count_upper(const\
    \ T &x, Node *u) const {\n        if (u == nullptr) return 0;\n        if (x <\
    \ u->dat)\n            return count_upper(x, u->ch[0]) + size(u->ch[1]) + 1;\n\
    \        else\n            return count_upper(x, u->ch[1]);\n    };\n\n    AVLSet\
    \ &merge_with(AVLSet &r) {\n        if (r.size() == 0) {\n            return *this;\n\
    \        } else if (size() == 0) {\n            root = r.root;\n        } else\
    \ {\n            auto [l, tmp] = split_rightest_node(root);\n            root\
    \ = merge(tmp, l, r.root);\n            r.root = nullptr;\n        }\n       \
    \ return *this;\n    };\n    Node *merge(Node *root, Node *l, Node *r) {\n   \
    \     if (abs(height(l) - height(r)) <= 2) {\n            root->ch[0] = l;\n \
    \           root->ch[1] = r;\n            return balance(recalc(root));\n    \
    \    } else if (height(l) > height(r)) {\n            l->ch[1] = merge(root, l->ch[1],\
    \ r);\n            return balance(recalc(l));\n        } else {\n            r->ch[0]\
    \ = merge(root, l, r->ch[0]);\n            return balance(recalc(r));\n      \
    \  }\n    };\n\n    std::pair<AVLSet, AVLSet> split(int k) {\n        assert(k\
    \ >= 0 && k <= size());\n        auto [l, r] = split(root, k);\n        root =\
    \ nullptr;\n        return {AVLSet(l), AVLSet(r)};\n    };\n    std::pair<Node\
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
    \ dfs(root, dfs);\n        return ret;\n    };\n    void dump() const {\n    \
    \    auto f = [](auto &&f, int d, Node *u) -> void {\n            if (u == nullptr)\
    \ return;\n            f(f, d + 1, u->ch[1]);\n            for (int i = 0; i <\
    \ d; i++) {\n                std::cout << \"      \";\n            }\n       \
    \     std::cout << \"(\" << u->dat << \", \" << u->sz << \", \" << u->hi << \"\
    )\"\n                      << std::endl;\n            f(f, d + 1, u->ch[0]);\n\
    \        };\n        f(f, 0, root);\n    };\n};\n\n\n#line 5 \"bbst/persistent_avl_set.hpp\"\
    \n\n// insert/erase base AVLtree\n// multiset\n// merge,split are not implemented\n\
    template <class T>\nstruct PersistentAVLSet : public AVLSet<T> {\n    using Set\
    \ = AVLSet<T>;\n    using Node = typename AVLSet<T>::Node;\n    PersistentAVLSet(Node\
    \ *root = nullptr) : Set(root){};\n\n    static Node *copy(Node *u) {\n      \
    \  if (u == nullptr) return nullptr;\n        if (Set::balance_factor(u) == 2)\
    \ {\n            u->ch[0] = new Node(u->ch[0]);\n            if (Set::balance_factor(u->ch[0])\
    \ == -1)\n                u->ch[0]->ch[1] = new Node(u->ch[0]->ch[1]);\n     \
    \   } else if (Set::balance_factor(u) == -2) {\n            u->ch[1] = new Node(u->ch[1]);\n\
    \            if (Set::balance_factor(u->ch[1]) == 1)\n                u->ch[1]->ch[0]\
    \ = new Node(u->ch[1]->ch[0]);\n        }\n        return u;\n    };\n\n    PersistentAVLSet\
    \ insert(const T &dat) const {\n        Node *nv = new Node(dat);\n        return\
    \ PersistentAVLSet(insert(this->root, nv));\n    };\n    Node *insert(Node *u,\
    \ Node *nv) const {\n        if (u == nullptr) return nv;\n        u = new Node(u);\n\
    \        if (u->dat < nv->dat)\n            u->ch[1] = insert(u->ch[1], nv);\n\
    \        else\n            u->ch[0] = insert(u->ch[0], nv);\n\n        return\
    \ Set::balance(Set::recalc(u));\n    };\n\n    PersistentAVLSet erase(const T\
    \ &dat) const {\n        return PersistentAVLSet(erase(this->root, dat));\n  \
    \  };\n    Node *erase(Node *u, const T &dat) const {\n        if (u == nullptr)\
    \ return nullptr;\n        u = new Node(u);\n        if (u->dat < dat) {\n   \
    \         u->ch[1] = erase(u->ch[1], dat);\n        } else if (dat < u->dat) {\n\
    \            u->ch[0] = erase(u->ch[0], dat);\n        } else {\n            u\
    \ = isolate_node(u);\n        }\n        return Set::balance(copy(Set::recalc(u)));\n\
    \    };\n    Node *isolate_node(Node *u) const {\n        if (u->ch[0] == nullptr\
    \ || u->ch[1] == nullptr) {\n            return u->ch[0] != nullptr ? u->ch[0]\
    \ : u->ch[1];\n        } else {\n            auto [l, nv] = split_rightest_node(u->ch[0]);\n\
    \            nv = new Node(nv);\n            nv->ch[0] = l;\n            nv->ch[1]\
    \ = u->ch[1];\n            return Set::balance(copy(Set::recalc(nv)));\n     \
    \   }\n    };\n    std::pair<Node *, Node *> split_rightest_node(Node *v) const\
    \ {\n        if (v->ch[1] != nullptr) {\n            v = new Node(v);\n      \
    \      auto [l, ret] = split_rightest_node(v->ch[1]);\n            v->ch[1] =\
    \ l;\n            return {Set::balance(copy(Set::recalc(v))), ret};\n        }\
    \ else {\n            return {isolate_node(v), v};\n        }\n    };\n};\n\n\n\
    #line 6 \"test/aoj/ITP2_7_D_persistent.test.cpp\"\n\n#define _overload(_1, _2,\
    \ _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define\
    \ _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64\
    \ Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__, _rep3,\
    \ _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n#define\
    \ ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\nstruct Com {\n    i64 com, x, l, r;\n};\n\nint\
    \ main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    i64\
    \ q;\n    cin >> q;\n    vector<PersistentAVLSet<i64>> st(q);\n    vector<Com>\
    \ query(q);\n\n    for (auto &vs : query) {\n        cin >> vs.com;\n        if\
    \ (vs.com == 3)\n            cin >> vs.l >> vs.r;\n        else\n            cin\
    \ >> vs.x;\n    }\n\n    rep(i, q) {\n        if (i > 0) st[i] = st[i - 1];\n\n\
    \        if (query[i].com == 0) {\n            st[i] = st[i].insert(query[i].x);\n\
    \        } else if (query[i].com == 2) {\n            i64 x = query[i].x;\n  \
    \          while (st[i].count(x) > 0) st[i] = st[i].erase(x);\n        }\n   \
    \ }\n    rep(i, q) {\n        if (query[i].com == 0) {\n            cout << st[i].size()\
    \ << '\\n';\n        } else if (query[i].com == 1) {\n            cout << st[i].count(query[i].x)\
    \ << '\\n';\n        } else if (query[i].com == 3) {\n            i64 l = query[i].l;\n\
    \            i64 r = query[i].r;\n            auto y = st[i].lower_bound(l);\n\
    \            while (y.has_value() && y.value() <= r) {\n                i64 cnt\
    \ = st[i].count(y.value());\n                rep(i, cnt) cout << y.value() <<\
    \ '\\n';\n                y = st[i].upper_bound(y.value());\n            }\n \
    \       }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D\"\
    \n#include <iostream>\n\n#include \"../../bbst/persistent_avl_set.hpp\"\n\n#define\
    \ _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nstruct Com {\n    i64 com, x, l, r;\n};\n\n\
    int main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    i64\
    \ q;\n    cin >> q;\n    vector<PersistentAVLSet<i64>> st(q);\n    vector<Com>\
    \ query(q);\n\n    for (auto &vs : query) {\n        cin >> vs.com;\n        if\
    \ (vs.com == 3)\n            cin >> vs.l >> vs.r;\n        else\n            cin\
    \ >> vs.x;\n    }\n\n    rep(i, q) {\n        if (i > 0) st[i] = st[i - 1];\n\n\
    \        if (query[i].com == 0) {\n            st[i] = st[i].insert(query[i].x);\n\
    \        } else if (query[i].com == 2) {\n            i64 x = query[i].x;\n  \
    \          while (st[i].count(x) > 0) st[i] = st[i].erase(x);\n        }\n   \
    \ }\n    rep(i, q) {\n        if (query[i].com == 0) {\n            cout << st[i].size()\
    \ << '\\n';\n        } else if (query[i].com == 1) {\n            cout << st[i].count(query[i].x)\
    \ << '\\n';\n        } else if (query[i].com == 3) {\n            i64 l = query[i].l;\n\
    \            i64 r = query[i].r;\n            auto y = st[i].lower_bound(l);\n\
    \            while (y.has_value() && y.value() <= r) {\n                i64 cnt\
    \ = st[i].count(y.value());\n                rep(i, cnt) cout << y.value() <<\
    \ '\\n';\n                y = st[i].upper_bound(y.value());\n            }\n \
    \       }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - bbst/persistent_avl_set.hpp
  - bbst/avl_set.hpp
  isVerificationFile: true
  path: test/aoj/ITP2_7_D_persistent.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ITP2_7_D_persistent.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_7_D_persistent.test.cpp
- /verify/test/aoj/ITP2_7_D_persistent.test.cpp.html
title: test/aoj/ITP2_7_D_persistent.test.cpp
---
