#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"
#include <iostream>
#include <tuple>
#include <queue>
#include "../../segment_tree/segment_tree2d.hpp"
using namespace std;
using llong = long long;

struct Monoid {
    using value_type = llong;
    static llong operation(llong a, llong b){return a + b;};
    static llong identity(){return 0ll;};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    llong H, W, T, Q;
    llong t, c, sy, sx, ty, tx;

    cin >> H >> W >> T >> Q;
    SegmentTree2D<Monoid> valid(H + 1, W + 1);
    SegmentTree2D<Monoid> invalid(H + 1, W + 1);
    queue<tuple<llong, llong, llong> > que;

    for (int i = 0; i < Q; i++) {
        cin >> t >> c >> sy >> sx;

        while (!que.empty() && get<0>(que.front()) + T <= t) {
            auto a = que.front();
            valid.update(get<1>(a), get<2>(a), 1);
            invalid.update(get<1>(a), get<2>(a), 0);
            que.pop();
        }

        switch(c) {
        case 0:
            invalid.update(sy, sx, 1);
            que.push(make_tuple(t, sy, sx));
            break;
        case 1:
            if (valid.at(sy, sx) == 1) {
                valid.update(sy, sx, 0);
            }
            break;
        case 2:
            cin >> ty >> tx;
            ty++, tx++;

            cout << valid.fold(sy, sx, ty, tx) << ' ';
            cout << invalid.fold(sy, sx, ty, tx) << '\n';
            break;
        }
    }

    return 0;
}
