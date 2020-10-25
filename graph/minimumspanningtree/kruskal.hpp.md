---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/minimumspanningtree/kruskal.md
    document_title: "\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5"
    links: []
  bundledCode: "#line 1 \"graph/minimumspanningtree/kruskal.hpp\"\n/**\n* @brief \u30AF\
    \u30E9\u30B9\u30AB\u30EB\u6CD5\n* @docs docs/graph/minimumspanningtree/kruskal.md\n\
    */\n\ntemplate <typename T>\nT kruskal(const Graph<T> &g) {\n    vector<Edge<T>>\
    \ edges;\n    for (int i = 0; i < g.V; ++i)\n        for (auto &e : g.mat[i])\
    \ edges.emplace_back(e);\n    sort(edges.begin(), edges.end(), [](const Edge<T>\
    \ &a, const Edge<T> &b) {\n        return a.cst < b.cst;\n    });\n    UnionFind\
    \ uf(g.V);\n    T ret(0);\n    for (auto &e : edges)\n        if (uf.unite(e.frm,\
    \ e.to)) ret += e.cst;\n    return ret;\n}\n"
  code: "/**\n* @brief \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5\n* @docs docs/graph/minimumspanningtree/kruskal.md\n\
    */\n\ntemplate <typename T>\nT kruskal(const Graph<T> &g) {\n    vector<Edge<T>>\
    \ edges;\n    for (int i = 0; i < g.V; ++i)\n        for (auto &e : g.mat[i])\
    \ edges.emplace_back(e);\n    sort(edges.begin(), edges.end(), [](const Edge<T>\
    \ &a, const Edge<T> &b) {\n        return a.cst < b.cst;\n    });\n    UnionFind\
    \ uf(g.V);\n    T ret(0);\n    for (auto &e : edges)\n        if (uf.unite(e.frm,\
    \ e.to)) ret += e.cst;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/minimumspanningtree/kruskal.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/minimumspanningtree/kruskal.hpp
layout: document
redirect_from:
- /library/graph/minimumspanningtree/kruskal.hpp
- /library/graph/minimumspanningtree/kruskal.hpp.html
title: "\u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5"
---
## 概要

最小全域木を求めるアルゴリズム. 内部でUnionFindを使用している.

## 計算量

$O(E\log V)$

## 使用例

* `kruskal(g)` : グラフ`g`に対してクラスカル法を行う.
  * 返り値 : 最小全域木の重さ.
