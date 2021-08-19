#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

// header file section
#include <iostream>
#include <vector>
#include "../../segment_tree/dynamic_segment_tree.hpp"
#include "../../data_type/max_monoid.hpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, x, y;

int main() {
    cin >> n >> q;

    vector<llong> v(n, -1 * ((1ll << 31) - 1));
    DynamicSegmentTree<MinMonoid<llong>> seg;
    for (int i = 0; i < n; i++) {
        seg.update(i, v[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            seg.update(x, -y);
        }
        else {
            cout << -seg.fold(x, y + 1) << '\n';
        }
    }

    return 0;
};

