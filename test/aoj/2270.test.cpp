#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2270"
#include <iostream>

#include "../../bbst/persistent_avl_set.hpp"
#include "../../tree/doubling_tree.hpp"

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) repeat(__VA_ARGS__)

#define ALL(X) begin(X), end(X)

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (auto &vs : x) cin >> vs;

    DoublingTreeBuilder buider(n);
    rep(i, n - 1) {
        i64 a, b;
        cin >> a >> b;
        --a, --b;
        buider.add_edge(a, b);
    }

    auto tr = buider.build();
    vector<PersistentAVLSet<int>> st(n);
    st[0] = st[0].insert(x[0]);
    auto dfs = [&](int u, auto &&f) {
        if (st[u].size() > 0) return;
        f(tr.climb(u, 1).value(), f);
        st[u] = st[tr.climb(u, 1).value()].insert(x[u]);
        return;
    };
    rep(i, 1, n) {
        //
        dfs(i, dfs);
    }

    auto count = [&](int u, int v, int r, int t) {
        return st[u].count_lower(t) + st[v].count_lower(t) -
               2 * st[r].count_lower(t) + (x[r] < t);
    };
    auto find = [&](int u, int v, int l) {
        int valid = 0;
        int invalid = 1 << 30;
        int lca = tr.lca(u, v);
        while (abs(valid - invalid) > 1) {
            i64 mid = (valid + invalid) / 2;
            if (count(u, v, lca, mid) < l)
                valid = mid;
            else
                invalid = mid;
        }
        return valid;
    };

    rep(_, q) {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;

        cout << find(u, v, l) << '\n';
    }

    return 0;
}