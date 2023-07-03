#ifndef DISJOINT_SPARSE_TABLE_HPP
#define DISJOINT_SPARSE_TABLE_HPP

#include <cassert>
#include <vector>

#include "../bit/ctz.hpp"
#include "../bit/msb.hpp"

//===
template <class SemiGroup>
struct DisjointSparseTable {
    using T = typename SemiGroup::value_type;
    using G = SemiGroup;

    std::vector<std::vector<T>> table;

    DisjointSparseTable() = default;
    template <class InputItr>
    DisjointSparseTable(InputItr first, InputItr last) {
        build(first, last);
    };

    template <class InputItr>
    void build(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        int logn = 1;
        while ((1 << logn) < n) logn++;

        table.reserve(logn);
        table.emplace_back(first, last);

        for (int i = 1; i < logn; i++) {
            table.emplace_back(first, last);
            int w = 1 << i;

            for (int k = w; k < n; k += 2 * w) {
                for (int j = k - 2; j >= k - w; j--) {
                    table[i][j] = G::operation(table[i][j], table[i][j + 1]);
                }
                for (int j = k + 1; j < std::min(n, k + w); j++) {
                    table[i][j] = G::operation(table[i][j], table[i][j - 1]);
                }
            }
        }
    };

    // [l, r)
    T fold(int l, int r) {
        assert(l < r);
        assert(l >= 0 && r <= size());
        r--;
        int x = l ^ r;

        if (x == 0)
            return table[0][l];
        else
            return G::operation(table[ctz32(msb32(x))][l],
                                table[ctz32(msb32(x))][r]);
    };

    T fold(int l, int r, SemiGroup e) {
        if (l >= r) return e;
        return fold(l, r);
    };

    int size() {
        return table[0].size();
    };

    const T operator[](int k) {
        return fold(k, k + 1);
    };
};
//===
#endif
