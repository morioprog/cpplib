---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/util/randomnumbergenerator.md
    document_title: "\u4E71\u6570\u751F\u6210\u5668"
    links: []
  bundledCode: "#line 1 \"util/randomnumbergenerator.hpp\"\n/**\n* @brief \u4E71\u6570\
    \u751F\u6210\u5668\n* @docs docs/util/randomnumbergenerator.md\n*/\n\nstruct RandomNumberGenerator\
    \ {\n    mt19937 mt;\n    RandomNumberGenerator()\n        : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    int operator()(int a, int b) {  // [a, b)\n        uniform_int_distribution<int>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    int operator()(int b)\
    \ {  // [0, b)\n        return (*this)(0, b);\n    }\n};\n"
  code: "/**\n* @brief \u4E71\u6570\u751F\u6210\u5668\n* @docs docs/util/randomnumbergenerator.md\n\
    */\n\nstruct RandomNumberGenerator {\n    mt19937 mt;\n    RandomNumberGenerator()\n\
    \        : mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n   \
    \ int operator()(int a, int b) {  // [a, b)\n        uniform_int_distribution<int>\
    \ dist(a, b - 1);\n        return dist(mt);\n    }\n    int operator()(int b)\
    \ {  // [0, b)\n        return (*this)(0, b);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/randomnumbergenerator.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/randomnumbergenerator.hpp
layout: document
redirect_from:
- /library/util/randomnumbergenerator.hpp
- /library/util/randomnumbergenerator.hpp.html
title: "\u4E71\u6570\u751F\u6210\u5668"
---
## 概要

乱数生成器.

## 計算量

$O(1)$

## 使用例

* `RandomNumberGenerator rng` : 乱数生成器を準備.
* `rng(b)` : $[0, b)$から乱数生成.
* `rng(a, b)` : $[a, b)$から乱数生成.
