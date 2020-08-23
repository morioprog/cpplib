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


# :heavy_check_mark: グリッドグラフ <small>(graph/gridgraph.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/gridgraph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 22:46:41+09:00




## 概要

グリッドグラフのテンプレート.

## 使用例

* `GridGraph<int> g(H, W)` : $H \times W$のグリッドグラフを定義.
  * C++17以降なら`<int>`が省略できる.
* `g.inside(h, w)` : グリッド内部かを判定する.
* `g.hash(h, w)` : $(h, w)$を$[0, H * W)$にマッピングする.
  * 第3引数に`margin`が指定できる.
* `add_edge`, `add_arc` : `int`2つずつ, もしくは`pair<int, int>`1つずつを渡す.
* `g.input_edges(E, origin, need_cost)` : 標準入力から無向辺を張る.
* `g.input_arcs(E, origin, need_cost)` : 標準入力から有向辺を張る.
  * `origin` : 辺を何originで受け取るか.
  * `need_cost` : コストを受け取るか.
    * `true` : `Ux Uy Vx Vy cst`
    * `false` : `Ux Uy Vx Vy`
* `g.load_board(board, ng, cost, neighbor)` : ボードから張るべき辺を探す.
  * `board` : グリッドを表すボード(`vector<string>`, `vector<vector<int>>`など).
  * `ng` : 進入できないマスを表す要素(`'#'`など).
  * `cost` : 各辺のコスト.
  * `neighbor` : 何近傍に進めるか.
    * $2$ : 右か下のマス ($x$, $y$が増える方向).
    * $4$ : 上下左右のマス.
    * $8$ : 上下左右と斜めのマス.


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/20.test.cpp.html">test/yukicoder/20.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief グリッドグラフ
* @docs docs/graph/gridgraph.md
*/

template<typename T=int>
struct GridGraph : Graph<T> {
    using Graph<T>::V;
    using Graph<T>::E;
    using Graph<T>::mat;
    const int Gdx[9] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
    const int Gdy[9] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
    int H, W;
    GridGraph() {}
    GridGraph(int h, int w) : H(h), W(w) {
        V = h * w;
        E = 0;
        mat.resize(V);
    }
    inline bool inside(const int h, const int w) const {
        return h >= 0 and w >= 0 and h < H and w < W;
    }
    inline int hash(const int h, const int w, const int margin = 0) const {
        return (h - margin) * W + (w - margin);
    }
    inline void add_edge(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_edge(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {
        int ax, ay, bx, by;
        tie(ax, ay) = ap;
        tie(bx, by) = bp;
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void add_arc(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {
        int ax, ay, bx, by;
        tie(ax, ay) = ap;
        tie(bx, by) = bp;
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int ax, ay, bx, by; T c;
                cin >> ax >> ay >> bx >> by >> c;
                add_edge(ax, ay, bx, by, c, margin);
            } else {
                int ax, ay, bx, by; T c(1);
                cin >> ax >> ay >> bx >> by;
                add_edge(ax, ay, bx, by, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int ax, ay, bx, by; T c;
                cin >> ax >> ay >> bx >> by >> c;
                add_arc(ax, ay, bx, by, c, margin);
            } else {
                int ax, ay, bx, by; T c(1);
                cin >> ax >> ay >> bx >> by;
                add_arc(ax, ay, bx, by, c, margin);
            }
        }
    }
    template<typename B, typename C>
    inline void load_board(const B &board, const C ng, const int cost = 1, const int neighbor = 4) {
        assert(board.size() == H);
        if (H > 0) assert(board[0].size() == W);
        assert(neighbor >= 1 and neighbor <= 9);
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (board[h][w] == ng) continue;
                for (int i = 0; i < neighbor; ++i) {
                    int nh = h + Gdx[i];
                    int nw = w + Gdy[i];
                    if (not inside(nh, nw)) continue;
                    if (board[nh][nw] == ng) continue;
                    add_arc(h, w, nh, nw, cost);
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
#line 1 "graph/gridgraph.hpp"
/**
* @brief グリッドグラフ
* @docs docs/graph/gridgraph.md
*/

template<typename T=int>
struct GridGraph : Graph<T> {
    using Graph<T>::V;
    using Graph<T>::E;
    using Graph<T>::mat;
    const int Gdx[9] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
    const int Gdy[9] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
    int H, W;
    GridGraph() {}
    GridGraph(int h, int w) : H(h), W(w) {
        V = h * w;
        E = 0;
        mat.resize(V);
    }
    inline bool inside(const int h, const int w) const {
        return h >= 0 and w >= 0 and h < H and w < W;
    }
    inline int hash(const int h, const int w, const int margin = 0) const {
        return (h - margin) * W + (w - margin);
    }
    inline void add_edge(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_edge(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {
        int ax, ay, bx, by;
        tie(ax, ay) = ap;
        tie(bx, by) = bp;
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void add_arc(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {
        int ax, ay, bx, by;
        tie(ax, ay) = ap;
        tie(bx, by) = bp;
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int ax, ay, bx, by; T c;
                cin >> ax >> ay >> bx >> by >> c;
                add_edge(ax, ay, bx, by, c, margin);
            } else {
                int ax, ay, bx, by; T c(1);
                cin >> ax >> ay >> bx >> by;
                add_edge(ax, ay, bx, by, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int ax, ay, bx, by; T c;
                cin >> ax >> ay >> bx >> by >> c;
                add_arc(ax, ay, bx, by, c, margin);
            } else {
                int ax, ay, bx, by; T c(1);
                cin >> ax >> ay >> bx >> by;
                add_arc(ax, ay, bx, by, c, margin);
            }
        }
    }
    template<typename B, typename C>
    inline void load_board(const B &board, const C ng, const int cost = 1, const int neighbor = 4) {
        assert(board.size() == H);
        if (H > 0) assert(board[0].size() == W);
        assert(neighbor >= 1 and neighbor <= 9);
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (board[h][w] == ng) continue;
                for (int i = 0; i < neighbor; ++i) {
                    int nh = h + Gdx[i];
                    int nw = w + Gdy[i];
                    if (not inside(nh, nw)) continue;
                    if (board[nh][nw] == ng) continue;
                    add_arc(h, w, nh, nw, cost);
                }
            }
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

