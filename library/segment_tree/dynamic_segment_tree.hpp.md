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


# :heavy_check_mark: segment_tree/dynamic_segment_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/dynamic_segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-06 02:39:07+00:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL2A_3.test.cpp.html">test/aoj/DSL2A_3.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

