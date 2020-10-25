## 概要

$k$番目の値を高速に取り出せるデータ構造. 削除を行えるが定数倍が少し重い.

## 計算量

- 追加 : $O(\log n)$
- 削除 : $O(\log n)$
- 取得 : $O(\log n)$
  - $k$が固定, 中央値
  - $f$次第ではオーダーが壊れる

## 使用例

- `LRMultiSet<ll> lr([](int sz) -> int { return (sz + 1) / 2; })` : 中央値を管理する.
- `LRMultiSet<ll> lr([](int sz) -> int { return 3; })` : 下から$3$番目の数を管理する.
- `lr.emplace(x)` : $x$を挿入.
- `lr.erase(x)` : $x$を削除.
- `lr.get()` : $f(sz)$番目の数を取得.
