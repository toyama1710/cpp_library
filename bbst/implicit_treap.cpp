#include <iostream>
#include <random>
#include <cstdint>
#include <functional>
using namespace std;

//===
struct ImplicitTreap {
    using uint = uint_fast32_t;
    
    struct Node {
        Node *par = nullptr;
        Node *left = nullptr, *right = nullptr;

        uint cnt = 1;
        int value;
        uint pri;

        Node (int value, uint pri): value(value), pri(pri) {}
    };

    mt19937 rnd;
    Node *root = nullptr;

    ImplicitTreap(): rnd((random_device())()) {}

    uint size() { return count(root); };
    uint count(Node *r) { return r == nullptr ? 0 : r->cnt; };
    Node *update(Node *r) {
        r->cnt = count(r->left) + count(r->right) + 1;
        return r;
    };
    
    Node *merge(Node *l, Node *r) {
        if (l == nullptr) return r;
        else if (r == nullptr) return l;

        if (l->pri > r->pri) {
            l->right = merge(l->right, r);
            update(l);
            return l;
        }
        else {
            r->left = merge(l, r->left);
            update(r);
            return r;
        }
    }
    pair<Node *, Node *> split(Node *t, uint k) {
        if (t == nullptr) return make_pair(nullptr, nullptr);

        if (k <= count(t->left)) {
            pair<Node *, Node *>s = split(t->left, k);
            t->left = s.second;
            update(t);
            return make_pair(s.first, t);
        }
        else {
            pair<Node *, Node *> s = split(t->right, k - count(t->left) - 1);
            t->right = s.first;
            update(t);
            return make_pair(t, s.second);
        }
    }

    void insert(Node *t, uint k, int v) {
        Node u = new Node(v, rnd());

        pair<Node *, Node *>s = split(t, k);
        t = merge(s.first, u);
        t = merge(t, s.second);
    }
    void erase(Node *t, uint k) {
        pair<Node *, Node *>s1 = split(t, k + 1);
        pair<Node *, Node *>s2 = split(s1.first, k);

        delete(s2.second);
        merge(s2.first, s1.second);
    }
};
//===

int main() {

    return 0;
}
