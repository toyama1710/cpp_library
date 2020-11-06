---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/combination.cpp\"\n#include <iostream>\n#include <cstdio>\n\
    using namespace std;\n\n//===\n// nCr mod p\n// p is prime\n// 1 <= k <= n <=\
    \ 1e7\n\nvoid init_comb(long long modulus);\nvoid init_comb(void);\nlong long\
    \ combination(long long n, long long k);\nlong long pow_mod(long long n, long\
    \ long m);\n\nlong long _modulus = (long long)1e9 + 7;\nlong long fact[10000007];\n\
    long long fact_inv[10000007];\n\nvoid init_comb(long long modulus) {_modulus =\
    \ modulus; }\nvoid init_comb(void) {\n    fact[0] = fact[1] = 1;\n    fact_inv[0]\
    \ = fact_inv[1] = 1;\n    for (int i = 2; i <= 10000000; i++) {\n        fact[i]\
    \ = fact[i - 1] * i % _modulus;\n        fact_inv[i] = pow_mod(fact[i], _modulus\
    \ - 2);\n    }\n}\n\nlong long combination(long long n, long long k) {\n    static\
    \ long long f;\n\n    if (f != _modulus) f = _modulus, init_comb();\n\n    if\
    \ (n < k) return 0;\n    if (n < 0 || k < 0) return 0;\n\n    return fact[n] *\
    \ (fact_inv[k] * fact_inv[n - k] % _modulus) % _modulus;\n}\n\nlong long pow_mod(long\
    \ long n, long long m) {\n    //n ** m;\n    long long ret = 1;\n\n    while (m)\
    \ {\n        if (m & 1) {\n            ret = ret * n % _modulus;\n        }\n\n\
    \        n = n * n % _modulus;\n        m = m >> 1;\n    }\n\n    return ret;\n\
    }\n//===\n\nint main() {\n    long long mod;\n    long long n, r;\n\n    printf(\"\
    mod: \");\n    scanf(\"%lld\", &mod);\n    init_comb(mod);\n\n    while (printf(\"\
    nCr: \"), scanf(\"%lld %lld\", &n, &r), n != -1 && r != -1) {\n        printf(\"\
    %lld\\n\", combination(n, r));\n    }\n    \n    return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\nusing namespace std;\n\n//===\n//\
    \ nCr mod p\n// p is prime\n// 1 <= k <= n <= 1e7\n\nvoid init_comb(long long\
    \ modulus);\nvoid init_comb(void);\nlong long combination(long long n, long long\
    \ k);\nlong long pow_mod(long long n, long long m);\n\nlong long _modulus = (long\
    \ long)1e9 + 7;\nlong long fact[10000007];\nlong long fact_inv[10000007];\n\n\
    void init_comb(long long modulus) {_modulus = modulus; }\nvoid init_comb(void)\
    \ {\n    fact[0] = fact[1] = 1;\n    fact_inv[0] = fact_inv[1] = 1;\n    for (int\
    \ i = 2; i <= 10000000; i++) {\n        fact[i] = fact[i - 1] * i % _modulus;\n\
    \        fact_inv[i] = pow_mod(fact[i], _modulus - 2);\n    }\n}\n\nlong long\
    \ combination(long long n, long long k) {\n    static long long f;\n\n    if (f\
    \ != _modulus) f = _modulus, init_comb();\n\n    if (n < k) return 0;\n    if\
    \ (n < 0 || k < 0) return 0;\n\n    return fact[n] * (fact_inv[k] * fact_inv[n\
    \ - k] % _modulus) % _modulus;\n}\n\nlong long pow_mod(long long n, long long\
    \ m) {\n    //n ** m;\n    long long ret = 1;\n\n    while (m) {\n        if (m\
    \ & 1) {\n            ret = ret * n % _modulus;\n        }\n\n        n = n *\
    \ n % _modulus;\n        m = m >> 1;\n    }\n\n    return ret;\n}\n//===\n\nint\
    \ main() {\n    long long mod;\n    long long n, r;\n\n    printf(\"mod: \");\n\
    \    scanf(\"%lld\", &mod);\n    init_comb(mod);\n\n    while (printf(\"nCr: \"\
    ), scanf(\"%lld %lld\", &n, &r), n != -1 && r != -1) {\n        printf(\"%lld\\\
    n\", combination(n, r));\n    }\n    \n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy: []
  timestamp: '2019-08-30 14:47:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: math/combination.cpp
---
