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


# :warning: disjoint_set/partially_persitent_union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#334b410b60c6352c539a44a5cc4509bc">disjoint_set</a>
* <a href="{{ site.github.repository_url }}/blob/master/disjoint_set/partially_persitent_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 01:10:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
struct PartiallyPersistentUnionFind {
    int turn;
    vector<int> t;
    vector<int> par;
    vector<vector<pair<int, int> > > sz;

    PartiallyPersistentUnionFind(int n):
        turn(0),
        t(n, -1),
        par(n, -1),
        sz(n, vector<pair<int, int> >(1, make_pair(0, 1)))
    {};

    bool unite(int x, int y) {
        x = find(turn, x);
        y = find(turn, y);
        turn++;

        if (x == y) return false;
                        
        if (par[y] < par[x]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        
        t[y] = turn;
        sz[x].push_back(make_pair(turn, -par[x]));

        return true;
    };

    int find (int time, int x) {
        if (par[x] < 0 || t[x] > time) return x;
        return find(time, par[x]);
    };

    bool same(int time, int x, int y) {
        return find(time, x) == find(time, y);
    };

    int size(int time, int x) {
        x = find(time, x);
        return (upper_bound(sz[x].begin(), sz[x].end(), make_pair(time, 1<<30)) - 1)->second;
    };
};
//===

int CodeThanksFes2017H() {
    int n, m;
    int a, b;
    int q;
    int x, y;

    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        --a, --b;

        uf.unite(a, b);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        --x, --y;

        int valid = m + 1;
        int invalid = 0;

        while (valid - invalid > 1) {
            int mid = (valid + invalid) / 2;

            if (uf.same(mid, x, y)) {
                valid = mid;
            }
            else {
                invalid = mid;
            }
        }

        if (invalid == m) {
            cout << -1 << endl;
        }
        else {
            cout << valid << endl;
        }
    }

    return 0;
}

int AGC002D() {
    int n, m;
    int a, b;
    int q;
    int x, y, z;

    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        
        uf.unite(a, b);
    }

    auto f = [&](int t) {
                 llong xs = uf.size(t, x);
                 llong ys = uf.size(t, y);

                 if (uf.same(t, x, y)) return xs;
                 else return xs + ys;
             };

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z;
        x--, y--;

        llong valid, invalid;
        llong mid;

        valid = m;
        invalid = 0;
        while (valid - invalid > 1) {
            mid = (valid + invalid) / 2;

            if (f(mid) >= z) valid = mid;
            else invalid = mid;
        }
        
        cout << valid << endl;
    }

    return 0;
}

int main() {
    //return CodeThanksFes2017H();
    return AGC002D();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "disjoint_set/partially_persitent_union_find.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
struct PartiallyPersistentUnionFind {
    int turn;
    vector<int> t;
    vector<int> par;
    vector<vector<pair<int, int> > > sz;

    PartiallyPersistentUnionFind(int n):
        turn(0),
        t(n, -1),
        par(n, -1),
        sz(n, vector<pair<int, int> >(1, make_pair(0, 1)))
    {};

    bool unite(int x, int y) {
        x = find(turn, x);
        y = find(turn, y);
        turn++;

        if (x == y) return false;
                        
        if (par[y] < par[x]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        
        t[y] = turn;
        sz[x].push_back(make_pair(turn, -par[x]));

        return true;
    };

    int find (int time, int x) {
        if (par[x] < 0 || t[x] > time) return x;
        return find(time, par[x]);
    };

    bool same(int time, int x, int y) {
        return find(time, x) == find(time, y);
    };

    int size(int time, int x) {
        x = find(time, x);
        return (upper_bound(sz[x].begin(), sz[x].end(), make_pair(time, 1<<30)) - 1)->second;
    };
};
//===

int CodeThanksFes2017H() {
    int n, m;
    int a, b;
    int q;
    int x, y;

    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        --a, --b;

        uf.unite(a, b);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        --x, --y;

        int valid = m + 1;
        int invalid = 0;

        while (valid - invalid > 1) {
            int mid = (valid + invalid) / 2;

            if (uf.same(mid, x, y)) {
                valid = mid;
            }
            else {
                invalid = mid;
            }
        }

        if (invalid == m) {
            cout << -1 << endl;
        }
        else {
            cout << valid << endl;
        }
    }

    return 0;
}

int AGC002D() {
    int n, m;
    int a, b;
    int q;
    int x, y, z;

    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;
        
        uf.unite(a, b);
    }

    auto f = [&](int t) {
                 llong xs = uf.size(t, x);
                 llong ys = uf.size(t, y);

                 if (uf.same(t, x, y)) return xs;
                 else return xs + ys;
             };

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z;
        x--, y--;

        llong valid, invalid;
        llong mid;

        valid = m;
        invalid = 0;
        while (valid - invalid > 1) {
            mid = (valid + invalid) / 2;

            if (f(mid) >= z) valid = mid;
            else invalid = mid;
        }
        
        cout << valid << endl;
    }

    return 0;
}

int main() {
    //return CodeThanksFes2017H();
    return AGC002D();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

