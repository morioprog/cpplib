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


# :warning: 三分探索 <small>(snippet/ternarysearch.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#54de4c5e0ecfc39083b31b56ee36cb19">snippet</a>
* <a href="{{ site.github.repository_url }}/blob/master/snippet/ternarysearch.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 02:31:58+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 三分探索
 */

using T = double;
auto f_trn = [&](T c) -> T {
    $3
};

T l = ${1:0}, r = ${2:1e9};
for (int _ = 0; _ < 100; ++_) {
    T c1 = (l * 2 + r) / 3;
    T c2 = (l + r * 2) / 3;
    if (f_trn(c1) > f_trn(c2)) l = c1;
    else r = c2;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "snippet/ternarysearch.hpp"
/**
 * @brief 三分探索
 */

using T = double;
auto f_trn = [&](T c) -> T {
    $3
};

T l = ${1:0}, r = ${2:1e9};
for (int _ = 0; _ < 100; ++_) {
    T c1 = (l * 2 + r) / 3;
    T c2 = (l + r * 2) / 3;
    if (f_trn(c1) > f_trn(c2)) l = c1;
    else r = c2;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

