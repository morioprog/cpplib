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


# :heavy_check_mark: グラフテンプレート <small>(graph/graph.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 17:45:50+09:00




## 概要

グラフ関連のアルゴリズム.

* ダイクストラ法 : 単一始点最短路. 辺の重みが非負である必要がある. $O(E\log V)$
* ベルマンフォード法 : 単一始点最短路. 負閉路検出ができる. $O(EV)$
* ワーシャルフロイド法 : 全点間最短路. 負閉路検出ができる. $O(V^3)$
  * 辺の追加は$O(V^2)$

## 使用例

* `Graph<int> g(V)` : $V$頂点のグラフを定義.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `U V cst`
    * `false` : `U V`
* `g.dijkstra(frm)` : `frm`からダイクストラ法.
  * 返り値の型 : `vector<T>`
* `g.bellmanford(frm)` : `frm`からベルマンフォード法.
  * 返り値の型 : `vector<T>`
  * 負閉路があったら空の`vector`を返す.
* `g.warshallfloyd(frm)` : ワーシャルフロイド法.
  * 結果は`g.wf`に格納される.
  * 返り値の型 : `bool`
  * 負閉路があったら`true`を返す.
  * 一度ワーシャルフロイドを使用した状態で辺を追加すると, `g.wf`が自動的に更新される.


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_C.test.cpp.html">test/aoj/GRL_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief グラフテンプレート
* @docs docs/graph/graph.md
*/

template<typename T>
struct Graph {
    using P = pair<T, int>;
    using Matrix = vector<vector<T>>;
    struct Edge {
        int frm, to;    T cst;
        Edge() {}
        Edge(int f, int t, T c) : frm(f), to(t), cst(c) {}
    };
    int V, E;   const T INF;
    vector<vector<Edge>> mat;
    Matrix wf;
    Graph() {}
    Graph(int v) : V(v), E(0),INF(numeric_limits<T>::max() / 10), mat(v) {}
    inline void add_edge(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 2;
        mat[a].emplace_back(a, b, c);
        mat[b].emplace_back(b, a, c);
        if ((int)wf.size() == 0) return;
        warshallfloyd_update(a, b, c);
        warshallfloyd_update(b, a, c);
    }
    inline void add_arc(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 1;
        mat[a].emplace_back(a, b, c);
        if ((int)wf.size() == 0) return;
        warshallfloyd_update(a, b, c);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_edge(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_edge(a, b, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_arc(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_arc(a, b, c, margin);
            }
        }
    }
    inline vector<T> dijkstra(int frm) {
        vector<T> ret(V, INF);  ret[frm] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(ret[frm], frm);
        while (not pq.empty()) {
            T cst;  int idx;
            tie(cst, idx) = pq.top();   pq.pop();
            if (ret[idx] < cst) continue;
            for (auto& e: mat[idx]) {
                T nxt_cst = cst + e.cst;
                if (ret[e.to] <= nxt_cst) continue;
                ret[e.to] = nxt_cst;
                pq.emplace(ret[e.to], e.to);
            }
        }
        return ret;
    }
    inline vector<T> bellmanford(int frm) {
        vector<T> ret(V, INF);  ret[frm] = 0;
        for (int i = 0; i < V - 1; ++i) {
            for (int j = 0; j < V; ++j) {
                for (auto& e: mat[j]) {
                    if (ret[e.frm] == INF) continue;
                    ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);
                }
            }
        }
        for (int j = 0; j < V; ++j) {
            for (auto& e: mat[j]) {
                if (ret[e.frm] == INF) continue;
                if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();
            }
        }
        return ret;
    }
    inline bool warshallfloyd() {
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
    inline void warshallfloyd_update(int frm, int to, T cst = 1) {
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
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/graph.hpp"
/**
* @brief グラフテンプレート
* @docs docs/graph/graph.md
*/

template<typename T>
struct Graph {
    using P = pair<T, int>;
    using Matrix = vector<vector<T>>;
    struct Edge {
        int frm, to;    T cst;
        Edge() {}
        Edge(int f, int t, T c) : frm(f), to(t), cst(c) {}
    };
    int V, E;   const T INF;
    vector<vector<Edge>> mat;
    Matrix wf;
    Graph() {}
    Graph(int v) : V(v), E(0),INF(numeric_limits<T>::max() / 10), mat(v) {}
    inline void add_edge(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 2;
        mat[a].emplace_back(a, b, c);
        mat[b].emplace_back(b, a, c);
        if ((int)wf.size() == 0) return;
        warshallfloyd_update(a, b, c);
        warshallfloyd_update(b, a, c);
    }
    inline void add_arc(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 1;
        mat[a].emplace_back(a, b, c);
        if ((int)wf.size() == 0) return;
        warshallfloyd_update(a, b, c);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_edge(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_edge(a, b, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_arc(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_arc(a, b, c, margin);
            }
        }
    }
    inline vector<T> dijkstra(int frm) {
        vector<T> ret(V, INF);  ret[frm] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(ret[frm], frm);
        while (not pq.empty()) {
            T cst;  int idx;
            tie(cst, idx) = pq.top();   pq.pop();
            if (ret[idx] < cst) continue;
            for (auto& e: mat[idx]) {
                T nxt_cst = cst + e.cst;
                if (ret[e.to] <= nxt_cst) continue;
                ret[e.to] = nxt_cst;
                pq.emplace(ret[e.to], e.to);
            }
        }
        return ret;
    }
    inline vector<T> bellmanford(int frm) {
        vector<T> ret(V, INF);  ret[frm] = 0;
        for (int i = 0; i < V - 1; ++i) {
            for (int j = 0; j < V; ++j) {
                for (auto& e: mat[j]) {
                    if (ret[e.frm] == INF) continue;
                    ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);
                }
            }
        }
        for (int j = 0; j < V; ++j) {
            for (auto& e: mat[j]) {
                if (ret[e.frm] == INF) continue;
                if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();
            }
        }
        return ret;
    }
    inline bool warshallfloyd() {
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
    inline void warshallfloyd_update(int frm, int to, T cst = 1) {
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
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

