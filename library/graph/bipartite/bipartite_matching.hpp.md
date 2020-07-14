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


# :heavy_check_mark: 二部グラフの最大マッチング <small>(graph/bipartite/bipartite_matching.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1cac5659bebf80b30fdbc9c35b6208b">graph/bipartite</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bipartite/bipartite_matching.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-14 22:08:56+09:00


* see: <a href="https://qiita.com/drken/items/e805e3f514acceb87602">https://qiita.com/drken/items/e805e3f514acceb87602</a>
* see: <a href="https://qiita.com/drken/items/7f98315b56c95a6181a4">https://qiita.com/drken/items/7f98315b56c95a6181a4</a>


## 概要

二部グラフの最大マッチング. 最大流で求める.

* 最大マッチングは, 最小点被覆$M$と一致.
* 最大安定集合(最大独立集合)は, 最小辺被覆と$V - M$で一致.

### 計算量

$O(EV)$

### 使用例

* `bipartite_matching(g)` : 二部グラフの最大マッチング.
  * マッチングの個数を返す.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_7_A.test.cpp.html">test/aoj/GRL_7_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 二部グラフの最大マッチング
 * @docs docs/graph/bipartite/bipartite_matching.md
 * @see https://qiita.com/drken/items/e805e3f514acceb87602
 * @see https://qiita.com/drken/items/7f98315b56c95a6181a4
 */

template<typename T>
int bipartite_matching(const Graph<T> &g) {
    int timestamp = 0;
    vector<int> alive(g.V, 1), used(g.V, 0), match(g.V, -1);
    auto dfs = [&](auto &&f, int cur) -> bool {
        used[cur] = timestamp;
        for (auto& nxt: g.mat[cur]) {
            int w = match[nxt];
            if (alive[nxt] == 0) continue;
            if (w == -1 or (used[w] != timestamp and f(f, w))) {
                match[cur] = nxt;
                match[nxt] = cur;
                return true;
            }
        }
        return false;
    };
    int ret = 0;
    for (int i = 0; i < g.V; ++i) {
        if (alive[i] == 0) continue;
        if (match[i] == -1) {
            ++timestamp;
            ret += dfs(dfs, i);
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/bipartite/bipartite_matching.hpp"
/**
 * @brief 二部グラフの最大マッチング
 * @docs docs/graph/bipartite/bipartite_matching.md
 * @see https://qiita.com/drken/items/e805e3f514acceb87602
 * @see https://qiita.com/drken/items/7f98315b56c95a6181a4
 */

template<typename T>
int bipartite_matching(const Graph<T> &g) {
    int timestamp = 0;
    vector<int> alive(g.V, 1), used(g.V, 0), match(g.V, -1);
    auto dfs = [&](auto &&f, int cur) -> bool {
        used[cur] = timestamp;
        for (auto& nxt: g.mat[cur]) {
            int w = match[nxt];
            if (alive[nxt] == 0) continue;
            if (w == -1 or (used[w] != timestamp and f(f, w))) {
                match[cur] = nxt;
                match[nxt] = cur;
                return true;
            }
        }
        return false;
    };
    int ret = 0;
    for (int i = 0; i < g.V; ++i) {
        if (alive[i] == 0) continue;
        if (match[i] == -1) {
            ++timestamp;
            ret += dfs(dfs, i);
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

