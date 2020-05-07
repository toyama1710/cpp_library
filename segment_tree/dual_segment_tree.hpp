#ifndef DUAL_SEGMENT_TREE_HPP
#define DUAL_SEGMENT_TREE_HPP

#include <vector>

//===
template<class OperatorMonoid,
         class Merge = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> >
struct DualSegmentTree {
    int sz, height;
    const OperatorMonoid e;
    const Merge merge_operator;
    vector<OperatorMonoid> lazy;
 
    DualSegmentTree(OperatorMonoid e, const Merge &h):
        e(e), merge_operator(h) {};
    void init(int nmemb) {
        sz = nmemb;
        lazy.assign(sz << 1, e);

        height = -1;
        while (nmemb) nmemb >>= 1, height++;
    };
 
    inline void propagate(int k) {
        if (k >= sz || lazy[k] == e) return;
        lazy[(k << 1) | 0] = merge_operator(lazy[(k << 1) | 0], lazy[k]);
        lazy[(k << 1) | 1] = merge_operator(lazy[(k << 1) | 1], lazy[k]);
        lazy[k] = e;
    };
    void push_down(int k) {
        for (int i = height; i > 0; i--) {
            propagate(k >> i);
        }
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

#endif
