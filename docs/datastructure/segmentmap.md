## 概要

**閉**区間を`map`で管理するやつ.

## 計算量

* 各クエリ : $O(\log n)$

## 使用例

* `SegmentMap mp(flg = true)` : 「区間を`map`で管理するやつ」を準備.
  * `flg` : $[l, c]$と$[c + 1, r]$をマージするかどうか.
* `mp.get(p)` : $p$を含む区間を返す. (存在しないなら`mp.end()`)
* `mp.insert(l, r)` : 閉区間$[l, r]$を追加する.
* `mp.remove(l, r)` : 閉区間$[l, r]$を取り除く.
* `mp.same(p, q)` : $2$点$p$, $q$が同じ区間にあれば`true`.
