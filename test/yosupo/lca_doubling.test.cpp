#include <iostream>
#include <optional>
#include <vector>

#include "../../tree/doubling_tree.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, A, B) _rep3(Itr, A, B, 1)
#define _rep3(Itr, A, B, S) for (i64 Itr = A; Itr < B; Itr += S)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define ALL(X) begin(X), end(X)

using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, q;
    cin >> n >> q;
    vector<optional<i64>> p(n, nullopt);
    rep(i, 1, n) {
        i64 v;
        cin >> v;
        p[i] = v;
    }

    DoublingTree lca(ALL(p));

    rep(i, q) {
        i64 u, v;
        cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }

    return 0;
};
