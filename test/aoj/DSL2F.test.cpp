#include <iostream>
#include "../../segment_tree/lazy_segment_tree.hpp"
using namespace std;
using llong = long long;

struct M {
    struct Monoid {
        using T = llong;
        using value_type = T;

        inline static T identity() {
            return (1ll << 31) - 1;
        };
        inline static T operation(T a, T b) {
            return min(a, b);
        };
    };
    struct Operator {
        using E = llong;
        using value_type = E;

        inline static E identity() {
            return (1ll << 31) - 1;
        };
        inline static E operation(E a, E b) {
            if (a == identity()) return b;
            else if (b == identity()) return a;
            else return b;
        };
    };

    using value_structure = Monoid;
    using operator_structure = Operator;
    using T = typename Monoid::T;
    using E = typename Operator::E;

    inline static T operation(T dat, E op) {
        if (op == operator_structure::identity()) return dat;
        else return op;
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    llong n, q;
    llong com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<M> seg(n);

    for (int i = 0; i < q; i++) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;

            seg.update(s, t + 1, x);
        }
        else if (com == 1) {
            cin >> s >> t;
            cout << seg.fold(s, t + 1) << '\n';
        }
    }

    return 0;
}
