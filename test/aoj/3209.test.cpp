#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3209"
#include <iostream>

#include "../../math/modint.hpp"

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

    constexpr int mod = int(1e9) + 7;
    int n;

    while (cin >> n, n > 0) {
        ModInt<mod> a, b, c, d;
        cin >> a >> b >> c >> d;

        ModInt<mod> s1 = (a + c) * (c - a + 1) / 2;
        ModInt<mod> s2 = (b + d) * (1 + d - b) / 2;

        cout << s1 * s2 << '\n';
    }

    return 0;
}