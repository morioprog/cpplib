---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/649.test.lrmultiset.cpp
    title: test/yukicoder/649.test.lrmultiset.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/lr/lrmultiset.md
    document_title: LR MultiSet
    links: []
  bundledCode: "#line 1 \"datastructure/lr/lrmultiset.hpp\"\n/**\n* @brief LR MultiSet\n\
    * @docs docs/datastructure/lr/lrmultiset.md\n*/\n\ntemplate <typename T>\nstruct\
    \ LRMultiSet {\n    using F = function<int(int)>;\n    const F f;\n    const T\
    \ err;\n    multiset<T> L, R;\n    int L_sz, R_sz;\n    T L_sum, R_sum;\n    //\
    \ f(sz) -> size of L\n    // e.g.) median : [](int sz) -> int { return (sz + 1)\
    \ / 2; }\n    LRMultiSet(F f, T err = numeric_limits<T>::max())\n        : f(f),\
    \ err(err), L_sz(0), R_sz(0), L_sum(0), R_sum(0) {}\n    void L_push(T x) {\n\
    \        ++L_sz;\n        L_sum += x;\n        L.emplace(x);\n    }\n    void\
    \ R_push(T x) {\n        ++R_sz;\n        R_sum += x;\n        R.emplace(x);\n\
    \    }\n    T L_pop() {\n        T ret = L_get_max();\n        L.erase(prev(L.end()));\n\
    \        --L_sz;\n        L_sum -= ret;\n        return ret;\n    }\n    T R_pop()\
    \ {\n        T ret = R_get_min();\n        R.erase(R.begin());\n        --R_sz;\n\
    \        R_sum -= ret;\n        return ret;\n    }\n    T L_get_min() {\n    \
    \    if (L.empty()) return err;\n        return *L.begin();\n    }\n    T L_get_max()\
    \ {\n        if (L.empty()) return err;\n        return *prev(L.end());\n    }\n\
    \    T R_get_min() {\n        if (R.empty()) return err;\n        return *R.begin();\n\
    \    }\n    T R_get_max() {\n        if (R.empty()) return err;\n        return\
    \ *prev(R.end());\n    }\n    void erase(T x) {\n        auto itr_l = L.find(x);\n\
    \        if (itr_l != L.end()) {\n            --L_sz;\n            L_sum -= x;\n\
    \            L.erase(itr_l);\n            return;\n        }\n        auto itr_r\
    \ = R.find(x);\n        if (itr_r != R.end()) {\n            --R_sz;\n       \
    \     R_sum -= x;\n            R.erase(itr_r);\n            return;\n        }\n\
    \        assert(false);\n    }\n    void emplace(T x) {\n        if (R.empty()\
    \ or R_get_min() > x)\n            L_push(x);\n        else\n            R_push(x);\n\
    \    }\n    void flatten() {\n        int gL_sz = f(L_sz + R_sz);\n        while\
    \ (L.size() < gL_sz) {\n            T tp = R_pop();\n            L_push(tp);\n\
    \        }\n        while (L.size() > gL_sz) {\n            T tp = L_pop();\n\
    \            R_push(tp);\n        }\n    }\n    T get() {\n        int gL_sz =\
    \ f(L_sz + R_sz);\n        if (gL_sz > L_sz + R_sz) return err;\n        flatten();\n\
    \        return L_get_max();\n    }\n};\n"
  code: "/**\n* @brief LR MultiSet\n* @docs docs/datastructure/lr/lrmultiset.md\n\
    */\n\ntemplate <typename T>\nstruct LRMultiSet {\n    using F = function<int(int)>;\n\
    \    const F f;\n    const T err;\n    multiset<T> L, R;\n    int L_sz, R_sz;\n\
    \    T L_sum, R_sum;\n    // f(sz) -> size of L\n    // e.g.) median : [](int\
    \ sz) -> int { return (sz + 1) / 2; }\n    LRMultiSet(F f, T err = numeric_limits<T>::max())\n\
    \        : f(f), err(err), L_sz(0), R_sz(0), L_sum(0), R_sum(0) {}\n    void L_push(T\
    \ x) {\n        ++L_sz;\n        L_sum += x;\n        L.emplace(x);\n    }\n \
    \   void R_push(T x) {\n        ++R_sz;\n        R_sum += x;\n        R.emplace(x);\n\
    \    }\n    T L_pop() {\n        T ret = L_get_max();\n        L.erase(prev(L.end()));\n\
    \        --L_sz;\n        L_sum -= ret;\n        return ret;\n    }\n    T R_pop()\
    \ {\n        T ret = R_get_min();\n        R.erase(R.begin());\n        --R_sz;\n\
    \        R_sum -= ret;\n        return ret;\n    }\n    T L_get_min() {\n    \
    \    if (L.empty()) return err;\n        return *L.begin();\n    }\n    T L_get_max()\
    \ {\n        if (L.empty()) return err;\n        return *prev(L.end());\n    }\n\
    \    T R_get_min() {\n        if (R.empty()) return err;\n        return *R.begin();\n\
    \    }\n    T R_get_max() {\n        if (R.empty()) return err;\n        return\
    \ *prev(R.end());\n    }\n    void erase(T x) {\n        auto itr_l = L.find(x);\n\
    \        if (itr_l != L.end()) {\n            --L_sz;\n            L_sum -= x;\n\
    \            L.erase(itr_l);\n            return;\n        }\n        auto itr_r\
    \ = R.find(x);\n        if (itr_r != R.end()) {\n            --R_sz;\n       \
    \     R_sum -= x;\n            R.erase(itr_r);\n            return;\n        }\n\
    \        assert(false);\n    }\n    void emplace(T x) {\n        if (R.empty()\
    \ or R_get_min() > x)\n            L_push(x);\n        else\n            R_push(x);\n\
    \    }\n    void flatten() {\n        int gL_sz = f(L_sz + R_sz);\n        while\
    \ (L.size() < gL_sz) {\n            T tp = R_pop();\n            L_push(tp);\n\
    \        }\n        while (L.size() > gL_sz) {\n            T tp = L_pop();\n\
    \            R_push(tp);\n        }\n    }\n    T get() {\n        int gL_sz =\
    \ f(L_sz + R_sz);\n        if (gL_sz > L_sz + R_sz) return err;\n        flatten();\n\
    \        return L_get_max();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/lr/lrmultiset.hpp
  requiredBy: []
  timestamp: '2020-08-29 18:58:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/649.test.lrmultiset.cpp
documentation_of: datastructure/lr/lrmultiset.hpp
layout: document
redirect_from:
- /library/datastructure/lr/lrmultiset.hpp
- /library/datastructure/lr/lrmultiset.hpp.html
title: LR MultiSet
---
## 概要

$k$番目の値を高速に取り出せるデータ構造. 削除を行えるが定数倍が少し重い.

## 計算量

- 追加 : $O(\log n)$
- 削除 : $O(\log n)$
- 取得 : $O(\log n)$
  - $k$が固定, 中央値
  - $f$次第ではオーダーが壊れる

## 使用例

- `LRMultiSet<ll> lr([](int sz) -> int { return (sz + 1) / 2; })` : 中央値を管理する.
- `LRMultiSet<ll> lr([](int sz) -> int { return 3; })` : 下から$3$番目の数を管理する.
- `lr.emplace(x)` : $x$を挿入.
- `lr.erase(x)` : $x$を削除.
- `lr.get()` : $f(sz)$番目の数を取得.
