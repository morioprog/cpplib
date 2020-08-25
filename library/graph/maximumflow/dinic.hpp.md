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


# :heavy_check_mark: Dinic法 <small>(graph/maximumflow/dinic.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9278425fe4cf6e9c7cdba9d11d70c354">graph/maximumflow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/maximumflow/dinic.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00


* see: <a href="http://yosupo.hatenablog.com/entry/2015/03/31/134336">http://yosupo.hatenablog.com/entry/2015/03/31/134336</a>


## 概要

最大流を求めるアルゴリズム.

## 計算量

$O(EV^2)$

## 使用例

* `Dinic<int> dnc(V)` : $V$頂点のグラフを定義.
  * 容量の型 : `int`
* `dnc.add_arc(u, v, c)` : $u$から$v$に容量$c$の有向辺を張る.
* `dnc.add_edge(u, v, c)` : $u$から$v$に容量$c$の無向辺を張る.
* `dnc.max_flow(s, t)` : $s$から$t$への最大流を求める.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_6_A.dinic.test.cpp.html">test/aoj/GRL_6_A.dinic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Dinic法
* @docs docs/graph/maximumflow/dinic.md
* @see http://yosupo.hatenablog.com/entry/2015/03/31/134336
* @note O(E * V ^ 2)
*/

template <typename T>
struct Dinic {
    struct CapEdge {
        int to, rev;
        T cap;
        CapEdge() {}
        CapEdge(int t, int r, T c)
            : to(t), rev(r), cap(c) {}
        operator int() const { return to; }
    };
    const T INF;
    vector<vector<CapEdge>> graph;
    vector<T> min_cst;
    vector<int> itr;
    Dinic(int n)
        : INF(numeric_limits<T>::max()), graph(n) {}
    void add_arc(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, 0);
    }
    void add_edge(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, c);
    }
    bool bfs(int s, int t) {
        queue<int> que;
        min_cst.assign((int)graph.size(), -1);
        min_cst[s] = 0;
        que.emplace(s);
        while (not que.empty()) {
            int idx = que.front();
            que.pop();
            for (auto& nxt : graph[idx]) {
                if (nxt.cap > 0 and min_cst[nxt] == -1) {
                    min_cst[nxt] = min_cst[idx] + 1;
                    que.emplace(nxt);
                }
            }
        }
        return min_cst[t] != -1;
    }
    T dfs(int idx, const int t, T flw) {
        if (idx == t) return flw;
        for (int& i = itr[idx]; i < (int)graph[idx].size(); ++i) {
            CapEdge& nxt = graph[idx][i];
            if (nxt.cap > 0 and min_cst[idx] < min_cst[nxt]) {
                T d = dfs(nxt, t, min(flw, nxt.cap));
                if (d > 0) {
                    nxt.cap -= d;
                    graph[nxt][nxt.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(int s, int t) {
        T ret = 0;
        while (bfs(s, t)) {
            itr.assign(graph.size(), 0);
            for (T tmp; (tmp = dfs(s, t, INF)) > 0;) ret += tmp;
        }
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/maximumflow/dinic.hpp"
/**
* @brief Dinic法
* @docs docs/graph/maximumflow/dinic.md
* @see http://yosupo.hatenablog.com/entry/2015/03/31/134336
* @note O(E * V ^ 2)
*/

template <typename T>
struct Dinic {
    struct CapEdge {
        int to, rev;
        T cap;
        CapEdge() {}
        CapEdge(int t, int r, T c)
            : to(t), rev(r), cap(c) {}
        operator int() const { return to; }
    };
    const T INF;
    vector<vector<CapEdge>> graph;
    vector<T> min_cst;
    vector<int> itr;
    Dinic(int n)
        : INF(numeric_limits<T>::max()), graph(n) {}
    void add_arc(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, 0);
    }
    void add_edge(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, c);
    }
    bool bfs(int s, int t) {
        queue<int> que;
        min_cst.assign((int)graph.size(), -1);
        min_cst[s] = 0;
        que.emplace(s);
        while (not que.empty()) {
            int idx = que.front();
            que.pop();
            for (auto& nxt : graph[idx]) {
                if (nxt.cap > 0 and min_cst[nxt] == -1) {
                    min_cst[nxt] = min_cst[idx] + 1;
                    que.emplace(nxt);
                }
            }
        }
        return min_cst[t] != -1;
    }
    T dfs(int idx, const int t, T flw) {
        if (idx == t) return flw;
        for (int& i = itr[idx]; i < (int)graph[idx].size(); ++i) {
            CapEdge& nxt = graph[idx][i];
            if (nxt.cap > 0 and min_cst[idx] < min_cst[nxt]) {
                T d = dfs(nxt, t, min(flw, nxt.cap));
                if (d > 0) {
                    nxt.cap -= d;
                    graph[nxt][nxt.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(int s, int t) {
        T ret = 0;
        while (bfs(s, t)) {
            itr.assign(graph.size(), 0);
            for (T tmp; (tmp = dfs(s, t, INF)) > 0;) ret += tmp;
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

