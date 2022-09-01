#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

//===
template <class T>
struct Edge {
    int src, to;
    T cost;

    Edge(int to, T cost) : src(-1), to(to), cost(cost){};
    Edge(int src, int to, T cost) : src(src), to(to), cost(cost){};

    operator int() const {
        return to;
    };
};

template <class T>
using WeightedGraph = vector<vector<Edge<T>>>;
using UnWeightedGraph = vector<vector<int>>;
//===

//===
// require graph/basic.cpp
// #inlcude <limits>

// when g has negative cycle, it returns empty vector<>
// time: O(|E||V|)
template <class T>
vector<T> bellman_ford(WeightedGraph<T> &g, int from) {
    const T INF = numeric_limits<T>::max();
    const int V = g.size();
    vector<T> min_cost(g.size(), INF);

    min_cost[from] = 0;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (auto &e : g[i]) {
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

// when some negative cycles is into from->to path has, it returns empty
// vector<T>
template <class T>
vector<T> bellman_ford(WeightedGraph<T> &g, int from, int to) {
    const T INF = numeric_limits<T>::max();
    const int V = g.size();
    vector<T> min_cost(g.size(), INF);
    vector<bool> used(g.size(), 0);
    vector<bool> reach(g.size(), 0);

    auto dfs = [&](auto &&f, int u) -> bool {
        if (used[u]) return reach[u];
        used[u] = true;
        for (int v : g[u]) reach[u] = reach[u] | f(f, v);
        return reach[u];
    };

    reach[to] = true;
    for (int i = 0; i < V; i++) dfs(dfs, i);

    min_cost[from] = 0;
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (auto &e : g[i]) {
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
    for (auto &e : dist) {
        if (e == numeric_limits<int>::max())
            cout << "INF" << endl;
        else
            cout << e << endl;
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

    if (dist.empty())
        cout << -1 << endl;
    else
        cout << max(0ll, -dist[n]) << endl;

    return 0;
};

int main() {
    return ABC137_E();
    // return AOJ_GRL_1_B();
};
