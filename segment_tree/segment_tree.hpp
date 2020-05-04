#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>
#include <functional>
#include <iterator>

//===
template<class Monoid, class OP = std::function<Monoid(Monoid, Monoid)>>
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    std::vector<Monoid> tree;
    const int size;
    const Monoid e; // neutral element
    const OP merge_monoid; // bin' operation

    SegmentTree (const Monoid &e, const OP &f, int nmemb):
        e(e), merge_monoid(f), size(nmemb)
    {
        tree.assign(size << 1, e);
    };

    template<class InputIterator>
    SegmentTree(const Monoid &e, const OP &f,
                InputIterator first, InputIterator last):
        e(e), merge_monoid(f), size(std::distance(first, last))
    {
        tree.assign(size << 1, e);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===

#endif
