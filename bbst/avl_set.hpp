#ifndef AVL_SET
#define AVL_SET

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <optional>
#include <utility>
#include <vector>

// insert/erase base AVLtree
// multiset
template <class T>
struct AVLSet {
    struct Node {
        int sz, hi;
        T dat;
        Node *ch[2];
        Node(T dat) : sz(1), hi(1), dat(dat), ch{nullptr, nullptr} {};
    };

    Node *root;

    AVLSet(Node *r = nullptr) : root(r){};
    AVLSet(const AVLSet &x) : root(x.root){};
    AVLSet &operator=(const AVLSet &x) {
        root = x.root;
        return *this;
    };

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
        if (u->dat < nv->dat)
            u->ch[1] = insert(u->ch[1], nv);
        else
            u->ch[0] = insert(u->ch[0], nv);

        return balance(recalc(u));
    };

    void erase(const T &dat) { root = erase(root, dat); };
    Node *erase(Node *u, const T &dat) {
        if (u == nullptr) return nullptr;
        if (u->dat < dat) {
            u->ch[1] = erase(u->ch[1], dat);
        } else if (dat < u->dat) {
            u->ch[0] = erase(u->ch[0], dat);
        } else {
            Node *del = u;
            u = isolate_node(u);
            delete del;
        }
        return balance(recalc(u));
    };
    Node *isolate_node(Node *u) {
        if (u->ch[0] == nullptr || u->ch[1] == nullptr) {
            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];
            return ret;
        } else {
            Node *l = isolate_node(&u, u->ch[0]);
            u->ch[0] = l;
            return balance(recalc(u));
        }
    };
    Node *isolate_node(Node **dst, Node *v) {
        if (v->ch[1] != nullptr) {
            v->ch[1] = isolate_node(dst, v->ch[1]);
            return balance(recalc(v));
        } else {
            std::swap((*dst)->ch[0], v->ch[0]);
            std::swap((*dst)->ch[1], v->ch[1]);
            std::swap(*dst, v);
            return isolate_node(v);
        }
    };

    bool contains(T dat) {
        Node *u = root;
        while (u != nullptr) {
            if (dat < u->dat) {
                u = u->ch[0];
            } else if (u->dat < dat) {
                u = u->ch[1];
            } else {
                return true;
            }
        }
        return false;
    };

    std::optional<T> lower_bound(const T &x) { return lower_bound(root, x); };
    std::optional<T> lower_bound(Node *u, const T &x) {
        if (u == nullptr) return std::nullopt;
        if (u->dat < x) {
            return lower_bound(u->ch[1], x);
        } else {
            auto ret = lower_bound(u->ch[0], x);
            if (ret)
                return ret;
            else
                return u->dat;
        }
    };
    std::optional<T> upper_bound(const T &x) { return upper_bound(root, x); };
    std::optional<T> upper_bound(Node *u, const T &x) {
        if (u == nullptr) return std::nullopt;
        if (x < u->dat) {
            auto ret = upper_bound(u->ch[0], x);
            if (ret)
                return ret;
            else
                return u->dat;
        } else {
            return upper_bound(u->ch[1], x);
        }
    };

    // 0-indexed
    std::optional<T> find_Kth(int k) {
        if (size() <= k || k < 0)
            return std::nullopt;
        else
            return find_Kth(root, k)->dat;
    };
    Node *find_Kth(Node *u, int k) {
        if (size(u->ch[0]) == k)
            return u;
        else if (size(u->ch[0]) > k)
            return find_Kth(u->ch[0], k);
        else
            return find_Kth(u->ch[1], k - size(u->ch[0]) - 1);
    };

    int count(const T &x) { return size() - count_upper(x) - count_lower(x); };
    int count_lower(const T &x) { return count_lower(x, root); };
    int count_lower(const T &x, Node *u) {
        if (u == nullptr) return 0;
        if (u->dat < x)
            return count_lower(x, u->ch[1]) + size(u->ch[0]) + 1;
        else
            return count_lower(x, u->ch[0]);
    };
    int count_upper(const T &x) { return count_upper(x, root); };
    int count_upper(const T &x, Node *u) {
        if (u == nullptr) return 0;
        if (x < u->dat)
            return count_upper(x, u->ch[0]) + size(u->ch[1]) + 1;
        else
            return count_upper(x, u->ch[1]);
    };

    AVLSet merge_with(AVLSet r) {
        if (size() == 0) {
            root = r.root;
        } else if (r.size() > 0) {
            Node dummy = *root;
            root = merge(&dummy, root, r.root);
        }
        return *this;
    };
    Node *merge(Node *dummy, Node *l, Node *r) {
        if (abs(height(l) - height(r)) <= 2) {
            dummy->ch[0] = l;
            dummy->ch[1] = r;
            return isolate_node(dummy);
        } else if (height(l) > height(r)) {
            l->ch[1] = merge(dummy, l->ch[1], r);
            return balance(recalc(l));
        } else {
            r->ch[0] = merge(dummy, l, r->ch[0]);
            return balance(recalc(r));
        }
    };

    std::pair<AVLSet, AVLSet> split(int k) {
        assert(k >= 0 && k <= size());
        auto [l, r] = split(root, k);
        root = nullptr;
        return {AVLSet(l), AVLSet(r)};
    };
    std::pair<Node *, Node *> split(Node *u, int k) {
        int lsize = size(u->ch[0]);
        Node *l = u->ch[0];
        Node *r = u->ch[1];
        if (lsize == k) {
            u->ch[0] = u->ch[1] = nullptr;
            return {l, insert(r, recalc(u))};
        } else if (lsize + 1 == k) {
            u->ch[0] = u->ch[1] = nullptr;
            return {insert(l, recalc(u)), r};
        } else if (lsize > k) {
            auto [x, y] = split(u->ch[0], k);
            u->ch[0] = y;
            return {x, balance((recalc(u)))};
        } else {
            auto [x, y] = split(u->ch[1], k - size(u->ch[0]) - 1);
            u->ch[1] = x;
            return {balance(recalc(u)), y};
        }
    };

    std::vector<T> list() {
        std::vector<T> ret;
        ret.reserve(size());
        auto dfs = [&](Node *u, auto &&f) {
            if (u == nullptr) return;
            f(u->ch[0], f);
            ret.emplace_back(u->dat);
            f(u->ch[1], f);
        };
        dfs(root, dfs);
        return ret;
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
};

#endif