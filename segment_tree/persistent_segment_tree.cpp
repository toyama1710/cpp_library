//=== header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <cstdint>

using namespace std;
using llong = long long;

//===
// #include <iterator>
// #include <functional>
// #include <vector>
// #include <cstdint>
template<class Monoid, class F = function<Monoid(Monoid, Monoid)>>
struct PersistentSegmentTree {
    struct Node;

    const Monoid e;
    const F f;
    const Node *root;
    const size_t n;

    struct Node {
        Monoid dat;
        Node *l = nullptr, *r = nullptr;

        Node (Monoid dat):dat(dat) {};
    };

    Node *merge_node(Node *lch, Node *rch) {
        Monoid l = (lch ? lch->dat : e);
        Monoid r = (rch ? rch->dat : e);
        Node *ret = new Node(f(l, r));
        ret->l = lch;
        ret->r = rch;

        return ret;
    };

    PersistentSegmentTree(Monoid e, F f, size_t n, Node *r)
        :e(e), f(f), n(n), root(r) {};
    PersistentSegmentTree(Monoid e, F f, size_t n)
        :e(e), f(f), n(n), root(alloc(0, n, vector<Monoid>(n, e))) {};
    template<class InputItr>
    PersistentSegmentTree(Monoid e, F f, InputItr first, InputItr last)
        :e(e), f(f), n(distance(first, last)), root(alloc(0, n, vector<Monoid>(first, last))) {};

    Node *alloc(size_t nl, size_t nr, const vector<Monoid> &v) {
        if (nr - nl <= 1) return new Node(v[nl]);
        else return merge_node(alloc(nl, (nl + nr) / 2, v),
                            alloc((nl + nr) / 2, nr, v));
    };

    Monoid fold(size_t l, size_t r) {
        return fold(l, r, 0, n, root);
    };
    Monoid fold(size_t ql, size_t qr, size_t nl, size_t nr, Node *np) {
        if (np == nullptr || qr <= nl || nr <= ql) return e;
        else if (ql <= nl && nr <= qr) return np->dat;
        else return f(fold(ql, qr, nl, (nl + nr) / 2, np->l), fold(ql, qr, (nl + nr) / 2, nr, np->r));
    };

    PersistentSegmentTree set(size_t idx, Monoid d) {
        return PersistentSegmentTree(e, f, n, update(0, n, idx, d, root));
    };
    Node *update(size_t nl, size_t nr, size_t idx, Monoid d, const Node *np) {
        if (idx < nl || nr <= idx) return np;
        else if (nr - nl == 1) return new Node(d);
        else return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l), update((nl + nr) / 2, nr, idx, d, np->r));
    };

    PersistentSegmentTree get_tree() {
        return *this;
    };

    Monoid operator [] (size_t idx) {
        return fold(idx, idx + 1, 0, n, root);
    };
};
//===

int main() {
    PersistentSegmentTree<llong> seg(0, [](llong l, llong r){return l + r; }, 5);
    cout << sizeof(seg) << endl;
    cout << sizeof(llong) << endl;
    return 0;
};

