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


# :warning: graph/bellman_ford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-04 12:45:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
using namespace std;

//===
template<class T>
struct Edge {
    int src, to;
    T cost;

    Edge (int to, T cost):
        src(-1), to(to), cost(cost) {};
    Edge (int src, int to, T cost):
        src(src), to(to), cost(cost) {};

    operator int() const {
        return to;
    };
};

template <class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using UnWeightedGraph = vector<vector<int> >;
//===

//===
// require graph/basic.cpp
// #inlcude <limits>

// when g has negative cycle, it returns empty vector<>
// time: O(|E||V|)
template<class T>
vector<T> bellman_ford(WeightedGraph<T> &g, int from) {

    const T INF = numeric_limits<T>::max();
    const int V = g.size();
    vector<T> min_cost(g.size(), INF);

    min_cost[from] = 0;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (auto &e:g[i]) {
                if (min_cost[i] == INF) break;
                if (min_cost[i] + e.cost < min_cost[e.to]) {
                    
                    min_cost[e.to] = min_cost[i] + e.cost;
                    if (k == V - 1) return vector<T>();
                }
            }
        }
    }

    return min_cost;
};

// when some negative cycles is into from->to path has, it returns empty vector<T>
template<class T>
vector<T> bellman_ford(WeightedGraph<T> &g, int from, int to) {
    
    const T INF = numeric_limits<T>::max();
    const int V = g.size();
    vector<T> min_cost(g.size(), INF);
    vector<bool> used(g.size(), 0);
    vector<bool> reach(g.size(), 0);

    auto dfs = [&](auto &&f, int u) -> bool {
                   if (used[u]) return reach[u];
                   used[u] = true;
                   for (int v:g[u]) reach[u] = reach[u] | f(f, v);
                   return reach[u];
               };

    reach[to] = true;
    for (int i = 0; i < V; i++) dfs(dfs, i);
    
    min_cost[from] = 0;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (auto &e:g[i]) {
                if (min_cost[i] == INF) break;
                if (min_cost[i] + e.cost < min_cost[e.to]) {
                    
                    min_cost[e.to] = min_cost[i] + e.cost;
                    if (k == V - 1 && reach[i]) return vector<T>();
                }
            }
        }
    }

    return min_cost;
};
//===

int AOJ_GRL_1_B() {
    int V, E, R;
    int s, t, d;

    cin >> V >> E >> R;
    WeightedGraph<int> G(V);
    for (int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }

    auto dist = bellman_ford(G, R);

    if (dist.empty()) cout << "NEGATIVE CYCLE" << endl;
    for (auto &e:dist) {
        if (e == numeric_limits<int>::max()) cout << "INF" << endl;
        else cout << e << endl;
    }

    return 0;
};

int ABC137_E() {
    using llong = long long;
    
    llong n, m, p;
    llong a, b, c;
    WeightedGraph<llong> G(2505);

    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].emplace_back(b, p - c);
    }

    auto dist = bellman_ford(G, 1, n);

    if (dist.empty()) cout << -1 << endl;
    else cout << max(0ll, -dist[n]) << endl;

    return 0;
};

int main() {
    return ABC137_E();
    //return AOJ_GRL_1_B();
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bellman_ford.cpp"
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
using namespace std;

//===
template<class T>
struct Edge {
    int src, to;
    T cost;

    Edge (int to, T cost):
        src(-1), to(to), cost(cost) {};
    Edge (int src, int to, T cost):
        src(src), to(to), cost(cost) {};

    operator int() const {
        return to;
    };
};

template <class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using UnWeightedGraph = vector<vector<int> >;
//===

//===
// require graph/basic.cpp
// #inlcude <limits>

// when g has negative cycle, it returns empty vector<>
// time: O(|E||V|)
template<class T>
vector<T> bellman_ford(WeightedGraph<T> &g, int from) {

    const T INF = numeric_limits<T>::max();
    const int V = g.size();
    vector<T> min_cost(g.size(), INF);

    min_cost[from] = 0;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (auto &e:g[i]) {
                if (min_cost[i] == INF) break;
                if (min_cost[i] + e.cost < min_cost[e.to]) {
                    
                    min_cost[e.to] = min_cost[i] + e.cost;
                    if (k == V - 1) return vector<T>();
                }
            }
        }
    }

    return min_cost;
};

// when some negative cycles is into from->to path has, it returns empty vector<T>
template<class T>
vector<T> bellman_ford(WeightedGraph<T> &g, int from, int to) {
    
    const T INF = numeric_limits<T>::max();
    const int V = g.size();
    vector<T> min_cost(g.size(), INF);
    vector<bool> used(g.size(), 0);
    vector<bool> reach(g.size(), 0);

    auto dfs = [&](auto &&f, int u) -> bool {
                   if (used[u]) return reach[u];
                   used[u] = true;
                   for (int v:g[u]) reach[u] = reach[u] | f(f, v);
                   return reach[u];
               };

    reach[to] = true;
    for (int i = 0; i < V; i++) dfs(dfs, i);
    
    min_cost[from] = 0;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (auto &e:g[i]) {
                if (min_cost[i] == INF) break;
                if (min_cost[i] + e.cost < min_cost[e.to]) {
                    
                    min_cost[e.to] = min_cost[i] + e.cost;
                    if (k == V - 1 && reach[i]) return vector<T>();
                }
            }
        }
    }

    return min_cost;
};
//===

int AOJ_GRL_1_B() {
    int V, E, R;
    int s, t, d;

    cin >> V >> E >> R;
    WeightedGraph<int> G(V);
    for (int i = 0; i < E; i++) {
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }

    auto dist = bellman_ford(G, R);

    if (dist.empty()) cout << "NEGATIVE CYCLE" << endl;
    for (auto &e:dist) {
        if (e == numeric_limits<int>::max()) cout << "INF" << endl;
        else cout << e << endl;
    }

    return 0;
};

int ABC137_E() {
    using llong = long long;
    
    llong n, m, p;
    llong a, b, c;
    WeightedGraph<llong> G(2505);

    cin >> n >> m >> p;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].emplace_back(b, p - c);
    }

    auto dist = bellman_ford(G, 1, n);

    if (dist.empty()) cout << -1 << endl;
    else cout << max(0ll, -dist[n]) << endl;

    return 0;
};

int main() {
    return ABC137_E();
    //return AOJ_GRL_1_B();
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

