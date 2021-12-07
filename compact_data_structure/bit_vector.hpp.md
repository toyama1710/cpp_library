---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: bit/pop_count.hpp
    title: bit/pop_count.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"compact_data_structure/bit_vector.hpp\"\n\n\n\n#include\
    \ <cstdint>\n#include <vector>\n#include <string>\n#line 1 \"bit/pop_count.hpp\"\
    \n\n\n\n#line 5 \"bit/pop_count.hpp\"\n\ninline int popcnt64(uint64_t bits) {\n\
    #ifdef __has_builtin\n    return __builtin_popcountll(bits);\n#else\n    bits\
    \ = (bits & 0x5555555555555555) + (bits >> 1 & 0x5555555555555555);\n    bits\
    \ = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);\n    bits\
    \ = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);\n    bits\
    \ = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);\n    bits\
    \ = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);\n    bits\
    \ = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);\n    return\
    \ bits;\n#endif\n};\n\ninline int popcnt32(uint32_t bits) {\n#ifdef __has_builtin\n\
    \    return __builtin_popcount(bits);\n#else\n    bits = (bits & 0x55555555) +\
    \ (bits >> 1 & 0x55555555);\n    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);\n\
    \    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);\n    bits = (bits\
    \ & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);\n    bits = (bits & 0x0000ffff) +\
    \ (bits >> 16 & 0x0000ffff);\n    return bits;\n#endif\n};\n\n\n#line 8 \"compact_data_structure/bit_vector.hpp\"\
    \n\nstruct BitVector {\n    using u64 = uint64_t;\n    using u32 = uint32_t;\n\
    \    using u8 = uint8_t;\n\n    std::vector<u32> bit;\n    std::vector<u32> chunk;\n\
    \n    BitVector() = default;\n    explicit BitVector(int len) : bit((len + 31)\
    \ / 32, 0), chunk((len + 31) / 32, 0){};\n    BitVector(std::vector<bool> v) :\
    \ bit((v.size() + 31) / 32, 0), chunk((v.size() + 31) / 32, 0) {\n        for\
    \ (int i = 0; i < v.size(); i++) {\n            if (v[i]) set(i);\n        }\n\
    \    };\n    BitVector(std::string s) : bit((s.size() + 31) / 32, 0), chunk((s.size()\
    \ + 31) / 32, 0) {\n        for (int i = 0; i < s.size(); i++) {\n           \
    \ if (s[i] == '1') set(i);\n        }\n    };\n\n    bool operator[] (int k) {\n\
    \        return bool((bit[k / 32] >> (k & 31)) & 1);\n    };\n\n    void set(int\
    \ k) {\n        bit[k / 32] |= 1u << (k & 31);\n    };\n    void build() {\n \
    \       for (int i = 1; i < size(); i++) {\n            chunk[i] = chunk[i - 1]\
    \ + popcnt32(bit[i - 1]);\n        }\n    };\n\n    int size() {\n        return\
    \ bit.size();\n    };\n\n    // count number of 1 in [0, k)\n    int rank1(int\
    \ k) {\n        return chunk[k / 32] +\n        popcnt32(bit[k / 32] & ~((~0u)\
    \ << (k & 31)));\n    };\n    // count number of 0 in [0, k)\n    int rank0(int\
    \ k) {\n        return k - rank1(k);\n    };\n    int select1(int k) {\n     \
    \   int l = 0;\n        int r = size();\n        int m;\n        while (r - l\
    \ > 1) {\n            m = (l + r) >> 1;\n            if (rank1(m) >= k) r = m;\n\
    \            else l = m;\n        }\n        return r - 1;\n    };\n    int select0(int\
    \ k) {\n        int l = 0;\n        int r = size();\n        int m;\n        while\
    \ (r - l > 1) {\n            m = (l + r) >> 1;\n            if (rank0(m) >= k)\
    \ r = m;\n            else l = m;\n        }\n        return r - 1;\n    };\n\
    };\n\n\n"
  code: "#ifndef BIT_VECTOR_HPP\n#define BIT_VECTOR_HPP\n\n#include <cstdint>\n#include\
    \ <vector>\n#include <string>\n#include \"../bit/pop_count.hpp\"\n\nstruct BitVector\
    \ {\n    using u64 = uint64_t;\n    using u32 = uint32_t;\n    using u8 = uint8_t;\n\
    \n    std::vector<u32> bit;\n    std::vector<u32> chunk;\n\n    BitVector() =\
    \ default;\n    explicit BitVector(int len) : bit((len + 31) / 32, 0), chunk((len\
    \ + 31) / 32, 0){};\n    BitVector(std::vector<bool> v) : bit((v.size() + 31)\
    \ / 32, 0), chunk((v.size() + 31) / 32, 0) {\n        for (int i = 0; i < v.size();\
    \ i++) {\n            if (v[i]) set(i);\n        }\n    };\n    BitVector(std::string\
    \ s) : bit((s.size() + 31) / 32, 0), chunk((s.size() + 31) / 32, 0) {\n      \
    \  for (int i = 0; i < s.size(); i++) {\n            if (s[i] == '1') set(i);\n\
    \        }\n    };\n\n    bool operator[] (int k) {\n        return bool((bit[k\
    \ / 32] >> (k & 31)) & 1);\n    };\n\n    void set(int k) {\n        bit[k / 32]\
    \ |= 1u << (k & 31);\n    };\n    void build() {\n        for (int i = 1; i <\
    \ size(); i++) {\n            chunk[i] = chunk[i - 1] + popcnt32(bit[i - 1]);\n\
    \        }\n    };\n\n    int size() {\n        return bit.size();\n    };\n\n\
    \    // count number of 1 in [0, k)\n    int rank1(int k) {\n        return chunk[k\
    \ / 32] +\n        popcnt32(bit[k / 32] & ~((~0u) << (k & 31)));\n    };\n   \
    \ // count number of 0 in [0, k)\n    int rank0(int k) {\n        return k - rank1(k);\n\
    \    };\n    int select1(int k) {\n        int l = 0;\n        int r = size();\n\
    \        int m;\n        while (r - l > 1) {\n            m = (l + r) >> 1;\n\
    \            if (rank1(m) >= k) r = m;\n            else l = m;\n        }\n \
    \       return r - 1;\n    };\n    int select0(int k) {\n        int l = 0;\n\
    \        int r = size();\n        int m;\n        while (r - l > 1) {\n      \
    \      m = (l + r) >> 1;\n            if (rank0(m) >= k) r = m;\n            else\
    \ l = m;\n        }\n        return r - 1;\n    };\n};\n\n#endif"
  dependsOn:
  - bit/pop_count.hpp
  isVerificationFile: false
  path: compact_data_structure/bit_vector.hpp
  requiredBy: []
  timestamp: '2021-12-07 22:49:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: compact_data_structure/bit_vector.hpp
layout: document
redirect_from:
- /library/compact_data_structure/bit_vector.hpp
- /library/compact_data_structure/bit_vector.hpp.html
title: compact_data_structure/bit_vector.hpp
---
