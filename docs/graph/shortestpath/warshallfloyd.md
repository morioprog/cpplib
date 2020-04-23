## 概要

全点間最短路. 負閉路検出ができる.

## 計算量

* 構築 : $O(V^3)$
* 更新 : $O(V^2)$

## 使用例

* `g.warshallfloyd()` : ワーシャルフロイド法を行う.
  * 結果は`g.wf`に格納される.
  * 返り値の型 : `bool`
  * 負閉路があったら`true`を返す.
* `g.warshallfloyd_add_arc(frm, to, cst)` : 有向辺を追加して, `g.wf`を更新.
* `g.warshallfloyd_add_edge(frm, to, cst)` : 無向辺を追加して, `g.wf`を更新.
