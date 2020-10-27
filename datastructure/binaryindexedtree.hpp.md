---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.binaryindexedtree.test.cpp
    title: test/aoj/DSL_2_B.binaryindexedtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1115.test.cpp
    title: test/yukicoder/1115.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/binaryindexedtree.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 1 \"datastructure/binaryindexedtree.hpp\"\n/**\n* @brief Binary\
    \ Indexed Tree\n* @docs docs/datastructure/binaryindexedtree.md\n*/\n\ntemplate\
    \ <typename T>\nstruct BinaryIndexedTree {\n    vector<T> data;\n    BinaryIndexedTree(int\
    \ sz) { data.assign(++sz, 0); }\n    T sum(int k) {\n        if (k < 0) return\
    \ T(0);\n        T ret = 0;\n        for (++k; k > 0; k -= k & -k) ret += data[k];\n\
    \        return (ret);\n    }\n    T sum(int l, int r) {\n        assert(l <=\
    \ r);\n        return sum(r - 1) - sum(l - 1);\n    }\n    void add(int k, T x)\
    \ {\n        for (++k; k < data.size(); k += k & -k) data[k] += x;\n    }\n};\n"
  code: "/**\n* @brief Binary Indexed Tree\n* @docs docs/datastructure/binaryindexedtree.md\n\
    */\n\ntemplate <typename T>\nstruct BinaryIndexedTree {\n    vector<T> data;\n\
    \    BinaryIndexedTree(int sz) { data.assign(++sz, 0); }\n    T sum(int k) {\n\
    \        if (k < 0) return T(0);\n        T ret = 0;\n        for (++k; k > 0;\
    \ k -= k & -k) ret += data[k];\n        return (ret);\n    }\n    T sum(int l,\
    \ int r) {\n        assert(l <= r);\n        return sum(r - 1) - sum(l - 1);\n\
    \    }\n    void add(int k, T x) {\n        for (++k; k < data.size(); k += k\
    \ & -k) data[k] += x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/binaryindexedtree.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1115.test.cpp
  - test/aoj/DSL_2_B.binaryindexedtree.test.cpp
documentation_of: datastructure/binaryindexedtree.hpp
layout: document
redirect_from:
- /library/datastructure/binaryindexedtree.hpp
- /library/datastructure/binaryindexedtree.hpp.html
title: Binary Indexed Tree
---
## 概要

一点加算クエリと区間和クエリを対数時間で行うデータ構造.

## 計算量

* 構築 : $O(n)$
* 区間取得 : $O(\log n)$
* 二分探索 : $O(\log n)$

## 使用例

* `BinaryIndexedTree<int> bit(N)` : 要素数$N$のBIT
* `bit.add(k, x)` : $k$要素目に$x$を加算.
* `bit.sum(k)` : 閉区間$[0, k]$の和を求める
* `bit.sum(l, r)` : 半開区間$[l, r)$の和を求める

