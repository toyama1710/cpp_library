---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3117_2.test.cpp
    title: test/aoj/3117_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/memory_pool_allocator.hpp\"\n\n\n\n#include <cassert>\n\
    #include <array>\n#include <numeric>\n#include <cstdint>\n\n//===\n\n// for use:\
    \ speed up (ex. persistent data structure)\ntemplate<class T, size_t sz>\nstruct\
    \ MemoryPoolAllocator {\n    using value_type = T;\n    std::array<T *, sz> addr;\n\
    \    std::array<char, sizeof(T) * sz> mem;\n    size_t ptr;\n\n    MemoryPoolAllocator()\
    \ {\n        ptr = 0;\n\n        for (int i = 0; i < sz; i++) {\n            addr[i]\
    \ = (T *)(&(mem[i * sizeof(T)]));\n        }\n    };\n\n    template<class U>\n\
    \    struct rebind {\n        using other = MemoryPoolAllocator<U, sz>;\n    };\n\
    \n    T *allocate(size_t n) {\n        assert(n == 1);\n        return addr[ptr++];\n\
    \    };\n\n    void deallocate(T *p, size_t n) {\n        assert(n == 1);\n  \
    \      addr[--ptr] = p;\n    };\n\n    int max_size() {\n        return 1;\n \
    \   };\n};\n\n//===\n\n"
  code: "#ifndef MEMORY_POOL_ALLOCATOR_HPP\n#define MEMORY_POOL_ALLOCATOR_HPP\n\n\
    #include <cassert>\n#include <array>\n#include <numeric>\n#include <cstdint>\n\
    \n//===\n\n// for use: speed up (ex. persistent data structure)\ntemplate<class\
    \ T, size_t sz>\nstruct MemoryPoolAllocator {\n    using value_type = T;\n   \
    \ std::array<T *, sz> addr;\n    std::array<char, sizeof(T) * sz> mem;\n    size_t\
    \ ptr;\n\n    MemoryPoolAllocator() {\n        ptr = 0;\n\n        for (int i\
    \ = 0; i < sz; i++) {\n            addr[i] = (T *)(&(mem[i * sizeof(T)]));\n \
    \       }\n    };\n\n    template<class U>\n    struct rebind {\n        using\
    \ other = MemoryPoolAllocator<U, sz>;\n    };\n\n    T *allocate(size_t n) {\n\
    \        assert(n == 1);\n        return addr[ptr++];\n    };\n\n    void deallocate(T\
    \ *p, size_t n) {\n        assert(n == 1);\n        addr[--ptr] = p;\n    };\n\
    \n    int max_size() {\n        return 1;\n    };\n};\n\n//===\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: util/memory_pool_allocator.hpp
  requiredBy: []
  timestamp: '2020-06-11 07:49:55+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3117_2.test.cpp
documentation_of: util/memory_pool_allocator.hpp
layout: document
redirect_from:
- /library/util/memory_pool_allocator.hpp
- /library/util/memory_pool_allocator.hpp.html
title: util/memory_pool_allocator.hpp
---
