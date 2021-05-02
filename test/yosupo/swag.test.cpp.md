---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: deque/sliding_window.hpp
    title: deque/sliding_window.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/swag.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#line 3 \"deque/sliding_window.hpp\"\n#include <cassert>\n#line\
    \ 6 \"deque/sliding_window.hpp\"\n\n//===\n// LIBRARY SECTION\n\n// #include <stack>\n\
    // #include <cassert>\ntemplate<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup,\
    \ SemiGroup)> >\nstruct SlidingWindow {\n    // first:original data, second:sum\n\
    \    using Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;\n    const OP\
    \ merge;\n\n    Stack front_st, back_st;\n\n    SlidingWindow(const OP &f):merge(f)\
    \ {};\n\n    inline SemiGroup fold() {\n        assert(!empty());\n        \n\
    \        if (front_st.empty()) return back_st.top().second;\n        else if (back_st.empty())\
    \ return front_st.top().second;\n        else return merge(front_st.top().second,\
    \ back_st.top().second);\n    };\n\n    inline void push_front(SemiGroup d) {\n\
    \        if (front_st.empty()) front_st.emplace(d, d);\n        else front_st.emplace(d,\
    \ merge(d, front_st.top().second));\n    };\n    inline void push_back(SemiGroup\
    \ d) {\n        if (back_st.empty()) back_st.emplace(d, d);\n        else back_st.emplace(d,\
    \ merge(back_st.top().second, d));\n    };\n\n    void pop_front() {\n       \
    \ assert(!empty());\n\n        if (front_st.empty()) {\n            Stack buff;\n\
    \            while (buff.size() + 1 < back_st.size()) {\n                buff.push(back_st.top());\n\
    \                back_st.pop();\n            }\n            while (!back_st.empty())\
    \ {\n                push_front(back_st.top().first);\n                back_st.pop();\n\
    \            }\n            while (!buff.empty()) {\n                push_back(buff.top().first);\n\
    \                buff.pop();\n            }\n        }\n        front_st.pop();\n\
    \    };\n    void pop_back() {\n        assert(!empty());\n\n        if (back_st.empty())\
    \ {\n            Stack buff;\n            while (buff.size() + 1 < front_st.size())\
    \ {\n                buff.push(front_st.top());\n                front_st.pop();\n\
    \            }\n            while (!front_st.empty()) {\n                push_back(front_st.top().first);\n\
    \                front_st.pop();\n            }\n            while (!buff.empty())\
    \ {\n                push_front(buff.top().first);\n                buff.pop();\n\
    \            }\n        }\n        back_st.pop();\n    };\n    \n    inline bool\
    \ empty() {\n        return size() == 0;\n    };\n\n    inline size_t size() {\n\
    \        return front_st.size() + back_st.size();\n    };\n};\n//===\n#line 16\
    \ \"test/yosupo/swag.test.cpp\"\n\nusing namespace std;\nusing llong = long long;\n\
    \n//const llong mod = 998244353;\n#define mod (998244353ll)\nSlidingWindow<pair<llong,\
    \ llong>> swag([](auto l, auto r) {\n            pair<llong, llong> ret;\n   \
    \         ret.first = l.first * r.first;\n            ret.second = l.first * r.second\
    \ + l.second;\n            ret.first %= mod;\n            ret.second %= mod;\n\
    \            return ret;\n        });\n\nint main() {\n    llong q;\n    llong\
    \ com;\n    llong a, b;\n    llong x;\n\n    cin >> q;\n\n    while (q--) {\n\
    \        cin >> com;\n\n        if (com == 0) {\n            cin >> a >> b;\n\
    \            swag.push_front({a, b});\n        }\n        else if (com == 1) {\n\
    \            swag.pop_back();\n        }\n        else if (com == 2) {\n     \
    \       cin >> x;\n\n            if (swag.empty()) {\n                cout <<\
    \ x << '\\n';\n            }\n            else {\n                auto f = swag.fold();\n\
    \                cout << (f.first * x + f.second) % mod << '\\n';\n          \
    \  }\n        }\n    }\n    return 0;\n};\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#include \"../../deque/sliding_window.hpp\"\n\nusing namespace\
    \ std;\nusing llong = long long;\n\n//const llong mod = 998244353;\n#define mod\
    \ (998244353ll)\nSlidingWindow<pair<llong, llong>> swag([](auto l, auto r) {\n\
    \            pair<llong, llong> ret;\n            ret.first = l.first * r.first;\n\
    \            ret.second = l.first * r.second + l.second;\n            ret.first\
    \ %= mod;\n            ret.second %= mod;\n            return ret;\n        });\n\
    \nint main() {\n    llong q;\n    llong com;\n    llong a, b;\n    llong x;\n\n\
    \    cin >> q;\n\n    while (q--) {\n        cin >> com;\n\n        if (com ==\
    \ 0) {\n            cin >> a >> b;\n            swag.push_front({a, b});\n   \
    \     }\n        else if (com == 1) {\n            swag.pop_back();\n        }\n\
    \        else if (com == 2) {\n            cin >> x;\n\n            if (swag.empty())\
    \ {\n                cout << x << '\\n';\n            }\n            else {\n\
    \                auto f = swag.fold();\n                cout << (f.first * x +\
    \ f.second) % mod << '\\n';\n            }\n        }\n    }\n    return 0;\n\
    };\n\n"
  dependsOn:
  - deque/sliding_window.hpp
  isVerificationFile: true
  path: test/yosupo/swag.test.cpp
  requiredBy: []
  timestamp: '2020-04-27 16:50:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/swag.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/swag.test.cpp
- /verify/test/yosupo/swag.test.cpp.html
title: test/yosupo/swag.test.cpp
---
