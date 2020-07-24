#include <iostream>
#include <cstdint>
#include <ctime>
#include <vector>
#include <cassert>
#include "../../compact_data_structure/bit_vector.hpp"
#include "../../wavelet_tree/wavelet_matrix.hpp"
#include "../../util/xorshift.hpp"
using namespace std;

int n;
vector<unsigned int> v;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = xorshift32() % 128;
    }

    WaveletMatrix<unsigned int, 32, BitVector> wm(v);

    for (int i = 0; i < n * n; i++) {
        int k = xorshift32() % n;
        int x = v[(xorshift32()) % n];

        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += (v[i] == x);

        if (cnt != wm.rank(x, k)) {
            cout << x << ' ' << k << ':' << "test failed" << endl;
            cout << cnt << ' ' << wm.rank(x, k) << endl;
        }
        assert(cnt == wm.rank(x, k));
    }
}