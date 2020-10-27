---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1501.combination.inverse.test.cpp
    title: test/aoj/1501.combination.inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1501.combination.pascal.test.cpp
    title: test/aoj/1501.combination.pascal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/determinantofmatrix.test.cpp
    title: test/yosupo/determinantofmatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/117.test.cpp
    title: test/yukicoder/117.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/modint.md
    document_title: ModInt
    links: []
  bundledCode: "#line 1 \"math/modint.hpp\"\n/**\n * @brief ModInt\n * @docs docs/math/modint.md\n\
    \ */\n\ntemplate <int MODULO>\nstruct ModInt {\n    using i32 = int;\n    using\
    \ i64 = long long;\n    using u32 = unsigned int;\n    using u64 = unsigned long\
    \ long;\n    u64 x;\n    ModInt()\n        : x(0) {}\n    ModInt(i64 y)\n    \
    \    : x(set(y % MODULO + MODULO)) {}\n    static u64 set(const i64 &y) { return\
    \ (y < MODULO) ? y : y - MODULO; }\n    ModInt operator+(const ModInt &m) const\
    \ { return ModInt(set(x + m.x)); }\n    ModInt operator-(const ModInt &m) const\
    \ { return ModInt(set(x + MODULO - m.x)); }\n    ModInt operator*(const ModInt\
    \ &m) const { return ModInt(x * m.x % MODULO); }\n    ModInt operator/(const ModInt\
    \ &m) const { return ModInt(x) * ~ModInt(m.x); }\n    ModInt &operator+=(const\
    \ ModInt &m) { return *this = *this + m; }\n    ModInt &operator-=(const ModInt\
    \ &m) { return *this = *this - m; }\n    ModInt &operator*=(const ModInt &m) {\
    \ return *this = *this * m; }\n    ModInt &operator/=(const ModInt &m) { return\
    \ *this = *this / m; }\n    ModInt &operator^=(const u64 &y) { return *this =\
    \ *this ^ y; }\n    ModInt operator~() const { return *this ^ (MODULO - 2); }\n\
    \    ModInt operator-() const { return ModInt(set(MODULO - x)); }\n    ModInt\
    \ operator++() { return *this = ModInt(set(x + 1)); }\n    ModInt operator--()\
    \ { return *this = ModInt(set(x + MODULO - 1)); }\n    bool operator<(const ModInt\
    \ &m) const { return x < m.x; }\n    bool operator>(const ModInt &m) const { return\
    \ x > m.x; }\n    bool operator==(const ModInt &m) const { return x == m.x; }\n\
    \    bool operator!=(const ModInt &m) const { return x != m.x; }\n    bool operator<=(const\
    \ ModInt &m) const { return x <= m.x; }\n    bool operator>=(const ModInt &m)\
    \ const { return x >= m.x; }\n    explicit operator u64() const { return x; }\n\
    \    ModInt operator^(i64 y) const { return pow(x, y); }\n    static ModInt pow(i64\
    \ x, i64 y) {\n        bool neg = false;\n        if (y < 0) y = -y, neg = true;\n\
    \        ModInt u(1), t(x);\n        while (y) {\n            if (y & 1) u *=\
    \ t;\n            t *= t;\n            y >>= 1;\n        }\n        return neg\
    \ ? ModInt(1) / u : u;\n    }\n    friend ostream &operator<<(ostream &os, const\
    \ ModInt<MODULO> &m) { return os << m.x; }\n    friend istream &operator>>(istream\
    \ &is, ModInt<MODULO> &m) {\n        u64 y;\n        is >> y;\n        m = ModInt(y);\n\
    \        return is;\n    }\n};\nconstexpr int MODULO = (int)1e9 + 7;\nusing modint\
    \         = ModInt<MODULO>;\n"
  code: "/**\n * @brief ModInt\n * @docs docs/math/modint.md\n */\n\ntemplate <int\
    \ MODULO>\nstruct ModInt {\n    using i32 = int;\n    using i64 = long long;\n\
    \    using u32 = unsigned int;\n    using u64 = unsigned long long;\n    u64 x;\n\
    \    ModInt()\n        : x(0) {}\n    ModInt(i64 y)\n        : x(set(y % MODULO\
    \ + MODULO)) {}\n    static u64 set(const i64 &y) { return (y < MODULO) ? y :\
    \ y - MODULO; }\n    ModInt operator+(const ModInt &m) const { return ModInt(set(x\
    \ + m.x)); }\n    ModInt operator-(const ModInt &m) const { return ModInt(set(x\
    \ + MODULO - m.x)); }\n    ModInt operator*(const ModInt &m) const { return ModInt(x\
    \ * m.x % MODULO); }\n    ModInt operator/(const ModInt &m) const { return ModInt(x)\
    \ * ~ModInt(m.x); }\n    ModInt &operator+=(const ModInt &m) { return *this =\
    \ *this + m; }\n    ModInt &operator-=(const ModInt &m) { return *this = *this\
    \ - m; }\n    ModInt &operator*=(const ModInt &m) { return *this = *this * m;\
    \ }\n    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }\n \
    \   ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }\n    ModInt\
    \ operator~() const { return *this ^ (MODULO - 2); }\n    ModInt operator-() const\
    \ { return ModInt(set(MODULO - x)); }\n    ModInt operator++() { return *this\
    \ = ModInt(set(x + 1)); }\n    ModInt operator--() { return *this = ModInt(set(x\
    \ + MODULO - 1)); }\n    bool operator<(const ModInt &m) const { return x < m.x;\
    \ }\n    bool operator>(const ModInt &m) const { return x > m.x; }\n    bool operator==(const\
    \ ModInt &m) const { return x == m.x; }\n    bool operator!=(const ModInt &m)\
    \ const { return x != m.x; }\n    bool operator<=(const ModInt &m) const { return\
    \ x <= m.x; }\n    bool operator>=(const ModInt &m) const { return x >= m.x; }\n\
    \    explicit operator u64() const { return x; }\n    ModInt operator^(i64 y)\
    \ const { return pow(x, y); }\n    static ModInt pow(i64 x, i64 y) {\n       \
    \ bool neg = false;\n        if (y < 0) y = -y, neg = true;\n        ModInt u(1),\
    \ t(x);\n        while (y) {\n            if (y & 1) u *= t;\n            t *=\
    \ t;\n            y >>= 1;\n        }\n        return neg ? ModInt(1) / u : u;\n\
    \    }\n    friend ostream &operator<<(ostream &os, const ModInt<MODULO> &m) {\
    \ return os << m.x; }\n    friend istream &operator>>(istream &is, ModInt<MODULO>\
    \ &m) {\n        u64 y;\n        is >> y;\n        m = ModInt(y);\n        return\
    \ is;\n    }\n};\nconstexpr int MODULO = (int)1e9 + 7;\nusing modint         =\
    \ ModInt<MODULO>;\n"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/117.test.cpp
  - test/aoj/NTL_1_B.test.cpp
  - test/aoj/1501.combination.pascal.test.cpp
  - test/aoj/1501.combination.inverse.test.cpp
  - test/yosupo/determinantofmatrix.test.cpp
documentation_of: math/modint.hpp
layout: document
redirect_from:
- /library/math/modint.hpp
- /library/math/modint.hpp.html
title: ModInt
---
## 概要

Mod演算のための構造体.

## 使用例

```cpp
modint M;               // MOD=1e9+7における演算を行う
modint::pow(3, 5);      // 3の5乗
```
