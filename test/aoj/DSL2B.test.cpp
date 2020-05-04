// header file section
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
using llong = long long;
using namespace std;

llong n, q;
llong com, x, y;

int main() {
    cin >> n >> q;
    SegmentTree<llong> seg(0, [](auto l, auto r){return l + r;}, n);
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            seg.update(x - 1, y);
        }
        else {
            cout << seg.fold(x - 1, y) << '\n';
        }
    }

    return 0;
};

