---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/888.test.cpp
    title: test/yukicoder/888.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/prime/divisor.md
    document_title: "Divisor (\u7D04\u6570)"
    links: []
  bundledCode: "#line 1 \"math/prime/divisor.hpp\"\n/**\n * @brief Divisor (\u7D04\
    \u6570)\n * @docs docs/math/prime/divisor.md\n */\n\nvector<long long> divisor(const\
    \ long long n) {\n    vector<long long> ret;\n    for (long long i = 1; i * i\
    \ <= n; ++i) {\n        if (n % i == 0) {\n            ret.emplace_back(i);\n\
    \            if (i * i != n) ret.emplace_back(n / i);\n        }\n    }\n    return\
    \ ret;\n}\n"
  code: "/**\n * @brief Divisor (\u7D04\u6570)\n * @docs docs/math/prime/divisor.md\n\
    \ */\n\nvector<long long> divisor(const long long n) {\n    vector<long long>\
    \ ret;\n    for (long long i = 1; i * i <= n; ++i) {\n        if (n % i == 0)\
    \ {\n            ret.emplace_back(i);\n            if (i * i != n) ret.emplace_back(n\
    \ / i);\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/divisor.hpp
  requiredBy: []
  timestamp: '2020-04-22 00:08:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/888.test.cpp
documentation_of: math/prime/divisor.hpp
layout: document
redirect_from:
- /library/math/prime/divisor.hpp
- /library/math/prime/divisor.hpp.html
title: "Divisor (\u7D04\u6570)"
---
## 概要

約数を列挙する. *ソートはされていない*.

## 計算量

$O(\sqrt{n})$

## 使用例

* `divisor(N)` : $N$の約数を返す.
  * 返り値の型 : `vector<long long>`
