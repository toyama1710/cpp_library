#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0407"

#include <algorithm>
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

    i64 n;
    cin >> n;
    auto v = make_vector({(size_t)n}, 0ll);
    // auto v = make_vector({n}, 0ll);  // warning
    for (auto &vs : v) cin >> vs;

    i64 ans = 1ll << 60;
    rep(t, 2000 + 1) {
        i64 tmp = 0;
        rep(i, n) tmp = max(tmp, abs(t - v[i]));
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}