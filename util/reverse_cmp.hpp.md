---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
    title: test/aoj/ALDS1_9_C_leftist_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
    title: test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"util/reverse_cmp.hpp\"\n\n\n\ntemplate <class T>\nstruct\
    \ RevCmp {\n    T val;\n\n    RevCmp(T val) : val(val){};\n\n    bool operator<(const\
    \ RevCmp &rhs) const { return rhs.val < val; };\n    bool operator>(const RevCmp\
    \ &rhs) const { return val < rhs.val; };\n    bool operator==(const RevCmp &rhs)\
    \ const {\n        return !(val < rhs.val || rhs.val < val);\n    };\n    bool\
    \ operator!=(const RevCmp &rhs) const {\n        return val < rhs.val || rhs.val\
    \ < val;\n    };\n    bool operator<=(const RevCmp &rhs) const {\n        return\
    \ *this < rhs || *this == rhs;\n    };\n    bool operator>=(const RevCmp &rhs)\
    \ const {\n        return *this > rhs || *this == rhs;\n    };\n\n    RevCmp &operator=(const\
    \ RevCmp &rhs) {\n        val = rhs.val;\n        return *this;\n    };\n\n  \
    \  T value() const { return val; };\n};\n\n\n"
  code: "#ifndef REVERSE_CMP_HPP\n#define REVERSE_CMP_HPP\n\ntemplate <class T>\n\
    struct RevCmp {\n    T val;\n\n    RevCmp(T val) : val(val){};\n\n    bool operator<(const\
    \ RevCmp &rhs) const { return rhs.val < val; };\n    bool operator>(const RevCmp\
    \ &rhs) const { return val < rhs.val; };\n    bool operator==(const RevCmp &rhs)\
    \ const {\n        return !(val < rhs.val || rhs.val < val);\n    };\n    bool\
    \ operator!=(const RevCmp &rhs) const {\n        return val < rhs.val || rhs.val\
    \ < val;\n    };\n    bool operator<=(const RevCmp &rhs) const {\n        return\
    \ *this < rhs || *this == rhs;\n    };\n    bool operator>=(const RevCmp &rhs)\
    \ const {\n        return *this > rhs || *this == rhs;\n    };\n\n    RevCmp &operator=(const\
    \ RevCmp &rhs) {\n        val = rhs.val;\n        return *this;\n    };\n\n  \
    \  T value() const { return val; };\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: util/reverse_cmp.hpp
  requiredBy: []
  timestamp: '2021-11-23 20:15:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_9_C_leftist_heap.test.cpp
  - test/aoj/ALDS1_9_C_persistent_leftist_heap.test.cpp
documentation_of: util/reverse_cmp.hpp
layout: document
redirect_from:
- /library/util/reverse_cmp.hpp
- /library/util/reverse_cmp.hpp.html
title: util/reverse_cmp.hpp
---