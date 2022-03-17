#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"
#include <algorithm>
#include <iostream>

#include "../../math/mod_binomial.hpp"

using namespace std;

int main() {
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    int h1 = abs(b1 - a1);
    int h2 = r - abs(b1 - a1);
    int w1 = abs(b2 - a2);
    int w2 = c - abs(b2 - a2);

    int h = min(h1, h2);
    int w = min(w1, w2);

    const int p = 100'000'007;
    auto ans = binomial<p>(h + w, h);
    if (h1 == h2) ans *= 2;
    if (w1 == w2) ans *= 2;

    cout << ans << endl;

    return 0;
}