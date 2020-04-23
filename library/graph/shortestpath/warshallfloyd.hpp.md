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
    - Last commit date: 2020-04-23 19:21:10+09:00




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
bool Graph<T>::warshallfloyd() {
    wf.assign(V, vector<T>(V, INF));
    for (int i = 0; i < V; ++i) wf[i][i] = 0;
    for (int i = 0; i < V; ++i) {
        for (auto& e: mat[i]) {
            wf[e.frm][e.to] = min(wf[e.frm][e.to], e.cst);
        }
    }
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (wf[i][k] != INF and wf[k][j] != INF) {
                    wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
                }
            }
        }
    }
    bool hasnegcycle = false;
    for (int i = 0; i < V; ++i) hasnegcycle |= wf[i][i] < 0;
    return hasnegcycle;
}

template<typename T>
void Graph<T>::warshallfloyd_update(int frm, int to, T cst) {
    if (wf[frm][to] <= cst) return;
    wf[frm][to] = cst;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (wf[i][frm] != INF and wf[frm][j] != INF) {
                wf[i][j] = min(wf[i][j], wf[i][frm] + wf[frm][j]);
            }
        }
    }
}

template<typename T>
void Graph<T>::warshallfloyd_add_arc(int frm, int to, T cst) {
    add_arc(frm, to, cst);
    warshallfloyd_update(frm, to, cst);
}

template<typename T>
void Graph<T>::warshallfloyd_add_edge(int frm, int to, T cst) {
    add_edge(frm, to, cst);
    warshallfloyd_update(frm, to, cst);
    warshallfloyd_update(to, frm, cst);
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
bool Graph<T>::warshallfloyd() {
    wf.assign(V, vector<T>(V, INF));
    for (int i = 0; i < V; ++i) wf[i][i] = 0;
    for (int i = 0; i < V; ++i) {
        for (auto& e: mat[i]) {
            wf[e.frm][e.to] = min(wf[e.frm][e.to], e.cst);
        }
    }
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (wf[i][k] != INF and wf[k][j] != INF) {
                    wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
                }
            }
        }
    }
    bool hasnegcycle = false;
    for (int i = 0; i < V; ++i) hasnegcycle |= wf[i][i] < 0;
    return hasnegcycle;
}

template<typename T>
void Graph<T>::warshallfloyd_update(int frm, int to, T cst) {
    if (wf[frm][to] <= cst) return;
    wf[frm][to] = cst;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (wf[i][frm] != INF and wf[frm][j] != INF) {
                wf[i][j] = min(wf[i][j], wf[i][frm] + wf[frm][j]);
            }
        }
    }
}

template<typename T>
void Graph<T>::warshallfloyd_add_arc(int frm, int to, T cst) {
    add_arc(frm, to, cst);
    warshallfloyd_update(frm, to, cst);
}

template<typename T>
void Graph<T>::warshallfloyd_add_edge(int frm, int to, T cst) {
    add_edge(frm, to, cst);
    warshallfloyd_update(frm, to, cst);
    warshallfloyd_update(to, frm, cst);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

