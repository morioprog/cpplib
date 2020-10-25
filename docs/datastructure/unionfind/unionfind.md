## 概要

連結成分を管理するデータ構造. [素集合データ構造](https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0).

## 計算量

$O(\alpha (n))$

## 使用例

* `UnionFind uf(V)` : $V$頂点のUnionFindを定義.
* `uf.unite(x, y)` : $x$と$y$を連結にする.
* `uf.same(x, y)` : $x$と$y$が連結かを返す.
* `uf.size(x)` : $x$の属する連結成分の大きさを返す.
* `uf.size()` : 連結成分の個数を返す.
