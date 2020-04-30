#ifndef PERSISTENT_SEGMENT_TREE_HPP
#define PERSISTENT_SEGMENT_TREE_HPP

#include <iterator>
#include <functional>
#include <vector>
#include <cstdint>
#include <cstddef>

//===
// LIBRARY SECTION
// #include <iterator>
// #include <functional>
// #include <vector>
// #include <cstdint>
// #include <cstddef>
template<class Monoid, class F = std::function<Monoid(Monoid, Monoid)>>
struct PersistentSegmentTree {
    using uint = size_t;
    
    struct Node {
        Monoid dat;
        Node *l = nullptr, *r = nullptr;

        Node (Monoid dat):dat(dat) {};
    };
    
    const Monoid e;
    const F f;
    const Node *root;
    const uint n;

    Node *merge_node(Node *lch, Node *rch) {
        Monoid l = (lch ? lch->dat : e);
        Monoid r = (rch ? rch->dat : e);
        Node *ret = new Node(f(l, r));
        ret->l = lch;
        ret->r = rch;

        return ret;
    };

    PersistentSegmentTree(Monoid e, F f, uint n, Node *r)
        :e(e), f(f), n(n), root(r) {};
    PersistentSegmentTree(Monoid e, F f, uint n)
        :e(e), f(f), n(n), root(alloc(0, n, std::vector<Monoid>(n, e))) {};
    template<class InputItr>
    PersistentSegmentTree(Monoid e, F f, InputItr first, InputItr last)
        :e(e), f(f), n(std::distance(first, last)), root(alloc(0, n, std::vector<Monoid>(first, last))) {};

    Node *alloc(uint nl, uint nr, const std::vector<Monoid> &v) {
        if (nr - nl <= 1) return new Node(v[nl]);
        else return merge_node(alloc(nl, (nl + nr) / 2, v),
                            alloc((nl + nr) / 2, nr, v));
    };

    const Monoid fold(uint l, uint r) const {
        return fold(l, r, 0, n, root);
    };
    const Monoid fold(uint ql, uint qr, uint nl, uint nr, Node *np) const {
        if (np == nullptr || qr <= nl || nr <= ql) return e;
        else if (ql <= nl && nr <= qr) return np->dat;
        else return f(fold(ql, qr, nl, (nl + nr) / 2, np->l), fold(ql, qr, (nl + nr) / 2, nr, np->r));
    };

    PersistentSegmentTree set(uint idx, Monoid d) {
        return PersistentSegmentTree(e, f, n, update(0, n, idx, d, root));
    };
    Node *update(uint nl, uint nr, uint idx, Monoid d, const Node *np) {
        if (idx < nl || nr <= idx) return np;
        else if (nr - nl == 1) return new Node(d);
        else return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l), update((nl + nr) / 2, nr, idx, d, np->r));
    };

    PersistentSegmentTree get_tree() {
        return *this;
    };

    const Monoid operator [] (uint idx) const {
        return fold(idx, idx + 1, 0, n, root);
    };
};
//===

#endif
