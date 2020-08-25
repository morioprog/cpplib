---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: BitMatrix <small>(math/matrix/bitmatrix.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a9839e7477a4d9c748aee996b52a14d5">math/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix/bitmatrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 20:54:10+09:00


* see: <a href="https://drken1215.hatenablog.com/entry/2019/03/20/202800">https://drken1215.hatenablog.com/entry/2019/03/20/202800</a>


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


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief BitMatrix
* @docs docs/math/matrix/bitmatrix.md
* @see https://drken1215.hatenablog.com/entry/2019/03/20/202800
*/

template <int H, int W = H>
struct BitMatrix {
    bitset<W> mat[H];
    BitMatrix() {}
    size_t height() const { return H; }
    size_t width() const { return W; }
    inline const bitset<W> &operator[](int idx) const { return mat[idx]; }
    inline bitset<W> &operator[](int idx) { return mat[idx]; }
    BitMatrix &operator&=(const BitMatrix &m) {
        for (int i = 0; i < height(); ++i) (*this)[i] &= m[i];
        return *this;
    }
    BitMatrix &operator|=(const BitMatrix &m) {
        for (int i = 0; i < height(); ++i) (*this)[i] |= m[i];
        return *this;
    }
    BitMatrix operator&(const BitMatrix &m) const { return (BitMatrix(*this) &= m); }
    BitMatrix operator|(const BitMatrix &m) const { return (BitMatrix(*this) |= m); }
    int gaussian_elimination(bool is_extended = false) {
        int rnk = 0;
        for (int j = 0; j < width(); ++j) {
            if (is_extended and j == width() - 1) break;
            int piv = -1;
            for (int i = rnk; i < height(); ++i) {
                if ((*this)[i][j]) {
                    piv = i;
                    break;
                }
            }
            if (piv == -1) continue;
            swap((*this)[piv], (*this)[rnk]);
            for (int i = 0; i < height(); ++i)
                if (i != rnk and (*this)[i][j]) (*this)[i] ^= (*this)[rnk];
            ++rnk;
        }
        return rnk;
    }
    int linear_equation(vector<int> b, vector<int> &res) {
        const int r = height(), c = width();
        BitMatrix<r, c + 1> m;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                m[i][j] = (*this)[i][j];
            }
            m[i][c] = b[i];
        }
        int rnk = gaussian_elimination(true);
        for (int i = rnk; i < r; ++i)
            if (m[i][c]) return -1;
        res.assign(c, 0);
        for (int i = 0; i < rnk; ++i) res[i] = m[i][c];
        return rnk;
    }
    template <int A, int B, int C>
    friend BitMatrix<A, C> operator*(const BitMatrix<A, B> &m1, const BitMatrix<B, C> &m2) {
        BitMatrix<A, C> ret;
        BitMatrix<C, B> tmp;
        for (int i = 0; i < C; ++i)
            for (int j = 0; j < B; ++j)
                tmp[i][j] = m2[j][i];
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < C; ++j)
                ret[i][j] = (m1[i] & tmp[j]).count() & 1;
        return ret;
    }
    template <int A>
    friend BitMatrix<A> bmat_pow(BitMatrix<A> m, unsigned long long n) {
        BitMatrix<A> ret;
        for (int i = 0; i < ret.height(); ++i) ret[i][i] = 1;
        while (n > 0) {
            if (n & 1) ret = ret * m;
            m = m * m;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const BitMatrix &m) {
        for (int i = 0; i < m.height(); ++i) {
            for (int j = 0; j < m.width(); ++j) {
                if (j > 0) os << ", ";
                os << m[i][j];
            }
            os << endl;
        }
        return os;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix/bitmatrix.hpp"
/**
* @brief BitMatrix
* @docs docs/math/matrix/bitmatrix.md
* @see https://drken1215.hatenablog.com/entry/2019/03/20/202800
*/

template <int H, int W = H>
struct BitMatrix {
    bitset<W> mat[H];
    BitMatrix() {}
    size_t height() const { return H; }
    size_t width() const { return W; }
    inline const bitset<W> &operator[](int idx) const { return mat[idx]; }
    inline bitset<W> &operator[](int idx) { return mat[idx]; }
    BitMatrix &operator&=(const BitMatrix &m) {
        for (int i = 0; i < height(); ++i) (*this)[i] &= m[i];
        return *this;
    }
    BitMatrix &operator|=(const BitMatrix &m) {
        for (int i = 0; i < height(); ++i) (*this)[i] |= m[i];
        return *this;
    }
    BitMatrix operator&(const BitMatrix &m) const { return (BitMatrix(*this) &= m); }
    BitMatrix operator|(const BitMatrix &m) const { return (BitMatrix(*this) |= m); }
    int gaussian_elimination(bool is_extended = false) {
        int rnk = 0;
        for (int j = 0; j < width(); ++j) {
            if (is_extended and j == width() - 1) break;
            int piv = -1;
            for (int i = rnk; i < height(); ++i) {
                if ((*this)[i][j]) {
                    piv = i;
                    break;
                }
            }
            if (piv == -1) continue;
            swap((*this)[piv], (*this)[rnk]);
            for (int i = 0; i < height(); ++i)
                if (i != rnk and (*this)[i][j]) (*this)[i] ^= (*this)[rnk];
            ++rnk;
        }
        return rnk;
    }
    int linear_equation(vector<int> b, vector<int> &res) {
        const int r = height(), c = width();
        BitMatrix<r, c + 1> m;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                m[i][j] = (*this)[i][j];
            }
            m[i][c] = b[i];
        }
        int rnk = gaussian_elimination(true);
        for (int i = rnk; i < r; ++i)
            if (m[i][c]) return -1;
        res.assign(c, 0);
        for (int i = 0; i < rnk; ++i) res[i] = m[i][c];
        return rnk;
    }
    template <int A, int B, int C>
    friend BitMatrix<A, C> operator*(const BitMatrix<A, B> &m1, const BitMatrix<B, C> &m2) {
        BitMatrix<A, C> ret;
        BitMatrix<C, B> tmp;
        for (int i = 0; i < C; ++i)
            for (int j = 0; j < B; ++j)
                tmp[i][j] = m2[j][i];
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < C; ++j)
                ret[i][j] = (m1[i] & tmp[j]).count() & 1;
        return ret;
    }
    template <int A>
    friend BitMatrix<A> bmat_pow(BitMatrix<A> m, unsigned long long n) {
        BitMatrix<A> ret;
        for (int i = 0; i < ret.height(); ++i) ret[i][i] = 1;
        while (n > 0) {
            if (n & 1) ret = ret * m;
            m = m * m;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const BitMatrix &m) {
        for (int i = 0; i < m.height(); ++i) {
            for (int j = 0; j < m.width(); ++j) {
                if (j > 0) os << ", ";
                os << m[i][j];
            }
            os << endl;
        }
        return os;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

