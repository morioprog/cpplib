---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/755.test.cpp
    title: test/yukicoder/755.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/cumulativesum/cumulativesum2d.md
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"datastructure/cumulativesum/cumulativesum2d.hpp\"\n/**\n\
    * @brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n* @docs docs/datastructure/cumulativesum/cumulativesum2d.md\n\
    */\n\ntemplate <class T>\nstruct CumulativeSum2D {\n    int H, W;\n    vector<vector<T>>\
    \ data;\n    CumulativeSum2D(const vector<vector<T>> &v) {\n        H = v.size();\n\
    \        W = (H == 0) ? 0 : v[0].size();\n        data.assign(H + 1, vector<T>(W\
    \ + 1, 0));\n        for (int i = 0; i < H; ++i) {\n            for (int j = 0;\
    \ j < W; ++j) {\n                data[i + 1][j + 1] = v[i][j] + data[i + 1][j]\
    \ + data[i][j + 1] - data[i][j];\n            }\n        }\n    }\n    T query(int\
    \ sx, int sy, int gx, int gy) {\n        return data[gx][gy] - data[sx][gy] -\
    \ data[gx][sy] + data[sx][sy];\n    }\n};\n"
  code: "/**\n* @brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n* @docs docs/datastructure/cumulativesum/cumulativesum2d.md\n\
    */\n\ntemplate <class T>\nstruct CumulativeSum2D {\n    int H, W;\n    vector<vector<T>>\
    \ data;\n    CumulativeSum2D(const vector<vector<T>> &v) {\n        H = v.size();\n\
    \        W = (H == 0) ? 0 : v[0].size();\n        data.assign(H + 1, vector<T>(W\
    \ + 1, 0));\n        for (int i = 0; i < H; ++i) {\n            for (int j = 0;\
    \ j < W; ++j) {\n                data[i + 1][j + 1] = v[i][j] + data[i + 1][j]\
    \ + data[i][j + 1] - data[i][j];\n            }\n        }\n    }\n    T query(int\
    \ sx, int sy, int gx, int gy) {\n        return data[gx][gy] - data[sx][gy] -\
    \ data[gx][sy] + data[sx][sy];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulativesum/cumulativesum2d.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/755.test.cpp
documentation_of: datastructure/cumulativesum/cumulativesum2d.hpp
layout: document
redirect_from:
- /library/datastructure/cumulativesum/cumulativesum2d.hpp
- /library/datastructure/cumulativesum/cumulativesum2d.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
## 概要

静的な2次元配列に対する矩形和クエリに答える.

## 計算量

* 構築 : $O(hw)$
* クエリ : $O(1)$

## 使用例

* `CumulativeSum2D<int> acc(v)` : `v`で2次元累積和を構築.
* `acc.query(a, b, c, d)` : 矩形$[a, b]$から$(c, d)$までのクエリ.
