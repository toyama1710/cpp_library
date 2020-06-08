#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include <iostream>
#include <algorithm>
#include "../../segment_tree/lazy_segment_tree.hpp"
using namespace std;
using llong = long long;

struct Monoid {
    using T = llong;
    using value_type = T;
    inline static T identity() {
        return 1ll << 60ll;
    };
    inline static T operation(const T a, const T b) {
        return min(a, b);
    };:
};

struct Operator {
    using T = llong;
    using value_type = T;
    inline static T identity() {
        return 0;
    };
    inline static T operation(const T a, const T b) {
        return a + b;
    };
};

template<class Monoid, class Op>
struct MO {
    using value_structure = Monoid;
    using operator_structure = Op;
    using T = typename Monoid::value_type;
    using E = typename Op::value_type;
    inline static T operation(T a, E b) {
        return a + b;
    };
};

llong n, q;
llong com, s, t, x;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    LazySegmentTree<MO<Monoid, Operator>> seg(n);
    for (int i = 0; i < n; i++) seg.set(i, 0);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else {
            cin >> s >> t;
            cout << seg.fold(s, t + 1) << '\n';
        }
    }
};