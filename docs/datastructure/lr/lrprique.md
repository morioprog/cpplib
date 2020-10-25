## 概要

$k$番目の値を高速に取り出せるデータ構造.

## 計算量

- 追加 : $O(\log n)$
- 取得 : $O(\log n)$
  - $f$次第ではオーダーが壊れる
    - 「$k$が固定」や「中央値」は大丈夫

## 使用例

- `LRPrique<ll> lr([](int sz) -> int { return (sz + 1) / 2; })` : 中央値を管理する.
- `LRPrique<ll> lr([](int sz) -> int { return 3; })` : 下から$3$番目の数を管理する.
- `lr.emplace(x)` : $x$を挿入.
- `lr.get()` : $f(sz)$番目の数を取得.
