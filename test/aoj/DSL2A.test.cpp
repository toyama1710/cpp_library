// header file section
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja"

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

int main() {
    cin >> n >> q;

    SegmentTree<llong> seg((1ll << 31) - 1, [](auto l, auto r){return min(l, r);}, n);

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            seg.update(x, y);
        }
        else {
            cout << seg.fold(x, y + 1) << '\n';
        }
    }

    return 0;
};

