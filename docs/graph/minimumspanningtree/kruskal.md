## 概要

最小全域木を求めるアルゴリズム. 内部でUnionFindを使用している.

## 計算量

$O(E\log V)$

## 使用例

* `g.kruskal()` : クラスカル法を行う.
  * 返り値 : 最小全域木の重さ.