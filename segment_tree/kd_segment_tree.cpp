#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <vector>
#include <initializer_list>
using namespace std;
using llong = long long;

//===
// #include <initializer_list>
// memory: O(A_1 * A_2 * ... A_k)
// time: O(log(A_1) * log(A_2) * ... log(A_k))
template<int K, class Monoid, class OP = function<Monoid(Monoid, Monoid)> >
struct KDSegmentTree {
    const OP merge_monoid;
    const Monoid e;
    int sz;
    vector<KDSegmentTree<K - 1, Monoid, OP> > dat;

    KDSegmentTree(const Monoid &e, const OP &f, initializer_list<int> w):
        merge_monoid(f), e(e)
    {
        init(w);
    };
    KDSegmentTree(const Monoid &e, const OP &f):
        merge_monoid(f), e(e) {};

    void init(initializer_list<int> w) {
        sz = list_at_(w, K - 1);
        dat.assign(sz << 1, KDSegmentTree<K - 1, Monoid, OP>(e, merge_monoid, w));
    };

    void update(initializer_list<int> a, Monoid x) {
        int idx = list_at_(a, K - 1) + sz;
        
        dat[idx].update(a, x);
        while (idx > 0) {
            idx >>= 1;
            dat[idx].update(a, x);
        }
    };

    Monoid fold(initializer_list<int> a, initializer_list<int> b) {
        int l = list_at_(a, K - 1) + sz;
        int r = list_at_(b, K - 1) + sz;

        Monoid v = e;
        while (l < r) {
            if (l & 1) v = merge_monoid(v, dat[l].fold(a, b)), l++;
            if (r & 1) --r, v = merge_monoid(dat[r].fold(a, b), v);

            l >>= 1;
            r >>= 1;
        }

        return v;
    };

    //===
    int list_at_(initializer_list<int> x, int k) {
        auto it = x.begin();
        while (k--) it++;
        return *it;
    };
};

template<class Monoid, class OP>
struct KDSegmentTree<1, Monoid, OP> {
    const int K = 1;
    const OP merge_monoid;
    const Monoid e;
    int sz;
    vector<Monoid> dat;
    
    KDSegmentTree(const Monoid &e, const OP &f, initializer_list<int> w):
        merge_monoid(f), e(e)
    {
        init(w);
    };
    KDSegmentTree(const Monoid &e, const OP &f):
        merge_monoid(f), e(e) {};

    void init(initializer_list<int> w) {
        sz = list_at_(w, K - 1);
        dat.assign(sz << 1, e);
    };

    void update(initializer_list<int> a, Monoid x) {
        int idx = list_at_(a, K - 1) + sz;
        dat[idx] = x;
        while (idx > 0) {
            idx >>= 1;
            dat[idx] = merge_monoid(dat[(idx << 1) | 0], dat[(idx << 1) | 1]);
        }
    };
    
    Monoid fold(initializer_list<int> a, initializer_list<int> b) {
        int l = list_at_(a, K - 1) + sz;
        int r = list_at_(b, K - 1) + sz;

        Monoid v = e;
        while (l < r) {
            if (l & 1) v = merge_monoid(v, dat[l]), l++;
            if (r & 1) --r, v = merge_monoid(dat[r], v);

            l >>= 1;
            r >>= 1;
        }

        return v;
    };

    //===
    int list_at_(initializer_list<int> w, int k) {
        auto it = w.begin();
        while (k--) it++;
        return *it;
    };
};
//===


int AOJ1068() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, c, q;
    llong gr;
    int sy, sx, ty, tx;

    cin >> r >> c >> q;
    while (r != 0 && c != 0 && q != 0) {
        KDSegmentTree<2, llong> seg(1ll << 60ll,
                                    [](auto l, auto r){return min(l, r);});
        seg.init({c, r});
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> gr;
                seg.update({j, i}, gr);
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> sy >> sx >> ty >> tx;

            cout << seg.fold({sx, sy}, {tx + 1,  ty + 1}) << '\n';
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
