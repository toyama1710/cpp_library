---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_aggregation.test.cpp
    title: test/yosupo/queue_aggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"queue/queue_aggregation.hpp\"\n#include <iostream>\n#include\
    \ <cstdio>\n#include <cassert>\n#include <functional>\n#include <stack>\n\n//===\n\
    // LIBRARY SECTION\n\n// #include <stack>\n// #include <cassert>\ntemplate<class\
    \ SemiGroup, class OP = std::function<SemiGroup(SemiGroup, SemiGroup)> >\nstruct\
    \ QueueAggregation {\n    using Stack = std::stack<std::pair<SemiGroup, SemiGroup>>;\n\
    \    const OP merge;\n    Stack front_st, back_st;\n\n    QueueAggregation(const\
    \ OP &f):merge(f) {};\n\n    SemiGroup fold() {\n        assert(!empty());\n \
    \       \n        if (front_st.empty()) return back_st.top().second;\n       \
    \ else if (back_st.empty()) return front_st.top().second;\n        else return\
    \ merge(front_st.top().second, back_st.top().second);\n    };\n\n    void push(SemiGroup\
    \ d) {\n        if (back_st.empty()) back_st.emplace(d, d);\n        else back_st.emplace(d,\
    \ merge(back_st.top().second, d));\n    };\n\n    void pop() {\n        assert(!empty());\n\
    \n        if (front_st.empty()) {\n            front_st.emplace(back_st.top().first,\
    \ back_st.top().first);\n            back_st.pop();\n            \n          \
    \  while (!back_st.empty()) {\n                front_st.emplace(back_st.top().first,\
    \ merge(back_st.top().first, front_st.top().second));\n                back_st.pop();\n\
    \            }\n        }\n        \n        front_st.pop();\n    };\n\n    bool\
    \ empty() {\n        return size() == 0;\n    };\n\n    size_t size() {\n    \
    \    return front_st.size() + back_st.size();\n    };\n};\n//===\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <cassert>\n#include <functional>\n\
    #include <stack>\n\n//===\n// LIBRARY SECTION\n\n// #include <stack>\n// #include\
    \ <cassert>\ntemplate<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup,\
    \ SemiGroup)> >\nstruct QueueAggregation {\n    using Stack = std::stack<std::pair<SemiGroup,\
    \ SemiGroup>>;\n    const OP merge;\n    Stack front_st, back_st;\n\n    QueueAggregation(const\
    \ OP &f):merge(f) {};\n\n    SemiGroup fold() {\n        assert(!empty());\n \
    \       \n        if (front_st.empty()) return back_st.top().second;\n       \
    \ else if (back_st.empty()) return front_st.top().second;\n        else return\
    \ merge(front_st.top().second, back_st.top().second);\n    };\n\n    void push(SemiGroup\
    \ d) {\n        if (back_st.empty()) back_st.emplace(d, d);\n        else back_st.emplace(d,\
    \ merge(back_st.top().second, d));\n    };\n\n    void pop() {\n        assert(!empty());\n\
    \n        if (front_st.empty()) {\n            front_st.emplace(back_st.top().first,\
    \ back_st.top().first);\n            back_st.pop();\n            \n          \
    \  while (!back_st.empty()) {\n                front_st.emplace(back_st.top().first,\
    \ merge(back_st.top().first, front_st.top().second));\n                back_st.pop();\n\
    \            }\n        }\n        \n        front_st.pop();\n    };\n\n    bool\
    \ empty() {\n        return size() == 0;\n    };\n\n    size_t size() {\n    \
    \    return front_st.size() + back_st.size();\n    };\n};\n//===\n"
  dependsOn: []
  isVerificationFile: false
  path: queue/queue_aggregation.hpp
  requiredBy: []
  timestamp: '2020-04-27 16:50:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_aggregation.test.cpp
documentation_of: queue/queue_aggregation.hpp
layout: document
redirect_from:
- /library/queue/queue_aggregation.hpp
- /library/queue/queue_aggregation.hpp.html
title: queue/queue_aggregation.hpp
---
