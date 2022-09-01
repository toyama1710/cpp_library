---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: segment_tree/dual_segment_tree.hpp
    title: segment_tree/dual_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL2D.test.cpp\"\n#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include <iostream>\n\n#line 1 \"segment_tree/dual_segment_tree.hpp\"\n\n\n\n\
    #include <cstdint>\n#include <vector>\n\n//===\ntemplate <class Monoid>\nstruct\
    \ DualSegmentTree {\n    using T = typename Monoid::value_type;\n    std::vector<T>\
    \ lazy;\n\n    DualSegmentTree() = default;\n    explicit DualSegmentTree(uint32_t\
    \ n) : lazy(n << 1, Monoid::identity()){};\n\n    inline int size() {\n      \
    \  return (int)(lazy.size() >> 1);\n    };\n\n    inline void propagate(uint32_t\
    \ k) {\n        if (k >= size()) return;\n        lazy[(k << 1) | 0] = Monoid::operation(lazy[(k\
    \ << 1) | 0], lazy[k]);\n        lazy[(k << 1) | 1] = Monoid::operation(lazy[(k\
    \ << 1) | 1], lazy[k]);\n        lazy[k] = Monoid::identity();\n    };\n    inline\
    \ void push_down(uint32_t k) {\n        for (uint32_t i = 31; i > 0; i--) propagate(k\
    \ >> i);\n    };\n\n    // [l, r)\n    void update(uint32_t l, uint32_t r, T op)\
    \ {\n        l += size();\n        r += size();\n        push_down(l);\n     \
    \   push_down(r - 1);\n\n        while (l < r) {\n            if (l & 1) lazy[l]\
    \ = Monoid::operation(lazy[l], op), l++;\n            if (r & 1) --r, lazy[r]\
    \ = Monoid::operation(lazy[r], op);\n\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n    };\n\n    T get(uint32_t k) {\n        k += size();\n   \
    \     push_down(k);\n        return lazy[k];\n    };\n\n    T operator[](uint32_t\
    \ k) {\n        return get(k);\n    };\n};\n//===\n\n\n#line 6 \"test/aoj/DSL2D.test.cpp\"\
    \nusing namespace std;\nusing llong = long long;\n\nstruct RUQ {\n    using value_type\
    \ = long long;\n    using T = value_type;\n\n    inline static T identity() {\n\
    \        return (1ll << 31) - 1;\n    };\n    inline static T operation(T a, T\
    \ b) {\n        if (a == identity())\n            return b;\n        else if (b\
    \ == identity())\n            return a;\n        else\n            return b;\n\
    \    };\n};\n\nint main() {\n    llong n, q;\n    llong com;\n    llong s, t,\
    \ x;\n    llong idx;\n\n    cin >> n >> q;\n    DualSegmentTree<RUQ> seg(n);\n\
    \    for (int i = 0; i < q; i++) {\n        cin >> com;\n\n        if (com ==\
    \ 0) {\n            cin >> s >> t >> x;\n            seg.update(s, t + 1, x);\n\
    \        } else if (com == 1) {\n            cin >> idx;\n            cout <<\
    \ seg[idx] << '\\n';\n        }\n    }\n};\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n#include <iostream>\n\n#include \"../../segment_tree/dual_segment_tree.hpp\"\
    \nusing namespace std;\nusing llong = long long;\n\nstruct RUQ {\n    using value_type\
    \ = long long;\n    using T = value_type;\n\n    inline static T identity() {\n\
    \        return (1ll << 31) - 1;\n    };\n    inline static T operation(T a, T\
    \ b) {\n        if (a == identity())\n            return b;\n        else if (b\
    \ == identity())\n            return a;\n        else\n            return b;\n\
    \    };\n};\n\nint main() {\n    llong n, q;\n    llong com;\n    llong s, t,\
    \ x;\n    llong idx;\n\n    cin >> n >> q;\n    DualSegmentTree<RUQ> seg(n);\n\
    \    for (int i = 0; i < q; i++) {\n        cin >> com;\n\n        if (com ==\
    \ 0) {\n            cin >> s >> t >> x;\n            seg.update(s, t + 1, x);\n\
    \        } else if (com == 1) {\n            cin >> idx;\n            cout <<\
    \ seg[idx] << '\\n';\n        }\n    }\n};\n"
  dependsOn:
  - segment_tree/dual_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL2D.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL2D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2D.test.cpp
- /verify/test/aoj/DSL2D.test.cpp.html
title: test/aoj/DSL2D.test.cpp
---
