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


# :x: test/aoj/DSL2A_3.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL2A_3.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-06 02:42:07+00:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A</a>


## Depends on

* :question: <a href="../../../library/data_type/max_monoid.hpp.html">data_type/max_monoid.hpp</a>
* :x: <a href="../../../library/segment_tree/dynamic_segment_tree.hpp.html">segment_tree/dynamic_segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

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
#include "../../segment_tree/dynamic_segment_tree.hpp"
#include "../../data_type/max_monoid.hpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, x, y;

int main() {
    cin >> n >> q;

    vector<llong> v(n, -1 * ((1ll << 31) - 1));
    DynamicSegmentTree<MinMonoid<llong>> seg();
    for (int i = 0; i < n; i++) {
        seg.update(i, v[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            seg.update(x, -y);
        }
        else {
            cout << -seg.fold(x, y + 1) << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL2A_3.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

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
#line 1 "segment_tree/dynamic_segment_tree.hpp"
//===
template<class Monoid>
struct DynamicSegmentTree {
    using T = typename Monoid::value_type;
    using llong = long long;

    struct Node {
        Node *left, *right;
        T v;
        Node(T v):v(v), left(nullptr), right(nullptr) {};
    };

    Node *root = nullptr;
    llong L = 0, R = 0;

    DynamicSegmentTree() = default;

    inline void eval(Node &u) {
        T lv = Monoid::identity(), rv = Monoid::identity();
        if (u.left) lv = u.left->v;
        if (u.right) rv = u.right->v;
        u.v = Monoid::operation(lv, rv);
    };

    inline void expand(llong i) {
        if (L == R) {
            R++;
            while (i >= R) R += R - L;
            while (i < L) L -= R - L;
            root = new Node(Monoid::identity());
        }
        else {
            Node *tmp;
            while (i >= R) {
                R += R - L;
                tmp = new Node(root->v);
                tmp->left = root;
                root = tmp;
            }
            while (i < L) {
                L -= R - L;
                tmp = new Node(root->v);
                tmp->right = root;
                root = tmp;
            }
        }
    };

    inline void update(llong i, T v) {
        if (i < L || R <= i) expand(i);
        update(root, L, R, i, v);
    };

    void update(Node *node, llong nl, llong nr, llong k, T v) {
        if (nr - nl <= 1) {
            node->v = v;
            return;
        }

        llong mid = (nl + nr) / 2;
        if (k < mid) {
            if (!node->left) node->left = new Node(Monoid::identity());
            update(node->left, nl, (nl + nr) / 2, k, v);
        }
        else {
            if (!node->right) node->right = new Node(Monoid::identity());
            update(node->right, (nl + nr) / 2, nr, k, v);
        }

        eval(*node);
        return;
    }

    // [l, r)
    inline T fold(llong l, llong r) {
        if (l < L) expand(l);
        if (r > R) expand(r);
        return fold(root, L, R, l, r);
    };
    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {
        if (ql <= nl && nr <= qr) return node->v;

        T lv = Monoid::identity(), rv = Monoid::identity();
        llong mid = (nl + nr) / 2;
        if (node->left && ql < mid && nl < qr) {
            lv = fold(node->left, nl, mid, ql, qr);
        }
        if (node->right && ql < nr && mid < qr) {
            rv = fold(node->right, mid, nr, ql, qr);
        }

        return Monoid::operation(lv, rv);
    };
    
    T operator[] (const llong k) {
        return fold(k, k + 1);
    };
};
//===
#line 1 "data_type/max_monoid.hpp"



#line 6 "data_type/max_monoid.hpp"

//===
template<class T>
struct MinMonoid {
    using value_type = T;
    inline static T identity() {
        return std::numeric_limits<T>::min();
    };
    inline static T operation(const T a, const T b) {
        return std::max(a, b);
    };
};
//===


#line 18 "test/aoj/DSL2A_3.test.cpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, x, y;

int main() {
    cin >> n >> q;

    vector<llong> v(n, -1 * ((1ll << 31) - 1));
    DynamicSegmentTree<MinMonoid<llong>> seg();
    for (int i = 0; i < n; i++) {
        seg.update(i, v[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            seg.update(x, -y);
        }
        else {
            cout << -seg.fold(x, y + 1) << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

