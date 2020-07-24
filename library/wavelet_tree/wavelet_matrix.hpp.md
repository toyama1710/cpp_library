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


# :warning: wavelet_tree/wavelet_matrix.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#2e27b575d470dfe6774b874d3fb14827">wavelet_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/wavelet_tree/wavelet_matrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 00:50:00+09:00




## Required by

* :warning: <a href="../test/ws/wm_rank.cpp.html">test/ws/wm_rank.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef WAVELET_MATRIX_HPP
#define WAVELET_MATRIX_HPP

#include <vector>

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

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "wavelet_tree/wavelet_matrix.hpp"



#include <vector>

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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

