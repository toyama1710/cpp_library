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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: segment_tree/fenwick_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-15 21:13:04+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//===
inline size_t get_lsb(size_t bits) {
    return  bits & ((~bits) + 1);
};

// ATTENTION!! 1-indexed
template<class T>
struct FenwickTree {
    vector<T> data;
    const size_t size;

    FenwickTree(size_t nmemb): data(nmemb + 1, 0), size(nmemb) {};
    
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
        }
        else if (com == 1) {
            if (x == 1) cout << sum.prefix_sum(y) << endl;
            else cout << sum.prefix_sum(y) - sum.prefix_sum(x - 1) << endl;
        }
    }

    return 0;
}

int main() {
    AOJ_DSL2B();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/fenwick_tree.cpp"
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//===
inline size_t get_lsb(size_t bits) {
    return  bits & ((~bits) + 1);
};

// ATTENTION!! 1-indexed
template<class T>
struct FenwickTree {
    vector<T> data;
    const size_t size;

    FenwickTree(size_t nmemb): data(nmemb + 1, 0), size(nmemb) {};
    
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
        }
        else if (com == 1) {
            if (x == 1) cout << sum.prefix_sum(y) << endl;
            else cout << sum.prefix_sum(y) - sum.prefix_sum(x - 1) << endl;
        }
    }

    return 0;
}

int main() {
    AOJ_DSL2B();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

