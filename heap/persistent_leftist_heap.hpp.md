---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
    title: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"heap/persistent_leftist_heap.hpp\"\n\n\n\n#include <cassert>\n\
    #include <utility>\n\ntemplate <class T>\nstruct PersistentLeftistHeap {\n   \
    \ struct Node {\n        T val;\n        int sz;\n        Node *ch[2];\n     \
    \   Node(const T &val) : val(val), sz(1), ch{nullptr, nullptr} {};\n        Node(Node\
    \ *ptr)\n            : val(ptr->val), sz(ptr->sz), ch{ptr->ch[0], ptr->ch[1]}\
    \ {};\n        static int size(const Node *u) { return u == nullptr ? 0 : u->sz;\
    \ };\n        static Node *update(Node *u) {\n            u->sz = size(u->ch[0])\
    \ + size(u->ch[1]) + 1;\n            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0],\
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
    \        return Self(meld(root->ch[0], root->ch[1]));\n    };\n};\n\n\n"
  code: "#ifndef PERSISTENT_LEFTIST_HEAP_HPP\n#define PERSISTENT_LEFTIST_HEAP_HPP\n\
    \n#include <cassert>\n#include <utility>\n\ntemplate <class T>\nstruct PersistentLeftistHeap\
    \ {\n    struct Node {\n        T val;\n        int sz;\n        Node *ch[2];\n\
    \        Node(const T &val) : val(val), sz(1), ch{nullptr, nullptr} {};\n    \
    \    Node(Node *ptr)\n            : val(ptr->val), sz(ptr->sz), ch{ptr->ch[0],\
    \ ptr->ch[1]} {};\n        static int size(const Node *u) { return u == nullptr\
    \ ? 0 : u->sz; };\n        static Node *update(Node *u) {\n            u->sz =\
    \ size(u->ch[0]) + size(u->ch[1]) + 1;\n            if (size(u->ch[0]) < size(u->ch[1]))\
    \ std::swap(u->ch[0], u->ch[1]);\n            return u;\n        }\n    };\n\n\
    \    Node *root;\n    using Self = PersistentLeftistHeap;\n    PersistentLeftistHeap()\
    \ = default;\n    PersistentLeftistHeap(Node *root) : root(root){};\n\n    int\
    \ size() const { return Node::size(root); };\n    bool empty() const { return\
    \ size() == 0; };\n\n    Node *meld(Node *h1, Node *h2) const {\n        if (h1\
    \ == nullptr) {\n            return h2;\n        } else if (h2 == nullptr) {\n\
    \            return h1;\n        } else {\n            if (h1->val > h2->val)\
    \ std::swap(h1, h2);\n            auto v = new Node(h1);\n            v->ch[1]\
    \ = meld(v->ch[1], h2);\n            return Node::update(v);\n        }\n    };\n\
    \    Self merge_with(const Self h) const { return Self(root, h.root); };\n   \
    \ Self push(const T &v) const { return Self(meld(root, new Node(v))); };\n   \
    \ T peek() const {\n        assert(!empty());\n        return root->val;\n   \
    \ };\n    Self pop() const {\n        assert(!empty());\n        return Self(meld(root->ch[0],\
    \ root->ch[1]));\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: heap/persistent_leftist_heap.hpp
  requiredBy: []
  timestamp: '2021-11-24 11:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
documentation_of: heap/persistent_leftist_heap.hpp
layout: document
redirect_from:
- /library/heap/persistent_leftist_heap.hpp
- /library/heap/persistent_leftist_heap.hpp.html
title: heap/persistent_leftist_heap.hpp
---
