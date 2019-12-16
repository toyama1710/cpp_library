//#pragma GCC optimize("Ofast")
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
    const OP merge_monoid; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(int nmemb, const Monoid &e, const OP &f):
        size(nmemb), merge_monoid(f), e(e)
    {
        tree.assign(size << 1, e);
    }

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid &e, const OP &f):
        size(distance(first, last)), merge_monoid(f), e(e)
    {
        tree.resize(size << 1);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    }

    inline void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    }

    // [l, r)
    inline Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);

            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===

//verify AOJ DSL_2_B
int AOJ_DSL2B() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    int com, x, y;

    scanf("%d %d", &n, &q);

    auto f = [](int l, int r){ return l + r; };
    SegmentTree<int, decltype(f)> RSQ(n, 0, f);

    while (q--) {
        scanf("%d %d %d", &com, &x, &y);
        x--;

        if (com == 0) {
            y += RSQ.fold(x, x + 1);
            RSQ.update(x, y);
        }
        else {
            printf("%d\n", RSQ.fold(x, y));
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
            cout << RMQ.fold(x, y + 1) << endl;
        }
    }

    return 0;
}

int main() {
    return AOJ_DSL2B();
    //return AOJ_DSL2A();
}
