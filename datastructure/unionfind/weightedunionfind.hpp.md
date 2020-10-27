---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1330.test.cpp
    title: test/aoj/1330.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.weightedunionfind.test.cpp
    title: test/yosupo/unionfind.weightedunionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/unionfind/weightedunionfind.md
    document_title: "\u91CD\u307F\u4ED8\u304DUnionFind"
    links:
    - https://qiita.com/drken/items/cce6fc5c579051e64fab
  bundledCode: "#line 1 \"datastructure/unionfind/weightedunionfind.hpp\"\n/**\n*\
    \ @brief \u91CD\u307F\u4ED8\u304DUnionFind\n* @docs docs/datastructure/unionfind/weightedunionfind.md\n\
    * @see https://qiita.com/drken/items/cce6fc5c579051e64fab\n*/\n\ntemplate <typename\
    \ T>\nstruct WeightedUnionFind {\n    int sz;\n    vector<int> parent;\n    vector<T>\
    \ diff_weight;\n    WeightedUnionFind(int sz)\n        : sz(sz), parent(sz, -1),\
    \ diff_weight(sz, T(0)) {}\n    // weight(y) = weight(x) + w\n    bool unite(int\
    \ x, int y, T w) {\n        w += weight(x) - weight(y);\n        if ((x = find(x))\
    \ != (y = find(y))) {\n            if (parent[y] < parent[x]) swap(x, y), w =\
    \ -w;\n            --sz;\n            parent[x] += parent[y];\n            parent[y]\
    \      = x;\n            diff_weight[y] = w;\n        }\n        return true;\n\
    \    }\n    int find(int x) {\n        if (parent[x] < 0) return x;\n        int\
    \ ret = find(parent[x]);\n        diff_weight[x] += diff_weight[parent[x]];\n\
    \        return parent[x] = ret;\n    }\n    T weight(int x) {\n        find(x);\n\
    \        return diff_weight[x];\n    }\n    T diff(int x, int y) { return weight(y)\
    \ - weight(x); }\n    bool same(int x, int y) { return find(x) == find(y); }\n\
    \    int size(int x) { return -parent[find(x)]; }\n    int size() { return sz;\
    \ }\n};\n"
  code: "/**\n* @brief \u91CD\u307F\u4ED8\u304DUnionFind\n* @docs docs/datastructure/unionfind/weightedunionfind.md\n\
    * @see https://qiita.com/drken/items/cce6fc5c579051e64fab\n*/\n\ntemplate <typename\
    \ T>\nstruct WeightedUnionFind {\n    int sz;\n    vector<int> parent;\n    vector<T>\
    \ diff_weight;\n    WeightedUnionFind(int sz)\n        : sz(sz), parent(sz, -1),\
    \ diff_weight(sz, T(0)) {}\n    // weight(y) = weight(x) + w\n    bool unite(int\
    \ x, int y, T w) {\n        w += weight(x) - weight(y);\n        if ((x = find(x))\
    \ != (y = find(y))) {\n            if (parent[y] < parent[x]) swap(x, y), w =\
    \ -w;\n            --sz;\n            parent[x] += parent[y];\n            parent[y]\
    \      = x;\n            diff_weight[y] = w;\n        }\n        return true;\n\
    \    }\n    int find(int x) {\n        if (parent[x] < 0) return x;\n        int\
    \ ret = find(parent[x]);\n        diff_weight[x] += diff_weight[parent[x]];\n\
    \        return parent[x] = ret;\n    }\n    T weight(int x) {\n        find(x);\n\
    \        return diff_weight[x];\n    }\n    T diff(int x, int y) { return weight(y)\
    \ - weight(x); }\n    bool same(int x, int y) { return find(x) == find(y); }\n\
    \    int size(int x) { return -parent[find(x)]; }\n    int size() { return sz;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/weightedunionfind.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
  - test/aoj/1330.test.cpp
  - test/yosupo/unionfind.weightedunionfind.test.cpp
documentation_of: datastructure/unionfind/weightedunionfind.hpp
layout: document
redirect_from:
- /library/datastructure/unionfind/weightedunionfind.hpp
- /library/datastructure/unionfind/weightedunionfind.hpp.html
title: "\u91CD\u307F\u4ED8\u304DUnionFind"
---
## 概要

連結成分と**ノード間の距離**を管理するデータ構造.

## 計算量

$O(\alpha (n))$

## 使用例

* `WeightedUnionFind uf(V)` : $V$頂点の重み付きUnionFindを定義.
* `uf.unite(x, y, w)` : $x$と$y$を連結にする.
  * このとき, $\mathrm{weight}(y) = \mathrm{weight}(x) + w$となるようにする.
* `uf.same(x, y)` : $x$と$y$が連結かを返す.
* `uf.size(x)` : $x$の属する連結成分の大きさを返す.
* `uf.size()` : 連結成分の個数を返す.
