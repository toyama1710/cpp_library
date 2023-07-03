#ifndef DOUBLING_TREE_HPP
#define DOUBLING_TREE_HPP
#include <iterator>
#include <optional>
#include <vector>

// 0-indexed
// climb(u, d): climb d steps towards root
// fold(u, v):
struct DoublingTree {
    std::vector<std::vector<std::optional<int>>> parent;
    std::vector<int> depth;
    int logn;

    template <class InputItr>
    DoublingTree(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        std::vector<std::optional<int>> p(n, std::nullopt);
        int i = 0;
        for (auto itr = first; itr != last; itr++, i++) {
            if (itr->has_value()) p[i] = (int)itr->value();
        }
        build(p);
    };

    void build(const std::vector<std::optional<int>> &p) {
        int n = p.size();
        logn = 1;
        while ((1 << logn) < n) logn++;

        parent.assign(logn, std::vector<std::optional<int>>(n, std::nullopt));
        for (int i = 0; i < n; i++) parent[0][i] = p[i];
        std::vector<std::vector<int>> tree(n);
        std::vector<int> root;
        for (int i = 0; i < n; i++) {
            if (parent[0][i].has_value())
                tree[parent[0][i].value()].push_back(i);
            else
                root.push_back(i);
        }

        depth.assign(n, -1);
        auto calc_depth = [&](int u, int d, auto &&f) -> void {
            depth[u] = d;
            for (auto v : tree[u]) {
                f(v, d + 1, f);
            }
            return;
        };

        for (int u : root) {
            calc_depth(u, 0, calc_depth);
        }

        for (int k = 1; k < logn; k++) {
            for (int u = 0; u < n; u++) {
                if (parent[k - 1][u].has_value())
                    parent[k][u] = parent[k - 1][parent[k - 1][u].value()];
            }
        }
    };

    std::optional<int> climb(int u, int d) {
        if (d > depth[u]) return std::nullopt;
        int cnt = 0;
        while (d > 0) {
            if (d & 1) u = parent[cnt][u].value();
            d >>= 1;
            cnt++;
        }
        return u;
    };

    // LowestCommonAncestor
    int lca(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        v = climb(v, depth[v] - depth[u]).value();

        if (u == v) return u;
        for (int k = logn - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u].value();
                v = parent[k][v].value();
            }
        }
        return parent[0][u].value();
    };

    inline int distance(int u, int v) {
        return depth[u] + depth[v] - depth[lca(u, v)] * 2;
    };
};

struct DoublingTreeBuilder {
    std::vector<std::vector<int>> g;
    DoublingTreeBuilder(int n) : g(n){};
    void add_edge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    };

    DoublingTree build(const std::vector<int> &root = {0}) {
        std::vector<std::optional<int>> parent(g.size(), std::nullopt);
        auto dfs = [&](int u, int p, auto &&f) -> void {
            for (auto v : g[u]) {
                if (v == p) continue;
                parent[v] = u;
                f(v, u, f);
            }
            return;
        };
        for (auto v : root) dfs(v, -1, dfs);
        return DoublingTree(parent.begin(), parent.end());
    };
};

#endif
