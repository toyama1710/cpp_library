---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL2A_1.test.cpp
    title: test/aoj/DSL2A_1.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_rmq.test.cpp
    title: test/yosupo/static_rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_type/min_monoid.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n\n//===\ntemplate <class T>\nstruct MinMonoid\
    \ {\n    using value_type = T;\n    inline static T identity() {\n        return\
    \ std::numeric_limits<T>::max();\n    };\n    inline static T operation(const\
    \ T a, const T b) {\n        return std::min(a, b);\n    };\n};\n//===\n\n\n"
  code: "#ifndef MIN_MONOID_HPP\n#define MIN_MONOID_HPP\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n\n//===\ntemplate <class T>\nstruct MinMonoid\
    \ {\n    using value_type = T;\n    inline static T identity() {\n        return\
    \ std::numeric_limits<T>::max();\n    };\n    inline static T operation(const\
    \ T a, const T b) {\n        return std::min(a, b);\n    };\n};\n//===\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: data_type/min_monoid.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static_rmq.test.cpp
  - test/aoj/DSL2A_1.test.cpp
documentation_of: data_type/min_monoid.hpp
layout: document
redirect_from:
- /library/data_type/min_monoid.hpp
- /library/data_type/min_monoid.hpp.html
title: data_type/min_monoid.hpp
---
