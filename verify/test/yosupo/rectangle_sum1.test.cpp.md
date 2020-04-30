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


# :x: test/yosupo/rectangle_sum1.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/rectangle_sum1.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 19:17:30+00:00


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Depends on

* :x: <a href="../../../library/segment_tree/persistent_segment_tree.hpp.html">segment_tree/persistent_segment_tree.hpp</a>
* :x: <a href="../../../library/util/coordinate_compression.hpp.html">util/coordinate_compression.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include <tuple>
#include "../../segment_tree/persistent_segment_tree.hpp"
#include "../../util/coordinate_compression.hpp"

using namespace std;
using llong = long long;

llong n, q;
vector<PersistentSegmentTree<llong>> v;
vector<tuple<llong, llong, llong>> p;
CoordinateCompression x_axis;
CoordinateCompression y_axis;

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        llong x, y, w;
        cin >> x >> y >> w;
        p.push_back(tie(y, x, w));
        x_axis.add(x);
        y_axis.add(y);
    }

    sort(p.begin(), p.end());
    x_axis.build();
    y_axis.build();

    v.push_back(PersistentSegmentTree<llong>(0,
                [](auto l, auto r) {return l + r;},
                x_axis.size()));

    for (int i = 0; i < p.size(); i++) {
        llong x, y, w;
        tie(y, x, w) = p[i];
        x = x_axis.zip(x);
        y = y_axis.zip(y);

        if (v.size() <= y) {
            v.push_back(v[y - 1]);
        }

        v[y] = v[y].update(x, v[y][x] + w);
    }

    for (int i = 0; i < q; i++) {
        llong l, d, r, u;
        cin >> l >> d >> r >> u;

        l = x_axis.zip(l);
        r = x_axis.zip(r);
        d = y_axis.zip(d) - 1;
        u = y_axis.zip(u) - 1;

        if (d >= 0) 
            cout << v[u].fold(l, r) - v[d].fold(l, r) << '\n';
        else if (u >= 0)
            cout << v[u].fold(l, r) << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/rectangle_sum1.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include <tuple>
#line 1 "segment_tree/persistent_segment_tree.hpp"



#include <iterator>
#line 7 "segment_tree/persistent_segment_tree.hpp"
#include <cstdint>
#include <cstddef>

//===
// LIBRARY SECTION
// #include <iterator>
// #include <functional>
// #include <vector>
// #include <cstdint>
// #include <cstddef>
template<class Monoid, class F = std::function<Monoid(Monoid, Monoid)>>
struct PersistentSegmentTree {
    using uint = size_t;
    
    struct Node {
        Monoid dat;
        Node *l = nullptr, *r = nullptr;

        Node (Monoid dat):dat(dat) {};
    };
    
    const Monoid e;
    const F f;
    const Node *root;
    const uint n;

    Node *merge_node(Node *lch, Node *rch) {
        Monoid l = (lch ? lch->dat : e);
        Monoid r = (rch ? rch->dat : e);
        Node *ret = new Node(f(l, r));
        ret->l = lch;
        ret->r = rch;

        return ret;
    };

    PersistentSegmentTree(Monoid e, F f, uint n, Node *r)
        :e(e), f(f), n(n), root(r) {};
    PersistentSegmentTree(Monoid e, F f, uint n)
        :e(e), f(f), n(n), root(alloc(0, n, std::vector<Monoid>(n, e))) {};
    template<class InputItr>
    PersistentSegmentTree(Monoid e, F f, InputItr first, InputItr last)
        :e(e), f(f), n(std::distance(first, last)), root(alloc(0, n, std::vector<Monoid>(first, last))) {};

    Node *alloc(uint nl, uint nr, const std::vector<Monoid> &v) {
        if (nr - nl <= 1) return new Node(v[nl]);
        else return merge_node(alloc(nl, (nl + nr) / 2, v),
                            alloc((nl + nr) / 2, nr, v));
    };

    const Monoid fold(uint l, uint r) const {
        return fold(l, r, 0, n, root);
    };
    const Monoid fold(uint ql, uint qr, uint nl, uint nr, Node *np) const {
        if (np == nullptr || qr <= nl || nr <= ql) return e;
        else if (ql <= nl && nr <= qr) return np->dat;
        else return f(fold(ql, qr, nl, (nl + nr) / 2, np->l), fold(ql, qr, (nl + nr) / 2, nr, np->r));
    };

    PersistentSegmentTree set(uint idx, Monoid d) {
        return PersistentSegmentTree(e, f, n, update(0, n, idx, d, root));
    };
    Node *update(uint nl, uint nr, uint idx, Monoid d, const Node *np) {
        if (idx < nl || nr <= idx) return np;
        else if (nr - nl == 1) return new Node(d);
        else return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l), update((nl + nr) / 2, nr, idx, d, np->r));
    };

    PersistentSegmentTree get_tree() {
        return *this;
    };

    const Monoid operator [] (uint idx) const {
        return fold(idx, idx + 1, 0, n, root);
    };
};
//===


#line 1 "util/coordinate_compression.hpp"
// header file section
#line 5 "util/coordinate_compression.hpp"
#include <cassert>

//===
// library section
// <iterator>
struct CoordinateCompression {
    using llong = long long;
    std::vector<llong> p;

#ifndef NODEBUG
    bool builded = false;
#endif

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(std::distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        std::sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
#ifndef NODEBUG
        builded = true;
#endif
    };

    void add(llong a) {
        p.push_back(a);
#ifndef NODEBUG
        builded = false;
#endif
    };
    void push(llong a) {
        add(a);
    }

    llong zip(llong x) {
#ifndef NODEBUG
        assert(builded);
#endif
        return std::lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
#ifndef NODEBUG
        assert(builded);
#endif
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===
#line 18 "test/yosupo/rectangle_sum1.test.cpp"

using namespace std;
using llong = long long;

llong n, q;
vector<PersistentSegmentTree<llong>> v;
vector<tuple<llong, llong, llong>> p;
CoordinateCompression x_axis;
CoordinateCompression y_axis;

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        llong x, y, w;
        cin >> x >> y >> w;
        p.push_back(tie(y, x, w));
        x_axis.add(x);
        y_axis.add(y);
    }

    sort(p.begin(), p.end());
    x_axis.build();
    y_axis.build();

    v.push_back(PersistentSegmentTree<llong>(0,
                [](auto l, auto r) {return l + r;},
                x_axis.size()));

    for (int i = 0; i < p.size(); i++) {
        llong x, y, w;
        tie(y, x, w) = p[i];
        x = x_axis.zip(x);
        y = y_axis.zip(y);

        if (v.size() <= y) {
            v.push_back(v[y - 1]);
        }

        v[y] = v[y].update(x, v[y][x] + w);
    }

    for (int i = 0; i < q; i++) {
        llong l, d, r, u;
        cin >> l >> d >> r >> u;

        l = x_axis.zip(l);
        r = x_axis.zip(r);
        d = y_axis.zip(d) - 1;
        u = y_axis.zip(u) - 1;

        if (d >= 0) 
            cout << v[u].fold(l, r) - v[d].fold(l, r) << '\n';
        else if (u >= 0)
            cout << v[u].fold(l, r) << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

