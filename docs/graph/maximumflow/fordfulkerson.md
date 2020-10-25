## 概要

最大流を求めるアルゴリズム.

## 計算量

$O(EF)$

* $F$ : 最大フロー

## 使用例

* `FordFulkerson<int> ff(V)` : $V$頂点のグラフを定義.
  * 容量の型 : `int`
* `ff.add_arc(u, v, c)` : $u$から$v$に容量$c$の有向辺を張る.
* `ff.add_edge(u, v, c)` : $u$から$v$に容量$c$の無向辺を張る.
* `ff.max_flow(s, t)` : $s$から$t$への最大流を求める.
