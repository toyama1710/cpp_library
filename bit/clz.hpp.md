---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/bits.test.cpp
    title: test/aoj/bits.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bit/clz.hpp\"\n\n\n\n#include <cstdint>\n\ninline int clz32_(uint32_t\
    \ bit) {\n    static const int table[] = {\n        31, 30, 29, 25, 28, 20, 24,\
    \ 15, 27, 17, 19, 10, 23, 8,  14, 5,\n        0,  26, 21, 16, 18, 11, 9,  6, \
    \ 1,  22, 12, 7,  2,  13, 3,  4,\n    };\n    static const uint32_t de_bruijn\
    \ = 0x04653adf;\n\n    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit\
    \ >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n    bit ^= bit >> 1;\n \
    \   return table[(bit * de_bruijn) >> 27];\n};\ninline int clz32(uint32_t bit)\
    \ {\n    if (bit == 0) return 32;\n#ifdef __has_builtin\n    return __builtin_clz(bit);\n\
    #else\n    return clz32_(bit);\n#endif\n};\n\ninline int clz64_(uint64_t bit)\
    \ {\n    static const int table[] = {\n        63, 62, 61, 56, 60, 50, 55, 44,\
    \ 59, 38, 49, 35, 54, 29, 43, 23,\n        58, 46, 37, 25, 48, 17, 34, 15, 53,\
    \ 32, 28, 9,  42, 13, 22, 6,\n        0,  57, 51, 45, 39, 36, 30, 24, 47, 26,\
    \ 18, 16, 33, 10, 14, 7,\n        1,  52, 40, 31, 27, 19, 11, 8,  2,  41, 20,\
    \ 12, 3,  21, 4,  5,\n    };\n    static const uint64_t de_bruijn = 0x0218a392cd3d5dbfull;\n\
    \    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit >> 4;\n    bit |=\
    \ bit >> 8;\n    bit |= bit >> 16;\n    bit |= bit >> 32;\n    bit ^= bit >> 1;\n\
    \    return table[(bit * de_bruijn) >> 58];\n};\ninline int clz64(uint64_t bit)\
    \ {\n    if (bit == 0) return 64;\n#ifdef __has_builtin\n    return __builtin_clzll(bit);\n\
    #else\n    return clz64_(bit);\n#endif\n};\n\n\n"
  code: "#ifndef CLZ_HPP\n#define CLZ_HPP\n\n#include <cstdint>\n\ninline int clz32_(uint32_t\
    \ bit) {\n    static const int table[] = {\n        31, 30, 29, 25, 28, 20, 24,\
    \ 15, 27, 17, 19, 10, 23, 8,  14, 5,\n        0,  26, 21, 16, 18, 11, 9,  6, \
    \ 1,  22, 12, 7,  2,  13, 3,  4,\n    };\n    static const uint32_t de_bruijn\
    \ = 0x04653adf;\n\n    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit\
    \ >> 4;\n    bit |= bit >> 8;\n    bit |= bit >> 16;\n    bit ^= bit >> 1;\n \
    \   return table[(bit * de_bruijn) >> 27];\n};\ninline int clz32(uint32_t bit)\
    \ {\n    if (bit == 0) return 32;\n#ifdef __has_builtin\n    return __builtin_clz(bit);\n\
    #else\n    return clz32_(bit);\n#endif\n};\n\ninline int clz64_(uint64_t bit)\
    \ {\n    static const int table[] = {\n        63, 62, 61, 56, 60, 50, 55, 44,\
    \ 59, 38, 49, 35, 54, 29, 43, 23,\n        58, 46, 37, 25, 48, 17, 34, 15, 53,\
    \ 32, 28, 9,  42, 13, 22, 6,\n        0,  57, 51, 45, 39, 36, 30, 24, 47, 26,\
    \ 18, 16, 33, 10, 14, 7,\n        1,  52, 40, 31, 27, 19, 11, 8,  2,  41, 20,\
    \ 12, 3,  21, 4,  5,\n    };\n    static const uint64_t de_bruijn = 0x0218a392cd3d5dbfull;\n\
    \    bit |= bit >> 1;\n    bit |= bit >> 2;\n    bit |= bit >> 4;\n    bit |=\
    \ bit >> 8;\n    bit |= bit >> 16;\n    bit |= bit >> 32;\n    bit ^= bit >> 1;\n\
    \    return table[(bit * de_bruijn) >> 58];\n};\ninline int clz64(uint64_t bit)\
    \ {\n    if (bit == 0) return 64;\n#ifdef __has_builtin\n    return __builtin_clzll(bit);\n\
    #else\n    return clz64_(bit);\n#endif\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bit/clz.hpp
  requiredBy: []
  timestamp: '2021-12-09 21:00:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/bits.test.cpp
documentation_of: bit/clz.hpp
layout: document
redirect_from:
- /library/bit/clz.hpp
- /library/bit/clz.hpp.html
title: bit/clz.hpp
---
