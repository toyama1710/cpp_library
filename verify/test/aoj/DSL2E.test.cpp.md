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


# :heavy_check_mark: test/aoj/DSL2E.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL2E.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-02 04:49:03+00:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/segment_tree/dual_segment_tree.hpp.html">segment_tree/dual_segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <iostream>
#include "../../segment_tree/dual_segment_tree.hpp"
using namespace std;
using llong = long long;

struct RAQ {
    using value_type = long long;
    using T = value_type;

    inline static T identity() {
        return 0;
    };
    inline static T operation(T a, T b) {
        return a + b;
    };
};

int main() {
    llong n, q;
    llong com;
    llong s, t, x;
    llong idx;

    cin >> n >> q;
    DualSegmentTree<RAQ> seg(n);
    for (int i = 0; i < q; i++) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            s--;
            seg.update(s, t, x);
        }
        else if (com == 1) {
            cin >> idx;
            idx--;
            cout << seg[idx] << '\n';
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL2E.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <iostream>
#line 1 "segment_tree/dual_segment_tree.hpp"



#include <vector>
#include <cstdint>

//===
template<class Monoid>
struct DualSegmentTree {
    using T = typename Monoid::value_type;
    std::vector<T> lazy;

    DualSegmentTree() = default;
    explicit DualSegmentTree(uint32_t n):
        lazy(n << 1, Monoid::identity()) {};

    inline int size() {
        return (int)(lazy.size() >> 1);
    };
    
    inline void propagate(uint32_t k) {
        if (k >= size()) return;
        lazy[(k << 1) | 0] = Monoid::operation(lazy[(k << 1) | 0], lazy[k]);
        lazy[(k << 1) | 1] = Monoid::operation(lazy[(k << 1) | 1], lazy[k]);
        lazy[k] = Monoid::identity();
    };
    inline void push_down(uint32_t k) {
        for (uint32_t i = 31; i > 0; i--) propagate(k >> i);
    };
 
    // [l, r)
    void update(uint32_t l, uint32_t r, T op) {
        l += size();
        r += size();
        push_down(l);
        push_down(r - 1);
         
        while (l < r) {
            if (l & 1) lazy[l] = Monoid::operation(lazy[l], op), l++;
            if (r & 1) --r, lazy[r] = Monoid::operation(lazy[r], op);
 
            l >>= 1;
            r >>= 1;
        }
    };

    T get(uint32_t k) {
        k += size();
        push_down(k);
        return lazy[k];
    };
 
    T operator [] (uint32_t k) {
        return  get(k);
    };
};
//===


#line 4 "test/aoj/DSL2E.test.cpp"
using namespace std;
using llong = long long;

struct RAQ {
    using value_type = long long;
    using T = value_type;

    inline static T identity() {
        return 0;
    };
    inline static T operation(T a, T b) {
        return a + b;
    };
};

int main() {
    llong n, q;
    llong com;
    llong s, t, x;
    llong idx;

    cin >> n >> q;
    DualSegmentTree<RAQ> seg(n);
    for (int i = 0; i < q; i++) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> x;
            s--;
            seg.update(s, t, x);
        }
        else if (com == 1) {
            cin >> idx;
            idx--;
            cout << seg[idx] << '\n';
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

