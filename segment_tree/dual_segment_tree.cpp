#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
using llong = long long;

//===
template<class OperatorMonoid,
         class Merge = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> >
struct DualSegmentTree {
    int sz;
    const OperatorMonoid e;
    const Merge merge_operator;
    vector<OperatorMonoid> lazy;
 
    DualSegmentTree(OperatorMonoid e, const Merge &h):
        e(e), merge_operator(h) {};
    void init(int nmemb) {
        sz = nmemb;
        lazy.assign(sz << 1, e);
    };
 
    void propagate(int k) {
        if (k >= sz) return;
        lazy[(k << 1) | 0] = merge_operator(lazy[(k << 1) | 0], lazy[k]);
        lazy[(k << 1) | 1] = merge_operator(lazy[(k << 1) | 1], lazy[k]);
        lazy[k] = e;
    };
    void push_down(int k) {
        if (k <= 0) return;
        push_down(k >> 1);
        propagate(k);
    };
 
    // [l, r)
    void update(int l, int r, OperatorMonoid op) {
        l += sz; r += sz;
        push_down(l);
        push_down(r - 1);
         
        while (l < r) {
            if (l & 1) lazy[l] = merge_operator(lazy[l], op), l++;
            if (r & 1) --r, lazy[r] = merge_operator(lazy[r], op);
 
            l >>= 1;
            r >>= 1;
        }
    };
 
    OperatorMonoid operator [] (int k) {
        k += sz;
        push_down(k);
        return lazy[k];
    };
};
//===

int AOJ_DSL_2_E() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    auto f = [](auto l, auto r){return l + r;};
    //DualSegmentTree<llong> dst(0, [](auto l, auto r){ return l + r; });
    DualSegmentTree<llong, decltype(f)> dst(0, f);
    llong n, q;
    llong com, s, t, x;

    cin >> n >> q;
    dst.init(n);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;

            s--;
            dst.update(s, t, x);
        }
        else if (com == 1) {
            cin >> x;

            x--;
            cout << dst[x] << '\n';
        }
    }

    return 0;
}

int main() {
    return AOJ_DSL_2_E();
}
