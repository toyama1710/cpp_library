---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/bits.test.cpp
    title: test/aoj/bits.test.cpp
  - icon: ':x:'
    path: test/yosupo/associative_array_amt.test.cpp
    title: test/yosupo/associative_array_amt.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/xorshift.hpp\"\n\n\n\n#include <cstdint>\n\nstruct\
    \ xorshift32 {\n    uint32_t seed;\n    xorshift32(uint32_t seed = 1710) : seed(seed){};\n\
    \    void set_seed(uint32_t s) {\n        seed = s;\n    };\n    uint32_t gen()\
    \ {\n        seed = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 17);\n\
    \        seed = seed ^ (seed << 5);\n        return seed;\n    };\n    uint32_t\
    \ operator()() {\n        return gen();\n    };\n};\n\nstruct xorshift64 {\n \
    \   uint64_t seed;\n    xorshift64(uint64_t seed = 1710) : seed(seed){};\n   \
    \ void set_seed(uint64_t s) {\n        seed = s;\n    };\n    uint64_t gen() {\n\
    \        seed = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 7);\n   \
    \     seed = seed ^ (seed << 17);\n        return seed;\n    };\n    uint64_t\
    \ operator()() {\n        return gen();\n    };\n};\n\n\n"
  code: "#ifndef XORSHIFT_HPP\n#define XORSHIFT_HPP\n\n#include <cstdint>\n\nstruct\
    \ xorshift32 {\n    uint32_t seed;\n    xorshift32(uint32_t seed = 1710) : seed(seed){};\n\
    \    void set_seed(uint32_t s) {\n        seed = s;\n    };\n    uint32_t gen()\
    \ {\n        seed = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 17);\n\
    \        seed = seed ^ (seed << 5);\n        return seed;\n    };\n    uint32_t\
    \ operator()() {\n        return gen();\n    };\n};\n\nstruct xorshift64 {\n \
    \   uint64_t seed;\n    xorshift64(uint64_t seed = 1710) : seed(seed){};\n   \
    \ void set_seed(uint64_t s) {\n        seed = s;\n    };\n    uint64_t gen() {\n\
    \        seed = seed ^ (seed << 13);\n        seed = seed ^ (seed >> 7);\n   \
    \     seed = seed ^ (seed << 17);\n        return seed;\n    };\n    uint64_t\
    \ operator()() {\n        return gen();\n    };\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: util/xorshift.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/associative_array_amt.test.cpp
  - test/aoj/bits.test.cpp
documentation_of: util/xorshift.hpp
layout: document
redirect_from:
- /library/util/xorshift.hpp
- /library/util/xorshift.hpp.html
title: util/xorshift.hpp
---
