---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/maximumflow/moyasu_umeru.md
    document_title: "\u71C3\u3084\u3059\u57CB\u3081\u308B"
    links:
    - https://yosupo.hatenablog.com/entry/2015/03/31/134336
  bundledCode: "#line 1 \"graph/maximumflow/moyasu_umeru.hpp\"\n/**\n* @brief \u71C3\
    \u3084\u3059\u57CB\u3081\u308B\n* @docs docs/graph/maximumflow/moyasu_umeru.md\n\
    * @see https://yosupo.hatenablog.com/entry/2015/03/31/134336\n*/\n\ntemplate <typename\
    \ T>\nstruct moyasu_umeru {\n    int N;\n    T margin;\n    const int R, B;  //\
    \ R:red, B:blue\n    const T INF;\n    vector<tuple<int, int, T>> edges;\n   \
    \ moyasu_umeru(int V, T INF = numeric_limits<T>::max() / 10)\n        : N(V +\
    \ 2), margin(0), R(V), B(V + 1), INF(INF) {}\n    void red_blue_penalty(int r,\
    \ int b, T pena) {\n        edges.emplace_back(r, b, pena);\n    }\n    void red_penalty(int\
    \ r, T pena) {\n        red_blue_penalty(r, B, pena);\n    }\n    void blue_penalty(int\
    \ b, T pena) {\n        red_blue_penalty(R, b, pena);\n    }\n    void red_reward(int\
    \ r, T rwrd) {\n        margin += rwrd;\n        blue_penalty(r, rwrd);\n    }\n\
    \    void blue_reward(int b, T rwrd) {\n        margin += rwrd;\n        red_penalty(b,\
    \ rwrd);\n    }\n    void reds_reward(vector<int> v_r, T rwrd) {\n        margin\
    \ += rwrd;\n        edges.emplace_back(R, N, rwrd);\n        for (auto& r : v_r)\
    \ edges.emplace_back(N, r, INF);\n        ++N;\n    }\n    void blues_reward(vector<int>\
    \ v_b, T rwrd) {\n        margin += rwrd;\n        edges.emplace_back(N, B, rwrd);\n\
    \        for (auto& b : v_b) edges.emplace_back(b, N, INF);\n        ++N;\n  \
    \  }\n};\n"
  code: "/**\n* @brief \u71C3\u3084\u3059\u57CB\u3081\u308B\n* @docs docs/graph/maximumflow/moyasu_umeru.md\n\
    * @see https://yosupo.hatenablog.com/entry/2015/03/31/134336\n*/\n\ntemplate <typename\
    \ T>\nstruct moyasu_umeru {\n    int N;\n    T margin;\n    const int R, B;  //\
    \ R:red, B:blue\n    const T INF;\n    vector<tuple<int, int, T>> edges;\n   \
    \ moyasu_umeru(int V, T INF = numeric_limits<T>::max() / 10)\n        : N(V +\
    \ 2), margin(0), R(V), B(V + 1), INF(INF) {}\n    void red_blue_penalty(int r,\
    \ int b, T pena) {\n        edges.emplace_back(r, b, pena);\n    }\n    void red_penalty(int\
    \ r, T pena) {\n        red_blue_penalty(r, B, pena);\n    }\n    void blue_penalty(int\
    \ b, T pena) {\n        red_blue_penalty(R, b, pena);\n    }\n    void red_reward(int\
    \ r, T rwrd) {\n        margin += rwrd;\n        blue_penalty(r, rwrd);\n    }\n\
    \    void blue_reward(int b, T rwrd) {\n        margin += rwrd;\n        red_penalty(b,\
    \ rwrd);\n    }\n    void reds_reward(vector<int> v_r, T rwrd) {\n        margin\
    \ += rwrd;\n        edges.emplace_back(R, N, rwrd);\n        for (auto& r : v_r)\
    \ edges.emplace_back(N, r, INF);\n        ++N;\n    }\n    void blues_reward(vector<int>\
    \ v_b, T rwrd) {\n        margin += rwrd;\n        edges.emplace_back(N, B, rwrd);\n\
    \        for (auto& b : v_b) edges.emplace_back(b, N, INF);\n        ++N;\n  \
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximumflow/moyasu_umeru.hpp
  requiredBy: []
  timestamp: '2020-09-13 19:13:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximumflow/moyasu_umeru.hpp
layout: document
redirect_from:
- /library/graph/maximumflow/moyasu_umeru.hpp
- /library/graph/maximumflow/moyasu_umeru.hpp.html
title: "\u71C3\u3084\u3059\u57CB\u3081\u308B"
---
## 概要

> わっけわかんねえほど沢山の制約ドパァな問題を解く一般的なテク

条件を読ませて, 張るべき辺を返す.

## 使用例

- `moyasu_umeru<int> mu(V)` : $V$頂点のグラフを定義.
  - コストの型 : `int`
- `mu.red_blue_penalty(r, b, pena)` : 頂点$r$を赤く, 頂点$b$を青く塗ったら罰金$pena$.
- `mu.red_penalty(r, pena)` : 頂点$r$を赤く塗ったら罰金$pena$.
- `mu.blue_penalty(b, pena)` : 頂点$b$を赤く塗ったら罰金$pena$.
- `mu.red_reward(r, rwrd)` : 頂点$r$を赤く塗ったら賞金$rwrd$.
- `mu.blue_reward(b, rwrd)` : 頂点$b$を青く塗ったら賞金$rwrd$.
- `mu.reds_reward(v_r, rwrd)` : 頂点群$v_r$を全て赤く塗ったら賞金$rwrd$.
- `mu.blues_reward(v_b, rwrd)` : 頂点群$v_b$を青て赤く塗ったら賞金$rwrd$.
- `mu.edges` : 張るべき辺.
- `mu.margin` : 無条件で得られる賞金.
