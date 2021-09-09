#ifndef PERSISTENT_AVL_SET_HPP
#define PERSISTENT_AVL_SET_HPP

#include "avl_set.hpp"

// insert/erase base AVLtree
// multiset
// merge,split is not implemented
template <class T>
struct PersistentAVLSet : public AVLSet<T> {
    using Set = AVLSet<T>;
    using Node = typename AVLSet<T>::Node;
    PersistentAVLSet(Node *root = nullptr) : Set(root){};

    PersistentAVLSet insert(const T &dat) {
        Node *nv = new Node(dat);
        return PersistentAVLSet(insert(this->root, nv));
    };
    Node *insert(Node *u, Node *nv) {
        if (u == nullptr) return nv;
        u = new Node(u);
        if (u->dat < nv->dat)
            u->ch[1] = insert(u->ch[1], nv);
        else
            u->ch[0] = insert(u->ch[0], nv);

        return Set::balance(Set::recalc(u));
    };

    PersistentAVLSet erase(const T &dat) {
        return PersistentAVLSet(erase(this->root, dat));
    };
    Node *erase(Node *u, const T &dat) {
        if (u == nullptr) return nullptr;
        if (u->dat < dat) {
            u = new Node(u);
            u->ch[1] = erase(u->ch[1], dat);
        } else if (dat < u->dat) {
            u = new Node(u);
            u->ch[0] = erase(u->ch[0], dat);
        } else {
            u = isolate_node(u);
        }
        return Set::balance(Set::recalc(u));
    };
    Node *isolate_node(Node *u) {
        if (u->ch[0] == nullptr || u->ch[1] == nullptr) {
            Node *ret = u->ch[0] != nullptr ? u->ch[0] : u->ch[1];
            return new Node(ret);
        } else {
            auto [l, nv] = Set::split_rightest_node(u->ch[0]);
            nv = new Node(nv);
            nv->ch[0] = l;
            nv->ch[1] = u->ch[1];
            return Set::balance(Set::recalc(nv));
        }
    };
    std::pair<Node *, Node *> split_rightest_node(Node *v) {
        if (v->ch[1] != nullptr) {
            v = new Node(v);
            auto [l, ret] = split_rightest_node(v->ch[1]);
            v->ch[1] = l;
            return {Set::balance(Set::recalc(v)), ret};
        } else {
            return {Set::isolate_node(v), v};
        }
    };
};

#endif