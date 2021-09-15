---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: compact_data_structure/bit_vector.hpp
    title: compact_data_structure/bit_vector.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bit/pop_count.hpp\"\n\n\n\n#include <cstdint>\n\n//===\n\
    int popcnt64(uint64_t bits) {\n#ifdef __has_builtin\n    return __builtin_popcountll(bits);\n\
    #else\n    bits = (bits & 0x5555555555555555) + (bits >> 1  & 0x5555555555555555);\n\
    \    bits = (bits & 0x3333333333333333) + (bits >> 2  & 0x3333333333333333);\n\
    \    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4  & 0x0f0f0f0f0f0f0f0f);\n\
    \    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8  & 0x00ff00ff00ff00ff);\n\
    \    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);\n\
    \    bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);\n\
    \    return bits;\n#endif\n}\nint popcnt32(uint32_t bits) {\n#ifdef __has_builtin\n\
    \    return __builtin_popcount(bits);\n#else\n    bits = (bits & 0x55555555) +\
    \ (bits >> 1 & 0x55555555);\n    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);\n\
    \    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);\n    bits = (bits\
    \ & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);\n    bits = (bits & 0x0000ffff) +\
    \ (bits >> 16 & 0x0000ffff);\n    return bits;\n#endif\n}\n//===\n\n\n"
  code: "#ifndef POP_COUNT_HPP\n#define POP_COUNT_HPP\n\n#include <cstdint>\n\n//===\n\
    int popcnt64(uint64_t bits) {\n#ifdef __has_builtin\n    return __builtin_popcountll(bits);\n\
    #else\n    bits = (bits & 0x5555555555555555) + (bits >> 1  & 0x5555555555555555);\n\
    \    bits = (bits & 0x3333333333333333) + (bits >> 2  & 0x3333333333333333);\n\
    \    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4  & 0x0f0f0f0f0f0f0f0f);\n\
    \    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8  & 0x00ff00ff00ff00ff);\n\
    \    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);\n\
    \    bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);\n\
    \    return bits;\n#endif\n}\nint popcnt32(uint32_t bits) {\n#ifdef __has_builtin\n\
    \    return __builtin_popcount(bits);\n#else\n    bits = (bits & 0x55555555) +\
    \ (bits >> 1 & 0x55555555);\n    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);\n\
    \    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);\n    bits = (bits\
    \ & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);\n    bits = (bits & 0x0000ffff) +\
    \ (bits >> 16 & 0x0000ffff);\n    return bits;\n#endif\n}\n//===\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: bit/pop_count.hpp
  requiredBy:
  - compact_data_structure/bit_vector.hpp
  timestamp: '2020-07-23 12:06:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/pop_count.hpp
layout: document
redirect_from:
- /library/bit/pop_count.hpp
- /library/bit/pop_count.hpp.html
title: bit/pop_count.hpp
---