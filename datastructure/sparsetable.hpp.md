---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/sparsetable.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"datastructure/sparsetable.hpp\"\n/**\n* @brief Sparse Table\n\
    * @docs docs/datastructure/sparsetable.md\n*/\n\ntemplate <typename T>\nstruct\
    \ SparseTable {\n    vector<vector<T>> st;\n    using F = function<T(T, T)>;\n\
    \    const F f;\n    SparseTable() {}\n    SparseTable(const vector<T> &v, const\
    \ F f)\n        : f(f) {\n        int b = 0, sz = v.size();\n        while ((1\
    \ << b) <= sz) ++b;\n        st.assign(b, vector<T>(1 << b));\n        for (int\
    \ i = 0; i < sz; ++i) st[0][i] = v[i];\n        for (int i = 1; i < b; ++i) {\n\
    \            for (int j = 0; j + (1 << i) <= (1 << b); ++j) {\n              \
    \  st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n            }\n\
    \        }\n    }\n    T query(const int l, const int r) const {\n        int\
    \ b = 31 - __builtin_clz(r - l);\n        return f(st[b][l], st[b][r - (1 << b)]);\n\
    \    }\n};\n"
  code: "/**\n* @brief Sparse Table\n* @docs docs/datastructure/sparsetable.md\n*/\n\
    \ntemplate <typename T>\nstruct SparseTable {\n    vector<vector<T>> st;\n   \
    \ using F = function<T(T, T)>;\n    const F f;\n    SparseTable() {}\n    SparseTable(const\
    \ vector<T> &v, const F f)\n        : f(f) {\n        int b = 0, sz = v.size();\n\
    \        while ((1 << b) <= sz) ++b;\n        st.assign(b, vector<T>(1 << b));\n\
    \        for (int i = 0; i < sz; ++i) st[0][i] = v[i];\n        for (int i = 1;\
    \ i < b; ++i) {\n            for (int j = 0; j + (1 << i) <= (1 << b); ++j) {\n\
    \                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n    }\n    T query(const int l, const int r) const\
    \ {\n        int b = 31 - __builtin_clz(r - l);\n        return f(st[b][l], st[b][r\
    \ - (1 << b)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/sparsetable.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: datastructure/sparsetable.hpp
layout: document
redirect_from:
- /library/datastructure/sparsetable.hpp
- /library/datastructure/sparsetable.hpp.html
title: Sparse Table
---
## 概要

静的な数列に対する区間取得クエリを定数時間で答えられるデータ構造.

渡す二項演算$f$は結合律と冪等律を満たす必要がある.

* 結合律 : $f(f(x, y), z) = f(x, f(y, z))$
* 冪等律 : $f(x, x) = x$

## 計算量

* 構築 : $O(n\log n)$
* 区間取得 : $O(1)$

## 使用例

* `SparseTable<int> st(v, [](int a, int b){ return min(a, b); })` : 区間最小クエリを処理するSparse Tableを構築.
* `st.query(l, r)` : 半開区間$[l, r)$の区間取得クエリ.
