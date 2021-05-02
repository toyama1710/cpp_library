---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"wavelet_matrix/wavelet_matrix.hpp\"\n\n\n\n#include <vector>\n\
    \n// T = integer type\n// LOG = bit size\n// FID = FullyIndexableDictionary\n\
    template<class T, int LOG, class FID>\nstruct WaveletMatrix {\n    int len;\n\
    \    FID bits[LOG];\n\n    WaveletMatrix() = default;\n    WaveletMatrix(std::vector<T>\
    \ data) {\n        len = data.size();\n        std::vector<T> ls(len), rs(len);\n\
    \        int p = 0, q = 0;\n\n        for (int depth = 0; depth < LOG; depth++)\
    \ {\n            p = q = 0;\n            bits[depth] = FID(len);\n           \
    \ for (int i = 0; i < len; i++) {\n                if ((data[i] >> (LOG - depth\
    \ - 1)) & 1) {\n                    bits[depth].set(i);\n                    rs[q++]\
    \ = data[i];\n                }\n                else {\n                    ls[p++]\
    \ = data[i];\n                }\n            }\n            bits[depth].build();\n\
    \            data.clear();\n            swap(data, ls);\n            for (int\
    \ i = 0; i < q; i++) {\n                data[i + p] = rs[i];\n            }\n\
    \        }\n    };\n\n    int access(int k) {\n        int ret = 0;\n        for\
    \ (int depth = 0; depth < LOG; depth++) {\n            ret <<= 1;\n          \
    \  ret |= bits[depth][k];\n            if (bits[depth][k]) {\n               \
    \ k = bits[depth].rank0(len) + bits[depth].rank1(k);\n            }\n        \
    \    else {\n                k = bits[depth].rank0(k);\n            }\n      \
    \  }\n        return ret;\n    };\n\n    // count v in [0, k)\n    int rank(T\
    \ v, int k) {\n        int l = 0;\n        int r = k;\n        for (int depth\
    \ = 0; depth < LOG; depth++) {\n            int bit = (v >> (LOG - depth - 1))\
    \ & 1;\n            if (bit) {\n                int b = bits[depth].rank0(len);\n\
    \                l = b + bits[depth].rank1(l);\n                r = b + bits[depth].rank1(r);\n\
    \            }\n            else {\n                l = bits[depth].rank0(l);\n\
    \                r = bits[depth].rank0(r);\n            }\n        }\n       \
    \ return r - l;\n    };\n\n    int less(T v, int l, int r) {\n        int ret\
    \ = 0;\n        for (depth = 0; depth < LOG; depth++) {\n            if ((v >>\
    \ (LOG - depth - 1)) & 1) {\n                ret += bits[depth].rank0(r) - bits[depth].rank0(l);\n\
    \                int b = bits[depth].rank0(len);\n                l = b + bits[depth].rank1(l);\n\
    \                r = b + bits[depth].rank1(r);\n            }\n            else\
    \ {\n                l = bits[depth].rank0(l);\n                r = bits[depth].rank0(r);\n\
    \            }\n        }\n        return ret;\n    };\n\n    int range_freq(int\
    \ l, int r, int lower, int upper) {\n        return less(upper, l, r) - less(lower\
    \ - 1, l, r);\n    };\n};\n\n\n"
  code: "#ifndef WAVELET_MATRIX_HPP\n#define WAVELET_MATRIX_HPP\n\n#include <vector>\n\
    \n// T = integer type\n// LOG = bit size\n// FID = FullyIndexableDictionary\n\
    template<class T, int LOG, class FID>\nstruct WaveletMatrix {\n    int len;\n\
    \    FID bits[LOG];\n\n    WaveletMatrix() = default;\n    WaveletMatrix(std::vector<T>\
    \ data) {\n        len = data.size();\n        std::vector<T> ls(len), rs(len);\n\
    \        int p = 0, q = 0;\n\n        for (int depth = 0; depth < LOG; depth++)\
    \ {\n            p = q = 0;\n            bits[depth] = FID(len);\n           \
    \ for (int i = 0; i < len; i++) {\n                if ((data[i] >> (LOG - depth\
    \ - 1)) & 1) {\n                    bits[depth].set(i);\n                    rs[q++]\
    \ = data[i];\n                }\n                else {\n                    ls[p++]\
    \ = data[i];\n                }\n            }\n            bits[depth].build();\n\
    \            data.clear();\n            swap(data, ls);\n            for (int\
    \ i = 0; i < q; i++) {\n                data[i + p] = rs[i];\n            }\n\
    \        }\n    };\n\n    int access(int k) {\n        int ret = 0;\n        for\
    \ (int depth = 0; depth < LOG; depth++) {\n            ret <<= 1;\n          \
    \  ret |= bits[depth][k];\n            if (bits[depth][k]) {\n               \
    \ k = bits[depth].rank0(len) + bits[depth].rank1(k);\n            }\n        \
    \    else {\n                k = bits[depth].rank0(k);\n            }\n      \
    \  }\n        return ret;\n    };\n\n    // count v in [0, k)\n    int rank(T\
    \ v, int k) {\n        int l = 0;\n        int r = k;\n        for (int depth\
    \ = 0; depth < LOG; depth++) {\n            int bit = (v >> (LOG - depth - 1))\
    \ & 1;\n            if (bit) {\n                int b = bits[depth].rank0(len);\n\
    \                l = b + bits[depth].rank1(l);\n                r = b + bits[depth].rank1(r);\n\
    \            }\n            else {\n                l = bits[depth].rank0(l);\n\
    \                r = bits[depth].rank0(r);\n            }\n        }\n       \
    \ return r - l;\n    };\n\n    int less(T v, int l, int r) {\n        int ret\
    \ = 0;\n        for (depth = 0; depth < LOG; depth++) {\n            if ((v >>\
    \ (LOG - depth - 1)) & 1) {\n                ret += bits[depth].rank0(r) - bits[depth].rank0(l);\n\
    \                int b = bits[depth].rank0(len);\n                l = b + bits[depth].rank1(l);\n\
    \                r = b + bits[depth].rank1(r);\n            }\n            else\
    \ {\n                l = bits[depth].rank0(l);\n                r = bits[depth].rank0(r);\n\
    \            }\n        }\n        return ret;\n    };\n\n    int range_freq(int\
    \ l, int r, int lower, int upper) {\n        return less(upper, l, r) - less(lower\
    \ - 1, l, r);\n    };\n};\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: wavelet_matrix/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2020-07-31 08:58:53+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: wavelet_matrix/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/wavelet_matrix/wavelet_matrix.hpp
- /library/wavelet_matrix/wavelet_matrix.hpp.html
title: wavelet_matrix/wavelet_matrix.hpp
---
