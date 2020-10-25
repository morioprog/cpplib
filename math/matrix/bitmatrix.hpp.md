---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/bitmatrix.md
    document_title: BitMatrix
    links:
    - https://drken1215.hatenablog.com/entry/2019/03/20/202800
  bundledCode: "#line 1 \"math/matrix/bitmatrix.hpp\"\n/**\n* @brief BitMatrix\n*\
    \ @docs docs/math/matrix/bitmatrix.md\n* @see https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    */\n\ntemplate <int H, int W = H>\nstruct BitMatrix {\n    bitset<W> mat[H];\n\
    \    BitMatrix() {}\n    size_t height() const { return H; }\n    size_t width()\
    \ const { return W; }\n    inline const bitset<W> &operator[](int idx) const {\
    \ return mat[idx]; }\n    inline bitset<W> &operator[](int idx) { return mat[idx];\
    \ }\n    BitMatrix &operator&=(const BitMatrix &m) {\n        for (int i = 0;\
    \ i < height(); ++i) (*this)[i] &= m[i];\n        return *this;\n    }\n    BitMatrix\
    \ &operator|=(const BitMatrix &m) {\n        for (int i = 0; i < height(); ++i)\
    \ (*this)[i] |= m[i];\n        return *this;\n    }\n    BitMatrix operator&(const\
    \ BitMatrix &m) const { return (BitMatrix(*this) &= m); }\n    BitMatrix operator|(const\
    \ BitMatrix &m) const { return (BitMatrix(*this) |= m); }\n    int gaussian_elimination(bool\
    \ is_extended = false) {\n        int rnk = 0;\n        for (int j = 0; j < width();\
    \ ++j) {\n            if (is_extended and j == width() - 1) break;\n         \
    \   int piv = -1;\n            for (int i = rnk; i < height(); ++i) {\n      \
    \          if ((*this)[i][j]) {\n                    piv = i;\n              \
    \      break;\n                }\n            }\n            if (piv == -1) continue;\n\
    \            swap((*this)[piv], (*this)[rnk]);\n            for (int i = 0; i\
    \ < height(); ++i)\n                if (i != rnk and (*this)[i][j]) (*this)[i]\
    \ ^= (*this)[rnk];\n            ++rnk;\n        }\n        return rnk;\n    }\n\
    \    int linear_equation(vector<int> b, vector<int> &res) {\n        const int\
    \ r = height(), c = width();\n        BitMatrix<r, c + 1> m;\n        for (int\
    \ i = 0; i < r; ++i) {\n            for (int j = 0; j < c; ++j) {\n          \
    \      m[i][j] = (*this)[i][j];\n            }\n            m[i][c] = b[i];\n\
    \        }\n        int rnk = gaussian_elimination(true);\n        for (int i\
    \ = rnk; i < r; ++i)\n            if (m[i][c]) return -1;\n        res.assign(c,\
    \ 0);\n        for (int i = 0; i < rnk; ++i) res[i] = m[i][c];\n        return\
    \ rnk;\n    }\n    template <int A, int B, int C>\n    friend BitMatrix<A, C>\
    \ operator*(const BitMatrix<A, B> &m1, const BitMatrix<B, C> &m2) {\n        BitMatrix<A,\
    \ C> ret;\n        BitMatrix<C, B> tmp;\n        for (int i = 0; i < C; ++i)\n\
    \            for (int j = 0; j < B; ++j)\n                tmp[i][j] = m2[j][i];\n\
    \        for (int i = 0; i < A; ++i)\n            for (int j = 0; j < C; ++j)\n\
    \                ret[i][j] = (m1[i] & tmp[j]).count() & 1;\n        return ret;\n\
    \    }\n    template <int A>\n    friend BitMatrix<A> bmat_pow(BitMatrix<A> m,\
    \ unsigned long long n) {\n        BitMatrix<A> ret;\n        for (int i = 0;\
    \ i < ret.height(); ++i) ret[i][i] = 1;\n        while (n > 0) {\n           \
    \ if (n & 1) ret = ret * m;\n            m = m * m;\n            n >>= 1;\n  \
    \      }\n        return ret;\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const BitMatrix &m) {\n        for (int i = 0; i < m.height(); ++i) {\n    \
    \        for (int j = 0; j < m.width(); ++j) {\n                if (j > 0) os\
    \ << \", \";\n                os << m[i][j];\n            }\n            os <<\
    \ endl;\n        }\n        return os;\n    }\n};\n"
  code: "/**\n* @brief BitMatrix\n* @docs docs/math/matrix/bitmatrix.md\n* @see https://drken1215.hatenablog.com/entry/2019/03/20/202800\n\
    */\n\ntemplate <int H, int W = H>\nstruct BitMatrix {\n    bitset<W> mat[H];\n\
    \    BitMatrix() {}\n    size_t height() const { return H; }\n    size_t width()\
    \ const { return W; }\n    inline const bitset<W> &operator[](int idx) const {\
    \ return mat[idx]; }\n    inline bitset<W> &operator[](int idx) { return mat[idx];\
    \ }\n    BitMatrix &operator&=(const BitMatrix &m) {\n        for (int i = 0;\
    \ i < height(); ++i) (*this)[i] &= m[i];\n        return *this;\n    }\n    BitMatrix\
    \ &operator|=(const BitMatrix &m) {\n        for (int i = 0; i < height(); ++i)\
    \ (*this)[i] |= m[i];\n        return *this;\n    }\n    BitMatrix operator&(const\
    \ BitMatrix &m) const { return (BitMatrix(*this) &= m); }\n    BitMatrix operator|(const\
    \ BitMatrix &m) const { return (BitMatrix(*this) |= m); }\n    int gaussian_elimination(bool\
    \ is_extended = false) {\n        int rnk = 0;\n        for (int j = 0; j < width();\
    \ ++j) {\n            if (is_extended and j == width() - 1) break;\n         \
    \   int piv = -1;\n            for (int i = rnk; i < height(); ++i) {\n      \
    \          if ((*this)[i][j]) {\n                    piv = i;\n              \
    \      break;\n                }\n            }\n            if (piv == -1) continue;\n\
    \            swap((*this)[piv], (*this)[rnk]);\n            for (int i = 0; i\
    \ < height(); ++i)\n                if (i != rnk and (*this)[i][j]) (*this)[i]\
    \ ^= (*this)[rnk];\n            ++rnk;\n        }\n        return rnk;\n    }\n\
    \    int linear_equation(vector<int> b, vector<int> &res) {\n        const int\
    \ r = height(), c = width();\n        BitMatrix<r, c + 1> m;\n        for (int\
    \ i = 0; i < r; ++i) {\n            for (int j = 0; j < c; ++j) {\n          \
    \      m[i][j] = (*this)[i][j];\n            }\n            m[i][c] = b[i];\n\
    \        }\n        int rnk = gaussian_elimination(true);\n        for (int i\
    \ = rnk; i < r; ++i)\n            if (m[i][c]) return -1;\n        res.assign(c,\
    \ 0);\n        for (int i = 0; i < rnk; ++i) res[i] = m[i][c];\n        return\
    \ rnk;\n    }\n    template <int A, int B, int C>\n    friend BitMatrix<A, C>\
    \ operator*(const BitMatrix<A, B> &m1, const BitMatrix<B, C> &m2) {\n        BitMatrix<A,\
    \ C> ret;\n        BitMatrix<C, B> tmp;\n        for (int i = 0; i < C; ++i)\n\
    \            for (int j = 0; j < B; ++j)\n                tmp[i][j] = m2[j][i];\n\
    \        for (int i = 0; i < A; ++i)\n            for (int j = 0; j < C; ++j)\n\
    \                ret[i][j] = (m1[i] & tmp[j]).count() & 1;\n        return ret;\n\
    \    }\n    template <int A>\n    friend BitMatrix<A> bmat_pow(BitMatrix<A> m,\
    \ unsigned long long n) {\n        BitMatrix<A> ret;\n        for (int i = 0;\
    \ i < ret.height(); ++i) ret[i][i] = 1;\n        while (n > 0) {\n           \
    \ if (n & 1) ret = ret * m;\n            m = m * m;\n            n >>= 1;\n  \
    \      }\n        return ret;\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const BitMatrix &m) {\n        for (int i = 0; i < m.height(); ++i) {\n    \
    \        for (int j = 0; j < m.width(); ++j) {\n                if (j > 0) os\
    \ << \", \";\n                os << m[i][j];\n            }\n            os <<\
    \ endl;\n        }\n        return os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/bitmatrix.hpp
  requiredBy: []
  timestamp: '2020-08-25 20:54:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/bitmatrix.hpp
layout: document
redirect_from:
- /library/math/matrix/bitmatrix.hpp
- /library/math/matrix/bitmatrix.hpp.html
title: BitMatrix
---
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
