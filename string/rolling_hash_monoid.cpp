#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
//#include <cstdint>
template<uint64_t mod, uint64_t base>
struct RollingHashMonoid {
    using rh = RollingHashMonoid<mod, base>;
        
    int sz;
    uint64_t h;

    static vector<uint64_t> p;

    RollingHashMonoid() {};
    RollingHashMonoid(char ch): sz(1), h(ch % mod) {};
    
    static rh neutral() {
        RollingHashMonoid res;
        res.sz = 0, res.h = 0;
        return res;
    };

    rh operator + (const rh &r) const {
        const rh &l = *this;
        rh res = neutral();

        while (p.size() <= r.sz) p.push_back(p.back() * base % mod);

        res.sz = l.sz + r.sz;
        res.h = (l.h * p[r.sz] % mod + r.h) % mod;
        return res;
    };
};
template<uint64_t mod, uint64_t base>
vector<uint64_t> RollingHashMonoid<mod, base>::p = vector<uint64_t>(1, 1);
//===

//verify PCK2019 pre 11
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

using Rhash = RollingHashMonoid<(llong)(1e9) + 9, 1710>;
auto concat = [](Rhash l, Rhash r){ return l + r; };
SegmentTree<Rhash, decltype(concat)> seg(131072, Rhash::neutral(), concat);

llong base = 1710, mod = (llong)(1e9) + 9;
llong n, q;
string s;
llong p;
char c;
vector<llong> divisor;
llong loopt[100005];

void init() {
    llong radt[100005];
    radt[0] = 1;

    for (llong i = 0; i < 100003; i++) {
        radt[i + 1] = (radt[i] * base) % mod;
    }

    for (llong i = 0; i < divisor.size(); i++) {
        llong idx = divisor[i];

        llong j = 0;
        while (j < n) {
            loopt[n / idx] += radt[j];
            loopt[n / idx] %= mod;
            j += idx;
        }
    }
}

bool same(llong idx) {
    llong v;

    v = seg.query(0, idx).h * loopt[n / idx] % mod;
    if (v != seg.tree[1].h) {
        return false;
    }

    return true;
}

int main() {
    cin >> n >> q;
    cin >> s;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);

            if (n / i != i) divisor.push_back(n / i);
        }
    }
    
    sort(divisor.begin(), divisor.end());
    init();

    for (int i = 0; i < s.size(); i++) {
        seg.update(i, Rhash(s[i]));
    }

    for (int i = 0; i < q; i++) {
        cin >> p >> c;
        p--;
        s[p] = c;
        
        seg.update(p, Rhash(s[p]));
        
        llong ans = n;
        for (llong i = 0; i < divisor.size(); i++) {
            llong idx = divisor[i];

            if (same(idx)) {
                ans = idx;
                break;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
