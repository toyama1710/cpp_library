#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<typename Monoid>
struct SegmentTree {
    using OP = function<Monoid(Monoid, Monoid)>;
    
    vector<Monoid> tree;
    int size;
    const OP f; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(int nmemb, const Monoid &e, const OP &f):
        f(f),
        e(e)
    {
        size = 1;
        while (size < nmemb) {
            size *= 2;
        }

        tree.assign(2 * size - 1, e);
    }

    void update(int k, Monoid dat)
    {
        k += size - 1;
        tree[k] = dat;
        
        while(k > 0) {
            k = (k - 1) / 2;
            tree[k] = f(tree[2 * k + 1], tree[2 * k + 2]);
        }
    }

    // [l, r)
    Monoid query(int l, int r)
    {
        l += size - 1;
        r += size - 1;

        Monoid d = e;
        while (l < r) {
            if (l % 2 == 0) {
                d = f(d, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                r--;
                d = f(d, tree[r]);
            }

            l = (l - 1) / 2;
            r = (r - 1) / 2;
        }

        return d;
    }
};
//===

//verify AOJ DSL_2_B
int AOJ_DSL_2_B(void)
{
    typedef long long ll;
    
    ll n, q;
    ll com, x, y;

    cin >> n >> q;

    SegmentTree<ll> RSQ(n,
                        0,
                        [](ll l, ll r){return l + r;});

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
}

//verify AOJ DSL_2_A
int AOJ_DSL_2_A(void)
{
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

int main()
{
    //   return AOJ_DSL_2_B();
    return AOJ_DSL_2_A();
}
