---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"heap/meldable_heap.cpp\"\n#include <iostream>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstdint>\n#include <cassert>\n#include\
    \ <cmath>\n#include <functional>\n#include <algorithm>\n#include <string>\n#include\
    \ <vector>\n#include <set>\n#include <map>\n#include <queue>\n#include <stack>\n\
    using namespace std;\nusing llong = long long;\n\n//===\n//=== xorshift\nuint32_t\
    \ xorshift32() {\n    static uint32_t s = 1710;\n    s = s ^ (s << 13);\n    s\
    \ = s ^ (s >> 17);\n    s = s ^ ( s << 5);\n    return s;\n}\n//===\n\n// not\
    \ stable\ntemplate<typename T, typename Compare = less<T> >\nstruct MeldableHeap\
    \ {\n    struct Node {\n        T dat;\n        Node *l, *r;\n\n        Node (T\
    \ dat): dat(dat), l(nullptr), r(nullptr) {};\n    };\n\n    Node *root;\n    Compare\
    \ cmp;\n\n    MeldableHeap (Compare cmp = Compare()): root(nullptr), cmp(cmp)\
    \ {};\n\n    Node *meld(Node *h1, Node *h2) {\n        if (h1 == nullptr) return\
    \ h2;\n        else if (h2 == nullptr) return h1;\n\n        if (cmp(h2->dat,\
    \ h1->dat)) swap(h1, h2);\n        \n        if (xorshift32() & 1) h1->l = meld(h1->l,\
    \ h2);\n        else h1->r = meld(h1->r, h2);\n\n        return h1;\n    };\n\n\
    \    void push(T dat) {\n        Node *u = new Node(dat);\n        root = meld(root,\
    \ u);\n    };\n\n    T top() { return root->dat; };\n    \n    T pop() {\n   \
    \     assert(!empty());\n        T ret = top();\n        Node *rm = root;\n  \
    \      root = meld(root->l, root->r);\n        delete rm;\n        \n        return\
    \ ret;\n    };\n\n    void merge_with(MeldableHeap &h) {\n        root = meld(root,\
    \ h);\n        h.root = nullptr;\n    };\n\n    bool empty() { return root ==\
    \ nullptr; };\n};\n// MinHeap<T> = MeldableHeap<T, less<T>>\n// MaxHeap<T> = MeldableHeap<T,\
    \ greater<T>>\n//===\n\nint ABC141D() {\n    llong n, m;\n    llong a;\n    MeldableHeap<llong,\
    \ greater<llong> > h;\n\n    cin >> n >> m;\n    for (int i = 0; i < n; i++) {\n\
    \        cin >> a;\n        h.push(a);\n    }\n\n    for (int i = 0; i < m; i++)\
    \ {\n        a = h.pop() / 2;\n        h.push(a);\n    }\n\n    llong sum = 0;\n\
    \    while (!h.empty()) {\n        sum += h.pop();\n    }\n\n    cout << sum <<\
    \ endl;\n    \n    return 0;\n}\n\nint main() {\n    return ABC141D();\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <cstdlib>\n#include <cstdint>\n\
    #include <cassert>\n#include <cmath>\n#include <functional>\n#include <algorithm>\n\
    #include <string>\n#include <vector>\n#include <set>\n#include <map>\n#include\
    \ <queue>\n#include <stack>\nusing namespace std;\nusing llong = long long;\n\n\
    //===\n//=== xorshift\nuint32_t xorshift32() {\n    static uint32_t s = 1710;\n\
    \    s = s ^ (s << 13);\n    s = s ^ (s >> 17);\n    s = s ^ ( s << 5);\n    return\
    \ s;\n}\n//===\n\n// not stable\ntemplate<typename T, typename Compare = less<T>\
    \ >\nstruct MeldableHeap {\n    struct Node {\n        T dat;\n        Node *l,\
    \ *r;\n\n        Node (T dat): dat(dat), l(nullptr), r(nullptr) {};\n    };\n\n\
    \    Node *root;\n    Compare cmp;\n\n    MeldableHeap (Compare cmp = Compare()):\
    \ root(nullptr), cmp(cmp) {};\n\n    Node *meld(Node *h1, Node *h2) {\n      \
    \  if (h1 == nullptr) return h2;\n        else if (h2 == nullptr) return h1;\n\
    \n        if (cmp(h2->dat, h1->dat)) swap(h1, h2);\n        \n        if (xorshift32()\
    \ & 1) h1->l = meld(h1->l, h2);\n        else h1->r = meld(h1->r, h2);\n\n   \
    \     return h1;\n    };\n\n    void push(T dat) {\n        Node *u = new Node(dat);\n\
    \        root = meld(root, u);\n    };\n\n    T top() { return root->dat; };\n\
    \    \n    T pop() {\n        assert(!empty());\n        T ret = top();\n    \
    \    Node *rm = root;\n        root = meld(root->l, root->r);\n        delete\
    \ rm;\n        \n        return ret;\n    };\n\n    void merge_with(MeldableHeap\
    \ &h) {\n        root = meld(root, h);\n        h.root = nullptr;\n    };\n\n\
    \    bool empty() { return root == nullptr; };\n};\n// MinHeap<T> = MeldableHeap<T,\
    \ less<T>>\n// MaxHeap<T> = MeldableHeap<T, greater<T>>\n//===\n\nint ABC141D()\
    \ {\n    llong n, m;\n    llong a;\n    MeldableHeap<llong, greater<llong> > h;\n\
    \n    cin >> n >> m;\n    for (int i = 0; i < n; i++) {\n        cin >> a;\n \
    \       h.push(a);\n    }\n\n    for (int i = 0; i < m; i++) {\n        a = h.pop()\
    \ / 2;\n        h.push(a);\n    }\n\n    llong sum = 0;\n    while (!h.empty())\
    \ {\n        sum += h.pop();\n    }\n\n    cout << sum << endl;\n    \n    return\
    \ 0;\n}\n\nint main() {\n    return ABC141D();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: heap/meldable_heap.cpp
  requiredBy: []
  timestamp: '2019-09-22 22:21:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heap/meldable_heap.cpp
layout: document
redirect_from:
- /library/heap/meldable_heap.cpp
- /library/heap/meldable_heap.cpp.html
title: heap/meldable_heap.cpp
---
