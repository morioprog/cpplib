---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/649.test.lrprique.cpp
    title: test/yukicoder/649.test.lrprique.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/lr/lrprique.md
    document_title: LR Priority Queue
    links: []
  bundledCode: "#line 1 \"datastructure/lr/lrprique.hpp\"\n/**\n* @brief LR Priority\
    \ Queue\n* @docs docs/datastructure/lr/lrprique.md\n*/\n\ntemplate <typename T>\n\
    struct LRPrique {\n    using F = function<int(int)>;\n    const F f;\n    const\
    \ T err;\n    priority_queue<T> L;\n    priority_queue<T, vector<T>, greater<>>\
    \ R;\n    int L_sz, R_sz;\n    T L_sum, R_sum;\n    // f(sz) -> size of L\n  \
    \  // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }\n    LRPrique(F\
    \ f, T err = numeric_limits<T>::max())\n        : f(f), err(err), L_sz(0), R_sz(0),\
    \ L_sum(0), R_sum(0) {}\n    void L_push(T x) {\n        ++L_sz;\n        L_sum\
    \ += x;\n        L.emplace(x);\n    }\n    void R_push(T x) {\n        ++R_sz;\n\
    \        R_sum += x;\n        R.emplace(x);\n    }\n    T L_pop() {\n        T\
    \ ret = L.top();\n        L.pop();\n        --L_sz;\n        L_sum -= ret;\n \
    \       return ret;\n    }\n    T R_pop() {\n        T ret = R.top();\n      \
    \  R.pop();\n        --R_sz;\n        R_sum -= ret;\n        return ret;\n   \
    \ }\n    void emplace(T x) {\n        if (R.empty() or R.top() > x)\n        \
    \    L_push(x);\n        else\n            R_push(x);\n    }\n    void flatten()\
    \ {\n        int gL_sz = f(L_sz + R_sz);\n        while (L.size() < gL_sz) {\n\
    \            T tp = R_pop();\n            L_push(tp);\n        }\n        while\
    \ (L.size() > gL_sz) {\n            T tp = L_pop();\n            R_push(tp);\n\
    \        }\n    }\n    T get() {\n        int gL_sz = f(L_sz + R_sz);\n      \
    \  if (gL_sz > L_sz + R_sz) return err;\n        flatten();\n        return L.top();\n\
    \    }\n};\n"
  code: "/**\n* @brief LR Priority Queue\n* @docs docs/datastructure/lr/lrprique.md\n\
    */\n\ntemplate <typename T>\nstruct LRPrique {\n    using F = function<int(int)>;\n\
    \    const F f;\n    const T err;\n    priority_queue<T> L;\n    priority_queue<T,\
    \ vector<T>, greater<>> R;\n    int L_sz, R_sz;\n    T L_sum, R_sum;\n    // f(sz)\
    \ -> size of L\n    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2;\
    \ }\n    LRPrique(F f, T err = numeric_limits<T>::max())\n        : f(f), err(err),\
    \ L_sz(0), R_sz(0), L_sum(0), R_sum(0) {}\n    void L_push(T x) {\n        ++L_sz;\n\
    \        L_sum += x;\n        L.emplace(x);\n    }\n    void R_push(T x) {\n \
    \       ++R_sz;\n        R_sum += x;\n        R.emplace(x);\n    }\n    T L_pop()\
    \ {\n        T ret = L.top();\n        L.pop();\n        --L_sz;\n        L_sum\
    \ -= ret;\n        return ret;\n    }\n    T R_pop() {\n        T ret = R.top();\n\
    \        R.pop();\n        --R_sz;\n        R_sum -= ret;\n        return ret;\n\
    \    }\n    void emplace(T x) {\n        if (R.empty() or R.top() > x)\n     \
    \       L_push(x);\n        else\n            R_push(x);\n    }\n    void flatten()\
    \ {\n        int gL_sz = f(L_sz + R_sz);\n        while (L.size() < gL_sz) {\n\
    \            T tp = R_pop();\n            L_push(tp);\n        }\n        while\
    \ (L.size() > gL_sz) {\n            T tp = L_pop();\n            R_push(tp);\n\
    \        }\n    }\n    T get() {\n        int gL_sz = f(L_sz + R_sz);\n      \
    \  if (gL_sz > L_sz + R_sz) return err;\n        flatten();\n        return L.top();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/lr/lrprique.hpp
  requiredBy: []
  timestamp: '2020-08-29 18:58:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/649.test.lrprique.cpp
documentation_of: datastructure/lr/lrprique.hpp
layout: document
redirect_from:
- /library/datastructure/lr/lrprique.hpp
- /library/datastructure/lr/lrprique.hpp.html
title: LR Priority Queue
---
## 概要

$k$番目の値を高速に取り出せるデータ構造.

## 計算量

- 追加 : $O(\log n)$
- 取得 : $O(\log n)$
  - $f$次第ではオーダーが壊れる
    - 「$k$が固定」や「中央値」は大丈夫

## 使用例

- `LRPrique<ll> lr([](int sz) -> int { return (sz + 1) / 2; })` : 中央値を管理する.
- `LRPrique<ll> lr([](int sz) -> int { return 3; })` : 下から$3$番目の数を管理する.
- `lr.emplace(x)` : $x$を挿入.
- `lr.get()` : $f(sz)$番目の数を取得.
