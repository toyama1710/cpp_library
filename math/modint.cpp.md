---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/jsc2019-qual/submissions/7199030
  bundledCode: "#line 1 \"math/modint.cpp\"\n#include <iostream>\n#include <cstdio>\n\
    using namespace std;\n\n//===\ntemplate<uint_fast64_t p>\nstruct ModInt {\n  \
    \  using uint = uint_fast64_t;\n    uint d;\n\n    ModInt(const uint x = 0):d((x\
    \ % p + p) % p) {};\n    \n    ModInt operator + (const ModInt x) const noexcept\
    \ {\n        if (d + x.d >= p) return ModInt(d + x.d - p);\n        else return\
    \ ModInt(d + x.d);\n    };\n    ModInt operator - (const ModInt x) const noexcept\
    \ {\n        if (d - x.d < 0) return ModInt(d - x.d + p);\n        else return\
    \ ModInt(d - x.d);\n    };\n    ModInt operator * (ModInt x) const noexcept {\n\
    \        return ModInt(d * x.d);\n    }\n    ModInt operator / (ModInt x) const\
    \ noexcept {\n        ModInt inv(1);\n        uint exp = p - 2;\n        while\
    \ (exp) {\n            if (exp & 1) inv *= x;\n            x *= x, exp >>= 1;\n\
    \        }\n\n        return ModInt(d * inv.d);\n    }\n\n    ModInt &operator\
    \ += (const ModInt x) noexcept {return *this = *this + x;};\n    ModInt &operator\
    \ -= (const ModInt x) noexcept {return *this = *this - x;};\n    ModInt &operator\
    \ *= (const ModInt x) noexcept {return *this = *this * x;};\n    ModInt &operator\
    \ /= (const ModInt x) noexcept {return *this = *this / x;};\n    void operator\
    \ ++ () noexcept {*this = *this + 1;};\n    void operator ++ (int) noexcept {*this\
    \ = *this + 1;};\n    void operator -- () noexcept {*this = *this - 1;};\n   \
    \ void operator -- (int) noexcept {*this = *this - 1;};\n\n    bool operator ==\
    \ (const ModInt x) noexcept {return d == x.d;};\n    bool operator != (const ModInt\
    \ x) noexcept {return d != x.d;};\n\n    ModInt operator + (const uint x) const\
    \ noexcept {return *this + ModInt(x);};\n    ModInt operator - (const uint x)\
    \ const noexcept {return *this - ModInt(x);};\n    ModInt operator * (const uint\
    \ x) const noexcept {return *this * ModInt(x);};\n    ModInt operator / (const\
    \ uint x) const noexcept {return *this / ModInt(x);};\n    \n    ModInt operator\
    \ += (const uint x) noexcept {return *this = *this + x;};\n    ModInt operator\
    \ -= (const uint x) noexcept {return *this = *this - x;};\n    ModInt operator\
    \ *= (const uint x) noexcept {return *this = *this * x;};\n    ModInt operator\
    \ /= (const uint x) noexcept {return *this = *this / x;};\n};\ntemplate<uint_fast64_t\
    \ p>\nostream &operator << (ostream &stream, const ModInt<p> &mi) {\n    return\
    \ stream << mi.d;\n};\ntemplate<uint_fast64_t p>\nistream &operator >> (istream\
    \ &stream, ModInt<p> &mi) {\n    uint_fast64_t a;\n    stream >> a;\n    mi =\
    \ ModInt<p>(a);\n    return stream;\n};\n//===\n\n\n// verify https://atcoder.jp/contests/jsc2019-qual/submissions/7199030\n\
    #define sum(X) ((X) * (X + 1) / 2)\nusing mint = ModInt<1'000'000'007>;\nusing\
    \ ll = long long;\n\nint main() {\n    ll n, k;\n    ll a[2005];\n    mint ans;\n\
    \n    cin >> n >> k;\n    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n\
    \    }\n \n    for (int i = 0; i < n; i++) {\n        mint cnt(0);\n        for\
    \ (int j = i + 1; j < n; j++) {\n            if (a[i] > a[j]) {\n            \
    \    cnt++;\n            }\n        }\n \n        mint cnt2(0);\n        for (int\
    \ j = 0; j < n; j++) {\n            if (a[i] > a[j]) {\n                cnt2++;\n\
    \            }\n        }\n \n        ans += cnt * k;\n        ans += cnt2 * sum(k\
    \ - 1);\n    }\n \n    cout << ans << endl;\n \n    return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\nusing namespace std;\n\n//===\ntemplate<uint_fast64_t\
    \ p>\nstruct ModInt {\n    using uint = uint_fast64_t;\n    uint d;\n\n    ModInt(const\
    \ uint x = 0):d((x % p + p) % p) {};\n    \n    ModInt operator + (const ModInt\
    \ x) const noexcept {\n        if (d + x.d >= p) return ModInt(d + x.d - p);\n\
    \        else return ModInt(d + x.d);\n    };\n    ModInt operator - (const ModInt\
    \ x) const noexcept {\n        if (d - x.d < 0) return ModInt(d - x.d + p);\n\
    \        else return ModInt(d - x.d);\n    };\n    ModInt operator * (ModInt x)\
    \ const noexcept {\n        return ModInt(d * x.d);\n    }\n    ModInt operator\
    \ / (ModInt x) const noexcept {\n        ModInt inv(1);\n        uint exp = p\
    \ - 2;\n        while (exp) {\n            if (exp & 1) inv *= x;\n          \
    \  x *= x, exp >>= 1;\n        }\n\n        return ModInt(d * inv.d);\n    }\n\
    \n    ModInt &operator += (const ModInt x) noexcept {return *this = *this + x;};\n\
    \    ModInt &operator -= (const ModInt x) noexcept {return *this = *this - x;};\n\
    \    ModInt &operator *= (const ModInt x) noexcept {return *this = *this * x;};\n\
    \    ModInt &operator /= (const ModInt x) noexcept {return *this = *this / x;};\n\
    \    void operator ++ () noexcept {*this = *this + 1;};\n    void operator ++\
    \ (int) noexcept {*this = *this + 1;};\n    void operator -- () noexcept {*this\
    \ = *this - 1;};\n    void operator -- (int) noexcept {*this = *this - 1;};\n\n\
    \    bool operator == (const ModInt x) noexcept {return d == x.d;};\n    bool\
    \ operator != (const ModInt x) noexcept {return d != x.d;};\n\n    ModInt operator\
    \ + (const uint x) const noexcept {return *this + ModInt(x);};\n    ModInt operator\
    \ - (const uint x) const noexcept {return *this - ModInt(x);};\n    ModInt operator\
    \ * (const uint x) const noexcept {return *this * ModInt(x);};\n    ModInt operator\
    \ / (const uint x) const noexcept {return *this / ModInt(x);};\n    \n    ModInt\
    \ operator += (const uint x) noexcept {return *this = *this + x;};\n    ModInt\
    \ operator -= (const uint x) noexcept {return *this = *this - x;};\n    ModInt\
    \ operator *= (const uint x) noexcept {return *this = *this * x;};\n    ModInt\
    \ operator /= (const uint x) noexcept {return *this = *this / x;};\n};\ntemplate<uint_fast64_t\
    \ p>\nostream &operator << (ostream &stream, const ModInt<p> &mi) {\n    return\
    \ stream << mi.d;\n};\ntemplate<uint_fast64_t p>\nistream &operator >> (istream\
    \ &stream, ModInt<p> &mi) {\n    uint_fast64_t a;\n    stream >> a;\n    mi =\
    \ ModInt<p>(a);\n    return stream;\n};\n//===\n\n\n// verify https://atcoder.jp/contests/jsc2019-qual/submissions/7199030\n\
    #define sum(X) ((X) * (X + 1) / 2)\nusing mint = ModInt<1'000'000'007>;\nusing\
    \ ll = long long;\n\nint main() {\n    ll n, k;\n    ll a[2005];\n    mint ans;\n\
    \n    cin >> n >> k;\n    for (int i = 0; i < n; i++) {\n        cin >> a[i];\n\
    \    }\n \n    for (int i = 0; i < n; i++) {\n        mint cnt(0);\n        for\
    \ (int j = i + 1; j < n; j++) {\n            if (a[i] > a[j]) {\n            \
    \    cnt++;\n            }\n        }\n \n        mint cnt2(0);\n        for (int\
    \ j = 0; j < n; j++) {\n            if (a[i] > a[j]) {\n                cnt2++;\n\
    \            }\n        }\n \n        ans += cnt * k;\n        ans += cnt2 * sum(k\
    \ - 1);\n    }\n \n    cout << ans << endl;\n \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy: []
  timestamp: '2019-09-28 12:02:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---
