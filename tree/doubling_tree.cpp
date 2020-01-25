#include <iostream>
#include <vector>
using namespace std;
using llong = long long;

//===
// definitely call build() before lca() and distance()
// 0-indexed
// climb(u, d): climb d steps towards root
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
    DoublingTree(vector<vector<int> > &g) {
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
    void build(int root = 0) {
        calc_depth(root, 0, -1);
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
