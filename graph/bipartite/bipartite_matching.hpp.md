---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/bipartite/bipartite_matching.md
    document_title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
    links:
    - https://qiita.com/drken/items/7f98315b56c95a6181a4
    - https://qiita.com/drken/items/e805e3f514acceb87602
  bundledCode: "#line 1 \"graph/bipartite/bipartite_matching.hpp\"\n/**\n * @brief\
    \ \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\
    \n * @docs docs/graph/bipartite/bipartite_matching.md\n * @see https://qiita.com/drken/items/e805e3f514acceb87602\n\
    \ * @see https://qiita.com/drken/items/7f98315b56c95a6181a4\n */\n\ntemplate <typename\
    \ T>\nint bipartite_matching(const Graph<T> &g) {\n    int timestamp = 0;\n  \
    \  vector<int> alive(g.V, 1), used(g.V, 0), match(g.V, -1);\n    auto dfs = [&](auto\
    \ &&f, int cur) -> bool {\n        used[cur] = timestamp;\n        for (auto &nxt\
    \ : g.mat[cur]) {\n            int w = match[nxt];\n            if (alive[nxt]\
    \ == 0) continue;\n            if (w == -1 or (used[w] != timestamp and f(f, w)))\
    \ {\n                match[cur] = nxt;\n                match[nxt] = cur;\n  \
    \              return true;\n            }\n        }\n        return false;\n\
    \    };\n    int ret = 0;\n    for (int i = 0; i < g.V; ++i) {\n        if (alive[i]\
    \ == 0) continue;\n        if (match[i] == -1) {\n            ++timestamp;\n \
    \           ret += dfs(dfs, i);\n        }\n    }\n    return ret;\n}\n"
  code: "/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\
    \u30C1\u30F3\u30B0\n * @docs docs/graph/bipartite/bipartite_matching.md\n * @see\
    \ https://qiita.com/drken/items/e805e3f514acceb87602\n * @see https://qiita.com/drken/items/7f98315b56c95a6181a4\n\
    \ */\n\ntemplate <typename T>\nint bipartite_matching(const Graph<T> &g) {\n \
    \   int timestamp = 0;\n    vector<int> alive(g.V, 1), used(g.V, 0), match(g.V,\
    \ -1);\n    auto dfs = [&](auto &&f, int cur) -> bool {\n        used[cur] = timestamp;\n\
    \        for (auto &nxt : g.mat[cur]) {\n            int w = match[nxt];\n   \
    \         if (alive[nxt] == 0) continue;\n            if (w == -1 or (used[w]\
    \ != timestamp and f(f, w))) {\n                match[cur] = nxt;\n          \
    \      match[nxt] = cur;\n                return true;\n            }\n      \
    \  }\n        return false;\n    };\n    int ret = 0;\n    for (int i = 0; i <\
    \ g.V; ++i) {\n        if (alive[i] == 0) continue;\n        if (match[i] == -1)\
    \ {\n            ++timestamp;\n            ret += dfs(dfs, i);\n        }\n  \
    \  }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.test.cpp
documentation_of: graph/bipartite/bipartite_matching.hpp
layout: document
redirect_from:
- /library/graph/bipartite/bipartite_matching.hpp
- /library/graph/bipartite/bipartite_matching.hpp.html
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
## 概要

二部グラフの最大マッチング. 最大流で求める.

* 最大マッチングは, 最小点被覆$M$と一致.
* 最大安定集合(最大独立集合)は, 最小辺被覆と$V - M$で一致.

### 計算量

$O(EV)$

### 使用例

* `bipartite_matching(g)` : 二部グラフの最大マッチング.
  * マッチングの個数を返す.
