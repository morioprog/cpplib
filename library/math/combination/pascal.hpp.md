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


# :heavy_check_mark: Combination (Pascal) <small>(math/combination/pascal.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#54907edcdfa59aabac4f72caf192990b">math/combination</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/combination/pascal.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

$C$, $P$, $H$をパスカルの三角形を用いて求める.

## 計算量

- クエリ : $O(r)$

## 使用例

- `C_pascal<modint>(n, r)` : `modint`型で$C(n, r)$に答える


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1501.combination.pascal.test.cpp.html">test/aoj/1501.combination.pascal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Combination (Pascal)
 * @docs docs/math/combination/pascal.md
 */

template <typename T>
T C_pascal(long long n, int r) {
    if (r == 0) return T(1);
    if (r < 0) return T(0);
    if (n < 0) return T(r & 1 ? -1 : 1) * C_pascal<T>(-n + r - 1, r);
    if (n == 0 || n < r) return T(0);
    T ret(1);
    for (int i = 1; i <= r; ++i) ret *= n--, ret /= i;
    return ret;
}

template <typename T>
T P_pascal(long long n, int r) {
    if (n < r || r < 0) return T(0);
    T ret(1);
    for (int i = 1; i <= r; ++i) ret *= n--;
    return ret;
}

template <typename T>
T H_pascal(long long n, int r) {
    if (n < 0 || r < 0) return T(0);
    if (!n && !r) return T(1);
    return C_pascal<T>(n + r - 1, r);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/combination/pascal.hpp"
/**
 * @brief Combination (Pascal)
 * @docs docs/math/combination/pascal.md
 */

template <typename T>
T C_pascal(long long n, int r) {
    if (r == 0) return T(1);
    if (r < 0) return T(0);
    if (n < 0) return T(r & 1 ? -1 : 1) * C_pascal<T>(-n + r - 1, r);
    if (n == 0 || n < r) return T(0);
    T ret(1);
    for (int i = 1; i <= r; ++i) ret *= n--, ret /= i;
    return ret;
}

template <typename T>
T P_pascal(long long n, int r) {
    if (n < r || r < 0) return T(0);
    T ret(1);
    for (int i = 1; i <= r; ++i) ret *= n--;
    return ret;
}

template <typename T>
T H_pascal(long long n, int r) {
    if (n < 0 || r < 0) return T(0);
    if (!n && !r) return T(1);
    return C_pascal<T>(n + r - 1, r);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

