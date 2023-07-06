---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/swag.test.cpp
    title: test/yosupo/swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"deque/sliding_window.hpp\"\n#include <cassert>\n#include\
    \ <cstdio>\n#include <functional>\n#include <iostream>\n#include <stack>\n\n//===\n\
    // LIBRARY SECTION\n\n// #include <stack>\n// #include <cassert>\ntemplate <class\
    \ SemiGroup,\n          class OP = std::function<SemiGroup(SemiGroup, SemiGroup)>\
    \ >\nstruct SlidingWindow {\n    // first:original data, second:sum\n    using\
    \ Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;\n    const OP merge;\n\
    \n    Stack front_st, back_st;\n\n    SlidingWindow(const OP &f) : merge(f){};\n\
    \n    inline SemiGroup fold() {\n        assert(!empty());\n\n        if (front_st.empty())\n\
    \            return back_st.top().second;\n        else if (back_st.empty())\n\
    \            return front_st.top().second;\n        else\n            return merge(front_st.top().second,\
    \ back_st.top().second);\n    };\n\n    inline void push_front(SemiGroup d) {\n\
    \        if (front_st.empty())\n            front_st.emplace(d, d);\n        else\n\
    \            front_st.emplace(d, merge(d, front_st.top().second));\n    };\n\n\
    \    inline void push_back(SemiGroup d) {\n        if (back_st.empty())\n    \
    \        back_st.emplace(d, d);\n        else\n            back_st.emplace(d,\
    \ merge(back_st.top().second, d));\n    };\n\n    void pop_front() {\n       \
    \ assert(!empty());\n\n        if (front_st.empty()) {\n            Stack buff;\n\
    \            while (buff.size() + 1 < back_st.size()) {\n                buff.push(back_st.top());\n\
    \                back_st.pop();\n            }\n\n            while (!back_st.empty())\
    \ {\n                push_front(back_st.top().first);\n                back_st.pop();\n\
    \            }\n\n            while (!buff.empty()) {\n                push_back(buff.top().first);\n\
    \                buff.pop();\n            }\n        }\n        front_st.pop();\n\
    \    };\n\n    void pop_back() {\n        assert(!empty());\n\n        if (back_st.empty())\
    \ {\n            Stack buff;\n            while (buff.size() + 1 < front_st.size())\
    \ {\n                buff.push(front_st.top());\n                front_st.pop();\n\
    \            }\n\n            while (!front_st.empty()) {\n                push_back(front_st.top().first);\n\
    \                front_st.pop();\n            }\n\n            while (!buff.empty())\
    \ {\n                push_front(buff.top().first);\n                buff.pop();\n\
    \            }\n        }\n        back_st.pop();\n    };\n\n    inline bool empty()\
    \ {\n        return size() == 0;\n    };\n\n    inline size_t size() {\n     \
    \   return front_st.size() + back_st.size();\n    };\n};\n//===\n"
  code: "#include <cassert>\n#include <cstdio>\n#include <functional>\n#include <iostream>\n\
    #include <stack>\n\n//===\n// LIBRARY SECTION\n\n// #include <stack>\n// #include\
    \ <cassert>\ntemplate <class SemiGroup,\n          class OP = std::function<SemiGroup(SemiGroup,\
    \ SemiGroup)> >\nstruct SlidingWindow {\n    // first:original data, second:sum\n\
    \    using Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;\n    const OP\
    \ merge;\n\n    Stack front_st, back_st;\n\n    SlidingWindow(const OP &f) : merge(f){};\n\
    \n    inline SemiGroup fold() {\n        assert(!empty());\n\n        if (front_st.empty())\n\
    \            return back_st.top().second;\n        else if (back_st.empty())\n\
    \            return front_st.top().second;\n        else\n            return merge(front_st.top().second,\
    \ back_st.top().second);\n    };\n\n    inline void push_front(SemiGroup d) {\n\
    \        if (front_st.empty())\n            front_st.emplace(d, d);\n        else\n\
    \            front_st.emplace(d, merge(d, front_st.top().second));\n    };\n\n\
    \    inline void push_back(SemiGroup d) {\n        if (back_st.empty())\n    \
    \        back_st.emplace(d, d);\n        else\n            back_st.emplace(d,\
    \ merge(back_st.top().second, d));\n    };\n\n    void pop_front() {\n       \
    \ assert(!empty());\n\n        if (front_st.empty()) {\n            Stack buff;\n\
    \            while (buff.size() + 1 < back_st.size()) {\n                buff.push(back_st.top());\n\
    \                back_st.pop();\n            }\n\n            while (!back_st.empty())\
    \ {\n                push_front(back_st.top().first);\n                back_st.pop();\n\
    \            }\n\n            while (!buff.empty()) {\n                push_back(buff.top().first);\n\
    \                buff.pop();\n            }\n        }\n        front_st.pop();\n\
    \    };\n\n    void pop_back() {\n        assert(!empty());\n\n        if (back_st.empty())\
    \ {\n            Stack buff;\n            while (buff.size() + 1 < front_st.size())\
    \ {\n                buff.push(front_st.top());\n                front_st.pop();\n\
    \            }\n\n            while (!front_st.empty()) {\n                push_back(front_st.top().first);\n\
    \                front_st.pop();\n            }\n\n            while (!buff.empty())\
    \ {\n                push_front(buff.top().first);\n                buff.pop();\n\
    \            }\n        }\n        back_st.pop();\n    };\n\n    inline bool empty()\
    \ {\n        return size() == 0;\n    };\n\n    inline size_t size() {\n     \
    \   return front_st.size() + back_st.size();\n    };\n};\n//===\n"
  dependsOn: []
  isVerificationFile: false
  path: deque/sliding_window.hpp
  requiredBy: []
  timestamp: '2023-07-03 22:03:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/swag.test.cpp
documentation_of: deque/sliding_window.hpp
layout: document
redirect_from:
- /library/deque/sliding_window.hpp
- /library/deque/sliding_window.hpp.html
title: deque/sliding_window.hpp
---
