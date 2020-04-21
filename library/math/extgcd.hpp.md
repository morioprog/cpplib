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


# :heavy_check_mark: 拡張ユークリッドの互除法 <small>(math/extgcd.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/extgcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 01:19:00+09:00




## 概要

与えられた$a, b$に対して, 最大公約数$gcd(a, b)$と, $ax + by = gcd(a, b)$なる$x, y$を求める.

## 計算量

$O(\log a)$

## 使用例

* `extgcd(a, b, x, y)` : $a$と$b$に対して拡張ユークリッドの互除法を行う.
  * $ax + by = gcd(a, b)$なる$x, y$は`x`, `y`に格納される.
  * 返り値 : $gcd(a, b)$


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_E.test.cpp.html">test/aoj/NTL_1_E.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 拡張ユークリッドの互除法
* @docs docs/math/extgcd.md
*/

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/extgcd.hpp"
/**
* @brief 拡張ユークリッドの互除法
* @docs docs/math/extgcd.md
*/

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

