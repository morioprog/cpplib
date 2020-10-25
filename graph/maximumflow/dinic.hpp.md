---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.dinic.test.cpp
    title: test/aoj/GRL_6_A.dinic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/maximumflow/dinic.md
    document_title: "Dinic\u6CD5"
    links:
    - http://yosupo.hatenablog.com/entry/2015/03/31/134336
  bundledCode: "#line 1 \"graph/maximumflow/dinic.hpp\"\n/**\n* @brief Dinic\u6CD5\
    \n* @docs docs/graph/maximumflow/dinic.md\n* @see http://yosupo.hatenablog.com/entry/2015/03/31/134336\n\
    * @note O(E * V ^ 2)\n*/\n\ntemplate <typename T>\nstruct Dinic {\n    struct\
    \ CapEdge {\n        int to, rev;\n        T cap;\n        CapEdge() {}\n    \
    \    CapEdge(int t, int r, T c)\n            : to(t), rev(r), cap(c) {}\n    \
    \    operator int() const { return to; }\n    };\n    const T INF;\n    vector<vector<CapEdge>>\
    \ graph;\n    vector<T> min_cst;\n    vector<int> itr;\n    Dinic(int n)\n   \
    \     : INF(numeric_limits<T>::max()), graph(n) {}\n    void add_arc(int a, int\
    \ b, T c) {\n        graph[a].emplace_back(b, (int)graph[b].size(), c);\n    \
    \    graph[b].emplace_back(a, (int)graph[a].size() - 1, 0);\n    }\n    void add_edge(int\
    \ a, int b, T c) {\n        graph[a].emplace_back(b, (int)graph[b].size(), c);\n\
    \        graph[b].emplace_back(a, (int)graph[a].size() - 1, c);\n    }\n    bool\
    \ bfs(int s, int t) {\n        queue<int> que;\n        min_cst.assign((int)graph.size(),\
    \ -1);\n        min_cst[s] = 0;\n        que.emplace(s);\n        while (not que.empty())\
    \ {\n            int idx = que.front();\n            que.pop();\n            for\
    \ (auto& nxt : graph[idx]) {\n                if (nxt.cap > 0 and min_cst[nxt]\
    \ == -1) {\n                    min_cst[nxt] = min_cst[idx] + 1;\n           \
    \         que.emplace(nxt);\n                }\n            }\n        }\n   \
    \     return min_cst[t] != -1;\n    }\n    T dfs(int idx, const int t, T flw)\
    \ {\n        if (idx == t) return flw;\n        for (int& i = itr[idx]; i < (int)graph[idx].size();\
    \ ++i) {\n            CapEdge& nxt = graph[idx][i];\n            if (nxt.cap >\
    \ 0 and min_cst[idx] < min_cst[nxt]) {\n                T d = dfs(nxt, t, min(flw,\
    \ nxt.cap));\n                if (d > 0) {\n                    nxt.cap -= d;\n\
    \                    graph[nxt][nxt.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    \    T max_flow(int s, int t) {\n        T ret = 0;\n        while (bfs(s, t))\
    \ {\n            itr.assign(graph.size(), 0);\n            for (T tmp; (tmp =\
    \ dfs(s, t, INF)) > 0;) ret += tmp;\n        }\n        return ret;\n    }\n};\n"
  code: "/**\n* @brief Dinic\u6CD5\n* @docs docs/graph/maximumflow/dinic.md\n* @see\
    \ http://yosupo.hatenablog.com/entry/2015/03/31/134336\n* @note O(E * V ^ 2)\n\
    */\n\ntemplate <typename T>\nstruct Dinic {\n    struct CapEdge {\n        int\
    \ to, rev;\n        T cap;\n        CapEdge() {}\n        CapEdge(int t, int r,\
    \ T c)\n            : to(t), rev(r), cap(c) {}\n        operator int() const {\
    \ return to; }\n    };\n    const T INF;\n    vector<vector<CapEdge>> graph;\n\
    \    vector<T> min_cst;\n    vector<int> itr;\n    Dinic(int n)\n        : INF(numeric_limits<T>::max()),\
    \ graph(n) {}\n    void add_arc(int a, int b, T c) {\n        graph[a].emplace_back(b,\
    \ (int)graph[b].size(), c);\n        graph[b].emplace_back(a, (int)graph[a].size()\
    \ - 1, 0);\n    }\n    void add_edge(int a, int b, T c) {\n        graph[a].emplace_back(b,\
    \ (int)graph[b].size(), c);\n        graph[b].emplace_back(a, (int)graph[a].size()\
    \ - 1, c);\n    }\n    bool bfs(int s, int t) {\n        queue<int> que;\n   \
    \     min_cst.assign((int)graph.size(), -1);\n        min_cst[s] = 0;\n      \
    \  que.emplace(s);\n        while (not que.empty()) {\n            int idx = que.front();\n\
    \            que.pop();\n            for (auto& nxt : graph[idx]) {\n        \
    \        if (nxt.cap > 0 and min_cst[nxt] == -1) {\n                    min_cst[nxt]\
    \ = min_cst[idx] + 1;\n                    que.emplace(nxt);\n               \
    \ }\n            }\n        }\n        return min_cst[t] != -1;\n    }\n    T\
    \ dfs(int idx, const int t, T flw) {\n        if (idx == t) return flw;\n    \
    \    for (int& i = itr[idx]; i < (int)graph[idx].size(); ++i) {\n            CapEdge&\
    \ nxt = graph[idx][i];\n            if (nxt.cap > 0 and min_cst[idx] < min_cst[nxt])\
    \ {\n                T d = dfs(nxt, t, min(flw, nxt.cap));\n                if\
    \ (d > 0) {\n                    nxt.cap -= d;\n                    graph[nxt][nxt.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    T max_flow(int s, int t) {\n        T ret\
    \ = 0;\n        while (bfs(s, t)) {\n            itr.assign(graph.size(), 0);\n\
    \            for (T tmp; (tmp = dfs(s, t, INF)) > 0;) ret += tmp;\n        }\n\
    \        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximumflow/dinic.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.dinic.test.cpp
documentation_of: graph/maximumflow/dinic.hpp
layout: document
redirect_from:
- /library/graph/maximumflow/dinic.hpp
- /library/graph/maximumflow/dinic.hpp.html
title: "Dinic\u6CD5"
---
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
