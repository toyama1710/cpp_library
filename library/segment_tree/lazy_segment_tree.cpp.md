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


# :warning: segment_tree/lazy_segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/lazy_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-03 00:09:12+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<class Monoid, class Laz>
struct LazySegmentTree {

    const function<Monoid(Monoid, Monoid)> mergeMonoid;
    const function<Monoid(Monoid, Laz, int)> applyLaz;
    const function<Laz(Laz, Laz)> mergeLaz;
    
    const Monoid e; // neutral element
    
    vector<Monoid> seg;
    vector<Laz> lazy;
    vector<bool> isUpdated;
    
    int size;
                                           
    LazySegmentTree(int nmemb, const Monoid &e,
                    function<Monoid(Monoid, Monoid)> f,
                    function<Monoid(Monoid, Laz, int)> g,
                    function<Laz(Laz, Laz)> h):
        e(e), mergeMonoid(f), applyLaz(g), mergeLaz(h)
    {
        size = 1;
        while (size < nmemb) {
            size *= 2;
        }

        seg.assign(2 * size - 1, e);
        isUpdated.assign(2 * size - 1, true);
        lazy.resize(2 * size - 1); 
    };

    inline void propagation(int k, int len) {
        if (!isUpdated[k]) {
            seg[k] = applyLaz(seg[k], lazy[k], len);
            if (len > 1) {
                if (isUpdated[2 * k + 1])
                    lazy[2 * k + 1] = lazy[k], isUpdated[2 * k + 1] = false;
                else
                    lazy[2 * k + 1] = mergeLaz(lazy[2 * k + 1], lazy[k]);
                
                if (isUpdated[2 * k + 2])
                    lazy[2 * k + 2] = lazy[k], isUpdated[2 * k + 2] = false;
                else 
                    lazy[2 * k + 2] = mergeLaz(lazy[2 * k + 2], lazy[k]);
            }
            isUpdated[k] = true;
        }
    };

    // [l, r) <= dat
    void update(int l, int r, Laz dat) {
        update(0, 0, size, l, r, dat);
    };
    Monoid update(int k, int nl, int nr, int ql, int qr, Laz dat) {
        propagation(k, nr - nl);

        if (nr <= ql || qr <= nl) return seg[k];

        if (ql <= nl && nr <= qr) {
            lazy[k] = dat;
            isUpdated[k] = false;
            propagation(k, nr - nl);
            return seg[k];
        }
        else {
            seg[k] = mergeMonoid(update(2 * k + 1, nl, (nl + nr) / 2, ql, qr, dat),
                                 update(2 * k + 2, (nl + nr) / 2, nr, ql, qr, dat));
            return seg[k];
        }
    };

    // [l, r)
    Monoid fold(int l, int r) {
        return fold(0, 0, size, l, r);
    };
    Monoid fold(int k, int nl, int nr, int ql, int qr) {

        propagation(k, nr - nl);
        
        if (nr <= ql || qr <= nl) return e;

        if (ql <= nl && nr <= qr) return seg[k];
        else return mergeMonoid(fold(2 * k + 1, nl, (nl + nr) / 2, ql, qr),
                                fold(2 * k + 2, (nl + nr) / 2, nr, ql, qr));
    };

    Monoid operator [](const int &k) {
        return fold(k, k + 1);
    };
};
//===

//verify 2019/07/25 17:12
int DSL_2_D(void)
{
    int n, q;
    int com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<int, int> seg(n, -1,
                                  /*f=*/[](int l, int r){
                                      return max(l, r);
                                  },
                                  /*g=*/[](int m, int laz, int len){
                                      return laz;
                                  },
                                  /*h=*/[](int l, int r) {
                                      return r;
                                  });

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else if (com == 1) {
            cin >> s;
            int a = seg[s];

            if (a == -1) cout << (1ll << 31ll) - 1 << endl;
            else cout << a << endl;
        }
    }

    return 0;
}

//verify 2019/07/25 17:21
int DSL_2_E()
{
    int n, q;
    int com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<int, int> seg(n, 0,
                                  [](int l, int r){
                                      return l + r;
                                  },
                                  [](int l, int r, int len){
                                      return l + (r * len);
                                  },
                                  [](int l, int r){
                                      return l + r;
                                  });
                                  

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            s--;

            seg.update(s, t, x);
        }
        else if (com == 1) {
            cin >> s;
            s--;

            cout << seg[s] << endl;
        }
    }

	return 0;
}

