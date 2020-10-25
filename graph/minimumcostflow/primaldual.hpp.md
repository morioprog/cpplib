---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/minimumcostflow/primaldual.md
    document_title: Primal Dual
    links:
    - http://www.prefield.com/algorithm/graph/primal_dual.html
  bundledCode: "#line 1 \"graph/minimumcostflow/primaldual.hpp\"\n/**\n* @brief Primal\
    \ Dual\n* @docs docs/graph/minimumcostflow/primaldual.md\n* @see http://www.prefield.com/algorithm/graph/primal_dual.html\n\
    * @note O(FE\\log V)\n*/\n\ntemplate <typename Cst, typename Cap>\nstruct PrimalDual\
    \ {\n    struct CapEdge {\n        int to, rev;\n        Cst cst;\n        Cap\
    \ cap;\n        CapEdge() {}\n        CapEdge(int t, int r, Cst cst, Cap cap)\n\
    \            : to(t), rev(r), cst(cst), cap(cap) {}\n        operator int() const\
    \ { return to; }\n    };\n    using P = pair<Cst, int>;\n    const Cst INF;\n\
    \    int V;\n    vector<vector<CapEdge>> graph;\n    vector<Cst> pot, min_cst;\n\
    \    vector<int> prv_v, prv_e;\n    PrimalDual(int V)\n        : INF(numeric_limits<Cst>::max()),\
    \ V(V), graph(V) {}\n    void add_arc(int a, int b, Cst cst, Cap cap) {\n    \
    \    graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);\n        graph[b].emplace_back(a,\
    \ (int)graph[a].size() - 1, -cst, 0);\n    }\n    Cst min_cost_flow(int s, int\
    \ t, Cap flw) {\n        pot.assign(V, 0);\n        prv_e.assign(V, -1);\n   \
    \     prv_v.assign(V, -1);\n        Cst ret = 0;\n        priority_queue<P, vector<P>,\
    \ greater<P>> pq;\n        while (flw > 0) {\n            min_cst.assign(V, INF);\n\
    \            pq.push(P(0, s));\n            min_cst[s] = 0;\n            while\
    \ (not pq.empty()) {\n                Cst cst;\n                int idx;\n   \
    \             tie(cst, idx) = pq.top();\n                pq.pop();\n         \
    \       if (min_cst[idx] < cst) continue;\n                for (int i = 0; i <\
    \ (int)graph[idx].size(); ++i) {\n                    CapEdge &nxt = graph[idx][i];\n\
    \                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];\n\
    \                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {\n         \
    \               min_cst[nxt] = nxt_cst;\n                        prv_v[nxt] =\
    \ idx, prv_e[nxt] = i;\n                        pq.push(P(min_cst[nxt], nxt));\n\
    \                    }\n                }\n            }\n            if (min_cst[t]\
    \ == INF) return -1;\n            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];\n\
    \            Cap add_flw = flw;\n            for (int v = t; v != s; v = prv_v[v])\
    \ {\n                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);\n\
    \            }\n            flw -= add_flw;\n            ret += add_flw * pot[t];\n\
    \            for (int v = t; v != s; v = prv_v[v]) {\n                CapEdge\
    \ &e = graph[prv_v[v]][prv_e[v]];\n                e.cap -= add_flw;\n       \
    \         graph[v][e.rev].cap += add_flw;\n            }\n        }\n        return\
    \ ret;\n    }\n};\n"
  code: "/**\n* @brief Primal Dual\n* @docs docs/graph/minimumcostflow/primaldual.md\n\
    * @see http://www.prefield.com/algorithm/graph/primal_dual.html\n* @note O(FE\\\
    log V)\n*/\n\ntemplate <typename Cst, typename Cap>\nstruct PrimalDual {\n   \
    \ struct CapEdge {\n        int to, rev;\n        Cst cst;\n        Cap cap;\n\
    \        CapEdge() {}\n        CapEdge(int t, int r, Cst cst, Cap cap)\n     \
    \       : to(t), rev(r), cst(cst), cap(cap) {}\n        operator int() const {\
    \ return to; }\n    };\n    using P = pair<Cst, int>;\n    const Cst INF;\n  \
    \  int V;\n    vector<vector<CapEdge>> graph;\n    vector<Cst> pot, min_cst;\n\
    \    vector<int> prv_v, prv_e;\n    PrimalDual(int V)\n        : INF(numeric_limits<Cst>::max()),\
    \ V(V), graph(V) {}\n    void add_arc(int a, int b, Cst cst, Cap cap) {\n    \
    \    graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);\n        graph[b].emplace_back(a,\
    \ (int)graph[a].size() - 1, -cst, 0);\n    }\n    Cst min_cost_flow(int s, int\
    \ t, Cap flw) {\n        pot.assign(V, 0);\n        prv_e.assign(V, -1);\n   \
    \     prv_v.assign(V, -1);\n        Cst ret = 0;\n        priority_queue<P, vector<P>,\
    \ greater<P>> pq;\n        while (flw > 0) {\n            min_cst.assign(V, INF);\n\
    \            pq.push(P(0, s));\n            min_cst[s] = 0;\n            while\
    \ (not pq.empty()) {\n                Cst cst;\n                int idx;\n   \
    \             tie(cst, idx) = pq.top();\n                pq.pop();\n         \
    \       if (min_cst[idx] < cst) continue;\n                for (int i = 0; i <\
    \ (int)graph[idx].size(); ++i) {\n                    CapEdge &nxt = graph[idx][i];\n\
    \                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];\n\
    \                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {\n         \
    \               min_cst[nxt] = nxt_cst;\n                        prv_v[nxt] =\
    \ idx, prv_e[nxt] = i;\n                        pq.push(P(min_cst[nxt], nxt));\n\
    \                    }\n                }\n            }\n            if (min_cst[t]\
    \ == INF) return -1;\n            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];\n\
    \            Cap add_flw = flw;\n            for (int v = t; v != s; v = prv_v[v])\
    \ {\n                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);\n\
    \            }\n            flw -= add_flw;\n            ret += add_flw * pot[t];\n\
    \            for (int v = t; v != s; v = prv_v[v]) {\n                CapEdge\
    \ &e = graph[prv_v[v]][prv_e[v]];\n                e.cap -= add_flw;\n       \
    \         graph[v][e.rev].cap += add_flw;\n            }\n        }\n        return\
    \ ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimumcostflow/primaldual.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: graph/minimumcostflow/primaldual.hpp
layout: document
redirect_from:
- /library/graph/minimumcostflow/primaldual.hpp
- /library/graph/minimumcostflow/primaldual.hpp.html
title: Primal Dual
---
## 概要

最小費用流を求めるアルゴリズム.

## 計算量

$O(FE\log V)$

- $O(UCV^2)$で求めるアルゴリズムもある.
  - $U$ : 容量合計
  - $C$ : 費用合計

## 使用例

- `PrimalDual<Cst, Cap> pd(V)` : $V$頂点のグラフを定義.
  - コストの型 : `Cst`
  - 容量の型 : `Cap`
- `pd.add_arc(u, v, cst, cap)` : $u$から$v$にコスト$cst$, 容量$cap$の有向辺を張る.
- `pd.min_cost_flow(s, t, f)` : $s$から$t$へ流量$f$での最小費用流を求める.
