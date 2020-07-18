#ifndef PERSISTENT_ARRAY_HPP
#define PERSISTENT_ARRAY_HPP

#include <memory>
#include <cstring>
#include <algorithm>

//===
// LIBRARY SECTION

// #include <memory>
// #include <cstring>
// #include <algorithm>
// binary tree
template<class T>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[2] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            ch[0] = np->ch[0];
            ch[1] = np->ch[1];
        };
    };

    Node *root = nullptr;
    int arr_size = 0;

    PersistentArray() = default;
    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()) {
        arr_size = 1;
        while (arr_size < size) arr_size *= 2;
        root = new Node();
        init(root, arr_size, d);
    };
    Node *init(Node *np, int size, T d) {
        if (size == 1) {
            np->dat = d;
            return np;
        }
        np->ch[0] = init(new Node(), size / 2, d);
        np->ch[1] = init(new Node(), size / 2, d);
        return np;
    };

    const T get(int idx) const {
        return get(idx, 0, arr_size, root);
    };
    const T get(int idx, int l, int r, Node *np) const {
        if (r - l <= 1) return np->dat;

        if (idx < (r - l) / 2) return get(idx, l, (l + r) / 2, np->ch[0]);
        else return get(idx, (l + r) / 2, r, np->ch[1]);
    };
    
    PersistentArray set(int idx, const T &val) {
        return {set(idx, int l, int r, val, root), arr_size};
    };
    Node *set(int idx, int l, int r, const T &val, Node *np) {
        if (r - l == 1) {
            Node *node = new Node(np);
            node->dat = val;
            return node;
        }
        else {
            Node *node = new Node(np);

            if (idx < (l + r) / 2) node->ch[0] = set(idx, l, (l + r) / 2, np->ch[0]);
            else node->ch[1] = set(idx, (l + r) / 2, r, np->ch[1]);

            return node;
        }
    };

    int size() {
        return arr_size;
    };
    PersistentArray get_array() {
        return *this;
    };
    
    const T operator [] (int idx) const {
        return get(idx);
    };
};
//===

#endif
