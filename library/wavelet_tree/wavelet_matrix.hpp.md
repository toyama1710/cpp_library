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
    - Last commit date: 2020-07-24 16:41:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef WAVELET_MATRIX_HPP
#define WAVELET_MATRIX_HPP

// T = integer type
// LOG = number of bit
// FID = FullyIndexableDictionary
template<class T, int LOG, class FID>
class WaveletMatrix {
    int len;
    FID bits[LOG];
    int zero_cnt[LOG];

    WaveletMatrix(vector<T> data) {
        len = data.size();
        std::vector<T> ls(len), rs(len);
        int p = 0, q = 0;

        for (int depth = 0; depth < LOG; depth++) {
            bits[depth] = FID(len);
            for (int i = 0; i < len; i++) {
                if ((data[i] >> (LOG - depth - 1)) & 1)) {
                    bits[depth].set(i);
                    rs[q++] = data[i];
                }
                else {
                    ls[p++] = data[i];
                }
            }
        }
        zero_cnt[depth] = p;
        bits[depth].build();
        data.clear();
        swap(data, ls);
        for (int i = 0; i < q; i++) {
            data[i + p] = rs[i];
        }
    };
};

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "wavelet_tree/wavelet_matrix.hpp"



// T = integer type
// LOG = number of bit
// FID = FullyIndexableDictionary
template<class T, int LOG, class FID>
class WaveletMatrix {
    int len;
    FID bits[LOG];
    int zero_cnt[LOG];

    WaveletMatrix(vector<T> data) {
        len = data.size();
        std::vector<T> ls(len), rs(len);
        int p = 0, q = 0;

        for (int depth = 0; depth < LOG; depth++) {
            bits[depth] = FID(len);
            for (int i = 0; i < len; i++) {
                if ((data[i] >> (LOG - depth - 1)) & 1)) {
                    bits[depth].set(i);
                    rs[q++] = data[i];
                }
                else {
                    ls[p++] = data[i];
                }
            }
        }
        zero_cnt[depth] = p;
        bits[depth].build();
        data.clear();
        swap(data, ls);
        for (int i = 0; i < q; i++) {
            data[i + p] = rs[i];
        }
    };
};



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

