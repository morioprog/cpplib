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


# :heavy_check_mark: トポロジカルソート <small>(graph/other/topological_sort.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7bdf4bef6792afd2baf0aea42eec3899">graph/other</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/other/topological_sort.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

トポロジカルソート.

### 計算量

$O(E + V)$

## 使用例

* `topological_sort(g)` : グラフ`g`をトポロジカルソート.
  * トポロジカルソートが出来ないなら`vector<int>()`を返す.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_4_B.test.cpp.html">test/aoj/GRL_4_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief トポロジカルソート
* @docs docs/graph/other/topological_sort.md
*/

template <typename T>
vector<int> topological_sort(const Graph<T> &g) {
    vector<int> order, color(g.V, 0);
    auto rec = [&](auto &&f, int v) -> bool {
        color[v] = 1;
        for (auto &e : g.mat[v]) {
            if (color[e] == 2) continue;
            if (color[e] == 1) return false;
            if (not f(f, e)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    };
    for (int i = 0; i < g.V; ++i)
        if (not color[i] and not rec(rec, i)) return vector<int>();
    reverse(order.begin(), order.end());
    return order;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/other/topological_sort.hpp"
/**
* @brief トポロジカルソート
* @docs docs/graph/other/topological_sort.md
*/

template <typename T>
vector<int> topological_sort(const Graph<T> &g) {
    vector<int> order, color(g.V, 0);
    auto rec = [&](auto &&f, int v) -> bool {
        color[v] = 1;
        for (auto &e : g.mat[v]) {
            if (color[e] == 2) continue;
            if (color[e] == 1) return false;
            if (not f(f, e)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    };
    for (int i = 0; i < g.V; ++i)
        if (not color[i] and not rec(rec, i)) return vector<int>();
    reverse(order.begin(), order.end());
    return order;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

