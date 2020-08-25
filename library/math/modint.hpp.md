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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: ModInt <small>(math/modint.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/modint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

Mod演算のための構造体.

## 使用例

```cpp
modint M;               // MOD=1e9+7における演算を行う
modint::pow(3, 5);      // 3の5乗
```


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_B.test.cpp.html">test/aoj/NTL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/determinantofmatrix.test.cpp.html">test/yosupo/determinantofmatrix.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1050.test.cpp.html">test/yukicoder/1050.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/117.test.cpp.html">test/yukicoder/117.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template <int MODULO>
struct ModInt {
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    u64 x;
    ModInt()
        : x(0) {}
    ModInt(i64 y)
        : x(set(y % MODULO + MODULO)) {}
    static u64 set(const i64 &y) { return (y < MODULO) ? y : y - MODULO; }
    ModInt operator+(const ModInt &m) const { return ModInt(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return ModInt(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return ModInt(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return ModInt(x) * ~ModInt(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }
    ModInt operator~() const { return *this ^ (MODULO - 2); }
    ModInt operator-() const { return ModInt(set(MODULO - x)); }
    ModInt operator++() { return *this = ModInt(set(x + 1)); }
    ModInt operator--() { return *this = ModInt(set(x + MODULO - 1)); }
    bool operator<(const ModInt &m) const { return x < m.x; }
    bool operator>(const ModInt &m) const { return x > m.x; }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator u64() const { return x; }
    ModInt operator^(i64 y) const { return pow(x, y); }
    static ModInt pow(i64 x, i64 y) {
        bool neg = false;
        if (y < 0) y = -y, neg = true;
        ModInt u(1), t(x);
        while (y) {
            if (y & 1) u *= t;
            t *= t;
            y >>= 1;
        }
        return neg ? ModInt(1) / u : u;
    }
    friend ostream &operator<<(ostream &os, const ModInt<MODULO> &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt<MODULO> &m) {
        u64 y;
        is >> y;
        m = ModInt(y);
        return is;
    }
};
constexpr int MODULO = (int)1e9 + 7;
using modint         = ModInt<MODULO>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/modint.hpp"
/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template <int MODULO>
struct ModInt {
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    u64 x;
    ModInt()
        : x(0) {}
    ModInt(i64 y)
        : x(set(y % MODULO + MODULO)) {}
    static u64 set(const i64 &y) { return (y < MODULO) ? y : y - MODULO; }
    ModInt operator+(const ModInt &m) const { return ModInt(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return ModInt(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return ModInt(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return ModInt(x) * ~ModInt(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }
    ModInt operator~() const { return *this ^ (MODULO - 2); }
    ModInt operator-() const { return ModInt(set(MODULO - x)); }
    ModInt operator++() { return *this = ModInt(set(x + 1)); }
    ModInt operator--() { return *this = ModInt(set(x + MODULO - 1)); }
    bool operator<(const ModInt &m) const { return x < m.x; }
    bool operator>(const ModInt &m) const { return x > m.x; }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator u64() const { return x; }
    ModInt operator^(i64 y) const { return pow(x, y); }
    static ModInt pow(i64 x, i64 y) {
        bool neg = false;
        if (y < 0) y = -y, neg = true;
        ModInt u(1), t(x);
        while (y) {
            if (y & 1) u *= t;
            t *= t;
            y >>= 1;
        }
        return neg ? ModInt(1) / u : u;
    }
    friend ostream &operator<<(ostream &os, const ModInt<MODULO> &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt<MODULO> &m) {
        u64 y;
        is >> y;
        m = ModInt(y);
        return is;
    }
};
constexpr int MODULO = (int)1e9 + 7;
using modint         = ModInt<MODULO>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

