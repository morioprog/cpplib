## 概要

グラフのテンプレート.

### 最短経路

* ダイクストラ法 : 単一始点最短路. 辺の重みが非負である必要がある. $O(E\log V)$
* ベルマンフォード法 : 単一始点最短路. 負閉路検出ができる. $O(EV)$
* ワーシャルフロイド法 : 全点間最短路. 負閉路検出ができる. $O(V^3)$
  * 辺の追加は$O(V^2)$

## 使用例

* `Graph<int> g(V)` : $V$頂点のグラフを定義.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `U V cst`
    * `false` : `U V`
* `GINF<int>` : グラフアルゴリズムで使う`INF`.
