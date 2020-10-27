---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/determinantofmatrix.test.cpp
    title: test/yosupo/determinantofmatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/matrix/matrix.md
    document_title: "Matrix (\u884C\u5217)"
    links: []
  bundledCode: "#line 1 \"math/matrix/matrix.hpp\"\n/**\n* @brief Matrix (\u884C\u5217\
    )\n* @docs docs/math/matrix/matrix.md\n*/\n\ntemplate <typename T>\nstruct Matrix\
    \ {\n    vector<vector<T>> A;\n    Matrix() {}\n    Matrix(size_t n, size_t m)\n\
    \        : A(n, vector<T>(m, 0)) {}\n    Matrix(size_t n)\n        : A(n, vector<T>(n,\
    \ 0)) {}\n    size_t height() const { return A.size(); }\n    size_t width() const\
    \ {\n        assert(height() > 0);\n        return A[0].size();\n    }\n    inline\
    \ const vector<T> &operator[](int k) const { return A.at(k); }\n    inline vector<T>\
    \ &operator[](int k) { return A.at(k); }\n    static Matrix I(size_t n) {\n  \
    \      Matrix mat(n);\n        for (int i = 0; i < n; ++i) mat[i][i] = 1;\n  \
    \      return mat;\n    }\n    Matrix &operator+=(const Matrix &B) {\n       \
    \ size_t n = height(), m = width();\n        assert(n == B.height() and m == B.width());\n\
    \        for (int i = 0; i < n; ++i)\n            for (int j = 0; j < m; ++j)\n\
    \                (*this)[i][j] += B[i][j];\n        return *this;\n    }\n   \
    \ Matrix &operator-=(const Matrix &B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() and m == B.width());\n        for (int i = 0;\
    \ i < n; ++i)\n            for (int j = 0; j < m; ++j)\n                (*this)[i][j]\
    \ -= B[i][j];\n        return *this;\n    }\n    Matrix &operator*=(const Matrix\
    \ &B) {\n        size_t n = height(), m = B.width(), p = width();\n        assert(p\
    \ == B.height());\n        vector<vector<T>> C(n, vector<T>(m, 0));\n        for\
    \ (int i = 0; i < n; ++i)\n            for (int j = 0; j < m; ++j)\n         \
    \       for (int k = 0; k < p; ++k)\n                    C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n        A.swap(C);\n        return *this;\n    }\n    Matrix &operator^=(long\
    \ long k) {\n        Matrix B = Matrix::I(height());\n        while (k > 0) {\n\
    \            if (k & 1) B *= *this;\n            *this *= *this;\n           \
    \ k >>= 1LL;\n        }\n        A.swap(B.A);\n        return *this;\n    }\n\
    \    Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B); }\n\
    \    Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B); }\n\
    \    Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B); }\n\
    \    Matrix operator^(const long long k) const { return (Matrix(*this) ^= k);\
    \ }\n    friend istream &operator>>(istream &is, Matrix &p) {\n        size_t\
    \ n = p.height(), m = p.width();\n        for (int i = 0; i < n; ++i) {\n    \
    \        for (int j = 0; j < m; ++j) {\n                is >> p[i][j];\n     \
    \       }\n        }\n        return is;\n    }\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p) {\n        size_t n = p.height(), m = p.width();\n        for\
    \ (int i = 0; i < n; ++i) {\n            os << '[';\n            for (int j =\
    \ 0; j < m; ++j) {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\" :\
    \ \", \");\n            }\n        }\n        return os;\n    }\n    T determinant()\
    \ {\n        Matrix B(*this);\n        assert(width() == height());\n        T\
    \ ret = 1;\n        for (int i = 0; i < width(); ++i) {\n            int idx =\
    \ -1;\n            for (int j = i; j < width(); ++j)\n                if (B[j][i]\
    \ != 0) idx = j;\n            if (idx == -1) return T(0);\n            if (i !=\
    \ idx) {\n                ret *= -1;\n                swap(B[i], B[idx]);\n  \
    \          }\n            ret *= B[i][i];\n            T vv = B[i][i];\n     \
    \       for (int j = 0; j < width(); ++j) B[i][j] /= vv;\n            for (int\
    \ j = i + 1; j < width(); ++j) {\n                T a = B[j][i];\n           \
    \     for (int k = 0; k < width(); ++k) B[j][k] -= B[i][k] * a;\n            }\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "/**\n* @brief Matrix (\u884C\u5217)\n* @docs docs/math/matrix/matrix.md\n\
    */\n\ntemplate <typename T>\nstruct Matrix {\n    vector<vector<T>> A;\n    Matrix()\
    \ {}\n    Matrix(size_t n, size_t m)\n        : A(n, vector<T>(m, 0)) {}\n   \
    \ Matrix(size_t n)\n        : A(n, vector<T>(n, 0)) {}\n    size_t height() const\
    \ { return A.size(); }\n    size_t width() const {\n        assert(height() >\
    \ 0);\n        return A[0].size();\n    }\n    inline const vector<T> &operator[](int\
    \ k) const { return A.at(k); }\n    inline vector<T> &operator[](int k) { return\
    \ A.at(k); }\n    static Matrix I(size_t n) {\n        Matrix mat(n);\n      \
    \  for (int i = 0; i < n; ++i) mat[i][i] = 1;\n        return mat;\n    }\n  \
    \  Matrix &operator+=(const Matrix &B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() and m == B.width());\n        for (int i = 0;\
    \ i < n; ++i)\n            for (int j = 0; j < m; ++j)\n                (*this)[i][j]\
    \ += B[i][j];\n        return *this;\n    }\n    Matrix &operator-=(const Matrix\
    \ &B) {\n        size_t n = height(), m = width();\n        assert(n == B.height()\
    \ and m == B.width());\n        for (int i = 0; i < n; ++i)\n            for (int\
    \ j = 0; j < m; ++j)\n                (*this)[i][j] -= B[i][j];\n        return\
    \ *this;\n    }\n    Matrix &operator*=(const Matrix &B) {\n        size_t n =\
    \ height(), m = B.width(), p = width();\n        assert(p == B.height());\n  \
    \      vector<vector<T>> C(n, vector<T>(m, 0));\n        for (int i = 0; i < n;\
    \ ++i)\n            for (int j = 0; j < m; ++j)\n                for (int k =\
    \ 0; k < p; ++k)\n                    C[i][j] += (*this)[i][k] * B[k][j];\n  \
    \      A.swap(C);\n        return *this;\n    }\n    Matrix &operator^=(long long\
    \ k) {\n        Matrix B = Matrix::I(height());\n        while (k > 0) {\n   \
    \         if (k & 1) B *= *this;\n            *this *= *this;\n            k >>=\
    \ 1LL;\n        }\n        A.swap(B.A);\n        return *this;\n    }\n    Matrix\
    \ operator+(const Matrix &B) const { return (Matrix(*this) += B); }\n    Matrix\
    \ operator-(const Matrix &B) const { return (Matrix(*this) -= B); }\n    Matrix\
    \ operator*(const Matrix &B) const { return (Matrix(*this) *= B); }\n    Matrix\
    \ operator^(const long long k) const { return (Matrix(*this) ^= k); }\n    friend\
    \ istream &operator>>(istream &is, Matrix &p) {\n        size_t n = p.height(),\
    \ m = p.width();\n        for (int i = 0; i < n; ++i) {\n            for (int\
    \ j = 0; j < m; ++j) {\n                is >> p[i][j];\n            }\n      \
    \  }\n        return is;\n    }\n    friend ostream &operator<<(ostream &os, Matrix\
    \ &p) {\n        size_t n = p.height(), m = p.width();\n        for (int i = 0;\
    \ i < n; ++i) {\n            os << '[';\n            for (int j = 0; j < m; ++j)\
    \ {\n                os << p[i][j] << (j + 1 == m ? \"]\\n\" : \", \");\n    \
    \        }\n        }\n        return os;\n    }\n    T determinant() {\n    \
    \    Matrix B(*this);\n        assert(width() == height());\n        T ret = 1;\n\
    \        for (int i = 0; i < width(); ++i) {\n            int idx = -1;\n    \
    \        for (int j = i; j < width(); ++j)\n                if (B[j][i] != 0)\
    \ idx = j;\n            if (idx == -1) return T(0);\n            if (i != idx)\
    \ {\n                ret *= -1;\n                swap(B[i], B[idx]);\n       \
    \     }\n            ret *= B[i][i];\n            T vv = B[i][i];\n          \
    \  for (int j = 0; j < width(); ++j) B[i][j] /= vv;\n            for (int j =\
    \ i + 1; j < width(); ++j) {\n                T a = B[j][i];\n               \
    \ for (int k = 0; k < width(); ++k) B[j][k] -= B[i][k] * a;\n            }\n \
    \       }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1050.test.cpp
  - test/yosupo/determinantofmatrix.test.cpp
documentation_of: math/matrix/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix/matrix.hpp
- /library/math/matrix/matrix.hpp.html
title: "Matrix (\u884C\u5217)"
---
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
