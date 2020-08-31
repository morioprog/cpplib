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


# :heavy_check_mark: Divisor (約数) <small>(math/prime/divisor.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#284ec5e6a3c30a992cd88179b43d3dce">math/prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime/divisor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 00:08:28+09:00




## 概要

約数を列挙する. *ソートはされていない*.

## 計算量

$O(\sqrt{n})$

## 使用例

* `divisor(N)` : $N$の約数を返す.
  * 返り値の型 : `vector<long long>`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/888.test.cpp.html">test/yukicoder/888.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Divisor (約数)
 * @docs docs/math/prime/divisor.md
 */

vector<long long> divisor(const long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i * i != n) ret.emplace_back(n / i);
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime/divisor.hpp"
/**
 * @brief Divisor (約数)
 * @docs docs/math/prime/divisor.md
 */

vector<long long> divisor(const long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i * i != n) ret.emplace_back(n / i);
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

