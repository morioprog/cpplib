## 概要

行列演算のための構造体.

## 計算量

* 行列式 : `O(n^3)`

## 使用例

* `Matrix<int> mat(n, m)` : $n$行$m$列の行列を定義.
* `Matrix<int> mat(n)` : $n$行$n$列の行列を定義.
* `cin >> mat` : 入力を受け取る.
* `cout << mat` : 分かりやすい形で出力.
* `mat ^= r` : 行列累乗.
* `mat[i][j]` : $i$行$j$列目の要素を取得.
* `mat.determinant()` : 行列式.
