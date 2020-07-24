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


# :warning: util/xorshift.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/xorshift.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 00:09:57+09:00




## Required by

* :warning: <a href="../test/ws/wm_rank.cpp.html">test/ws/wm_rank.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdint>
#include <ctime>

//===
static uint32_t __seed__ = 1710;
uint32_t xorshift32() {
    __seed__ = __seed__ ^ (__seed__ << 13);
    __seed__ = __seed__ ^ (__seed__ >> 17);
    __seed__ = __seed__ ^ (__seed__ << 5);
    return __seed__;
}
void set_seed(uint32_t s) {
    __seed__ = s;
};
//===
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/xorshift.hpp"
#include <iostream>
#include <cstdint>
#include <ctime>

//===
static uint32_t __seed__ = 1710;
uint32_t xorshift32() {
    __seed__ = __seed__ ^ (__seed__ << 13);
    __seed__ = __seed__ ^ (__seed__ >> 17);
    __seed__ = __seed__ ^ (__seed__ << 5);
    return __seed__;
}
void set_seed(uint32_t s) {
    __seed__ = s;
};
//===

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

