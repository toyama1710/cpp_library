#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343"
#include <iostream>
#include <vector>

#include "../../bbst/if/avl_set.hpp"

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

    i64 n, c;
    cin >> n >> c;

    using P = pair<i64, i64>;
    AVLSet<P> st;
    rep(i, n) st.insert(P(0, i));
    vector<i64> score(n);

    i64 com, t, m, p;
    rep(_, c) {
        cin >> com;
        if (com == 0) {
            cin >> t >> p;
            --t;
            st.erase(P(-score[t], t));
            score[t] += p;
            st.insert(P(-score[t], t));
        } else if (com == 1) {
            cin >> m;
            auto s = st.find_Kth(m - 1).value();
            cout << s.second + 1 << ' ' << -s.first << '\n';
        }
    }

    return 0;
}