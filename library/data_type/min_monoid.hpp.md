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


# :heavy_check_mark: data_type/min_monoid.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#17f71d965fe9589ddbd11caf7182243e">data_type</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_type/min_monoid.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 13:11:31+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL2A.test.cpp.html">test/aoj/DSL2A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef MIN_MONOID_HPP
#define MIN_MONOID_HPP

#include <numeric>
#include <algorithm>

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

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_type/min_monoid.hpp"



#include <numeric>
#include <algorithm>

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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

