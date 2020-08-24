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


# :x: ランレングス圧縮 (groupby) <small>(util/groupby.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/groupby.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 19:38:59+09:00




## 概要

ランレングス圧縮. 命名はPythonに準拠.

### 注意

* **C++14以降**で動く.
* `vector<bool>`だと内部の参照を外さないと動かない？

## 使用例

* `groupby(v)` : コンテナ`v`をランレングス圧縮.
  * 返り値の型 : `vector<pair<T, int>>`
    * `T` : `v`の要素.
    * `int` : その要素が何個続いているか.


## Verified with

* :x: <a href="../../verify/test/yukicoder/1183.test.cpp.html">test/yukicoder/1183.test.cpp</a>
* :x: <a href="../../verify/test/yukicoder/203.test.cpp.html">test/yukicoder/203.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief ランレングス圧縮 (groupby)
* @docs docs/util/groupby.md
*/

template <typename Container>
auto groupby(const Container &vec) {
    assert(vec.size() != 0);
    vector<pair<remove_const_t<remove_reference_t<decltype(vec.front())>>, int>> ret;
    int piv = -1;
    for (auto &e : vec) {
        if (piv == -1 or ret[piv].first != e)
            ++piv, ret.emplace_back(make_pair(e, 1));
        else
            ++(ret[piv].second);
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/groupby.hpp"
/**
* @brief ランレングス圧縮 (groupby)
* @docs docs/util/groupby.md
*/

template <typename Container>
auto groupby(const Container &vec) {
    assert(vec.size() != 0);
    vector<pair<remove_const_t<remove_reference_t<decltype(vec.front())>>, int>> ret;
    int piv = -1;
    for (auto &e : vec) {
        if (piv == -1 or ret[piv].first != e)
            ++piv, ret.emplace_back(make_pair(e, 1));
        else
            ++(ret[piv].second);
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

