---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_type/min_monoid.hpp
    title: data_type/min_monoid.hpp
  - icon: ':question:'
    path: segment_tree/segment_tree.hpp
    title: segment_tree/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL2A_1.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\n\n// header\
    \ file section\n#include <iostream>\n#include <vector>\n\n#line 1 \"data_type/min_monoid.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\n//===\n\
    template <class T>\nstruct MinMonoid {\n    using value_type = T;\n    inline\
    \ static T identity() {\n        return std::numeric_limits<T>::max();\n    };\n\
    \    inline static T operation(const T a, const T b) {\n        return std::min(a,\
    \ b);\n    };\n};\n//===\n\n\n#line 1 \"segment_tree/segment_tree.hpp\"\n\n\n\n\
    #include <functional>\n#include <iterator>\n#line 7 \"segment_tree/segment_tree.hpp\"\
    \n\n//===\ntemplate <class Monoid>\nstruct SegmentTree {\n    using T = typename\
    \ Monoid::value_type;\n\n    std::vector<T> tree;\n\n    SegmentTree() = default;\n\
    \    explicit SegmentTree(int n) : tree(n << 1, Monoid::identity()){};\n\n   \
    \ template <class InputIterator>\n    SegmentTree(InputIterator first, InputIterator\
    \ last) {\n        tree.assign(distance(first, last) << 1, Monoid::identity());\n\
    \n        int i;\n        i = size();\n        for (InputIterator itr = first;\
    \ itr != last; itr++) {\n            tree[i++] = *itr;\n        }\n        for\
    \ (i = size() - 1; i > 0; i--) {\n            tree[i] = Monoid::operation(tree[(i\
    \ << 1)], tree[(i << 1) | 1]);\n        }\n    };\n\n    inline int size() {\n\
    \        return tree.size() >> 1;\n    };\n\n    inline T operator[](int k) {\n\
    \        return tree[k + size()];\n    };\n\n    void update(int k, const T dat)\
    \ {\n        k += size();\n        tree[k] = dat;\n\n        while (k > 1) {\n\
    \            k >>= 1;\n            tree[k] = Monoid::operation(tree[(k << 1)],\
    \ tree[(k << 1) | 1]);\n        }\n    };\n\n    // [l, r)\n    T fold(int l,\
    \ int r) {\n        l += size();  // points leaf\n        r += size();\n\n   \
    \     T lv = Monoid::identity();\n        T rv = Monoid::identity();\n       \
    \ while (l < r) {\n            if (l & 1) lv = Monoid::operation(lv, tree[l++]);\n\
    \            if (r & 1) rv = Monoid::operation(tree[--r], rv);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n\n        return Monoid::operation(lv,\
    \ rv);\n    };\n\n    template <class F>\n    inline int sub_tree_search(int i,\
    \ T sum, F f) {\n        while (i < size()) {\n            T x = Monoid::operation(sum,\
    \ tree[i << 1]);\n            if (f(x)) {\n                i = i << 1;\n     \
    \       } else {\n                sum = x;\n                i = (i << 1) | 1;\n\
    \            }\n        }\n        return i - size() + 1;\n    }\n\n    template\
    \ <class F>\n    int find_first(int l, F f) {\n        l += size();\n        int\
    \ r = size() * 2;  // r = n;\n        int tmpr = r;\n        int shift = 0;\n\n\
    \        T sum = Monoid::identity();\n        while (l < r) {\n            if\
    \ (l & 1) {\n                if (f(Monoid::operation(sum, tree[l]))) {\n     \
    \               return sub_tree_search(l, sum, f);\n                }\n      \
    \          sum = Monoid::operation(sum, tree[l]);\n                l++;\n    \
    \        }\n            l >>= 1;\n            r >>= 1;\n            shift++;\n\
    \        }\n\n        while (shift > 0) {\n            shift--;\n            r\
    \ = tmpr >> shift;\n            if (r & 1) {\n                r--;\n         \
    \       if (f(Monoid::operation(sum, tree[r]))) {\n                    return\
    \ sub_tree_search(r, sum, f);\n                }\n                sum = Monoid::operation(sum,\
    \ tree[r]);\n            }\n        }\n\n        return -1;\n    };\n};\n//===\n\
    \n\n#line 10 \"test/aoj/DSL2A_1.test.cpp\"\n\nusing namespace std;\nusing llong\
    \ = long long;\n\nllong n, q;\nllong com, x, y;\n\nint main() {\n    cin >> n\
    \ >> q;\n\n    vector<llong> v(n, (1ll << 31) - 1);\n    SegmentTree<MinMonoid<llong>>\
    \ seg(v.begin(), v.end());\n\n    for (int i = 0; i < q; i++) {\n        cin >>\
    \ com >> x >> y;\n\n        if (com == 0) {\n            seg.update(x, y);\n \
    \       } else {\n            cout << seg.fold(x, y + 1) << '\\n';\n        }\n\
    \    }\n\n    return 0;\n};\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n// header file section\n#include <iostream>\n#include <vector>\n\n#include\
    \ \"../../data_type/min_monoid.hpp\"\n#include \"../../segment_tree/segment_tree.hpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nllong n, q;\nllong com,\
    \ x, y;\n\nint main() {\n    cin >> n >> q;\n\n    vector<llong> v(n, (1ll <<\
    \ 31) - 1);\n    SegmentTree<MinMonoid<llong>> seg(v.begin(), v.end());\n\n  \
    \  for (int i = 0; i < q; i++) {\n        cin >> com >> x >> y;\n\n        if\
    \ (com == 0) {\n            seg.update(x, y);\n        } else {\n            cout\
    \ << seg.fold(x, y + 1) << '\\n';\n        }\n    }\n\n    return 0;\n};\n"
  dependsOn:
  - data_type/min_monoid.hpp
  - segment_tree/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL2A_1.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL2A_1.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2A_1.test.cpp
- /verify/test/aoj/DSL2A_1.test.cpp.html
title: test/aoj/DSL2A_1.test.cpp
---
