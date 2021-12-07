#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_C"

#include <iostream>

#include "../../util/make_vector.hpp"

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
    auto room = make_vector({4, 3, 10}, 0);

    i64 n;
    cin >> n;
    rep(_, n) {
        i64 b, f, r, v;
        cin >> b >> f >> r >> v;
        --b, --f, --r;
        room[b][f][r] += v;
    }

    rep(i, 4) {
        rep(j, 3) {
            rep(k, 10) cout << ' ' << room[i][j][k];
            cout << endl;
        }
        if (i < 3) {
            rep(i, 20) cout << '#';
            cout << endl;
        }
    }

    return 0;
}