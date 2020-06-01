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


# :heavy_check_mark: ベルマンフォード法 <small>(graph/shortestpath/bellmanford.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#893699352036854e82d247c81f4d89a6">graph/shortestpath</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortestpath/bellmanford.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 02:19:59+09:00




## 概要

単一始点最短路. 負閉路検出ができる.

## 計算量

$O(EV)$

## 使用例

* `bellmanford(g, frm)` : `frm`からベルマンフォード法.
  * 返り値の型 : `vector<T>`
  * 負閉路があったら空の`vector`を返す.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief ベルマンフォード法
* @docs docs/graph/shortestpath/bellmanford.md
*/

template<typename T>
vector<T> bellmanford(const Graph<T> &g, int frm) {
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    for (int i = 0; i < g.V - 1; ++i) {
        for (int j = 0; j < g.V; ++j) {
            for (auto& e: g.mat[j]) {
                if (ret[e.frm] == GINF<T>) continue;
                ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);
            }
        }
    }
    for (int j = 0; j < g.V; ++j) {
        for (auto& e: g.mat[j]) {
            if (ret[e.frm] == GINF<T>) continue;
            if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shortestpath/bellmanford.hpp"
/**
* @brief ベルマンフォード法
* @docs docs/graph/shortestpath/bellmanford.md
*/

template<typename T>
vector<T> bellmanford(const Graph<T> &g, int frm) {
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    for (int i = 0; i < g.V - 1; ++i) {
        for (int j = 0; j < g.V; ++j) {
            for (auto& e: g.mat[j]) {
                if (ret[e.frm] == GINF<T>) continue;
                ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);
            }
        }
    }
    for (int j = 0; j < g.V; ++j) {
        for (auto& e: g.mat[j]) {
            if (ret[e.frm] == GINF<T>) continue;
            if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

