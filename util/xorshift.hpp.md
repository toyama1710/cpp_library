---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/xorshift.hpp\"\n#include <iostream>\n#include <cstdint>\n\
    #include <ctime>\n\n//===\nstatic uint32_t __seed__ = 1710;\nuint32_t xorshift32()\
    \ {\n    __seed__ = __seed__ ^ (__seed__ << 13);\n    __seed__ = __seed__ ^ (__seed__\
    \ >> 17);\n    __seed__ = __seed__ ^ (__seed__ << 5);\n    return __seed__;\n\
    }\nvoid set_seed(uint32_t s) {\n    __seed__ = s;\n};\n//===\n"
  code: "#include <iostream>\n#include <cstdint>\n#include <ctime>\n\n//===\nstatic\
    \ uint32_t __seed__ = 1710;\nuint32_t xorshift32() {\n    __seed__ = __seed__\
    \ ^ (__seed__ << 13);\n    __seed__ = __seed__ ^ (__seed__ >> 17);\n    __seed__\
    \ = __seed__ ^ (__seed__ << 5);\n    return __seed__;\n}\nvoid set_seed(uint32_t\
    \ s) {\n    __seed__ = s;\n};\n//==="
  dependsOn: []
  isVerificationFile: false
  path: util/xorshift.hpp
  requiredBy: []
  timestamp: '2020-07-25 00:09:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/xorshift.hpp
layout: document
redirect_from:
- /library/util/xorshift.hpp
- /library/util/xorshift.hpp.html
title: util/xorshift.hpp
---
