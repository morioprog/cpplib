---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.eratosthenes.test.cpp
    title: test/aoj/ALDS1_1_C.eratosthenes.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/prime/eratosthenes.md
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 1 \"math/prime/eratosthenes.hpp\"\n/**\n* @brief \u30A8\u30E9\
    \u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n* @docs docs/math/prime/eratosthenes.md\n\
    */\n\nvector<bool> eratosthenes(const int n) {\n    vector<bool> r(n + 1, true);\n\
    \    for (int i = 2; i * i <= n; ++i) {\n        if (r[i]) {\n            for\
    \ (int j = i * 2; j <= n; j += i) r[j] = false;\n        }\n    }\n    if (r.size()\
    \ > 2) {\n        r[0] = r[1] = false;\n    } else if (r.size() > 1) {\n     \
    \   r[0] = false;\n    }\n    return r;\n}\n"
  code: "/**\n* @brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n* @docs\
    \ docs/math/prime/eratosthenes.md\n*/\n\nvector<bool> eratosthenes(const int n)\
    \ {\n    vector<bool> r(n + 1, true);\n    for (int i = 2; i * i <= n; ++i) {\n\
    \        if (r[i]) {\n            for (int j = i * 2; j <= n; j += i) r[j] = false;\n\
    \        }\n    }\n    if (r.size() > 2) {\n        r[0] = r[1] = false;\n   \
    \ } else if (r.size() > 1) {\n        r[0] = false;\n    }\n    return r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/eratosthenes.hpp
  requiredBy: []
  timestamp: '2020-08-24 20:00:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C.eratosthenes.test.cpp
documentation_of: math/prime/eratosthenes.hpp
layout: document
redirect_from:
- /library/math/prime/eratosthenes.hpp
- /library/math/prime/eratosthenes.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
## 概要

$n$以下の素数判定を高速に行う.

## 計算量

$O(n\log\log{n})$

## 使用例

- `eratosthenes(n)` : $n$以下の自然数に対して求める.
  - 返り値の型 : `vector<bool>`
