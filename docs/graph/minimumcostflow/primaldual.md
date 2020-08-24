## 概要

最小費用流を求めるアルゴリズム.

## 計算量

$O(FE\log V)$

* $O(UCV^2)$で求めるアルゴリズムもある.
  * $U$ : 容量合計
  * $C$ : 費用合計
  * 参考 : <http://www.prefield.com/algorithm/graph/primal_dual.html>

## 使用例

* `PrimalDual<Cst, Cap> pd(V)` : $V$頂点のグラフを定義.
  * コストの型 : `Cst`
  * 容量の型 : `Cap`
* `pd.add_arc(u, v, cst, cap)` : $u$から$v$にコスト$cst$, 容量$cap$の有向辺を張る.
* `pd.min_cost_flow(s, t, f)` : $s$から$t$へ流量$f$での最小費用流を求める.
