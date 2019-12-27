#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//===
// memory: O(HW)
// time: O(logH * logW)
template<class T, class OP = function<T(T, T)> >
struct SegmentTree2D {
    const OP mergef;
    const size_t H, W;
    const T e;
    vector<vector<T> > tree;

    SegmentTree2D(size_t H, size_t W, const T &e, const OP &f):
        H(H), W(W), e(e), mergef(f)
    {
        tree.assign(H << 1, vector<T>(W << 1, e));
    };

    void update(int sy, int sx, T dat) {
        sy += H;
        sx += W;
        
        int ty, tx;
        tree[sy][sx] = dat;
        tx = sx;
        while (tx > 1) {
            tx >>= 1;
            tree[sy][tx] = mergef(tree[sy][(tx << 1)],
                                  tree[sy][(tx << 1) | 1]);
        }

        ty = sy;
        while (ty > 1) {
            ty >>= 1;
            tx = sx;
            tree[ty][tx] = mergef(tree[(ty << 1)][tx],
                                  tree[(ty << 1) | 1][tx]);
            while (tx > 1) {
                tx >>= 1;
                tree[ty][tx] = mergef(tree[(ty << 1)][tx],
                                      tree[(ty << 1) | 1][tx]);
            }
        }
    };

    T fold(int sy, int sx, int ty, int tx) {
        sy += H;
        ty += H;

        T ret = e;
        while (sy < ty) {
            if (sy & 1) ret = mergef(ret, fold_x(sy++, sx, tx));
            if (ty & 1) ret = mergef(fold_x(--ty, sx, tx), ret);

            sy >>= 1;
            ty >>= 1;
        }
        return ret;
    };
    T fold_x(int y, int l, int r) {
        l += W;
        r += W;

        T ret = e;
        while (l < r) {
            if (l & 1) ret = mergef(ret, tree[y][l++]);
            if (r & 1) ret = mergef(tree[y][--r], ret);

            l >>= 1;
            r >>= 1;
        }
        return ret;
    };

    T at(int sy, int sx) const {
        return tree[sy + H][sx + W];
    };
};
//===

using llong = long long;

int AOJ1068() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    llong r, c, q;
    llong gr;
    llong sy, sx, ty, tx;

    cin >> r >> c >> q;
    while (r != 0 && c != 0 && q != 0) {
        SegmentTree2D<llong> seg(r, c, 1ll << 60ll,
                                 [](auto l, auto r){return min(l, r);});
        
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

int main() {
    return AOJ1068();
}
