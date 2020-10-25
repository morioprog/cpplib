---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/bipartite/bipartite_check.md
    document_title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    links: []
  bundledCode: "#line 1 \"graph/bipartite/bipartite_check.hpp\"\n/**\n * @brief \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\n * @docs docs/graph/bipartite/bipartite_check.md\n\
    \ */\n\ntemplate <typename T>\n// int is_bipartite(const Graph<T> &g) {\nbool\
    \ is_bipartite(const Graph<T> &g) {\n    bool isbi = true;\n    vector<int> color(g.V,\
    \ 0);\n    auto dfs = [&](auto &&f, int i, int clr) -> void {\n        if (color[i]\
    \ != 0) return;\n        color[i] = clr;\n        for (auto &e : g.mat[i]) {\n\
    \            if (color[e.to] == 0)\n                f(f, e.to, -clr);\n      \
    \      else if (color[e.to] == clr)\n                isbi = false;\n        }\n\
    \    };\n    dfs(dfs, 0, 1);\n    return isbi;\n    // int cnt = 0;\n    // for\
    \ (auto &e : color)\n    //     if (e == 1) ++cnt;\n    // return isbi ? -1 :\
    \ cnt;\n}\n"
  code: "/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\n * @docs docs/graph/bipartite/bipartite_check.md\n\
    \ */\n\ntemplate <typename T>\n// int is_bipartite(const Graph<T> &g) {\nbool\
    \ is_bipartite(const Graph<T> &g) {\n    bool isbi = true;\n    vector<int> color(g.V,\
    \ 0);\n    auto dfs = [&](auto &&f, int i, int clr) -> void {\n        if (color[i]\
    \ != 0) return;\n        color[i] = clr;\n        for (auto &e : g.mat[i]) {\n\
    \            if (color[e.to] == 0)\n                f(f, e.to, -clr);\n      \
    \      else if (color[e.to] == clr)\n                isbi = false;\n        }\n\
    \    };\n    dfs(dfs, 0, 1);\n    return isbi;\n    // int cnt = 0;\n    // for\
    \ (auto &e : color)\n    //     if (e == 1) ++cnt;\n    // return isbi ? -1 :\
    \ cnt;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite/bipartite_check.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite/bipartite_check.hpp
layout: document
redirect_from:
- /library/graph/bipartite/bipartite_check.hpp
- /library/graph/bipartite/bipartite_check.hpp.html
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
## 概要

二部グラフの判定.

### 計算量

$O(E + V)$

### 使用例

* `is_bipartite(g)` : 二部グラフの判定.
  * 片方の集合の大きさが欲しかったら, 適宜コメントを外す.
