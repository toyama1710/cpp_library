---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/bits.test.cpp
    title: test/aoj/bits.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/xorshift.hpp\"\n\n\n\n#include <cstdint>\n\nstruct\
    \ xorshift32 {\n    uint32_t seed = 1710;\n    xorshift32(uint32_t seed) : seed(seed){};\n\
    \    void set_seed(uint32_t s) { seed = s; };\n    uint32_t gen() {\n        seed\
    \ = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 17);\n        seed =\
    \ seed ^ (seed << 5);\n        return seed;\n    };\n    uint32_t operator()()\
    \ { return gen(); };\n};\n\nstruct xorshift64 {\n    uint64_t seed = 1710;\n \
    \   xorshift64(uint64_t seed) : seed(seed){};\n    void set_seed(uint64_t s) {\
    \ seed = s; };\n    uint64_t gen() {\n        seed = seed ^ (seed << 13);\n  \
    \      seed = seed ^ (seed >> 7);\n        seed = seed ^ (seed << 17);\n     \
    \   return seed;\n    };\n    uint64_t operator()() { return gen(); };\n};\n\n\
    \n"
  code: "#ifndef XORSHIFT_HPP\n#define XORSHIFT_HPP\n\n#include <cstdint>\n\nstruct\
    \ xorshift32 {\n    uint32_t seed = 1710;\n    xorshift32(uint32_t seed) : seed(seed){};\n\
    \    void set_seed(uint32_t s) { seed = s; };\n    uint32_t gen() {\n        seed\
    \ = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 17);\n        seed =\
    \ seed ^ (seed << 5);\n        return seed;\n    };\n    uint32_t operator()()\
    \ { return gen(); };\n};\n\nstruct xorshift64 {\n    uint64_t seed = 1710;\n \
    \   xorshift64(uint64_t seed) : seed(seed){};\n    void set_seed(uint64_t s) {\
    \ seed = s; };\n    uint64_t gen() {\n        seed = seed ^ (seed << 13);\n  \
    \      seed = seed ^ (seed >> 7);\n        seed = seed ^ (seed << 17);\n     \
    \   return seed;\n    };\n    uint64_t operator()() { return gen(); };\n};\n\n\
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: util/xorshift.hpp
  requiredBy: []
  timestamp: '2021-12-07 23:05:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/bits.test.cpp
documentation_of: util/xorshift.hpp
layout: document
redirect_from:
- /library/util/xorshift.hpp
- /library/util/xorshift.hpp.html
title: util/xorshift.hpp
---
