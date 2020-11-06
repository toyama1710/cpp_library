---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2A_2.test.cpp
    title: test/aoj/DSL2A_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2A_3.test.cpp
    title: test/aoj/DSL2A_3.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_type/max_monoid.hpp\"\n\n\n\n#include <numeric>\n#include\
    \ <algorithm>\n\n//===\ntemplate<class T>\nstruct MinMonoid {\n    using value_type\
    \ = T;\n    inline static T identity() {\n        return std::numeric_limits<T>::min();\n\
    \    };\n    inline static T operation(const T a, const T b) {\n        return\
    \ std::max(a, b);\n    };\n};\n//===\n\n\n"
  code: "#ifndef MAX_MONOID_HPP\n#define MAX_MONOID_HPP\n\n#include <numeric>\n#include\
    \ <algorithm>\n\n//===\ntemplate<class T>\nstruct MinMonoid {\n    using value_type\
    \ = T;\n    inline static T identity() {\n        return std::numeric_limits<T>::min();\n\
    \    };\n    inline static T operation(const T a, const T b) {\n        return\
    \ std::max(a, b);\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: data_type/max_monoid.hpp
  requiredBy: []
  timestamp: '2020-05-07 16:24:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2A_2.test.cpp
  - test/aoj/DSL2A_3.test.cpp
documentation_of: data_type/max_monoid.hpp
layout: document
redirect_from:
- /library/data_type/max_monoid.hpp
- /library/data_type/max_monoid.hpp.html
title: data_type/max_monoid.hpp
---
