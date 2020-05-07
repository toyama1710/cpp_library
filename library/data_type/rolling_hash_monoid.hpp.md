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


# :x: data_type/rolling_hash_monoid.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#17f71d965fe9589ddbd11caf7182243e">data_type</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_type/rolling_hash_monoid.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 15:27:24+09:00




## Verified with

* :x: <a href="../../verify/test/aoj/2444.test.cpp.html">test/aoj/2444.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef ROLLING_HASH_MONOID_HPP
#define ROLLING_HASH_MONOID_HPP

#include <vector>

//===
template<unsigned long long base, unsigned long long mod>
struct RollingHashMonoid {
    using ull = unsigned long long;

    struct Str {
        ull hash = 0;
        ull len = 0;

        Str() = default;
        Str (char ch) {
            hash = ch % mod;
            len = 1;
        };
    };
    using value_type = Str;

    static std::vector<ull> pow_table;
    inline static Str identity() {
        return Str();
    };
    inline static Str operation(const Str a, const Str b) {
        Str ret;
        ret.hash = a.hash * power(b.len) % mod + b.hash % mod;
        ret.len = a.len + b.len;
        return ret;
    };

    inline static ull power(ull n) {
        while (pow_table.size() <= n) pow_table.push_back(pow_table.back() * base % mod);
        return pow_table[n];
    };
};
template<unsigned long long base, unsigned long long mod>
std::vector<unsigned long long> RollingHashMonoid<base, mod>::pow_table(1, 1);
//===
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_type/rolling_hash_monoid.hpp"



#include <vector>

//===
template<unsigned long long base, unsigned long long mod>
struct RollingHashMonoid {
    using ull = unsigned long long;

    struct Str {
        ull hash = 0;
        ull len = 0;

        Str() = default;
        Str (char ch) {
            hash = ch % mod;
            len = 1;
        };
    };
    using value_type = Str;

    static std::vector<ull> pow_table;
    inline static Str identity() {
        return Str();
    };
    inline static Str operation(const Str a, const Str b) {
        Str ret;
        ret.hash = a.hash * power(b.len) % mod + b.hash % mod;
        ret.len = a.len + b.len;
        return ret;
    };

    inline static ull power(ull n) {
        while (pow_table.size() <= n) pow_table.push_back(pow_table.back() * base % mod);
        return pow_table[n];
    };
};
template<unsigned long long base, unsigned long long mod>
std::vector<unsigned long long> RollingHashMonoid<base, mod>::pow_table(1, 1);
//===


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

