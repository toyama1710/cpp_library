#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../segment_tree/persistent_lazy_segment_tree.hpp"
#include <bits/stdc++.h>

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) repeat(__VA_ARGS__)

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

struct M {
    struct Monoid {
        using T = uint;
        using value_type = T;
        inline static T identity() { return (1ll << 31) - 1; };
        inline static T operation(T a, T b) { return min(a, b); };
    };
    struct Operator {
        using E = uint;
        using value_type = E;
        inline static E identity() { return (1ll << 31) - 1; };
        inline static E operation(E a, E b) {
            if (b == identity())
                return a;
            else
                return b;
        };
    };

    using value_structure = Monoid;
    using operator_structure = Operator;
    using T = typename Monoid::T;
    using E = typename Operator::E;

    inline static T operation(T dat, E op) {
        if (op == operator_structure::identity())
            return dat;
        else
            return op;
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<PersistentLazySegmentTree<M>> v(q + 1);

    v[0] = PersistentLazySegmentTree<M>(n, (1ll << 31) - 1);
    queue<pair<int, pair<int, int>>> que;

    rep(i, 1, q + 1) {
        v[i] = v[i - 1];

        i64 ty;
        i64 s, t, x;
        cin >> ty;

        if (ty == 0) {
            cin >> s >> t >> x;
            v[i] = v[i].update(s, t + 1, x);
        } else {
            cin >> s >> t;
            que.push({i, {s, t + 1}});
        }
        // v[i].dump();
    }

    while (!que.empty()) {
        auto a = que.front();
        que.pop();
        i64 idx = a.first;
        i64 s = a.second.first;
        i64 t = a.second.second;
        cout << v[idx].fold(s, t) << endl;
        // v[idx].dump();
    }

    return 0;
}
