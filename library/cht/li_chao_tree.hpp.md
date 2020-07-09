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


# :warning: cht/li_chao_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7d1cf34ccafd0e26b00bb21cd8cce647">cht</a>
* <a href="{{ site.github.repository_url }}/blob/master/cht/li_chao_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-03 08:42:43+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef LI_CHAO_TREE_HPP
#define LI_CHAO_TREE_HPP

#include <vector>
#include <algorithm>
#include <limits>

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

    LiChaoTree() = default;
    explicit LiChaoTree(int n):seg(n << 1, Line::identity()) {};

    int size() {
        return  seg.size() >> 1;
    };

    void add_segment(T a, T b, int l, int r) {
        Line x(a, b);
        int ll = l, lr = l + 1;
        int rl = r - 1, rr = r;
        l += size();
        r += size();
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

    void update(Line &x, int k, int l, int r) {
        //replace
        if (x.get(l) <= seg[k].get(l) && x.get(r - 1) <= seg[k].get(r - 1)) seg[k] = x;
        //left
        else if (x.get(l) < seg[k].get(l)) update(x, k << 1, l, (l + r) >> 1);
        //right
        else if (x.get(r - 1) < seg[k].get(r - 1)) update(x, (k << 1) | 1, (l + r) >> 1, r);
        else return;
    };

    T get(int x) {
        int k = x + size();
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

    LiChaoTree() = default;
    explicit LiChaoTree(int n):seg(n << 1, Line::identity()) {};

    int size() {
        return  seg.size() >> 1;
    };

    void add_segment(T a, T b, int l, int r) {
        Line x(a, b);
        int ll = l, lr = l + 1;
        int rl = r - 1, rr = r;
        l += size();
        r += size();
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

    void update(Line &x, int k, int l, int r) {
        //replace
        if (x.get(l) <= seg[k].get(l) && x.get(r - 1) <= seg[k].get(r - 1)) seg[k] = x;
        //left
        else if (x.get(l) < seg[k].get(l)) update(x, k << 1, l, (l + r) >> 1);
        //right
        else if (x.get(r - 1) < seg[k].get(r - 1)) update(x, (k << 1) | 1, (l + r) >> 1, r);
        else return;
    };

    T get(int x) {
        int k = x + size();
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
