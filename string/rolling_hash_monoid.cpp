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
    
    rh neutral() {
        RollingHashMonoid res;
        res.ch = 0, res.sz = 0, res.h = 0;
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

int main() {

    return 0;
}
