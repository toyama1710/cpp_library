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


# :warning: disjoint_set/weighted_union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#334b410b60c6352c539a44a5cc4509bc">disjoint_set</a>
* <a href="{{ site.github.repository_url }}/blob/master/disjoint_set/weighted_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-04 12:59:40+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <string>
#include <map>
using namespace std;

//===
//#include <vector>
//#include <functional>
template<typename Abel>
struct WeightedUnionFind {
    using OP = function<Abel(Abel, Abel)>;

    vector<int> parent;
    vector<Abel> diff_weight; // distance from root
    const OP add;
    const OP sub;
    const Abel e;
    
    WeightedUnionFind(int nmemb,
                      const Abel &e = 0,
                      const OP &add = [](Abel x, Abel y){return x+y;},
                      const OP &sub = [](Abel x, Abel y){return x-y;}):
        e(e), add(add), sub(sub)
    {
        parent.assign(nmemb, -1);
        diff_weight.assign(nmemb, e);
    };

    int root(int x) {
        if (parent[x] < 0) {
            return x;
        }
        
        int p = root(parent[x]);
        diff_weight[x] = add(diff_weight[x], diff_weight[parent[x]]);
        parent[x] = p;

        return p;
    };

    bool unite(int x, int y, Abel w) {
        Abel wx = weight(x);
        Abel wy = weight(y);
        x = root(x);
        y = root(y);

        if (x == y) return false;
        w = sub(add(w, wx), wy);
        if (size(x) < size(y)) swap(x, y), w = -w;

        parent[x] += parent[y];
        parent[y] = x;
        diff_weight[y] = w;
        
        return true;
    };
    
    bool same(int x, int y) {
        return root(x) == root(y);
    };
    
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    };

    Abel diff(int x, int y) {
        return sub(weight(y), weight(x));
    };

    int size(int x) {
        return -parent[root(x)];
    };
};
//===

typedef long long ll;

// verify AtCoder Beginner Contest 087 D
int abc087D(void)
{
    WeightedUnionFind<ll> uf(1000005);
    ll n, m;
    ll l, r, d;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> d;

        uf.unite(l, r, d);

        if (uf.diff(l, r) != d) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}

// verify AOJ_DSL_1_B
int AOJ_DSL1B(void)
{
    int n, q;
    ll com, x, y, w;

    cin >> n >> q;
    
    WeightedUnionFind<ll> uf(n);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> x >> y >> w;
            uf.unite(x, y, w);
        }
        else {
            cin >> x >> y;
            if (uf.same(x, y)) {
                cout << uf.diff(x, y) << endl;
            }
            else {
                cout << '?' << endl;
            }
        }
    }

    return 0;
}

// verify UTPC2010 D
int UTPC2010D(void)
{
    int n;
    while (cin >> n, n != 0) {
        map<string, int> mp;
        string s, t;
        int id = 1;
        ll cost;
        WeightedUnionFind<ll> uf(n * 2 + 5);
        bool f = true;

        for (int i = 0; i < n; i++) {
            scanf("%*d"); // '1'
            cin >> s; //
            scanf(" %*c "); // '='
            scanf("10^ %lld", &cost);
            cin >> t;

            if (mp.count(s) == 0) {
                mp[s] = id++;
            }
            if (mp.count(t) == 0) {
                mp[t] = id++;
            }

            uf.unite(mp[s], mp[t], cost);

            if (uf.diff(mp[s], mp[t]) != cost) {
                f = false;
            }
        }

        if (f) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}

int main()
{
    //return abc087D();
    return AOJ_DSL1B();
    //return UTPC2010D();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "disjoint_set/weighted_union_find.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <functional>
#include <string>
#include <map>
using namespace std;

//===
//#include <vector>
//#include <functional>
template<typename Abel>
struct WeightedUnionFind {
    using OP = function<Abel(Abel, Abel)>;

    vector<int> parent;
    vector<Abel> diff_weight; // distance from root
    const OP add;
    const OP sub;
    const Abel e;
    
    WeightedUnionFind(int nmemb,
                      const Abel &e = 0,
                      const OP &add = [](Abel x, Abel y){return x+y;},
                      const OP &sub = [](Abel x, Abel y){return x-y;}):
        e(e), add(add), sub(sub)
    {
        parent.assign(nmemb, -1);
        diff_weight.assign(nmemb, e);
    };

    int root(int x) {
        if (parent[x] < 0) {
            return x;
        }
        
        int p = root(parent[x]);
        diff_weight[x] = add(diff_weight[x], diff_weight[parent[x]]);
        parent[x] = p;

        return p;
    };

    bool unite(int x, int y, Abel w) {
        Abel wx = weight(x);
        Abel wy = weight(y);
        x = root(x);
        y = root(y);

        if (x == y) return false;
        w = sub(add(w, wx), wy);
        if (size(x) < size(y)) swap(x, y), w = -w;

        parent[x] += parent[y];
        parent[y] = x;
        diff_weight[y] = w;
        
        return true;
    };
    
    bool same(int x, int y) {
        return root(x) == root(y);
    };
    
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    };

    Abel diff(int x, int y) {
        return sub(weight(y), weight(x));
    };

    int size(int x) {
        return -parent[root(x)];
    };
};
//===

typedef long long ll;

// verify AtCoder Beginner Contest 087 D
int abc087D(void)
{
    WeightedUnionFind<ll> uf(1000005);
    ll n, m;
    ll l, r, d;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> d;

        uf.unite(l, r, d);

        if (uf.diff(l, r) != d) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}

// verify AOJ_DSL_1_B
int AOJ_DSL1B(void)
{
    int n, q;
    ll com, x, y, w;

    cin >> n >> q;
    
    WeightedUnionFind<ll> uf(n);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> x >> y >> w;
            uf.unite(x, y, w);
        }
        else {
            cin >> x >> y;
            if (uf.same(x, y)) {
                cout << uf.diff(x, y) << endl;
            }
            else {
                cout << '?' << endl;
            }
        }
    }

    return 0;
}

// verify UTPC2010 D
int UTPC2010D(void)
{
    int n;
    while (cin >> n, n != 0) {
        map<string, int> mp;
        string s, t;
        int id = 1;
        ll cost;
        WeightedUnionFind<ll> uf(n * 2 + 5);
        bool f = true;

        for (int i = 0; i < n; i++) {
            scanf("%*d"); // '1'
            cin >> s; //
            scanf(" %*c "); // '='
            scanf("10^ %lld", &cost);
            cin >> t;

            if (mp.count(s) == 0) {
                mp[s] = id++;
            }
            if (mp.count(t) == 0) {
                mp[t] = id++;
            }

            uf.unite(mp[s], mp[t], cost);

            if (uf.diff(mp[s], mp[t]) != cost) {
                f = false;
            }
        }

        if (f) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}

int main()
{
    //return abc087D();
    return AOJ_DSL1B();
    //return UTPC2010D();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

