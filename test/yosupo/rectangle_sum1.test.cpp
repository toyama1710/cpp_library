#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
// header file section
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
#include <tuple>
#include <vector>

#include "../../segment_tree/persistent_segment_tree.hpp"
#include "../../util/coordinate_compression.hpp"

using namespace std;
using llong = long long;

struct Monoid {
    using value_type = llong;
    static llong operation(llong a, llong b) {
        return a + b;
    };
    static llong identity() {
        return 0;
    }
};

llong n, q;
vector<PersistentSegmentTree<Monoid>> v;
vector<tuple<llong, llong, llong>> p;
CoordinateCompressionBuilder<llong> x_axis_builder;
CoordinateCompressionBuilder<llong> y_axis_builder;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        llong x, y, w;
        cin >> x >> y >> w;
        p.push_back(tie(y, x, w));
        x_axis_builder.push(x);
        y_axis_builder.push(y);
    }

    sort(p.begin(), p.end());
    auto x_axis = x_axis_builder.build();
    auto y_axis = y_axis_builder.build();

    v.push_back(PersistentSegmentTree<Monoid>(x_axis.size()));

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
