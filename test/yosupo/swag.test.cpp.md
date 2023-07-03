---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: deque/sliding_window.hpp
    title: deque/sliding_window.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/swag.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n// header file section\n#include <algorithm>\n#include <bitset>\n#include <cfloat>\n\
    #include <cstdio>\n#include <functional>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <vector>\n\n#line 1 \"deque/sliding_window.hpp\"\n#include <cassert>\n#line\
    \ 6 \"deque/sliding_window.hpp\"\n\n//===\n// LIBRARY SECTION\n\n// #include <stack>\n\
    // #include <cassert>\ntemplate <class SemiGroup,\n          class OP = std::function<SemiGroup(SemiGroup,\
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
    \   return front_st.size() + back_st.size();\n    };\n};\n//===\n#line 17 \"test/yosupo/swag.test.cpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\n// const llong mod = 998244353;\n\
    #define mod (998244353ll)\nSlidingWindow<pair<llong, llong>> swag([](auto l, auto\
    \ r) {\n    pair<llong, llong> ret;\n    ret.first = l.first * r.first;\n    ret.second\
    \ = l.first * r.second + l.second;\n    ret.first %= mod;\n    ret.second %= mod;\n\
    \    return ret;\n});\n\nint main() {\n    llong q;\n    llong com;\n    llong\
    \ a, b;\n    llong x;\n\n    cin >> q;\n\n    while (q--) {\n        cin >> com;\n\
    \n        if (com == 0) {\n            cin >> a >> b;\n            swag.push_front({a,\
    \ b});\n        } else if (com == 1) {\n            swag.pop_back();\n       \
    \ } else if (com == 2) {\n            cin >> x;\n\n            if (swag.empty())\
    \ {\n                cout << x << '\\n';\n            } else {\n             \
    \   auto f = swag.fold();\n                cout << (f.first * x + f.second) %\
    \ mod << '\\n';\n            }\n        }\n    }\n    return 0;\n};\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n// header file section\n#include <algorithm>\n#include <bitset>\n#include <cfloat>\n\
    #include <cstdio>\n#include <functional>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include\
    \ <vector>\n\n#include \"../../deque/sliding_window.hpp\"\n\nusing namespace std;\n\
    using llong = long long;\n\n// const llong mod = 998244353;\n#define mod (998244353ll)\n\
    SlidingWindow<pair<llong, llong>> swag([](auto l, auto r) {\n    pair<llong, llong>\
    \ ret;\n    ret.first = l.first * r.first;\n    ret.second = l.first * r.second\
    \ + l.second;\n    ret.first %= mod;\n    ret.second %= mod;\n    return ret;\n\
    });\n\nint main() {\n    llong q;\n    llong com;\n    llong a, b;\n    llong\
    \ x;\n\n    cin >> q;\n\n    while (q--) {\n        cin >> com;\n\n        if\
    \ (com == 0) {\n            cin >> a >> b;\n            swag.push_front({a, b});\n\
    \        } else if (com == 1) {\n            swag.pop_back();\n        } else\
    \ if (com == 2) {\n            cin >> x;\n\n            if (swag.empty()) {\n\
    \                cout << x << '\\n';\n            } else {\n                auto\
    \ f = swag.fold();\n                cout << (f.first * x + f.second) % mod <<\
    \ '\\n';\n            }\n        }\n    }\n    return 0;\n};\n"
  dependsOn:
  - deque/sliding_window.hpp
  isVerificationFile: true
  path: test/yosupo/swag.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 22:03:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/swag.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/swag.test.cpp
- /verify/test/yosupo/swag.test.cpp.html
title: test/yosupo/swag.test.cpp
---
