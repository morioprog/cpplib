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


# :heavy_check_mark: 01-BFS <small>(graph/shortestpath/01_bfs.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#893699352036854e82d247c81f4d89a6">graph/shortestpath</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortestpath/01_bfs.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 23:58:47+09:00




## 概要

単一始点最短路. 辺の重みが$0$または$1$のみである必要がある.

## 計算量

$O(E + V)$

## 使用例

* `bfs_01(g, frm)` : `frm`から01-BFS.
  * 返り値の型 : `vector<T>`


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2945.test.cpp.html">test/aoj/2945.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 01-BFS
* @docs docs/graph/shortestpath/01_bfs.md
*/

template<typename T>
vector<T> bfs_01(const Graph<T> &g, int frm) {
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    deque<int> dq;
    dq.emplace_back(frm);
    while (not dq.empty()) {
        int idx = dq.front();   dq.pop_front();
        for (auto& e: g.mat[idx]) {
            T nxt_cst = ret[idx] + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            if (e.cst == 0) dq.emplace_front(e.to);
            else            dq.emplace_back(e.to);
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shortestpath/01_bfs.hpp"
/**
* @brief 01-BFS
* @docs docs/graph/shortestpath/01_bfs.md
*/

template<typename T>
vector<T> bfs_01(const Graph<T> &g, int frm) {
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    deque<int> dq;
    dq.emplace_back(frm);
    while (not dq.empty()) {
        int idx = dq.front();   dq.pop_front();
        for (auto& e: g.mat[idx]) {
            T nxt_cst = ret[idx] + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            if (e.cst == 0) dq.emplace_front(e.to);
            else            dq.emplace_back(e.to);
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

