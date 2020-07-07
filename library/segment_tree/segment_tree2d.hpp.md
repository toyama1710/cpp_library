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


# :x: segment_tree/segment_tree2d.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/segment_tree2d.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-07 02:44:06+00:00




## Verified with

* :x: <a href="../../verify/test/aoj/2842.test.cpp.html">test/aoj/2842.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cassert>
#include <vector>

//===
// memory: O(HW)
// time: O(logH * logW)
template<class CommutativeMonoid>
struct SegmentTree2D {
    using M = CommutativeMonoid;
    using T = typename M::value_type;
    const std::size_t H, W;
    std::vector<std::vector<T>> tree;

    SegmentTree2D(size_t H, size_t W):H(H), W(W) {
        tree.assign(H << 1, std::vector<T>(W << 1, M::identity()));
    };

    void update(int sy, int sx, T dat) {
        sy += H;
        sx += W;
        int ty, tx;
        tree[sy][sx] = dat;
        tx = sx;
        while (tx > 1) {
            tx >>= 1;
            tree[sy][tx] = M::operation(tree[sy][(tx << 1)],
                    tree[sy][(tx << 1) | 1]);
        }

        ty = sy;
        while (ty > 1) {
            ty >>= 1;
            tx = sx;
            tree[ty][tx] = M::operation(tree[(ty << 1)][tx],
                    tree[(ty << 1) | 1][tx]);
            while (tx > 1) {
                tx >>= 1;
                tree[ty][tx] = M::operation(tree[(ty << 1)][tx],
                        tree[(ty << 1) | 1][tx]);
            }
        }
    };

    T fold(int sy, int sx, int ty, int tx) {
        sy += H;
        ty += H;

        T ret = M::identity();
        while (sy < ty) {
            if (sy & 1) ret = M::operation(ret, fold_x(sy++, sx, tx));
            if (ty & 1) ret = M::operation(fold_x(--ty, sx, tx), ret);
            sy >>= 1;
            ty >>= 1;
        }
        return ret;
    };
    T fold_x(int y, int l, int r) {
        l += W;
        r += W;
        T ret = M::identity();
        while (l < r) {
            if (l & 1) ret = M::operation(ret, tree[y][l++]);
            if (r & 1) ret = M::operation(tree[y][--r], ret);
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/segment_tree2d.hpp"
#include <cassert>
#include <vector>

//===
// memory: O(HW)
// time: O(logH * logW)
template<class CommutativeMonoid>
struct SegmentTree2D {
    using M = CommutativeMonoid;
    using T = typename M::value_type;
    const std::size_t H, W;
    std::vector<std::vector<T>> tree;

    SegmentTree2D(size_t H, size_t W):H(H), W(W) {
        tree.assign(H << 1, std::vector<T>(W << 1, M::identity()));
    };

    void update(int sy, int sx, T dat) {
        sy += H;
        sx += W;
        int ty, tx;
        tree[sy][sx] = dat;
        tx = sx;
        while (tx > 1) {
            tx >>= 1;
            tree[sy][tx] = M::operation(tree[sy][(tx << 1)],
                    tree[sy][(tx << 1) | 1]);
        }

        ty = sy;
        while (ty > 1) {
            ty >>= 1;
            tx = sx;
            tree[ty][tx] = M::operation(tree[(ty << 1)][tx],
                    tree[(ty << 1) | 1][tx]);
            while (tx > 1) {
                tx >>= 1;
                tree[ty][tx] = M::operation(tree[(ty << 1)][tx],
                        tree[(ty << 1) | 1][tx]);
            }
        }
    };

    T fold(int sy, int sx, int ty, int tx) {
        sy += H;
        ty += H;

        T ret = M::identity();
        while (sy < ty) {
            if (sy & 1) ret = M::operation(ret, fold_x(sy++, sx, tx));
            if (ty & 1) ret = M::operation(fold_x(--ty, sx, tx), ret);
            sy >>= 1;
            ty >>= 1;
        }
        return ret;
    };
    T fold_x(int y, int l, int r) {
        l += W;
        r += W;
        T ret = M::identity();
        while (l < r) {
            if (l & 1) ret = M::operation(ret, tree[y][l++]);
            if (r & 1) ret = M::operation(tree[y][--r], ret);
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

