---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
    title: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"heap/leftist_heap.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <utility>\n\n// min heap\n// weight-biased leftist heap\ntemplate <class T>\n\
    struct LeftistHeap {\n    struct Node {\n        T val;\n        int sz;\n   \
    \     Node *ch[2];\n        Node(T &val) : val(val), sz(1), ch{nullptr, nullptr}\
    \ {};\n        static int size(Node *u) { return u == nullptr ? 0 : u->sz; };\n\
    \        static Node *update(Node *u) {\n            u->sz = size(u->ch[0]) +\
    \ size(u->ch[1]) + 1;\n            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0],\
    \ u->ch[1]);\n            return u;\n        }\n    };\n\n    Node *root = nullptr;\n\
    \    LeftistHeap() = default;\n\n    Node *meld(Node *h1, Node *h2) {\n      \
    \  if (h1 == nullptr) {\n            return h2;\n        } else if (h2 == nullptr)\
    \ {\n            return h1;\n        } else {\n            if (h1->val > h2->val)\
    \ std::swap(h1, h2);\n            h1->ch[1] = meld(h1->ch[1], h2);\n         \
    \   return Node::update(h1);\n        }\n    };\n    LeftistHeap &merge_with(LeftistHeap\
    \ &h) {\n        root = meld(root, h.root);\n        h.root = nullptr;\n     \
    \   return *this;\n    };\n\n    LeftistHeap &push(T val) {\n        root = meld(root,\
    \ new Node(val));\n        return *this;\n    };\n    T peek() const {\n     \
    \   assert(root != nullptr);\n        return root->val;\n    };\n    LeftistHeap\
    \ &pop() {\n        assert(root != nullptr);\n        auto [l, r] = root->ch;\n\
    \        delete root;\n        root = meld(l, r);\n        return *this;\n   \
    \ };\n    int size() { return Node::size(root); };\n    bool empty() { return\
    \ size() == 0; };\n};\n\n\n"
  code: "#ifndef LEFTIST_HEAP_HPP\n#define LEFTIST_HEAP_HPP\n\n#include <cassert>\n\
    #include <utility>\n\n// min heap\n// weight-biased leftist heap\ntemplate <class\
    \ T>\nstruct LeftistHeap {\n    struct Node {\n        T val;\n        int sz;\n\
    \        Node *ch[2];\n        Node(T &val) : val(val), sz(1), ch{nullptr, nullptr}\
    \ {};\n        static int size(Node *u) { return u == nullptr ? 0 : u->sz; };\n\
    \        static Node *update(Node *u) {\n            u->sz = size(u->ch[0]) +\
    \ size(u->ch[1]) + 1;\n            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0],\
    \ u->ch[1]);\n            return u;\n        }\n    };\n\n    Node *root = nullptr;\n\
    \    LeftistHeap() = default;\n\n    Node *meld(Node *h1, Node *h2) {\n      \
    \  if (h1 == nullptr) {\n            return h2;\n        } else if (h2 == nullptr)\
    \ {\n            return h1;\n        } else {\n            if (h1->val > h2->val)\
    \ std::swap(h1, h2);\n            h1->ch[1] = meld(h1->ch[1], h2);\n         \
    \   return Node::update(h1);\n        }\n    };\n    LeftistHeap &merge_with(LeftistHeap\
    \ &h) {\n        root = meld(root, h.root);\n        h.root = nullptr;\n     \
    \   return *this;\n    };\n\n    LeftistHeap &push(T val) {\n        root = meld(root,\
    \ new Node(val));\n        return *this;\n    };\n    T peek() const {\n     \
    \   assert(root != nullptr);\n        return root->val;\n    };\n    LeftistHeap\
    \ &pop() {\n        assert(root != nullptr);\n        auto [l, r] = root->ch;\n\
    \        delete root;\n        root = meld(l, r);\n        return *this;\n   \
    \ };\n    int size() { return Node::size(root); };\n    bool empty() { return\
    \ size() == 0; };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: heap/leftist_heap.hpp
  requiredBy: []
  timestamp: '2021-11-24 11:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_9_C_leftist_heap.test.cpp
documentation_of: heap/leftist_heap.hpp
layout: document
redirect_from:
- /library/heap/leftist_heap.hpp
- /library/heap/leftist_heap.hpp.html
title: heap/leftist_heap.hpp
---
