---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../wavelet_tree/wavelet_matrix.hpp:\
    \ line -1: no such header\n"
  code: "#include <iostream>\n#include <cstdint>\n#include <ctime>\n#include <vector>\n\
    #include <cassert>\n#include \"../../compact_data_structure/bit_vector.hpp\"\n\
    #include \"../../wavelet_tree/wavelet_matrix.hpp\"\n#include \"../../util/xorshift.hpp\"\
    \nusing namespace std;\n\nint n;\nvector<unsigned int> v;\n\nint main() {\n  \
    \  cin >> n;\n    v.resize(n);\n    for (int i = 0; i < n; i++) {\n        v[i]\
    \ = xorshift32() % 128;\n    }\n\n    WaveletMatrix<unsigned int, 16, BitVector>\
    \ wm(v);\n\n    for (int i = 0; i < n * n; i++) {\n        int k = xorshift32()\
    \ % n;\n        int x = v[(xorshift32()) % n];\n\n        int cnt = 0;\n     \
    \   for (int i = 0; i < k; i++) if (v[i] == x) cnt++;\n\n        if (cnt != wm.rank(x,\
    \ k)) {\n            cout << x << ' ' << k << ':' << \"test failed\" << endl;\n\
    \            cout << cnt << ' ' << wm.rank(x, k) << endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: test/ws/wm_rank.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/ws/wm_rank.cpp
layout: document
redirect_from:
- /library/test/ws/wm_rank.cpp
- /library/test/ws/wm_rank.cpp.html
title: test/ws/wm_rank.cpp
---
