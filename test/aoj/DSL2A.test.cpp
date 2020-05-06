// header file section
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include "../../segment_tree/segment_tree.hpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, x, y;

struct SumMonoid {
    using value_type = llong;
    inline static llong identity() {
        return 0ll;
    };

    inline static llong operation(llong a, llong b) {
        return a + b;
    };
};

int main() {
    cin >> n >> q;
    SegmentTree<SumMonoid> seg(n);

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;
        --x;

        if (com == 0) {
            seg.update(x, seg[x] + y);
        }
        else {
            cout << seg.fold(x, y) << '\n';
        }
    }

    return 0;
};

