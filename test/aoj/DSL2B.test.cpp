// header file section
#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../../data_type/sum_monoid.hpp"
#include "../../segment_tree/segment_tree.hpp"
using llong = long long;
using namespace std;

llong n, q;
llong com, x, y;

int main() {
    cin >> n >> q;
    SegmentTree<SumMonoid<llong>> seg(n);
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            seg.update(x - 1, seg[x - 1] + y);
        } else {
            cout << seg.fold(x - 1, y) << '\n';
        }
    }

    return 0;
};
