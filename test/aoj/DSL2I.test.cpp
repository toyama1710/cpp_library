#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"
#include <iostream>
#include <utility>

#include "../../segment_tree/lazy_segment_tree.hpp"
using namespace std;
using llong = long long;

struct Monoid {
    using T = pair<llong, llong>;
    using value_type = pair<llong, llong>;
    inline static T identity() {
        return {0ll, 0ll};
    };
    inline static T operation(T &a, T &b) {
        return {a.first + b.first, a.second + b.second};
    };
};
struct Operator {
    using E = llong;
    using value_type = llong;
    inline static E identity() {
        return -1024;
    };
    inline static E operation(E &a, E &b) {
        if (b == identity())
            return a;
        else
            return b;
    };
};
struct A {
    using value_structure = Monoid;
    using operator_structure = Operator;
    using T = typename value_structure::T;
    using E = typename operator_structure::E;
    inline static T operation(T &a, E &b) {
        if (b == operator_structure::identity()) return a;
        return {b * a.second, a.second};
    };
};

llong n, q;
llong com, s, t, x;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    LazySegmentTree<A> seg(n);

    for (int i = 0; i < n; i++) seg.set(i, {0ll, 1ll});

    while (q--) {
        cin >> com;
        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else {
            cin >> s >> t;
            cout << seg.fold(s, t + 1).first << '\n';
        }
    }
}