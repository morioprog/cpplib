---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':x:'
    path: test/yukicoder/20.test.cpp
    title: test/yukicoder/20.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/shortestpath/dijkstra.md
    document_title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 1 \"graph/shortestpath/dijkstra.hpp\"\n/**\n* @brief \u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\n* @docs docs/graph/shortestpath/dijkstra.md\n\
    */\n\ntemplate <typename T>\nvector<T> dijkstra(const Graph<T>& g, int frm) {\n\
    \    using P = pair<T, int>;\n    vector<T> ret(g.V, GINF<T>);\n    ret[frm] =\
    \ 0;\n    priority_queue<P, vector<P>, greater<P>> pq;\n    pq.emplace(ret[frm],\
    \ frm);\n    while (not pq.empty()) {\n        T cst;\n        int idx;\n    \
    \    tie(cst, idx) = pq.top();\n        pq.pop();\n        if (ret[idx] < cst)\
    \ continue;\n        for (auto& e : g.mat[idx]) {\n            T nxt_cst = cst\
    \ + e.cst;\n            if (ret[e.to] <= nxt_cst) continue;\n            ret[e.to]\
    \ = nxt_cst;\n            pq.emplace(ret[e.to], e.to);\n        }\n    }\n   \
    \ return ret;\n}\n"
  code: "/**\n* @brief \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n* @docs docs/graph/shortestpath/dijkstra.md\n\
    */\n\ntemplate <typename T>\nvector<T> dijkstra(const Graph<T>& g, int frm) {\n\
    \    using P = pair<T, int>;\n    vector<T> ret(g.V, GINF<T>);\n    ret[frm] =\
    \ 0;\n    priority_queue<P, vector<P>, greater<P>> pq;\n    pq.emplace(ret[frm],\
    \ frm);\n    while (not pq.empty()) {\n        T cst;\n        int idx;\n    \
    \    tie(cst, idx) = pq.top();\n        pq.pop();\n        if (ret[idx] < cst)\
    \ continue;\n        for (auto& e : g.mat[idx]) {\n            T nxt_cst = cst\
    \ + e.cst;\n            if (ret[e.to] <= nxt_cst) continue;\n            ret[e.to]\
    \ = nxt_cst;\n            pq.emplace(ret[e.to], e.to);\n        }\n    }\n   \
    \ return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortestpath/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/20.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/shortestpath/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortestpath/dijkstra.hpp
- /library/graph/shortestpath/dijkstra.hpp.html
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---
## 概要

単一始点最短路. 辺の重みが非負である必要がある.

## 計算量

$O(E\log V)$

## 使用例

* `dijkstra(g, frm)` : `frm`からダイクストラ法.
  * 返り値の型 : `vector<T>`
