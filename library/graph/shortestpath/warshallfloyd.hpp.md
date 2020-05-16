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


# :heavy_check_mark: ワーシャルフロイド法 <small>(graph/shortestpath/warshallfloyd.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#893699352036854e82d247c81f4d89a6">graph/shortestpath</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shortestpath/warshallfloyd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 22:07:22+09:00




## 概要

全点間最短路. 負閉路検出ができる.

## 計算量

* 構築 : $O(V^3)$
* 更新 : $O(V^2)$

## 使用例

* `g.warshallfloyd()` : ワーシャルフロイド法を行う.
  * 結果は`g.wf`に格納される.
  * 返り値の型 : `bool`
  * 負閉路があったら`true`を返す.
* `g.warshallfloyd_add_arc(frm, to, cst)` : 有向辺を追加して, `g.wf`を更新.
* `g.warshallfloyd_add_edge(frm, to, cst)` : 無向辺を追加して, `g.wf`を更新.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_1_C.test.cpp.html">test/aoj/GRL_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief ワーシャルフロイド法
* @docs docs/graph/shortestpath/warshallfloyd.md
*/

template<typename T>
bool warshallfloyd(Graph<T> &g) {
    g.wf.assign(g.V, vector<T>(g.V, GINF<T>));
    for (int i = 0; i < g.V; ++i) g.wf[i][i] = 0;
    for (int i = 0; i < g.V; ++i) for (auto& e: g.mat[i]) g.wf[e.frm][e.to] = min(g.wf[e.frm][e.to], e.cst);
    for (int k = 0; k < g.V; ++k) for (int i = 0; i < g.V; ++i) for (int j = 0; j < g.V; ++j) {
        if (g.wf[i][k] != GINF<T> and g.wf[k][j] != GINF<T>) g.wf[i][j] = min(g.wf[i][j], g.wf[i][k] + g.wf[k][j]);
    }
    bool hasnegcycle = false;
    for (int i = 0; i < g.V; ++i) hasnegcycle |= g.wf[i][i] < 0;
    return hasnegcycle;
}

template<typename T>
void warshallfloyd_update(Graph<T> &g, int frm, int to, T cst) {
    if (g.wf[frm][to] <= cst) return;
    g.wf[frm][to] = cst;
    for (int i = 0; i < g.V; ++i) {
        for (int j = 0; j < g.V; ++j) {
            if (g.wf[i][frm] != GINF<T> and g.wf[frm][j] != GINF<T>) {
                g.wf[i][j] = min(g.wf[i][j], g.wf[i][frm] + g.wf[frm][j]);
            }
        }
    }
}

template<typename T>
void warshallfloyd_add_arc(Graph<T> &g, int frm, int to, T cst) {
    g.add_arc(frm, to, cst);
    warshallfloyd_update(g, frm, to, cst);
}

template<typename T>
void warshallfloyd_add_edge(Graph<T> &g, int frm, int to, T cst) {
    g.add_edge(frm, to, cst);
    warshallfloyd_update(g, frm, to, cst);
    warshallfloyd_update(g, to, frm, cst);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shortestpath/warshallfloyd.hpp"
/**
* @brief ワーシャルフロイド法
* @docs docs/graph/shortestpath/warshallfloyd.md
*/

template<typename T>
bool warshallfloyd(Graph<T> &g) {
    g.wf.assign(g.V, vector<T>(g.V, GINF<T>));
    for (int i = 0; i < g.V; ++i) g.wf[i][i] = 0;
    for (int i = 0; i < g.V; ++i) for (auto& e: g.mat[i]) g.wf[e.frm][e.to] = min(g.wf[e.frm][e.to], e.cst);
    for (int k = 0; k < g.V; ++k) for (int i = 0; i < g.V; ++i) for (int j = 0; j < g.V; ++j) {
        if (g.wf[i][k] != GINF<T> and g.wf[k][j] != GINF<T>) g.wf[i][j] = min(g.wf[i][j], g.wf[i][k] + g.wf[k][j]);
    }
    bool hasnegcycle = false;
    for (int i = 0; i < g.V; ++i) hasnegcycle |= g.wf[i][i] < 0;
    return hasnegcycle;
}

template<typename T>
void warshallfloyd_update(Graph<T> &g, int frm, int to, T cst) {
    if (g.wf[frm][to] <= cst) return;
    g.wf[frm][to] = cst;
    for (int i = 0; i < g.V; ++i) {
        for (int j = 0; j < g.V; ++j) {
            if (g.wf[i][frm] != GINF<T> and g.wf[frm][j] != GINF<T>) {
                g.wf[i][j] = min(g.wf[i][j], g.wf[i][frm] + g.wf[frm][j]);
            }
        }
    }
}

template<typename T>
void warshallfloyd_add_arc(Graph<T> &g, int frm, int to, T cst) {
    g.add_arc(frm, to, cst);
    warshallfloyd_update(g, frm, to, cst);
}

template<typename T>
void warshallfloyd_add_edge(Graph<T> &g, int frm, int to, T cst) {
    g.add_edge(frm, to, cst);
    warshallfloyd_update(g, frm, to, cst);
    warshallfloyd_update(g, to, frm, cst);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

