---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: util/make_vector.hpp
    title: util/make_vector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_C
  bundledCode: "#line 1 \"test/aoj/IPT1_6_C.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_C\"\n\n#include\
    \ <iostream>\n\n#line 1 \"util/make_vector.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cstdint>\n#include <initializer_list>\n#include <vector>\n\ntemplate <class\
    \ T, uint64_t N>\nauto make_vector_(const uint64_t *dim, T e) {\n    if constexpr\
    \ (N == 1) {\n        return std::vector<T>(*dim, e);\n    } else {\n        auto\
    \ v = make_vector_<T, N - 1>(dim + 1, e);\n        return std::vector<decltype(v)>(*dim,\
    \ v);\n    }\n};\ntemplate <class T, uint64_t N>\nauto make_vector(const uint64_t\
    \ (&dim)[N], const T &e) {\n    assert(N > 0);\n    return make_vector_<T, N>(dim,\
    \ e);\n};\n\n\n#line 7 \"test/aoj/IPT1_6_C.test.cpp\"\n\n#define _overload(_1,\
    \ _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)\n#define\
    \ _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a, b, step) for (i64\
    \ Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__, _rep3,\
    \ _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n#define\
    \ ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\nusing\
    \ u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    auto room = make_vector({4, 3, 10}, 0);\n\n    i64 n;\n    cin >> n;\n  \
    \  rep(_, n) {\n        i64 b, f, r, v;\n        cin >> b >> f >> r >> v;\n  \
    \      --b, --f, --r;\n        room[b][f][r] += v;\n    }\n\n    rep(i, 4) {\n\
    \        rep(j, 3) {\n            rep(k, 10) cout << ' ' << room[i][j][k];\n \
    \           cout << endl;\n        }\n        if (i < 3) {\n            rep(i,\
    \ 20) cout << '#';\n            cout << endl;\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_C\"\
    \n\n#include <iostream>\n\n#include \"../../util/make_vector.hpp\"\n\n#define\
    \ _overload(_1, _2, _3, _4, name, ...) name\n#define _rep1(Itr, N) _rep3(Itr,\
    \ 0, N, 1)\n#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)\n#define _rep3(Itr, a,\
    \ b, step) for (i64 Itr = a; Itr < b; Itr += step)\n#define repeat(...) _overload(__VA_ARGS__,\
    \ _rep3, _rep2, _rep1)(__VA_ARGS__)\n#define rep(...) repeat(__VA_ARGS__)\n\n\
    #define ALL(X) begin(X), end(X)\n\nusing namespace std;\nusing i64 = long long;\n\
    using u64 = unsigned long long;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    auto room = make_vector({4, 3, 10}, 0);\n\n    i64 n;\n    cin >> n;\n  \
    \  rep(_, n) {\n        i64 b, f, r, v;\n        cin >> b >> f >> r >> v;\n  \
    \      --b, --f, --r;\n        room[b][f][r] += v;\n    }\n\n    rep(i, 4) {\n\
    \        rep(j, 3) {\n            rep(k, 10) cout << ' ' << room[i][j][k];\n \
    \           cout << endl;\n        }\n        if (i < 3) {\n            rep(i,\
    \ 20) cout << '#';\n            cout << endl;\n        }\n    }\n\n    return\
    \ 0;\n}"
  dependsOn:
  - util/make_vector.hpp
  isVerificationFile: true
  path: test/aoj/IPT1_6_C.test.cpp
  requiredBy: []
  timestamp: '2021-12-07 20:32:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/IPT1_6_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/IPT1_6_C.test.cpp
- /verify/test/aoj/IPT1_6_C.test.cpp.html
title: test/aoj/IPT1_6_C.test.cpp
---
