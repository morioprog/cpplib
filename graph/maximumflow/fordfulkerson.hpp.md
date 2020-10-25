---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.fordfulkerson.test.cpp
    title: test/aoj/GRL_6_A.fordfulkerson.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/maximumflow/fordfulkerson.md
    document_title: "FordFulkerson\u6CD5"
    links:
    - http://yosupo.hatenablog.com/entry/2015/03/31/134336
  bundledCode: "#line 1 \"graph/maximumflow/fordfulkerson.hpp\"\n/**\n* @brief FordFulkerson\u6CD5\
    \n* @docs docs/graph/maximumflow/fordfulkerson.md\n* @see http://yosupo.hatenablog.com/entry/2015/03/31/134336\n\
    * @note O(E * F) (F : \u6700\u5927\u30D5\u30ED\u30FC)\n*/\n\ntemplate <typename\
    \ T>\nstruct FordFulkerson {\n    struct CapEdge {\n        int to, rev;\n   \
    \     T cap;\n        CapEdge() {}\n        CapEdge(int t, int r, T c)\n     \
    \       : to(t), rev(r), cap(c) {}\n        operator int() const { return to;\
    \ }\n    };\n    const T INF;\n    int timestamp;\n    vector<int> used;\n   \
    \ vector<vector<CapEdge>> graph;\n    FordFulkerson(int n)\n        : INF(numeric_limits<T>::max()),\
    \ timestamp(0), used(n, -1), graph(n) {}\n    void add_arc(int a, int b, T c)\
    \ {\n        graph[a].emplace_back(b, (int)graph[b].size(), c);\n        graph[b].emplace_back(a,\
    \ (int)graph[a].size() - 1, 0);\n    }\n    void add_edge(int a, int b, T c) {\n\
    \        graph[a].emplace_back(b, (int)graph[b].size(), c);\n        graph[b].emplace_back(a,\
    \ (int)graph[a].size() - 1, c);\n    }\n    T dfs(int idx, const int t, T flw)\
    \ {\n        if (idx == t) return flw;\n        used[idx] = timestamp;\n     \
    \   for (auto& nxt : graph[idx]) {\n            if (nxt.cap > 0 and used[nxt]\
    \ != timestamp) {\n                T d = dfs(nxt, t, min(flw, nxt.cap));\n   \
    \             if (d > 0) {\n                    nxt.cap -= d;\n              \
    \      graph[nxt][nxt.rev].cap += d;\n                    return d;\n        \
    \        }\n            }\n        }\n        return 0;\n    }\n    T max_flow(int\
    \ s, int t) {\n        T ret = 0;\n        for (T tmp; (tmp = dfs(s, t, INF))\
    \ > 0; ++timestamp) ret += tmp;\n        return ret;\n    }\n};\n"
  code: "/**\n* @brief FordFulkerson\u6CD5\n* @docs docs/graph/maximumflow/fordfulkerson.md\n\
    * @see http://yosupo.hatenablog.com/entry/2015/03/31/134336\n* @note O(E * F)\
    \ (F : \u6700\u5927\u30D5\u30ED\u30FC)\n*/\n\ntemplate <typename T>\nstruct FordFulkerson\
    \ {\n    struct CapEdge {\n        int to, rev;\n        T cap;\n        CapEdge()\
    \ {}\n        CapEdge(int t, int r, T c)\n            : to(t), rev(r), cap(c)\
    \ {}\n        operator int() const { return to; }\n    };\n    const T INF;\n\
    \    int timestamp;\n    vector<int> used;\n    vector<vector<CapEdge>> graph;\n\
    \    FordFulkerson(int n)\n        : INF(numeric_limits<T>::max()), timestamp(0),\
    \ used(n, -1), graph(n) {}\n    void add_arc(int a, int b, T c) {\n        graph[a].emplace_back(b,\
    \ (int)graph[b].size(), c);\n        graph[b].emplace_back(a, (int)graph[a].size()\
    \ - 1, 0);\n    }\n    void add_edge(int a, int b, T c) {\n        graph[a].emplace_back(b,\
    \ (int)graph[b].size(), c);\n        graph[b].emplace_back(a, (int)graph[a].size()\
    \ - 1, c);\n    }\n    T dfs(int idx, const int t, T flw) {\n        if (idx ==\
    \ t) return flw;\n        used[idx] = timestamp;\n        for (auto& nxt : graph[idx])\
    \ {\n            if (nxt.cap > 0 and used[nxt] != timestamp) {\n             \
    \   T d = dfs(nxt, t, min(flw, nxt.cap));\n                if (d > 0) {\n    \
    \                nxt.cap -= d;\n                    graph[nxt][nxt.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n    T max_flow(int s, int t) {\n        T ret\
    \ = 0;\n        for (T tmp; (tmp = dfs(s, t, INF)) > 0; ++timestamp) ret += tmp;\n\
    \        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximumflow/fordfulkerson.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.fordfulkerson.test.cpp
documentation_of: graph/maximumflow/fordfulkerson.hpp
layout: document
redirect_from:
- /library/graph/maximumflow/fordfulkerson.hpp
- /library/graph/maximumflow/fordfulkerson.hpp.html
title: "FordFulkerson\u6CD5"
---
## 概要

最大流を求めるアルゴリズム.

## 計算量

$O(EF)$

* $F$ : 最大フロー

## 使用例

* `FordFulkerson<int> ff(V)` : $V$頂点のグラフを定義.
  * 容量の型 : `int`
* `ff.add_arc(u, v, c)` : $u$から$v$に容量$c$の有向辺を張る.
* `ff.add_edge(u, v, c)` : $u$から$v$に容量$c$の無向辺を張る.
* `ff.max_flow(s, t)` : $s$から$t$への最大流を求める.
