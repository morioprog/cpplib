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


# :heavy_check_mark: 素数判定 <small>(math/prime/is_prime.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#284ec5e6a3c30a992cd88179b43d3dce">math/prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime/is_prime.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

素数判定する.

## 計算量

$O(\sqrt{n})$

## 使用例

* `is_prime(N)` : $N$が素数かを返す.
  * 返り値の型 : `bool`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_1_C.isprime.test.cpp.html">test/aoj/ALDS1_1_C.isprime.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 素数判定
 * @docs docs/math/prime/is_prime.md
 */

bool is_prime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime/is_prime.hpp"
/**
 * @brief 素数判定
 * @docs docs/math/prime/is_prime.md
 */

bool is_prime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

