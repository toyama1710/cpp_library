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


# :heavy_check_mark: test/yosupo/static_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/static_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 02:29:37+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :question: <a href="../../../library/bit/msb.hpp.html">bit/msb.hpp</a>
* :heavy_check_mark: <a href="../../../library/sparse_table/disjoint_sparse_table.hpp.html">sparse_table/disjoint_sparse_table.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <iostream>
#include "../../sparse_table/disjoint_sparse_table.hpp"
using namespace std;
using llong = long long;

struct Sum {
    using T = llong;
    using value_type = T;

    inline static T operation(T x, T y) {
        return x + y;
    };
};

llong n, q;
vector<llong> a;
DisjointSparseTable<Sum> dst;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (auto &v:a) cin >> v;

    dst.build(a.begin(), a.end());

    while (q--) {
        llong l, r;
        cin >> l >> r;
        cout << dst.fold(l, r) << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/static_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <iostream>
#line 1 "sparse_table/disjoint_sparse_table.hpp"



#include <cassert>
#include <vector>
#line 1 "bit/msb.hpp"



#include <cstdint>

inline int msb32(uint32_t x) {
        if (x == 0) return -1;
#ifndef __has_builtin
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

inline int msb64(uint64_t x) {
    if (x == 0) return -1;

    #ifndef __has_builtin
        int r = 0;
        if (x >> 32) x >>= 32, r |= 32;
        if (x >> 16) x >>= 16, r |= 16;
        if (x >> 8) x >>= 8, r |= 8;
        if (x >> 4) x >>= 4, r |= 4;
        if (x >> 2) x >>= 2, r |= 2;
        return r | (x >> 1);
#else
    return 63 - __builtin_clzll(x);
#endif
};


#line 8 "sparse_table/disjoint_sparse_table.hpp"

//===
template <class SemiGroup>
struct DisjointSparseTable {
    using T = typename SemiGroup::value_type;
    using G = SemiGroup;

    std::vector<std::vector<T>> table;

    DisjointSparseTable() = default;
    template<class InputItr>
    DisjointSparseTable(InputItr first, InputItr last) {
        build(first, last);
    };

    template<class InputItr>
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

        if (x == 0) return table[0][l];
        else return G::operation(table[msb32(x)][l], table[msb32(x)][r]);
    };
    T fold(int l, int r, SemiGroup e) {
        if (l >= r) return e;
        return fold(l, r);
    };

    int size() {
        return table[0].size();
    };
    const T operator [] (int k) {
        return fold(k, k + 1);
    };
};
//===

#line 4 "test/yosupo/static_range_sum.test.cpp"
using namespace std;
using llong = long long;

struct Sum {
    using T = llong;
    using value_type = T;

    inline static T operation(T x, T y) {
        return x + y;
    };
};

llong n, q;
vector<llong> a;
DisjointSparseTable<Sum> dst;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (auto &v:a) cin >> v;

    dst.build(a.begin(), a.end());

    while (q--) {
        llong l, r;
        cin >> l >> r;
        cout << dst.fold(l, r) << '\n';
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

