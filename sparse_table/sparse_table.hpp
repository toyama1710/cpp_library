#ifndef SPARSE_TABLE_HPP
#define SPARSE_TABLE_HPP

#include <functional>
#include <vector>
#include <iterator>

//===
template<class SemiLattice>
struct SparseTable {
    using S = SemiLattice;
    using T = typename SemiLattice::value_type;

    std::vector<std::vector<T>> table;
    std::vector<size_t> log2;

    SparseTable() = default;

    template<class InputItr>
    SparseTable(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        log2.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;
        
        table.reserve(log2[n] + 1);
        table.emplace_back(first, last);

        for (int i = 1; (1 << i) <= n; i++) {
            int w = 1 << (i - 1);
            table.emplace_back();
            table.back().reserve(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i].emplace_back(S::operation(table[i - 1][j], table[i - 1][j + w]));
            }
        }
    };

    //[l, r)
    T fold(int l, int r) {
        int k = log2[r - l];
        return S::operation(table[k][l], table[k][r - (1 << k)]);
    };

    int size() {
        return table[0].size();
    };

    T operator[] (const int k) {
        return table[0][k];
    };
};
//===

#endif