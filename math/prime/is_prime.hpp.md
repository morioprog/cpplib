---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.isprime.test.cpp
    title: test/aoj/ALDS1_1_C.isprime.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/prime/is_prime.md
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 1 \"math/prime/is_prime.hpp\"\n/**\n * @brief \u7D20\u6570\u5224\
    \u5B9A\n * @docs docs/math/prime/is_prime.md\n */\n\nbool is_prime(long long n)\
    \ {\n    if (n < 2) return false;\n    for (int i = 2; i * i <= n; ++i)\n    \
    \    if (n % i == 0) return false;\n    return true;\n}\n"
  code: "/**\n * @brief \u7D20\u6570\u5224\u5B9A\n * @docs docs/math/prime/is_prime.md\n\
    \ */\n\nbool is_prime(long long n) {\n    if (n < 2) return false;\n    for (int\
    \ i = 2; i * i <= n; ++i)\n        if (n % i == 0) return false;\n    return true;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/is_prime.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C.isprime.test.cpp
documentation_of: math/prime/is_prime.hpp
layout: document
redirect_from:
- /library/math/prime/is_prime.hpp
- /library/math/prime/is_prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
## 概要

素数判定する.

## 計算量

$O(\sqrt{n})$

## 使用例

* `is_prime(N)` : $N$が素数かを返す.
  * 返り値の型 : `bool`
