## 概要

グリッドグラフのテンプレート.

## 使用例

- `GridGraph<int> g(H, W, S = 0)` : $H \times W$のグリッドグラフを定義.
  - `S` : 超頂点の個数
  - C++17 以降なら`<int>`が省略できる.
- `g.inside(h, w)` : グリッド内部かを判定する.
- `g.hash(h, w)` : $(h, w)$を$[0, H * W)$にマッピングする.
  - 第 3 引数に`margin`が指定できる.
- `g.hash_super(s)` : 超頂点$s$をマッピングする.
- `add_edge`, `add_arc` : `int`2 つずつ, `pair<int, int>`1 つずつ, `int`1 つずつを渡す.
- `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
- `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  - `origin` : 辺を何 origin で受け取るか.
  - `need_cost` : コストを受け取るか.
    - `true` : `Ux Uy Vx Vy cst`
    - `false` : `Ux Uy Vx Vy`
- `g.load_board(board, ng, cost, neighbor)` : ボードから張るべき辺を探す.
  - `board` : グリッドを表すボード(`vector<string>`, `vector<vector<int>>`など).
  - `ng` : 進入できないマスを表す要素(`'#'`など).
  - `cost` : 各辺のコスト.
  - `neighbor` : 何近傍に進めるか.
    - $2$ : 右か下のマス ($x$, $y$が増える方向).
    - $4$ : 上下左右のマス.
    - $8$ : 上下左右と斜めのマス.
