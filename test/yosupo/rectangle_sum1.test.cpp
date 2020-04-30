#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
// header file section
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
#include <tuple>
#include "../../segment_tree/persistent_segment_tree.hpp"
#include "../../util/coordinate_compression.hpp"

using namespace std;
using llong = long long;

llong n, q;
vector<PersistentSegmentTree<llong>> v;
vector<tuple<llong, llong, llong>> p;
CoordinateCompression x_axis;
CoordinateCompression y_axis;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        llong x, y, w;
        cin >> x >> y >> w;
        p.push_back(tie(y, x, w));
        x_axis.add(x);
        y_axis.add(y);
    }

    sort(p.begin(), p.end());
    x_axis.build();
    y_axis.build();

    v.push_back(PersistentSegmentTree<llong>(0,
                [](auto l, auto r) {return l + r;},
                x_axis.size()));

    for (int i = 0; i < p.size(); i++) {
        llong x, y, w;
        tie(y, x, w) = p[i];
        x = x_axis.zip(x);
        y = y_axis.zip(y);

        if (v.size() <= y) {
            v.push_back(v[y - 1]);
        }

        v[y] = v[y].update(x, v[y][x] + w);
    }

    for (int i = 0; i < q; i++) {
        llong l, d, r, u;
        cin >> l >> d >> r >> u;

        l = x_axis.zip(l);
        r = x_axis.zip(r);
        d = y_axis.zip(d) - 1;
        u = y_axis.zip(u) - 1;

        if (d >= 0) 
            cout << v[u].fold(l, r) - v[d].fold(l, r) << '\n';
        else if (u >= 0)
            cout << v[u].fold(l, r) << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
};

