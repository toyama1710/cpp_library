---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: heap/persistent_leftist_heap.hpp
    title: heap/persistent_leftist_heap.hpp
  - icon: ':heavy_check_mark:'
    path: util/reverse_cmp.hpp
    title: util/reverse_cmp.hpp
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
  bundledCode: "#line 1 \"test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp\"\n\
    #define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <queue>\n#include <string>\n#include <tuple>\n\
    \n#line 1 \"heap/persistent_leftist_heap.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <utility>\n\ntemplate <class T>\nstruct PersistentLeftistHeap {\n    struct\
    \ Node {\n        T val;\n        int sz;\n        Node *ch[2];\n        Node(const\
    \ T &val) : val(val), sz(1), ch{nullptr, nullptr} {};\n        Node(Node *ptr)\n\
    \            : val(ptr->val), sz(ptr->sz), ch{ptr->ch[0], ptr->ch[1]} {};\n  \
    \      static int size(const Node *u) { return u == nullptr ? 0 : u->sz; };\n\
    \        static Node *update(Node *u) {\n            u->sz = size(u->ch[0]) +\
    \ size(u->ch[1]) + 1;\n            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0],\
    \ u->ch[1]);\n            return u;\n        }\n    };\n\n    Node *root;\n  \
    \  using Self = PersistentLeftistHeap;\n    PersistentLeftistHeap() = default;\n\
    \    PersistentLeftistHeap(Node *root) : root(root){};\n\n    int size() const\
    \ { return Node::size(root); };\n    bool empty() const { return size() == 0;\
    \ };\n\n    Node *meld(Node *h1, Node *h2) const {\n        if (h1 == nullptr)\
    \ {\n            return h2;\n        } else if (h2 == nullptr) {\n           \
    \ return h1;\n        } else {\n            if (h1->val > h2->val) std::swap(h1,\
    \ h2);\n            auto v = new Node(h1);\n            v->ch[1] = meld(v->ch[1],\
    \ h2);\n            return Node::update(v);\n        }\n    };\n    Self merge_with(const\
    \ Self h) const { return Self(root, h.root); };\n    Self push(const T &v) const\
    \ { return Self(meld(root, new Node(v))); };\n    T peek() const {\n        assert(!empty());\n\
    \        return root->val;\n    };\n    Self pop() const {\n        assert(!empty());\n\
    \        return Self(meld(root->ch[0], root->ch[1]));\n    };\n};\n\n\n#line 1\
    \ \"util/reverse_cmp.hpp\"\n\n\n\ntemplate <class T>\nstruct RevCmp {\n    T val;\n\
    \n    RevCmp(T val) : val(val){};\n\n    bool operator<(const RevCmp &rhs) const\
    \ { return rhs.val < val; };\n    bool operator>(const RevCmp &rhs) const { return\
    \ val < rhs.val; };\n    bool operator==(const RevCmp &rhs) const {\n        return\
    \ !(val < rhs.val || rhs.val < val);\n    };\n    bool operator!=(const RevCmp\
    \ &rhs) const {\n        return val < rhs.val || rhs.val < val;\n    };\n    bool\
    \ operator<=(const RevCmp &rhs) const {\n        return *this < rhs || *this ==\
    \ rhs;\n    };\n    bool operator>=(const RevCmp &rhs) const {\n        return\
    \ *this > rhs || *this == rhs;\n    };\n\n    RevCmp &operator=(const RevCmp &rhs)\
    \ {\n        val = rhs.val;\n        return *this;\n    };\n\n    T value() const\
    \ { return val; };\n};\n\n\n#line 11 \"test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    vector<PersistentLeftistHeap<i64>> que;\n    que.push_back(PersistentLeftistHeap<i64>());\n\
    \    vector<int> query;\n\n    string s;\n    while (cin >> s, s != \"end\") {\n\
    \        if (s == \"insert\") {\n            query.push_back(1);\n           \
    \ i64 k;\n            cin >> k;\n            que.push_back(que.back().push(-k));\n\
    \        } else {\n            query.push_back(0);\n            que.push_back(que.back().pop());\n\
    \        }\n    }\n\n    rep(i, (i64)query.size()) {\n        if (query[i] ==\
    \ 0) {\n            cout << -que[i].peek() << '\\n';\n        }\n    }\n\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <queue>\n#include <string>\n#include <tuple>\n\
    \n#include \"../../heap/persistent_leftist_heap.hpp\"\n#include \"../../util/reverse_cmp.hpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    vector<PersistentLeftistHeap<i64>> que;\n    que.push_back(PersistentLeftistHeap<i64>());\n\
    \    vector<int> query;\n\n    string s;\n    while (cin >> s, s != \"end\") {\n\
    \        if (s == \"insert\") {\n            query.push_back(1);\n           \
    \ i64 k;\n            cin >> k;\n            que.push_back(que.back().push(-k));\n\
    \        } else {\n            query.push_back(0);\n            que.push_back(que.back().pop());\n\
    \        }\n    }\n\n    rep(i, (i64)query.size()) {\n        if (query[i] ==\
    \ 0) {\n            cout << -que[i].peek() << '\\n';\n        }\n    }\n\n   \
    \ return 0;\n}\n"
  dependsOn:
  - heap/persistent_leftist_heap.hpp
  - util/reverse_cmp.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
  requiredBy: []
  timestamp: '2021-11-24 11:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
- /verify/test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp.html
title: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
---
