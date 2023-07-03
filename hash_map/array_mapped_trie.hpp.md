---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/associative_array_amt.test.cpp
    title: test/yosupo/associative_array_amt.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"hash_map/array_mapped_trie.hpp\"\n\n\n\n#include <cstdint>\n\
    \ntemplate <class T, int key_width = 32, int chunk_width = 4>\nstruct ArrayMappedTrie\
    \ {\n    using u64 = uint64_t;\n    static constexpr u64 mask = (1 << chunk_width)\
    \ - 1;\n\n    union Node {\n        Node *link[1 << chunk_width];\n        T dat;\n\
    \        Node() : link{} {};\n    };\n\n    Node *root;\n    const T id;\n   \
    \ ArrayMappedTrie(T id = T()) : root(new Node()), id(id){};\n\n    Node *get_node(u64\
    \ idx) {\n        Node *u = root;\n        for (int i = 0; i < (key_width + chunk_width\
    \ - 1) / chunk_width; i++) {\n            if (!u->link[idx & mask]) u->link[idx\
    \ & mask] = new Node();\n            u = u->link[idx & mask];\n            idx\
    \ >>= chunk_width;\n        }\n        return u;\n    };\n\n    bool find(u64\
    \ idx) {\n        Node *u = root;\n        u64 i = 0;\n        while (i < (key_width\
    \ + chunk_width - 1) / chunk_width && !u) {\n            u = u->link[idx & mask];\n\
    \            idx >>= chunk_width;\n        }\n        return u != nullptr;\n \
    \   };\n\n    T &operator[](u64 idx) {\n        if (find(idx)) {\n           \
    \ return get_node(idx)->dat;\n        } else {\n            return get_node(idx)->dat\
    \ = id;\n        }\n    };\n};\n\n\n"
  code: "#ifndef ARRAY_MAPPED_TRIE_HPP\n#define ARRAY_MAPPED_TRIE_HPP\n\n#include\
    \ <cstdint>\n\ntemplate <class T, int key_width = 32, int chunk_width = 4>\nstruct\
    \ ArrayMappedTrie {\n    using u64 = uint64_t;\n    static constexpr u64 mask\
    \ = (1 << chunk_width) - 1;\n\n    union Node {\n        Node *link[1 << chunk_width];\n\
    \        T dat;\n        Node() : link{} {};\n    };\n\n    Node *root;\n    const\
    \ T id;\n    ArrayMappedTrie(T id = T()) : root(new Node()), id(id){};\n\n   \
    \ Node *get_node(u64 idx) {\n        Node *u = root;\n        for (int i = 0;\
    \ i < (key_width + chunk_width - 1) / chunk_width; i++) {\n            if (!u->link[idx\
    \ & mask]) u->link[idx & mask] = new Node();\n            u = u->link[idx & mask];\n\
    \            idx >>= chunk_width;\n        }\n        return u;\n    };\n\n  \
    \  bool find(u64 idx) {\n        Node *u = root;\n        u64 i = 0;\n       \
    \ while (i < (key_width + chunk_width - 1) / chunk_width && !u) {\n          \
    \  u = u->link[idx & mask];\n            idx >>= chunk_width;\n        }\n   \
    \     return u != nullptr;\n    };\n\n    T &operator[](u64 idx) {\n        if\
    \ (find(idx)) {\n            return get_node(idx)->dat;\n        } else {\n  \
    \          return get_node(idx)->dat = id;\n        }\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: hash_map/array_mapped_trie.hpp
  requiredBy: []
  timestamp: '2023-07-03 22:03:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/associative_array_amt.test.cpp
documentation_of: hash_map/array_mapped_trie.hpp
layout: document
redirect_from:
- /library/hash_map/array_mapped_trie.hpp
- /library/hash_map/array_mapped_trie.hpp.html
title: hash_map/array_mapped_trie.hpp
---
