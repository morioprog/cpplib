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


# :warning: Bipartite Check <small>(graph/bipartite/bipartite_check.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1cac5659bebf80b30fdbc9c35b6208b">graph/bipartite</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bipartite/bipartite_check.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-14 21:38:43+09:00




## 概要

二部グラフの判定.

### 計算量

$O(E + V)$

### 使用例

* `is_bipartite(g)` : 二部グラフの判定.
  * 片方の集合の大きさが欲しかったら, 適宜コメントを外す.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Bipartite Check
 * @docs docs/graph/bipartite/bipartite_check.md
 */

template<typename T>
// int is_bipartite(const Graph<T> &g) {
bool is_bipartite(const Graph<T> &g) {
    bool isbi = true;
    vector<int> color(g.V, 0);
    auto dfs = [&](auto &&f, int i, int clr) -> void {
        if (color[i] != 0) return;
        color[i] = clr;
        for (auto& e: g.mat[i]) {
            /* */if (color[e.to] == 0)      f(f, e.to, -clr);
            else if (color[e.to] == clr)    isbi = false;
        }
    };
    dfs(dfs, 0, 1);
    return isbi;
    // int cnt = 0;
    // for (auto& e: color) if (e == 1) ++cnt;
    // return isbi ? -1 : cnt;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bipartite/bipartite_check.hpp"
/**
 * @brief Bipartite Check
 * @docs docs/graph/bipartite/bipartite_check.md
 */

template<typename T>
// int is_bipartite(const Graph<T> &g) {
bool is_bipartite(const Graph<T> &g) {
    bool isbi = true;
    vector<int> color(g.V, 0);
    auto dfs = [&](auto &&f, int i, int clr) -> void {
        if (color[i] != 0) return;
        color[i] = clr;
        for (auto& e: g.mat[i]) {
            /* */if (color[e.to] == 0)      f(f, e.to, -clr);
            else if (color[e.to] == clr)    isbi = false;
        }
    };
    dfs(dfs, 0, 1);
    return isbi;
    // int cnt = 0;
    // for (auto& e: color) if (e == 1) ++cnt;
    // return isbi ? -1 : cnt;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

