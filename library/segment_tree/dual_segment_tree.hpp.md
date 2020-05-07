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


# :warning: segment_tree/dual_segment_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/dual_segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 12:11:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef DUAL_SEGMENT_TREE_HPP
#define DUAL_SEGMENT_TREE_HPP

#include <vector>

//===
template<class OperatorMonoid,
         class Merge = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> >
struct DualSegmentTree {
    int sz, height;
    const OperatorMonoid e;
    const Merge merge_operator;
    vector<OperatorMonoid> lazy;
 
    DualSegmentTree(OperatorMonoid e, const Merge &h):
        e(e), merge_operator(h) {};
    void init(int nmemb) {
        sz = nmemb;
        lazy.assign(sz << 1, e);

        height = -1;
        while (nmemb) nmemb >>= 1, height++;
    };
 
    inline void propagate(int k) {
        if (k >= sz || lazy[k] == e) return;
        lazy[(k << 1) | 0] = merge_operator(lazy[(k << 1) | 0], lazy[k]);
        lazy[(k << 1) | 1] = merge_operator(lazy[(k << 1) | 1], lazy[k]);
        lazy[k] = e;
    };
    void push_down(int k) {
        for (int i = height; i > 0; i--) {
            propagate(k >> i);
        }
    };
 
    // [l, r)
    void update(int l, int r, OperatorMonoid op) {
        l += sz; r += sz;
        push_down(l);
        push_down(r - 1);
         
        while (l < r) {
            if (l & 1) lazy[l] = merge_operator(lazy[l], op), l++;
            if (r & 1) --r, lazy[r] = merge_operator(lazy[r], op);
 
            l >>= 1;
            r >>= 1;
        }
    };
 
    OperatorMonoid operator [] (int k) {
        k += sz;
        push_down(k);
        return lazy[k];
    };
};
//===

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/dual_segment_tree.hpp"



#include <vector>

//===
template<class OperatorMonoid,
         class Merge = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> >
struct DualSegmentTree {
    int sz, height;
    const OperatorMonoid e;
    const Merge merge_operator;
    vector<OperatorMonoid> lazy;
 
    DualSegmentTree(OperatorMonoid e, const Merge &h):
        e(e), merge_operator(h) {};
    void init(int nmemb) {
        sz = nmemb;
        lazy.assign(sz << 1, e);

        height = -1;
        while (nmemb) nmemb >>= 1, height++;
    };
 
    inline void propagate(int k) {
        if (k >= sz || lazy[k] == e) return;
        lazy[(k << 1) | 0] = merge_operator(lazy[(k << 1) | 0], lazy[k]);
        lazy[(k << 1) | 1] = merge_operator(lazy[(k << 1) | 1], lazy[k]);
        lazy[k] = e;
    };
    void push_down(int k) {
        for (int i = height; i > 0; i--) {
            propagate(k >> i);
        }
    };
 
    // [l, r)
    void update(int l, int r, OperatorMonoid op) {
        l += sz; r += sz;
        push_down(l);
        push_down(r - 1);
         
        while (l < r) {
            if (l & 1) lazy[l] = merge_operator(lazy[l], op), l++;
            if (r & 1) --r, lazy[r] = merge_operator(lazy[r], op);
 
            l >>= 1;
            r >>= 1;
        }
    };
 
    OperatorMonoid operator [] (int k) {
        k += sz;
        push_down(k);
        return lazy[k];
    };
};
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

