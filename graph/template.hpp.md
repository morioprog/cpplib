---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2945.test.cpp
    title: test/aoj/2945.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_B.test.cpp
    title: test/aoj/GRL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertexaddpathsum.test.cpp
    title: test/yosupo/vertexaddpathsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertexaddsubtreesum.test.cpp
    title: test/yosupo/vertexaddsubtreesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/13.test.cpp
    title: test/yukicoder/13.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/20.test.cpp
    title: test/yukicoder/20.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/399.test.cpp
    title: test/yukicoder/399.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/template.md
    document_title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "#line 1 \"graph/template.hpp\"\n/**\n* @brief \u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n* @docs docs/graph/template.md\n*/\n\ntemplate\
    \ <typename T>\nstruct Edge {\n    int frm, to, idx;\n    T cst;\n    Edge() {}\n\
    \    Edge(int f, int t, T c, int i = -1)\n        : frm(f), to(t), idx(i), cst(c)\
    \ {}\n    operator int() const { return to; }\n};\n\ntemplate <typename T>\nconstexpr\
    \ T GINF = numeric_limits<T>::max() / 10;\n\ntemplate <typename T>\nstruct Graph\
    \ {\n    int V, E;\n    vector<vector<Edge<T>>> mat;\n    vector<vector<T>> wf;\n\
    \    Graph() {}\n    Graph(int v)\n        : V(v), E(0), mat(v) {}\n    inline\
    \ void add_edge(int a, int b, T c = 1, int margin = 0) {\n        a -= margin,\
    \ b -= margin;\n        mat[a].emplace_back(a, b, c, E++);\n        mat[b].emplace_back(b,\
    \ a, c, E++);\n    }\n    inline void add_arc(int a, int b, T c = 1, int margin\
    \ = 0) {\n        a -= margin, b -= margin;\n        mat[a].emplace_back(a, b,\
    \ c, E++);\n    }\n    inline void input_edges(int M, int margin = 0, bool need_cost\
    \ = false) {\n        for (int i = 0; i < M; ++i) {\n            int a, b;\n \
    \           T c(1);\n            cin >> a >> b;\n            if (need_cost) cin\
    \ >> c;\n            add_edge(a, b, c, margin);\n        }\n    }\n    inline\
    \ void input_arcs(int M, int margin = 0, bool need_cost = false) {\n        for\
    \ (int i = 0; i < M; ++i) {\n            int a, b;\n            T c(1);\n    \
    \        cin >> a >> b;\n            if (need_cost) cin >> c;\n            add_arc(a,\
    \ b, c, margin);\n        }\n    }\n};\n"
  code: "/**\n* @brief \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n* @docs\
    \ docs/graph/template.md\n*/\n\ntemplate <typename T>\nstruct Edge {\n    int\
    \ frm, to, idx;\n    T cst;\n    Edge() {}\n    Edge(int f, int t, T c, int i\
    \ = -1)\n        : frm(f), to(t), idx(i), cst(c) {}\n    operator int() const\
    \ { return to; }\n};\n\ntemplate <typename T>\nconstexpr T GINF = numeric_limits<T>::max()\
    \ / 10;\n\ntemplate <typename T>\nstruct Graph {\n    int V, E;\n    vector<vector<Edge<T>>>\
    \ mat;\n    vector<vector<T>> wf;\n    Graph() {}\n    Graph(int v)\n        :\
    \ V(v), E(0), mat(v) {}\n    inline void add_edge(int a, int b, T c = 1, int margin\
    \ = 0) {\n        a -= margin, b -= margin;\n        mat[a].emplace_back(a, b,\
    \ c, E++);\n        mat[b].emplace_back(b, a, c, E++);\n    }\n    inline void\
    \ add_arc(int a, int b, T c = 1, int margin = 0) {\n        a -= margin, b -=\
    \ margin;\n        mat[a].emplace_back(a, b, c, E++);\n    }\n    inline void\
    \ input_edges(int M, int margin = 0, bool need_cost = false) {\n        for (int\
    \ i = 0; i < M; ++i) {\n            int a, b;\n            T c(1);\n         \
    \   cin >> a >> b;\n            if (need_cost) cin >> c;\n            add_edge(a,\
    \ b, c, margin);\n        }\n    }\n    inline void input_arcs(int M, int margin\
    \ = 0, bool need_cost = false) {\n        for (int i = 0; i < M; ++i) {\n    \
    \        int a, b;\n            T c(1);\n            cin >> a >> b;\n        \
    \    if (need_cost) cin >> c;\n            add_arc(a, b, c, margin);\n       \
    \ }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/20.test.cpp
  - test/yukicoder/399.test.cpp
  - test/yukicoder/13.test.cpp
  - test/aoj/GRL_5_C.test.cpp
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/2945.test.cpp
  - test/aoj/GRL_7_A.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/GRL_5_E.test.cpp
  - test/aoj/GRL_5_D.test.cpp
  - test/aoj/GRL_4_B.test.cpp
  - test/yosupo/vertexaddsubtreesum.test.cpp
  - test/yosupo/vertexaddpathsum.test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
## 概要

グラフのテンプレート.

#### 最短経路

* ダイクストラ法 : 単一始点最短路. 辺の重みが非負である必要がある. $O(E\log V)$
* ベルマンフォード法 : 単一始点最短路. 負閉路検出ができる. $O(EV)$
* ワーシャルフロイド法 : 全点間最短路. 負閉路検出ができる. $O(V^3)$
  * 辺の追加は$O(V^2)$

#### 最小全域木

* クラスカル法 : UnionFindに依存. $O(E\log V)$

## 使用例

* `Graph<int> g(V)` : $V$頂点のグラフを定義.
* `GINF<int>` : グラフアルゴリズムで使う`INF`.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `U V cst`
    * `false` : `U V`
