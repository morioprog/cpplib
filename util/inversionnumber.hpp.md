---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1115.test.cpp
    title: test/yukicoder/1115.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/util/inversionnumber.md
    document_title: "\u8EE2\u5012\u6570"
    links: []
  bundledCode: "#line 1 \"util/inversionnumber.hpp\"\n/**\n* @brief \u8EE2\u5012\u6570\
    \n* @docs docs/util/inversionnumber.md\n*/\n\ntemplate <typename T>\nlong long\
    \ inversion_number(vector<T> &v) {\n    int sz = v.size();\n    vector<T> rev,\
    \ v_cp(v);\n    sort(v_cp.begin(), v_cp.end());\n    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(),\
    \ v_cp.end(), e) - v_cp.begin());\n    BinaryIndexedTree<T> bit(sz);\n    long\
    \ long ret = 0;\n    for (int i = 0; i < sz; ++i) {\n        ret += i - bit.sum(rev[i]);\n\
    \        bit.add(rev[i], 1);\n    }\n    return ret;\n}\n"
  code: "/**\n* @brief \u8EE2\u5012\u6570\n* @docs docs/util/inversionnumber.md\n\
    */\n\ntemplate <typename T>\nlong long inversion_number(vector<T> &v) {\n    int\
    \ sz = v.size();\n    vector<T> rev, v_cp(v);\n    sort(v_cp.begin(), v_cp.end());\n\
    \    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(),\
    \ e) - v_cp.begin());\n    BinaryIndexedTree<T> bit(sz);\n    long long ret =\
    \ 0;\n    for (int i = 0; i < sz; ++i) {\n        ret += i - bit.sum(rev[i]);\n\
    \        bit.add(rev[i], 1);\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: util/inversionnumber.hpp
  requiredBy: []
  timestamp: '2020-08-24 21:21:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1115.test.cpp
documentation_of: util/inversionnumber.hpp
layout: document
redirect_from:
- /library/util/inversionnumber.hpp
- /library/util/inversionnumber.hpp.html
title: "\u8EE2\u5012\u6570"
---
## 概要

転倒数. $i < j$ かつ $a_i > a_j$ となる組$(i, j)$の個数. バブルソートのスワップ回数と等しい.

## 計算量

$O(n\log n)$

## 使用例

* `inversion_number(v)` : `v`の転倒数.
