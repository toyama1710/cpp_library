#ifndef PERSISTENT_ARRAY_HPP
#define PERSISTENT_ARRAY_HPP

#include <algorithm>
#include <cstring>
#include <memory>

//===
// LIBRARY SECTION

// #include <memory>
// #include <cstring>
// #include <algorithm>
// K-ary tree
template <class T, int K = 2>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node *ch[K] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            std::memcpy(ch, np->ch, sizeof(Node *) * K);
        };
    };

    Node *root = nullptr;
    int arr_size = 0;

    PersistentArray() = default;
    PersistentArray(Node *root, int arr_size)
        : root(root), arr_size(arr_size){};
    PersistentArray(int size, const T &d = T()) : arr_size(size) {
        root = new Node();
        init(root, size, d);
    };
    Node *init(Node *np, int size, T d) {
        np->dat = d;

        if (size == 1) return np;
        for (int i = 0; i < std::min(K, size); i++) {
            np->ch[i] = init(new Node(), (size + K - 1) / K, d);
        }
        return np;
    };

    const T get(int idx) const {
        return get(idx, root);
    };
    const T get(int idx, Node *np) const {
        if (idx == 0) return np->dat;
        return get((idx - 1) / K, np->ch[idx % K]);
    };

    PersistentArray set(int idx, const T &val) {
        return {set(idx, val, root), arr_size};
    };
    Node *set(int idx, const T &val, Node *np) {
        if (idx == 0) {
            Node *node = new Node(np);
            node->dat = val;
            return node;
        } else {
            Node *node = new Node(np);
            node->ch[idx % K] = set((idx - 1) / K, val, np->ch[idx % K]);
            return node;
        }
    };

    void destructive_set(int idx, const T &val) {
        destructive_set(idx, val, root);
    };
    void destructive_set(int idx, const T &val, Node *np) {
        if (idx == 0)
            np->dat = val;
        else
            destructive_set((idx - 1) / K, val, np->ch[idx % K]);
    };

    int size() {
        return arr_size;
    };
    PersistentArray get_array() {
        return *this;
    };

    const T operator[](int idx) const {
        return get(idx, root);
    };
};
//===

#endif
