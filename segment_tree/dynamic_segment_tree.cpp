#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cfloat>
using namespace std;

//===
template<class Monoid, class OP = function<Monoid(const Monoid, const Monoid)> >
struct DynamicSegmentTree {
    struct Node {
        Node *left, *right;
        Monoid v;
        Node(Monoid v):v(v), left(nullptr), right(nullptr) {}
    };

    using llong = long long;

    Node *root = nullptr;
    llong L = 0, R = 0;
    const OP merge_monoid; // bin'operation
    const Monoid e;

    DynamicSegmentTree(const Monoid &e, const OP &f):
        e(e), merge_monoid(f) {};

    inline void eval(Node &u) {
        Monoid lv = e, rv = e;
        if (u.left) lv = u.left->v;
        if (u.right) rv = u.right->v;
        u.v = merge_monoid(lv, rv);
    };

    void expand(llong i) {
        if (L == R) {
            R++;
            while (i >= R) R += R - L;
            while (i < L) L -= R - L;
            root = new Node(e);
        }
        else {
            Node *tmp;
            while (i >= R) {
                R += R - L;
                tmp = new Node(root->v);
                tmp->left = root;
                root = tmp;
            }
            while (i < L) {
                L -= R - L;
                tmp = new Node(root->v);
                tmp->right = root;
                root = tmp;
            }
        }
    };

    void update(llong i, Monoid v) {
        if (i < L || R <= i) expand(i);
        update(root, L, R, i, v);
    };

    void update(Node *node, llong nl, llong nr, llong k, Monoid v) {
        if (nr - nl <= 1) {
            node->v = v;
            return;
        }
        
        llong mid = (nl + nr) / 2;
        if (k < mid) {
            if (!node->left) node->left = new Node(e);
            update(node->left, nl, (nl + nr) / 2, k, v);
        }
        else {
            if (!node->right) node->right = new Node(e);
            update(node->right, (nl + nr) / 2, nr, k, v);
        }

        eval(*node);
        return;
    }

    // [l, r)
    Monoid fold(llong l, llong r) {
        return fold(root, L, R, l, r);
    };
    Monoid fold(Node *node, llong nl, llong nr, llong ql, llong qr) {
        if (nr <= ql || qr <= nl) return e;
        if (ql <= nl && nr <= qr) return node->v;

        Monoid lv = e, rv = e;
        if (node->left) lv = fold(node->left, nl, (nl + nr) / 2, ql, qr);
        if (node->right) rv = fold(node->right, (nl + nr) / 2, nr, ql, qr);

        return merge_monoid(lv, rv);
    };
    
    Monoid operator[] (const llong k) {
        return fold(k, k + 1);
    };
};
//===

//verify AOJ DSL2A
int DSL_2_A(void) {
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<int> RMQ((1u << 31u) - 1,
                    [](int l, int r){
                        return min(l, r);
                    });
    
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            RMQ.update(x, y);
        }
        else {
            cout << RMQ.fold(x, y + 1) << endl;
        }
    }

    return 0;
}

int DSL_2_B(void) {
    using ll = long long;
    
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<ll> RSQ(0, [](ll l, ll r){ return l + r; });

    while (q--) {
        cin >> com >> x >> y;

        if (com == 0) {
            RSQ.update(x - 1, RSQ[x - 1] + y);
        }
        else if (com == 1) {
            cout << RSQ.fold(x - 1, y) << endl;
        }
    }
    return 0;
}

int ARC008_D(void) {
    using ll = long long;
    
    struct func{ double a, b; };
    auto merge = [](func l, func r) {
                     return (func){l.a * r.a, l.b * r.a + r.b};
                 };

    ll n, m;
    ll p;
    double a, b;
    double minv, maxv;
    minv = maxv = 1;

    cin >> n >> m;

    DynamicSegmentTree<func, decltype(merge)> seg((func){1, 0}, merge);

    for (int i = 0; i < m; i++) {
        cin >> p >> a >> b;
        --p;

        seg.update(p, (func){a, b});
        func x = seg.fold(0, n);

        minv = min(minv, x.a + x.b);
        maxv = max(maxv, x.a + x.b);
    }

    printf("%.*lf\n", DBL_DIG, minv);
    printf("%.*lf\n", DBL_DIG, maxv);

    return 0;
}

int main()
{
    //return DSL_2_A();
    //return DSL_2_B();
    return ARC008_D();
}
