---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.unionfind.test.cpp
    title: test/yosupo/unionfind.unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/unionfind/unionfind.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 1 \"datastructure/unionfind/unionfind.hpp\"\n/**\n* @brief UnionFind\n\
    * @docs docs/datastructure/unionfind/unionfind.md\n*/\n\nstruct UnionFind {\n\
    \    int sz;\n    vector<int> parent;\n    UnionFind(int sz)\n        : sz(sz),\
    \ parent(sz, -1) {}\n    bool unite(int x, int y) {\n        if ((x = find(x))\
    \ != (y = find(y))) {\n            if (parent[y] < parent[x]) swap(x, y);\n  \
    \          parent[x] += parent[y];\n            parent[y] = x;\n            --sz;\n\
    \            return true;\n        }\n        return false;\n    }\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n    int find(int x) { return parent[x]\
    \ < 0 ? x : parent[x] = find(parent[x]); }\n    int size(int x) { return -parent[find(x)];\
    \ }\n    int size() { return sz; }\n};\n"
  code: "/**\n* @brief UnionFind\n* @docs docs/datastructure/unionfind/unionfind.md\n\
    */\n\nstruct UnionFind {\n    int sz;\n    vector<int> parent;\n    UnionFind(int\
    \ sz)\n        : sz(sz), parent(sz, -1) {}\n    bool unite(int x, int y) {\n \
    \       if ((x = find(x)) != (y = find(y))) {\n            if (parent[y] < parent[x])\
    \ swap(x, y);\n            parent[x] += parent[y];\n            parent[y] = x;\n\
    \            --sz;\n            return true;\n        }\n        return false;\n\
    \    }\n    bool same(int x, int y) { return find(x) == find(y); }\n    int find(int\
    \ x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }\n    int size(int\
    \ x) { return -parent[find(x)]; }\n    int size() { return sz; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind/unionfind.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.unionfind.test.cpp
  - test/aoj/GRL_2_A.test.cpp
documentation_of: datastructure/unionfind/unionfind.hpp
layout: document
redirect_from:
- /library/datastructure/unionfind/unionfind.hpp
- /library/datastructure/unionfind/unionfind.hpp.html
title: UnionFind
---
## 概要

連結成分を管理するデータ構造. [素集合データ構造](https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0).

## 計算量

$O(\alpha (n))$

## 使用例

* `UnionFind uf(V)` : $V$頂点のUnionFindを定義.
* `uf.unite(x, y)` : $x$と$y$を連結にする.
* `uf.same(x, y)` : $x$と$y$が連結かを返す.
* `uf.size(x)` : $x$の属する連結成分の大きさを返す.
* `uf.size()` : 連結成分の個数を返す.
