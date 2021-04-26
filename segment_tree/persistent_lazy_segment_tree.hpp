#ifndef PERSISTENT_LAZY_SEGMENT_TREE_HPP
#define PERSISTENT_LAZY_SEGMENT_TREE_HPP

template<class MonoidwithOperator>
struct PersistentLazySegmentTree {
    using A = MonoidwithOperator;
    using M = typename A::value_structure;
    using O = typename A::operator_structure;
    using T = typename M::value_type;
    using E = typename O::value_type;
    template<class C>
    using Self = PersistentLazySegmentTree<C>;

    struct Node {
        T v;
        E op;
        Node *ch[2];
        Node () : v(M::identity()), op(O::identity()), ch({nullptr, nullptr}) {};
        Node (T v, E op, Node *left = nullptr, Node *right = nullptr): v(v), op(op), ch({left, right}) {};
        Node (const Node &) = default;
    };
    Node *root;
    int sz;

    Self<A>() = default;
    Self<A>(const Self<A> &) = default;

    Self<A>(int n, T init_v): sz(n), root(alloc(0, n, init_v)) {};
    explicit Self<A>(int n): sz(n), root(alloc(0, n, M::identity())) {};
    Self<A>(Node *u, int sz): root(u), sz(sz) {};
    Self<A> &operator = (const Self<A> &) = default;

    Node *alloc(int nl, int nr, T init_v) {
        if (nr - nl <= 1) return new Node(init_v, O::identity());
        Node *ret = new Node();
        ret.ch[0] = alloc(nl, (nl + nr) / 2, init_v);
        ret.ch[1] = alloc((nl + nr) / 2, nr, init_v);
        ret.v = M::operation(ret.ch[0]->v, ret.ch[1]->v);
        return ret;
    };

    void push_down(Node *u) {
        if (u->op == O::identity()) return;
        u.v = M::operation(u.v, u.op);

        if (u.ch[0] != nullptr) {
            u.ch[0] = new Node(u.ch[0]);
            u.ch[0]->op = O::operation(u.ch[0]->op, u->op);
        }
        if (u.ch[1] != nullptr) {
            u.ch[1] = new Node(u.ch[1]);
            u.ch[1]->op = O::operation(u.ch[1]->op, u->op);
        }

        u.op = O::identity();
    };

    T fold(int nl, int nr) {
        return fold(root, nl, nr, 0, sz);
    };
    T fold(Node *u, int nl, int nr, int ql, int qr) {
        push_down(u);
        if (ql <= nl && nr <= qr) return u->v;

        int mid = (nl + nr) / 2;
        if (mid >= qr) {
            return fold(u.ch[0], nl, mid, ql, qr);
        }
        else if (mid <= ql) {
            return fold(u.ch[1], mid, nr, ql, qr);
        }
        else {
            return M::operation(fold(u.ch[0], nl, mid, ql, qr),
                                fold(u.ch[1], mid, nr, ql, qr));
        }
    };

    Self<A> update(int l, int r, E op) {
        return Self<A>(update(root, op, 0, sz, l, r), sz);
    };
    Node* update(Node *u, E op, int nl, int nr, int ql, int qr) {
        push_down(u);
        Node *ret = new Node(u);
        if (ql <= nl && nr <= qr) {
            ret.op = op;
            return ret;
        }

        int mid = (nl + nr) / 2;
        if (mid >= qr) {
            ret.ch[0] = update(u.ch[0], op, nl, mid, ql, qr);
        }
        else if (mid <= ql) {
            ret.ch[1] = update(u.ch[1], op, mid, nr, ql, qr);
        }
        else {
            ret.ch[0] = update(u.ch[0], op, nl, mid, ql, qr);
            ret.ch[1] = update(u.ch[1], op, mid, nr, ql, qr);
        }
        return ret;
    };
};

#endif
