#ifndef AVL_SET_HPP
#define AVL_SET_HPP

#include <optional>

#include "../impl/avl_base.hpp"

template <class T>
struct AVLSetNode : public AVLBaseNode {
    AVLSetNode(const T &val) : val(val){};
    T val;
};

template <class T>
struct AVLSet : public AVLBase {
    using Node = AVLSetNode<T>;
    using Base = AVLBase;

    AVLSet &insert(const T &val) {
        Node *nv = new Node(val);
        auto [l, r] = Base::split(this->root, count_lower(val));
        this->root = Base::merge(nv, l, r);
        return *this;
    };
    AVLSet &erase(const T &val) {
        if (!contains(val)) return *this;
        auto [tmp, r] = Base::split(this->root, count_lower(val) + 1);
        auto [l, del] = Base::split_rightest_node(tmp);
        delete del;
        this->root = Base::merge(l, r);
        return *this;
    };

    std::optional<T> find_Kth(int k) {
        if (Base::size() <= k || k < 0) return std::nullopt;
        auto [tmp, r] = Base::split(this->root, k + 1);
        auto [l, mid] = Base::split_rightest_node(tmp);
        T ret = (Node *)(mid)->val;
        this->root = Base::merge((Node *)mid, (Node *)l, (Node *)r);
        return ret;
    };

    bool contains(const T &val) { return count(val) > 0; };
    int count(const T &x) {
        return Base::size() - count_upper(x) - count_lower(x);
    };
    int count_lower(const T &x) { return count_lower(x, this->root); };
    int count_lower(const T &x, Node *u) {
        if (u == nullptr) return 0;
        if (u->dat < x)
            return count_lower(x, u->ch[1]) + size(u->ch[0]) + 1;
        else
            return count_lower(x, u->ch[0]);
    };
    int count_upper(const T &x) { return count_upper(x, this->root); };
    int count_upper(const T &x, Node *u) {
        if (u == nullptr) return 0;
        if (x < u->dat)
            return count_upper(x, u->ch[0]) + size(u->ch[1]) + 1;
        else
            return count_upper(x, u->ch[1]);
    };
};

#endif