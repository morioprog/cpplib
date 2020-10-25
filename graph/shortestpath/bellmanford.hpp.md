---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/shortestpath/bellmanford.md
    document_title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
    links: []
  bundledCode: "#line 1 \"graph/shortestpath/bellmanford.hpp\"\n/**\n* @brief \u30D9\
    \u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\n* @docs docs/graph/shortestpath/bellmanford.md\n\
    */\n\ntemplate <typename T>\nvector<T> bellmanford(const Graph<T>& g, int frm)\
    \ {\n    vector<T> ret(g.V, GINF<T>);\n    ret[frm] = 0;\n    for (int i = 0;\
    \ i < g.V - 1; ++i) {\n        for (int j = 0; j < g.V; ++j) {\n            for\
    \ (auto& e : g.mat[j]) {\n                if (ret[e.frm] == GINF<T>) continue;\n\
    \                ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);\n           \
    \ }\n        }\n    }\n    for (int j = 0; j < g.V; ++j) {\n        for (auto&\
    \ e : g.mat[j]) {\n            if (ret[e.frm] == GINF<T>) continue;\n        \
    \    if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();\n        }\n    }\n\
    \    return ret;\n}\n"
  code: "/**\n* @brief \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5\n* @docs\
    \ docs/graph/shortestpath/bellmanford.md\n*/\n\ntemplate <typename T>\nvector<T>\
    \ bellmanford(const Graph<T>& g, int frm) {\n    vector<T> ret(g.V, GINF<T>);\n\
    \    ret[frm] = 0;\n    for (int i = 0; i < g.V - 1; ++i) {\n        for (int\
    \ j = 0; j < g.V; ++j) {\n            for (auto& e : g.mat[j]) {\n           \
    \     if (ret[e.frm] == GINF<T>) continue;\n                ret[e.to] = min(ret[e.to],\
    \ ret[e.frm] + e.cst);\n            }\n        }\n    }\n    for (int j = 0; j\
    \ < g.V; ++j) {\n        for (auto& e : g.mat[j]) {\n            if (ret[e.frm]\
    \ == GINF<T>) continue;\n            if (ret[e.frm] + e.cst < ret[e.to]) return\
    \ vector<T>();\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortestpath/bellmanford.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: graph/shortestpath/bellmanford.hpp
layout: document
redirect_from:
- /library/graph/shortestpath/bellmanford.hpp
- /library/graph/shortestpath/bellmanford.hpp.html
title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
---
## 概要

単一始点最短路. 負閉路検出ができる.

## 計算量

$O(EV)$

## 使用例

* `bellmanford(g, frm)` : `frm`からベルマンフォード法.
  * 返り値の型 : `vector<T>`
  * 負閉路があったら空の`vector`を返す.
