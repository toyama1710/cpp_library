#ifndef AVL_SET
#define AVL_SET

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <optional>
#include <utility>

// insert/erase base AVLtree
// multiset
template <class T, class Compare = std::less<T>>
struct AVLSet {
    struct Node {
        int sz, hi;
        T dat;
        Node *ch[2];
        Node(T dat) : sz(1), hi(1), dat(dat), ch{nullptr, nullptr} {};
    };

    Node *root;
    const Compare cmp;

    AVLSet(const Compare &cmp = Compare()) : root(nullptr), cmp(cmp){};
    AVLSet(Node *r, Compare &cmp) : root(r), cmp(cmp){};
    AVLSet(const AVLSet &) = default;

    int size(Node *u) {
        if (u != nullptr)
            return u->sz;
        else
            return 0;
    };
    int size() { return size(root); };

    int height(Node *u) {
        if (u != nullptr)
            return u->hi;
        else
            return 0;
    };

    template <int d>  // 0: left, 1: right
    Node *rotate(Node *u) {
        assert(u != nullptr && u->ch[d] != nullptr);
        Node *v = u->ch[d];
        u->ch[d] = v->ch[d ^ 1];
        v->ch[d ^ 1] = u;

        recalc(u);
        recalc(v);
        return v;
    };
    int balance_factor(Node *u) {
        if (u == nullptr) return 0;
        return height(u->ch[0]) - height(u->ch[1]);
    };
    Node *balance(Node *u) {
        if (u == nullptr) return nullptr;
        assert(-2 <= balance_factor(u) && balance_factor(u) <= 2);
        if (balance_factor(u) == 2) {
            if (balance_factor(u->ch[0]) == -1) u->ch[0] = rotate<1>(u->ch[0]);
            u = rotate<0>(u);
        } else if (balance_factor(u) == -2) {
            if (balance_factor(u->ch[1]) == 1) u->ch[1] = rotate<0>(u->ch[1]);
            u = rotate<1>(u);
        }
        return u;
    };
    Node *recalc(Node *u) {
        if (u == nullptr) return nullptr;
        u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;
        u->hi = std::max(height(u->ch[0]), height(u->ch[1])) + 1;
        return u;
    };

    void insert(T dat) {
        Node *u = new Node(dat);
        root = insert(root, u);
    };
    Node *insert(Node *u, Node *nv) {
        if (u == nullptr) return nv;
        if (cmp(u->dat, nv->dat))
            u->ch[1] = insert(u->ch[1], nv);
        else
            u->ch[0] = insert(u->ch[0], nv);

        return balance(recalc(u));
    };

    void erase(T dat) { root = erase(root, dat); };
    Node *erase(Node *u, const T &dat) {
        if (u == nullptr) return nullptr;
        if (cmp(u->dat, dat)) {
            u->ch[1] = erase(u->ch[1], dat);
        } else if (cmp(dat, u->dat)) {
            u->ch[0] = erase(u->ch[0], dat);
        } else {
            u = erase_node(u);
        }
        return balance(recalc(u));
    };
    Node *erase_node(Node *u) {
        if (u->ch[0] == nullptr || u->ch[1] == nullptr) {
            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];
            delete u;
            return ret;
        } else {
            auto dfs = [&](auto &&f, Node *v) -> Node * {
                if (v->ch[1] != nullptr) {
                    v->ch[1] = f(f, v->ch[1]);
                    return balance(recalc(v));
                } else {
                    std::swap(u->dat, v->dat);
                    return erase_node(v);
                }
            };
            u->ch[0] = dfs(dfs, u->ch[0]);
            return balance(recalc(u));
        }
    };

    bool contains(T dat) {
        Node *u = root;
        while (u != nullptr) {
            if (cmp(dat, u->dat)) {
                u = u->ch[0];
            } else if (cmp(u->dat, dat)) {
                u = u->ch[1];
            } else {
                return true;
            }
        }
        return false;
    };

    void dump() {
        auto f = [](auto &&f, int d, Node *u) -> void {
            if (u == nullptr) return;
            f(f, d + 1, u->ch[1]);
            for (int i = 0; i < d; i++) {
                std::cout << "      ";
            }
            std::cout << "(" << u->dat << ", " << u->sz << ", " << u->hi << ")"
                      << std::endl;
            f(f, d + 1, u->ch[0]);
        };
        f(f, 0, root);
    };

    /*
    std::optional<T> lower_bound(T x){};
    std::optional<T> upper_bound(T x){};

    T find_Kth(int k);
    int count(T x) { return size() - count_upper(x) - count_lower(x); };
    int count_lower(T x);
    int count_upper(T x);
    */
};

#endif