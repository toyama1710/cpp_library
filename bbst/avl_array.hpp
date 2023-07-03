#ifndef AVL_ARRAY_HPP
#define AVL_ARRAY_HPP

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

template <class MonoidwithOperator>
struct AVLArray {
    using A = MonoidwithOperator;
    using M = typename A::value_structure;
    using T = typename M::value_type;
    using O = typename A::operator_structure;
    using E = typename O::value_type;

    struct Node {
        T val;
        T sum;
        E op;
        T rev_sum;
        bool rev_flag;
        int hi;
        int sz;
        Node *ch[2];

        Node(const T &val = M::identity(), const E &op = O::identity())
            : val(val),
              sum(val),
              op(op),
              rev_sum(val),
              rev_flag(false),
              hi(1),
              sz(1),
              ch{nullptr, nullptr} {};
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

    int size() {
        return size(root);
    };

    static int size(const Node *u) {
        if (u == nullptr)
            return 0;
        else
            return u->sz;
    };

    static T sum(const Node *u) {
        if (u == nullptr) {
            return M::identity();
        } else if (u->rev_flag) {
            return A::operation(u->rev_sum, u->op);
        } else {
            return A::operation(u->sum, u->op);
        }
    };

    static T rev_sum(const Node *u) {
        if (u == nullptr) {
            return M::identity();
        } else if (u->rev_flag) {
            return A::operation(u->sum, u->op);
        } else {
            return A::operation(u->rev_sum, u->op);
        }
    };

    static Node *push_down(Node *u) {
        eval_lazy(u);
        eval_rev(u);
        return u;
    };

    static void eval_rev(Node *u) {
        if (u->rev_flag) {
            std::swap(u->ch[0], u->ch[1]);
            std::swap(u->sum, u->rev_sum);
            u->rev_flag = false;
            if (u->ch[0]) u->ch[0]->rev_flag ^= 1;
            if (u->ch[1]) u->ch[1]->rev_flag ^= 1;
        }
    };

    static void eval_lazy(Node *u) {
        u->val = A::operation(u->val, u->op);
        u->sum = A::operation(u->sum, u->op);
        u->rev_sum = A::operation(u->rev_sum, u->op);
        if (u->ch[0]) u->ch[0]->op = O::operation(u->ch[0]->op, u->op);
        if (u->ch[1]) u->ch[1]->op = O::operation(u->ch[1]->op, u->op);
        u->op = O::identity();
    };

    static Node *calc_sum(Node *u) {
        u->sum =
            M::operation(M::operation(sum(u->ch[0]), u->val), sum(u->ch[1]));
        u->rev_sum = M::operation(M::operation(rev_sum(u->ch[1]), u->val),
                                  rev_sum(u->ch[0]));
        return u;
    };

    static Node *recalc(Node *u) {
        // assert(u->op == O::identity());
        u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;
        u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;
        return calc_sum(u);
    };

    template <int d>
    static Node *rotate(Node *u) {
        assert(u != nullptr && u->ch[d] != nullptr);
        Node *v = push_down(u->ch[d]);
        u->ch[d] = v->ch[d ^ 1];
        v->ch[d ^ 1] = u;
        recalc(u);
        recalc(v);
        return v;
    };

    static Node *balance(Node *u) {
        if (u == nullptr) return nullptr;
        push_down(u);
        if (balance_factor(u) == 2) {
            if (balance_factor(push_down(u->ch[0])) == -1)
                u->ch[0] = rotate<1>(u->ch[0]);
            u = rotate<0>(u);
        } else if (balance_factor(u) == -2) {
            if (balance_factor(push_down(u->ch[1])) == 1)
                u->ch[1] = rotate<0>(u->ch[1]);
            u = rotate<1>(u);
        }
        return u;
    };

