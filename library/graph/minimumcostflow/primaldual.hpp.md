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


# :heavy_check_mark: Primal Dual <small>(graph/minimumcostflow/primaldual.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#4f2a5e89d3f9de5e41e39d8432f85e12">graph/minimumcostflow</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/minimumcostflow/primaldual.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 23:54:37+09:00


* see: <a href="http://www.prefield.com/algorithm/graph/primal_dual.html">http://www.prefield.com/algorithm/graph/primal_dual.html</a>


## 概要

最小費用流を求めるアルゴリズム.

## 計算量

$O(FE\log V)$

* $O(UCV^2)$で求めるアルゴリズムもある.
  * $U$ : 容量合計
  * $C$ : 費用合計
  * 参考 : <http://www.prefield.com/algorithm/graph/primal_dual.html>

## 使用例

* `PrimalDual<Cst, Cap> pd(V)` : $V$頂点のグラフを定義.
  * コストの型 : `Cst`
  * 容量の型 : `Cap`
* `pd.add_arc(u, v, cst, cap)` : $u$から$v$にコスト$cst$, 容量$cap$の有向辺を張る.
* `pd.min_cost_flow(s, t, f)` : $s$から$t$へ流量$f$での最小費用流を求める.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_6_B.test.cpp.html">test/aoj/GRL_6_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Primal Dual
* @docs docs/graph/minimumcostflow/primaldual.md
* @see http://www.prefield.com/algorithm/graph/primal_dual.html
* @note O(FE\log V)
*/

template <typename Cst, typename Cap>
struct PrimalDual {
    struct CapEdge {
        int to, rev;
        Cst cst;
        Cap cap;
        CapEdge() {}
        CapEdge(int t, int r, Cst cst, Cap cap) : to(t), rev(r), cst(cst), cap(cap) {}
        operator int() const { return to; }
    };
    using P = pair<Cst, int>;
    const Cst INF;
    int V;
    vector<vector<CapEdge>> graph;
    vector<Cst> pot, min_cst;
    vector<int> prv_v, prv_e;
    PrimalDual(int V) : INF(numeric_limits<Cst>::max()), V(V), graph(V) {}
    void add_arc(int a, int b, Cst cst, Cap cap) {
        graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, -cst, 0);
    }
    Cst min_cost_flow(int s, int t, Cap flw) {
        pot.assign(V, 0);
        prv_e.assign(V, -1);
        prv_v.assign(V, -1);
        Cst ret = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        while (flw > 0) {
            min_cst.assign(V, INF);
            pq.push(P(0, s));
            min_cst[s] = 0;
            while (not pq.empty()) {
                Cst cst;
                int idx;
                tie(cst, idx) = pq.top();
                pq.pop();
                if (min_cst[idx] < cst) continue;
                for (int i = 0; i < (int)graph[idx].size(); ++i) {
                    CapEdge &nxt = graph[idx][i];
                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];
                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {
                        min_cst[nxt] = nxt_cst;
                        prv_v[nxt] = idx, prv_e[nxt] = i;
                        pq.push(P(min_cst[nxt], nxt));
                    }
                }
            }
            if (min_cst[t] == INF) return -1;
            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];
            Cap add_flw = flw;
            for (int v = t; v != s; v = prv_v[v]) {
                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);
            }
            flw -= add_flw;
            ret += add_flw * pot[t];
            for (int v = t; v != s; v = prv_v[v]) {
                CapEdge &e = graph[prv_v[v]][prv_e[v]];
                e.cap -= add_flw;
                graph[v][e.rev].cap += add_flw;
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/minimumcostflow/primaldual.hpp"
/**
* @brief Primal Dual
* @docs docs/graph/minimumcostflow/primaldual.md
* @see http://www.prefield.com/algorithm/graph/primal_dual.html
* @note O(FE\log V)
*/

template <typename Cst, typename Cap>
struct PrimalDual {
    struct CapEdge {
        int to, rev;
        Cst cst;
        Cap cap;
        CapEdge() {}
        CapEdge(int t, int r, Cst cst, Cap cap) : to(t), rev(r), cst(cst), cap(cap) {}
        operator int() const { return to; }
    };
    using P = pair<Cst, int>;
    const Cst INF;
    int V;
    vector<vector<CapEdge>> graph;
    vector<Cst> pot, min_cst;
    vector<int> prv_v, prv_e;
    PrimalDual(int V) : INF(numeric_limits<Cst>::max()), V(V), graph(V) {}
    void add_arc(int a, int b, Cst cst, Cap cap) {
        graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, -cst, 0);
    }
    Cst min_cost_flow(int s, int t, Cap flw) {
        pot.assign(V, 0);
        prv_e.assign(V, -1);
        prv_v.assign(V, -1);
        Cst ret = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        while (flw > 0) {
            min_cst.assign(V, INF);
            pq.push(P(0, s));
            min_cst[s] = 0;
            while (not pq.empty()) {
                Cst cst;
                int idx;
                tie(cst, idx) = pq.top();
                pq.pop();
                if (min_cst[idx] < cst) continue;
                for (int i = 0; i < (int)graph[idx].size(); ++i) {
                    CapEdge &nxt = graph[idx][i];
                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];
                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {
                        min_cst[nxt] = nxt_cst;
                        prv_v[nxt] = idx, prv_e[nxt] = i;
                        pq.push(P(min_cst[nxt], nxt));
                    }
                }
            }
            if (min_cst[t] == INF) return -1;
            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];
            Cap add_flw = flw;
            for (int v = t; v != s; v = prv_v[v]) {
                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);
            }
            flw -= add_flw;
            ret += add_flw * pot[t];
            for (int v = t; v != s; v = prv_v[v]) {
                CapEdge &e = graph[prv_v[v]][prv_e[v]];
                e.cap -= add_flw;
                graph[v][e.rev].cap += add_flw;
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

