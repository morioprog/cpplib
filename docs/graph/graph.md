## 概要

グラフ関連のアルゴリズム.

* ダイクストラ法 : 単一始点最短路. $O(E\log V)$

## 使用例

* `Graph<int> g(V)` : $V$頂点のグラフを定義.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `U V cst`
    * `false` : `U V`
* `g.dijkstra(frm)` : `frm`からダイクストラ法.
  * 返り値の型 : `vector<T>`
