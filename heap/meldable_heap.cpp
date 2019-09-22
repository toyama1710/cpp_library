#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

//===
//=== xorshift
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ ( s << 5);
    return s;
}
//===

// not stable
template<typename T, typename Compare = less<T> >
struct MeldableHeap {
    struct Node {
        T dat;
        Node *l, *r;

        Node (T dat): dat(dat), l(nullptr), r(nullptr) {};
    };

    Node *root;
    Compare cmp;

    MeldableHeap (Compare cmp = Compare()): root(nullptr), cmp(cmp) {};

    Node *meld(Node *h1, Node *h2) {
        if (h1 == nullptr) return h2;
        else if (h2 == nullptr) return h1;

        if (cmp(h2->dat, h1->dat)) swap(h1, h2);
        
        if (xorshift32() & 1) h1->l = meld(h1->l, h2);
        else h1->r = meld(h1->r, h2);

        return h1;
    };

    void push(T dat) {
        Node *u = new Node(dat);
        root = meld(root, u);
    };

    T top() { return root->dat; };
    
    T pop() {
        assert(!empty());
        T ret = top();
        Node *rm = root;
        root = meld(root->l, root->r);
        delete rm;
        
        return ret;
    };

    void merge_with(MeldableHeap &h) {
        root = meld(root, h);
        h.root = nullptr;
    };

    bool empty() { return root == nullptr; };
};
// MinHeap<T> = MeldableHeap<T, less<T>>
// MaxHeap<T> = MeldableHeap<T, greater<T>>
//===

int ABC141D() {
    llong n, m;
    llong a;
    MeldableHeap<llong, greater<llong> > h;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h.push(a);
    }

    for (int i = 0; i < m; i++) {
        a = h.pop() / 2;
        h.push(a);
    }

    llong sum = 0;
    while (!h.empty()) {
        sum += h.pop();
    }

    cout << sum << endl;
    
    return 0;
}

int main() {
    return ABC141D();
}
