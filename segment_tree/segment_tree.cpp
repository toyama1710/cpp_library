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

    void update(int k, Monoid dat) {
        k += size - 1;
        tree[k] = dat;
        
        while(k > 0) {
            k = (k - 1) / 2;
            tree[k] = f(tree[2 * k + 1], tree[2 * k + 2]);
        }
    }

    // [l, r)
    Monoid query(int l, int r) {
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

    Monoid operator[] (const int k) { return query(k, k + 1); }
};
//===

/*
//verify AOJ DSL_2_B
int main()
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
*/

/*
  //verify AOJ DSL_2_A
int main()
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
*/

//---verify PCK2013 pre 7
using ll = long long;
ll n, r, l;
ll d[1'000'005];
ll t[1'000'005];
ll x[1'000'005];
ll tv[1'000'005];

struct Team{ ll id, point; };

int main()
{
    cin >> n >> r >> l;
    for (int i = 1; i <= r; i++) {
        cin >> d[i] >> t[i] >> x[i];
    }

    SegmentTree<Team> seg(n + 1,
                          (Team){0, -1 * (1ll << 60ll)},
                          [](const Team x, const Team y){
                              if (x.point > y.point) {
                                  return x;
                              }
                              else if (x.point == y.point) {
                                  if (x.id < y.id) {
                                      return x;
                                  }
                                  else {
                                      return y;
                                  }
                              }
                              else {
                                  return y;
                              }
                          });
    //init
    for (int i = 1; i <= n; i++) {
        seg.update(i, (Team){i, 0});
    }

    //setinel
    d[0] = 0, t[0] = 0, x[0] = 0;
    d[r + 1] = 0, t[r + 1] = l, x[r + 1] = 0;
        
    for (int i = 1; i <= r + 1; i++) {
        Team a = seg.query(1, n + 1);
        tv[a.id] += t[i] - t[i - 1];

        a = seg[d[i]];
        a.point += x[i];
        seg.update(d[i], a);
    }

    int mpos = 0;
    for (int i = 1; i <= n; i++) {
        if (tv[mpos] < tv[i]) mpos = i;
    }

    cout << mpos << endl;

    return 0;
}
