---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum1.test.cpp
    title: test/yosupo/rectangle_sum1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/coordinate_compression.hpp\"\n\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <class T>\nstruct CoordinateCompression {\n    std::vector<T>\
    \ p;\n\n    template <class InputItr>\n    CoordinateCompression(InputItr first,\
    \ InputItr last) : p(first, last) {\n        std::sort(p.begin(), p.end());\n\
    \        p.erase(unique(p.begin(), p.end()), p.end());\n    };\n    int zip(T\
    \ x) {\n        return std::lower_bound(p.begin(), p.end(), x) - p.begin();\n\
    \    };\n    T unzip(int x) {\n        return p[x];\n    };\n    int size() {\n\
    \        return p.size();\n    };\n};\n\ntemplate <class T>\nstruct CoordinateCompressionBuilder\
    \ {\n    std::vector<T> p;\n\n    CoordinateCompressionBuilder() = default;\n\
    \    template <class InputItr>\n    CoordinateCompressionBuilder(InputItr first,\
    \ InputItr last)\n        : p(first, last){};\n    void push(T x) {\n        p.push_back(x);\n\
    \    };\n    CoordinateCompression<T> build() {\n        return CoordinateCompression<T>(p.begin(),\
    \ p.end());\n    };\n};\n\n\n"
  code: "#ifndef COORDINATE_COMPRESSION_HPP\n#define COORDINATE_COMPRESSION_HPP\n\
    #include <algorithm>\n#include <vector>\n\ntemplate <class T>\nstruct CoordinateCompression\
    \ {\n    std::vector<T> p;\n\n    template <class InputItr>\n    CoordinateCompression(InputItr\
    \ first, InputItr last) : p(first, last) {\n        std::sort(p.begin(), p.end());\n\
    \        p.erase(unique(p.begin(), p.end()), p.end());\n    };\n    int zip(T\
    \ x) {\n        return std::lower_bound(p.begin(), p.end(), x) - p.begin();\n\
    \    };\n    T unzip(int x) {\n        return p[x];\n    };\n    int size() {\n\
    \        return p.size();\n    };\n};\n\ntemplate <class T>\nstruct CoordinateCompressionBuilder\
    \ {\n    std::vector<T> p;\n\n    CoordinateCompressionBuilder() = default;\n\
    \    template <class InputItr>\n    CoordinateCompressionBuilder(InputItr first,\
    \ InputItr last)\n        : p(first, last){};\n    void push(T x) {\n        p.push_back(x);\n\
    \    };\n    CoordinateCompression<T> build() {\n        return CoordinateCompression<T>(p.begin(),\
    \ p.end());\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: util/coordinate_compression.hpp
  requiredBy: []
  timestamp: '2022-08-07 21:13:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_sum1.test.cpp
documentation_of: util/coordinate_compression.hpp
layout: document
redirect_from:
- /library/util/coordinate_compression.hpp
- /library/util/coordinate_compression.hpp.html
title: util/coordinate_compression.hpp
---
