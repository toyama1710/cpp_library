---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_type/sum_monoid.hpp
    title: data_type/sum_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: segment_tree/segment_tree.hpp
    title: segment_tree/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_3
  bundledCode: "#line 1 \"test/atcoder/ARC033C.cpp\"\n#define IGNORE\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc033/tasks/arc033_3\"\n// header file section\n\
    #include <iostream>\n#include <cstdio>\n#include <cfloat>\n#include <vector>\n\
    #include <queue>\n#include <stack>\n#include <map>\n#include <set>\n#include <bitset>\n\
    #include <functional>\n#include <numeric>\n#include <algorithm>\n#line 1 \"segment_tree/segment_tree.hpp\"\
    \n\n\n\n#line 6 \"segment_tree/segment_tree.hpp\"\n#include <iterator>\n\n//===\n\
    template<class Monoid>\nstruct SegmentTree {\n    using T = typename Monoid::value_type;\n\
    \n    std::vector<T> tree;\n\n    SegmentTree() = default;\n    explicit SegmentTree(int\
    \ n)\n        :tree(n << 1, Monoid::identity()) {};\n\n    template<class InputIterator>\n\
    \    SegmentTree(InputIterator first, InputIterator last) {\n        tree.assign(distance(first,\
    \ last) << 1, Monoid::identity());\n\n        int i;\n        i = size();\n  \
    \      for (InputIterator itr = first; itr != last; itr++) {\n            tree[i++]\
    \ = *itr;\n        }\n        for (i = size() - 1; i > 0; i--) {\n           \
    \ tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);\n        }\n\
    \    };\n\n    inline int size() {\n        return tree.size() >> 1;\n    };\n\
    \n    inline T operator[] (int k) {\n        return tree[k + size()];\n    };\n\
    \n    void update(int k, const T dat) {\n        k += size();\n        tree[k]\
    \ = dat;\n        \n        while(k > 1) {\n            k >>= 1;\n           \
    \ tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);\n        }\n\
    \    };\n\n    // [l, r)\n    T fold(int l, int r) {\n        l += size(); //points\
    \ leaf\n        r += size();\n\n        T lv = Monoid::identity();\n        T\
    \ rv = Monoid::identity();\n        while (l < r) {\n            if (l & 1) lv\
    \ = Monoid::operation(lv, tree[l++]);\n            if (r & 1) rv = Monoid::operation(tree[--r],\
    \ rv);\n            l >>= 1;\n            r >>= 1;\n        }\n\n        return\
    \ Monoid::operation(lv, rv);\n    };\n\n    template<class F>\n    inline int\
    \ sub_tree_search(int i, T sum, F f) {\n        while (i < size()) {\n       \
    \     T x = Monoid::operation(sum, tree[i << 1]);\n            if (f(x)) {\n \
    \               i = i << 1;\n            }\n            else {\n             \
    \   sum = x;\n                i = (i << 1) | 1;\n            }\n        }\n  \
    \      return i - size();\n    }\n\n    template<class F>\n    int search(int\
    \ l, F f) {\n        l += size();\n        int r = size() * 2; //r = n;\n    \
    \    int tmpr = r;\n        int shift = 0;\n\n        T sum = Monoid::identity();\n\
    \        while (l < r) {\n            if (l & 1) {\n                if (f(Monoid::operation(sum,\
    \ tree[l]))) {\n                    return sub_tree_search(l, sum, f);\n     \
    \           }\n                sum = Monoid::operation(sum, tree[l]);\n      \
    \          l++;\n            }\n            l >>= 1;\n            r >>= 1;\n \
    \           shift++;\n        }\n\n        while (shift > 0) {\n            shift--;\n\
    \            r = tmpr >> shift;\n            if (r & 1) {\n                r--;\n\
    \                if (f(Monoid::operation(sum, tree[r]))) {\n                 \
    \   return sub_tree_search(r, sum, f);\n                }\n                sum\
    \ = Monoid::operation(sum, tree[r]);\n            }\n        }\n\n        return\
    \ -1;\n    };\n};\n//===\n\n\n#line 1 \"data_type/sum_monoid.hpp\"\n\n\n\ntemplate<class\
    \ T>\nstruct SumMonoid {\n    using value_type = T;\n    inline static T identity()\
    \ {\n        return (T)0;\n    };\n    inline static T operation(const T a, const\
    \ T b) {\n        return a + b;\n    };\n};\n\n\n#line 18 \"test/atcoder/ARC033C.cpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nint q;\nint t, x;\nconst\
    \ int n = 200001;\nSegmentTree<SumMonoid<llong>> st(n);\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    cin >> q;\n    while (q--) {\n      \
    \  cin >> t >> x;\n\n        if (t == 1) {\n            st.update(x, st[x] + 1);\n\
    \        }\n        else {\n            int idx = st.search(0,\n             \
    \       [&](llong sum){\n                        return sum >= x;\n          \
    \          });\n            st.update(idx, st[idx] - 1);\n            cout <<\
    \ idx << '\\n';\n        }\n    }\n\n    return 0;\n};\n\n"
  code: "#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/arc033/tasks/arc033_3\"\
    \n// header file section\n#include <iostream>\n#include <cstdio>\n#include <cfloat>\n\
    #include <vector>\n#include <queue>\n#include <stack>\n#include <map>\n#include\
    \ <set>\n#include <bitset>\n#include <functional>\n#include <numeric>\n#include\
    \ <algorithm>\n#include \"../../segment_tree/segment_tree.hpp\"\n#include \"../../data_type/sum_monoid.hpp\"\
    \n\nusing namespace std;\nusing llong = long long;\n\nint q;\nint t, x;\nconst\
    \ int n = 200001;\nSegmentTree<SumMonoid<llong>> st(n);\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    cin >> q;\n    while (q--) {\n      \
    \  cin >> t >> x;\n\n        if (t == 1) {\n            st.update(x, st[x] + 1);\n\
    \        }\n        else {\n            int idx = st.search(0,\n             \
    \       [&](llong sum){\n                        return sum >= x;\n          \
    \          });\n            st.update(idx, st[idx] - 1);\n            cout <<\
    \ idx << '\\n';\n        }\n    }\n\n    return 0;\n};\n\n"
  dependsOn:
  - segment_tree/segment_tree.hpp
  - data_type/sum_monoid.hpp
  isVerificationFile: false
  path: test/atcoder/ARC033C.cpp
  requiredBy: []
  timestamp: '2020-06-10 22:44:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ARC033C.cpp
layout: document
redirect_from:
- /library/test/atcoder/ARC033C.cpp
- /library/test/atcoder/ARC033C.cpp.html
title: test/atcoder/ARC033C.cpp
---
