#ifndef PRIME_FACTORIZE_TABLE_HPP
#define PRIME_FACTORIZE_TABLE_HPP

#include <cassert>
#include <utility>
#include <vector>

struct PrimeFactorizeTable {
    using P = std::pair<int, int>;  // prod(table[i], first ** second) = i
    std::vector<std::vector<P>> table;

    PrimeFactorizeTable(int n) : table(n + 1) {
        for (int i = 2; i <= n; i++) {
            if (!table[i].empty()) continue;
            for (int j = i; j <= n; j += i) {
                table[j].push_back(P(i, 0));
                int tmp = j;
                while (tmp > 1 && tmp % i == 0) {
                    table[j].back().second++;
                    tmp /= i;
                }
            }
        }
    };

    std::vector<P> factorize(int n) {
        assert(n > 1);
        return table[n];
    };
};

#endif
