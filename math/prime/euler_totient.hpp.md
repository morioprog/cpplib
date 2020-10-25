---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/prime/euler_totient.md
    document_title: "Euler's totient function (\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
      \u95A2\u6570)"
    links: []
  bundledCode: "#line 1 \"math/prime/euler_totient.hpp\"\n/**\n* @brief Euler's totient\
    \ function (\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)\n* @docs docs/math/prime/euler_totient.md\n\
    */\n\nlong long euler_totient(long long n) {\n    long long ret = n;\n    for\
    \ (long long i = 2; i * i <= n; ++i) {\n        if (n % i) continue;\n       \
    \ ret -= ret / i;\n        while (n % i == 0) n /= i;\n    }\n    if (n > 1) ret\
    \ -= ret / n;\n    return ret;\n}\n"
  code: "/**\n* @brief Euler's totient function (\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
    \u95A2\u6570)\n* @docs docs/math/prime/euler_totient.md\n*/\n\nlong long euler_totient(long\
    \ long n) {\n    long long ret = n;\n    for (long long i = 2; i * i <= n; ++i)\
    \ {\n        if (n % i) continue;\n        ret -= ret / i;\n        while (n %\
    \ i == 0) n /= i;\n    }\n    if (n > 1) ret -= ret / n;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/euler_totient.hpp
  requiredBy: []
  timestamp: '2020-04-22 01:00:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
documentation_of: math/prime/euler_totient.hpp
layout: document
redirect_from:
- /library/math/prime/euler_totient.hpp
- /library/math/prime/euler_totient.hpp.html
title: "Euler's totient function (\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\
  )"
---
## 概要

$1$以上$N$以下の整数について, $N$と互いに素なものの個数を求める.

## 計算量

$O(\sqrt{n})$

## 使用例

* `euler_totient(N)` : $\varphi(N)$を返す.
  * 返り値の型 : `long long`
