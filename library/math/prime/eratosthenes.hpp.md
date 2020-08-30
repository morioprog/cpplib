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


# :heavy_check_mark: エラトステネスの篩 <small>(math/prime/eratosthenes.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#284ec5e6a3c30a992cd88179b43d3dce">math/prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime/eratosthenes.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 20:00:55+09:00




## 概要

$n$以下の素数判定を高速に行う.

## 計算量

$O(n\log\log{n})$

## 使用例

- `eratosthenes(n)` : $n$以下の自然数に対して求める.
  - 返り値の型 : `vector<bool>`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_1_C.eratosthenes.test.cpp.html">test/aoj/ALDS1_1_C.eratosthenes.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief エラトステネスの篩
* @docs docs/math/prime/eratosthenes.md
*/

vector<bool> eratosthenes(const int n) {
    vector<bool> r(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (r[i]) {
            for (int j = i * 2; j <= n; j += i) r[j] = false;
        }
    }
    if (r.size() > 2) {
        r[0] = r[1] = false;
    } else if (r.size() > 1) {
        r[0] = false;
    }
    return r;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime/eratosthenes.hpp"
/**
* @brief エラトステネスの篩
* @docs docs/math/prime/eratosthenes.md
*/

vector<bool> eratosthenes(const int n) {
    vector<bool> r(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (r[i]) {
            for (int j = i * 2; j <= n; j += i) r[j] = false;
        }
    }
    if (r.size() > 2) {
        r[0] = r[1] = false;
    } else if (r.size() > 1) {
        r[0] = false;
    }
    return r;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

