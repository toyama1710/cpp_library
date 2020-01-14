#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

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
// #include <limits>
// #include <queue>
// if s->u path is nothing, min_cost[u] = numeric_limits<T>::max()
// time:O((V+E) log V)
template<class T>
vector<T> dijkstra(WeightedGraph<T> &g, int s) {
    const T INF = numeric_limits<T>::max();
    using P = pair<T, int>;

    vector<T> min_cost(g.size(), INF);
    //vector<T> restore(g.size(), -1);
    priority_queue<P, vector<P>, greater<P> > que;
    que.emplace(0, s);

    while (!que.empty()) {
        T cost = que.top().first;
        int pos = que.top().second;
        que.pop();

        if (min_cost[pos] != INF) continue;
        min_cost[pos] = cost;
        for (Edge<T> e:g[pos]) {
            if (min_cost[e.to] <= cost + e.cost) continue;
            que.emplace(cost + e.cost, e.to);
            //restore[npos] = pos;
        }
    }

    return min_cost;
};
//===

int AOJ_GRL_1_A() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, r;
    int s, t, d;
    const llong INF = numeric_limits<int>::max();

    cin >> n >> m >> r;
    
    WeightedGraph<int> g(n);
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> d;

        g[s].emplace_back(t, d);
    }

    vector<int> dist = dijkstra(g, r);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}

int main() {
    AOJ_GRL_1_A();
    return 0;
}
