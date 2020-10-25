---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1501.combination.pascal.test.cpp
    title: test/aoj/1501.combination.pascal.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/combination/pascal.md
    document_title: Combination (Pascal)
    links: []
  bundledCode: "#line 1 \"math/combination/pascal.hpp\"\n/**\n * @brief Combination\
    \ (Pascal)\n * @docs docs/math/combination/pascal.md\n */\n\ntemplate <typename\
    \ T>\nT C_pascal(long long n, int r) {\n    if (r == 0) return T(1);\n    if (r\
    \ < 0) return T(0);\n    if (n < 0) return T(r & 1 ? -1 : 1) * C_pascal<T>(-n\
    \ + r - 1, r);\n    if (n == 0 || n < r) return T(0);\n    T ret(1);\n    for\
    \ (int i = 1; i <= r; ++i) ret *= n--, ret /= i;\n    return ret;\n}\n\ntemplate\
    \ <typename T>\nT P_pascal(long long n, int r) {\n    if (n < r || r < 0) return\
    \ T(0);\n    T ret(1);\n    for (int i = 1; i <= r; ++i) ret *= n--;\n    return\
    \ ret;\n}\n\ntemplate <typename T>\nT H_pascal(long long n, int r) {\n    if (n\
    \ < 0 || r < 0) return T(0);\n    if (!n && !r) return T(1);\n    return C_pascal<T>(n\
    \ + r - 1, r);\n}\n"
  code: "/**\n * @brief Combination (Pascal)\n * @docs docs/math/combination/pascal.md\n\
    \ */\n\ntemplate <typename T>\nT C_pascal(long long n, int r) {\n    if (r ==\
    \ 0) return T(1);\n    if (r < 0) return T(0);\n    if (n < 0) return T(r & 1\
    \ ? -1 : 1) * C_pascal<T>(-n + r - 1, r);\n    if (n == 0 || n < r) return T(0);\n\
    \    T ret(1);\n    for (int i = 1; i <= r; ++i) ret *= n--, ret /= i;\n    return\
    \ ret;\n}\n\ntemplate <typename T>\nT P_pascal(long long n, int r) {\n    if (n\
    \ < r || r < 0) return T(0);\n    T ret(1);\n    for (int i = 1; i <= r; ++i)\
    \ ret *= n--;\n    return ret;\n}\n\ntemplate <typename T>\nT H_pascal(long long\
    \ n, int r) {\n    if (n < 0 || r < 0) return T(0);\n    if (!n && !r) return\
    \ T(1);\n    return C_pascal<T>(n + r - 1, r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combination/pascal.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1501.combination.pascal.test.cpp
documentation_of: math/combination/pascal.hpp
layout: document
redirect_from:
- /library/math/combination/pascal.hpp
- /library/math/combination/pascal.hpp.html
title: Combination (Pascal)
---
## 概要

$C$, $P$, $H$をパスカルの三角形を用いて求める.

## 計算量

- クエリ : $O(r)$

## 使用例

- `C_pascal<modint>(n, r)` : `modint`型で$C(n, r)$に答える
