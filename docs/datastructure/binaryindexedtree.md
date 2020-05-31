## 概要

一点加算クエリと区間和クエリを対数時間で行うデータ構造.

## 計算量

* 構築 : $O(n)$
* 区間取得 : $O(\log n)$

## 使用例

```cpp
BinaryIndexedTree<int> bit(N);      // 要素数NのBIT
bit.add(k, x);                      // 要素kに値xを加算
bit.sum(k);                         // 閉区間[0, k]の和を求める
bit.sum(l, r);                      // 半開区間[l, r)の和を求める
bit.lower_bound(x);                 // sum(i)>=xなる最小のiを求める
```
