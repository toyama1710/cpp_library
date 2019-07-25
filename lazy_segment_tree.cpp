#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

//===
template<typename Monoid, typename Laz>
struct LazySegmentTree {

    const function<Monoid(Monoid, Monoid)> mergeMonoid;
    const function<Monoid(Monoid, Laz, int)> applyLaz;
    const function<Laz(Laz, Laz)> mergeLaz;
    
    const Monoid e; // neutral element
    
    vector<Monoid> seg;
    vector<Laz> lazy;
    vector<bool> isUpdated;
    
    int size;
                                           
    LazySegmentTree(int nmemb, const Monoid &e,
                    function<Monoid(Monoid, Monoid)> f,
                    function<Monoid(Monoid, Laz, int)> g,
                    function<Laz(Laz, Laz)> h):
        e(e), mergeMonoid(f), applyLaz(g), mergeLaz(h)
    {
        size = 1;
        while (size < nmemb) {
            size *= 2;
        }

        seg.assign(2 * size - 1, e);
        isUpdated.assign(2 * size - 1, true);
        lazy.resize(2 * size - 1); 
    }

    inline void lazyPropagation(int k, int len)
    {
        if (!isUpdated[k]) {
            seg[k] = applyLaz(seg[k], lazy[k], len);
            if (len > 1) {
                if (isUpdated[2 * k + 1])
                    lazy[2 * k + 1] = lazy[k], isUpdated[2 * k + 1] = false;
                else
                    lazy[2 * k + 1] = mergeLaz(lazy[2 * k + 1], lazy[k]);
                
                if (isUpdated[2 * k + 2])
                    lazy[2 * k + 2] = lazy[k], isUpdated[2 * k + 2] = false;
                else 
                    lazy[2 * k + 2] = mergeLaz(lazy[2 * k + 2], lazy[k]);
            }
            isUpdated[k] = true;
        }
    }

    Monoid update(int k, int nl, int nr, int ql, int qr, Laz dat)
    {
        lazyPropagation(k, nr - nl);

        if (nr <= ql || qr <= nl) return seg[k];

        if (ql <= nl && nr <= qr) {
            lazy[k] = dat;
            isUpdated[k] = false;
            lazyPropagation(k, nr - nl);
            return seg[k];
        }
        else {
            seg[k] = mergeMonoid(update(2 * k + 1, nl, (nl + nr) / 2, ql, qr, dat),
                                 update(2 * k + 2, (nl + nr) / 2, nr, ql, qr, dat));
            return seg[k];
        }
    }

    // [l, r) <= dat
    void update(int l, int r, Laz dat)
    {
        update(0, 0, size, l, r, dat);
        return;
    }

    Monoid query(int k, int nl, int nr, int ql, int qr)
    {

        lazyPropagation(k, nr - nl);
        
        if (nr <= ql || qr <= nl) return e;

        if (ql <= nl && nr <= qr) return seg[k];
        else return mergeMonoid(query(2 * k + 1, nl, (nl + nr) / 2, ql, qr),
                                query(2 * k + 2, (nl + nr) / 2, nr, ql, qr));
    }

    // [l, r)
    Monoid query(int l, int r)
    {
        return query(0, 0, size, l, r);
    }

    Monoid operator [](const int &k)
    {
        return query(k, k + 1);
    }
};
//===

//verify 2019/07/25 17:12
int DSL_2_D(void)
{
    int n, q;
    int com, s, t, x;

    cin >> n >> q;

    LazySegmentTree<int, int> seg(n, -1,
                                  /*f=*/[](int l, int r){
                                      return max(l, r);
                                  },
                                  /*g=*/[](int m, int laz, int len){
                                      return laz;
                                  },
                                  /*h=*/[](int l, int r) {
                                      return r;
                                  });

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else if (com == 1) {
            cin >> s;
            int a = seg[s];

            if (a == -1) cout << (1ll << 31ll) - 1 << endl;
            else cout << a << endl;
        }
    }

    return 0;
}

int main()
{
    return DSL_2_D();
}
