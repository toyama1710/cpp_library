#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <iostream>

#include "../../bbst/avl_set.hpp"

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

    using P = pair<i64, i64>;
    auto cmp = [](P lhs, P rhs) -> bool { return lhs.first < rhs.first; };
    AVLSet<P, decltype(cmp)> st(cmp);

    i64 q;
    cin >> q;

    rep(_, q) {
        i64 com, k, v;

        cin >> com;

        if (com == 0) {
            cin >> k >> v;
            st.erase(P(k, 0));
            st.insert(P(k, v));
        } else if (com == 1) {
            cin >> k;
            if (st.contains(P(k, 0))) {
                cout << st.find_Kth(st.count_lower(P(k, 0))).value().second
                     << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}