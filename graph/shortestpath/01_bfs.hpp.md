---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2945.test.cpp
    title: test/aoj/2945.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/shortestpath/01_bfs.md
    document_title: 01-BFS
    links: []
  bundledCode: "#line 1 \"graph/shortestpath/01_bfs.hpp\"\n/**\n* @brief 01-BFS\n\
    * @docs docs/graph/shortestpath/01_bfs.md\n*/\n\ntemplate <typename T>\nvector<T>\
    \ bfs_01(const Graph<T>& g, int frm) {\n    vector<T> ret(g.V, GINF<T>);\n   \
    \ ret[frm] = 0;\n    deque<int> dq;\n    dq.emplace_back(frm);\n    while (not\
    \ dq.empty()) {\n        int idx = dq.front();\n        dq.pop_front();\n    \
    \    for (auto& e : g.mat[idx]) {\n            T nxt_cst = ret[idx] + e.cst;\n\
    \            if (ret[e.to] <= nxt_cst) continue;\n            ret[e.to] = nxt_cst;\n\
    \            if (e.cst == 0) dq.emplace_front(e.to);\n            else\n     \
    \           dq.emplace_back(e.to);\n        }\n    }\n    return ret;\n}\n"
  code: "/**\n* @brief 01-BFS\n* @docs docs/graph/shortestpath/01_bfs.md\n*/\n\ntemplate\
    \ <typename T>\nvector<T> bfs_01(const Graph<T>& g, int frm) {\n    vector<T>\
    \ ret(g.V, GINF<T>);\n    ret[frm] = 0;\n    deque<int> dq;\n    dq.emplace_back(frm);\n\
    \    while (not dq.empty()) {\n        int idx = dq.front();\n        dq.pop_front();\n\
    \        for (auto& e : g.mat[idx]) {\n            T nxt_cst = ret[idx] + e.cst;\n\
    \            if (ret[e.to] <= nxt_cst) continue;\n            ret[e.to] = nxt_cst;\n\
    \            if (e.cst == 0) dq.emplace_front(e.to);\n            else\n     \
    \           dq.emplace_back(e.to);\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortestpath/01_bfs.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2945.test.cpp
documentation_of: graph/shortestpath/01_bfs.hpp
layout: document
redirect_from:
- /library/graph/shortestpath/01_bfs.hpp
- /library/graph/shortestpath/01_bfs.hpp.html
title: 01-BFS
---
## 概要

単一始点最短路. 辺の重みが$0$または$1$のみである必要がある.

## 計算量

$O(E + V)$

## 使用例

* `bfs_01(g, frm)` : `frm`から01-BFS.
  * 返り値の型 : `vector<T>`
