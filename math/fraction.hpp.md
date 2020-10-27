---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/750.test.cpp
    title: test/yukicoder/750.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/fraction.md
    document_title: "Fraction (\u5206\u6570)"
    links: []
  bundledCode: "#line 1 \"math/fraction.hpp\"\n/**\n * @brief Fraction (\u5206\u6570\
    )\n * @docs docs/math/fraction.md\n */\n\ntemplate <typename T = long long>\n\
    struct Fraction {\n    T numer, denom;\n    T gcd(T a, T b) { return b ? gcd(b,\
    \ a % b) : a; }\n    Fraction(T n = 0, T d = 1) {\n        T g = gcd(n, d);\n\
    \        assert(d != 0);\n        numer = n / g, denom = d / g;\n        if (denom\
    \ < 0) numer *= -1, denom *= -1;\n    }\n    Fraction operator+(const Fraction\
    \ &f) const { return Fraction(numer * f.denom + denom * f.numer, denom * f.denom);\
    \ }\n    Fraction operator-(const Fraction &f) const { return Fraction(numer *\
    \ f.denom - denom * f.numer, denom * f.denom); }\n    Fraction operator*(const\
    \ Fraction &f) const { return Fraction(numer * f.numer, denom * f.denom); }\n\
    \    Fraction operator/(const Fraction &f) const { return Fraction(numer * f.denom,\
    \ denom * f.numer); }\n    Fraction &operator+=(const Fraction &f) { return *this\
    \ = *this + f; }\n    Fraction &operator-=(const Fraction &f) { return *this =\
    \ *this - f; }\n    Fraction &operator*=(const Fraction &f) { return *this = *this\
    \ * f; }\n    Fraction &operator/=(const Fraction &f) { return *this = *this /\
    \ f; }\n    Fraction operator~() const { return Fraction(denom, numer); }\n  \
    \  bool operator<(const Fraction &f) const { return numer * f.denom < f.numer\
    \ * denom; }\n    bool operator>(const Fraction &f) const { return numer * f.denom\
    \ > f.numer * denom; }\n    bool operator==(const Fraction &f) const { return\
    \ numer == f.numer && denom == f.denom; }\n    bool operator!=(const Fraction\
    \ &f) const { return numer != f.numer || denom != f.denom; }\n    bool operator<=(const\
    \ Fraction &f) const { return numer * f.denom <= f.numer * denom; }\n    bool\
    \ operator>=(const Fraction &f) const { return numer * f.denom >= f.numer * denom;\
    \ }\n    double to_double() const { return (double)numer / denom; }\n    friend\
    \ ostream &operator<<(ostream &os, const Fraction &f) { return os << f.numer <<\
    \ \" / \" << f.denom; }\n};\n"
  code: "/**\n * @brief Fraction (\u5206\u6570)\n * @docs docs/math/fraction.md\n\
    \ */\n\ntemplate <typename T = long long>\nstruct Fraction {\n    T numer, denom;\n\
    \    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }\n    Fraction(T n = 0,\
    \ T d = 1) {\n        T g = gcd(n, d);\n        assert(d != 0);\n        numer\
    \ = n / g, denom = d / g;\n        if (denom < 0) numer *= -1, denom *= -1;\n\
    \    }\n    Fraction operator+(const Fraction &f) const { return Fraction(numer\
    \ * f.denom + denom * f.numer, denom * f.denom); }\n    Fraction operator-(const\
    \ Fraction &f) const { return Fraction(numer * f.denom - denom * f.numer, denom\
    \ * f.denom); }\n    Fraction operator*(const Fraction &f) const { return Fraction(numer\
    \ * f.numer, denom * f.denom); }\n    Fraction operator/(const Fraction &f) const\
    \ { return Fraction(numer * f.denom, denom * f.numer); }\n    Fraction &operator+=(const\
    \ Fraction &f) { return *this = *this + f; }\n    Fraction &operator-=(const Fraction\
    \ &f) { return *this = *this - f; }\n    Fraction &operator*=(const Fraction &f)\
    \ { return *this = *this * f; }\n    Fraction &operator/=(const Fraction &f) {\
    \ return *this = *this / f; }\n    Fraction operator~() const { return Fraction(denom,\
    \ numer); }\n    bool operator<(const Fraction &f) const { return numer * f.denom\
    \ < f.numer * denom; }\n    bool operator>(const Fraction &f) const { return numer\
    \ * f.denom > f.numer * denom; }\n    bool operator==(const Fraction &f) const\
    \ { return numer == f.numer && denom == f.denom; }\n    bool operator!=(const\
    \ Fraction &f) const { return numer != f.numer || denom != f.denom; }\n    bool\
    \ operator<=(const Fraction &f) const { return numer * f.denom <= f.numer * denom;\
    \ }\n    bool operator>=(const Fraction &f) const { return numer * f.denom >=\
    \ f.numer * denom; }\n    double to_double() const { return (double)numer / denom;\
    \ }\n    friend ostream &operator<<(ostream &os, const Fraction &f) { return os\
    \ << f.numer << \" / \" << f.denom; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2020-08-31 14:27:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/750.test.cpp
documentation_of: math/fraction.hpp
layout: document
redirect_from:
- /library/math/fraction.hpp
- /library/math/fraction.hpp.html
title: "Fraction (\u5206\u6570)"
---
## 概要

分数演算のための構造体.

## 使用例

```cpp
Fraction f(4, 6);   // 4/6(= 2/3)の値を持つ
~f;                 // 逆数を計算 (= 3/2)
f.to_double();      // = 0.666666...
```
