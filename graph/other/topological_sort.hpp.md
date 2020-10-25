---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_B.test.cpp
    title: test/aoj/GRL_4_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/other/topological_sort.md
    document_title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
    links: []
  bundledCode: "#line 1 \"graph/other/topological_sort.hpp\"\n/**\n* @brief \u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n* @docs docs/graph/other/topological_sort.md\n\
    */\n\ntemplate <typename T>\nvector<int> topological_sort(const Graph<T> &g) {\n\
    \    vector<int> order, color(g.V, 0);\n    auto rec = [&](auto &&f, int v) ->\
    \ bool {\n        color[v] = 1;\n        for (auto &e : g.mat[v]) {\n        \
    \    if (color[e] == 2) continue;\n            if (color[e] == 1) return false;\n\
    \            if (not f(f, e)) return false;\n        }\n        order.push_back(v);\n\
    \        color[v] = 2;\n        return true;\n    };\n    for (int i = 0; i <\
    \ g.V; ++i)\n        if (not color[i] and not rec(rec, i)) return vector<int>();\n\
    \    reverse(order.begin(), order.end());\n    return order;\n}\n"
  code: "/**\n* @brief \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n* @docs\
    \ docs/graph/other/topological_sort.md\n*/\n\ntemplate <typename T>\nvector<int>\
    \ topological_sort(const Graph<T> &g) {\n    vector<int> order, color(g.V, 0);\n\
    \    auto rec = [&](auto &&f, int v) -> bool {\n        color[v] = 1;\n      \
    \  for (auto &e : g.mat[v]) {\n            if (color[e] == 2) continue;\n    \
    \        if (color[e] == 1) return false;\n            if (not f(f, e)) return\
    \ false;\n        }\n        order.push_back(v);\n        color[v] = 2;\n    \
    \    return true;\n    };\n    for (int i = 0; i < g.V; ++i)\n        if (not\
    \ color[i] and not rec(rec, i)) return vector<int>();\n    reverse(order.begin(),\
    \ order.end());\n    return order;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/other/topological_sort.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_4_B.test.cpp
documentation_of: graph/other/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/other/topological_sort.hpp
- /library/graph/other/topological_sort.hpp.html
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
## 概要

トポロジカルソート.

### 計算量

$O(E + V)$

## 使用例

* `topological_sort(g)` : グラフ`g`をトポロジカルソート.
  * トポロジカルソートが出来ないなら`vector<int>()`を返す.
