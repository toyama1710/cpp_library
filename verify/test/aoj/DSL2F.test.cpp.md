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


# :x: test/aoj/DSL2F.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL2F.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-08 11:56:19+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F</a>


## Depends on

* :x: <a href="../../../library/segment_tree/lazy_segment_tree.hpp.html">segment_tree/lazy_segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include <iostream>
#include <algorithm>
#include "../../segment_tree/lazy_segment_tree.hpp"
using namespace std;
using llong = long long;

struct M {
    struct Monoid {
        using T = llong;
        using value_type = T;

        inline static T identity() {
            return (1ll << 31) - 1;
        };
        inline static T operation(T a, T b) {
            return min(a, b);
        };
    };
    struct Operator {
        using E = llong;
        using value_type = E;

        inline static E identity() {
            return (1ll << 31) - 1;
        };
        inline static E operation(E a, E b) {
            if (a == identity()) return b;
            else if (b == identity()) return a;
            else return b;
        };
    };

    using value_structure = Monoid;
    using operator_structure = Operator;
    using T = typename Monoid::T;
    using E = typename Operator::E;

    inline static T operation(T dat, E op) {
        if (op == operator_structure::identity()) return dat;
        else return op;
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    llong n, q;
    llong com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<M> seg(n);

    for (int i = 0; i < q; i++) {

        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else if (com == 1) {
            cin >> s >> t;
            cout << seg.fold(s, t + 1) << endl;
        }

    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL2F.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include <iostream>
#include <algorithm>
#line 1 "segment_tree/lazy_segment_tree.hpp"



#include <vector>
#include <cstdint>

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
        for (int i = 31; i > 0; i--) propagation(k >> i);
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

        recalc(tmpl);
        recalc(tmpr - 1);
    };

    // foldl[l, r)
    T fold(uint32_t l, uint32_t r) {
        l += size();
        r += size();
        push_down(l);
        push_down(r - 1);
        recalc(l);
        recalc(r - 1);

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

    void dump() {
        int s = 1;
        for (int w = 1; w <= size() * 2; w *= 2) {
            for (int i = s; i < s + w; i++) {
                std::cout << i << ':';
                std::cout << tree[i].dat << " / " << tree[i].lazy << ' ';
            }
            std::cout << std::endl;
            s += w;
        }
    };
};
//===


#line 5 "test/aoj/DSL2F.test.cpp"
using namespace std;
using llong = long long;

struct M {
    struct Monoid {
        using T = llong;
        using value_type = T;

        inline static T identity() {
            return (1ll << 31) - 1;
        };
        inline static T operation(T a, T b) {
            return min(a, b);
        };
    };
    struct Operator {
        using E = llong;
        using value_type = E;

        inline static E identity() {
            return (1ll << 31) - 1;
        };
        inline static E operation(E a, E b) {
            if (a == identity()) return b;
            else if (b == identity()) return a;
            else return b;
        };
    };

    using value_structure = Monoid;
    using operator_structure = Operator;
    using T = typename Monoid::T;
    using E = typename Operator::E;

    inline static T operation(T dat, E op) {
        if (op == operator_structure::identity()) return dat;
        else return op;
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    llong n, q;
    llong com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<M> seg(n);

    for (int i = 0; i < q; i++) {

        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else if (com == 1) {
            cin >> s >> t;
            cout << seg.fold(s, t + 1) << endl;
        }

    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

