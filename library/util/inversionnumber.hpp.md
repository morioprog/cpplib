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


# :heavy_check_mark: 転倒数 <small>(util/inversionnumber.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/inversionnumber.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 21:21:29+09:00




## 概要

転倒数. $i < j$ かつ $a_i > a_j$ となる組$(i, j)$の個数. バブルソートのスワップ回数と等しい.

## 計算量

$O(n\log n)$

## 使用例

* `inversion_number(v)` : `v`の転倒数.


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/1115.test.cpp.html">test/yukicoder/1115.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 転倒数
* @docs docs/util/inversionnumber.md
*/

template <typename T>
long long inversion_number(vector<T> &v) {
    int sz = v.size();
    vector<T> rev, v_cp(v);
    sort(v_cp.begin(), v_cp.end());
    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
    BinaryIndexedTree<T> bit(sz);
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
        ret += i - bit.sum(rev[i]);
        bit.add(rev[i], 1);
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/inversionnumber.hpp"
/**
* @brief 転倒数
* @docs docs/util/inversionnumber.md
*/

template <typename T>
long long inversion_number(vector<T> &v) {
    int sz = v.size();
    vector<T> rev, v_cp(v);
    sort(v_cp.begin(), v_cp.end());
    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
    BinaryIndexedTree<T> bit(sz);
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
        ret += i - bit.sum(rev[i]);
        bit.add(rev[i], 1);
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

