#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
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

        root.v = &e;
    }

    void update(ll k, Monoid dat)
    {
        Node *n = &root;

        ll l = 0, r = size;

        while (r - l > 1) {
            ll mid = (l + r) / 2;

            if (k < mid) {
                if (!n->left) n->left = new Node(e);
                n = n->left;
                r = mid;
            }
            else {
                if (!n->right) n->right = new Node(e);
                n = n->right;
                l = mid;
            }
            n->v = f(n->v, dat);
        }
    }

    Monoid query(Node *node, ll nl, ll nr, ll ql, ll qr)
    {
        if (nr <= ql || qr <= nr) return e;

        if (ql <= nl && nr <= qr) return node->v;

        Monoid l = e, r = e;
        
        if (node->left) l = query(node->left, nl, (nl + nr) / 2, ql, qr);
        if (node->right) r = query(node->right, (nl + nr) / 2, nr, ql, qr);

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

int main()
{
    return 0;
}
