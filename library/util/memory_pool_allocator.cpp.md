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


# :warning: util/memory_pool_allocator.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/memory_pool_allocator.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-11 02:18:30+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef MEMORY_POOL_ALLOCATOR_HPP
#define MEMORY_POOL_ALLOCATOR_HPP

#include <vector>
#include <cassert>
#include <numeric>
#include <cstdint>

//===

// for use: speed up tree (ex. persistent data structure)
template<class T>
struct MemoryPoolAllocator {
    std::vector<T *> addr;
    std::vector<char> mem;
    size_t ptr;

    MemoryPoolAllocator(size_t n) {
        ptr = 0;
        mem.resize(sizeof(T) * n);
        addr.resize(n);

        for (int i = 0; i < n; i++) {
            addr[i] = &(mem[i * sizeof(T)]);
        }
    };

    T *allocate(size_t n) {
        assert(n == 1);
        return addr[ptr++];
    };

    void deallocate(T *p, size_t n) {
        assert(n == 1);
        addr[--ptr] = p;
    };
};

//===
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/memory_pool_allocator.cpp"



#include <vector>
#include <cassert>
#include <numeric>
#include <cstdint>

//===

// for use: speed up tree (ex. persistent data structure)
template<class T>
struct MemoryPoolAllocator {
    std::vector<T *> addr;
    std::vector<char> mem;
    size_t ptr;

    MemoryPoolAllocator(size_t n) {
        ptr = 0;
        mem.resize(sizeof(T) * n);
        addr.resize(n);

        for (int i = 0; i < n; i++) {
            addr[i] = &(mem[i * sizeof(T)]);
        }
    };

    T *allocate(size_t n) {
        assert(n == 1);
        return addr[ptr++];
    };

    void deallocate(T *p, size_t n) {
        assert(n == 1);
        addr[--ptr] = p;
    };
};

//===


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

