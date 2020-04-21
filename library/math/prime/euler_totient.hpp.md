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


# :heavy_check_mark: Euler's totient function (オイラーのφ関数) <small>(math/prime/euler_totient.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#284ec5e6a3c30a992cd88179b43d3dce">math/prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime/euler_totient.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 01:00:48+09:00




## 概要

オイラーの$\varphi$関数. $1$以上$N$以下の整数について, $N$と互いに素なものの個数を求める.

## 計算量

$O(\sqrt{n})$

## 使用例

* `euler_totient(N)` : $\varphi(N)$を返す.
  * 返り値の型 : `long long`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/NTL_1_D.test.cpp.html">test/aoj/NTL_1_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Euler's totient function (オイラーのφ関数)
* @docs docs/math/prime/euler_totient.md
*/

long long euler_totient(long long n) {
    long long ret = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        ret -= ret / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime/euler_totient.hpp"
/**
* @brief Euler's totient function (オイラーのφ関数)
* @docs docs/math/prime/euler_totient.md
*/

long long euler_totient(long long n) {
    long long ret = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        ret -= ret / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