    static std::pair<Node *, Node *> split_rightest_node(Node *u) {
        push_down(u);
        if (u->ch[1] != nullptr) {
            auto [l, ret] = split_rightest_node(u->ch[1]);
            u->ch[1] = l;
            return {balance(recalc(u)), ret};
        } else {
            Node *ret = u->ch[0];
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
    };

    static Node *merge(Node *mid, Node *l, Node *r) {
        if (abs(height(l) - height(r)) <= 1) {
            mid->ch[0] = l;
            mid->ch[1] = r;
            return recalc(mid);
        } else if (height(l) > height(r)) {
            push_down(l);
            l->ch[1] = merge(mid, l->ch[1], r);
            return balance(recalc(l));
        } else {
            push_down(r);
            r->ch[0] = merge(mid, l, r->ch[0]);
            return balance(recalc(r));
        }
    };

    // first: [0, k), second: [k, n)
    std::pair<AVLArray, AVLArray> split_at(int k) {
        assert(0 <= k && k <= size());
        auto [l, r] = split(root, k);
        root = nullptr;
        return {AVLArray(l), AVLArray(r)};
    };

    static std::pair<Node *, Node *> split(Node *u, int k) {
        if (u == nullptr) return {nullptr, nullptr};
        push_down(u);
        Node *l = u->ch[0];
        Node *r = u->ch[1];
        u->ch[0] = u->ch[1] = nullptr;

        int lsize = size(l);
        if (lsize == k) {
            return {l, merge(u, nullptr, r)};
        } else if (k < lsize) {
            auto [x, y] = split(l, k);
            return {x, merge(u, y, r)};
        } else {
            auto [x, y] = split(r, k - lsize - 1);
            return {merge(u, l, x), y};
        }
    };

    // sum [l, r)
    T fold(int l, int r) {
        if (r <= l) return M::identity();
        auto [tmp, right] = split(root, r);
        auto [left, mid] = split(tmp, l);
        T ret = sum(mid);
        root = merge(merge(left, mid), right);
        return ret;
    };

    T fold_rev(int l, int r) {
        if (r <= l) return M::identity();
        reverse(l, r);
        T ret = fold(l, r);
        reverse(l, r);
        return ret;
    };

    AVLArray &reverse(int l, int r) {
        if (r <= l) return *this;
        auto [tmp, right] = split(root, r);
        auto [left, mid] = split(tmp, l);
        mid->rev_flag ^= 1;
        root = merge(merge(left, mid), right);
        return *this;
    };

    AVLArray &insert_at(int k, const T &dat) {
        assert(0 <= k && k <= size());
        Node *nv = new Node(dat);
        auto [l, r] = split(root, k);
        root = merge(nv, l, r);
        return *this;
    };

    AVLArray &set(int k, const T &dat) {
        return update(k, dat);
    };

    AVLArray &update(int k, const T &dat) {
        assert(0 <= k && k < size());
        auto [tmp, r] = split(root, k + 1);
        auto [l, mid] = split_rightest_node(tmp);
        mid->val = dat;
        root = merge(mid, l, r);
        return *this;
    };

    AVLArray &update(int l, int r, const E &op) {
        if (r <= l) return *this;
        auto [tmp, right] = split(root, r);
        auto [left, mid] = split(tmp, l);
        mid->op = O::operation(mid->op, op);
        root = merge(merge(left, mid), right);
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

    std::vector<T> list() {
        std::vector<T> ret;
        ret.reserve(size());
        auto dfs = [&](auto &&f, Node *u) {
            f(f, u->ch[0]);
            ret.push_back(u->dat);
            f(f, u->ch[1]);
        };
        dfs(dfs, root);
        return ret;
    };

    const T operator[](int k) {
        return at(root, k);
    };

    const T at(Node *u, int k) {
        assert(0 <= k && k < size(u));
        push_down(u);
        if (size(u->ch[0]) == k)
            return u->val;
        else if (k < size(u->ch[0]))
            return at(u->ch[0], k);
        else
            return at(u->ch[1], k - size(u->ch[0]) - 1);
    };
};

#endif
