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


# :heavy_check_mark: Prime Factor (素因数分解) <small>(math/prime/prime_factor.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#284ec5e6a3c30a992cd88179b43d3dce">math/prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime/prime_factor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-21 22:55:01+09:00




## 概要

素因数分解する.

## 計算量

$O(\sqrt{n})$

## 使用例

* `prime_factor(N)` : $N$を素因数分解したものを返す.
  * 返り値の型 : `map<long long, int>`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/NTL_1_A.test.cpp.html">test/aoj/NTL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Prime Factor (素因数分解)
 * @docs docs/math/prime/prime_factor.md
 */

map<long long, int> prime_factor(long long n) {
    map<long long, int> ret;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++ret[i];
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime/prime_factor.hpp"
/**
 * @brief Prime Factor (素因数分解)
 * @docs docs/math/prime/prime_factor.md
 */

map<long long, int> prime_factor(long long n) {
    map<long long, int> ret;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++ret[i];
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

