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


# :heavy_check_mark: string/rolling_hash.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/rolling_hash.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-07 16:40:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2444_2.test.cpp.html">test/aoj/2444_2.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef ROLLING_HASH_HPP
#define ROLLING_HASH_HPP

#include <cstdint>

//===
//#include <cstdint>
template <uint64_t base, uint64_t mod>
struct RollingHash {
    const std::string s;
    const int len;
    std::vector<uint64_t> hashed, power;

    RollingHash (const std::string &s):s(s), len(s.size()) {
        hashed.assign(len + 1, 0);
        power.assign(len + 1, 1);

        for (int i = 0; i < len; i++) {
            hashed[i + 1] = (hashed[i] * base + s[i]) % mod;
            power[i + 1] = power[i] * base % mod;
        }
    };

    // s[l, r)
    uint64_t get_hash(int l, int r) {
        uint64_t res = hashed[r] + mod - hashed[l] * power[r - l] % mod;
        if (res >= mod) res -= mod;
        return res;
    };
};

template<uint64_t base>
struct RollingHash<base, (1ull << 61ull) - 1ull> {
    const std::string s;
    const int len;
    const uint64_t mask30 = (1ull << 30ull) - 1ull;
    const uint64_t mask31 = (1ull << 31ull) - 1ull;
    const uint64_t mod = (1ull << 61ull) - 1ull;
    std::vector<uint64_t> hashed, power;

    RollingHash (const std::string &s):s(s), len(s.size()) {
        hashed.assign(len + 1, 0);
        power.assign(len + 1, 1);

        for (int i = 0; i < len; i++) {
            hashed[i + 1] = calc_mod(mul(hashed[i], base) + s[i]);
            power[i + 1] = calc_mod(mul(power[i], base));
        }
    };

    // s[l, r)
    uint64_t get_hash(int l, int r) {
        uint64_t res = hashed[r] + mod - calc_mod(mul(hashed[l], power[r - l]));
        if (res >= mod) res -= mod;
        return res;
    };

    inline uint64_t mul(uint64_t l, uint64_t r) {
        uint64_t lu = l >> 31;
        uint64_t ld = l & mask31;
        uint64_t ru = r >> 31;
        uint64_t rd = r & mask31;
        uint64_t mid = ld * ru + lu * rd;

        return ((lu * ru) << 1) +
            (mid >> 30) + ((mid & mask30) << 31)
            + ld * rd;
    };

    inline uint64_t calc_mod(uint64_t v) {
        v = (v & mod) + (v >> 61);
        if (v >= mod) v -= mod;
        return v;
    };
};

template<uint64_t base>
using MRollingHash = RollingHash<base, (1ull << 61ull) - 1ull>;
//===

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/rolling_hash.hpp"



#include <cstdint>

//===
//#include <cstdint>
template <uint64_t base, uint64_t mod>
struct RollingHash {
    const std::string s;
    const int len;
    std::vector<uint64_t> hashed, power;

    RollingHash (const std::string &s):s(s), len(s.size()) {
        hashed.assign(len + 1, 0);
        power.assign(len + 1, 1);

        for (int i = 0; i < len; i++) {
            hashed[i + 1] = (hashed[i] * base + s[i]) % mod;
            power[i + 1] = power[i] * base % mod;
        }
    };

    // s[l, r)
    uint64_t get_hash(int l, int r) {
        uint64_t res = hashed[r] + mod - hashed[l] * power[r - l] % mod;
        if (res >= mod) res -= mod;
        return res;
    };
};

template<uint64_t base>
struct RollingHash<base, (1ull << 61ull) - 1ull> {
    const std::string s;
    const int len;
    const uint64_t mask30 = (1ull << 30ull) - 1ull;
    const uint64_t mask31 = (1ull << 31ull) - 1ull;
    const uint64_t mod = (1ull << 61ull) - 1ull;
    std::vector<uint64_t> hashed, power;

    RollingHash (const std::string &s):s(s), len(s.size()) {
        hashed.assign(len + 1, 0);
        power.assign(len + 1, 1);

        for (int i = 0; i < len; i++) {
            hashed[i + 1] = calc_mod(mul(hashed[i], base) + s[i]);
            power[i + 1] = calc_mod(mul(power[i], base));
        }
    };

    // s[l, r)
    uint64_t get_hash(int l, int r) {
        uint64_t res = hashed[r] + mod - calc_mod(mul(hashed[l], power[r - l]));
        if (res >= mod) res -= mod;
        return res;
    };

    inline uint64_t mul(uint64_t l, uint64_t r) {
        uint64_t lu = l >> 31;
        uint64_t ld = l & mask31;
        uint64_t ru = r >> 31;
        uint64_t rd = r & mask31;
        uint64_t mid = ld * ru + lu * rd;

        return ((lu * ru) << 1) +
            (mid >> 30) + ((mid & mask30) << 31)
            + ld * rd;
    };

    inline uint64_t calc_mod(uint64_t v) {
        v = (v & mod) + (v >> 61);
        if (v >= mod) v -= mod;
        return v;
    };
};

template<uint64_t base>
using MRollingHash = RollingHash<base, (1ull << 61ull) - 1ull>;
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

