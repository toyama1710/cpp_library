---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: cht/li_chao_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7d1cf34ccafd0e26b00bb21cd8cce647">cht</a>
* <a href="{{ site.github.repository_url }}/blob/master/cht/li_chao_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-23 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/line_add_get_min.test.cpp.html">test/yosupo/line_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/segment_add_get_min.test.cpp.html">test/yosupo/segment_add_get_min.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef LI_CHAO_TREE_HPP
#define LI_CHAO_TREE_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iterator>

template <class T = long long>
struct LiChaoTree {
    struct Line {
        T a, b;
        Line (T a, T b):
            a(a), b(b) {};
        T get(T x) {
            return a * x + b;
        };
        inline static Line identity() {
            return Line(0, std::numeric_limits<T>::max());
        };
    };

    std::vector<Line> seg;
    std::vector<T> pos;

    LiChaoTree() = default;
    explicit LiChaoTree(int n) {
        int n_ = 1;
        while (n_ < n) n_ *= 2;
        seg.resize(n_ * 2, Line::identity());
        pos.resize(n_);
        std::iota(pos.begin(), pos.end(), T(0)); 
    };
    template<class InputItr>
    LiChaoTree(InputItr first, InputItr last) {
        init(first, last);
    };
    LiChaoTree(std::vector<T> p) {
        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        init(p.begin(), p.end());
    }

    template<class InputItr>
    void init(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        int n_ = 1;

        while (n_ < n) n_ *= 2;

        seg.resize(n_ * 2, Line::identity());
        pos.reserve(n_);
        for (; first != last; first++) pos.push_back(*first);
        while (pos.size() < n_) pos.push_back(pos.back() + 1);
    }

    int size() {
        return  seg.size() >> 1;
    };

    void add_line(T a, T b) {
        update(Line(a, b), 1, 0, size() - 1);
    };

    // [s, t)
    void add_segment(T a, T b, T s, T t) {
        Line x(a, b);
        int sl, sr;
        int tl, tr;

        sl = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin();
        sr = sl;
        tl = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin();
        tr = tl;

        s = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin();
        t = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin();
        s += size();
        t += size();

        while (s < t) {
            int len = sr - sl + 1;
            if (s & 1) {
                update(x, s, sl, sr);
                sl += len;
                sr += len;
                s++;
            }
            if (t & 1) {
                t--;
                tl -= len;
                tr -= len;
                update(x, t, tl, tr);
            }
            s >>= 1;
            sr += len;
            t >>= 1;
            tr += len;
        }
    };

    // [l, r]
    void update(Line x, int k, int l, int r) {
        T pl = pos[l];
        T pr = pos[r];
        T pm = pos[(l + r) / 2];

        if (x.get(pl) >= seg[k].get(pl) && x.get(pr) >= seg[k].get(pr)) return;

        if (x.get(pl) <= seg[k].get(pl) && x.get(pr) <= seg[k].get(pr)) {
            seg[k] = x;
            return;
        }

        if (x.get(pm) < seg[k].get(pm)) std::swap(x, seg[k]);
        if (x.get(pl) <= seg[k].get(pl)) update(x, k << 1, l, (l + r) / 2);
        else update(x, (k << 1) | 1, (l + r) / 2 + 1, r);
    };

    T get(T x) {
        int k = std::lower_bound(pos.begin(), pos.end(), x) - pos.begin() + size();

        T ret = seg[k].get(x);
        while (k > 0) {
            k >>= 1;
            ret = std::min(ret, seg[k].get(x));
        }
        return ret;
    };
};

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "cht/li_chao_tree.hpp"



#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iterator>

template <class T = long long>
struct LiChaoTree {
    struct Line {
        T a, b;
        Line (T a, T b):
            a(a), b(b) {};
        T get(T x) {
            return a * x + b;
        };
        inline static Line identity() {
            return Line(0, std::numeric_limits<T>::max());
        };
    };

    std::vector<Line> seg;
    std::vector<T> pos;

    LiChaoTree() = default;
    explicit LiChaoTree(int n) {
        int n_ = 1;
        while (n_ < n) n_ *= 2;
        seg.resize(n_ * 2, Line::identity());
        pos.resize(n_);
        std::iota(pos.begin(), pos.end(), T(0)); 
    };
    template<class InputItr>
    LiChaoTree(InputItr first, InputItr last) {
        init(first, last);
    };
    LiChaoTree(std::vector<T> p) {
        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        init(p.begin(), p.end());
    }

    template<class InputItr>
    void init(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        int n_ = 1;

        while (n_ < n) n_ *= 2;

        seg.resize(n_ * 2, Line::identity());
        pos.reserve(n_);
        for (; first != last; first++) pos.push_back(*first);
        while (pos.size() < n_) pos.push_back(pos.back() + 1);
    }

    int size() {
        return  seg.size() >> 1;
    };

    void add_line(T a, T b) {
        update(Line(a, b), 1, 0, size() - 1);
    };

    // [s, t)
    void add_segment(T a, T b, T s, T t) {
        Line x(a, b);
        int sl, sr;
        int tl, tr;

        sl = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin();
        sr = sl;
        tl = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin();
        tr = tl;

        s = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin();
        t = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin();
        s += size();
        t += size();

        while (s < t) {
            int len = sr - sl + 1;
            if (s & 1) {
                update(x, s, sl, sr);
                sl += len;
                sr += len;
                s++;
            }
            if (t & 1) {
                t--;
                tl -= len;
                tr -= len;
                update(x, t, tl, tr);
            }
            s >>= 1;
            sr += len;
            t >>= 1;
            tr += len;
        }
    };

    // [l, r]
    void update(Line x, int k, int l, int r) {
        T pl = pos[l];
        T pr = pos[r];
        T pm = pos[(l + r) / 2];

        if (x.get(pl) >= seg[k].get(pl) && x.get(pr) >= seg[k].get(pr)) return;

        if (x.get(pl) <= seg[k].get(pl) && x.get(pr) <= seg[k].get(pr)) {
            seg[k] = x;
            return;
        }

        if (x.get(pm) < seg[k].get(pm)) std::swap(x, seg[k]);
        if (x.get(pl) <= seg[k].get(pl)) update(x, k << 1, l, (l + r) / 2);
        else update(x, (k << 1) | 1, (l + r) / 2 + 1, r);
    };

    T get(T x) {
        int k = std::lower_bound(pos.begin(), pos.end(), x) - pos.begin() + size();

        T ret = seg[k].get(x);
        while (k > 0) {
            k >>= 1;
            ret = std::min(ret, seg[k].get(x));
        }
        return ret;
    };
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

