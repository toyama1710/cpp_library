#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <iostream>

#include "../../segment_tree/dual_segment_tree.hpp"
using namespace std;
using llong = long long;

struct RAQ {
    using value_type = long long;
    using T = value_type;

    inline static T identity() {
        return 0;
    };
    inline static T operation(T a, T b) {
        return a + b;
    };
};

int main() {
    llong n, q;
    llong com;
    llong s, t, x;
    llong idx;

    cin >> n >> q;
    DualSegmentTree<RAQ> seg(n);
    for (int i = 0; i < q; i++) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            s--;
            seg.update(s, t, x);
        } else if (com == 1) {
            cin >> idx;
            idx--;
            cout << seg[idx] << '\n';
        }
    }
};
