---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: heap/leftist_heap.hpp
    title: heap/leftist_heap.hpp
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
  bundledCode: "#line 1 \"test/aoj/ALDS1_9_C_leftist_heap.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <queue>\n#include <string>\n#include <tuple>\n\
    \n#line 1 \"heap/leftist_heap.hpp\"\n\n\n\n#include <cassert>\n#include <utility>\n\
    \n// min heap\n// weight-biased leftist heap\ntemplate <class T>\nstruct LeftistHeap\
    \ {\n    struct Node {\n        T val;\n        int sz;\n        Node *ch[2];\n\
    \        Node(T &val) : val(val), sz(1), ch{nullptr, nullptr} {};\n        static\
    \ int size(Node *u) { return u == nullptr ? 0 : u->sz; };\n        static Node\
    \ *update(Node *u) {\n            u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;\n\
    \            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0], u->ch[1]);\n\
    \            return u;\n        }\n    };\n\n    Node *root = nullptr;\n    LeftistHeap()\
    \ = default;\n\n    Node *meld(Node *h1, Node *h2) {\n        if (h1 == nullptr)\
    \ {\n            return h2;\n        } else if (h2 == nullptr) {\n           \
    \ return h1;\n        } else {\n            if (h1->val > h2->val) std::swap(h1,\
    \ h2);\n            h1->ch[1] = meld(h1->ch[1], h2);\n            return Node::update(h1);\n\
    \        }\n    };\n    LeftistHeap &merge_with(LeftistHeap &h) {\n        root\
    \ = meld(root, h.root);\n        h.root = nullptr;\n        return *this;\n  \
    \  };\n\n    LeftistHeap &push(T val) {\n        root = meld(root, new Node(val));\n\
    \        return *this;\n    };\n    T top() const {\n        assert(root != nullptr);\n\
    \        return root->val;\n    };\n    LeftistHeap &pop() {\n        assert(root\
    \ != nullptr);\n        auto [l, r] = root->ch;\n        delete root;\n      \
    \  root = meld(l, r);\n        return *this;\n    };\n    int size() { return\
    \ Node::size(root); };\n    bool empty() { return size() == 0; };\n};\n\n\n#line\
    \ 1 \"util/reverse_cmp.hpp\"\n\n\n\ntemplate <class T>\nstruct RevCmp {\n    T\
    \ val;\n\n    RevCmp(T val) : val(val){};\n\n    bool operator<(const RevCmp &rhs)\
    \ const { return rhs.val < val; };\n    bool operator>(const RevCmp &rhs) const\
    \ { return val < rhs.val; };\n    bool operator==(const RevCmp &rhs) const {\n\
    \        return !(val < rhs.val || rhs.val < val);\n    };\n    bool operator!=(const\
    \ RevCmp &rhs) const {\n        return val < rhs.val || rhs.val < val;\n    };\n\
    \    bool operator<=(const RevCmp &rhs) const {\n        return *this < rhs ||\
    \ *this == rhs;\n    };\n    bool operator>=(const RevCmp &rhs) const {\n    \
    \    return *this > rhs || *this == rhs;\n    };\n\n    RevCmp &operator=(const\
    \ RevCmp &rhs) {\n        val = rhs.val;\n        return *this;\n    };\n\n  \
    \  T value() const { return val; };\n};\n\n\n#line 11 \"test/aoj/ALDS1_9_C_leftist_heap.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    LeftistHeap<RevCmp<i64>> que;\n\n    string s;\n    while (cin >> s, s !=\
    \ \"end\") {\n        if (s == \"insert\") {\n            i64 k;\n           \
    \ cin >> k;\n            if (!que.empty() && que.top().value() == k)\n       \
    \         que.push(k).pop().push(k).pop();\n            que.push(k);\n       \
    \ } else {\n            cout << que.top().value() << '\\n';\n            que.pop();\n\
    \        }\n        // cout << que.size() << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <queue>\n#include <string>\n#include <tuple>\n\
    \n#include \"../../heap/leftist_heap.hpp\"\n#include \"../../util/reverse_cmp.hpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    LeftistHeap<RevCmp<i64>> que;\n\n    string s;\n    while (cin >> s, s !=\
    \ \"end\") {\n        if (s == \"insert\") {\n            i64 k;\n           \
    \ cin >> k;\n            if (!que.empty() && que.top().value() == k)\n       \
    \         que.push(k).pop().push(k).pop();\n            que.push(k);\n       \
    \ } else {\n            cout << que.top().value() << '\\n';\n            que.pop();\n\
    \        }\n        // cout << que.size() << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - heap/leftist_heap.hpp
  - util/reverse_cmp.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
  requiredBy: []
  timestamp: '2021-11-23 23:43:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_9_C_leftist_heap.test.cpp
- /verify/test/aoj/ALDS1_9_C_leftist_heap.test.cpp.html
title: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
---
