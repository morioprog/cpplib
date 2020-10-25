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
