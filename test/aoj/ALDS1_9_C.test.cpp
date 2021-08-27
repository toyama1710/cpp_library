#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <iostream>
#include <string>
#include <tuple>

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

    auto cmp = [](i64 lhs, i64 rhs) { return lhs > rhs; };
    AVLSet<i64, decltype(cmp)> gr(cmp);
    AVLSet<i64> le;

    string s;
    const int inf = 2'000'000'000;
    while (cin >> s, s != "end") {
        if (s == "insert") {
            i64 k;
            cin >> k;
            gr.insert(k);
            le.insert(k);
        } else {
            auto [x, y, z] =
                tuple(le.find_Kth(le.size() - 1), gr.lower_bound(inf),
                      gr.upper_bound(inf + 1));

            assert(x && y && z);
            assert(x.value() == y.value() && y.value() == z.value() &&
                   x.value() == z.value());

            cout << x.value() << '\n';

            le.erase(x.value());
            gr.erase(x.value());
        }
    }

    return 0;
}