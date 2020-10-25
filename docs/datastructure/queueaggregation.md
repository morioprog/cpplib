## 概要

全体を二項演算$f$で畳み込んだものを$O(1)$で答えられるキュー.

渡す$f$は結合律を満たす必要がある.

- 結合律 : $f(f(x, y), z) = f(x, f(y, z))$

## 計算量

$O(1)$

## 使用例

- `QueueAggregation<int> swag([](int a, int b){ return min(a, b); })` : 最小クエリを処理する SWAG.
- `swag.emplace(x)` : $x$を追加.
- `swag.pop()` : `swag`から`pop`.
- `swag.query()` : 全体を$f$で畳んだ結果.
