---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segment_tree/dual_segment_tree.hpp
    title: segment_tree/dual_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/aoj/DSL2E.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <iostream>\n#line 1 \"segment_tree/dual_segment_tree.hpp\"\n\n\n\n\
    #include <vector>\n#include <cstdint>\n\n//===\ntemplate<class Monoid>\nstruct\
    \ DualSegmentTree {\n    using T = typename Monoid::value_type;\n    std::vector<T>\
    \ lazy;\n\n    DualSegmentTree() = default;\n    explicit DualSegmentTree(uint32_t\
    \ n):\n        lazy(n << 1, Monoid::identity()) {};\n\n    inline int size() {\n\
    \        return (int)(lazy.size() >> 1);\n    };\n    \n    inline void propagate(uint32_t\
    \ k) {\n        if (k >= size()) return;\n        lazy[(k << 1) | 0] = Monoid::operation(lazy[(k\
    \ << 1) | 0], lazy[k]);\n        lazy[(k << 1) | 1] = Monoid::operation(lazy[(k\
    \ << 1) | 1], lazy[k]);\n        lazy[k] = Monoid::identity();\n    };\n    inline\
    \ void push_down(uint32_t k) {\n        for (uint32_t i = 31; i > 0; i--) propagate(k\
    \ >> i);\n    };\n \n    // [l, r)\n    void update(uint32_t l, uint32_t r, T\
    \ op) {\n        l += size();\n        r += size();\n        push_down(l);\n \
    \       push_down(r - 1);\n         \n        while (l < r) {\n            if\
    \ (l & 1) lazy[l] = Monoid::operation(lazy[l], op), l++;\n            if (r &\
    \ 1) --r, lazy[r] = Monoid::operation(lazy[r], op);\n \n            l >>= 1;\n\
    \            r >>= 1;\n        }\n    };\n\n    T get(uint32_t k) {\n        k\
    \ += size();\n        push_down(k);\n        return lazy[k];\n    };\n \n    T\
    \ operator [] (uint32_t k) {\n        return  get(k);\n    };\n};\n//===\n\n\n\
    #line 4 \"test/aoj/DSL2E.test.cpp\"\nusing namespace std;\nusing llong = long\
    \ long;\n\nstruct RAQ {\n    using value_type = long long;\n    using T = value_type;\n\
    \n    inline static T identity() {\n        return 0;\n    };\n    inline static\
    \ T operation(T a, T b) {\n        return a + b;\n    };\n};\n\nint main() {\n\
    \    llong n, q;\n    llong com;\n    llong s, t, x;\n    llong idx;\n\n    cin\
    \ >> n >> q;\n    DualSegmentTree<RAQ> seg(n);\n    for (int i = 0; i < q; i++)\
    \ {\n        cin >> com;\n\n        if (com == 0) {\n            cin >> s >> t\
    \ >> x;\n            s--;\n            seg.update(s, t, x);\n        }\n     \
    \   else if (com == 1) {\n            cin >> idx;\n            idx--;\n      \
    \      cout << seg[idx] << '\\n';\n        }\n    }\n};\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n#include <iostream>\n#include \"../../segment_tree/dual_segment_tree.hpp\"\n\
    using namespace std;\nusing llong = long long;\n\nstruct RAQ {\n    using value_type\
    \ = long long;\n    using T = value_type;\n\n    inline static T identity() {\n\
    \        return 0;\n    };\n    inline static T operation(T a, T b) {\n      \
    \  return a + b;\n    };\n};\n\nint main() {\n    llong n, q;\n    llong com;\n\
    \    llong s, t, x;\n    llong idx;\n\n    cin >> n >> q;\n    DualSegmentTree<RAQ>\
    \ seg(n);\n    for (int i = 0; i < q; i++) {\n        cin >> com;\n\n        if\
    \ (com == 0) {\n            cin >> s >> t >> x;\n            s--;\n          \
    \  seg.update(s, t, x);\n        }\n        else if (com == 1) {\n           \
    \ cin >> idx;\n            idx--;\n            cout << seg[idx] << '\\n';\n  \
    \      }\n    }\n};\n"
  dependsOn:
  - segment_tree/dual_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL2E.test.cpp
  requiredBy: []
  timestamp: '2020-07-02 04:49:03+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL2E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2E.test.cpp
- /verify/test/aoj/DSL2E.test.cpp.html
title: test/aoj/DSL2E.test.cpp
---
