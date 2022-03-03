---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hash_map/array_mapped_trie.hpp
    title: hash_map/array_mapped_trie.hpp
  - icon: ':heavy_check_mark:'
    path: util/xorshift.hpp
    title: util/xorshift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo/associative_array_amt.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\n\n#include <iostream>\n\
    \n#line 1 \"hash_map/array_mapped_trie.hpp\"\n\n\n\n#include <cstdint>\n\ntemplate<class\
    \ T, int key_width = 32, int chunk_width = 4>\nstruct ArrayMappedTrie {\n    using\
    \ u64 = uint64_t;\n    static constexpr u64 mask = (1 << chunk_width) - 1;\n\n\
    \    union Node {\n        Node *link[1 << chunk_width];\n        T dat;\n   \
    \     Node(): link{} {};\n    };\n\n    Node *root;\n    const T id;\n    ArrayMappedTrie(T\
    \ id = T()): root(new Node()), id(id) {};\n\n    Node *get_node(u64 idx) {\n \
    \       Node *u = root;\n        for (int i = 0; i < (key_width + chunk_width\
    \ - 1) / chunk_width; i++) {\n            if (!u->link[idx & mask])\n        \
    \        u->link[idx & mask] = new Node();\n            u = u->link[idx & mask];\n\
    \            idx >>= chunk_width;\n        }\n        return u;\n    };\n\n  \
    \  bool find(u64 idx) {\n        Node *u = root;\n        u64 i = 0;\n       \
    \ while (i < (key_width + chunk_width - 1) / chunk_width && !u) {\n          \
    \  u = u->link[idx & mask];\n            idx >>= chunk_width;\n        }\n   \
    \     return u != nullptr;\n    };\n\n    T &operator[](u64 idx) {\n        if\
    \ (find(idx)) {\n            return get_node(idx)->dat;\n        }else {\n   \
    \         return get_node(idx)->dat = id;\n        }\n    };\n};\n\n\n#line 1\
    \ \"util/xorshift.hpp\"\n\n\n\n#line 5 \"util/xorshift.hpp\"\n\nstruct xorshift32\
    \ {\n    uint32_t seed;\n    xorshift32(uint32_t seed = 1710) : seed(seed){};\n\
    \    void set_seed(uint32_t s) { seed = s; };\n    uint32_t gen() {\n        seed\
    \ = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 17);\n        seed =\
    \ seed ^ (seed << 5);\n        return seed;\n    };\n    uint32_t operator()()\
    \ { return gen(); };\n};\n\nstruct xorshift64 {\n    uint64_t seed;\n    xorshift64(uint64_t\
    \ seed = 1710) : seed(seed){};\n    void set_seed(uint64_t s) { seed = s; };\n\
    \    uint64_t gen() {\n        seed = seed ^ (seed << 13);\n        seed = seed\
    \ ^ (seed >> 7);\n        seed = seed ^ (seed << 17);\n        return seed;\n\
    \    };\n    uint64_t operator()() { return gen(); };\n};\n\n\n#line 7 \"test/yosupo/associative_array_amt.test.cpp\"\
    \n\n#define _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nu64 h(i64 k) {\n    xorshift64 rnd(k);\n  \
    \  rnd(); rnd(); rnd();\n    return rnd();\n};\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    i64 q;\n    cin >> q;\n\n    ArrayMappedTrie<i64,\
    \ 40, 4> mp;\n\n    rep(_, q) {\n        i64 com, k, v;\n\n        cin >> com;\n\
    \n        if (com == 0) {\n            cin >> k >> v;\n            mp[h(k)] =\
    \ v;\n        } else if (com == 1) {\n            cin >> k;\n            cout\
    \ << mp[h(k)] << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include <iostream>\n\n#include \"../../hash_map/array_mapped_trie.hpp\"\n#include\
    \ \"../../util/xorshift.hpp\"\n\n#define _overload(_1, _2, _3, _4, name, ...)\
    \ name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr,\
    \ a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)\n\
    #define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)\n\
    #define rep(...) repeat(__VA_ARGS__)\n\n#define ALL(X) begin(X), end(X)\n\nusing\
    \ namespace std;\nusing i64 = long long;\nusing u64 = unsigned long long;\n\n\
    u64 h(i64 k) {\n    xorshift64 rnd(k);\n    rnd(); rnd(); rnd();\n    return rnd();\n\
    };\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    i64 q;\n    cin >> q;\n\n    ArrayMappedTrie<i64, 40, 4> mp;\n\n    rep(_,\
    \ q) {\n        i64 com, k, v;\n\n        cin >> com;\n\n        if (com == 0)\
    \ {\n            cin >> k >> v;\n            mp[h(k)] = v;\n        } else if\
    \ (com == 1) {\n            cin >> k;\n            cout << mp[h(k)] << endl;\n\
    \        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - hash_map/array_mapped_trie.hpp
  - util/xorshift.hpp
  isVerificationFile: true
  path: test/yosupo/associative_array_amt.test.cpp
  requiredBy: []
  timestamp: '2022-03-04 02:20:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/associative_array_amt.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/associative_array_amt.test.cpp
- /verify/test/yosupo/associative_array_amt.test.cpp.html
title: test/yosupo/associative_array_amt.test.cpp
---
