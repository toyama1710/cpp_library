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


# :x: test/yosupo/line_add_get_min2.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/line_add_get_min2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-30 01:03:24+00:00


* see: <a href="https://judge.yosupo.jp/problem/line_add_get_min">https://judge.yosupo.jp/problem/line_add_get_min</a>


## Depends on

* :x: <a href="../../../library/cht/dynamic_li_chao_tree.hpp.html">cht/dynamic_li_chao_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "../../cht/dynamic_li_chao_tree.hpp"

using namespace std;
using llong = long long;

llong n, q;

const llong INF = 1ll << 60ll;
DynamicLiChaoTree<llong, -1 * INF, INF> cht;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        llong a, b;
        cin >> a >> b;
        cht.add_line(a, b);
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;

        cin >> com;
        if (com == 0) {
            cin >> x >> y;
            cht.add_line(x, y);
        }
        else {
            cin >> x;
            cout << cht.get(x) << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/line_add_get_min2.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#line 1 "cht/dynamic_li_chao_tree.hpp"



#line 5 "cht/dynamic_li_chao_tree.hpp"
#include <limits>

template <class T, T lower, T upper>
struct DynamicLiChaoTree {

    struct Line {
        T a, b;
        T get(T x) {
            return a * x + b;
        };
        Line (T a, T b) : a(a), b(b) {};
    };

    struct Node {
        Line x;
        Node *l, *r;
        Node (const Node &u) : x(u.x), l(u.l), r(u.r) {};
        Node (const Line &x) : x(x), l(nullptr), r(nullptr) {};
    };

    Node *root;

    DynamicLiChaoTree() : root(nullptr) {};

    void add_line(T a, T b) {
        auto x = Line(a, b);
        root = update(root, x, lower, upper);
    };

    Node *update(Node *u, Line &x, T lx, T rx) {
        if (u == nullptr) return new Node(x);
        if (x.get(lx) <= u->x.get(lx) && x.get(rx) <= u->x.get(rx)) {
            u->x = x;
            return u;
        }

        // T mx = std::midpoint(lx, rx);
        T mx = (lx + rx) / 2;
        if (x.get(mx) < u->x.get(mx)) std::swap(x, u->x);
        if (x.get(lx) < u->x.get(lx)) u->l = update(u->l, x, lx, mx);
        else u->r = update(u->r, x, mx, rx);

        return u;
    };

    T get(T x) {
        return get(x, root, lower, upper);
    };
    T get(T x, Node *u, T lx, T rx) {
        if (u == nullptr) return std::numeric_limits<T>::max();

        T mx = (lx + rx) / 2;
        if (x < mx) return std::min(u->x.get(x), get(x, u->l, lx, mx));
        else return std::min(u->x.get(x), get(x, u->r, mx, rx));
    };
};


#line 8 "test/yosupo/line_add_get_min2.test.cpp"

using namespace std;
using llong = long long;

llong n, q;

const llong INF = 1ll << 60ll;
DynamicLiChaoTree<llong, -1 * INF, INF> cht;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        llong a, b;
        cin >> a >> b;
        cht.add_line(a, b);
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;

        cin >> com;
        if (com == 0) {
            cin >> x >> y;
            cht.add_line(x, y);
        }
        else {
            cin >> x;
            cout << cht.get(x) << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

