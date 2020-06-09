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
    explicit SegmentTree(int n)
        :tree(n << 1, Monoid::identity()) {};

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last) {
        tree.assign(distance(first, last) << 1, Monoid::identity());

        int i;
        i = size();
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }
        for (i = size() - 1; i > 0; i--) {
            tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    inline int size() {
        return tree.size() >> 1;
    };

    inline T operator[] (int k) {
        return tree[k + size()];
    };

    void update(int k, const T dat) {
        k += size();
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    T fold(int l, int r) {
        l += size(); //points leaf
        r += size();

        T lv = Monoid::identity();
        T rv = Monoid::identity();
        while (l < r) {
            if (l & 1) lv = Monoid::operation(lv, tree[l++]);
            if (r & 1) rv = Monoid::operation(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return Monoid::operation(lv, rv);
    };

    template<class F>
    inline int sub_tree_search(int i, T sum, F f) {
        while (i < size()) {
            T x = Monoid::operation(sum, tree[i << 1]);
            if (f(x)) {
                i = i << 1;
            }
            else {
                sum = x;
                i = (i << 1) | 1;
            }
        }
        return i - size();
    }

    template<class F>
    int search(int l, F f) {
        l += size();
        int r = size() * 2; // r = n;
        int tmpr = r;
        int shift = 0;

        T sum = Monoid::identity();
        while (l < r) {
            if (l & 1) {
                if (f(Monoid::operation(sum, tree[l]))) {
                    return sub_tree_search(l, sum, f);
                }
                sum = Monoid::operation(sum, tree[l]);
                l++;
            }
            l >>= 1;
            r >>= 1;
            shift++;
        }

        while (shift > 0) {
            shift--;
            r = tmpr >> shift;
            if (r & 1) {
                r--;
                if (f(Monoid::operation(sum, tree[r]))) {
                    return sub_tree_search(r, sum, f);
                }
                sum = Monoid::operation(sum, tree[r]);
            }
        }

        return -1;
    };
};
//===

#endif
