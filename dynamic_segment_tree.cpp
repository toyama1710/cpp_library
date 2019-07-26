#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cfloat>
using namespace std;

//===
template<typename Monoid>
struct DynamicSegmentTree {
    struct Node {
        Node *left, *right;
        Monoid v;
        Node(Monoid v):v(v), left(nullptr), right(nullptr){}
        Node(void):left(nullptr), right(nullptr){}
    };
    
    using OP = function<Monoid(Monoid, Monoid)>;
    using ll = long long;

    Node root = Node();
    ll size;
    const OP f; // bin' operation
    const Monoid e; // neutral element
                                           
    DynamicSegmentTree(ll nmemb, const Monoid &e, const OP &f):
        f(f),
        e(e)
    {
        size = 1;
        while (size < nmemb) {
            size *= 2;
        }

        root.v = e;
    }

    Monoid update(Node *node, ll nl, ll nr, ll k, Monoid dat) {
        if (nr - nl <= 1) {
            return node->v = dat;
        }
        
        ll mid = (nl + nr) / 2;
        Monoid lv, rv;

        lv = rv = e;

        if (node->left != nullptr) lv = node->left->v;
        if (node->right != nullptr) rv = node->right->v;
            
        if (k < mid) {
            if (node->left == nullptr) node->left = new Node(e);
            lv = update(node->left, nl, (nl + nr) / 2, k, dat);
        }
        else {
            if (node->right == nullptr) node->right = new Node(e);
            rv = update(node->right, (nl + nr) / 2, nr, k, dat);
        }

        return node->v = f(lv, rv);
    }

    void update(ll k, Monoid dat)
    {
        update(&root, 0, size, k, dat);
    }

    Monoid query(Node *node, ll nl, ll nr, ll ql, ll qr)
    {
        if (nr <= ql || qr <= nl) return e;

        if (ql <= nl && nr <= qr) return node->v;

        Monoid l = e, r = e;
        
        if (node->left != nullptr) l = query(node->left, nl, (nl + nr) / 2, ql, qr);
        if (node->right != nullptr) r = query(node->right, (nl + nr) / 2, nr, ql, qr);

        return f(l, r);
    }
    
    // [l, r)
    Monoid query(ll l, ll r)
    {
        return query(&root, 0, size, l, r);
    }

    Monoid operator[] (const ll k)
    {
        return query(k, k + 1);
    }
};
//===

//verify AOJ DSL2A
int DSL_2_A(void)
{
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<int> RMQ(n,
                    (1u << 31u) - 1,
                    [](int l, int r){
                        return min(l, r);
                    });
    
    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            RMQ.update(x, y);
        }
        else {
            cout << RMQ.query(x, y + 1) << endl;
        }
    }

    return 0;
}

int DSL_2_B(void)
{
    using ll = long long;
    
    int n, q;
    int com, x, y;

    cin >> n >> q;

    DynamicSegmentTree<ll> RSQ(n, 0,
                               [](ll l, ll r){ return l + r; });

    while (q--) {
        cin >> com >> x >> y;

        if (com == 0) {
            RSQ.update(x - 1, RSQ[x - 1] + y);
        }
        else if (com == 1) {
            cout << RSQ.query(x - 1, y) << endl;
        }
    }
}

int ARC008_D(void)
{
    using ll = long long;
    
    struct func{ double a, b; };

    ll n, m;
    ll p;
    double a, b;
    double minv, maxv;
    minv = maxv = 1;

    cin >> n >> m;

    DynamicSegmentTree<func> seg(n, (func){1, 0},
                                 [](func l, func r) {
                                     func ret;
                                     ret.a = l.a * r.a;
                                     ret.b = l.b * r.a + r.b;
                                     return ret;
                                 });

    for (int i = 0; i < m; i++) {
        cin >> p >> a >> b;
        --p;

        seg.update(p, (func){a, b});
        func x = seg.query(0, n);

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
