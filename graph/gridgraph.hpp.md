---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2945.test.cpp
    title: test/aoj/2945.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/13.test.cpp
    title: test/yukicoder/13.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/20.test.cpp
    title: test/yukicoder/20.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/gridgraph.md
    document_title: "\u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 1 \"graph/gridgraph.hpp\"\n/**\n* @brief \u30B0\u30EA\u30C3\u30C9\
    \u30B0\u30E9\u30D5\n* @docs docs/graph/gridgraph.md\n*/\n\ntemplate <typename\
    \ T = int>\nstruct GridGraph : Graph<T> {\n    using Graph<T>::V;\n    using Graph<T>::E;\n\
    \    using Graph<T>::mat;\n    const int Gdx[9] = { 1, 0, -1, 0, 1, -1, -1, 1,\
    \ 0 };\n    const int Gdy[9] = { 0, 1, 0, -1, -1, -1, 1, 1, 0 };\n    int H, W;\n\
    \    GridGraph() {}\n    GridGraph(int h, int w)\n        : H(h), W(w) {\n   \
    \     V = h * w;\n        E = 0;\n        mat.resize(V);\n    }\n    inline bool\
    \ inside(const int h, const int w) const {\n        return h >= 0 and w >= 0 and\
    \ h < H and w < W;\n    }\n    inline int hash(const int h, const int w, const\
    \ int margin = 0) const {\n        return (h - margin) * W + (w - margin);\n \
    \   }\n    inline void add_edge(int ax, int ay, int bx, int by, T c = 1, int margin\
    \ = 0) {\n        ax -= margin, ay -= margin, bx -= margin, by -= margin;\n  \
    \      int a = hash(ax, ay), b = hash(bx, by);\n        mat[a].emplace_back(a,\
    \ b, c, E++);\n        mat[b].emplace_back(b, a, c, E++);\n    }\n    inline void\
    \ add_edge(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {\n\
    \        int ax, ay, bx, by;\n        tie(ax, ay) = ap;\n        tie(bx, by) =\
    \ bp;\n        ax -= margin, ay -= margin, bx -= margin, by -= margin;\n     \
    \   int a = hash(ax, ay), b = hash(bx, by);\n        mat[a].emplace_back(a, b,\
    \ c, E++);\n        mat[b].emplace_back(b, a, c, E++);\n    }\n    inline void\
    \ add_arc(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {\n       \
    \ ax -= margin, ay -= margin, bx -= margin, by -= margin;\n        int a = hash(ax,\
    \ ay), b = hash(bx, by);\n        mat[a].emplace_back(a, b, c, E++);\n    }\n\
    \    inline void add_arc(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin\
    \ = 0) {\n        int ax, ay, bx, by;\n        tie(ax, ay) = ap;\n        tie(bx,\
    \ by) = bp;\n        ax -= margin, ay -= margin, bx -= margin, by -= margin;\n\
    \        int a = hash(ax, ay), b = hash(bx, by);\n        mat[a].emplace_back(a,\
    \ b, c, E++);\n    }\n    inline void input_edges(int M, int margin = 0, bool\
    \ need_cost = false) {\n        for (int i = 0; i < M; ++i) {\n            int\
    \ ax, ay, bx, by;\n            T c(1);\n            cin >> ax >> ay >> bx >> by;\n\
    \            if (need_cost) cin >> c;\n            add_edge(ax, ay, bx, by, c,\
    \ margin);\n        }\n    }\n    inline void input_arcs(int M, int margin = 0,\
    \ bool need_cost = false) {\n        for (int i = 0; i < M; ++i) {\n         \
    \   int ax, ay, bx, by;\n            T c(1);\n            cin >> ax >> ay >> bx\
    \ >> by;\n            if (need_cost) cin >> c;\n            add_arc(ax, ay, bx,\
    \ by, c, margin);\n        }\n    }\n    template <typename B, typename C>\n \
    \   inline void load_board(const B &board, const C ng, const T cost = 1, const\
    \ int neighbor = 4) {\n        assert(board.size() == H);\n        if (H > 0)\
    \ assert(board[0].size() == W);\n        assert(neighbor >= 1 and neighbor <=\
    \ 9);\n        for (int h = 0; h < H; ++h) {\n            for (int w = 0; w <\
    \ W; ++w) {\n                if (board[h][w] == ng) continue;\n              \
    \  for (int i = 0; i < neighbor; ++i) {\n                    int nh = h + Gdx[i];\n\
    \                    int nw = w + Gdy[i];\n                    if (not inside(nh,\
    \ nw)) continue;\n                    if (board[nh][nw] == ng) continue;\n   \
    \                 add_arc(h, w, nh, nw, cost);\n                }\n          \
    \  }\n        }\n    }\n};\n"
  code: "/**\n* @brief \u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5\n* @docs docs/graph/gridgraph.md\n\
    */\n\ntemplate <typename T = int>\nstruct GridGraph : Graph<T> {\n    using Graph<T>::V;\n\
    \    using Graph<T>::E;\n    using Graph<T>::mat;\n    const int Gdx[9] = { 1,\
    \ 0, -1, 0, 1, -1, -1, 1, 0 };\n    const int Gdy[9] = { 0, 1, 0, -1, -1, -1,\
    \ 1, 1, 0 };\n    int H, W;\n    GridGraph() {}\n    GridGraph(int h, int w)\n\
    \        : H(h), W(w) {\n        V = h * w;\n        E = 0;\n        mat.resize(V);\n\
    \    }\n    inline bool inside(const int h, const int w) const {\n        return\
    \ h >= 0 and w >= 0 and h < H and w < W;\n    }\n    inline int hash(const int\
    \ h, const int w, const int margin = 0) const {\n        return (h - margin) *\
    \ W + (w - margin);\n    }\n    inline void add_edge(int ax, int ay, int bx, int\
    \ by, T c = 1, int margin = 0) {\n        ax -= margin, ay -= margin, bx -= margin,\
    \ by -= margin;\n        int a = hash(ax, ay), b = hash(bx, by);\n        mat[a].emplace_back(a,\
    \ b, c, E++);\n        mat[b].emplace_back(b, a, c, E++);\n    }\n    inline void\
    \ add_edge(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {\n\
    \        int ax, ay, bx, by;\n        tie(ax, ay) = ap;\n        tie(bx, by) =\
    \ bp;\n        ax -= margin, ay -= margin, bx -= margin, by -= margin;\n     \
    \   int a = hash(ax, ay), b = hash(bx, by);\n        mat[a].emplace_back(a, b,\
    \ c, E++);\n        mat[b].emplace_back(b, a, c, E++);\n    }\n    inline void\
    \ add_arc(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {\n       \
    \ ax -= margin, ay -= margin, bx -= margin, by -= margin;\n        int a = hash(ax,\
    \ ay), b = hash(bx, by);\n        mat[a].emplace_back(a, b, c, E++);\n    }\n\
    \    inline void add_arc(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin\
    \ = 0) {\n        int ax, ay, bx, by;\n        tie(ax, ay) = ap;\n        tie(bx,\
    \ by) = bp;\n        ax -= margin, ay -= margin, bx -= margin, by -= margin;\n\
    \        int a = hash(ax, ay), b = hash(bx, by);\n        mat[a].emplace_back(a,\
    \ b, c, E++);\n    }\n    inline void input_edges(int M, int margin = 0, bool\
    \ need_cost = false) {\n        for (int i = 0; i < M; ++i) {\n            int\
    \ ax, ay, bx, by;\n            T c(1);\n            cin >> ax >> ay >> bx >> by;\n\
    \            if (need_cost) cin >> c;\n            add_edge(ax, ay, bx, by, c,\
    \ margin);\n        }\n    }\n    inline void input_arcs(int M, int margin = 0,\
    \ bool need_cost = false) {\n        for (int i = 0; i < M; ++i) {\n         \
    \   int ax, ay, bx, by;\n            T c(1);\n            cin >> ax >> ay >> bx\
    \ >> by;\n            if (need_cost) cin >> c;\n            add_arc(ax, ay, bx,\
    \ by, c, margin);\n        }\n    }\n    template <typename B, typename C>\n \
    \   inline void load_board(const B &board, const C ng, const T cost = 1, const\
    \ int neighbor = 4) {\n        assert(board.size() == H);\n        if (H > 0)\
    \ assert(board[0].size() == W);\n        assert(neighbor >= 1 and neighbor <=\
    \ 9);\n        for (int h = 0; h < H; ++h) {\n            for (int w = 0; w <\
    \ W; ++w) {\n                if (board[h][w] == ng) continue;\n              \
    \  for (int i = 0; i < neighbor; ++i) {\n                    int nh = h + Gdx[i];\n\
    \                    int nw = w + Gdy[i];\n                    if (not inside(nh,\
    \ nw)) continue;\n                    if (board[nh][nw] == ng) continue;\n   \
    \                 add_arc(h, w, nh, nw, cost);\n                }\n          \
    \  }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/gridgraph.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/20.test.cpp
  - test/yukicoder/13.test.cpp
  - test/aoj/2945.test.cpp
