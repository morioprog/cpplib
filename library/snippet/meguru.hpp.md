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


# :warning: めぐる式二分探索 <small>(snippet/meguru.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#54de4c5e0ecfc39083b31b56ee36cb19">snippet</a>
* <a href="{{ site.github.repository_url }}/blob/master/snippet/meguru.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 00:09:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief めぐる式二分探索
 */

auto check = [&](long long mid) -> bool {
    $3
};

long long ok = $1, ng = $2;
while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) >> 1;
    (check(mid) ? ok : ng) = mid;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "snippet/meguru.hpp"
/**
 * @brief めぐる式二分探索
 */

auto check = [&](long long mid) -> bool {
    $3
};

long long ok = $1, ng = $2;
while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) >> 1;
    (check(mid) ? ok : ng) = mid;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
