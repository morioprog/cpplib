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


# :question: ダイクストラ法 <small>(graph/shortestpath/dijkstra.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#893699352036854e82d247c81f4d89a6">graph/shortestpath</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortestpath/dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 02:19:59+09:00




## 概要

単一始点最短路. 辺の重みが非負である必要がある.

## 計算量

$O(E\log V)$

## 使用例

* `dijkstra(g, frm)` : `frm`からダイクストラ法.
  * 返り値の型 : `vector<T>`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/20.test.cpp.html">test/yukicoder/20.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief ダイクストラ法
* @docs docs/graph/shortestpath/dijkstra.md
*/

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int frm) {
    using P = pair<T, int>;
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(ret[frm], frm);
    while (not pq.empty()) {
        T cst;  int idx;
        tie(cst, idx) = pq.top();   pq.pop();
        if (ret[idx] < cst) continue;
        for (auto& e: g.mat[idx]) {
            T nxt_cst = cst + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            pq.emplace(ret[e.to], e.to);
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shortestpath/dijkstra.hpp"
/**
* @brief ダイクストラ法
* @docs docs/graph/shortestpath/dijkstra.md
*/

template<typename T>
vector<T> dijkstra(const Graph<T> &g, int frm) {
    using P = pair<T, int>;
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(ret[frm], frm);
    while (not pq.empty()) {
        T cst;  int idx;
        tie(cst, idx) = pq.top();   pq.pop();
        if (ret[idx] < cst) continue;
        for (auto& e: g.mat[idx]) {
            T nxt_cst = cst + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            pq.emplace(ret[e.to], e.to);
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

