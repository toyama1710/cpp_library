---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/queue_aggregation.test.cpp
    title: test/yosupo/queue_aggregation.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"queue/queue_aggregation.hpp\"\n#include <cassert>\n#include\
    \ <cstdio>\n#include <functional>\n#include <iostream>\n#include <stack>\n\n//===\n\
    // LIBRARY SECTION\n\n// #include <stack>\n// #include <cassert>\ntemplate <class\
    \ SemiGroup,\n          class OP = std::function<SemiGroup(SemiGroup, SemiGroup)>>\n\
    struct QueueAggregation {\n    using Stack = std::stack<std::pair<SemiGroup, SemiGroup>>;\n\
    \    const OP merge;\n    Stack front_st, back_st;\n\n    QueueAggregation(const\
    \ OP &f) : merge(f){};\n\n    SemiGroup fold() {\n        assert(!empty());\n\n\
    \        if (front_st.empty())\n            return back_st.top().second;\n   \
    \     else if (back_st.empty())\n            return front_st.top().second;\n \
    \       else\n            return merge(front_st.top().second, back_st.top().second);\n\
    \    };\n\n    void push(SemiGroup d) {\n        if (back_st.empty())\n      \
    \      back_st.emplace(d, d);\n        else\n            back_st.emplace(d, merge(back_st.top().second,\
    \ d));\n    };\n\n    void pop() {\n        assert(!empty());\n\n        if (front_st.empty())\
    \ {\n            front_st.emplace(back_st.top().first, back_st.top().first);\n\
    \            back_st.pop();\n\n            while (!back_st.empty()) {\n      \
    \          front_st.emplace(\n                    back_st.top().first,\n     \
    \               merge(back_st.top().first, front_st.top().second));\n        \
    \        back_st.pop();\n            }\n        }\n\n        front_st.pop();\n\
    \    };\n\n    bool empty() {\n        return size() == 0;\n    };\n\n    size_t\
    \ size() {\n        return front_st.size() + back_st.size();\n    };\n};\n//===\n"
  code: "#include <cassert>\n#include <cstdio>\n#include <functional>\n#include <iostream>\n\
    #include <stack>\n\n//===\n// LIBRARY SECTION\n\n// #include <stack>\n// #include\
    \ <cassert>\ntemplate <class SemiGroup,\n          class OP = std::function<SemiGroup(SemiGroup,\
    \ SemiGroup)>>\nstruct QueueAggregation {\n    using Stack = std::stack<std::pair<SemiGroup,\
    \ SemiGroup>>;\n    const OP merge;\n    Stack front_st, back_st;\n\n    QueueAggregation(const\
    \ OP &f) : merge(f){};\n\n    SemiGroup fold() {\n        assert(!empty());\n\n\
    \        if (front_st.empty())\n            return back_st.top().second;\n   \
    \     else if (back_st.empty())\n            return front_st.top().second;\n \
    \       else\n            return merge(front_st.top().second, back_st.top().second);\n\
    \    };\n\n    void push(SemiGroup d) {\n        if (back_st.empty())\n      \
    \      back_st.emplace(d, d);\n        else\n            back_st.emplace(d, merge(back_st.top().second,\
    \ d));\n    };\n\n    void pop() {\n        assert(!empty());\n\n        if (front_st.empty())\
    \ {\n            front_st.emplace(back_st.top().first, back_st.top().first);\n\
    \            back_st.pop();\n\n            while (!back_st.empty()) {\n      \
    \          front_st.emplace(\n                    back_st.top().first,\n     \
    \               merge(back_st.top().first, front_st.top().second));\n        \
    \        back_st.pop();\n            }\n        }\n\n        front_st.pop();\n\
    \    };\n\n    bool empty() {\n        return size() == 0;\n    };\n\n    size_t\
    \ size() {\n        return front_st.size() + back_st.size();\n    };\n};\n//===\n"
  dependsOn: []
  isVerificationFile: false
  path: queue/queue_aggregation.hpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/queue_aggregation.test.cpp
documentation_of: queue/queue_aggregation.hpp
layout: document
redirect_from:
- /library/queue/queue_aggregation.hpp
- /library/queue/queue_aggregation.hpp.html
title: queue/queue_aggregation.hpp
---