//verify 2019/07/25 17:27
int DSL_2_F(void)
{
    using ll = long long;
        
    ll n, q;
    ll com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<ll, ll> seg(n, (1ll << 31ll) - 1,
                                [](ll l, ll r){ return min(l, r); },
                                [](ll m, ll laz, int len){ return laz; },
                                [](ll l, ll r){ return r; });

    while (q--) {
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

int DSL_2_H(void)
{
    using ll = long long;

    ll n, q;
    ll com, s, t, x;

    cin >> n >> q;
    LazySegmentTree<ll, ll> seg(n, 1ll << 60ll,
                                [](ll l, ll r){ return min(l, r); },
                                [](ll m, ll l, int len){ return m + l; },
                                [](ll l, ll r){ return l + r; });
    seg.update(0, n, -1 * (1ll << 60ll));

    while (q--) {
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

int DSL_2_I(void)
{
    using ll = long long;

    ll n, q;
    ll com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<ll, ll> seg(n, 0,
                                [](ll l, ll r){ return l + r; },
                                [](ll m, ll l, ll len){ return l * len; },
                                [](ll l, ll r){ return r; });

    while (q--) {
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

int main()
{
    //return DSL_2_D();
    //return DSL_2_E();
    //return DSL_2_F();
    //return DSL_2_H();
    return DSL_2_I();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/lazy_segment_tree.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<class Monoid, class Laz>
struct LazySegmentTree {

    const function<Monoid(Monoid, Monoid)> mergeMonoid;
    const function<Monoid(Monoid, Laz, int)> applyLaz;
    const function<Laz(Laz, Laz)> mergeLaz;
    
    const Monoid e; // neutral element
    
    vector<Monoid> seg;
    vector<Laz> lazy;
    vector<bool> isUpdated;
    
    int size;
                                           
    LazySegmentTree(int nmemb, const Monoid &e,
                    function<Monoid(Monoid, Monoid)> f,
                    function<Monoid(Monoid, Laz, int)> g,
                    function<Laz(Laz, Laz)> h):
        e(e), mergeMonoid(f), applyLaz(g), mergeLaz(h)
    {
        size = 1;
        while (size < nmemb) {
            size *= 2;
        }

        seg.assign(2 * size - 1, e);
        isUpdated.assign(2 * size - 1, true);
        lazy.resize(2 * size - 1); 
    };

    inline void propagation(int k, int len) {
        if (!isUpdated[k]) {
            seg[k] = applyLaz(seg[k], lazy[k], len);
            if (len > 1) {
                if (isUpdated[2 * k + 1])
                    lazy[2 * k + 1] = lazy[k], isUpdated[2 * k + 1] = false;
                else
                    lazy[2 * k + 1] = mergeLaz(lazy[2 * k + 1], lazy[k]);
                
                if (isUpdated[2 * k + 2])
                    lazy[2 * k + 2] = lazy[k], isUpdated[2 * k + 2] = false;
                else 
                    lazy[2 * k + 2] = mergeLaz(lazy[2 * k + 2], lazy[k]);
            }
            isUpdated[k] = true;
        }
    };

    // [l, r) <= dat
    void update(int l, int r, Laz dat) {
        update(0, 0, size, l, r, dat);
    };
    Monoid update(int k, int nl, int nr, int ql, int qr, Laz dat) {
        propagation(k, nr - nl);

        if (nr <= ql || qr <= nl) return seg[k];

        if (ql <= nl && nr <= qr) {
            lazy[k] = dat;
            isUpdated[k] = false;
            propagation(k, nr - nl);
            return seg[k];
        }
        else {
            seg[k] = mergeMonoid(update(2 * k + 1, nl, (nl + nr) / 2, ql, qr, dat),
                                 update(2 * k + 2, (nl + nr) / 2, nr, ql, qr, dat));
            return seg[k];
        }
    };

    // [l, r)
    Monoid fold(int l, int r) {
        return fold(0, 0, size, l, r);
    };
    Monoid fold(int k, int nl, int nr, int ql, int qr) {

        propagation(k, nr - nl);
        
        if (nr <= ql || qr <= nl) return e;

        if (ql <= nl && nr <= qr) return seg[k];
        else return mergeMonoid(fold(2 * k + 1, nl, (nl + nr) / 2, ql, qr),
                                fold(2 * k + 2, (nl + nr) / 2, nr, ql, qr));
    };

    Monoid operator [](const int &k) {
        return fold(k, k + 1);
    };
};
//===

//verify 2019/07/25 17:12
int DSL_2_D(void)
{
    int n, q;
    int com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<int, int> seg(n, -1,
                                  /*f=*/[](int l, int r){
                                      return max(l, r);
                                  },
                                  /*g=*/[](int m, int laz, int len){
                                      return laz;
                                  },
                                  /*h=*/[](int l, int r) {
                                      return r;
                                  });

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else if (com == 1) {
            cin >> s;
            int a = seg[s];

            if (a == -1) cout << (1ll << 31ll) - 1 << endl;
            else cout << a << endl;
        }
    }

    return 0;
}

//verify 2019/07/25 17:21
int DSL_2_E()
{
    int n, q;
    int com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<int, int> seg(n, 0,
                                  [](int l, int r){
                                      return l + r;
                                  },
                                  [](int l, int r, int len){
                                      return l + (r * len);
                                  },
                                  [](int l, int r){
                                      return l + r;
                                  });
                                  

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            s--;

            seg.update(s, t, x);
        }
        else if (com == 1) {
            cin >> s;
            s--;

            cout << seg[s] << endl;
        }
    }

	return 0;
}

//verify 2019/07/25 17:27
int DSL_2_F(void)
{
    using ll = long long;
        
    ll n, q;
    ll com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<ll, ll> seg(n, (1ll << 31ll) - 1,
                                [](ll l, ll r){ return min(l, r); },
                                [](ll m, ll laz, int len){ return laz; },
                                [](ll l, ll r){ return r; });

    while (q--) {
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

int DSL_2_H(void)
{
    using ll = long long;

    ll n, q;
    ll com, s, t, x;

    cin >> n >> q;
    LazySegmentTree<ll, ll> seg(n, 1ll << 60ll,
                                [](ll l, ll r){ return min(l, r); },
                                [](ll m, ll l, int len){ return m + l; },
                                [](ll l, ll r){ return l + r; });
    seg.update(0, n, -1 * (1ll << 60ll));

    while (q--) {
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

int DSL_2_I(void)
{
    using ll = long long;

    ll n, q;
    ll com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<ll, ll> seg(n, 0,
                                [](ll l, ll r){ return l + r; },
                                [](ll m, ll l, ll len){ return l * len; },
                                [](ll l, ll r){ return r; });

    while (q--) {
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

int main()
{
    //return DSL_2_D();
    //return DSL_2_E();
    //return DSL_2_F();
    //return DSL_2_H();
    return DSL_2_I();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

