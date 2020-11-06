---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/sparse_array.hpp\"\n#include <iostream>\n#include <cstdio>\n\
    #include <vector>\n#include <cstdint>\n#include <array>\n\n//===\n// #include\
    \ <cstdint>\n// #include <array>\ntemplate<class T, size_t N, size_t BlockSize\
    \ = 64>\nstruct SparseArray {\n    std::array<T *, (N + BlockSize - 1) / BlockSize>\
    \ ptr;\n\n    SparseArray() {\n        ptr.fill(nullptr);\n    };\n\n    ~SparseArray()\
    \ {\n        clear();\n    };\n\n    void clear() {\n        for (auto p:ptr)\
    \ delete p;\n        ptr.fill(nullptr);\n    };\n\n    T& operator [](size_t k)\
    \ {\n        if (!ptr[k / BlockSize]) ptr[k / BlockSize] = new T[BlockSize];\n\
    \        return &((ptr[k / BlockSize])[k % BlockSize]);\n    };\n};\n//===\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <vector>\n#include <cstdint>\n\
    #include <array>\n\n//===\n// #include <cstdint>\n// #include <array>\ntemplate<class\
    \ T, size_t N, size_t BlockSize = 64>\nstruct SparseArray {\n    std::array<T\
    \ *, (N + BlockSize - 1) / BlockSize> ptr;\n\n    SparseArray() {\n        ptr.fill(nullptr);\n\
    \    };\n\n    ~SparseArray() {\n        clear();\n    };\n\n    void clear()\
    \ {\n        for (auto p:ptr) delete p;\n        ptr.fill(nullptr);\n    };\n\n\
    \    T& operator [](size_t k) {\n        if (!ptr[k / BlockSize]) ptr[k / BlockSize]\
    \ = new T[BlockSize];\n        return &((ptr[k / BlockSize])[k % BlockSize]);\n\
    \    };\n};\n//===\n"
  dependsOn: []
  isVerificationFile: false
  path: util/sparse_array.hpp
  requiredBy: []
  timestamp: '2020-05-07 13:13:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/sparse_array.hpp
layout: document
redirect_from:
- /library/util/sparse_array.hpp
- /library/util/sparse_array.hpp.html
title: util/sparse_array.hpp
---
