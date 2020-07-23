## 概要

一点加算クエリと区間和クエリを対数時間で行うデータ構造.

## 計算量

* 構築 : $O(n)$
* 区間取得 : $O(\log n)$
* 二分探索 : $O(\log n)$

## 使用例

* `BinaryIndexedTree<int> bit(N)` : 要素数$N$のBIT
* `bit.add(k, x)` : $k$要素目に$x$を加算.
* `bit.sum(k)` : 閉区間$[0, k]$の和を求める
* `bit.sum(l, r)` : 半開区間$[l, r)$の和を求める

