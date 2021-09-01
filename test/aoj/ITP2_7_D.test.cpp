#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_7_D"
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

    i64 q;
    cin >> q;
    AVLSet<i64> st;

    i64 com, x, l, r;
    rep(_, q) {
        cin >> com;

        switch (com) {
            case 0: {
                cin >> x;
                st.insert(x);
                cout << st.size() << '\n';
                break;
            }
            case 1: {
                cin >> x;
                cout << st.count(x) << '\n';
                break;
            }
            case 2: {
                cin >> x;
                auto [low, tmp] = st.split(st.count_lower(x));
                auto [del, upp] = tmp.split(tmp.count(x));
                st.merge_with(low);
                st.merge_with(upp);
                break;
            }
            case 3: {
                cin >> l >> r;
                auto [low, tmp] = st.split(st.count_lower(l));
                auto [t, upp] = tmp.split(tmp.count_lower(r) + tmp.count(r));

                auto v = t.list();
                for (auto vs : v) {
                    cout << vs << '\n';
                }
                st.merge_with(low).merge_with(t).merge_with(upp);
            }
        }
    }

    return 0;
}
