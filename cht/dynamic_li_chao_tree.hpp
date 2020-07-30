#ifndef DYNAMIC_LI_CHAO_TREE_H
#define DYNAMIC_LI_CHAO_TREE_H

#include <algorithm>
#include <limits>

template <class T, T lower, T upper>
struct DynamicLiChaoTree {

    struct Line {
        T a, b;
        T get(T x) {
            return a * x + b;
        };
        Line (T a, T b) : a(a), b(b) {};
    };

    struct Node {
        Line x;
        Node *l, *r;
        Node (const Node &u) : x(u.x), l(u.l), r(u.r) {};
        Node (const Line &x) : x(x), l(nullptr), r(nullptr) {};
    };

    Node *root;

    DynamicLiChaoTree() : root(nullptr) {};

    void add_line(T a, T b) {
        auto x = Line(a, b);
        root = update(root, x, lower, upper);
    };

    Node *update(Node *u, Line &x, T lx, T rx) {
        if (u == nullptr) return new Node(x);
        if (x.get(lx) <= u->x.get(lx) && x.get(rx) <= u->x.get(rx)) {
            u->x = x;
            return u;
        }

        // T mx = std::midpoint(lx, rx);
        T mx = (lx + rx) / 2;
        if (x.get(mx) < u->x.get(mx)) std::swap(x, u->x);
        if (x.get(lx) < u->x.get(lx)) u->l = update(u->l, x, lx, mx);
        else u->r = update(u->r, x, mx, rx);

        return u;
    };

    T get(T x) {
        return get(x, root, lower, upper);
    };
    T get(T x, Node *u, T lx, T rx) {
        if (u == nullptr) return std::numeric_limits<T>::max();

        T mx = (lx + rx) / 2;
        if (x < mx) return std::min(u->x.get(x), get(x, u->l, lx, mx));
        else return std::min(u->x.get(x), get(x, u->r, mx, rx));
    };
};

#endif
