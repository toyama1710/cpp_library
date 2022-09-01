#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <iostream>

#include "../../segment_tree/dual_segment_tree.hpp"
using namespace std;
using llong = long long;

struct RUQ {
    using value_type = long long;
    using T = value_type;

    inline static T identity() {
        return (1ll << 31) - 1;
    };
    inline static T operation(T a, T b) {
        if (a == identity())
            return b;
        else if (b == identity())
            return a;
        else
            return b;
    };
};

int main() {
    llong n, q;
    llong com;
    llong s, t, x;
    llong idx;

    cin >> n >> q;
    DualSegmentTree<RUQ> seg(n);
    for (int i = 0; i < q; i++) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else if (com == 1) {
            cin >> idx;
            cout << seg[idx] << '\n';
        }
    }
};
