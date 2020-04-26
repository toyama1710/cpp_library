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


# :warning: segment_tree/dynamic_segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/dynamic_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-19 12:22:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cfloat>
using namespace std;

//===
template<class Monoid, class OP = function<Monoid(const Monoid, const Monoid)> >
struct DynamicSegmentTree {
    struct Node {
        Node *left, *right;
        Monoid v;
        Node(Monoid v):v(v), left(nullptr), right(nullptr) {}
    };

    using llong = long long;

    Node *root = nullptr;
    llong L = 0, R = 0;
    const OP merge_monoid; // bin'operation
    const Monoid e;

    DynamicSegmentTree(const Monoid &e, const OP &f):
        e(e), merge_monoid(f) {};

    inline void eval(Node &u) {
        Monoid lv = e, rv = e;
        if (u.left) lv = u.left->v;
        if (u.right) rv = u.right->v;
        u.v = merge_monoid(lv, rv);
    };

    inline void expand(llong i) {
        if (L == R) {
            R++;
            while (i >= R) R += R - L;
            while (i < L) L -= R - L;
            root = new Node(e);
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

    inline void update(llong i, Monoid v) {
        if (i < L || R <= i) expand(i);
        update(root, L, R, i, v);
    };

    void update(Node *node, llong nl, llong nr, llong k, Monoid v) {
        if (nr - nl <= 1) {
            node->v = v;
            return;
        }

        llong mid = (nl + nr) / 2;
        if (k < mid) {
            if (!node->left) node->left = new Node(e);
            update(node->left, nl, (nl + nr) / 2, k, v);
        }
        else {
            if (!node->right) node->right = new Node(e);
            update(node->right, (nl + nr) / 2, nr, k, v);
        }

        eval(*node);
        return;
    }

    // [l, r)
    inline Monoid fold(llong l, llong r) {
        if (l < L) expand(l);
        if (r > R) expand(r);
        return fold(root, L, R, l, r);
    };
    Monoid fold(Node *node, llong nl, llong nr, llong ql, llong qr) {
        if (ql <= nl && nr <= qr) return node->v;

        Monoid lv = e, rv = e;
        llong mid = (nl + nr) / 2;
        if (node->left && ql < mid && nl < qr) {
            lv = fold(node->left, nl, mid, ql, qr);
        }
        if (node->right && ql < nr && mid < qr) {
            rv = fold(node->right, mid, nr, ql, qr);
        }

        return merge_monoid(lv, rv);
    };
    
    Monoid operator[] (const llong k) {
        return fold(k, k + 1);
    };
};
//===

//verify AOJ DSL2A
int DSL_2_A(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<int> RMQ((1u << 31u) - 1,
                    [](int l, int r){
                        return min(l, r);
                    });
    
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            RMQ.update(x, y);
        }
        else {
            cout << RMQ.fold(x, y + 1) << endl;
        }
    }

    return 0;
}

int DSL_2_B(void) {
    using ll = long long;
    
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<ll> RSQ(0, [](ll l, ll r){return l + r;});

    while (q--) {
        cin >> com >> x >> y;

        if (com == 0) {
            RSQ.update(x - 1, RSQ[x - 1] + y);
        }
        else if (com == 1) {
            cout << RSQ.fold(x - 1, y) << endl;
        }
    }
    return 0;
}

int ARC008_D(void) {
    using ll = long long;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    struct func{ double a, b; };
    auto merge = [](func l, func r) {
                     return (func){l.a * r.a, l.b * r.a + r.b};
                 };

    ll n, m;
    ll p;
    double a, b;
    double minv, maxv;
    minv = maxv = 1;

    scanf("%lld %lld", &n, &m);

    DynamicSegmentTree<func, decltype(merge)> seg((func){1, 0}, merge);

    for (int i = 0; i < m; i++) {
        scanf("%lld %lf %lf", &p, &a, &b);
        --p;

        seg.update(p, (func){a, b});
        func x = seg.fold(0, n);

        minv = min(minv, x.a + x.b);
        maxv = max(maxv, x.a + x.b);
    }

    printf("%.*lf\n", DBL_DIG, minv);
    printf("%.*lf\n", DBL_DIG, maxv);

    return 0;
}

