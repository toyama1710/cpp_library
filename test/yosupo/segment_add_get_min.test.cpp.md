---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: cht/li_chao_tree.hpp
    title: cht/li_chao_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo/segment_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <tuple>\n#include <vector>\n\n#line 1 \"cht/li_chao_tree.hpp\"\
    \n\n\n\n#line 5 \"cht/li_chao_tree.hpp\"\n#include <iterator>\n#include <limits>\n\
    #include <numeric>\n#line 9 \"cht/li_chao_tree.hpp\"\n\ntemplate <class T = long\
    \ long>\nstruct LiChaoTree {\n    struct Line {\n        T a, b;\n        Line(T\
    \ a, T b) : a(a), b(b){};\n        T get(T x) {\n            return a * x + b;\n\
    \        };\n        inline static Line identity() {\n            return Line(0,\
    \ std::numeric_limits<T>::max());\n        };\n    };\n\n    std::vector<Line>\
    \ seg;\n    std::vector<T> pos;\n\n    LiChaoTree() = default;\n    explicit LiChaoTree(int\
    \ n) {\n        int n_ = 1;\n        while (n_ < n) n_ *= 2;\n        seg.resize(n_\
    \ * 2, Line::identity());\n        pos.resize(n_);\n        std::iota(pos.begin(),\
    \ pos.end(), T(0));\n    };\n    template <class InputItr>\n    LiChaoTree(InputItr\
    \ first, InputItr last) {\n        init(first, last);\n    };\n    LiChaoTree(std::vector<T>\
    \ p) {\n        std::sort(p.begin(), p.end());\n        p.erase(std::unique(p.begin(),\
    \ p.end()), p.end());\n        init(p.begin(), p.end());\n    }\n\n    template\
    \ <class InputItr>\n    void init(InputItr first, InputItr last) {\n        int\
    \ n = std::distance(first, last);\n        int n_ = 1;\n\n        while (n_ <\
    \ n) n_ *= 2;\n\n        seg.resize(n_ * 2, Line::identity());\n        pos.reserve(n_);\n\
    \        for (; first != last; first++) pos.push_back(*first);\n        while\
    \ (pos.size() < n_) pos.push_back(pos.back() + 1);\n    }\n\n    int size() {\n\
    \        return seg.size() >> 1;\n    };\n\n    void add_line(T a, T b) {\n  \
    \      update(Line(a, b), 1, 0, size() - 1);\n    };\n\n    // [s, t)\n    void\
    \ add_segment(T a, T b, T s, T t) {\n        Line x(a, b);\n        int sl, tl;\n\
    \        int len = 1;\n\n        sl = std::lower_bound(pos.begin(), pos.end(),\
    \ s) - pos.begin();\n        tl = std::lower_bound(pos.begin(), pos.end(), t)\
    \ - pos.begin();\n\n        s = std::lower_bound(pos.begin(), pos.end(), s) -\
    \ pos.begin() + size();\n        t = std::lower_bound(pos.begin(), pos.end(),\
    \ t) - pos.begin() + size();\n\n        while (s < t) {\n            if (s & 1)\
    \ {\n                update(x, s, sl, sl + len - 1);\n                sl += len;\n\
    \                s++;\n            }\n            if (t & 1) {\n             \
    \   t--;\n                tl -= len;\n                update(x, t, tl, tl + len\
    \ - 1);\n            }\n            s >>= 1;\n            t >>= 1;\n         \
    \   len <<= 1;\n        }\n    };\n\n    // [l, r]\n    void update(Line x, int\
    \ k, int l, int r) {\n        T pl = pos[l];\n        T pr = pos[r];\n       \
    \ T pm = pos[(l + r) / 2];\n\n        if (x.get(pl) >= seg[k].get(pl) && x.get(pr)\
    \ >= seg[k].get(pr)) return;\n\n        if (x.get(pl) <= seg[k].get(pl) && x.get(pr)\
    \ <= seg[k].get(pr)) {\n            seg[k] = x;\n            return;\n       \
    \ }\n\n        if (x.get(pm) < seg[k].get(pm)) std::swap(x, seg[k]);\n       \
    \ if (x.get(pl) <= seg[k].get(pl))\n            update(x, k << 1, l, (l + r) /\
    \ 2);\n        else\n            update(x, (k << 1) | 1, (l + r) / 2 + 1, r);\n\
    \    };\n\n    T get(T x) {\n        int k =\n            std::lower_bound(pos.begin(),\
    \ pos.end(), x) - pos.begin() + size();\n\n        T ret = seg[k].get(x);\n  \
    \      while (k > 0) {\n            k >>= 1;\n            ret = std::min(ret,\
    \ seg[k].get(x));\n        }\n        return ret;\n    };\n};\n\n\n#line 9 \"\
    test/yosupo/segment_add_get_min.test.cpp\"\n\nusing namespace std;\nusing llong\
    \ = long long;\n\nllong n, q;\nvector<tuple<llong, llong, llong, llong, llong>>\
    \ query;\nvector<llong> l, r;\nvector<llong> a, b;\nvector<llong> p;\n\nint main()\
    \ {\n    cin >> n >> q;\n    l.resize(n);\n    r.resize(n);\n    a.resize(n);\n\
    \    b.resize(n);\n    query.resize(q);\n    for (int i = 0; i < n; i++) {\n \
    \       cin >> l[i] >> r[i] >> a[i] >> b[i];\n        p.push_back(l[i]);\n   \
    \     p.push_back(r[i]);\n    }\n\n    for (int i = 0; i < q; i++) {\n       \
    \ llong com, l, r, a, b;\n\n        cin >> com;\n        if (com == 0) {\n   \
    \         cin >> l >> r >> a >> b;\n            p.push_back(l);\n            p.push_back(r);\n\
    \        } else {\n            cin >> l;\n            p.push_back(l);\n      \
    \  }\n        query[i] = tie(com, l, r, a, b);\n    }\n\n    LiChaoTree<llong>\
    \ cht(p);\n    for (int i = 0; i < n; i++) {\n        cht.add_segment(a[i], b[i],\
    \ l[i], r[i]);\n    }\n\n    for (int i = 0; i < q; i++) {\n        llong com,\
    \ l, r, a, b;\n        tie(com, l, r, a, b) = query[i];\n\n        if (com ==\
    \ 0) {\n            cht.add_segment(a, b, l, r);\n        } else {\n         \
    \   auto out = cht.get(l);\n\n            if (out >= llong(1e18) * 3) {\n    \
    \            cout << \"INFINITY\" << '\\n';\n            } else {\n          \
    \      cout << out << '\\n';\n            }\n        }\n    }\n\n    return 0;\n\
    };\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <algorithm>\n#include <iostream>\n#include <tuple>\n#include <vector>\n\
    \n#include \"../../cht/li_chao_tree.hpp\"\n\nusing namespace std;\nusing llong\
    \ = long long;\n\nllong n, q;\nvector<tuple<llong, llong, llong, llong, llong>>\
    \ query;\nvector<llong> l, r;\nvector<llong> a, b;\nvector<llong> p;\n\nint main()\
    \ {\n    cin >> n >> q;\n    l.resize(n);\n    r.resize(n);\n    a.resize(n);\n\
    \    b.resize(n);\n    query.resize(q);\n    for (int i = 0; i < n; i++) {\n \
    \       cin >> l[i] >> r[i] >> a[i] >> b[i];\n        p.push_back(l[i]);\n   \
    \     p.push_back(r[i]);\n    }\n\n    for (int i = 0; i < q; i++) {\n       \
    \ llong com, l, r, a, b;\n\n        cin >> com;\n        if (com == 0) {\n   \
    \         cin >> l >> r >> a >> b;\n            p.push_back(l);\n            p.push_back(r);\n\
    \        } else {\n            cin >> l;\n            p.push_back(l);\n      \
    \  }\n        query[i] = tie(com, l, r, a, b);\n    }\n\n    LiChaoTree<llong>\
    \ cht(p);\n    for (int i = 0; i < n; i++) {\n        cht.add_segment(a[i], b[i],\
    \ l[i], r[i]);\n    }\n\n    for (int i = 0; i < q; i++) {\n        llong com,\
    \ l, r, a, b;\n        tie(com, l, r, a, b) = query[i];\n\n        if (com ==\
    \ 0) {\n            cht.add_segment(a, b, l, r);\n        } else {\n         \
    \   auto out = cht.get(l);\n\n            if (out >= llong(1e18) * 3) {\n    \
    \            cout << \"INFINITY\" << '\\n';\n            } else {\n          \
    \      cout << out << '\\n';\n            }\n        }\n    }\n\n    return 0;\n\
    };\n"
  dependsOn:
  - cht/li_chao_tree.hpp
  isVerificationFile: true
  path: test/yosupo/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/segment_add_get_min.test.cpp
- /verify/test/yosupo/segment_add_get_min.test.cpp.html
title: test/yosupo/segment_add_get_min.test.cpp
---
