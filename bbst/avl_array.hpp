#ifndef AVL_ARRAY_HPP
#define AVL_ARRAY_HPP

#include <algorithm>
#include <cassert>
#include <optional>
#include <utility>

template <class Monoid>
struct AVLArray {
    using M = Monoid;
    using T = typename Monoid::value_type;
    struct Node {
        T val;
        T sum;
        int hi;
        int sz;
        Node *ch[2];

        Node(const T &val = M::identity())
            : val(val), sum(val), hi(1), sz(1), ch{nullptr, nullptr} {};
    };

    Node *root;

    explicit AVLArray(Node *root = nullptr) : root(root){};
    AVLArray(const AVLArray &x) : root(x.root){};
    AVLArray &operator=(const AVLArray &x) {
        root = x.root;
        return *this;
    };

    static int height(const Node *u) {
        if (u == nullptr)
            return 0;
        else
            return u->hi;
    };
    static int balance_factor(const Node *u) {
        return height(u->ch[0]) - height(u->ch[1]);
    };
    int size() { return size(root); };
    static int size(const Node *u) {
        if (u == nullptr)
            return 0;
        else
            return u->sz;
    };
    static T sum(const Node *u) {
        if (u == nullptr)
            return M::identity();
        else
            return u->sum;
    };
    static Node *recalc(Node *u) {
        u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;
        u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;
        u->sum =
            M::operation(M::operation(sum(u->ch[0]), u->val), sum(u->ch[1]));
        return u;
    };
    template <int d>
    static Node *rotate(Node *u) {
        assert(u != nullptr && u->ch[d] != nullptr);
        Node *v = u->ch[d];
        u->ch[d] = v->ch[d ^ 1];
        v->ch[d ^ 1] = u;
        recalc(u);
        recalc(v);
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
    static std::pair<Node *, Node *> split_rightest_node(Node *u) {
        if (u->ch[1] != nullptr) {
            auto [l, ret] = split_rightest_node(u->ch[1]);
            u->ch[1] = l;
            return {balance(recalc(u)), ret};
        } else {
            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];
            return {ret, u};
        }
    };

    AVLArray &append(AVLArray &r) {
        root = merge(root, r.root);
        r.root = nullptr;
        return *this;
    };
    static Node *merge(Node *l, Node *r) {
        if (l == nullptr) {
            return r;
        } else {
            auto [left, mid] = split_rightest_node(l);
            return merge(mid, left, r);
        }
    }
    static Node *merge(Node *mid, Node *l, Node *r) {
        if (abs(height(l) - height(r)) <= 2) {
            mid->ch[0] = l;
            mid->ch[1] = r;
            return balance(recalc(mid));
        } else if (height(l) > height(r)) {
            l->ch[1] = merge(mid, l->ch[1], r);
            return balance(recalc(l));
        } else {
            r->ch[0] = merge(mid, l, r->ch[0]);
            return balance(recalc(r));
        }
    };

    // first: [0, k), second: [k, n)
    std::pair<AVLArray, AVLArray> split_at(int k) {
        assert(0 <= k && k <= size());
        auto [l, r] = split();
        root = nullptr;
        return {AVLArray(l), AVLArray(r)};
    };
    static std::pair<Node *, Node *> split(Node *u, int k) {
        if (u == nullptr) return {nullptr, nullptr};
        Node *l = u->ch[0];
        Node *r = u->ch[1];
        u->ch[0] = u->ch[1] = nullptr;
        int lsize = size(l);
        if (lsize == k) {
            return {l, merge(recalc(u), nullptr, r)};
        } else if (k < lsize) {
            auto [x, y] = split(l, k);
            return {x, merge(recalc(u), y, r)};
        } else {
            auto [x, y] = split(r, k - lsize - 1);
            return {merge(recalc(u), l, x), y};
        }
    };

    // sum [l, r)
    T fold(int l, int r) {
        auto [tmp, right] = split(root, r);
        auto [left, mid] = split(tmp, l);
        T ret = sum(mid);
        root = merge(merge(left, mid), right);
        return ret;
    };

    AVLArray &insert_at(int k, const T &dat) {
        assert(0 <= k && k <= size());
        Node *nv = new Node(dat);
        auto [l, r] = split(root, k);
        root = merge(nv, l, r);
        return *this;
    };
    AVLArray &update_at(int k, const T &dat) {
        assert(0 <= k && k < size());
        auto [tmp, r] = split(root, k + 1);
        auto [l, mid] = split_rightest_node(tmp);
        mid->val = dat;
        root = merge(recalc(mid), l, r);
        return *this;
    };
    AVLArray &erase_at(int k) {
        assert(0 <= k && k < size());
        auto [tmp, r] = split(root, k + 1);
        auto [l, mid] = split_rightest_node(tmp);
        delete mid;
        root = merge(l, r);
        return *this;
    };

    AVLArray &rotate(int l, int mid, int r) {
        auto [tmp1, right] = split(root, r);
        auto [tmp2, m2] = split(tmp1, mid);
        auto [left, m1] = split(tmp2, l);
        root = merge(left, merge(m2, merge(m1, right)));
        return *this;
    };

    const T operator[](int k) { return at(root, k); };
    const T at(Node *u, int k) {
        assert(0 <= k && k < size(u));
        if (size(u->ch[0]) == k)
            return u->val;
        else if (k < size(u->ch[0]))
            return at(u->ch[0], k);
        else
            return at(u->ch[1], k - size(u->ch[0]) - 1);
    };
};

#endif