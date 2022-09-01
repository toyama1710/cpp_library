#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

//===
inline size_t get_lsb(size_t bits) {
    return bits & ((~bits) + 1);
};

// ATTENTION!! 1-indexed
template <class T>
struct FenwickTree {
    vector<T> data;
    const size_t size;

    FenwickTree(size_t nmemb) : data(nmemb + 1, 0), size(nmemb){};

    void add(size_t k, T d) {
        while (k <= size) data[k] += d, k += get_lsb(k);
    };

    // get sum for [1, i]
    T prefix_sum(size_t i) {
        T ret = 0;
        while (i > 0) ret += data[i], i -= get_lsb(i);
        return ret;
    };
};
//===

int AOJ_DSL2B() {
    int n, q;
    int com, x, y;

    cin >> n >> q;
    FenwickTree<long long> sum(n);

    while (q--) {
        cin >> com >> x >> y;

        if (com == 0) {
            sum.add(x, y);
        } else if (com == 1) {
            if (x == 1)
                cout << sum.prefix_sum(y) << endl;
            else
                cout << sum.prefix_sum(y) - sum.prefix_sum(x - 1) << endl;
        }
    }

    return 0;
}

int main() {
    AOJ_DSL2B();
}
