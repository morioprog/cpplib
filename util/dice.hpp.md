---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0502.test.cpp
    title: test/aoj/0502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_A.test.cpp
    title: test/aoj/ITP1_11_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_B.test.cpp
    title: test/aoj/ITP1_11_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_C.test.cpp
    title: test/aoj/ITP1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_D.test.cpp
    title: test/aoj/ITP1_11_D.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/util/dice.md
    document_title: "\u30B5\u30A4\u30B3\u30ED"
    links: []
  bundledCode: "#line 1 \"util/dice.hpp\"\n/**\n* @brief \u30B5\u30A4\u30B3\u30ED\n\
    * @docs docs/util/dice.md\n*/\n\n// \u4E0B\u306By, \u53F3\u306Bx\nenum { R,\n\
    \       U,\n       L,\n       D };\nconst int ddx[] = { 1, 0, -1, 0 };\nconst\
    \ int ddy[] = { 0, -1, 0, 1 };\n\nstruct Dice {\n    int T, N, E, S, W, B;\n \
    \   int table[6][6] = {\n        { 0, 3, 5, 2, 4, 0 },\n        { 4, 0, 1, 6,\
    \ 0, 3 },\n        { 2, 6, 0, 0, 1, 5 },\n        { 5, 1, 0, 0, 6, 2 },\n    \
    \    { 3, 0, 6, 1, 0, 4 },\n        { 0, 4, 2, 5, 3, 0 }\n    };\n    Dice(int\
    \ T, int S)\n        : T(T), S(S) { build(); }\n    void build() {\n        E\
    \            = table[T - 1][S - 1];\n        tie(N, W, B) = make_tuple(7 - S,\
    \ 7 - E, 7 - T);\n        // swap(E, W);  // \u3082\u30461\u7A2E\u985E\u306E\u30B5\
    \u30A4\u30B3\u30ED\u306E\u5834\u5408\n    }\n    void rot(int dir) {\n       \
    \ if (dir == R) tie(T, S) = make_pair(W, S);\n        if (dir == U) tie(T, S)\
    \ = make_pair(S, B);\n        if (dir == L) tie(T, S) = make_pair(E, S);\n   \
    \     if (dir == D) tie(T, S) = make_pair(N, T);\n        // 1\u884C\u3067\u66F8\
    \u304F\u306A\u3089\n        // tie(T, S) = (vector<pair<int, int>>){{W, S}, {S,\
    \ B}, {E, S}, {N, T}}[dir];\n        build();\n    }\n    int get(int m) {\n \
    \       return (vector<int>){ E, N, W, S, T, B }[m];\n    }\n};\n"
  code: "/**\n* @brief \u30B5\u30A4\u30B3\u30ED\n* @docs docs/util/dice.md\n*/\n\n\
    // \u4E0B\u306By, \u53F3\u306Bx\nenum { R,\n       U,\n       L,\n       D };\n\
    const int ddx[] = { 1, 0, -1, 0 };\nconst int ddy[] = { 0, -1, 0, 1 };\n\nstruct\
    \ Dice {\n    int T, N, E, S, W, B;\n    int table[6][6] = {\n        { 0, 3,\
    \ 5, 2, 4, 0 },\n        { 4, 0, 1, 6, 0, 3 },\n        { 2, 6, 0, 0, 1, 5 },\n\
    \        { 5, 1, 0, 0, 6, 2 },\n        { 3, 0, 6, 1, 0, 4 },\n        { 0, 4,\
    \ 2, 5, 3, 0 }\n    };\n    Dice(int T, int S)\n        : T(T), S(S) { build();\
    \ }\n    void build() {\n        E            = table[T - 1][S - 1];\n       \
    \ tie(N, W, B) = make_tuple(7 - S, 7 - E, 7 - T);\n        // swap(E, W);  //\
    \ \u3082\u30461\u7A2E\u985E\u306E\u30B5\u30A4\u30B3\u30ED\u306E\u5834\u5408\n\
    \    }\n    void rot(int dir) {\n        if (dir == R) tie(T, S) = make_pair(W,\
    \ S);\n        if (dir == U) tie(T, S) = make_pair(S, B);\n        if (dir ==\
    \ L) tie(T, S) = make_pair(E, S);\n        if (dir == D) tie(T, S) = make_pair(N,\
    \ T);\n        // 1\u884C\u3067\u66F8\u304F\u306A\u3089\n        // tie(T, S)\
    \ = (vector<pair<int, int>>){{W, S}, {S, B}, {E, S}, {N, T}}[dir];\n        build();\n\
    \    }\n    int get(int m) {\n        return (vector<int>){ E, N, W, S, T, B }[m];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/dice.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0502.test.cpp
  - test/aoj/ITP1_11_A.test.cpp
  - test/aoj/ITP1_11_D.test.cpp
  - test/aoj/ITP1_11_C.test.cpp
  - test/aoj/ITP1_11_B.test.cpp
documentation_of: util/dice.hpp
layout: document
redirect_from:
- /library/util/dice.hpp
- /library/util/dice.hpp.html
title: "\u30B5\u30A4\u30B3\u30ED"
---
## 概要

サイコロ.

```txt
       _______
      /\      \           N(U)
     /  \   T  \           |            4
    /    \______\  W(L) - T,B - E(R)  2 1 5 6
    \ S  /      /          |            3
     \  /   E  /          S(D)
      \/______/
```

### 注意

もう1種類のサイコロ(3と4が逆)なら, `build`の中をコメントアウトする.

```txt
  3
2 1 5 6
  4
```

## 使用例

* `Dice dc(T, S)` : TとSが上のような位置関係のサイコロを作成.
* `dc.rot(R)` : 右方向に回転.
* `dc.get(idx)` : 側面の値を返す.
  * `idx` : 0から順に`R`, `U`, `L`, `D`.
* `ddx[], ddy[]` : 下を$y$, 右を$x$としたときの進む方向.
