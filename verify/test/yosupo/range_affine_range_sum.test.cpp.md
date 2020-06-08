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


# :heavy_check_mark: test/yosupo/range_affine_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-09 00:16:13+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/bit/msb.hpp.html">bit/msb.hpp</a>
* :heavy_check_mark: <a href="../../../library/segment_tree/lazy_segment_tree.hpp.html">segment_tree/lazy_segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <iostream>
#include <utility>
#include "../../segment_tree/lazy_segment_tree.hpp"
using llong = long long;
using namespace std;

struct A {
    struct M {
        using value_type = pair<llong, llong>;
        inline static value_type identity() {
            return {0, 0};
        };
        inline static value_type operation(value_type a, value_type b) {
            return {(a.first + b.first) % 998244353, a.second + b.second};
        };
    };
    struct O {
        using value_type = pair<llong, llong>;
        inline static value_type identity() {
            return {1ll, 0ll};
        };
        inline static value_type operation(value_type x, value_type y) {
            auto ret = identity();
            ret.first = (x.first * y.first) % 998244353;
            ret.second = (y.first * x.second + y.second) % 998244353;
            return ret;
        };
    };
    using value_structure = M;
    using operator_structure = O;
    inline static M::value_type operation(M::value_type a, O::value_type b) {
        return {(b.first * a.first + b.second * a.second) % 998244353, a.second};
    };
};

llong n, q;
llong a;
llong com, s, t, b, c;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    LazySegmentTree<A> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        seg.set(i, {a, 1});
    }

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> b >> c;
            seg.update(s, t, {b, c});
        }
        else {
            cin >> s >> t;
            cout << seg.fold(s, t).first << '\n';
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <iostream>
#include <utility>
#line 1 "segment_tree/lazy_segment_tree.hpp"



#include <vector>
#include <cstdint>
#line 1 "bit/msb.hpp"



#line 5 "bit/msb.hpp"

inline int msb32(uint32_t x) {
        if (x == 0) return -1;
#ifndef __has_builtin
        int r = 0;
        if (x >> 16) x >>= 16, r |= 16;
        if (x >> 8) x >>= 8, r |= 8;
        if (x >> 4) x >>= 4, r |= 4;
        if (x >> 2) x >>= 2, r |= 2;
        return r | (x >> 1);
#else
        return 31 - __builtin_clz(x);
#endif
};

inline int msb64(uint64_t x) {
    if (x == 0) return -1;

    #ifndef __has_builtin
        int r = 0;
        if (x >> 32) x >>= 32, r |= 32;
        if (x >> 16) x >>= 16, r |= 16;
        if (x >> 8) x >>= 8, r |= 8;
        if (x >> 4) x >>= 4, r |= 4;
        if (x >> 2) x >>= 2, r |= 2;
        return r | (x >> 1);
#else
    return 63 - __builtin_clzll(x);
#endif
};


#line 7 "segment_tree/lazy_segment_tree.hpp"

//===
template<class MonoidwithOperator>
struct LazySegmentTree {
    using M = MonoidwithOperator;
    using V = typename M::value_structure;
    using T = typename V::value_type;
    using O = typename M::operator_structure;
    using E = typename O::value_type;

    // mergeMonoid V::operation
    // applyOperator M::operation
    // mergeOperator O::operation

    struct Node {
        T dat;
        E lazy;
        Node (T dat, E lazy): dat(dat), lazy(lazy) {};
    };

    std::vector<Node> tree;

    LazySegmentTree() = default;
    explicit LazySegmentTree(uint32_t n):
        tree(n * 2 + 2, Node(V::identity(), O::identity())) {};

    int size() {
        return tree.size() >> 1;
    };
    
    void propagation(uint32_t k) {
        const uint32_t l = (k << 1) | 0;
        const uint32_t r = (k << 1) | 1;
        tree[l].lazy = O::operation(tree[l].lazy, tree[k].lazy);
        tree[r].lazy = O::operation(tree[r].lazy, tree[k].lazy);
        tree[l].dat = M::operation(tree[l].dat, tree[k].lazy);
        tree[r].dat = M::operation(tree[r].dat, tree[k].lazy);
        tree[k].lazy = O::identity();
    };
    void push_down(uint32_t k) {
        if (k == 0) return;
        uint32_t w = msb32(k);
        for (int i = w; i > 0; i--) propagation(k >> i);
    };
    void recalc(uint32_t k) {
        while (k > 1) {
            k >>= 1;
            tree[k].dat = V::operation(tree[(k << 1) | 0].dat,
                                       tree[(k << 1) | 1].dat);
        }
    };
    
    // [l, r) += op
    void update(uint32_t l, uint32_t r, E op) {
        l += size();
        r += size();
        uint32_t tmpl = l;
        uint32_t tmpr = r;
        push_down(l);
        push_down(r - 1);

        while (l < r) {
            if (l & 1) {
                tree[l].lazy = O::operation(tree[l].lazy, op);
                tree[l].dat = M::operation(tree[l].dat, op);
                l++;
            }
            if (r & 1) {
                --r;
                tree[r].lazy = O::operation(tree[r].lazy, op);
                tree[r].dat = M::operation(tree[r].dat, op);
            }
            l >>= 1;
            r >>= 1;
        }

        push_down(tmpl);
        push_down(tmpr - 1);
        recalc(tmpl);
        recalc(tmpr - 1);
    };
    void update(uint32_t idx, T x) {
        idx += size();
        push_down(idx);
        tree[idx].dat = x;
        recalc(idx);
    };
    void set(uint32_t idx, T x) {
        update(idx, x);
    };

    // foldl[l, r)
    T fold(uint32_t l, uint32_t r) {
        l += size();
        r += size();
        push_down(l);
        push_down(r - 1);

        T lv = V::identity();
        T rv = V::identity();

        while (l < r) {
            if (l & 1) lv = V::operation(lv, tree[l].dat), l++;
            if (r & 1) --r, rv = V::operation(tree[r].dat, rv);

            l >>= 1;
            r >>= 1;
        }

        return V::operation(lv, rv);
    };

    T operator [](const uint32_t &k) {
        push_down(k + size());
        return tree[k + size()].dat;
    };
};
//===


#line 5 "test/yosupo/range_affine_range_sum.test.cpp"
using llong = long long;
using namespace std;

struct A {
    struct M {
        using value_type = pair<llong, llong>;
        inline static value_type identity() {
            return {0, 0};
        };
        inline static value_type operation(value_type a, value_type b) {
            return {(a.first + b.first) % 998244353, a.second + b.second};
        };
    };
    struct O {
        using value_type = pair<llong, llong>;
        inline static value_type identity() {
            return {1ll, 0ll};
        };
        inline static value_type operation(value_type x, value_type y) {
            auto ret = identity();
            ret.first = (x.first * y.first) % 998244353;
            ret.second = (y.first * x.second + y.second) % 998244353;
            return ret;
        };
    };
    using value_structure = M;
    using operator_structure = O;
    inline static M::value_type operation(M::value_type a, O::value_type b) {
        return {(b.first * a.first + b.second * a.second) % 998244353, a.second};
    };
};

llong n, q;
llong a;
llong com, s, t, b, c;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    LazySegmentTree<A> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        seg.set(i, {a, 1});
    }

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> b >> c;
            seg.update(s, t, {b, c});
        }
        else {
            cin >> s >> t;
            cout << seg.fold(s, t).first << '\n';
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

