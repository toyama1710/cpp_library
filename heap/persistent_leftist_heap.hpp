#ifndef PERSISTENT_LEFTIST_HEAP_HPP
#define PERSISTENT_LEFTIST_HEAP_HPP

#include <cassert>
#include <utility>

template <class T>
struct PersistentLeftistHeap {
    struct Node {
        T val;
        int sz;
        Node *ch[2];
        Node(const T &val) : val(val), sz(1), ch{nullptr, nullptr} {};
        Node(Node *ptr)
            : val(ptr->val), sz(ptr->sz), ch{ptr->ch[0], ptr->ch[1]} {};

        static int size(const Node *u) {
            return u == nullptr ? 0 : u->sz;
        };

        static Node *update(Node *u) {
            u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;
            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0], u->ch[1]);
            return u;
        }
    };

    Node *root;
    using Self = PersistentLeftistHeap;

    PersistentLeftistHeap() = default;
    PersistentLeftistHeap(Node *root) : root(root){};

    int size() const {
        return Node::size(root);
    };

    bool empty() const {
        return size() == 0;
    };

    Node *meld(Node *h1, Node *h2) const {
        if (h1 == nullptr) {
            return h2;
        } else if (h2 == nullptr) {
            return h1;
        } else {
            if (h1->val > h2->val) std::swap(h1, h2);
            auto v = new Node(h1);
            v->ch[1] = meld(v->ch[1], h2);
            return Node::update(v);
        }
    };

    Self merge_with(const Self h) const {
        return Self(root, h.root);
    };

    Self push(const T &v) const {
        return Self(meld(root, new Node(v)));
    };

    T peek() const {
        assert(!empty());
        return root->val;
    };

    Self pop() const {
        assert(!empty());
        return Self(meld(root->ch[0], root->ch[1]));
    };
};

#endif
