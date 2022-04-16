---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cht/li_chao_tree.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <limits>\n#include <numeric>\n#include <iterator>\n\n\
    template <class T = long long>\nstruct LiChaoTree {\n    struct Line {\n     \
    \   T a, b;\n        Line (T a, T b):\n            a(a), b(b) {};\n        T get(T\
    \ x) {\n            return a * x + b;\n        };\n        inline static Line\
    \ identity() {\n            return Line(0, std::numeric_limits<T>::max());\n \
    \       };\n    };\n\n    std::vector<Line> seg;\n    std::vector<T> pos;\n\n\
    \    LiChaoTree() = default;\n    explicit LiChaoTree(int n) {\n        int n_\
    \ = 1;\n        while (n_ < n) n_ *= 2;\n        seg.resize(n_ * 2, Line::identity());\n\
    \        pos.resize(n_);\n        std::iota(pos.begin(), pos.end(), T(0)); \n\
    \    };\n    template<class InputItr>\n    LiChaoTree(InputItr first, InputItr\
    \ last) {\n        init(first, last);\n    };\n    LiChaoTree(std::vector<T> p)\
    \ {\n        std::sort(p.begin(), p.end());\n        p.erase(std::unique(p.begin(),\
    \ p.end()), p.end());\n        init(p.begin(), p.end());\n    }\n\n    template<class\
    \ InputItr>\n    void init(InputItr first, InputItr last) {\n        int n = std::distance(first,\
    \ last);\n        int n_ = 1;\n\n        while (n_ < n) n_ *= 2;\n\n        seg.resize(n_\
    \ * 2, Line::identity());\n        pos.reserve(n_);\n        for (; first != last;\
    \ first++) pos.push_back(*first);\n        while (pos.size() < n_) pos.push_back(pos.back()\
    \ + 1);\n    }\n\n    int size() {\n        return  seg.size() >> 1;\n    };\n\
    \n    void add_line(T a, T b) {\n        update(Line(a, b), 1, 0, size() - 1);\n\
    \    };\n\n    // [s, t)\n    void add_segment(T a, T b, T s, T t) {\n       \
    \ Line x(a, b);\n        int sl, tl;\n        int len = 1;\n\n        sl = std::lower_bound(pos.begin(),\
    \ pos.end(), s) - pos.begin();\n        tl = std::lower_bound(pos.begin(), pos.end(),\
    \ t) - pos.begin();\n\n        s = std::lower_bound(pos.begin(), pos.end(), s)\
    \ - pos.begin() + size();\n        t = std::lower_bound(pos.begin(), pos.end(),\
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
    \ if (x.get(pl) <= seg[k].get(pl)) update(x, k << 1, l, (l + r) / 2);\n      \
    \  else update(x, (k << 1) | 1, (l + r) / 2 + 1, r);\n    };\n\n    T get(T x)\
    \ {\n        int k = std::lower_bound(pos.begin(), pos.end(), x) - pos.begin()\
    \ + size();\n\n        T ret = seg[k].get(x);\n        while (k > 0) {\n     \
    \       k >>= 1;\n            ret = std::min(ret, seg[k].get(x));\n        }\n\
    \        return ret;\n    };\n};\n\n\n"
  code: "#ifndef LI_CHAO_TREE_HPP\n#define LI_CHAO_TREE_HPP\n\n#include <vector>\n\
    #include <algorithm>\n#include <limits>\n#include <numeric>\n#include <iterator>\n\
    \ntemplate <class T = long long>\nstruct LiChaoTree {\n    struct Line {\n   \
    \     T a, b;\n        Line (T a, T b):\n            a(a), b(b) {};\n        T\
    \ get(T x) {\n            return a * x + b;\n        };\n        inline static\
    \ Line identity() {\n            return Line(0, std::numeric_limits<T>::max());\n\
    \        };\n    };\n\n    std::vector<Line> seg;\n    std::vector<T> pos;\n\n\
    \    LiChaoTree() = default;\n    explicit LiChaoTree(int n) {\n        int n_\
    \ = 1;\n        while (n_ < n) n_ *= 2;\n        seg.resize(n_ * 2, Line::identity());\n\
    \        pos.resize(n_);\n        std::iota(pos.begin(), pos.end(), T(0)); \n\
    \    };\n    template<class InputItr>\n    LiChaoTree(InputItr first, InputItr\
    \ last) {\n        init(first, last);\n    };\n    LiChaoTree(std::vector<T> p)\
    \ {\n        std::sort(p.begin(), p.end());\n        p.erase(std::unique(p.begin(),\
    \ p.end()), p.end());\n        init(p.begin(), p.end());\n    }\n\n    template<class\
    \ InputItr>\n    void init(InputItr first, InputItr last) {\n        int n = std::distance(first,\
    \ last);\n        int n_ = 1;\n\n        while (n_ < n) n_ *= 2;\n\n        seg.resize(n_\
    \ * 2, Line::identity());\n        pos.reserve(n_);\n        for (; first != last;\
    \ first++) pos.push_back(*first);\n        while (pos.size() < n_) pos.push_back(pos.back()\
    \ + 1);\n    }\n\n    int size() {\n        return  seg.size() >> 1;\n    };\n\
    \n    void add_line(T a, T b) {\n        update(Line(a, b), 1, 0, size() - 1);\n\
    \    };\n\n    // [s, t)\n    void add_segment(T a, T b, T s, T t) {\n       \
    \ Line x(a, b);\n        int sl, tl;\n        int len = 1;\n\n        sl = std::lower_bound(pos.begin(),\
    \ pos.end(), s) - pos.begin();\n        tl = std::lower_bound(pos.begin(), pos.end(),\
    \ t) - pos.begin();\n\n        s = std::lower_bound(pos.begin(), pos.end(), s)\
    \ - pos.begin() + size();\n        t = std::lower_bound(pos.begin(), pos.end(),\
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
    \ if (x.get(pl) <= seg[k].get(pl)) update(x, k << 1, l, (l + r) / 2);\n      \
    \  else update(x, (k << 1) | 1, (l + r) / 2 + 1, r);\n    };\n\n    T get(T x)\
    \ {\n        int k = std::lower_bound(pos.begin(), pos.end(), x) - pos.begin()\
    \ + size();\n\n        T ret = seg[k].get(x);\n        while (k > 0) {\n     \
    \       k >>= 1;\n            ret = std::min(ret, seg[k].get(x));\n        }\n\
    \        return ret;\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: cht/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2020-07-23 03:00:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: cht/li_chao_tree.hpp
layout: document
redirect_from:
- /library/cht/li_chao_tree.hpp
- /library/cht/li_chao_tree.hpp.html
title: cht/li_chao_tree.hpp
---