documentation_of: graph/gridgraph.hpp
layout: document
redirect_from:
- /library/graph/gridgraph.hpp
- /library/graph/gridgraph.hpp.html
title: "\u30B0\u30EA\u30C3\u30C9\u30B0\u30E9\u30D5"
---
## 概要

グリッドグラフのテンプレート.

## 使用例

* `GridGraph<int> g(H, W)` : $H \times W$のグリッドグラフを定義.
  * C++17以降なら`<int>`が省略できる.
* `g.inside(h, w)` : グリッド内部かを判定する.
* `g.hash(h, w)` : $(h, w)$を$[0, H * W)$にマッピングする.
  * 第3引数に`margin`が指定できる.
* `add_edge`, `add_arc` : `int`2つずつ, もしくは`pair<int, int>`1つずつを渡す.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `Ux Uy Vx Vy cst`
    * `false` : `Ux Uy Vx Vy`
* `g.load_board(board, ng, cost, neighbor)` : ボードから張るべき辺を探す.
  * `board` : グリッドを表すボード(`vector<string>`, `vector<vector<int>>`など).
  * `ng` : 進入できないマスを表す要素(`'#'`など).
  * `cost` : 各辺のコスト.
  * `neighbor` : 何近傍に進めるか.
    * $2$ : 右か下のマス ($x$, $y$が増える方向).
    * $4$ : 上下左右のマス.
    * $8$ : 上下左右と斜めのマス.
