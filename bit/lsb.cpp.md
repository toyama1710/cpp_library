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
  bundledCode: "#line 1 \"bit/lsb.cpp\"\n#include <iostream>\n#include <cstdio>\n\
    using namespace std;\nusing llong = long long;\n\n//===\ntemplate<class Integer>\n\
    inline Integer lsb(Integer bits) {\n    return bits & (~bits + 1);\n}\n//===\n\
    \nint main() {\n    int a;\n    llong b;\n    unsigned c;\n\n    cin >> a >> b\
    \ >> c;\n    cout << lsb(a) << ' ' << lsb(b) << ' ' << lsb(c) << endl;\n\n   \
    \ return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\nusing namespace std;\nusing llong\
    \ = long long;\n\n//===\ntemplate<class Integer>\ninline Integer lsb(Integer bits)\
    \ {\n    return bits & (~bits + 1);\n}\n//===\n\nint main() {\n    int a;\n  \
    \  llong b;\n    unsigned c;\n\n    cin >> a >> b >> c;\n    cout << lsb(a) <<\
    \ ' ' << lsb(b) << ' ' << lsb(c) << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: bit/lsb.cpp
  requiredBy: []
  timestamp: '2019-11-15 21:16:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/lsb.cpp
layout: document
redirect_from:
- /library/bit/lsb.cpp
- /library/bit/lsb.cpp.html
title: bit/lsb.cpp
---
