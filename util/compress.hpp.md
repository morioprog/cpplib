---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/util/compress.md
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"util/compress.hpp\"\n/**\n* @brief \u5EA7\u6A19\u5727\u7E2E\
    \n* @docs docs/util/compress.md\n*/\n\ntemplate <typename T>\npair<vector<T>,\
    \ map<T, int>> compress(vector<T> ord) {\n    vector<T> com(ord);\n    map<T,\
    \ int> rev;\n    sort(com.begin(), com.end());\n    com.erase(unique(com.begin(),\
    \ com.end()), com.end());\n    for (int i = 0; i < com.size(); ++i) rev[com[i]]\
    \ = i;\n    vector<T> ret;\n    for (auto& e : ord) ret.emplace_back(rev[e]);\n\
    \    return make_pair(ret, rev);\n}\n"
  code: "/**\n* @brief \u5EA7\u6A19\u5727\u7E2E\n* @docs docs/util/compress.md\n*/\n\
    \ntemplate <typename T>\npair<vector<T>, map<T, int>> compress(vector<T> ord)\
    \ {\n    vector<T> com(ord);\n    map<T, int> rev;\n    sort(com.begin(), com.end());\n\
    \    com.erase(unique(com.begin(), com.end()), com.end());\n    for (int i = 0;\
    \ i < com.size(); ++i) rev[com[i]] = i;\n    vector<T> ret;\n    for (auto& e\
    \ : ord) ret.emplace_back(rev[e]);\n    return make_pair(ret, rev);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: util/compress.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/compress.hpp
layout: document
redirect_from:
- /library/util/compress.hpp
- /library/util/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
## 概要

座標圧縮.

## 計算量

$O(n\log n)$

## 使用例

* `auto [com, rev] = compress(ord)` : `ord`を座標圧縮.
  * `com` : 座標圧縮して得られる配列.
  * `rev` : `ord`と`com`の対応関係.
