## 概要

最大流を求めるアルゴリズム.

## 計算量

$O(EV^2)$

## 使用例

* `Dinic<int> dnc(V)` : $V$頂点のグラフを定義.
  * 容量の型 : `int`
* `dnc.add_arc(u, v, c)` : $u$から$v$に容量$c$の有向辺を張る.
* `dnc.add_edge(u, v, c)` : $u$から$v$に容量$c$の無向辺を張る.
* `dnc.max_flow(s, t)` : $s$から$t$への最大流を求める.
