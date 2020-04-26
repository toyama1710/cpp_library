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


# :warning: tree/doubling_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/doubling_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-13 08:01:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
using namespace std;
using llong = long long;

//===
// call build() before other query (except add_edge)
// 0-indexed
// climb(u, d): climb d steps towards root
// fold(u, v):
struct DoublingTree {
    vector<vector<int> > G;
    vector<vector<int> > parent;
    vector<int> depth;
    int logn;

    DoublingTree(int n) {
        logn = 1;
        while ((1 << logn) < n) logn++;

        G.resize(n);
        parent.assign(logn, vector<int>(n, -1));
        depth.assign(n, -1);
    };

    template<class Graph>
    DoublingTree(Graph &g) {
        DoublingTree(g.size());
        for (int i = 0; i < g.size(); i++) {
            G[i].resize(g[i].size());
            for (int j = 0; j < g[i].size(); j++) {
                G[i][j] = g[i][j];
            }
        }
    };

    void calc_depth(int u, int d, int par) {
        depth[u] = d++;
        parent[0][u] = par;
        for (int v:G[u]) {
            if (v == par) continue;
            calc_depth(v, d, u);
        }
    };
    
    void build(vector<int> root = {0}) {
        for (int i = 0; i < root.size(); i++) {
            calc_depth(root[i], 0, -1);
        }
        for (int k = 1; k < logn; k++) {
            for (int u = 0; u < size(); u++) {
                if (parent[k - 1][u] == -1) continue;
                parent[k][u] = parent[k - 1][parent[k - 1][u]];
            }
        }
    };
    
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    };
    int climb(int u, int d) {
        int cnt = 0;
        while (d) {
            if (d & 1) u = parent[cnt][u];
            d >>= 1;
            cnt++;
        }
        return u;
    };
    // LowestCommonAncestor
    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        v = climb(v, depth[v] - depth[u]);

        if (u == v) return u;
        for (int k = logn - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    };
    inline int distance(int u, int v) {
        return depth[u] + depth[v] - depth[lca(u, v)] * 2;
    };
    inline int size() {
        return G.size();
    };
};
//===

// verify lca()
int AOJ_GRL_5_C() {
    int n;
    int k, c;
    int q;
    int u, v;

    cin >> n;
    DoublingTree t(n);

    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            t.add_edge(i, c);
        }
    }

    t.build();
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        cout << t.lca(u, v) << endl;
    }

    return 0;
};

int main() {
    return AOJ_GRL_5_C();
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree/doubling_tree.cpp"
#include <iostream>
#include <vector>
using namespace std;
using llong = long long;

//===
// call build() before other query (except add_edge)
// 0-indexed
// climb(u, d): climb d steps towards root
// fold(u, v):
struct DoublingTree {
    vector<vector<int> > G;
    vector<vector<int> > parent;
    vector<int> depth;
    int logn;

    DoublingTree(int n) {
        logn = 1;
        while ((1 << logn) < n) logn++;

        G.resize(n);
        parent.assign(logn, vector<int>(n, -1));
        depth.assign(n, -1);
    };

    template<class Graph>
    DoublingTree(Graph &g) {
        DoublingTree(g.size());
        for (int i = 0; i < g.size(); i++) {
            G[i].resize(g[i].size());
            for (int j = 0; j < g[i].size(); j++) {
                G[i][j] = g[i][j];
            }
        }
    };

    void calc_depth(int u, int d, int par) {
        depth[u] = d++;
        parent[0][u] = par;
        for (int v:G[u]) {
            if (v == par) continue;
            calc_depth(v, d, u);
        }
    };
    
    void build(vector<int> root = {0}) {
        for (int i = 0; i < root.size(); i++) {
            calc_depth(root[i], 0, -1);
        }
        for (int k = 1; k < logn; k++) {
            for (int u = 0; u < size(); u++) {
                if (parent[k - 1][u] == -1) continue;
                parent[k][u] = parent[k - 1][parent[k - 1][u]];
            }
        }
    };
    
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    };
    int climb(int u, int d) {
        int cnt = 0;
        while (d) {
            if (d & 1) u = parent[cnt][u];
            d >>= 1;
            cnt++;
        }
        return u;
    };
    // LowestCommonAncestor
    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        v = climb(v, depth[v] - depth[u]);

        if (u == v) return u;
        for (int k = logn - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    };
    inline int distance(int u, int v) {
        return depth[u] + depth[v] - depth[lca(u, v)] * 2;
    };
    inline int size() {
        return G.size();
    };
};
//===

// verify lca()
int AOJ_GRL_5_C() {
    int n;
    int k, c;
    int q;
    int u, v;

    cin >> n;
    DoublingTree t(n);

    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            t.add_edge(i, c);
        }
    }

    t.build();
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        cout << t.lca(u, v) << endl;
    }

    return 0;
};

int main() {
    return AOJ_GRL_5_C();
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

