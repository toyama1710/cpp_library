---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../cht/dynamic_li_chao_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <vector>\n#include <tuple>\n#include <algorithm>\n\
    #include \"../../cht/dynamic_li_chao_tree.hpp\"\n\nusing namespace std;\nusing\
    \ llong = long long;\n\nllong n, q;\n\nconst llong INF = 1ll << 60ll;\nDynamicLiChaoTree<llong,\
    \ -1 * INF, INF> cht;\n\nint main() {\n    cin >> n >> q;\n    for (int i = 0;\
    \ i < n; i++) {\n        llong a, b;\n        cin >> a >> b;\n        cht.add_line(a,\
    \ b);\n    }\n\n    for (int i = 0; i < q; i++) {\n        llong com, x, y;\n\n\
    \        cin >> com;\n        if (com == 0) {\n            cin >> x >> y;\n  \
    \          cht.add_line(x, y);\n        }\n        else {\n            cin >>\
    \ x;\n            cout << cht.get(x) << '\\n';\n        }\n    }\n\n    return\
    \ 0;\n};\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/line_add_get_min2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min2.test.cpp
- /verify/test/yosupo/line_add_get_min2.test.cpp.html
title: test/yosupo/line_add_get_min2.test.cpp
---
