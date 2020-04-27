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


# :warning: tree/hl_decomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/hl_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 13:16:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
struct HeavyLightDecomposition {
private:
    vector<vector<int> > G; // UnWeightedGraph
    vector<int> head; // root of heavy-edge
    vector<int> par;
    vector<int> sz;

    void convert_rooted_tree(int v) {
        int sz[v] = 1;
        for (int u:G[v]) {
            if (par[v] == u) continue;
            par[u] = v;
            convert_rooted_tree(u);
            sz[v] += sz[u];
        }
    };

public:
    HeavyLightDecomposition(int n):
        G(n)
    {};
    
    void build(vector<int> rs = {0}) {
        for (int r:rs) {
            convert_rooted_tree(r);
            head[r] = r;
            dfs(r);
        }
    };
    
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    };
    int lca(int u, int v) {
    };
    int distance(int u, int v) {
    };

    //return range on EulerTour
    vector<pair<int, int> > get_ranges(int u, int v) { //vertex
    };
};
//===

int main() {

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree/hl_decomposition.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
struct HeavyLightDecomposition {
private:
    vector<vector<int> > G; // UnWeightedGraph
    vector<int> head; // root of heavy-edge
    vector<int> par;
    vector<int> sz;

    void convert_rooted_tree(int v) {
        int sz[v] = 1;
        for (int u:G[v]) {
            if (par[v] == u) continue;
            par[u] = v;
            convert_rooted_tree(u);
            sz[v] += sz[u];
        }
    };

public:
    HeavyLightDecomposition(int n):
        G(n)
    {};
    
    void build(vector<int> rs = {0}) {
        for (int r:rs) {
            convert_rooted_tree(r);
            head[r] = r;
            dfs(r);
        }
    };
    
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    };
    int lca(int u, int v) {
    };
    int distance(int u, int v) {
    };

    //return range on EulerTour
    vector<pair<int, int> > get_ranges(int u, int v) { //vertex
    };
};
//===

int main() {

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

