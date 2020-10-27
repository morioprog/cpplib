---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1183.test.cpp
    title: test/yukicoder/1183.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/203.test.cpp
    title: test/yukicoder/203.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/util/groupby.md
    document_title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (groupby)"
    links: []
  bundledCode: "#line 1 \"util/groupby.hpp\"\n/**\n* @brief \u30E9\u30F3\u30EC\u30F3\
    \u30B0\u30B9\u5727\u7E2E (groupby)\n* @docs docs/util/groupby.md\n*/\n\ntemplate\
    \ <typename Container>\nauto groupby(const Container &vec) {\n    assert(vec.size()\
    \ != 0);\n    vector<pair<remove_const_t<remove_reference_t<decltype(vec.front())>>,\
    \ int>> ret;\n    int piv = -1;\n    for (auto &e : vec) {\n        if (piv ==\
    \ -1 or ret[piv].first != e)\n            ++piv, ret.emplace_back(make_pair(e,\
    \ 1));\n        else\n            ++(ret[piv].second);\n    }\n    return ret;\n\
    }\n"
  code: "/**\n* @brief \u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (groupby)\n\
    * @docs docs/util/groupby.md\n*/\n\ntemplate <typename Container>\nauto groupby(const\
    \ Container &vec) {\n    assert(vec.size() != 0);\n    vector<pair<remove_const_t<remove_reference_t<decltype(vec.front())>>,\
    \ int>> ret;\n    int piv = -1;\n    for (auto &e : vec) {\n        if (piv ==\
    \ -1 or ret[piv].first != e)\n            ++piv, ret.emplace_back(make_pair(e,\
    \ 1));\n        else\n            ++(ret[piv].second);\n    }\n    return ret;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: util/groupby.hpp
  requiredBy: []
  timestamp: '2020-08-24 19:38:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/203.test.cpp
  - test/yukicoder/1183.test.cpp
documentation_of: util/groupby.hpp
layout: document
redirect_from:
- /library/util/groupby.hpp
- /library/util/groupby.hpp.html
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (groupby)"
---
## 概要

ランレングス圧縮. 命名はPythonに準拠.

### 注意

* **C++14以降**で動く.
* `vector<bool>`だと内部の参照を外さないと動かない？

## 使用例

* `groupby(v)` : コンテナ`v`をランレングス圧縮.
  * 返り値の型 : `vector<pair<T, int>>`
    * `T` : `v`の要素.
    * `int` : その要素が何個続いているか.