int main()
{
    return DSL_2_A();
    //return DSL_2_B();
    //return ARC008_D();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/dynamic_segment_tree.cpp"
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cfloat>
using namespace std;

//===
template<class Monoid, class OP = function<Monoid(const Monoid, const Monoid)> >
struct DynamicSegmentTree {
    struct Node {
        Node *left, *right;
        Monoid v;
        Node(Monoid v):v(v), left(nullptr), right(nullptr) {}
    };

    using llong = long long;

    Node *root = nullptr;
    llong L = 0, R = 0;
    const OP merge_monoid; // bin'operation
    const Monoid e;

    DynamicSegmentTree(const Monoid &e, const OP &f):
        e(e), merge_monoid(f) {};

    inline void eval(Node &u) {
        Monoid lv = e, rv = e;
        if (u.left) lv = u.left->v;
        if (u.right) rv = u.right->v;
        u.v = merge_monoid(lv, rv);
    };

    inline void expand(llong i) {
        if (L == R) {
            R++;
            while (i >= R) R += R - L;
            while (i < L) L -= R - L;
            root = new Node(e);
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

    inline void update(llong i, Monoid v) {
        if (i < L || R <= i) expand(i);
        update(root, L, R, i, v);
    };

    void update(Node *node, llong nl, llong nr, llong k, Monoid v) {
        if (nr - nl <= 1) {
            node->v = v;
            return;
        }

        llong mid = (nl + nr) / 2;
        if (k < mid) {
            if (!node->left) node->left = new Node(e);
            update(node->left, nl, (nl + nr) / 2, k, v);
        }
        else {
            if (!node->right) node->right = new Node(e);
            update(node->right, (nl + nr) / 2, nr, k, v);
        }

        eval(*node);
        return;
    }

    // [l, r)
    inline Monoid fold(llong l, llong r) {
        if (l < L) expand(l);
        if (r > R) expand(r);
        return fold(root, L, R, l, r);
    };
    Monoid fold(Node *node, llong nl, llong nr, llong ql, llong qr) {
        if (ql <= nl && nr <= qr) return node->v;

        Monoid lv = e, rv = e;
        llong mid = (nl + nr) / 2;
        if (node->left && ql < mid && nl < qr) {
            lv = fold(node->left, nl, mid, ql, qr);
        }
        if (node->right && ql < nr && mid < qr) {
            rv = fold(node->right, mid, nr, ql, qr);
        }

        return merge_monoid(lv, rv);
    };
    
    Monoid operator[] (const llong k) {
        return fold(k, k + 1);
    };
};
//===

//verify AOJ DSL2A
int DSL_2_A(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<int> RMQ((1u << 31u) - 1,
                    [](int l, int r){
                        return min(l, r);
                    });
    
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            RMQ.update(x, y);
        }
        else {
            cout << RMQ.fold(x, y + 1) << endl;
        }
    }

    return 0;
}

int DSL_2_B(void) {
    using ll = long long;
    
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<ll> RSQ(0, [](ll l, ll r){return l + r;});

    while (q--) {
        cin >> com >> x >> y;

        if (com == 0) {
            RSQ.update(x - 1, RSQ[x - 1] + y);
        }
        else if (com == 1) {
            cout << RSQ.fold(x - 1, y) << endl;
        }
    }
    return 0;
}

int ARC008_D(void) {
    using ll = long long;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    struct func{ double a, b; };
    auto merge = [](func l, func r) {
                     return (func){l.a * r.a, l.b * r.a + r.b};
                 };

    ll n, m;
    ll p;
    double a, b;
    double minv, maxv;
    minv = maxv = 1;

    scanf("%lld %lld", &n, &m);

    DynamicSegmentTree<func, decltype(merge)> seg((func){1, 0}, merge);

    for (int i = 0; i < m; i++) {
        scanf("%lld %lf %lf", &p, &a, &b);
        --p;

        seg.update(p, (func){a, b});
        func x = seg.fold(0, n);

        minv = min(minv, x.a + x.b);
        maxv = max(maxv, x.a + x.b);
    }

    printf("%.*lf\n", DBL_DIG, minv);
    printf("%.*lf\n", DBL_DIG, maxv);

    return 0;
}

int main()
{
    return DSL_2_A();
    //return DSL_2_B();
    //return ARC008_D();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

