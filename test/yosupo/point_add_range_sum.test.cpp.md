---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bbst/avl_array.hpp
    title: bbst/avl_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include <iostream>\n\
    \n#line 1 \"bbst/avl_array.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <optional>\n#include <utility>\n\ntemplate <class Monoid>\nstruct AVLArray\
    \ {\n    using M = Monoid;\n    using T = typename Monoid::value_type;\n    struct\
    \ Node {\n        T val;\n        T sum;\n        int hi;\n        int sz;\n \
    \       Node *ch[2];\n\n        Node(const T &val = M::identity())\n         \
    \   : val(val), sum(val), hi(1), sz(1), ch{nullptr, nullptr} {};\n    };\n\n \
    \   Node *root;\n\n    explicit AVLArray(Node *root = nullptr) : root(root){};\n\
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
    \ }\n    };\n\n    // first:[0, k), second:[k, n)\n    std::pair<AVLArray, AVLArray>\
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
    \ };\n\n    const T operator[](int k) { return at(root, k); };\n    const T at(Node\
    \ *u, int k) {\n        assert(0 <= k && k < size(u));\n        if (size(u->ch[0])\
    \ == k)\n            return u->val;\n        else if (k < size(u->ch[0]))\n  \
    \          return at(u->ch[0], k);\n        else\n            return at(u->ch[1],\
    \ k - size(u->ch[0]) - 1);\n    };\n};\n\n\n#line 6 \"test/yosupo/point_add_range_sum.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nstruct Sum {\n    using T = i64;\n    using\
    \ value_type = T;\n    static T identity() { return 0; };\n    static T operation(T\
    \ lhs, T rhs) { return lhs + rhs; };\n};\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    int n, q;\n    cin >> n >> q;\n\n   \
    \ AVLArray<Sum> arr;\n    rep(i, n) {\n        i64 a;\n        cin >> a;\n   \
    \     arr.insert_at(i, a);\n    }\n\n    i64 com, a, b;\n    rep(_, q) {\n   \
    \     cin >> com >> a >> b;\n        if (com == 0) {\n            arr.update_at(a,\
    \ arr[a] + b);\n        } else if (com == 1) {\n            cout << arr.fold(a,\
    \ b) << '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n\n#include \"../../bbst/avl_array.hpp\"\n\n#define _overload(_1,\
    \ _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define\
    \ _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64\
    \ Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__, _rep3,\
    \ _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n#define\
    \ ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\nstruct Sum {\n    using T = i64;\n    using value_type\
    \ = T;\n    static T identity() { return 0; };\n    static T operation(T lhs,\
    \ T rhs) { return lhs + rhs; };\n};\n\nint main() {\n    cin.tie(nullptr);\n \
    \   ios::sync_with_stdio(false);\n\n    int n, q;\n    cin >> n >> q;\n\n    AVLArray<Sum>\
    \ arr;\n    rep(i, n) {\n        i64 a;\n        cin >> a;\n        arr.insert_at(i,\
    \ a);\n    }\n\n    i64 com, a, b;\n    rep(_, q) {\n        cin >> com >> a >>\
    \ b;\n        if (com == 0) {\n            arr.update_at(a, arr[a] + b);\n   \
    \     } else if (com == 1) {\n            cout << arr.fold(a, b) << '\\n';\n \
    \       }\n    }\n\n    return 0;\n}"
  dependsOn:
  - bbst/avl_array.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-09-02 18:35:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.test.cpp
- /verify/test/yosupo/point_add_range_sum.test.cpp.html
title: test/yosupo/point_add_range_sum.test.cpp
---
