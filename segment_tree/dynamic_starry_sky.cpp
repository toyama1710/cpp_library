#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
// T:monoid, E:operator
template<class T, class E>
struct DynamicStarrySky {
    using llong = long long;
    using MergeT = function<T(T, T)>;
    using ApplyE = function<T(T, E, llong)>;
    using MergeE = function<E(E, E)>;
    
    struct Node {
        Node *left, *right;
        T v;
        E lazy;
        Node(T t, E e):v(t), lazy(e), left(nullptr), right(nullptr) {}
    };

    Node *root = nullptr;
    llong L = 0, R = 0;

    const MergeT merge_monoid;
    const ApplyE apply_lazy;
    const MergeE merge_lazy;

    const T ti;
    const E ei;

    DynamicStarrySky(const T &ti, const E &ei,
                     const MergeT &f, const ApplyE &g, const MergeE &h):
        ti(ti), ei(ei), merge_monoid(f), apply_lazy(g), merge_lazy(h) {};

    inline void eval(Node &u, llong l, llong r) {
        T lv = ti, rv = ti;
        if (u.left) lv = apply_lazy(u.left->v, u.left->lazy, (r - l) / 2);
        if (u.right) rv = apply_lazy(u.right->v, u.right->lazy, (r - l) / 2);
        u.v = merge_monoid(lv, rv);
    };

    inline void expand(llong i) {
        if (L == R) {
            R++;
            while (i >= R) R += R - L;
            while (i < L) L -= R - L;
            root = new Node(ti, ei);
        }
        else {
            Node *tmp;
            while (i >= R) {
                tmp = new Node(apply_lazy(root->v, root->lazy, R - L), ei);
                tmp->left = root;
                R += R - L;
                root = tmp;
            }
            while (i < L) {
                tmp = new Node(apply_lazy(root->v, root->lazy, R - L), ei);
                tmp->right = root;
                L -= R - L;
                root = tmp;
            }
        }
    };

    // [l, r)
    inline void update(llong l, llong r, E x) {
        if (l < L) expand(l);
        if (r > R) expand(r);
        update(root, L, R, l, r, x);
    };
    void update(Node *node, llong nl, llong nr, llong ql, llong qr, E x) {
        if (nr <= ql || qr <= nl) return;

        if (ql <= nl && nr <= qr) {
            node->lazy = merge_lazy(node->lazy, x);
        }
        else {
            if (!node->left) node->left = new Node(ti, ei);
            update(node->left, nl, (nl + nr) / 2, ql, qr, x);

            if (!node->right) node->right = new Node(ti, ei);
            update(node->right, (nl + nr) / 2, nr, ql, qr, x);
        }
        eval(*node, nl, nr);
        return;
    };
    
    // [l, r)
    inline T fold(llong l, llong r) {
        if (l < L) expand(l);
        if (r > R) expand(r);
        return fold(root, L, R, l, r);
    };
    T fold(Node *node, llong nl, llong nr, llong ql, llong qr) {
        if (ql <= nl && nr <= qr) return apply_lazy(node->v, node->lazy, nr - nl);

        T lv = ti, rv = ti;
        llong mid = (nl + nr) / 2;
        if (node->left && ql < mid && nl < qr) {
            lv = fold(node->left, nl, mid, ql, qr);
        }
        if (node->right && ql < nr && mid < qr) {
            rv = fold(node->right, mid, nr, ql, qr);
        }

        T v;
        v = merge_monoid(lv, rv);
        v = apply_lazy(v, node->lazy, min(nr, qr) - max(nl, ql));
            
        return v;
    };
    
    T operator[] (const llong k) {
        return fold(k, k + 1);
    };
};
//===

using llong = long long;
llong n, q;
llong com;
llong s, t, x;
DynamicStarrySky<llong, llong> RSQ(0, 0,
                                   [](auto l, auto r) { return l + r; },
                                   [](auto l, auto r, llong L) { return l + r * L; },
                                   [](auto l, auto r) { return l + r; });

int main() {
    cin >> n >> q;

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            --s;

            RSQ.update(s, t, x);
        }
        else if (com == 1) {
            cin >> s >> t;
            --s;
            
            cout << RSQ.fold(s, t) << '\n';
        }
    }
};
