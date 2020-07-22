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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/line_add_get_min.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/line_add_get_min.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-23 03:00:37+09:00


* see: <a href="https://judge.yosupo.jp/problem/line_add_get_min">https://judge.yosupo.jp/problem/line_add_get_min</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/cht/li_chao_tree.hpp.html">cht/li_chao_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "../../cht/li_chao_tree.hpp"

using namespace std;
using llong = long long;

llong n, q;
vector<tuple<llong, llong, llong>> query;
vector<llong> a, b;
vector<llong> p;

int main() {
    cin >> n >> q;
    a.resize(n);
    b.resize(n);
    query.resize(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;

        cin >> com;
        if (com == 0) {
            cin >> x >> y;
        }
        else {
            cin >> x;
            p.push_back(x);
        }
        query[i] = tie(com, x, y);
    }

    LiChaoTree<llong> cht(p);
    for (int i = 0; i < n; i++) {
        cht.add_line(a[i], b[i]);
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;
        tie(com, x, y) = query[i];

        if (com == 0) {
            cht.add_line(x, y);
        }
        else {
            cout << cht.get(x) << endl;
        }
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/line_add_get_min.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#line 1 "cht/li_chao_tree.hpp"



#line 6 "cht/li_chao_tree.hpp"
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
        int sl, tl;
        int len = 1;

        sl = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin();
        tl = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin();

        s = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin() + size();
        t = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin() + size();

        while (s < t) {
            if (s & 1) {
                update(x, s, sl, sl + len - 1);
                sl += len;
                s++;
            }
            if (t & 1) {
                t--;
                tl -= len;
                update(x, t, tl, tl + len - 1);
            }
            s >>= 1;
            t >>= 1;
            len <<= 1;
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


#line 8 "test/yosupo/line_add_get_min.test.cpp"

using namespace std;
using llong = long long;

llong n, q;
vector<tuple<llong, llong, llong>> query;
vector<llong> a, b;
vector<llong> p;

int main() {
    cin >> n >> q;
    a.resize(n);
    b.resize(n);
    query.resize(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;

        cin >> com;
        if (com == 0) {
            cin >> x >> y;
        }
        else {
            cin >> x;
            p.push_back(x);
        }
        query[i] = tie(com, x, y);
    }

    LiChaoTree<llong> cht(p);
    for (int i = 0; i < n; i++) {
        cht.add_line(a[i], b[i]);
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;
        tie(com, x, y) = query[i];

        if (com == 0) {
            cht.add_line(x, y);
        }
        else {
            cout << cht.get(x) << endl;
        }
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

