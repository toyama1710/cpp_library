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


# :warning: disjoint_set/union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#334b410b60c6352c539a44a5cc4509bc">disjoint_set</a>
* <a href="{{ site.github.repository_url }}/blob/master/disjoint_set/union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-04 13:03:08+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
using namespace std;

//===
struct UnionFind {
    int n;
    vector<int> parent;

    UnionFind() {}
    UnionFind(int nmemb) {
        init(nmemb);
    };

    void init(int nmemb) {
        parent.clear();
        parent.assign(nmemb, -1);
    };

    int root(int x) {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = root(parent[x]);
    };

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return;

        if (parent[y] < parent[x]) swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;
        
        return;
    };
    
    bool same(int x, int y) {
        return root(x) == root(y);
    };
    int size(int x) {
        return -(parent[root(x)]);
    };
};
//===

// verify AOJ DSL_1_A
int main()
{
    UnionFind uf;
    int n, q;
    int com, x, y;

    cin >> n >> q;
    uf.init(n);
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        }
        else {
            if (uf.same(x, y)) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "disjoint_set/union_find.cpp"
#include <iostream>
#include <vector>
using namespace std;

//===
struct UnionFind {
    int n;
    vector<int> parent;

    UnionFind() {}
    UnionFind(int nmemb) {
        init(nmemb);
    };

    void init(int nmemb) {
        parent.clear();
        parent.assign(nmemb, -1);
    };

    int root(int x) {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = root(parent[x]);
    };

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return;

        if (parent[y] < parent[x]) swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;
        
        return;
    };
    
    bool same(int x, int y) {
        return root(x) == root(y);
    };
    int size(int x) {
        return -(parent[root(x)]);
    };
};
//===

// verify AOJ DSL_1_A
int main()
{
    UnionFind uf;
    int n, q;
    int com, x, y;

    cin >> n >> q;
    uf.init(n);
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        }
        else {
            if (uf.same(x, y)) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

