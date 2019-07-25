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
                is (isUpdated[k])
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

    void update(int l, int r, int node, int nl, int nr)
    {
        if (r <= nl || nr <= l) return;

        lazyPropagation(node, nr - nl);

        if (l <= nl && r <= nr) {
        }
        else {
        }
    }

    // [l, r) <= dat
    void update(int l, int r, Laz dat)
    {
    }

    Monoid query(int node, int nl, int nr, int ql, int qr)
    {
        if (nr <= ql || qr <= nl) return e;

        if (ql <= nl && nr <= qr) {
            if (isUpdated(node)) return seg[node];
            else return applyLaz(seg[node], lazy[node], nr - nl);
        }
        else {
            lazyPropagation(node);
        }
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
