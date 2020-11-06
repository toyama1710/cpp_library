---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum1.test.cpp
    title: test/yosupo/rectangle_sum1.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/coordinate_compression.hpp\"\n\n\n// header file section\n\
    #include <vector>\n#include <iterator>\n#include <algorithm>\n#include <cassert>\n\
    \n//===\n// library section\n// <iterator>\nstruct CoordinateCompression {\n \
    \   using llong = long long;\n    std::vector<llong> p;\n\n#ifndef NDEBUG\n  \
    \  bool builded = false;\n#endif\n\n    CoordinateCompression () {};\n    template\
    \ <class InputItr>\n    CoordinateCompression (InputItr first, InputItr last)\
    \ {\n        p.reserve(std::distance(first, last));\n        for (auto itr = first;\
    \ itr != last; itr++) {\n            p.push_back(*itr);\n        }\n        build();\n\
    \    };\n\n    void build() {\n        std::sort(p.begin(), p.end());\n      \
    \  p.erase(unique(p.begin(), p.end()), p.end());\n#ifndef NDEBUG\n        builded\
    \ = true;\n#endif\n    };\n\n    void add(llong a) {\n        p.push_back(a);\n\
    #ifndef NDEBUG\n        builded = false;\n#endif\n    };\n    void push(llong\
    \ a) {\n        add(a);\n    }\n\n    llong zip(llong x) {\n#ifndef NDEBUG\n \
    \       assert(builded);\n#endif\n        return std::lower_bound(p.begin(), p.end(),\
    \ x) - p.begin();\n    };\n    llong unzip(llong x) {\n#ifndef NDEBUG\n      \
    \  assert(builded);\n#endif\n        return p[x];\n    };\n\n    llong size()\
    \ {\n        return p.size();\n    };\n};\n//===\n\n"
  code: "#ifndef COORDINATE_COMPRESSION_HPP\n#define COORDINATE_COMPRESSION_HPP\n\
    // header file section\n#include <vector>\n#include <iterator>\n#include <algorithm>\n\
    #include <cassert>\n\n//===\n// library section\n// <iterator>\nstruct CoordinateCompression\
    \ {\n    using llong = long long;\n    std::vector<llong> p;\n\n#ifndef NDEBUG\n\
    \    bool builded = false;\n#endif\n\n    CoordinateCompression () {};\n    template\
    \ <class InputItr>\n    CoordinateCompression (InputItr first, InputItr last)\
    \ {\n        p.reserve(std::distance(first, last));\n        for (auto itr = first;\
    \ itr != last; itr++) {\n            p.push_back(*itr);\n        }\n        build();\n\
    \    };\n\n    void build() {\n        std::sort(p.begin(), p.end());\n      \
    \  p.erase(unique(p.begin(), p.end()), p.end());\n#ifndef NDEBUG\n        builded\
    \ = true;\n#endif\n    };\n\n    void add(llong a) {\n        p.push_back(a);\n\
    #ifndef NDEBUG\n        builded = false;\n#endif\n    };\n    void push(llong\
    \ a) {\n        add(a);\n    }\n\n    llong zip(llong x) {\n#ifndef NDEBUG\n \
    \       assert(builded);\n#endif\n        return std::lower_bound(p.begin(), p.end(),\
    \ x) - p.begin();\n    };\n    llong unzip(llong x) {\n#ifndef NDEBUG\n      \
    \  assert(builded);\n#endif\n        return p[x];\n    };\n\n    llong size()\
    \ {\n        return p.size();\n    };\n};\n//===\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: util/coordinate_compression.hpp
  requiredBy: []
  timestamp: '2020-04-30 19:50:45+00:00'
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
