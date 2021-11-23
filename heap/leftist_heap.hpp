#ifndef LEFTIST_HEAP_HPP
#define LEFTIST_HEAP_HPP

#include <cassert>
#include <utility>

// min heap
// weight-biased leftist heap
template <class T>
struct LeftistHeap {
    struct Node {
        T val;
        int sz;
        Node *ch[2];
        Node(T &val) : val(val), sz(1), ch{nullptr, nullptr} {};
        static int size(Node *u) { return u == nullptr ? 0 : u->sz; };
        static Node *update(Node *u) {
            u->sz = size(u->ch[0]) + size(u->ch[1]) + 1;
            if (size(u->ch[0]) < size(u->ch[1])) std::swap(u->ch[0], u->ch[1]);
            return u;
        }
    };

    Node *root = nullptr;
    LeftistHeap() = default;

    Node *meld(Node *h1, Node *h2) {
        if (h1 == nullptr) {
            return h2;
        } else if (h2 == nullptr) {
            return h1;
        } else {
            if (h1->val > h2->val) std::swap(h1, h2);
            h1->ch[1] = meld(h1->ch[1], h2);
            return Node::update(h1);
        }
    };
    LeftistHeap &merge_with(LeftistHeap &h) {
        root = meld(root, h.root);
        h.root = nullptr;
        return *this;
    };

    LeftistHeap &push(T val) {
        root = meld(root, new Node(val));
        return *this;
    };
    T top() const {
        assert(root != nullptr);
        return root->val;
    };
    LeftistHeap &pop() {
        assert(root != nullptr);
        auto [l, r] = root->ch;
        delete root;
        root = meld(l, r);
        return *this;
    };
    int size() { return Node::size(root); };
    bool empty() { return size() == 0; };
};

#endif