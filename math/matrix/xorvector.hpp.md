---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/xorvector.md
    document_title: Xor Vector
    links: []
  bundledCode: "#line 1 \"math/matrix/xorvector.hpp\"\n/**\n* @brief Xor Vector\n\
    * @docs docs/math/matrix/xorvector.md\n*/\n\nstruct XorVector {\n    bool dirty\
    \ = false;\n    int rank, N;\n    vector<long long> span;\n    XorVector(int N)\n\
    \        : rank(0), N(N), span(N, 0) {}\n    void emplace(ll num) {\n        span[rank++]\
    \ = num;\n        dirty        = true;\n    }\n    bool find(ll num) {\n     \
    \   if (num == 0) return true;\n        if (dirty) gaussian_elimination();\n \
    \       for (int i = 0; i < rank; ++i) {\n            if (span[i] == 0LL) break;\n\
    \            num = min(num, num ^ span[i]);\n        }\n        return num ==\
    \ 0LL;\n    }\n    void gaussian_elimination() {\n        rank = 0;\n        for\
    \ (int col = 63; col >= 0; --col) {\n            int pivot = -1;\n           \
    \ for (int row = rank; row < N; ++row)\n                if (span[row] >> col &\
    \ 1) {\n                    pivot = row;\n                    break;\n       \
    \         }\n            if (pivot == -1) continue;\n            swap(span[pivot],\
    \ span[rank]);\n            for (int row = 0; row < N; ++row)\n              \
    \  if (row != rank and span[row] >> col & 1) span[row] ^= span[rank];\n      \
    \      ++rank;\n        }\n        dirty = false;\n    }\n    void print() {\n\
    \        for (int i = 0; i < rank; ++i) cerr << bitset<64>(span[i]) << endl;\n\
    \        cerr << endl;\n    }\n};\n"
  code: "/**\n* @brief Xor Vector\n* @docs docs/math/matrix/xorvector.md\n*/\n\nstruct\
    \ XorVector {\n    bool dirty = false;\n    int rank, N;\n    vector<long long>\
    \ span;\n    XorVector(int N)\n        : rank(0), N(N), span(N, 0) {}\n    void\
    \ emplace(ll num) {\n        span[rank++] = num;\n        dirty        = true;\n\
    \    }\n    bool find(ll num) {\n        if (num == 0) return true;\n        if\
    \ (dirty) gaussian_elimination();\n        for (int i = 0; i < rank; ++i) {\n\
    \            if (span[i] == 0LL) break;\n            num = min(num, num ^ span[i]);\n\
    \        }\n        return num == 0LL;\n    }\n    void gaussian_elimination()\
    \ {\n        rank = 0;\n        for (int col = 63; col >= 0; --col) {\n      \
    \      int pivot = -1;\n            for (int row = rank; row < N; ++row)\n   \
    \             if (span[row] >> col & 1) {\n                    pivot = row;\n\
    \                    break;\n                }\n            if (pivot == -1) continue;\n\
    \            swap(span[pivot], span[rank]);\n            for (int row = 0; row\
    \ < N; ++row)\n                if (row != rank and span[row] >> col & 1) span[row]\
    \ ^= span[rank];\n            ++rank;\n        }\n        dirty = false;\n   \
    \ }\n    void print() {\n        for (int i = 0; i < rank; ++i) cerr << bitset<64>(span[i])\
    \ << endl;\n        cerr << endl;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/xorvector.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/184.test.cpp
documentation_of: math/matrix/xorvector.hpp
layout: document
redirect_from:
- /library/math/matrix/xorvector.hpp
- /library/math/matrix/xorvector.hpp.html
title: Xor Vector
---
## 概要

掃き出せる`vector<long long>`.

## 計算量

* 掃き出し法 : $O(nb)$ ($b$はビットサイズ)

## 使用例

* `XorVector vec(n)` : 最大サイズ$n$の`vector`を定義.
* `vec.emplace(m)` : $m$を追加.
* `vec.find(m)` : いくつかの要素のXORが$m$になるかを返す.
* `vec.gaussian_elimination()` : 掃き出し法.
* `vec.print()` : デバッグ出力.

## 問題例

* [ABC141F - Xor Sum 3](https://atcoder.jp/contests/abc141/tasks/abc141_f)
* [AGC045A - Xor Battle](https://atcoder.jp/contests/agc045/tasks/agc045_a)
* [codeFlyer D - 数列 XOR](https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d)
