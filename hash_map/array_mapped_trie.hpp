#ifndef ARRAY_MAPPED_TRIE_HPP
#define ARRAY_MAPPED_TRIE_HPP

#include <cstdint>

template <class T, int key_width = 32, int chunk_width = 4>
struct ArrayMappedTrie {
    using u64 = uint64_t;
    static constexpr u64 mask = (1 << chunk_width) - 1;

    union Node {
        Node *link[1 << chunk_width];
        T dat;
        Node() : link{} {};
    };

    Node *root;
    const T id;
    ArrayMappedTrie(T id = T()) : root(new Node()), id(id){};

    Node *get_node(u64 idx) {
        Node *u = root;
        for (int i = 0; i < (key_width + chunk_width - 1) / chunk_width; i++) {
            if (!u->link[idx & mask]) u->link[idx & mask] = new Node();
            u = u->link[idx & mask];
            idx >>= chunk_width;
        }
        return u;
    };

    bool find(u64 idx) {
        Node *u = root;
        u64 i = 0;
        while (i < (key_width + chunk_width - 1) / chunk_width && !u) {
            u = u->link[idx & mask];
            idx >>= chunk_width;
        }
        return u != nullptr;
    };

    T &operator[](u64 idx) {
        if (find(idx)) {
            return get_node(idx)->dat;
        } else {
            return get_node(idx)->dat = id;
        }
    };
};

#endif
