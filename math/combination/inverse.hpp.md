---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1501.combination.inverse.test.cpp
    title: test/aoj/1501.combination.inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/combination/inverse.md
    document_title: Combination (Inverse)
    links: []
  bundledCode: "#line 1 \"math/combination/inverse.hpp\"\n/**\n * @brief Combination\
    \ (Inverse)\n * @docs docs/math/combination/inverse.md\n */\n\ntemplate <typename\
    \ T>\nstruct Combination {\n    using u32 = unsigned int;\n    using i64 = long\
    \ long;\n    Combination() {}\n    Combination(u32 n) { init(n); }\n    vector<T>\
    \ fact, finv, invs;\n    void init(u32 n) {\n        u32 m = fact.size();\n  \
    \      if (n < m) return;\n        fact.resize(n + 1, 1);\n        finv.resize(n\
    \ + 1, 1);\n        invs.resize(n + 1, 1);\n        if (m == 0) m = 1;\n     \
    \   for (u32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * T(i);\n        finv[n]\
    \ = T(1) / fact[n];\n        for (u32 i = n; i >= m; --i) finv[i - 1] = finv[i]\
    \ * T(i);\n        for (u32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];\n\
    \    }\n    T getFact(u32 n) {\n        init(n);\n        return fact[n];\n  \
    \  }\n    T getFinv(u32 n) {\n        init(n);\n        return finv[n];\n    }\n\
    \    T getInvs(u32 n) {\n        init(n);\n        return invs[n];\n    }\n  \
    \  T C(i64 n, i64 r) {\n        if (r == 0) return T(1);\n        if (r < 0) return\
    \ T(0);\n        if (n < 0) return T(r & 1 ? -1 : 1) * C(-n + r - 1, r);\n   \
    \     if (n == 0 || n < r) return T(0);\n        init(n);\n        return fact[n]\
    \ * finv[n - r] * finv[r];\n    }\n    T P(i64 n, i64 r) {\n        if (n < r\
    \ || r < 0) return T(0);\n        init(n);\n        return fact[n] * finv[n -\
    \ r];\n    }\n    T H(i64 n, i64 r) {\n        if (n < 0 || r < 0) return T(0);\n\
    \        if (!n && !r) return T(1);\n        init(n + r - 1);\n        return\
    \ C(n + r - 1, r);\n    }\n};\n"
  code: "/**\n * @brief Combination (Inverse)\n * @docs docs/math/combination/inverse.md\n\
    \ */\n\ntemplate <typename T>\nstruct Combination {\n    using u32 = unsigned\
    \ int;\n    using i64 = long long;\n    Combination() {}\n    Combination(u32\
    \ n) { init(n); }\n    vector<T> fact, finv, invs;\n    void init(u32 n) {\n \
    \       u32 m = fact.size();\n        if (n < m) return;\n        fact.resize(n\
    \ + 1, 1);\n        finv.resize(n + 1, 1);\n        invs.resize(n + 1, 1);\n \
    \       if (m == 0) m = 1;\n        for (u32 i = m; i <= n; ++i) fact[i] = fact[i\
    \ - 1] * T(i);\n        finv[n] = T(1) / fact[n];\n        for (u32 i = n; i >=\
    \ m; --i) finv[i - 1] = finv[i] * T(i);\n        for (u32 i = m; i <= n; ++i)\
    \ invs[i] = finv[i] * fact[i - 1];\n    }\n    T getFact(u32 n) {\n        init(n);\n\
    \        return fact[n];\n    }\n    T getFinv(u32 n) {\n        init(n);\n  \
    \      return finv[n];\n    }\n    T getInvs(u32 n) {\n        init(n);\n    \
    \    return invs[n];\n    }\n    T C(i64 n, i64 r) {\n        if (r == 0) return\
    \ T(1);\n        if (r < 0) return T(0);\n        if (n < 0) return T(r & 1 ?\
    \ -1 : 1) * C(-n + r - 1, r);\n        if (n == 0 || n < r) return T(0);\n   \
    \     init(n);\n        return fact[n] * finv[n - r] * finv[r];\n    }\n    T\
    \ P(i64 n, i64 r) {\n        if (n < r || r < 0) return T(0);\n        init(n);\n\
    \        return fact[n] * finv[n - r];\n    }\n    T H(i64 n, i64 r) {\n     \
    \   if (n < 0 || r < 0) return T(0);\n        if (!n && !r) return T(1);\n   \
    \     init(n + r - 1);\n        return C(n + r - 1, r);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combination/inverse.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/117.test.cpp
  - test/aoj/1501.combination.inverse.test.cpp
documentation_of: math/combination/inverse.hpp
layout: document
redirect_from:
- /library/math/combination/inverse.hpp
- /library/math/combination/inverse.hpp.html
title: Combination (Inverse)
---
## 概要

$C$, $P$, $H$を逆元を用いて求める.

## 計算量

- 前計算 : $O(n)$
- クエリ : $O(1)$

## 使用例

- `Combination<modint> comb` : 準備
- `comb.C(n, r)` : $C(n, r)$に答える
- `comb.getFact(m)` : $m!$に答える
