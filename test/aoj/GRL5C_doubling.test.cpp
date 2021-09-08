#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include <iostream>
#include <vector>

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

    i64 n;
    cin >> n;
    DoublingTreeBuilder builder(n);
    rep(i, n) {
        i64 k, c;
        cin >> k;
        rep(j, k) {
            cin >> c;
            builder.add_edge(i, c);
        }
    }

    auto t = builder.build({0});
    i64 q;
    cin >> q;
    rep(i, q) {
        i64 u, v;
        cin >> u >> v;

        cout << t.lca(u, v) << '\n';
    }

    return 0;
}