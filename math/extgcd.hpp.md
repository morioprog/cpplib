---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/extgcd.md
    document_title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5"
    links: []
  bundledCode: "#line 1 \"math/extgcd.hpp\"\n/**\n* @brief \u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n* @docs docs/math/extgcd.md\n\
    */\n\nlong long extgcd(long long a, long long b, long long &x, long long &y) {\n\
    \    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n\
    \    long long d = extgcd(b, a % b, y, x);\n    y -= a / b * x;\n    return d;\n\
    }\n"
  code: "/**\n* @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\n* @docs docs/math/extgcd.md\n*/\n\nlong long extgcd(long long a,\
    \ long long b, long long &x, long long &y) {\n    if (b == 0) {\n        x = 1;\n\
    \        y = 0;\n        return a;\n    }\n    long long d = extgcd(b, a % b,\
    \ y, x);\n    y -= a / b * x;\n    return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy: []
  timestamp: '2020-04-22 01:19:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_E.test.cpp
documentation_of: math/extgcd.hpp
layout: document
redirect_from:
- /library/math/extgcd.hpp
- /library/math/extgcd.hpp.html
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
## 概要

与えられた$a, b$に対して, 最大公約数$gcd(a, b)$と, $ax + by = gcd(a, b)$なる$x, y$を求める.

## 計算量

$O(\log a)$

## 使用例

* `extgcd(a, b, x, y)` : $a$と$b$に対して拡張ユークリッドの互除法を行う.
  * $ax + by = gcd(a, b)$なる$x, y$は`x`, `y`に格納される.
  * 返り値 : $gcd(a, b)$
