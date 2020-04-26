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


# :warning: segment_tree/segment_tree2d.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/segment_tree2d.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-28 19:34:22+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//===
// memory: O(HW)
// time: O(logH * logW)
template<class T, class OP = function<T(T, T)> >
struct SegmentTree2D {
    const OP mergef;
    const size_t H, W;
    const T e;
    vector<vector<T> > tree;

    SegmentTree2D(size_t H, size_t W, const T &e, const OP &f):
        H(H), W(W), e(e), mergef(f)
    {
        tree.assign(H << 1, vector<T>(W << 1, e));
    };

    void update(int sy, int sx, T dat) {
        sy += H;
        sx += W;
        
        int ty, tx;
        tree[sy][sx] = dat;
        tx = sx;
        while (tx > 1) {
            tx >>= 1;
            tree[sy][tx] = mergef(tree[sy][(tx << 1)],
                                  tree[sy][(tx << 1) | 1]);
        }

        ty = sy;
        while (ty > 1) {
            ty >>= 1;
            tx = sx;
            tree[ty][tx] = mergef(tree[(ty << 1)][tx],
                                  tree[(ty << 1) | 1][tx]);
            while (tx > 1) {
                tx >>= 1;
                tree[ty][tx] = mergef(tree[(ty << 1)][tx],
                                      tree[(ty << 1) | 1][tx]);
            }
        }
    };

    T fold(int sy, int sx, int ty, int tx) {
        sy += H;
        ty += H;

        T ret = e;
        while (sy < ty) {
            if (sy & 1) ret = mergef(ret, fold_x(sy++, sx, tx));
            if (ty & 1) ret = mergef(fold_x(--ty, sx, tx), ret);

            sy >>= 1;
            ty >>= 1;
        }
        return ret;
    };
    T fold_x(int y, int l, int r) {
        l += W;
        r += W;

        T ret = e;
        while (l < r) {
            if (l & 1) ret = mergef(ret, tree[y][l++]);
            if (r & 1) ret = mergef(tree[y][--r], ret);

            l >>= 1;
            r >>= 1;
        }
        return ret;
    };

    T at(int sy, int sx) const {
        return tree[sy + H][sx + W];
    };
};
//===

using llong = long long;

int AOJ1068() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    llong r, c, q;
    llong gr;
    llong sy, sx, ty, tx;

    cin >> r >> c >> q;
    while (r != 0 && c != 0 && q != 0) {
        SegmentTree2D<llong> seg(r, c, 1ll << 60ll,
                                 [](auto l, auto r){return min(l, r);});
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> gr;
                seg.update(i, j, gr);
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> sy >> sx >> ty >> tx;

            cout << seg.fold(sy, sx, ty + 1,  tx + 1) << '\n';
        }

        /*
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << seg.at(i, j) << ' ';
            }
            cout << endl;
        }
        */
        
        cin >> r >> c >> q;
    }

    return 0;
}

int AOJ2842() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    llong H, W, T, Q;
    llong t, c, sy, sx, ty, tx;

    cin >> H >> W >> T >> Q;
    SegmentTree2D<llong> valid(H + 1, W + 1, 0,
                               [](auto l, auto r){return l + r;});
    SegmentTree2D<llong> invalid(H + 1, W + 1, 0,
                                 [](auto l, auto r){return l + r;});
    queue<tuple<llong, llong, llong> > que;

    for (int i = 0; i < Q; i++) {
        cin >> t >> c >> sy >> sx;

        while (!que.empty() && get<0>(que.front()) + T <= t) {
            auto a = que.front();
            valid.update(get<1>(a), get<2>(a), 1);
            invalid.update(get<1>(a), get<2>(a), 0);
            que.pop();
        }

        switch(c) {
        case 0:
            invalid.update(sy, sx, 1);
            que.push(make_tuple(t, sy, sx));
            break;
        case 1:
            if (valid.at(sy, sx) == 1) {
                valid.update(sy, sx, 0);
            }
            break;
        case 2:
            cin >> ty >> tx;
            ty++, tx++;

            cout << valid.fold(sy, sx, ty, tx) << ' ';
            cout << invalid.fold(sy, sx, ty, tx) << '\n';
            break;
        }
    }

    return 0;
}

