#ifndef PERSISTENT_SEGMENT_TREE_HPP
#define PERSISTENT_SEGMENT_TREE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <vector>

template <class Monoid>
struct PersistentSegmentTree {
    using uint = size_t;
    using T = typename Monoid::value_type;

    struct Node {
        T dat;
        Node *l = nullptr, *r = nullptr;

        Node(T dat) : dat(dat){};
    };

    Node *root;
    uint n;

    Node *merge_node(Node *lch, Node *rch) {
        T l = (lch ? lch->dat : Monoid::identity());
        T r = (rch ? rch->dat : Monoid::identity());
        Node *ret = new Node(Monoid::operation(l, r));
        ret->l = lch;
        ret->r = rch;

        return ret;
    };

    PersistentSegmentTree(const PersistentSegmentTree &) = default;
    PersistentSegmentTree &operator=(const PersistentSegmentTree &) = default;
    PersistentSegmentTree(uint n, Node *r) : root(r), n(n){};
    PersistentSegmentTree(uint n)
        : root(alloc(0, n, std::vector<T>(n, Monoid::identity()))), n(n){};
    template <class InputItr>
    PersistentSegmentTree(const InputItr first, const InputItr last)
        : n(std::distance(first, last)),
          root(alloc(0, n, std::vector<T>(first, last))){};

    Node *alloc(uint nl, uint nr, const std::vector<T> &v) {
        if (nr - nl <= 1)
            return new Node(v[nl]);
        else
            return merge_node(alloc(nl, (nl + nr) / 2, v),
                              alloc((nl + nr) / 2, nr, v));
    };

    const T fold(uint l, uint r) const {
        return fold(l, r, 0, n, root);
    };
    const T fold(uint ql, uint qr, uint nl, uint nr, const Node *np) const {
        if (np == nullptr || qr <= nl || nr <= ql)
            return Monoid::identity();
        else if (ql <= nl && nr <= qr)
            return np->dat;
        else
            return Monoid::operation(fold(ql, qr, nl, (nl + nr) / 2, np->l),
                                     fold(ql, qr, (nl + nr) / 2, nr, np->r));
    };

    PersistentSegmentTree update(uint idx, T d) {
        return set(idx, d);
    };
    PersistentSegmentTree set(uint idx, T d) {
        return PersistentSegmentTree(n, update(0, n, idx, d, root));
    };
    Node *update(uint nl, uint nr, uint idx, T d, Node *np) {
        if (idx < nl || nr <= idx)
            return np;
        else if (nr - nl == 1)
            return new Node(d);
        else
            return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l),
                              update((nl + nr) / 2, nr, idx, d, np->r));
    };

    PersistentSegmentTree get_tree() {
        return *this;
    };

    T operator[](uint idx) {
        return fold(idx, idx + 1, 0, n, root);
    };
};

#endif
