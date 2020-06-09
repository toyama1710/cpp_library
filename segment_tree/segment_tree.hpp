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
    int bsearch(int l, int r, T s, F f) {
        l += size();
        r += size();
        std::vector<int> left, right;
        std::vector<int> q_idx;
        while (l < r) {
            if (l & 1) left.push_back(l++);
            if (r & 1) right.push_back(--r);
            l >>= 1;
            r >>= 1;
        }
        std::swap(q_idx, left);
        for (auto itr = right.rbegin(); itr != right.rend(); itr++) q_idx.push_back(*itr);

        T sum = Monoid::identity();
        for (auto v:q_idx) {
            if (f(Monoid::operation(sum, tree[v]))) {
                int i = v;
                while (i < size()) {
                    if (f(Monoid::operation(sum, tree[i << 1]))) {
                        i = i << 1;
                    }
                    else {
                        sum = Monoid::operation(sum, tree[i << 1]);
                        i = (i << 1) | 1;
                    }
                }
                return i - size();
            }
            else {
                sum = Monoid::operation(sum, tree[v]);
            }
        }
        return -1;
    };
};
//===

#endif
