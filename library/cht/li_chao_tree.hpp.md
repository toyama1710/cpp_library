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


# :x: cht/li_chao_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7d1cf34ccafd0e26b00bb21cd8cce647">cht</a>
* <a href="{{ site.github.repository_url }}/blob/master/cht/li_chao_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-22 23:49:41+09:00




## Verified with

* :x: <a href="../../verify/test/yosupo/line_add_get_min.test.cpp.html">test/yosupo/line_add_get_min.test.cpp</a>


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
        std::iota(pos.begin(), pos.end(), 0); 
    };
    template<class InputItr>
    LiChaoTree(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        int n_ = 1;

        while (n_ < n) n_ *= 2;

        seg.resize(n_ * 2, Line::identity());
        pos.reserve(n_);
        for (; first != last; first++) pos.push_back(*first);
        while (pos.size() < n_) pos.push_back(pos.back() + 1);
    };

    int size() {
        return  seg.size() >> 1;
    };

    void add_line(T a, T b) {
        update(Line(a, b), 1, 0, size());
    };
    void add_segment(T a, T b, T s, T t) {
        Line x(a, b);
        int l = std::lower_bound(pos.begin(), pos.end(), l) - pos.begin() + size();
        int r = std::lower_bound(pos.begin(), pos.end(), r) - pos.begin() + size();
        int ll = l, lr = l + 1;
        int rl = r - 1, rr = r;
        while (l < r) {
            if (l & 1) {
                update(x, l, ll, lr);
                l++;
                int range = lr - ll;
                ll += range;
                lr += range;
            }
            if (r & 1) {
                r--;
                update(x, r, rl, rr);
                int range = rr - rl;
                rl -= range;
                rr -= range;
            }
            l >>= 1;
            lr += lr - ll;
            r >>= 1;
            rl -= rr - rl;
        }
    };

    // [l, r]
    void update(Line x, int k, int l, int r) {
        T pl = pos[l];
        T pr = pos[r];
        T pm = pos[(l + r) / 2];

        if (x.get(pl) <= seg[k].get(pl) && x.get(pr) <= seg[k].get(pr)) {
            seg[k] = x;
            return;
        }

        if (x.get(pm) <= seg[k].get(pm)) std::swap(x, seg[k]);
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
        std::iota(pos.begin(), pos.end(), 0); 
    };
    template<class InputItr>
    LiChaoTree(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        int n_ = 1;

        while (n_ < n) n_ *= 2;

        seg.resize(n_ * 2, Line::identity());
        pos.reserve(n_);
        for (; first != last; first++) pos.push_back(*first);
        while (pos.size() < n_) pos.push_back(pos.back() + 1);
    };

    int size() {
        return  seg.size() >> 1;
    };

    void add_line(T a, T b) {
        update(Line(a, b), 1, 0, size());
    };
    void add_segment(T a, T b, T s, T t) {
        Line x(a, b);
        int l = std::lower_bound(pos.begin(), pos.end(), l) - pos.begin() + size();
        int r = std::lower_bound(pos.begin(), pos.end(), r) - pos.begin() + size();
        int ll = l, lr = l + 1;
        int rl = r - 1, rr = r;
        while (l < r) {
            if (l & 1) {
                update(x, l, ll, lr);
                l++;
                int range = lr - ll;
                ll += range;
                lr += range;
            }
            if (r & 1) {
                r--;
                update(x, r, rl, rr);
                int range = rr - rl;
                rl -= range;
                rr -= range;
            }
            l >>= 1;
            lr += lr - ll;
            r >>= 1;
            rl -= rr - rl;
        }
    };

    // [l, r]
    void update(Line x, int k, int l, int r) {
        T pl = pos[l];
        T pr = pos[r];
        T pm = pos[(l + r) / 2];

        if (x.get(pl) <= seg[k].get(pl) && x.get(pr) <= seg[k].get(pr)) {
            seg[k] = x;
            return;
        }

        if (x.get(pm) <= seg[k].get(pm)) std::swap(x, seg[k]);
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

