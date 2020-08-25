## 概要

$\mathbb{F}_2$上の行列演算のための構造体.

## 計算量

- ガウスの消去法 : $O(RC^2)$
- 連立一次方程式 : $O(RC^2)$

## 使用例

- `BitMatrix<n, m> mat` : $n$行$m$列の行列を定義.
- `BitMatrix<n> mat` : $n$行$n$列の行列を定義.
- `cout << mat` : 分かりやすい形で出力.
- `mat ^= r` : 行列累乗.
- `mat[i][j]` : $i$行$j$列目の要素を取得.
- `mat.gaussian_elimination(is_extended)` : ガウスの消去法.
  - `is_extend` : 拡大係数行列かどうか.
- `mat.linear_equation(b, x)` : 連立一次方程式$Ax = b$を解く.
  - `x` : 答えを格納する.
  - 返り値: ランク(解が存在しなければ$-1$).
