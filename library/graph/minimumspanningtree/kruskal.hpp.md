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


# :heavy_check_mark: クラスカル法 <small>(graph/minimumspanningtree/kruskal.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fd7b240ac98922caf22c9202d36f936f">graph/minimumspanningtree</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/minimumspanningtree/kruskal.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 02:19:59+09:00




## 概要

最小全域木を求めるアルゴリズム. 内部でUnionFindを使用している.

## 計算量

$O(E\log V)$

## 使用例

* `kruskal(g)` : グラフ`g`に対してクラスカル法を行う.
  * 返り値 : 最小全域木の重さ.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_2_A.test.cpp.html">test/aoj/GRL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief クラスカル法
* @docs docs/graph/minimumspanningtree/kruskal.md
*/

template<typename T>
T kruskal(const Graph<T> &g) {
    vector<Edge<T>> edges;
    for (int i = 0; i < g.V; ++i) for (auto& e: g.mat[i]) edges.emplace_back(e);
    sort(edges.begin(), edges.end(), [](const Edge<T> &a, const Edge<T> &b) {
        return a.cst < b.cst;
    });
    UnionFind uf(g.V);
    T ret(0);
    for (auto& e : edges) if (uf.unite(e.frm, e.to)) ret += e.cst;
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/minimumspanningtree/kruskal.hpp"
/**
* @brief クラスカル法
* @docs docs/graph/minimumspanningtree/kruskal.md
*/

template<typename T>
T kruskal(const Graph<T> &g) {
    vector<Edge<T>> edges;
    for (int i = 0; i < g.V; ++i) for (auto& e: g.mat[i]) edges.emplace_back(e);
    sort(edges.begin(), edges.end(), [](const Edge<T> &a, const Edge<T> &b) {
        return a.cst < b.cst;
    });
    UnionFind uf(g.V);
    T ret(0);
    for (auto& e : edges) if (uf.unite(e.frm, e.to)) ret += e.cst;
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

