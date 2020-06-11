#ifndef SET_TREAP_HPP
#define SET_TREAP_HPP

#include <iostream>
#include <cstdint>
#include <random>
#include <functional>
#include <cassert>
#include <memory>
#include <utility>

//===
template <class T, class Compare = std::less<T>,
         class A = std::allocator<T>>
struct Treap {
    using uint = uint_fast32_t;
    using uint64 = uint_fast64_t;
    struct Node;
    using pn = std::pair<Node *, Node *>;
    
    struct Node {
        T dat;
        uint64 p;

        uint sz = 1;
        Node *lch;
        Node *rch;

        Node(T dat, uint64 p):
            dat(dat), p(p), lch(nullptr), rch(nullptr) {}
    };
    
    Node *root;
    const Compare cmp;
    std::mt19937 rnd;
    
    using Alloc = typename std::allocator_traits<A>::template rebind_alloc<Node>;
    using Traits = typename std::allocator_traits<Alloc>;
    Alloc alc;
    
    Treap(const Compare &cmp = Compare()):
        root(nullptr), cmp(cmp), rnd(std::mt19937(std::random_device()())), alc() {};
    
    void clear(Node *u) {
        if (u == nullptr) return;
        clear(u->lch);
        clear(u->rch);
        Traits::deallocate(alc, u, 1);
    };
    ~Treap() {
        clear(root);
    };

    int size() {
        return size(root);
    }
    int size(Node *u) {
        if (u == nullptr) return 0;
        else return u->sz;
    };
    void update(Node *u) {
        u->sz = size(u->lch) + size(u->rch) + 1;
    };
    Node *merge(Node *l, Node *r) {
        if (l == nullptr) return r;
        if (r == nullptr) return l;

        if (l->p > r->p) {
            l->rch = merge(l->rch, r);
            update(l);
            return l;
        }
        else {
            r->lch = merge(l, r->lch);
            update(r);
            return r;
        }
    };
    pn split(Node *t, T dat) { // first->dat <= dat, dat < second->dat
        if (t == nullptr) return std::make_pair(nullptr, nullptr);
        if (cmp(dat, t->dat)) {
            pn s = split(t->lch, dat);
            t->lch = s.second;
            update(t);
            return std::make_pair(s.first, t);
        }
        else {
            pn s = split(t->rch, dat);
            t->rch = s.first;
            update(t);
            return std::make_pair(t, s.second);
        }
    };
    
    bool find(T dat) {
        Node *u = root;
        while (u != nullptr && (cmp(u->dat, dat) || cmp(dat, u->dat))) {
            if (cmp(dat, u->dat)) u = u->lch;
            else u = u->rch;
        }
        return u != nullptr;
    };

    void insert(T dat) {
        Node *u = Traits::allocate(alc, 1);
        Traits::construct(alc, u, dat, (uint64)rnd());
        pn t = split(root, dat);
        root = merge(t.first, merge(u, t.second));
    };
    void erase(T dat) {
        assert(find(dat));
        pn t = split(root, dat);
        root = merge(erase_rightist(t.first), t.second);
    };
    Node *erase_rightist(Node *u) {
        if (u->rch == nullptr) {
            Node *ret = u->lch;
            Traits::deallocate(alc, u, 1);
            return ret;
        }
        u->rch = erase_rightist(u->rch);
        update(u);
        return u;
    }

    int order_of(T x) { // 0-index
        Node *u = root;
        int k = 0;
        while (u != nullptr && (cmp(u->dat, x) || cmp(x, u->dat))) {
            if (cmp(x, u->dat)) {
                u = u->lch;
            }
            else {
                k = k + size(u->lch) + 1;
                u = u->rch;
            }
        }

        if (u == nullptr) return -1;
        k += size(u->lch);
        return k;
    };
    T find_Kth_element(uint k) { // 0-index
        assert(k < size());
        assert(k >= 0);
        
        Node *u = root;
        int idx = size(u->lch);
        while (idx != k) {
            if (idx > k) {
                u = u->lch;
                idx -= size(u->rch) + 1;
            }
            else {
                u = u->rch;
                idx += size(u->lch) + 1;
            }
        }

        return u->dat;
    };
};
//===

#endif
