---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/shortestpath/warshallfloyd.md
    document_title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
    links: []
  bundledCode: "#line 1 \"graph/shortestpath/warshallfloyd.hpp\"\n/**\n* @brief \u30EF\
    \u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\n* @docs docs/graph/shortestpath/warshallfloyd.md\n\
    */\n\ntemplate <typename T>\nbool warshallfloyd(Graph<T> &g) {\n    g.wf.assign(g.V,\
    \ vector<T>(g.V, GINF<T>));\n    for (int i = 0; i < g.V; ++i) g.wf[i][i] = 0;\n\
    \    for (int i = 0; i < g.V; ++i)\n        for (auto &e : g.mat[i]) g.wf[e.frm][e.to]\
    \ = min(g.wf[e.frm][e.to], e.cst);\n    for (int k = 0; k < g.V; ++k)\n      \
    \  for (int i = 0; i < g.V; ++i)\n            for (int j = 0; j < g.V; ++j) {\n\
    \                if (g.wf[i][k] != GINF<T> and g.wf[k][j] != GINF<T>) g.wf[i][j]\
    \ = min(g.wf[i][j], g.wf[i][k] + g.wf[k][j]);\n            }\n    bool hasnegcycle\
    \ = false;\n    for (int i = 0; i < g.V; ++i) hasnegcycle |= g.wf[i][i] < 0;\n\
    \    return hasnegcycle;\n}\n\ntemplate <typename T>\nvoid warshallfloyd_update(Graph<T>\
    \ &g, int frm, int to, T cst) {\n    if (g.wf[frm][to] <= cst) return;\n    g.wf[frm][to]\
    \ = cst;\n    for (int i = 0; i < g.V; ++i) {\n        for (int j = 0; j < g.V;\
    \ ++j) {\n            if (g.wf[i][frm] != GINF<T> and g.wf[frm][j] != GINF<T>)\
    \ {\n                g.wf[i][j] = min(g.wf[i][j], g.wf[i][frm] + g.wf[frm][j]);\n\
    \            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid warshallfloyd_add_arc(Graph<T>\
    \ &g, int frm, int to, T cst) {\n    g.add_arc(frm, to, cst);\n    warshallfloyd_update(g,\
    \ frm, to, cst);\n}\n\ntemplate <typename T>\nvoid warshallfloyd_add_edge(Graph<T>\
    \ &g, int frm, int to, T cst) {\n    g.add_edge(frm, to, cst);\n    warshallfloyd_update(g,\
    \ frm, to, cst);\n    warshallfloyd_update(g, to, frm, cst);\n}\n"
  code: "/**\n* @brief \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\
    \n* @docs docs/graph/shortestpath/warshallfloyd.md\n*/\n\ntemplate <typename T>\n\
    bool warshallfloyd(Graph<T> &g) {\n    g.wf.assign(g.V, vector<T>(g.V, GINF<T>));\n\
    \    for (int i = 0; i < g.V; ++i) g.wf[i][i] = 0;\n    for (int i = 0; i < g.V;\
    \ ++i)\n        for (auto &e : g.mat[i]) g.wf[e.frm][e.to] = min(g.wf[e.frm][e.to],\
    \ e.cst);\n    for (int k = 0; k < g.V; ++k)\n        for (int i = 0; i < g.V;\
    \ ++i)\n            for (int j = 0; j < g.V; ++j) {\n                if (g.wf[i][k]\
    \ != GINF<T> and g.wf[k][j] != GINF<T>) g.wf[i][j] = min(g.wf[i][j], g.wf[i][k]\
    \ + g.wf[k][j]);\n            }\n    bool hasnegcycle = false;\n    for (int i\
    \ = 0; i < g.V; ++i) hasnegcycle |= g.wf[i][i] < 0;\n    return hasnegcycle;\n\
    }\n\ntemplate <typename T>\nvoid warshallfloyd_update(Graph<T> &g, int frm, int\
    \ to, T cst) {\n    if (g.wf[frm][to] <= cst) return;\n    g.wf[frm][to] = cst;\n\
    \    for (int i = 0; i < g.V; ++i) {\n        for (int j = 0; j < g.V; ++j) {\n\
    \            if (g.wf[i][frm] != GINF<T> and g.wf[frm][j] != GINF<T>) {\n    \
    \            g.wf[i][j] = min(g.wf[i][j], g.wf[i][frm] + g.wf[frm][j]);\n    \
    \        }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid warshallfloyd_add_arc(Graph<T>\
    \ &g, int frm, int to, T cst) {\n    g.add_arc(frm, to, cst);\n    warshallfloyd_update(g,\
    \ frm, to, cst);\n}\n\ntemplate <typename T>\nvoid warshallfloyd_add_edge(Graph<T>\
    \ &g, int frm, int to, T cst) {\n    g.add_edge(frm, to, cst);\n    warshallfloyd_update(g,\
    \ frm, to, cst);\n    warshallfloyd_update(g, to, frm, cst);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortestpath/warshallfloyd.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: graph/shortestpath/warshallfloyd.hpp
layout: document
redirect_from:
- /library/graph/shortestpath/warshallfloyd.hpp
- /library/graph/shortestpath/warshallfloyd.hpp.html
title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
---
## 概要

全点間最短路. 負閉路検出ができる.

## 計算量

* 構築 : $O(V^3)$
* 更新 : $O(V^2)$

## 使用例

* `warshallfloyd(g)` : ワーシャルフロイド法を行う.
  * 結果は`g.wf`に格納される.
  * 返り値の型 : `bool`
  * 負閉路があったら`true`を返す.
* `warshallfloyd_add_arc(g, frm, to, cst)` : 有向辺を追加して, `g.wf`を更新.
* `warshallfloyd_add_edge(g, frm, to, cst)` : 無向辺を追加して, `g.wf`を更新.
