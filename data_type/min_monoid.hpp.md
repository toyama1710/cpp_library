---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2A_1.test.cpp
    title: test/aoj/DSL2A_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_rmq.test.cpp
    title: test/yosupo/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_type/min_monoid.hpp\"\n\n\n\n#include <numeric>\n#include\
    \ <limits>\n#include <algorithm>\n\n//===\ntemplate<class T>\nstruct MinMonoid\
    \ {\n    using value_type = T;\n    inline static T identity() {\n        return\
    \ std::numeric_limits<T>::max();\n    };\n    inline static T operation(const\
    \ T a, const T b) {\n        return std::min(a, b);\n    };\n};\n//===\n\n\n"
  code: "#ifndef MIN_MONOID_HPP\n#define MIN_MONOID_HPP\n\n#include <numeric>\n#include\
    \ <limits>\n#include <algorithm>\n\n//===\ntemplate<class T>\nstruct MinMonoid\
    \ {\n    using value_type = T;\n    inline static T identity() {\n        return\
    \ std::numeric_limits<T>::max();\n    };\n    inline static T operation(const\
    \ T a, const T b) {\n        return std::min(a, b);\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: data_type/min_monoid.hpp
  requiredBy: []
  timestamp: '2021-08-19 23:45:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2A_1.test.cpp
  - test/yosupo/static_rmq.test.cpp
documentation_of: data_type/min_monoid.hpp
layout: document
redirect_from:
- /library/data_type/min_monoid.hpp
- /library/data_type/min_monoid.hpp.html
title: data_type/min_monoid.hpp
---
