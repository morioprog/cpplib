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


# :heavy_check_mark: グラフテンプレート <small>(graph/template.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

グラフのテンプレート.

#### 最短経路

* ダイクストラ法 : 単一始点最短路. 辺の重みが非負である必要がある. $O(E\log V)$
* ベルマンフォード法 : 単一始点最短路. 負閉路検出ができる. $O(EV)$
* ワーシャルフロイド法 : 全点間最短路. 負閉路検出ができる. $O(V^3)$
  * 辺の追加は$O(V^2)$

#### 最小全域木

* クラスカル法 : UnionFindに依存. $O(E\log V)$

## 使用例

* `Graph<int> g(V)` : $V$頂点のグラフを定義.
* `GINF<int>` : グラフアルゴリズムで使う`INF`.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `U V cst`
    * `false` : `U V`


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2945.test.cpp.html">test/aoj/2945.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_C.test.cpp.html">test/aoj/GRL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.test.cpp.html">test/aoj/GRL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_4_B.test.cpp.html">test/aoj/GRL_4_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.test.cpp.html">test/aoj/GRL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_7_A.test.cpp.html">test/aoj/GRL_7_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertexaddpathsum.test.cpp.html">test/yosupo/vertexaddpathsum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertexaddsubtreesum.test.cpp.html">test/yosupo/vertexaddsubtreesum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/13.test.cpp.html">test/yukicoder/13.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/20.test.cpp.html">test/yukicoder/20.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/399.test.cpp.html">test/yukicoder/399.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
*/

template <typename T>
struct Edge {
    int frm, to, idx;
    T cst;
    Edge() {}
    Edge(int f, int t, T c, int i = -1)
        : frm(f), to(t), idx(i), cst(c) {}
    operator int() const { return to; }
};

template <typename T>
constexpr T GINF = numeric_limits<T>::max() / 10;

template <typename T>
struct Graph {
    int V, E;
    vector<vector<Edge<T>>> mat;
    vector<vector<T>> wf;
    Graph() {}
    Graph(int v)
        : V(v), E(0), mat(v) {}
    inline void add_edge(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            int a, b;
            T c(1);
            cin >> a >> b;
            if (need_cost) cin >> c;
            add_edge(a, b, c, margin);
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            int a, b;
            T c(1);
            cin >> a >> b;
            if (need_cost) cin >> c;
            add_arc(a, b, c, margin);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/template.hpp"
/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
*/

template <typename T>
struct Edge {
    int frm, to, idx;
    T cst;
    Edge() {}
    Edge(int f, int t, T c, int i = -1)
        : frm(f), to(t), idx(i), cst(c) {}
    operator int() const { return to; }
};

template <typename T>
constexpr T GINF = numeric_limits<T>::max() / 10;

template <typename T>
struct Graph {
    int V, E;
    vector<vector<Edge<T>>> mat;
    vector<vector<T>> wf;
    Graph() {}
    Graph(int v)
        : V(v), E(0), mat(v) {}
    inline void add_edge(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            int a, b;
            T c(1);
            cin >> a >> b;
            if (need_cost) cin >> c;
            add_edge(a, b, c, margin);
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            int a, b;
            T c(1);
            cin >> a >> b;
            if (need_cost) cin >> c;
            add_arc(a, b, c, margin);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

