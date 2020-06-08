## 概要

全体をfoldしたものを$O(1)$で答えられるQueue.

渡す二項演算$f$は結合律を満たす必要がある.

* 結合律 : $f(f(x, y), z) = f(x, f(y, z))$

## 計算量

$O(1)$

## 使用例

* `QueueAggregation<int> swag([](int a, int b){ return min(a, b); })` : 最小クエリを処理するSWAG.
* `swag.push(x)` : $x$をpush.
* `swag.pop()` : SWAGからpop.
* `swag.query()` : 全体をfold.
