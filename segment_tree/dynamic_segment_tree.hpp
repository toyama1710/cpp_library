#ifndef DYNAMIC_SEGMENT_TREE_HPP
#define DYNAMIC_SEGMENT_TREE_HPP

template <class Monoid>
struct DynamicSegmentTree {
    using T = typename Monoid::value_type;
    using llong = long long;

    struct Node {
        T v;
        Node *left, *right;
        Node(T v) : v(v), left(nullptr), right(nullptr){};
    };

    Node *root = nullptr;
    llong L = 0, R = 0;

    DynamicSegmentTree() = default;

    inline void eval(Node &u) {
        T lv = Monoid::identity(), rv = Monoid::identity();
        if (u.left) lv = u.left->v;
        if (u.right) rv = u.right->v;
        u.v = Monoid::operation(lv, rv);
    };

    inline void expand(llong i) {
        if (L == R) {
            R++;
            while (i >= R) R += R - L;
            while (i < L) L -= R - L;
            root = new Node(Monoid::identity());
        } else {
            Node *tmp;
            while (i >= R) {
                R += R - L;
                tmp = new Node(root->v);
                tmp->left = root;
                root = tmp;
            }
            while (i < L) {
                L -= R - L;
                tmp = new Node(root->v);
                tmp->right = root;
                root = tmp;
            }
        }
    };

    inline void update(llong i, T v) {
        if (i < L || R <= i) expand(i);
        update(root, L, R, i, v);
    };

    void update(Node *node, llong nl, llong nr, llong k, T v) {
        if (nr - nl <= 1) {
            node->v = v;
            return;
        }

        llong mid = (nl + nr) / 2;
        if (k < mid) {
            if (!node->left) node->left = new Node(Monoid::identity());
            update(node->left, nl, (nl + nr) / 2, k, v);
        } else {
            if (!node->right) node->right = new Node(Monoid::identity());
            update(node->right, (nl + nr) / 2, nr, k, v);
        }

        eval(*node);
        return;
    }

    // [l, r)
    inline T fold(llong l, llong r) {
        if (l < L) expand(l);
        if (r > R) expand(r);
        return fold(root, L, R, l, r);
    };
    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {
        if (ql <= nl && nr <= qr) return node->v;

        T lv = Monoid::identity(), rv = Monoid::identity();
        llong mid = (nl + nr) / 2;
        if (node->left && ql < mid && nl < qr)
            lv = fold(node->left, nl, mid, ql, qr);
        if (node->right && ql < nr && mid < qr)
            rv = fold(node->right, mid, nr, ql, qr);

        return Monoid::operation(lv, rv);
    };

    T operator[](const llong k) {
        return fold(k, k + 1);
    };
};

#endif