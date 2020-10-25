## 概要

連結成分と**ノード間の距離**を管理するデータ構造.

## 計算量

$O(\alpha (n))$

## 使用例

* `WeightedUnionFind uf(V)` : $V$頂点の重み付きUnionFindを定義.
* `uf.unite(x, y, w)` : $x$と$y$を連結にする.
  * このとき, $\mathrm{weight}(y) = \mathrm{weight}(x) + w$となるようにする.
* `uf.same(x, y)` : $x$と$y$が連結かを返す.
* `uf.size(x)` : $x$の属する連結成分の大きさを返す.
* `uf.size()` : 連結成分の個数を返す.
