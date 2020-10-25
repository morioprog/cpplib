---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/prime/prime_factor.md
    document_title: "Prime Factor (\u7D20\u56E0\u6570\u5206\u89E3)"
    links: []
  bundledCode: "#line 1 \"math/prime/prime_factor.hpp\"\n/**\n * @brief Prime Factor\
    \ (\u7D20\u56E0\u6570\u5206\u89E3)\n * @docs docs/math/prime/prime_factor.md\n\
    \ */\n\nmap<long long, int> prime_factor(long long n) {\n    map<long long, int>\
    \ ret;\n    for (long long i = 2; i * i <= n; ++i) {\n        while (n % i ==\
    \ 0) {\n            ++ret[i];\n            n /= i;\n        }\n    }\n    if (n\
    \ != 1) ret[n] = 1;\n    return ret;\n}\n"
  code: "/**\n * @brief Prime Factor (\u7D20\u56E0\u6570\u5206\u89E3)\n * @docs docs/math/prime/prime_factor.md\n\
    \ */\n\nmap<long long, int> prime_factor(long long n) {\n    map<long long, int>\
    \ ret;\n    for (long long i = 2; i * i <= n; ++i) {\n        while (n % i ==\
    \ 0) {\n            ++ret[i];\n            n /= i;\n        }\n    }\n    if (n\
    \ != 1) ret[n] = 1;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/prime_factor.hpp
  requiredBy: []
  timestamp: '2020-04-21 22:55:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_A.test.cpp
documentation_of: math/prime/prime_factor.hpp
layout: document
redirect_from:
- /library/math/prime/prime_factor.hpp
- /library/math/prime/prime_factor.hpp.html
title: "Prime Factor (\u7D20\u56E0\u6570\u5206\u89E3)"
---
## 概要

素因数分解する.

## 計算量

$O(\sqrt{n})$

## 使用例

* `prime_factor(N)` : $N$を素因数分解したものを返す.
  * 返り値の型 : `map<long long, int>`
