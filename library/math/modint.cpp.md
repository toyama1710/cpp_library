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


# :warning: math/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-28 12:02:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
using namespace std;

//===
template<uint_fast64_t p>
struct ModInt {
    using uint = uint_fast64_t;
    uint d;

    ModInt(const uint x = 0):d((x % p + p) % p) {};
    
    ModInt operator + (const ModInt x) const noexcept {
        if (d + x.d >= p) return ModInt(d + x.d - p);
        else return ModInt(d + x.d);
    };
    ModInt operator - (const ModInt x) const noexcept {
        if (d - x.d < 0) return ModInt(d - x.d + p);
        else return ModInt(d - x.d);
    };
    ModInt operator * (ModInt x) const noexcept {
        return ModInt(d * x.d);
    }
    ModInt operator / (ModInt x) const noexcept {
        ModInt inv(1);
        uint exp = p - 2;
        while (exp) {
            if (exp & 1) inv *= x;
            x *= x, exp >>= 1;
        }

        return ModInt(d * inv.d);
    }

    ModInt &operator += (const ModInt x) noexcept {return *this = *this + x;};
    ModInt &operator -= (const ModInt x) noexcept {return *this = *this - x;};
    ModInt &operator *= (const ModInt x) noexcept {return *this = *this * x;};
    ModInt &operator /= (const ModInt x) noexcept {return *this = *this / x;};
    void operator ++ () noexcept {*this = *this + 1;};
    void operator ++ (int) noexcept {*this = *this + 1;};
    void operator -- () noexcept {*this = *this - 1;};
    void operator -- (int) noexcept {*this = *this - 1;};

    bool operator == (const ModInt x) noexcept {return d == x.d;};
    bool operator != (const ModInt x) noexcept {return d != x.d;};

    ModInt operator + (const uint x) const noexcept {return *this + ModInt(x);};
    ModInt operator - (const uint x) const noexcept {return *this - ModInt(x);};
    ModInt operator * (const uint x) const noexcept {return *this * ModInt(x);};
    ModInt operator / (const uint x) const noexcept {return *this / ModInt(x);};
    
    ModInt operator += (const uint x) noexcept {return *this = *this + x;};
    ModInt operator -= (const uint x) noexcept {return *this = *this - x;};
    ModInt operator *= (const uint x) noexcept {return *this = *this * x;};
    ModInt operator /= (const uint x) noexcept {return *this = *this / x;};
};
template<uint_fast64_t p>
ostream &operator << (ostream &stream, const ModInt<p> &mi) {
    return stream << mi.d;
};
template<uint_fast64_t p>
istream &operator >> (istream &stream, ModInt<p> &mi) {
    uint_fast64_t a;
    stream >> a;
    mi = ModInt<p>(a);
    return stream;
};
//===


// verify https://atcoder.jp/contests/jsc2019-qual/submissions/7199030
#define sum(X) ((X) * (X + 1) / 2)
using mint = ModInt<1'000'000'007>;
using ll = long long;

int main() {
    ll n, k;
    ll a[2005];
    mint ans;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; i++) {
        mint cnt(0);
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                cnt++;
            }
        }
 
        mint cnt2(0);
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                cnt2++;
            }
        }
 
        ans += cnt * k;
        ans += cnt2 * sum(k - 1);
    }
 
    cout << ans << endl;
 
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modint.cpp"
#include <iostream>
#include <cstdio>
using namespace std;

//===
template<uint_fast64_t p>
struct ModInt {
    using uint = uint_fast64_t;
    uint d;

    ModInt(const uint x = 0):d((x % p + p) % p) {};
    
    ModInt operator + (const ModInt x) const noexcept {
        if (d + x.d >= p) return ModInt(d + x.d - p);
        else return ModInt(d + x.d);
    };
    ModInt operator - (const ModInt x) const noexcept {
        if (d - x.d < 0) return ModInt(d - x.d + p);
        else return ModInt(d - x.d);
    };
    ModInt operator * (ModInt x) const noexcept {
        return ModInt(d * x.d);
    }
    ModInt operator / (ModInt x) const noexcept {
        ModInt inv(1);
        uint exp = p - 2;
        while (exp) {
            if (exp & 1) inv *= x;
            x *= x, exp >>= 1;
        }

        return ModInt(d * inv.d);
    }

    ModInt &operator += (const ModInt x) noexcept {return *this = *this + x;};
    ModInt &operator -= (const ModInt x) noexcept {return *this = *this - x;};
    ModInt &operator *= (const ModInt x) noexcept {return *this = *this * x;};
    ModInt &operator /= (const ModInt x) noexcept {return *this = *this / x;};
    void operator ++ () noexcept {*this = *this + 1;};
    void operator ++ (int) noexcept {*this = *this + 1;};
    void operator -- () noexcept {*this = *this - 1;};
    void operator -- (int) noexcept {*this = *this - 1;};

    bool operator == (const ModInt x) noexcept {return d == x.d;};
    bool operator != (const ModInt x) noexcept {return d != x.d;};

    ModInt operator + (const uint x) const noexcept {return *this + ModInt(x);};
    ModInt operator - (const uint x) const noexcept {return *this - ModInt(x);};
    ModInt operator * (const uint x) const noexcept {return *this * ModInt(x);};
    ModInt operator / (const uint x) const noexcept {return *this / ModInt(x);};
    
    ModInt operator += (const uint x) noexcept {return *this = *this + x;};
    ModInt operator -= (const uint x) noexcept {return *this = *this - x;};
    ModInt operator *= (const uint x) noexcept {return *this = *this * x;};
    ModInt operator /= (const uint x) noexcept {return *this = *this / x;};
};
template<uint_fast64_t p>
ostream &operator << (ostream &stream, const ModInt<p> &mi) {
    return stream << mi.d;
};
template<uint_fast64_t p>
istream &operator >> (istream &stream, ModInt<p> &mi) {
    uint_fast64_t a;
    stream >> a;
    mi = ModInt<p>(a);
    return stream;
};
//===


// verify https://atcoder.jp/contests/jsc2019-qual/submissions/7199030
#define sum(X) ((X) * (X + 1) / 2)
using mint = ModInt<1'000'000'007>;
using ll = long long;

int main() {
    ll n, k;
    ll a[2005];
    mint ans;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; i++) {
        mint cnt(0);
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                cnt++;
            }
        }
 
        mint cnt2(0);
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) {
                cnt2++;
            }
        }
 
        ans += cnt * k;
        ans += cnt2 * sum(k - 1);
    }
 
    cout << ans << endl;
 
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

