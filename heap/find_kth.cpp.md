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
  bundledCode: "#line 1 \"heap/find_kth.cpp\"\n#define NODEBUG\n#include <iostream>\n\
    #include <cstdio>\n#include <cstdlib>\n#include <cmath>\n#include <functional>\n\
    #include <algorithm>\n#include <string>\n#include <vector>\n#include <set>\n#include\
    \ <map>\n#include <queue>\n#include <stack>\n#include <cassert>\nusing namespace\
    \ std;\nusing llong = long long;\n\n//===\n//#include <cassert>\ntemplate<class\
    \ T, class Compare = function<bool(T, T)>,\n         class Heap = priority_queue<T,\
    \ vector<T>, Compare> >\nstruct FindKth {\n    const int K;\n    Heap maxh;\n\
    \    Heap minh;\n\n    FindKth (const int K, const Compare &cmp = less<T>()):\n\
    \        K(K),\n        maxh(cmp),\n        minh([cmp](auto l, auto r){ return\
    \ cmp(r, l); })\n    {};\n    \n    size_t size() {\n        return maxh.size()\
    \ + minh.size();\n    };\n    bool empty() {\n        return size() <= 0;\n  \
    \  };\n\n    void push(T d){\n        maxh.push(d);\n        if (maxh.size() >\
    \ K) {\n            minh.push(maxh.top());\n            maxh.pop();\n        }\n\
    \    };\n    \n    T find(){\n        assert(maxh.size() == K);\n        return\
    \ maxh.top();\n    };\n    T find_lower(){\n        assert(!empty());\n      \
    \  return maxh.top();\n    };\n    \n    void pop() {\n        assert(!empty());\n\
    \n        maxh.pop();\n        if (!minh.empty()) {\n            maxh.push(minh.top());\n\
    \            minh.pop();\n        }\n    };\n};\n//===\n\nint yc649() {\n    \n\
    \    llong q, k;\n    llong com, v;\n\n    cin >> q >> k;\n    FindKth<llong>\
    \ st(k);\n\n    while (q--) {\n        cin >> com;\n\n        if (com == 1) {\n\
    \            cin >> v;\n            st.push(v);\n        }\n        else {\n \
    \           if (st.size() < k) {\n                cout << -1 << endl;\n      \
    \      }\n            else {\n                cout << st.find() << endl;\n   \
    \             st.pop();\n            }\n        }\n    }\n    \n    return 0;\n\
    }\n\nint main() {\n    return yc649();\n}\n"
  code: "#define NODEBUG\n#include <iostream>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cmath>\n#include <functional>\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n#include <set>\n#include <map>\n#include <queue>\n#include\
    \ <stack>\n#include <cassert>\nusing namespace std;\nusing llong = long long;\n\
    \n//===\n//#include <cassert>\ntemplate<class T, class Compare = function<bool(T,\
    \ T)>,\n         class Heap = priority_queue<T, vector<T>, Compare> >\nstruct\
    \ FindKth {\n    const int K;\n    Heap maxh;\n    Heap minh;\n\n    FindKth (const\
    \ int K, const Compare &cmp = less<T>()):\n        K(K),\n        maxh(cmp),\n\
    \        minh([cmp](auto l, auto r){ return cmp(r, l); })\n    {};\n    \n   \
    \ size_t size() {\n        return maxh.size() + minh.size();\n    };\n    bool\
    \ empty() {\n        return size() <= 0;\n    };\n\n    void push(T d){\n    \
    \    maxh.push(d);\n        if (maxh.size() > K) {\n            minh.push(maxh.top());\n\
    \            maxh.pop();\n        }\n    };\n    \n    T find(){\n        assert(maxh.size()\
    \ == K);\n        return maxh.top();\n    };\n    T find_lower(){\n        assert(!empty());\n\
    \        return maxh.top();\n    };\n    \n    void pop() {\n        assert(!empty());\n\
    \n        maxh.pop();\n        if (!minh.empty()) {\n            maxh.push(minh.top());\n\
    \            minh.pop();\n        }\n    };\n};\n//===\n\nint yc649() {\n    \n\
    \    llong q, k;\n    llong com, v;\n\n    cin >> q >> k;\n    FindKth<llong>\
    \ st(k);\n\n    while (q--) {\n        cin >> com;\n\n        if (com == 1) {\n\
    \            cin >> v;\n            st.push(v);\n        }\n        else {\n \
    \           if (st.size() < k) {\n                cout << -1 << endl;\n      \
    \      }\n            else {\n                cout << st.find() << endl;\n   \
    \             st.pop();\n            }\n        }\n    }\n    \n    return 0;\n\
    }\n\nint main() {\n    return yc649();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: heap/find_kth.cpp
  requiredBy: []
  timestamp: '2020-03-31 22:26:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: heap/find_kth.cpp
layout: document
redirect_from:
- /library/heap/find_kth.cpp
- /library/heap/find_kth.cpp.html
title: heap/find_kth.cpp
---
