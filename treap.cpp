#include <iostream>
#include <cstdint>
#include <random>
#include <functional>
using namespace std;

//===comparator
template<typename T,
         typename Equal = equal_to<T>,
         typename Less = less<T>,
         typename Greater = greater<T>>
struct Comparator {
    const Equal eq();
    const Less le();
    const Greater gr();

    int operator ()(const T &l, const T &r) {
        if (le(l, r)) return -1;
        if (eq(l, r)) return 0;
        if (gr(l, r)) return 1;
    }
};
//===

//===
template <typename T, typename Compare = Comparator<T>>
struct Treap {
    using uint = uint_fast32_t;
    using uint64 = uint_fast64_t;
    
    struct Node {
        T dat;
        uint64 p;

        Node *parent;
        Node *l, *r;

        Node(T dat, uint64 p):
            dat(dat), p(p), parent(nullptr), l(nullptr), r(nullptr) {}

    };
    
    Node *root = nullptr;
    const Compare cmp;
    mt19937 rnd;

    Treap(Compare &cmp = Compare()):
        cmp(cmp), rnd(mt19937(random_device()())) {}

    bool has_element(T x) {
        Node *w = root;

        while (w != nullptr) {
            int c = cmp(w->dat, x);
            if (c < 0) w = w->right;
            else if (c > 0) w = w->left;
            else return true;
        }
        return false;
    }

    Node *find_last_node(T x) {
        Node *w = root;
        Node *prev = nullptr;

        while (w != nullptr) {
            prev = w;
            int c = cmp(w->dat, x);
            if (c < 0) w = w->right;
            else if (c > 0) w = w->left;
            else return w;
        }
        return prev;
    }

    // suc:true, faile:false
    bool insert(T x) {
        Node *u = new Node(x, (uint64)rnd());
        Node *w = find_last_node(x);

        if (w == nullptr) {
            root = u;
        }
        else if(add_child(w, u)) {
            babble_up(u);
            return true;
        }

        delete u;
        return false;
    }
    bool erase(T x) {
        Node *u = find_last_node(x);
        Node *p = u->parent;

        if (u == nullptr || cmp(u->dat, x) != 0) return false;

        trickle_down(u);
        if (p == nullptr) {
            root = nullptr;
        }
        else {
            if (p->left == u) p->left = nullptr;
            else p->right = nullptr;
        }
        delete u;
        
        return true;
    }

    bool add_child(Node *p, Node *u) {
        int c = cmp(p->dat, u->dat);

        if (c < 0) this->right = u;
        else if (c > 0) this->left = u;
        else return false;
            
        u->parent = this;
        return true;
    }

    void babble_up(Node *u) {
        while (u->parent != nullptr && u->parent->p > u->p) {
            if (u->parent->right == u) rotate_left(u->parent);
            if (u->parent->left == u) rotate_right(u->parent);
        }
        
        if (u->parent == nullptr) root = u;
    }
    void trickle_down(Node *u) {
        while (u->left != nullptr || u->right != nullptr) {
            if (u->left != nullptr) rotate_right(u);
            else if (u->right != nullptr) rotate_left(u);
            else if (u->left->p < u->right->p) rotate_right(u);
            else rotate_left(u);

            if (root == u) root = u->parent;
        }
    }
    
    void rotate_left(Node *u) {
        Node *w = u->right;
        w->parent = u->parent;
        u->parent = w;
        
        u->right = w->left;
        if (u->right != nullptr) u->right->parent = u;
        w->left = u;   
        
        if (w->parent != nullptr) {
            if (w->parent->left == u) w->parent->left = w;
            else w->parent->right = w;
        }
        else {
            root = w;
        }
    }

    void rotate_right(Node *u) {
        Node *w = u->left;
        w->parent = u->parent;
        u->parent = w;

        u->left = w->right;
        if (u->left != nullptr) u->left->parent = u;
        w->right = u;

        if (w->parent != nullptr) {
            if (w->parent->left == u) w->parent->left = w;
            else w->parent->right = w;
        }
        else {
            root = w;
        }
    }
};
//===

int main() {

    return 0;
}
