#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>
#include <functional>
#include <iterator>

//===
template<class Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    std::vector<T> tree;

    SegmentTree() = default;
    SegmentTree(int n)
        :tree(size << 1, Monoid::identity()) {};

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last) {
        tree.assign(size << 1, Monoid::identity());
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    inline int size() {
        return tree.size() >> 1;
    };

    inline T operator[] (const int k) const {
        return tree[k + size];
    };

    void update(int k, T dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    T fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = Monoid::identity();
        Monoid rv = Monoid::identity();
        while (l < r) {
            if (l & 1) lv = Monoid::operation(lv, tree[l++]);
            if (r & 1) rv = Monoid::operation(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return Monoid::operation(lv, rv);
    };
};
//===

#endif
