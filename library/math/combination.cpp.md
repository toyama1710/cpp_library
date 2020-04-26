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


# :warning: math/combination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/combination.cpp">View this file on GitHub</a>
    - Last commit date: 2019-08-30 14:47:15+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
using namespace std;

//===
// nCr mod p
// p is prime
// 1 <= k <= n <= 1e7

void init_comb(long long modulus);
void init_comb(void);
long long combination(long long n, long long k);
long long pow_mod(long long n, long long m);

long long _modulus = (long long)1e9 + 7;
long long fact[10000007];
long long fact_inv[10000007];

void init_comb(long long modulus) {_modulus = modulus; }
void init_comb(void) {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    for (int i = 2; i <= 10000000; i++) {
        fact[i] = fact[i - 1] * i % _modulus;
        fact_inv[i] = pow_mod(fact[i], _modulus - 2);
    }
}

long long combination(long long n, long long k) {
    static long long f;

    if (f != _modulus) f = _modulus, init_comb();

    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fact[n] * (fact_inv[k] * fact_inv[n - k] % _modulus) % _modulus;
}

long long pow_mod(long long n, long long m) {
    //n ** m;
    long long ret = 1;

    while (m) {
        if (m & 1) {
            ret = ret * n % _modulus;
        }

        n = n * n % _modulus;
        m = m >> 1;
    }

    return ret;
}
//===

int main() {
    long long mod;
    long long n, r;

    printf("mod: ");
    scanf("%lld", &mod);
    init_comb(mod);

    while (printf("nCr: "), scanf("%lld %lld", &n, &r), n != -1 && r != -1) {
        printf("%lld\n", combination(n, r));
    }
    
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/combination.cpp"
#include <iostream>
#include <cstdio>
using namespace std;

//===
// nCr mod p
// p is prime
// 1 <= k <= n <= 1e7

void init_comb(long long modulus);
void init_comb(void);
long long combination(long long n, long long k);
long long pow_mod(long long n, long long m);

long long _modulus = (long long)1e9 + 7;
long long fact[10000007];
long long fact_inv[10000007];

void init_comb(long long modulus) {_modulus = modulus; }
void init_comb(void) {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    for (int i = 2; i <= 10000000; i++) {
        fact[i] = fact[i - 1] * i % _modulus;
        fact_inv[i] = pow_mod(fact[i], _modulus - 2);
    }
}

long long combination(long long n, long long k) {
    static long long f;

    if (f != _modulus) f = _modulus, init_comb();

    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fact[n] * (fact_inv[k] * fact_inv[n - k] % _modulus) % _modulus;
}

long long pow_mod(long long n, long long m) {
    //n ** m;
    long long ret = 1;

    while (m) {
        if (m & 1) {
            ret = ret * n % _modulus;
        }

        n = n * n % _modulus;
        m = m >> 1;
    }

    return ret;
}
//===

int main() {
    long long mod;
    long long n, r;

    printf("mod: ");
    scanf("%lld", &mod);
    init_comb(mod);

    while (printf("nCr: "), scanf("%lld %lld", &n, &r), n != -1 && r != -1) {
        printf("%lld\n", combination(n, r));
    }
    
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

