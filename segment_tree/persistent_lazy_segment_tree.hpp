#ifndef PERSISTENT_LAZY_SEGMENT_TREE_HPP
#define PERSISTENT_LAZY_SEGMENT_TREE_HPP

#include <iostream>
template <class MonoidwithOperator>
struct PersistentLazySegmentTree {
    using A = MonoidwithOperator;
    using M = typename A::value_structure;
    using O = typename A::operator_structure;
    using T = typename M::value_type;
    using E = typename O::value_type;

    struct Node {
        T v;
        E op;
        Node *left, *right;
        Node()
            : v(M::identity()),
              op(O::identity()),
              left(nullptr),
              right(nullptr){};
        Node(T v, E op, Node *left = nullptr, Node *right = nullptr)
            : v(v), op(op), left(left), right(right){};
        Node(const Node &) = default;
    };

    Node *root;
    int sz;

    PersistentLazySegmentTree() = default;
    PersistentLazySegmentTree(const PersistentLazySegmentTree &) = default;
    explicit PersistentLazySegmentTree(int n)
        : root(alloc(0, n, M::identity())), sz(n){};
    PersistentLazySegmentTree(int n, T init_v)
        : root(alloc(0, n, init_v)), sz(n){};
    PersistentLazySegmentTree(Node *u, int sz) : root(u), sz(sz){};
    PersistentLazySegmentTree &operator=(const PersistentLazySegmentTree &) =
        default;

    Node *alloc(int nl, int nr, T init_v) {
        if (nr - nl <= 1) return new Node(init_v, O::identity());
        Node *ret = new Node();
        ret->left = alloc(nl, (nl + nr) / 2, init_v);
        ret->right = alloc((nl + nr) / 2, nr, init_v);
        ret->v = M::operation(ret->left->v, ret->right->v);
        return ret;
    };

    void push_down(Node *u) {
        if (u->op == O::identity()) return;
        u->v = A::operation(u->v, u->op);

        if (u->left != nullptr) {
            u->left = new Node(*u->left);
            u->left->op = O::operation(u->left->op, u->op);
        }
        if (u->right != nullptr) {
            u->right = new Node(*u->right);
            u->right->op = O::operation(u->right->op, u->op);
        }

        u->op = O::identity();
    };

    T fold(int l, int r) {
        if (r <= l) return M::identity();
        return fold(root, O::identity(), 0, sz, l, r);
    };
    T fold(Node *u, E op, int nl, int nr, int ql, int qr) {
        op = O::operation(u->op, op);
        if (ql <= nl && nr <= qr) return A::operation(u->v, op);

        int mid = (nl + nr) / 2;
        if (qr <= mid) {
            return fold(u->left, op, nl, mid, ql, qr);
        } else if (mid <= ql) {
            return fold(u->right, op, mid, nr, ql, qr);
        } else {
            return M::operation(fold(u->left, op, nl, mid, ql, qr),
                                fold(u->right, op, mid, nr, ql, qr));
        }
    };

    PersistentLazySegmentTree update(int l, int r, E op) {
        if (r <= l) return PersistentLazySegmentTree(*this);
        return PersistentLazySegmentTree(update(root, op, 0, sz, l, r), sz);
    };
    Node *update(Node *u, E op, int nl, int nr, int ql, int qr) {
        Node *ret = new Node(*u);
        if (ql <= nl && nr <= qr) {
            ret->op = O::operation(ret->op, op);
            return ret;
        }

        push_down(ret);
        int mid = (nl + nr) / 2;
        if (qr <= mid) {
            ret->left = update(ret->left, op, nl, mid, ql, qr);
        } else if (mid <= ql) {
            ret->right = update(ret->right, op, mid, nr, ql, qr);
        } else {
            ret->left = update(ret->left, op, nl, mid, ql, qr);
            ret->right = update(ret->right, op, mid, nr, ql, qr);
        }
        ret->v = M::operation(A::operation(ret->left->v, ret->left->op),
                              A::operation(ret->right->v, ret->right->op));
        return ret;
    };

    void dump() {
        dump(root, 0);
    };
    void dump(Node *u, int d) {
        if (u == nullptr) return;
        dump(u->right, d + 1);
        for (int i = 0; i < d; i++) std::cout << "\t\t";
        std::cout << "(" << u->v << ", " << u->op << ")" << std::endl;
        dump(u->left, d + 1);
    };
};

#endif
