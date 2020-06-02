---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/static_rmq.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/static_rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 08:32:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_type/min_monoid.hpp.html">data_type/min_monoid.hpp</a>
* :heavy_check_mark: <a href="../../../library/sparse_table/sparse_table.hpp.html">sparse_table/sparse_table.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include "../../sparse_table/sparse_table.hpp"
#include "../../data_type/min_monoid.hpp"
using namespace std;
using llong = long long;

llong n, q;
vector<llong> a;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (auto &v:a) cin >> v;

    SparseTable<MinMonoid<llong>> rmq(a.begin(), a.end());
    
    while (q--) {
        llong l, r;
        cin >> l >> r;
        cout << rmq.fold(l, r) << '\n';
    }

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/static_rmq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#line 1 "sparse_table/sparse_table.hpp"



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


#line 1 "data_type/min_monoid.hpp"



#include <numeric>
#include <algorithm>

//===
template<class T>
struct MinMonoid {
    using value_type = T;
    inline static T identity() {
        return std::numeric_limits<T>::max();
    };
    inline static T operation(const T a, const T b) {
        return std::min(a, b);
    };
};
//===


#line 6 "test/yosupo/static_rmq.test.cpp"
using namespace std;
using llong = long long;

llong n, q;
vector<llong> a;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (auto &v:a) cin >> v;

    SparseTable<MinMonoid<llong>> rmq(a.begin(), a.end());
    
    while (q--) {
        llong l, r;
        cin >> l >> r;
        cout << rmq.fold(l, r) << '\n';
    }

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

