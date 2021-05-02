---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"array/partially_persistent_array.cpp\"\n#include <iostream>\n\
    #include <cstdio>\n#include <vector>\n#include <iterator>\nusing namespace std;\n\
    using llong = long long;\n\n//===\ntemplate <class T>\nstruct PartiallyPersistentArray\
    \ {\n    int turn;\n    vector<vector<pair<int, T>>> arr;\n    const size_t sz;\n\
    \n    PartiallyPersistentArray(size_t nmemb, T v): sz(nmemb) {\n        turn =\
    \ 0;\n        arr.resize(sz, vector<pair<int, T> >(1, {0, v}));\n    };\n\n  \
    \  template<class InputIterator>\n    PartiallyPersistentArray(InputIterator first,\
    \ InputIterator last):\n        sz(distance(first, last))\n    {\n        turn\
    \ = 0;\n        arr.reserve(sz);\n        for (InputIterator i = first; i != last;\
    \ i++) {\n            arr.push_back(vector<pair<int, T>>(1, {0, *i}));\n     \
    \   }\n    };\n\n    void set(int k, T v) {\n        arr[k].push_back({++turn,\
    \ v});\n    };\n\n    T get(int t, int k) {\n        int valid = 0;\n        int\
    \ invalid = arr[k].size();\n        int mid;\n\n        while (invalid - valid\
    \ > 1) {\n            mid = (valid + invalid) / 2;\n\n            if (t <= arr[k][mid].first)\
    \ valid = mid;\n            else invalid = mid;\n        }\n\n        return arr[k][valid];\n\
    \    };\n};\n//===\n\n\nint main() {\n\n    return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <vector>\n#include <iterator>\n\
    using namespace std;\nusing llong = long long;\n\n//===\ntemplate <class T>\n\
    struct PartiallyPersistentArray {\n    int turn;\n    vector<vector<pair<int,\
    \ T>>> arr;\n    const size_t sz;\n\n    PartiallyPersistentArray(size_t nmemb,\
    \ T v): sz(nmemb) {\n        turn = 0;\n        arr.resize(sz, vector<pair<int,\
    \ T> >(1, {0, v}));\n    };\n\n    template<class InputIterator>\n    PartiallyPersistentArray(InputIterator\
    \ first, InputIterator last):\n        sz(distance(first, last))\n    {\n    \
    \    turn = 0;\n        arr.reserve(sz);\n        for (InputIterator i = first;\
    \ i != last; i++) {\n            arr.push_back(vector<pair<int, T>>(1, {0, *i}));\n\
    \        }\n    };\n\n    void set(int k, T v) {\n        arr[k].push_back({++turn,\
    \ v});\n    };\n\n    T get(int t, int k) {\n        int valid = 0;\n        int\
    \ invalid = arr[k].size();\n        int mid;\n\n        while (invalid - valid\
    \ > 1) {\n            mid = (valid + invalid) / 2;\n\n            if (t <= arr[k][mid].first)\
    \ valid = mid;\n            else invalid = mid;\n        }\n\n        return arr[k][valid];\n\
    \    };\n};\n//===\n\n\nint main() {\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: array/partially_persistent_array.cpp
  requiredBy: []
  timestamp: '2019-12-04 22:32:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: array/partially_persistent_array.cpp
layout: document
redirect_from:
- /library/array/partially_persistent_array.cpp
- /library/array/partially_persistent_array.cpp.html
title: array/partially_persistent_array.cpp
---
