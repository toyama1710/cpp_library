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


# :heavy_check_mark: segment_tree/segment_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-04 15:40:53+00:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL2A.test.cpp.html">test/aoj/DSL2A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>
#include <functional>
#include <iterator>

//===
template<typename Monoid, typename OP = std::function<Monoid(Monoid, Monoid)> >
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    std::vector<Monoid> tree;
    const int size;
    const Monoid e; // neutral element
    const OP merge_monoid; // bin' operation

    SegmentTree (const Monoid &e, const OP &f, int nmemb):
        e(e), merge_monoid(f), size(nmemb)
    {
        tree.assign(size << 1, e);
    };

    template<class InputIterator>
    SegmentTree(const Monoid &e, const OP &f,
                InputIterator first, InputIterator last):
        e(e), merge_monoid(f), size(std::distance(first, last))
    {
        tree.assign(size << 1, e);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/segment_tree.hpp"



#include <vector>
#include <functional>
#include <iterator>

//===
template<typename Monoid, typename OP = std::function<Monoid(Monoid, Monoid)> >
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    std::vector<Monoid> tree;
    const int size;
    const Monoid e; // neutral element
    const OP merge_monoid; // bin' operation

    SegmentTree (const Monoid &e, const OP &f, int nmemb):
        e(e), merge_monoid(f), size(nmemb)
    {
        tree.assign(size << 1, e);
    };

    template<class InputIterator>
    SegmentTree(const Monoid &e, const OP &f,
                InputIterator first, InputIterator last):
        e(e), merge_monoid(f), size(std::distance(first, last))
    {
        tree.assign(size << 1, e);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

