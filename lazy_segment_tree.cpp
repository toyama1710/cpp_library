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
    int height;
                                           
    LazySegmentTree(int nmemb, const Monoid &e,
                    function<Monoid(Monoid, Monoid)> f,
                    function<Monoid(Monoid, Laz, int)> g,
                    function<Laz(Laz, Laz)> h):
        e(e), mergeMonoid(f), applyLaz(g), mergeLaz(h)
    {
        height = 0;
        size = 1;
        while (size < nmemb) {
            size *= 2;
            height++;
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
                if (!isUpdated[2 * k + 1])
                    lazy[2 * k + 1] = lazy[k];
                else
                    lazy[2 * k + 1] = mergeLaz(lazy[2 * k + 1], lazy[k]);
                
                if (isUpdated[2 * k + 2])
                    lazy[2 * k + 2] = lazy[k];
                else 
                    lazy[2 * k + 2] = mergeLaz(lazy[2 * k + 2], lazy[k]);
            }
            isUpdated[k] = true;
        }
    }

    void update(int k, int nl, int nr, int ql, int qr, Laz dat)
    {
        if (qr <= nl || nr <= ql) return;

        lazyPropagation(k, nr - nl);

        if (ql <= nl && nr <= qr) {
            lazy[k] = dat;
            lazy(k, nr - nl);
        }
        else {
            update(2 * k + 1, nl, (nl + nr) / 2, ql, qr, dat);
            update(2 * k + 2, (nl + nr) / 2, nr, ql, qr, dat);
            seg[k] = mergeMonoid(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }

    // [l, r) <= dat
    void update(int l, int r, Laz dat)
    {
        update(0, 0, size, l, r, dat);
    }

    Monoid query(int k, int nl, int nr, int ql, int qr)
    {
        if (nr <= ql || qr <= nl) return e;

        lazyPropagation(k, nr - nl);

        if (ql <= nl && nr <= qr) return seg[k];
        else return mergeMonoid(query(2 * k + 1, nl, (nl + nr) / 2, ql, qr),
                                query(2 * K + 1, (nl + nr) / f2, ql, qr));
    }

    // [l, r)
    Monoid query(int l, int r)
    {
        return query(0, 0, size, l, r);
    }
};
//===

int main()
{
    return 0;
}
