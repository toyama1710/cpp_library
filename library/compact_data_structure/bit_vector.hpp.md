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


# :warning: compact_data_structure/bit_vector.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5f15b424ad8b963fc9e5594111bd69bf">compact_data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/compact_data_structure/bit_vector.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-23 13:07:35+09:00




## Depends on

* :warning: <a href="../bit/pop_count.hpp.html">bit/pop_count.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef BIT_VECTOR_HPP
#define BIT_VECTOR_HPP

#include <cstdint>
#include <vector>
#include <string>
#include "../bit/pop_count.hpp"

struct BitVector {
    using u64 = uint64_t;
    using u32 = uint32_t;
    using u8 = uint8_t;

    std::vector<u32> bit;
    std::vector<u32> chunk;

    BitVector() = default;
    explicit BitVector(int len) : bit((len + 31) / 32, 0), chunk((len + 31) / 32, 0){};
    BitVector(std::vector<bool> v) : bit((v.size() + 31) / 32, 0), chunk((v.size() + 31) / 32, 0) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) set(i);
        }
    };
    BitVector(std::string s) : bit((s.size() + 31) / 32, 0), chunk((s.size() + 31) / 32, 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') set(i);
        }
    };

    void set(int k) {
        bit[k / 32] |= 1u << (k & 31);
    };
    void build() {
        for (int i = 1; i < size(); i++) {
            chunk[i] = chunk[i - 1] + popcnt32(bit[i - 1]);
        }
    };

    int size() {
        return bit.size();
    };

    // count number of 1 in [0, k)
    int rank1(int k) {
        return chunk[k / 32] +
        popcnt32(bit[k / 32] & (~0) >> (k & 31));
    };
    // count number of 0 in [0, k)
    int rank0(int k) {
        return k - rank1(k);
    };
    int select1(int k) {
        int l = 0;
        int r = size();
        int m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            if (rank1(m) >= k) r = m;
            else l = m;
        }
        return r - 1;
    };
    int select0(int k) {
        int l = 0;
        int r = size();
        int m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            if (rank0(m) >= k) r = m;
            else l = m;
        }
        return r - 1;
    };
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "compact_data_structure/bit_vector.hpp"



#include <cstdint>
#include <vector>
#include <string>
#line 1 "bit/pop_count.hpp"



#line 5 "bit/pop_count.hpp"

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


#line 8 "compact_data_structure/bit_vector.hpp"

struct BitVector {
    using u64 = uint64_t;
    using u32 = uint32_t;
    using u8 = uint8_t;

    std::vector<u32> bit;
    std::vector<u32> chunk;

    BitVector() = default;
    explicit BitVector(int len) : bit((len + 31) / 32, 0), chunk((len + 31) / 32, 0){};
    BitVector(std::vector<bool> v) : bit((v.size() + 31) / 32, 0), chunk((v.size() + 31) / 32, 0) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) set(i);
        }
    };
    BitVector(std::string s) : bit((s.size() + 31) / 32, 0), chunk((s.size() + 31) / 32, 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') set(i);
        }
    };

    void set(int k) {
        bit[k / 32] |= 1u << (k & 31);
    };
    void build() {
        for (int i = 1; i < size(); i++) {
            chunk[i] = chunk[i - 1] + popcnt32(bit[i - 1]);
        }
    };

    int size() {
        return bit.size();
    };

    // count number of 1 in [0, k)
    int rank1(int k) {
        return chunk[k / 32] +
        popcnt32(bit[k / 32] & (~0) >> (k & 31));
    };
    // count number of 0 in [0, k)
    int rank0(int k) {
        return k - rank1(k);
    };
    int select1(int k) {
        int l = 0;
        int r = size();
        int m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            if (rank1(m) >= k) r = m;
            else l = m;
        }
        return r - 1;
    };
    int select0(int k) {
        int l = 0;
        int r = size();
        int m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            if (rank0(m) >= k) r = m;
            else l = m;
        }
        return r - 1;
    };
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

