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


# :warning: test/ws/wm_rank.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#371cfd9101dedf155cc0c947ec787865">test/ws</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/ws/wm_rank.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 00:50:00+09:00




## Depends on

* :warning: <a href="../../bit/pop_count.hpp.html">bit/pop_count.hpp</a>
* :warning: <a href="../../compact_data_structure/bit_vector.hpp.html">compact_data_structure/bit_vector.hpp</a>
* :warning: <a href="../../util/xorshift.hpp.html">util/xorshift.hpp</a>
* :warning: <a href="../../wavelet_tree/wavelet_matrix.hpp.html">wavelet_tree/wavelet_matrix.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdint>
#include <ctime>
#include <vector>
#include <cassert>
#include "../../compact_data_structure/bit_vector.hpp"
#include "../../wavelet_tree/wavelet_matrix.hpp"
#include "../../util/xorshift.hpp"
using namespace std;

int n;
vector<unsigned int> v;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = xorshift32() % 128;
    }

    WaveletMatrix<unsigned int, 32, BitVector> wm(v);

    for (int i = 0; i < n * n; i++) {
        int k = xorshift32() % n;
        int x = v[(xorshift32()) % n];

        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += (v[i] == x);

        if (cnt != wm.rank(x, k)) {
            cout << x << ' ' << k << ':' << "test failed" << endl;
            cout << cnt << ' ' << wm.rank(x, k) << endl;
        }
        assert(cnt == wm.rank(x, k));
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/ws/wm_rank.cpp"
#include <iostream>
#include <cstdint>
#include <ctime>
#include <vector>
#include <cassert>
#line 1 "compact_data_structure/bit_vector.hpp"



#line 6 "compact_data_structure/bit_vector.hpp"
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

    bool operator[] (int k) {
        return bool((bit[k / 32] >> (k & 31)) & 1);
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
        popcnt32(bit[k / 32] & ~((~0u) << (k & 31)));
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


#line 1 "wavelet_tree/wavelet_matrix.hpp"



#line 5 "wavelet_tree/wavelet_matrix.hpp"

// T = integer type
// LOG = bit size
// FID = FullyIndexableDictionary
template<class T, int LOG, class FID>
struct WaveletMatrix {
    int len;
    FID bits[LOG];

    WaveletMatrix() = default;
    WaveletMatrix(std::vector<T> data) {
        len = data.size();
        std::vector<T> ls(len), rs(len);
        int p = 0, q = 0;

        for (int depth = 0; depth < LOG; depth++) {
            p = q = 0;
            bits[depth] = FID(len);
            for (int i = 0; i < len; i++) {
                if ((data[i] >> (LOG - depth - 1)) & 1) {
                    bits[depth].set(i);
                    rs[q++] = data[i];
                }
                else {
                    ls[p++] = data[i];
                }
            }
            bits[depth].build();
            data.clear();
            swap(data, ls);
            for (int i = 0; i < q; i++) {
                data[i + p] = rs[i];
            }
        }
    };

    int access(int k) {
        int ret = 0;
        for (int depth = 0; depth < LOG; depth++) {
            ret <<= 1;
            ret |= bits[depth][k];
            if (bits[depth][k]) {
                k = bits[depth].rank0(len) + bits[depth].rank1(k);
            }
            else {
                k = bits[depth].rank0(k);
            }
        }
        return ret;
    };

    // count v in [0, k)
    int rank(T v, int k) {
        int l = 0;
        int r = k;
        for (int depth = 0; depth < LOG; depth++) {
            int bit = (v >> (LOG - depth - 1)) & 1;
            if (bit) {
                int b = bits[depth].rank0(len);
                l = b + bits[depth].rank1(l);
                r = b + bits[depth].rank1(r);
            }
            else {
                l = bits[depth].rank0(l);
                r = bits[depth].rank0(r);
            }
        }
        return r - l;
    };
};


#line 4 "util/xorshift.hpp"

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
#line 9 "test/ws/wm_rank.cpp"
using namespace std;

int n;
vector<unsigned int> v;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = xorshift32() % 128;
    }

    WaveletMatrix<unsigned int, 32, BitVector> wm(v);

    for (int i = 0; i < n * n; i++) {
        int k = xorshift32() % n;
        int x = v[(xorshift32()) % n];

        int cnt = 0;
        for (int i = 0; i < k; i++) cnt += (v[i] == x);

        if (cnt != wm.rank(x, k)) {
            cout << x << ' ' << k << ':' << "test failed" << endl;
            cout << cnt << ' ' << wm.rank(x, k) << endl;
        }
        assert(cnt == wm.rank(x, k));
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

