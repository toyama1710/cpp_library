---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1418.test.cpp
    title: test/aoj/1418.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1418_2.test.cpp
    title: test/aoj/1418_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/prime_factorize_table.hpp\"\n\n\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nstruct PrimeFactorizeTable {\n    using\
    \ P = std::pair<int, int>;  // prod(table[i], first ** second) = i\n    std::vector<std::vector<P>>\
    \ table;\n\n    PrimeFactorizeTable(int n) : table(n + 1) {\n        for (int\
    \ i = 2; i <= n; i++) {\n            if (!table[i].empty()) continue;\n      \
    \      for (int j = i; j <= n; j += i) {\n                table[j].push_back(P(i,\
    \ 0));\n                int tmp = j;\n                while (tmp > 1 && tmp %\
    \ i == 0) {\n                    table[j].back().second++;\n                 \
    \   tmp /= i;\n                }\n            }\n        }\n    };\n\n    std::vector<P>\
    \ factorize(int n) {\n        assert(n > 1);\n        return table[n];\n    };\n\
    };\n\n\n"
  code: "#ifndef PRIME_FACTORIZE_TABLE_HPP\n#define PRIME_FACTORIZE_TABLE_HPP\n\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nstruct PrimeFactorizeTable\
    \ {\n    using P = std::pair<int, int>;  // prod(table[i], first ** second) =\
    \ i\n    std::vector<std::vector<P>> table;\n\n    PrimeFactorizeTable(int n)\
    \ : table(n + 1) {\n        for (int i = 2; i <= n; i++) {\n            if (!table[i].empty())\
    \ continue;\n            for (int j = i; j <= n; j += i) {\n                table[j].push_back(P(i,\
    \ 0));\n                int tmp = j;\n                while (tmp > 1 && tmp %\
    \ i == 0) {\n                    table[j].back().second++;\n                 \
    \   tmp /= i;\n                }\n            }\n        }\n    };\n\n    std::vector<P>\
    \ factorize(int n) {\n        assert(n > 1);\n        return table[n];\n    };\n\
    };\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factorize_table.hpp
  requiredBy: []
  timestamp: '2022-04-17 00:42:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1418_2.test.cpp
  - test/aoj/1418.test.cpp
documentation_of: math/prime_factorize_table.hpp
layout: document
redirect_from:
- /library/math/prime_factorize_table.hpp
- /library/math/prime_factorize_table.hpp.html
title: math/prime_factorize_table.hpp
---
