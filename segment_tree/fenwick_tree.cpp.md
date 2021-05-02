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
  bundledCode: "#line 1 \"segment_tree/fenwick_tree.cpp\"\n#include <iostream>\n#include\
    \ <cstdio>\n#include <cstdint>\n#include <functional>\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n\n//===\ninline size_t get_lsb(size_t\
    \ bits) {\n    return  bits & ((~bits) + 1);\n};\n\n// ATTENTION!! 1-indexed\n\
    template<class T>\nstruct FenwickTree {\n    vector<T> data;\n    const size_t\
    \ size;\n\n    FenwickTree(size_t nmemb): data(nmemb + 1, 0), size(nmemb) {};\n\
    \    \n    void add(size_t k, T d) {\n        while (k <= size) data[k] += d,\
    \ k += get_lsb(k);\n    };\n\n    // get sum for [1, i]\n    T prefix_sum(size_t\
    \ i) {\n        T ret = 0;\n        while (i > 0) ret += data[i], i -= get_lsb(i);\n\
    \        return ret;\n    };\n};\n//===\n\nint AOJ_DSL2B() {\n    int n, q;\n\
    \    int com, x, y;\n\n    cin >> n >> q;\n    FenwickTree<long long> sum(n);\n\
    \n    while (q--) {\n        cin >> com >> x >> y;\n\n        if (com == 0) {\n\
    \            sum.add(x, y);\n        }\n        else if (com == 1) {\n       \
    \     if (x == 1) cout << sum.prefix_sum(y) << endl;\n            else cout <<\
    \ sum.prefix_sum(y) - sum.prefix_sum(x - 1) << endl;\n        }\n    }\n\n   \
    \ return 0;\n}\n\nint main() {\n    AOJ_DSL2B();\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <cstdint>\n#include <functional>\n\
    #include <algorithm>\n#include <vector>\nusing namespace std;\n\n//===\ninline\
    \ size_t get_lsb(size_t bits) {\n    return  bits & ((~bits) + 1);\n};\n\n// ATTENTION!!\
    \ 1-indexed\ntemplate<class T>\nstruct FenwickTree {\n    vector<T> data;\n  \
    \  const size_t size;\n\n    FenwickTree(size_t nmemb): data(nmemb + 1, 0), size(nmemb)\
    \ {};\n    \n    void add(size_t k, T d) {\n        while (k <= size) data[k]\
    \ += d, k += get_lsb(k);\n    };\n\n    // get sum for [1, i]\n    T prefix_sum(size_t\
    \ i) {\n        T ret = 0;\n        while (i > 0) ret += data[i], i -= get_lsb(i);\n\
    \        return ret;\n    };\n};\n//===\n\nint AOJ_DSL2B() {\n    int n, q;\n\
    \    int com, x, y;\n\n    cin >> n >> q;\n    FenwickTree<long long> sum(n);\n\
    \n    while (q--) {\n        cin >> com >> x >> y;\n\n        if (com == 0) {\n\
    \            sum.add(x, y);\n        }\n        else if (com == 1) {\n       \
    \     if (x == 1) cout << sum.prefix_sum(y) << endl;\n            else cout <<\
    \ sum.prefix_sum(y) - sum.prefix_sum(x - 1) << endl;\n        }\n    }\n\n   \
    \ return 0;\n}\n\nint main() {\n    AOJ_DSL2B();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: segment_tree/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2019-11-15 21:13:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segment_tree/fenwick_tree.cpp
layout: document
redirect_from:
- /library/segment_tree/fenwick_tree.cpp
- /library/segment_tree/fenwick_tree.cpp.html
title: segment_tree/fenwick_tree.cpp
---
