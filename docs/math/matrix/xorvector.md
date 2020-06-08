## 概要

掃き出せる`vector<long long>`.

## 計算量

* 掃き出し法 : $O(nb)$ ($b$はビットサイズ)

## 使用例

* `XorVector vec(n)` : 最大サイズ$n$の`vector`を定義.
* `vec.emplace(m)` : $m$を追加.
* `vec.find(m)` : いくつかの要素のXORが$m$になるかを返す.
* `vec.gaussian_elimination()` : 掃き出し法.
* `vec.print()` : デバッグ出力.

## 問題例

* [ABC141F - Xor Sum 3](https://atcoder.jp/contests/abc141/tasks/abc141_f)
* [AGC045A - Xor Battle](https://atcoder.jp/contests/agc045/tasks/agc045_a)
