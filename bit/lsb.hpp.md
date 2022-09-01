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
  bundledCode: "#line 1 \"bit/lsb.hpp\"\n\n\n\n#include <cstdint>\n\ninline uint64_t\
    \ lsb32(uint32_t bits) {\n    return bits & (~bits + 1);\n};\ninline uint64_t\
    \ lsb64(uint64_t bits) {\n    return bits & (~bits + 1);\n};\n\n"
  code: "#ifndef LSB_HPP\n#define LSB_HPP\n\n#include <cstdint>\n\ninline uint64_t\
    \ lsb32(uint32_t bits) {\n    return bits & (~bits + 1);\n};\ninline uint64_t\
    \ lsb64(uint64_t bits) {\n    return bits & (~bits + 1);\n};\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bit/lsb.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/bits.test.cpp
documentation_of: bit/lsb.hpp
layout: document
redirect_from:
- /library/bit/lsb.hpp
- /library/bit/lsb.hpp.html
title: bit/lsb.hpp
---
