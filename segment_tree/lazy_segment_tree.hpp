#ifndef LAZY_SEGMENT_TREE_HPP
#define LAZY_SEGMENT_TREE_HPP

#include <vector>
#include <cstdint>

//===
template<class MonoidwithOperator>
struct LazySegmentTree {
    using M = MonoidwithOperator;
    using V = typename M::value_structure;
    using T = typename V::value_type;
    using O = typename M::operator_structure;
    using E = typename O::value_type;

    // mergeMonoid V::operation
    // applyOperator M::operation
    // mergeOperator O::operation

    struct Node {
        T dat;
        E lazy;
        Node (T dat, E lazy): dat(dat), lazy(lazy) {};
    };

    std::vector<Node> tree;

    LazySegmentTree() = default;
    explicit LazySegmentTree(uint32_t n):
        tree(n * 2 + 2, Node(V::identity(), O::identity())) {};

    int size() {
        return tree.size() >> 1;
    };
    
    void propagation(uint32_t k) {
        const uint32_t l = (k << 1) | 0;
        const uint32_t r = (k << 1) | 1;
        tree[l].lazy = O::operation(tree[l].lazy, tree[k].lazy);
        tree[r].lazy = O::operation(tree[r].lazy, tree[k].lazy);
        tree[l].dat = M::operation(tree[l].dat, tree[k].lazy);
        tree[r].dat = M::operation(tree[r].dat, tree[k].lazy);
        tree[k].lazy = O::identity();
    };
    void push_down(uint32_t k) {
        for (int i = 31; i > 0; i--) propagation(k >> i);
    };
    void recalc(uint32_t k) {
        while (k > 1) {
            k >>= 1;
            tree[k].dat = V::operation(tree[(k << 1) | 0].dat,
                                       tree[(k << 1) | 1].dat);
        }
    };
    
    // [l, r) += op
    void update(uint32_t l, uint32_t r, E op) {
        l += size();
        r += size();
        uint32_t tmpl = l;
        uint32_t tmpr = r;
        push_down(l);
        push_down(r - 1);

        while (l < r) {
            if (l & 1) {
                tree[l].lazy = O::operation(tree[l].lazy, op);
                tree[l].dat = M::operation(tree[l].dat, op);
                l++;
            }
            if (r & 1) {
                --r;
                tree[r].lazy = O::operation(tree[r].lazy, op);
                tree[r].dat = M::operation(tree[r].dat, op);
            }
            l >>= 1;
            r >>= 1;
        }

        recalc(tmpl);
        recalc(tmpr - 1);
    };

    // foldl[l, r)
    T fold(uint32_t l, uint32_t r) {
        l += size();
        r += size();
        push_down(l);
        push_down(r - 1);
        recalc(l);
        recalc(r - 1);

        T lv = V::identity();
        T rv = V::identity();

        while (l < r) {
            if (l & 1) lv = V::operation(lv, tree[l].dat), l++;
            if (r & 1) --r, rv = V::operation(tree[r].dat, rv);

            l >>= 1;
            r >>= 1;
        }

        return V::operation(lv, rv);
    };

    T operator [](const uint32_t &k) {
        push_down(k + size());
        return tree[k + size()].dat;
    };

    void dump() {
        int s = 1;
        for (int w = 1; w <= size() * 2; w *= 2) {
            for (int i = s; i < s + w; i++) {
                std::cout << i << ':';
                std::cout << tree[i].dat << " / " << tree[i].lazy << ' ';
            }
            std::cout << std::endl;
            s += w;
        }
    };
};
//===

#endif
