---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: queue/queue_aggregation.hpp
    title: queue/queue_aggregation.hpp
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
  bundledCode: "#line 1 \"test/yosupo/queue_aggregation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n// header file\
    \ section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n#include\
    \ <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include <set>\n\
    #include <bitset>\n#include <functional>\n#include <numeric>\n#include <algorithm>\n\
    #line 3 \"queue/queue_aggregation.hpp\"\n#include <cassert>\n#line 6 \"queue/queue_aggregation.hpp\"\
    \n\n//===\n// LIBRARY SECTION\n\n// #include <stack>\n// #include <cassert>\n\
    template<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup, SemiGroup)>\
    \ >\nstruct QueueAggregation {\n    using Stack = std::stack<std::pair<SemiGroup,\
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
    \    return front_st.size() + back_st.size();\n    };\n};\n//===\n#line 16 \"\
    test/yosupo/queue_aggregation.test.cpp\"\n\nusing namespace std;\nusing llong\
    \ = long long;\n\n//const llong mod = 998244353;\n#define mod (998244353ll)\n\
    QueueAggregation<pair<llong, llong>> swag([](auto l, auto r) {\n            pair<llong,\
    \ llong> ret;\n            ret.first = r.first * l.first;\n            ret.second\
    \ = r.first * l.second + r.second;\n            ret.first %= mod;\n          \
    \  ret.second %= mod;\n            return ret;\n        });\n\nint main() {\n\
    \    llong q;\n    llong com;\n    llong a, b;\n    llong x;\n\n    cin >> q;\n\
    \n    while (q--) {\n        cin >> com;\n\n        if (com == 0) {\n        \
    \    cin >> a >> b;\n            swag.push({a, b});\n        }\n        else if\
    \ (com == 1) {\n            swag.pop();\n        }\n        else if (com == 2)\
    \ {\n            cin >> x;\n\n            if (swag.empty()) {\n              \
    \  cout << x << '\\n';\n            }\n            else {\n                auto\
    \ f = swag.fold();\n                cout << (f.first * x + f.second) % mod <<\
    \ '\\n';\n            }\n        }\n    }\n    return 0;\n};\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#include \"../../queue/queue_aggregation.hpp\"\n\nusing namespace\
    \ std;\nusing llong = long long;\n\n//const llong mod = 998244353;\n#define mod\
    \ (998244353ll)\nQueueAggregation<pair<llong, llong>> swag([](auto l, auto r)\
    \ {\n            pair<llong, llong> ret;\n            ret.first = r.first * l.first;\n\
    \            ret.second = r.first * l.second + r.second;\n            ret.first\
    \ %= mod;\n            ret.second %= mod;\n            return ret;\n        });\n\
    \nint main() {\n    llong q;\n    llong com;\n    llong a, b;\n    llong x;\n\n\
    \    cin >> q;\n\n    while (q--) {\n        cin >> com;\n\n        if (com ==\
    \ 0) {\n            cin >> a >> b;\n            swag.push({a, b});\n        }\n\
    \        else if (com == 1) {\n            swag.pop();\n        }\n        else\
    \ if (com == 2) {\n            cin >> x;\n\n            if (swag.empty()) {\n\
    \                cout << x << '\\n';\n            }\n            else {\n    \
    \            auto f = swag.fold();\n                cout << (f.first * x + f.second)\
    \ % mod << '\\n';\n            }\n        }\n    }\n    return 0;\n};\n\n"
  dependsOn:
  - queue/queue_aggregation.hpp
  isVerificationFile: true
  path: test/yosupo/queue_aggregation.test.cpp
  requiredBy: []
  timestamp: '2020-04-27 16:50:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_aggregation.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_aggregation.test.cpp
- /verify/test/yosupo/queue_aggregation.test.cpp.html
title: test/yosupo/queue_aggregation.test.cpp
---