int main() {
    return AOJ2842();
    //return AOJ1068();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/segment_tree2d.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//===
// memory: O(HW)
// time: O(logH * logW)
template<class T, class OP = function<T(T, T)> >
struct SegmentTree2D {
    const OP mergef;
    const size_t H, W;
    const T e;
    vector<vector<T> > tree;

    SegmentTree2D(size_t H, size_t W, const T &e, const OP &f):
        H(H), W(W), e(e), mergef(f)
    {
        tree.assign(H << 1, vector<T>(W << 1, e));
    };

    void update(int sy, int sx, T dat) {
        sy += H;
        sx += W;
        
        int ty, tx;
        tree[sy][sx] = dat;
        tx = sx;
        while (tx > 1) {
            tx >>= 1;
            tree[sy][tx] = mergef(tree[sy][(tx << 1)],
                                  tree[sy][(tx << 1) | 1]);
        }

        ty = sy;
        while (ty > 1) {
            ty >>= 1;
            tx = sx;
            tree[ty][tx] = mergef(tree[(ty << 1)][tx],
                                  tree[(ty << 1) | 1][tx]);
            while (tx > 1) {
                tx >>= 1;
                tree[ty][tx] = mergef(tree[(ty << 1)][tx],
                                      tree[(ty << 1) | 1][tx]);
            }
        }
    };

    T fold(int sy, int sx, int ty, int tx) {
        sy += H;
        ty += H;

        T ret = e;
        while (sy < ty) {
            if (sy & 1) ret = mergef(ret, fold_x(sy++, sx, tx));
            if (ty & 1) ret = mergef(fold_x(--ty, sx, tx), ret);

            sy >>= 1;
            ty >>= 1;
        }
        return ret;
    };
    T fold_x(int y, int l, int r) {
        l += W;
        r += W;

        T ret = e;
        while (l < r) {
            if (l & 1) ret = mergef(ret, tree[y][l++]);
            if (r & 1) ret = mergef(tree[y][--r], ret);

            l >>= 1;
            r >>= 1;
        }
        return ret;
    };

    T at(int sy, int sx) const {
        return tree[sy + H][sx + W];
    };
};
//===

using llong = long long;

int AOJ1068() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    llong r, c, q;
    llong gr;
    llong sy, sx, ty, tx;

    cin >> r >> c >> q;
    while (r != 0 && c != 0 && q != 0) {
        SegmentTree2D<llong> seg(r, c, 1ll << 60ll,
                                 [](auto l, auto r){return min(l, r);});
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> gr;
                seg.update(i, j, gr);
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> sy >> sx >> ty >> tx;

            cout << seg.fold(sy, sx, ty + 1,  tx + 1) << '\n';
        }

        /*
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << seg.at(i, j) << ' ';
            }
            cout << endl;
        }
        */
        
        cin >> r >> c >> q;
    }

    return 0;
}

int AOJ2842() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    llong H, W, T, Q;
    llong t, c, sy, sx, ty, tx;

    cin >> H >> W >> T >> Q;
    SegmentTree2D<llong> valid(H + 1, W + 1, 0,
                               [](auto l, auto r){return l + r;});
    SegmentTree2D<llong> invalid(H + 1, W + 1, 0,
                                 [](auto l, auto r){return l + r;});
    queue<tuple<llong, llong, llong> > que;

    for (int i = 0; i < Q; i++) {
        cin >> t >> c >> sy >> sx;

        while (!que.empty() && get<0>(que.front()) + T <= t) {
            auto a = que.front();
            valid.update(get<1>(a), get<2>(a), 1);
            invalid.update(get<1>(a), get<2>(a), 0);
            que.pop();
        }

        switch(c) {
        case 0:
            invalid.update(sy, sx, 1);
            que.push(make_tuple(t, sy, sx));
            break;
        case 1:
            if (valid.at(sy, sx) == 1) {
                valid.update(sy, sx, 0);
            }
            break;
        case 2:
            cin >> ty >> tx;
            ty++, tx++;

            cout << valid.fold(sy, sx, ty, tx) << ' ';
            cout << invalid.fold(sy, sx, ty, tx) << '\n';
            break;
        }
    }

    return 0;
}

int main() {
    return AOJ2842();
    //return AOJ1068();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

