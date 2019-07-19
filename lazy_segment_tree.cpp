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
    const function<Monoid(Monoid, Laz)> applyLaz;
    const function<Laz(Laz, Laz)> mergeLaz;
    
    vector<Monoid> seg;
    vector<Laz> lazy;
    vector<bool> isUpdated;
    
    int size;
    int height;
    const Monoid e; // neutral element
                                           
    LazySegmentTree(int nmemb, const Monoid &e,
                    function<Monoid(Monoid, Monoid)> f,
                    function<Monoid(Monoid, Laz)> g,
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

    // [l, r) <= dat
    void update(int l, int r, Laz dat)
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
    }
};
//===

int main()
{
    return 0;
}
