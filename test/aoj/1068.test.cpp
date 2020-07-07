#define PROBLEM "judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"

#include <iostream>
#include "../../segment_tree/segment_tree2d.hpp"

using llong = long long;
using namespace std;

struct Monoid {
    using value_type = llong;
    using T = llong;

    inline static T operation(T a, T b) {
        return min(a, b);
    };
    inline static T identity() {
        return (1ll << 50);
    };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    llong r, c, q;
    llong gr;
    llong sy, sx, ty, tx;

    cin >> r >> c >> q;
    while (r != 0 && c != 0 && q != 0) {
        SegmentTree2D<Monoid> seg(r, c);
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> gr;
                seg.update(i, j, gr);
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> sy >> sx >> ty >> tx;

            cout << seg.fold(sy, sx, ty + 1,  tx + 1) << '\n';
        }

        /*
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << seg.at(i, j) << ' ';
            }
            cout << endl;
        }
        */
        
        cin >> r >> c >> q;
    }

    return 0;
}
