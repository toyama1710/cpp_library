#ifndef AVL_BASE_HPP
#define AVL_BASE_HPP

#include <algorithm>
#include <cassert>

struct AVLBaseNode {
    using Self = AVLBaseNode;
    int hi;
    int sz;
    Self *ch[2];

    AVLBaseNode() : hi(1), sz(1), ch{nullptr, nullptr} {};
    static int height(Self *u) {
        if (u == nullptr)
            return 0;
        else
            return u->hi;
    };
    static int size(Self *u) {
        if (u == nullptr)
            return 0;
        else
            return u->sz;
    };
    void recalc() {
        calc_sum();
        sz = size(ch[0]) + size(ch[1]) + 1;
        hi = std::max(height(ch[0]), height(ch[1])) + 1;
    };
    virtual void calc_sum(){};
    virtual void push_down(){};
};

struct AVLBase {
    using Node = AVLBaseNode;
    Node *root;

    explicit AVLBase(Node *root = nullptr) : root(root){};
    AVLBase(const AVLBase &x) : root(x.root){};
    AVLBase &operator=(const AVLBase &x) {
        root = x.root;
        return *this;
    };

    static int balance_factor(const Node *u) {
        return Node::height(u->ch[0]) - Node::height(u->ch[1]);
    };
    int size() { return Node::size(root); };
    template <int d>
    static Node *rotate(Node *u) {
        assert(u != nullptr && u->ch[d] != nullptr);
        Node *v = u->ch[d];
        u->push_down();
        v->push_down();
        u->ch[d] = v->ch[d ^ 1];
        v->ch[d ^ 1] = u;
        u->recalc();
        v->recalc();
        return v;
    };
    static Node *balance(Node *u) {
        if (u == nullptr) return nullptr;
        if (balance_factor(u) == 2) {
            if (balance_factor(u->ch[0]) == -1) u->ch[0] = rotate<1>(u->ch[0]);
            u = rotate<0>(u);
        } else if (balance_factor(u) == -2) {
            if (balance_factor(u->ch[1]) == 1) u->ch[1] = rotate<0>(u->ch[1]);
            u = rotate<1>(u);
        }
        return u;
    };
    static std::pair<void *, void *> split_rightest_node(Node *u) {
        u->push_down();
        if (u->ch[1] != nullptr) {
            auto [l, ret] = split_rightest_node(u->ch[1]);
            u->ch[1] = (Node *)l;
            u->recalc();
            return {balance(u), ret};
        } else {
            void *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];
            return {ret, u};
        }
    };

    AVLBase &append(AVLBase &r) {
        root = (Node *)merge(root, r.root);
        r.root = nullptr;
        return *this;
    };
    static void *merge(Node *l, Node *r) {
        if (l == nullptr) {
            return r;
        } else {
            auto [left, mid] = split_rightest_node(l);
            return merge((Node *)mid, (Node *)left, r);
        }
    }
    static void *merge(Node *mid, Node *l, Node *r) {
        l->push_down();
        r->push_down();
        if (abs(Node::height(l) - Node::height(r)) <= 2) {
            mid->ch[0] = l;
            mid->ch[1] = r;
            mid->recalc();
            return balance(mid);
        } else if (Node::height(l) > Node::height(r)) {
            l->ch[1] = (Node *)merge(mid, l->ch[1], r);
            l->recalc();
            return balance(l);
        } else {
            r->ch[0] = (Node *)merge(mid, l, r->ch[0]);
            r->recalc();
            return balance(r);
        }
    };

    // first: [0, k), second: [k, n)
    std::pair<AVLBase, AVLBase> split_at(int k) {
        assert(0 <= k && k <= size());
        auto [l, r] = split(root, k);
        root = nullptr;
        return {AVLBase((Node *)l), AVLBase((Node *)r)};
    };
    static std::pair<void *, void *> split(Node *u, int k) {
        if (u == nullptr) return {nullptr, nullptr};
        u->push_down();
        Node *l = u->ch[0];
        Node *r = u->ch[1];
        u->ch[0] = u->ch[1] = nullptr;
        u->recalc();
        int lsize = Node::size(l);
        if (lsize == k) {
            return {l, merge(u, nullptr, r)};
        } else if (k < lsize) {
            auto [x, y] = split(l, k);
            return {(Node *)x, merge(u, (Node *)y, r)};
        } else {
            auto [x, y] = split(r, k - lsize - 1);
            return {merge(u, l, (Node *)x), (Node *)y};
        }
    };
};

#endif