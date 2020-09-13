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


# :warning: 燃やす埋める <small>(graph/maximumflow/moyasu_umeru.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9278425fe4cf6e9c7cdba9d11d70c354">graph/maximumflow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/maximumflow/moyasu_umeru.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 19:13:22+09:00


* see: <a href="https://yosupo.hatenablog.com/entry/2015/03/31/134336">https://yosupo.hatenablog.com/entry/2015/03/31/134336</a>


## 概要

> わっけわかんねえほど沢山の制約ドパァな問題を解く一般的なテク

条件を読ませて, 張るべき辺を返す.

## 使用例

- `moyasu_umeru<int> mu(V)` : $V$頂点のグラフを定義.
  - コストの型 : `int`
- `mu.red_blue_penalty(r, b, pena)` : 頂点$r$を赤く, 頂点$b$を青く塗ったら罰金$pena$.
- `mu.red_penalty(r, pena)` : 頂点$r$を赤く塗ったら罰金$pena$.
- `mu.blue_penalty(b, pena)` : 頂点$b$を赤く塗ったら罰金$pena$.
- `mu.red_reward(r, rwrd)` : 頂点$r$を赤く塗ったら賞金$rwrd$.
- `mu.blue_reward(b, rwrd)` : 頂点$b$を青く塗ったら賞金$rwrd$.
- `mu.reds_reward(v_r, rwrd)` : 頂点群$v_r$を全て赤く塗ったら賞金$rwrd$.
- `mu.blues_reward(v_b, rwrd)` : 頂点群$v_b$を青て赤く塗ったら賞金$rwrd$.
- `mu.edges` : 張るべき辺.
- `mu.margin` : 無条件で得られる賞金.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 燃やす埋める
* @docs docs/graph/maximumflow/moyasu_umeru.md
* @see https://yosupo.hatenablog.com/entry/2015/03/31/134336
*/

template <typename T>
struct moyasu_umeru {
    int N;
    T margin;
    const int R, B;  // R:red, B:blue
    const T INF;
    vector<tuple<int, int, T>> edges;
    moyasu_umeru(int V, T INF = numeric_limits<T>::max() / 10)
        : N(V + 2), margin(0), R(V), B(V + 1), INF(INF) {}
    void red_blue_penalty(int r, int b, T pena) {
        edges.emplace_back(r, b, pena);
    }
    void red_penalty(int r, T pena) {
        red_blue_penalty(r, B, pena);
    }
    void blue_penalty(int b, T pena) {
        red_blue_penalty(R, b, pena);
    }
    void red_reward(int r, T rwrd) {
        margin += rwrd;
        blue_penalty(r, rwrd);
    }
    void blue_reward(int b, T rwrd) {
        margin += rwrd;
        red_penalty(b, rwrd);
    }
    void reds_reward(vector<int> v_r, T rwrd) {
        margin += rwrd;
        edges.emplace_back(R, N, rwrd);
        for (auto& r : v_r) edges.emplace_back(N, r, INF);
        ++N;
    }
    void blues_reward(vector<int> v_b, T rwrd) {
        margin += rwrd;
        edges.emplace_back(N, B, rwrd);
        for (auto& b : v_b) edges.emplace_back(b, N, INF);
        ++N;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/maximumflow/moyasu_umeru.hpp"
/**
* @brief 燃やす埋める
* @docs docs/graph/maximumflow/moyasu_umeru.md
* @see https://yosupo.hatenablog.com/entry/2015/03/31/134336
*/

template <typename T>
struct moyasu_umeru {
    int N;
    T margin;
    const int R, B;  // R:red, B:blue
    const T INF;
    vector<tuple<int, int, T>> edges;
    moyasu_umeru(int V, T INF = numeric_limits<T>::max() / 10)
        : N(V + 2), margin(0), R(V), B(V + 1), INF(INF) {}
    void red_blue_penalty(int r, int b, T pena) {
        edges.emplace_back(r, b, pena);
    }
    void red_penalty(int r, T pena) {
        red_blue_penalty(r, B, pena);
    }
    void blue_penalty(int b, T pena) {
        red_blue_penalty(R, b, pena);
    }
    void red_reward(int r, T rwrd) {
        margin += rwrd;
        blue_penalty(r, rwrd);
    }
    void blue_reward(int b, T rwrd) {
        margin += rwrd;
        red_penalty(b, rwrd);
    }
    void reds_reward(vector<int> v_r, T rwrd) {
        margin += rwrd;
        edges.emplace_back(R, N, rwrd);
        for (auto& r : v_r) edges.emplace_back(N, r, INF);
        ++N;
    }
    void blues_reward(vector<int> v_b, T rwrd) {
        margin += rwrd;
        edges.emplace_back(N, B, rwrd);
        for (auto& b : v_b) edges.emplace_back(b, N, INF);
        ++N;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

