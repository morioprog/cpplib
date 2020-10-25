---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/staticrangesum.test.cpp
    title: test/yosupo/staticrangesum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/cumulativesum/cumulativesum.md
    document_title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"datastructure/cumulativesum/cumulativesum.hpp\"\n/**\n*\
    \ @brief 1\u6B21\u5143\u7D2F\u7A4D\u548C\n* @docs docs/datastructure/cumulativesum/cumulativesum.md\n\
    */\n\ntemplate <typename T>\nstruct CumulativeSum {\n    int sz;\n    vector<T>\
    \ data;\n    CumulativeSum(const vector<T> &v, const T margin = 0)\n        :\
    \ sz(v.size()), data(1, margin) {\n        for (int i = 0; i < sz; ++i) data.emplace_back(data[i]\
    \ + v[i]);\n    }\n    T query(const int &l, const int &r) const {\n        if\
    \ (l >= r) return 0;\n        return data[min(r, sz)] - data[max(l, 0)];\n   \
    \ }\n    T operator[](const int &k) const {\n        return query(k, k + 1);\n\
    \    }\n    void print() {\n        for (int i = 0; i < sz; ++i) cerr << data[i]\
    \ << ' ';\n        cerr << endl;\n    }\n};\n"
  code: "/**\n* @brief 1\u6B21\u5143\u7D2F\u7A4D\u548C\n* @docs docs/datastructure/cumulativesum/cumulativesum.md\n\
    */\n\ntemplate <typename T>\nstruct CumulativeSum {\n    int sz;\n    vector<T>\
    \ data;\n    CumulativeSum(const vector<T> &v, const T margin = 0)\n        :\
    \ sz(v.size()), data(1, margin) {\n        for (int i = 0; i < sz; ++i) data.emplace_back(data[i]\
    \ + v[i]);\n    }\n    T query(const int &l, const int &r) const {\n        if\
    \ (l >= r) return 0;\n        return data[min(r, sz)] - data[max(l, 0)];\n   \
    \ }\n    T operator[](const int &k) const {\n        return query(k, k + 1);\n\
    \    }\n    void print() {\n        for (int i = 0; i < sz; ++i) cerr << data[i]\
    \ << ' ';\n        cerr << endl;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/cumulativesum/cumulativesum.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/staticrangesum.test.cpp
documentation_of: datastructure/cumulativesum/cumulativesum.hpp
layout: document
redirect_from:
- /library/datastructure/cumulativesum/cumulativesum.hpp
- /library/datastructure/cumulativesum/cumulativesum.hpp.html
title: "1\u6B21\u5143\u7D2F\u7A4D\u548C"
---
## 概要

静的な配列に対する区間和クエリに答える.

## 計算量

* 構築 : $O(n)$
* クエリ : $O(1)$

## 使用例

* `CumulativeSum<int> acc(v)` : `v`で累積和を構築.
* `acc.query(l, r)` : 半開区間$[l, r)$のクエリ.
* `acc[k]` : 元の配列の$k$要素目.
* `acc.print()` : 累積和の中身をデバッグ出力.
