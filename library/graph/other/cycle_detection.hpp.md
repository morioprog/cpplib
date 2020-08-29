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


# :warning: 閉路検出 <small>(graph/other/cycle_detection.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7bdf4bef6792afd2baf0aea42eec3899">graph/other</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/other/cycle_detection.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 09:09:31+09:00




## 概要

閉路検出.

### 計算量

$O(E + V)$

## 使用例

- `cycle_detection(g)` : グラフ`g`の閉路上の頂点を順番に返す.
  - 閉路がないなら`vector<int>()`を返す.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 閉路検出
* @docs docs/graph/other/cycle_detection.md
*/

template <typename T>
vector<int> cycle_detection(const Graph<T> &g) {
    vector<int> cycle, color(g.V, 0);
    auto dfs = [&](auto &&f, int cur, int &frm) -> bool {
        color[cur] = 1;
        for (auto &nxt : g.mat[cur]) {
            if (color[nxt] == 0) {
                if (f(f, nxt, frm)) {
                    cycle.emplace_back(cur);
                    return frm != cur;
                } else if (not cycle.empty())
                    return false;
            } else if (color[nxt] == 1) {
                cycle.emplace_back(cur);
                frm = nxt;
                return true;
            }
        }
        color[cur] = 2;
        return false;
    };
    int frm = -1;
    for (int i = 0; i < g.V; ++i) {
        if (color[i] == 0) {
            dfs(dfs, i, frm);
            if (not cycle.empty()) {
                reverse(cycle.begin(), cycle.end());
                break;
            }
        }
    }
    return cycle;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/other/cycle_detection.hpp"
/**
* @brief 閉路検出
* @docs docs/graph/other/cycle_detection.md
*/

template <typename T>
vector<int> cycle_detection(const Graph<T> &g) {
    vector<int> cycle, color(g.V, 0);
    auto dfs = [&](auto &&f, int cur, int &frm) -> bool {
        color[cur] = 1;
        for (auto &nxt : g.mat[cur]) {
            if (color[nxt] == 0) {
                if (f(f, nxt, frm)) {
                    cycle.emplace_back(cur);
                    return frm != cur;
                } else if (not cycle.empty())
                    return false;
            } else if (color[nxt] == 1) {
                cycle.emplace_back(cur);
                frm = nxt;
                return true;
            }
        }
        color[cur] = 2;
        return false;
    };
    int frm = -1;
    for (int i = 0; i < g.V; ++i) {
        if (color[i] == 0) {
            dfs(dfs, i, frm);
            if (not cycle.empty()) {
                reverse(cycle.begin(), cycle.end());
                break;
            }
        }
    }
    return cycle;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

