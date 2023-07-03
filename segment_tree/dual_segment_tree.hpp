#ifndef DUAL_SEGMENT_TREE_HPP
#define DUAL_SEGMENT_TREE_HPP

#include <cstdint>
#include <vector>

//===
template <class Monoid>
struct DualSegmentTree {
    using T = typename Monoid::value_type;
    std::vector<T> lazy;

    DualSegmentTree() = default;
    explicit DualSegmentTree(uint32_t n) : lazy(n << 1, Monoid::identity()){};

    inline int size() {
        return (int)(lazy.size() >> 1);
    };

    inline void propagate(uint32_t k) {
        if (k >= size()) return;
        lazy[(k << 1) | 0] = Monoid::operation(lazy[(k << 1) | 0], lazy[k]);
        lazy[(k << 1) | 1] = Monoid::operation(lazy[(k << 1) | 1], lazy[k]);
        lazy[k] = Monoid::identity();
    };

    inline void push_down(uint32_t k) {
        for (uint32_t i = 31; i > 0; i--) propagate(k >> i);
    };

    // [l, r)
    void update(uint32_t l, uint32_t r, T op) {
        l += size();
        r += size();
        push_down(l);
        push_down(r - 1);

        while (l < r) {
            if (l & 1) lazy[l] = Monoid::operation(lazy[l], op), l++;
            if (r & 1) --r, lazy[r] = Monoid::operation(lazy[r], op);

            l >>= 1;
            r >>= 1;
        }
    };

    T get(uint32_t k) {
        k += size();
        push_down(k);
        return lazy[k];
    };

    T operator[](uint32_t k) {
        return get(k);
    };
};
//===

#endif
