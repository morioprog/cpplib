## 概要

${}_{n}\mathrm{C}_{r}$, ${}_{n}\mathrm{P}_{r}$, ${}_{n}\mathrm{H}_{r}$を逆元を用いて求める.

## 計算量

* 前計算 : $O(n)$
* クエリ : $O(1)$

## 使用例

* `Combination<modint> comb` : 準備
* `comb.C(n, r)` : ${}_{n}\mathrm{C}_{r}$に答える
* `comb.getFact(m)` : $m!$に答える
