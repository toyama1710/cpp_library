#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D"
#include <iostream>

#include "../../bbst/persistent_avl_set.hpp"

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

struct Com {
    i64 com, x, l, r;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    i64 q;
    cin >> q;
    vector<PersistentAVLSet<i64>> st(q);
    vector<Com> query(q);

    for (auto &vs : query) {
        cin >> vs.com;
        if (vs.com == 3)
            cin >> vs.l >> vs.r;
        else
            cin >> vs.x;
    }

    rep(i, q) {
        if (i > 0) st[i] = st[i - 1];

        if (query[i].com == 0) {
            st[i] = st[i].insert(query[i].x);
        } else if (query[i].com == 2) {
            i64 x = query[i].x;
            while (st[i].count(x) > 0) st[i] = st[i].erase(x);
        }
    }

    rep(i, q) {
        if (query[i].com == 0) {
            cout << st[i].size() << '\n';
        } else if (query[i].com == 1) {
            cout << st[i].count(query[i].x) << '\n';
        } else if (query[i].com == 3) {
            i64 l = query[i].l;
            i64 r = query[i].r;
            auto y = st[i].lower_bound(l);
            while (y.has_value() && y.value() <= r) {
                i64 cnt = st[i].count(y.value());
                rep(i, cnt) cout << y.value() << '\n';
                y = st[i].upper_bound(y.value());
            }
        }
    }

    return 0;
}
