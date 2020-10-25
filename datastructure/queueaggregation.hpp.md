---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/queueaggregation.md
    document_title: Queue Aggregation
    links: []
  bundledCode: "#line 1 \"datastructure/queueaggregation.hpp\"\n/**\n* @brief Queue\
    \ Aggregation\n* @docs docs/datastructure/queueaggregation.md\n*/\n\ntemplate\
    \ <typename T>\nstruct QueueAggregation {\n    using F = function<T(T, T)>;\n\
    \    stack<pair<T, T>> st_f, st_b;  // {val, sum}\n    const F func;\n    const\
    \ T IDENT;\n    QueueAggregation(const F f, const T IDENT)\n        : func(f),\
    \ IDENT(IDENT) {\n        st_f.emplace(IDENT, IDENT);\n        st_b.emplace(IDENT,\
    \ IDENT);\n    }\n    // remove sentinel\n    int size() const { return (int)st_f.size()\
    \ + (int)st_b.size() - 2; }\n    bool empty() const { return size() == 0; }\n\
    \    T query() {\n        return func(st_f.top().second, st_b.top().second);\n\
    \    }\n    void emplace(const T &x) {\n        T merged = func(st_b.top().second,\
    \ x);\n        st_b.emplace(x, merged);\n    }\n    void pop() {\n        assert(not\
    \ empty());\n        if (st_f.size() == 1) {  // <=> st_f.empty()\n          \
    \  st_f.emplace(st_b.top().first, st_b.top().first);\n            st_b.pop();\n\
    \            while (st_b.size() != 1) {\n                T merged = func(st_b.top().first,\
    \ st_f.top().second);\n                st_f.emplace(st_b.top().first, merged);\n\
    \                st_b.pop();\n            }\n        }\n        st_f.pop();\n\
    \    }\n};\n"
  code: "/**\n* @brief Queue Aggregation\n* @docs docs/datastructure/queueaggregation.md\n\
    */\n\ntemplate <typename T>\nstruct QueueAggregation {\n    using F = function<T(T,\
    \ T)>;\n    stack<pair<T, T>> st_f, st_b;  // {val, sum}\n    const F func;\n\
    \    const T IDENT;\n    QueueAggregation(const F f, const T IDENT)\n        :\
    \ func(f), IDENT(IDENT) {\n        st_f.emplace(IDENT, IDENT);\n        st_b.emplace(IDENT,\
    \ IDENT);\n    }\n    // remove sentinel\n    int size() const { return (int)st_f.size()\
    \ + (int)st_b.size() - 2; }\n    bool empty() const { return size() == 0; }\n\
    \    T query() {\n        return func(st_f.top().second, st_b.top().second);\n\
    \    }\n    void emplace(const T &x) {\n        T merged = func(st_b.top().second,\
    \ x);\n        st_b.emplace(x, merged);\n    }\n    void pop() {\n        assert(not\
    \ empty());\n        if (st_f.size() == 1) {  // <=> st_f.empty()\n          \
    \  st_f.emplace(st_b.top().first, st_b.top().first);\n            st_b.pop();\n\
    \            while (st_b.size() != 1) {\n                T merged = func(st_b.top().first,\
    \ st_f.top().second);\n                st_f.emplace(st_b.top().first, merged);\n\
    \                st_b.pop();\n            }\n        }\n        st_f.pop();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/queueaggregation.hpp
  requiredBy: []
  timestamp: '2020-08-29 20:31:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1036.test.cpp
documentation_of: datastructure/queueaggregation.hpp
layout: document
redirect_from:
- /library/datastructure/queueaggregation.hpp
- /library/datastructure/queueaggregation.hpp.html
title: Queue Aggregation
---
## 概要

全体を二項演算$f$で畳み込んだものを$O(1)$で答えられるキュー.

渡す$f$は結合律を満たす必要がある.

- 結合律 : $f(f(x, y), z) = f(x, f(y, z))$

## 計算量

$O(1)$

## 使用例

- `QueueAggregation<int> swag([](int a, int b){ return min(a, b); })` : 最小クエリを処理する SWAG.
- `swag.emplace(x)` : $x$を追加.
- `swag.pop()` : `swag`から`pop`.
- `swag.query()` : 全体を$f$で畳んだ結果.
