---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2444_2.test.cpp
    title: test/aoj/2444_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\n\n\n\n#include <cstdint>\n\n\
    //===\n//#include <cstdint>\ntemplate <uint64_t base, uint64_t mod>\nstruct RollingHash\
    \ {\n    const std::string s;\n    const int len;\n    std::vector<uint64_t> hashed,\
    \ power;\n\n    RollingHash(const std::string &s) : s(s), len(s.size()) {\n  \
    \      hashed.assign(len + 1, 0);\n        power.assign(len + 1, 1);\n\n     \
    \   for (int i = 0; i < len; i++) {\n            hashed[i + 1] = (hashed[i] *\
    \ base + s[i]) % mod;\n            power[i + 1] = power[i] * base % mod;\n   \
    \     }\n    };\n\n    // s[l, r)\n    uint64_t get_hash(int l, int r) {\n   \
    \     uint64_t res = hashed[r] + mod - hashed[l] * power[r - l] % mod;\n     \
    \   if (res >= mod) res -= mod;\n        return res;\n    };\n};\n\ntemplate <uint64_t\
    \ base>\nstruct RollingHash<base, (1ull << 61ull) - 1ull> {\n    const std::string\
    \ s;\n    const int len;\n    const uint64_t mask30 = (1ull << 30ull) - 1ull;\n\
    \    const uint64_t mask31 = (1ull << 31ull) - 1ull;\n    const uint64_t mod =\
    \ (1ull << 61ull) - 1ull;\n    std::vector<uint64_t> hashed, power;\n\n    RollingHash(const\
    \ std::string &s) : s(s), len(s.size()) {\n        hashed.assign(len + 1, 0);\n\
    \        power.assign(len + 1, 1);\n\n        for (int i = 0; i < len; i++) {\n\
    \            hashed[i + 1] = calc_mod(mul(hashed[i], base) + s[i]);\n        \
    \    power[i + 1] = calc_mod(mul(power[i], base));\n        }\n    };\n\n    //\
    \ s[l, r)\n    uint64_t get_hash(int l, int r) {\n        uint64_t res = hashed[r]\
    \ + mod - calc_mod(mul(hashed[l], power[r - l]));\n        if (res >= mod) res\
    \ -= mod;\n        return res;\n    };\n\n    inline uint64_t mul(uint64_t l,\
    \ uint64_t r) {\n        uint64_t lu = l >> 31;\n        uint64_t ld = l & mask31;\n\
    \        uint64_t ru = r >> 31;\n        uint64_t rd = r & mask31;\n        uint64_t\
    \ mid = ld * ru + lu * rd;\n\n        return ((lu * ru) << 1) + (mid >> 30) +\
    \ ((mid & mask30) << 31) +\n               ld * rd;\n    };\n\n    inline uint64_t\
    \ calc_mod(uint64_t v) {\n        v = (v & mod) + (v >> 61);\n        if (v >=\
    \ mod) v -= mod;\n        return v;\n    };\n};\n\ntemplate <uint64_t base>\n\
    using MRollingHash = RollingHash<base, (1ull << 61ull) - 1ull>;\n//===\n\n\n"
  code: "#ifndef ROLLING_HASH_HPP\n#define ROLLING_HASH_HPP\n\n#include <cstdint>\n\
    \n//===\n//#include <cstdint>\ntemplate <uint64_t base, uint64_t mod>\nstruct\
    \ RollingHash {\n    const std::string s;\n    const int len;\n    std::vector<uint64_t>\
    \ hashed, power;\n\n    RollingHash(const std::string &s) : s(s), len(s.size())\
    \ {\n        hashed.assign(len + 1, 0);\n        power.assign(len + 1, 1);\n\n\
    \        for (int i = 0; i < len; i++) {\n            hashed[i + 1] = (hashed[i]\
    \ * base + s[i]) % mod;\n            power[i + 1] = power[i] * base % mod;\n \
    \       }\n    };\n\n    // s[l, r)\n    uint64_t get_hash(int l, int r) {\n \
    \       uint64_t res = hashed[r] + mod - hashed[l] * power[r - l] % mod;\n   \
    \     if (res >= mod) res -= mod;\n        return res;\n    };\n};\n\ntemplate\
    \ <uint64_t base>\nstruct RollingHash<base, (1ull << 61ull) - 1ull> {\n    const\
    \ std::string s;\n    const int len;\n    const uint64_t mask30 = (1ull << 30ull)\
    \ - 1ull;\n    const uint64_t mask31 = (1ull << 31ull) - 1ull;\n    const uint64_t\
    \ mod = (1ull << 61ull) - 1ull;\n    std::vector<uint64_t> hashed, power;\n\n\
    \    RollingHash(const std::string &s) : s(s), len(s.size()) {\n        hashed.assign(len\
    \ + 1, 0);\n        power.assign(len + 1, 1);\n\n        for (int i = 0; i < len;\
    \ i++) {\n            hashed[i + 1] = calc_mod(mul(hashed[i], base) + s[i]);\n\
    \            power[i + 1] = calc_mod(mul(power[i], base));\n        }\n    };\n\
    \n    // s[l, r)\n    uint64_t get_hash(int l, int r) {\n        uint64_t res\
    \ = hashed[r] + mod - calc_mod(mul(hashed[l], power[r - l]));\n        if (res\
    \ >= mod) res -= mod;\n        return res;\n    };\n\n    inline uint64_t mul(uint64_t\
    \ l, uint64_t r) {\n        uint64_t lu = l >> 31;\n        uint64_t ld = l &\
    \ mask31;\n        uint64_t ru = r >> 31;\n        uint64_t rd = r & mask31;\n\
    \        uint64_t mid = ld * ru + lu * rd;\n\n        return ((lu * ru) << 1)\
    \ + (mid >> 30) + ((mid & mask30) << 31) +\n               ld * rd;\n    };\n\n\
    \    inline uint64_t calc_mod(uint64_t v) {\n        v = (v & mod) + (v >> 61);\n\
    \        if (v >= mod) v -= mod;\n        return v;\n    };\n};\n\ntemplate <uint64_t\
    \ base>\nusing MRollingHash = RollingHash<base, (1ull << 61ull) - 1ull>;\n//===\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2444_2.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
