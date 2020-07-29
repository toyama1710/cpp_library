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


# :warning: bit/pop_count.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f67169dfbf72c4ca285e9ee12e3e9ac5">bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/bit/pop_count.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-23 12:06:47+09:00




## Required by

* :warning: <a href="../compact_data_structure/bit_vector.hpp.html">compact_data_structure/bit_vector.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef POP_COUNT_HPP
#define POP_COUNT_HPP

#include <cstdint>

//===
int popcnt64(uint64_t bits) {
#ifdef __has_builtin
    return __builtin_popcountll(bits);
#else
    bits = (bits & 0x5555555555555555) + (bits >> 1  & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2  & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4  & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8  & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
    return bits;
#endif
}
int popcnt32(uint32_t bits) {
#ifdef __has_builtin
    return __builtin_popcount(bits);
#else
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    bits = (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
    return bits;
#endif
}
//===

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "bit/pop_count.hpp"



#include <cstdint>

//===
int popcnt64(uint64_t bits) {
#ifdef __has_builtin
    return __builtin_popcountll(bits);
#else
    bits = (bits & 0x5555555555555555) + (bits >> 1  & 0x5555555555555555);
    bits = (bits & 0x3333333333333333) + (bits >> 2  & 0x3333333333333333);
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4  & 0x0f0f0f0f0f0f0f0f);
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8  & 0x00ff00ff00ff00ff);
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);
    bits = (bits & 0x00000000ffffffff) + (bits >> 32 & 0x00000000ffffffff);
    return bits;
#endif
}
int popcnt32(uint32_t bits) {
#ifdef __has_builtin
    return __builtin_popcount(bits);
#else
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    bits = (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
    return bits;
#endif
}
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

