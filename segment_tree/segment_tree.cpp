#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<typename Monoid, typename OP = function<Monoid(Monoid, Monoid)> >
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    vector<Monoid> tree;
    int size;
    const OP f; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(int nmemb, const Monoid &e, const OP &f):
        size(nmemb),
        f(f),
        e(e)
    {
        tree.assign(2 * size, e);
    }

    void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k /= 2;
            tree[k] = f(tree[2 * k], tree[2 * k + 1]);
        }
    }

    // [l, r)
    Monoid query(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid vl = e;
        Monoid vr = e;
        while (l < r) {
            if (l & 1) {
                vl = f(vl, tree[l]);
                l++;
            }
            if (r & 1) {
                r--;
                vr = f(tree[r], vr);
            }

            l /= 2;
            r /= 2;
        }

        return f(vl, vr);
    }

    Monoid operator[] (const int k) { return query(k, k + 1); }
};
//===

//verify AOJ DSL_2_B
int AOJ_DSL2B() {
    typedef long long ll;
    
    ll n, q;
    ll com, x, y;

    cin >> n >> q;

    auto f = [](ll l, ll r){ return l + r; };
    SegmentTree<ll, decltype(f)> RSQ(n, 0, f);

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;
        x--;

        if (com == 0) {
            y += RSQ.query(x, x + 1);
            RSQ.update(x, y);
        }
        else {
            cout << RSQ.query(x, y) << endl;
        }
    }

    return 0;
}

//verify AOJ DSL_2_A
int AOJ_DSL2A() {
    int n, q;
    int com, x, y;

    cin >> n >> q;

    SegmentTree<int> RMQ(n,
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

int main() {
    //return AOJ_DSL2B();
    return AOJ_DSL2A();
}
