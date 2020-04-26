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


# :warning: segment_tree/segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-25 15:38:50+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<typename Monoid, typename OP = function<Monoid(Monoid, Monoid)> >
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    vector<Monoid> tree;
    int size;
    const OP merge_monoid; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(const Monoid &e, const OP &f):
        merge_monoid(f), e(e) {};
    void init(int nmemb) {
        size = nmemb;
        tree.assign(size << 1, e);
    };

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid &e, const OP &f):
        size(distance(first, last)), merge_monoid(f), e(e)
    {
        tree.resize(size << 1);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    inline void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    inline Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);

            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===

//verify AOJ DSL_2_B
int AOJ_DSL2B() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    int com, x, y;
    SegmentTree<int> RSQ(0, [](int l, int r){return l + r;});

    scanf("%d %d", &n, &q);
    RSQ.init(n);

    while (q--) {
        scanf("%d %d %d", &com, &x, &y);
        x--;

        if (com == 0) {
            y += RSQ.fold(x, x + 1);
            RSQ.update(x, y);
        }
        else {
            printf("%d\n", RSQ.fold(x, y));
        }
    }

    return 0;
}

//verify AOJ DSL_2_A
int AOJ_DSL2A() {
    int n, q;
    int com, x, y;
    SegmentTree<int> RMQ((1u << 31u) - 1,
                         [](int l, int r){return min(l, r);});

    cin >> n >> q;
    RMQ.init(n);
    
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

int main() {
    return AOJ_DSL2B();
    //return AOJ_DSL2A();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/segment_tree.cpp"
//#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<typename Monoid, typename OP = function<Monoid(Monoid, Monoid)> >
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    vector<Monoid> tree;
    int size;
    const OP merge_monoid; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(const Monoid &e, const OP &f):
        merge_monoid(f), e(e) {};
    void init(int nmemb) {
        size = nmemb;
        tree.assign(size << 1, e);
    };

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid &e, const OP &f):
        size(distance(first, last)), merge_monoid(f), e(e)
    {
        tree.resize(size << 1);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    inline void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    inline Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);

            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===

//verify AOJ DSL_2_B
int AOJ_DSL2B() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    int com, x, y;
    SegmentTree<int> RSQ(0, [](int l, int r){return l + r;});

    scanf("%d %d", &n, &q);
    RSQ.init(n);

    while (q--) {
        scanf("%d %d %d", &com, &x, &y);
        x--;

        if (com == 0) {
            y += RSQ.fold(x, x + 1);
            RSQ.update(x, y);
        }
        else {
            printf("%d\n", RSQ.fold(x, y));
        }
    }

    return 0;
}

//verify AOJ DSL_2_A
int AOJ_DSL2A() {
    int n, q;
    int com, x, y;
    SegmentTree<int> RMQ((1u << 31u) - 1,
                         [](int l, int r){return min(l, r);});

    cin >> n >> q;
    RMQ.init(n);
    
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

int main() {
    return AOJ_DSL2B();
    //return AOJ_DSL2A();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

