---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_type/max_monoid.hpp
    title: data_type/max_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: segment_tree/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL2A_2.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#line 1 \"segment_tree/segment_tree.hpp\"\n\n\n\n#line 6 \"segment_tree/segment_tree.hpp\"\
    \n#include <iterator>\n\n//===\ntemplate<class Monoid>\nstruct SegmentTree {\n\
    \    using T = typename Monoid::value_type;\n\n    std::vector<T> tree;\n\n  \
    \  SegmentTree() = default;\n    explicit SegmentTree(int n)\n        :tree(n\
    \ << 1, Monoid::identity()) {};\n\n    template<class InputIterator>\n    SegmentTree(InputIterator\
    \ first, InputIterator last) {\n        tree.assign(distance(first, last) << 1,\
    \ Monoid::identity());\n\n        int i;\n        i = size();\n        for (InputIterator\
    \ itr = first; itr != last; itr++) {\n            tree[i++] = *itr;\n        }\n\
    \        for (i = size() - 1; i > 0; i--) {\n            tree[i] = Monoid::operation(tree[(i\
    \ << 1)], tree[(i << 1) | 1]);\n        }\n    };\n\n    inline int size() {\n\
    \        return tree.size() >> 1;\n    };\n\n    inline T operator[] (int k) {\n\
    \        return tree[k + size()];\n    };\n\n    void update(int k, const T dat)\
    \ {\n        k += size();\n        tree[k] = dat;\n        \n        while(k >\
    \ 1) {\n            k >>= 1;\n            tree[k] = Monoid::operation(tree[(k\
    \ << 1)], tree[(k << 1) | 1]);\n        }\n    };\n\n    // [l, r)\n    T fold(int\
    \ l, int r) {\n        l += size(); //points leaf\n        r += size();\n\n  \
    \      T lv = Monoid::identity();\n        T rv = Monoid::identity();\n      \
    \  while (l < r) {\n            if (l & 1) lv = Monoid::operation(lv, tree[l++]);\n\
    \            if (r & 1) rv = Monoid::operation(tree[--r], rv);\n            l\
    \ >>= 1;\n            r >>= 1;\n        }\n\n        return Monoid::operation(lv,\
    \ rv);\n    };\n\n    template<class F>\n    inline int sub_tree_search(int i,\
    \ T sum, F f) {\n        while (i < size()) {\n            T x = Monoid::operation(sum,\
    \ tree[i << 1]);\n            if (f(x)) {\n                i = i << 1;\n     \
    \       }\n            else {\n                sum = x;\n                i = (i\
    \ << 1) | 1;\n            }\n        }\n        return i - size();\n    }\n\n\
    \    template<class F>\n    int search(int l, F f) {\n        l += size();\n \
    \       int r = size() * 2; //r = n;\n        int tmpr = r;\n        int shift\
    \ = 0;\n\n        T sum = Monoid::identity();\n        while (l < r) {\n     \
    \       if (l & 1) {\n                if (f(Monoid::operation(sum, tree[l])))\
    \ {\n                    return sub_tree_search(l, sum, f);\n                }\n\
    \                sum = Monoid::operation(sum, tree[l]);\n                l++;\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n            shift++;\n\
    \        }\n\n        while (shift > 0) {\n            shift--;\n            r\
    \ = tmpr >> shift;\n            if (r & 1) {\n                r--;\n         \
    \       if (f(Monoid::operation(sum, tree[r]))) {\n                    return\
    \ sub_tree_search(r, sum, f);\n                }\n                sum = Monoid::operation(sum,\
    \ tree[r]);\n            }\n        }\n\n        return -1;\n    };\n};\n//===\n\
    \n\n#line 1 \"data_type/max_monoid.hpp\"\n\n\n\n#line 6 \"data_type/max_monoid.hpp\"\
    \n\n//===\ntemplate<class T>\nstruct MinMonoid {\n    using value_type = T;\n\
    \    inline static T identity() {\n        return std::numeric_limits<T>::min();\n\
    \    };\n    inline static T operation(const T a, const T b) {\n        return\
    \ std::max(a, b);\n    };\n};\n//===\n\n\n#line 18 \"test/aoj/DSL2A_2.test.cpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nllong n, q;\nllong com,\
    \ x, y;\n\nint main() {\n    cin >> n >> q;\n\n    vector<llong> v(n, -1 * ((1ll\
    \ << 31) - 1));\n    SegmentTree<MinMonoid<llong>> seg(v.begin(), v.end());\n\n\
    \    for (int i = 0; i < q; i++) {\n        cin >> com >> x >> y;\n\n        if\
    \ (com == 0) {\n            seg.update(x, -y);\n        }\n        else {\n  \
    \          cout << -seg.fold(x, y + 1) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n};\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#include \"../../segment_tree/segment_tree.hpp\"\n#include \"../../data_type/max_monoid.hpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nllong n, q;\nllong com,\
    \ x, y;\n\nint main() {\n    cin >> n >> q;\n\n    vector<llong> v(n, -1 * ((1ll\
    \ << 31) - 1));\n    SegmentTree<MinMonoid<llong>> seg(v.begin(), v.end());\n\n\
    \    for (int i = 0; i < q; i++) {\n        cin >> com >> x >> y;\n\n        if\
    \ (com == 0) {\n            seg.update(x, -y);\n        }\n        else {\n  \
    \          cout << -seg.fold(x, y + 1) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n};\n\n"
  dependsOn:
  - segment_tree/segment_tree.hpp
  - data_type/max_monoid.hpp
  isVerificationFile: true
  path: test/aoj/DSL2A_2.test.cpp
  requiredBy: []
  timestamp: '2020-06-10 22:44:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL2A_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL2A_2.test.cpp
- /verify/test/aoj/DSL2A_2.test.cpp.html
title: test/aoj/DSL2A_2.test.cpp
---
