#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//===
template<typename Monoid>
struct SegmentTree {
    using OP = function<Monoid(Monoid, Monoid)>;
    
    vector<Monoid> tree;
    int size;
    const op f; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(int nmemb, const Monoid &e, const op &f):
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
        k += n - 1;
        tree[k] = dat;
        
        while(k > 0) {
            k = (k - 1) / 2;
            tree[k] = f(tree[2 * k + 1], tree[2 * k + 2]);
        }
    }

    // [l, r)
    Monoid query(int l, int r) {
        l += n - 1;
        r += n - 1;

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

int main()
{
    int n, q;
    int com, x, y;

    cin >> n >> q;

    SegmentTree RMQ<int>(n,
                    [](int l, int r){
                        return min(l, r);
                    },
                    (1 << 31) - 1);
    
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

