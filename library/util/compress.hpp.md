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


# :warning: 座標圧縮 <small>(util/compress.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/compress.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

座標圧縮.

## 計算量

$O(n\log n)$

## 使用例

* `auto [com, rev] = compress(ord)` : `ord`を座標圧縮.
  * `com` : 座標圧縮して得られる配列.
  * `rev` : `ord`と`com`の対応関係.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 座標圧縮
* @docs docs/util/compress.md
*/

template <typename T>
pair<vector<T>, map<T, int>> compress(vector<T> ord) {
    vector<T> com(ord);
    map<T, int> rev;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
    vector<T> ret;
    for (auto& e : ord) ret.emplace_back(rev[e]);
    return make_pair(ret, rev);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/compress.hpp"
/**
* @brief 座標圧縮
* @docs docs/util/compress.md
*/

template <typename T>
pair<vector<T>, map<T, int>> compress(vector<T> ord) {
    vector<T> com(ord);
    map<T, int> rev;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
    vector<T> ret;
    for (auto& e : ord) ret.emplace_back(rev[e]);
    return make_pair(ret, rev);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

