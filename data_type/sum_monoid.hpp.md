---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ARC033C.cpp
    title: test/atcoder/ARC033C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL2B.test.cpp
    title: test/aoj/DSL2B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_type/sum_monoid.hpp\"\n\n\n\ntemplate<class T>\nstruct\
    \ SumMonoid {\n    using value_type = T;\n    inline static T identity() {\n \
    \       return (T)0;\n    };\n    inline static T operation(const T a, const T\
    \ b) {\n        return a + b;\n    };\n};\n\n\n"
  code: "#ifndef SUM_MONOID_HPP\n#define SUM_MONOID_HPP\n\ntemplate<class T>\nstruct\
    \ SumMonoid {\n    using value_type = T;\n    inline static T identity() {\n \
    \       return (T)0;\n    };\n    inline static T operation(const T a, const T\
    \ b) {\n        return a + b;\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: data_type/sum_monoid.hpp
  requiredBy:
  - test/atcoder/ARC033C.cpp
  timestamp: '2020-05-07 13:37:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL2B.test.cpp
documentation_of: data_type/sum_monoid.hpp
layout: document
redirect_from:
- /library/data_type/sum_monoid.hpp
- /library/data_type/sum_monoid.hpp.html
title: data_type/sum_monoid.hpp
---
