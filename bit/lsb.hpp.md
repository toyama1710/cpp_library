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
  bundledCode: '#line 1 "bit/lsb.hpp"




    #include <cstdint>


    inline uint64_t lsb32(uint32_t bits) { return bits & (~bits + 1); };

    inline uint64_t lsb64(uint64_t bits) { return bits & (~bits + 1); };


    '
  code: '#ifndef LSB_HPP

    #define LSB_HPP


    #include <cstdint>


    inline uint64_t lsb32(uint32_t bits) { return bits & (~bits + 1); };

    inline uint64_t lsb64(uint64_t bits) { return bits & (~bits + 1); };

    #endif'
  dependsOn: []
  isVerificationFile: false
  path: bit/lsb.hpp
  requiredBy: []
  timestamp: '2021-12-07 22:49:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/lsb.hpp
layout: document
redirect_from:
- /library/bit/lsb.hpp
- /library/bit/lsb.hpp.html
title: bit/lsb.hpp
---
