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


# :warning: 乱数生成器 <small>(util/randomnumbergenerator.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/randomnumbergenerator.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

乱数生成器.

## 計算量

$O(1)$

## 使用例

* `RandomNumberGenerator rng;` : 乱数生成器を準備.
* `rng(b)` : $[0, b)$から乱数生成.
* `rng(a, b)` : $[a, b)$から乱数生成.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 乱数生成器
* @docs docs/util/randomnumbergenerator.md
*/

struct RandomNumberGenerator {
    mt19937 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    int operator()(int a, int b) {  // [a, b)
        uniform_int_distribution<int> dist(a, b - 1);
        return dist(mt);
    }
    int operator()(int b) {  // [0, b)
        return (*this)(0, b);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/randomnumbergenerator.hpp"
/**
* @brief 乱数生成器
* @docs docs/util/randomnumbergenerator.md
*/

struct RandomNumberGenerator {
    mt19937 mt;
    RandomNumberGenerator()
        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    int operator()(int a, int b) {  // [a, b)
        uniform_int_distribution<int> dist(a, b - 1);
        return dist(mt);
    }
    int operator()(int b) {  // [0, b)
        return (*this)(0, b);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

