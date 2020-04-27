#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <vector>
using namespace std;
using llong = long long;

//===
template <class SemiGroup,
          class Merge = function<SemiGroup(SemiGroup, SemiGroup)>>
struct DisjointSparseTable {
    static int msb(int x) {
#ifndef __has_builtin
        // (r |= a) == (r += a)
        int r = 0;
        if (x >> 16) x >>= 16, r |= 16;
        if (x >> 8) x >>= 8, r |= 8;
        if (x >> 4) x >>= 4, r |= 4;
        if (x >> 2) x >>= 2, r |= 2;
        return r | (x >> 1);
#else
        return 31 - __builtin_clz(x);
#endif
    };

    bool builded = false;
    Merge f;
    int sz;
    vector<vector<SemiGroup>> table;
    vector<int> msb_table;

    DisjointSparseTable(int n, SemiGroup d, Merge f): sz(n), f(f) {
        table.emplace_back(n, d);
        builded = false;
    }
    template<class InputItr>
    DisjointSparseTable(InputItr first, InputItr last, Merge f) {
        table.emplace_back(first, last);
        sz = table[0].size();

        build();
    };

    void build() {
        msb_table[0] = 1;
        for (int i = 1; i < sz; i <<= 1) {
            msb_table[i] = msb_table[i - 1] + 1;
            for (int j = i + 1; j < (i << 1); j++) {
                msb_table[j] = msb_table[i];
            }
        }
        for (int i = 2; i < sz; i <<= 1) {
            
        }
    };
    void set(int idx, SemiGroup d) {
        assert(idx >= 0 && idx < sz);
        table[0][idx] = d;
        builded = false;
    };

    SemiGroup fold(int l, int r) {
        assert(l < r);
        assert(l >= 0 && r <= sz);
        assert(builded);
    };
    SemiGroup fold(int l, int r, SemiGroup e) {
        if (l >= r) return e;
        return fold(l, r);
    };
};
//===

int main() {

    return 0;
}
