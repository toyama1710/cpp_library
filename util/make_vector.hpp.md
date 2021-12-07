---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0407.test.cpp
    title: test/aoj/0407.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/IPT1_6_C.test.cpp
    title: test/aoj/IPT1_6_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/make_vector.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <initializer_list>\n#include <vector>\n\ntemplate <class T, uint64_t N>\nauto\
    \ make_vector_(const uint64_t *dim, T e) {\n    if constexpr (N == 1) {\n    \
    \    return std::vector<T>(*dim, e);\n    } else {\n        auto v = make_vector_<T,\
    \ N - 1>(dim + 1, e);\n        return std::vector<decltype(v)>(*dim, v);\n   \
    \ }\n};\ntemplate <class T, uint64_t N>\nauto make_vector(const uint64_t (&dim)[N],\
    \ const T &e) {\n    assert(N > 0);\n    return make_vector_<T, N>(dim, e);\n\
    };\n\n\n"
  code: "#ifndef MAKE_VECTOR_HPP\n#define MAKE_VECTOR_HPP\n\n#include <cassert>\n\
    #include <initializer_list>\n#include <vector>\n\ntemplate <class T, uint64_t\
    \ N>\nauto make_vector_(const uint64_t *dim, T e) {\n    if constexpr (N == 1)\
    \ {\n        return std::vector<T>(*dim, e);\n    } else {\n        auto v = make_vector_<T,\
    \ N - 1>(dim + 1, e);\n        return std::vector<decltype(v)>(*dim, v);\n   \
    \ }\n};\ntemplate <class T, uint64_t N>\nauto make_vector(const uint64_t (&dim)[N],\
    \ const T &e) {\n    assert(N > 0);\n    return make_vector_<T, N>(dim, e);\n\
    };\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: util/make_vector.hpp
  requiredBy: []
  timestamp: '2021-12-07 20:27:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0407.test.cpp
  - test/aoj/IPT1_6_C.test.cpp
documentation_of: util/make_vector.hpp
layout: document
redirect_from:
- /library/util/make_vector.hpp
- /library/util/make_vector.hpp.html
title: util/make_vector.hpp
---
