---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/yosupo/rangeaffinerangesum.test.cpp
    title: test/yosupo/rangeaffinerangesum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/399.test.cpp
    title: test/yukicoder/399.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/datastructure/segmenttree/lazysegmenttree.md
    document_title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"datastructure/segmenttree/lazysegmenttree.hpp\"\n/**\n*\
    \ @brief \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @docs docs/datastructure/segmenttree/lazysegmenttree.md\n\
    */\n\ntemplate <typename M, typename OM, typename F, typename G, typename H, typename\
    \ P>\nstruct LazySegmentTree {\n    int sz;\n    const M ID_M;\n    const OM ID_OM;\n\
    \    F f;\n    G g;\n    H h;\n    P p;\n    vector<M> dat;\n    vector<OM> laz;\n\
    \    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)\n        : ID_M(ID_M),\
    \ ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }\n    LazySegmentTree(const\
    \ vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)\n        : ID_M(ID_M), ID_OM(ID_OM),\
    \ f(f), g(g), h(h), p(p) {\n        int n = v.size();\n        build(n);\n   \
    \     for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];\n        for (int i\
    \ = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);\n    }\n\
    \    void build(int n) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n\
    \        dat.assign(2 * sz - 1, ID_M);\n        laz.assign(2 * sz - 1, ID_OM);\n\
    \    }\n    void eval(int len, int k) {\n        if (laz[k] == ID_OM) return;\n\
    \        if (2 * k + 1 < 2 * sz - 1) {\n            laz[2 * k + 1] = h(laz[2 *\
    \ k + 1], laz[k]);\n            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);\n\
    \        }\n        dat[k] = g(dat[k], p(laz[k], len));\n        laz[k] = ID_OM;\n\
    \    }\n    M update(int a, int b, OM x, int k, int l, int r) {\n        eval(r\
    \ - l, k);\n        if (r <= a or b <= l) return dat[k];\n        if (a <= l and\
    \ r <= b) {\n            laz[k] = h(laz[k], x);\n            return g(dat[k],\
    \ p(laz[k], r - l));\n        }\n        return dat[k] = f(update(a, b, x, 2 *\
    \ k + 1, l, (l + r) / 2),\n                          update(a, b, x, 2 * k + 2,\
    \ (l + r) / 2, r));\n    }\n    M update(int a, int b, OM x) {\n        return\
    \ update(a, b, x, 0, 0, sz);\n    }\n    M query(int a, int b, int k, int l, int\
    \ r) {\n        eval(r - l, k);\n        if (r <= a or b <= l) return ID_M;\n\
    \        if (a <= l and r <= b) return dat[k];\n        M vl = query(a, b, 2 *\
    \ k + 1, l, (l + r) / 2);\n        M vr = query(a, b, 2 * k + 2, (l + r) / 2,\
    \ r);\n        return f(vl, vr);\n    }\n    M query(int a, int b) {\n       \
    \ return query(a, b, 0, 0, sz);\n    }\n    M operator[](const int &k) {\n   \
    \     return query(k, k + 1);\n    }\n    void print() {\n        for (int i =\
    \ 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';\n        cerr << endl;\n   \
    \ }\n};\n\ntemplate <typename M, typename OM, typename F, typename G, typename\
    \ H, typename P>\nauto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P\
    \ p) {\n    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h,\
    \ p);\n}\ntemplate <typename M, typename OM, typename F, typename G, typename\
    \ H, typename P>\nauto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H\
    \ h, P p) {\n    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f,\
    \ g, h, p);\n}\n"
  code: "/**\n* @brief \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @docs docs/datastructure/segmenttree/lazysegmenttree.md\n\
    */\n\ntemplate <typename M, typename OM, typename F, typename G, typename H, typename\
    \ P>\nstruct LazySegmentTree {\n    int sz;\n    const M ID_M;\n    const OM ID_OM;\n\
    \    F f;\n    G g;\n    H h;\n    P p;\n    vector<M> dat;\n    vector<OM> laz;\n\
    \    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)\n        : ID_M(ID_M),\
    \ ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }\n    LazySegmentTree(const\
    \ vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)\n        : ID_M(ID_M), ID_OM(ID_OM),\
    \ f(f), g(g), h(h), p(p) {\n        int n = v.size();\n        build(n);\n   \
    \     for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];\n        for (int i\
    \ = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);\n    }\n\
    \    void build(int n) {\n        sz = 1;\n        while (sz < n) sz <<= 1;\n\
    \        dat.assign(2 * sz - 1, ID_M);\n        laz.assign(2 * sz - 1, ID_OM);\n\
    \    }\n    void eval(int len, int k) {\n        if (laz[k] == ID_OM) return;\n\
    \        if (2 * k + 1 < 2 * sz - 1) {\n            laz[2 * k + 1] = h(laz[2 *\
    \ k + 1], laz[k]);\n            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);\n\
    \        }\n        dat[k] = g(dat[k], p(laz[k], len));\n        laz[k] = ID_OM;\n\
    \    }\n    M update(int a, int b, OM x, int k, int l, int r) {\n        eval(r\
    \ - l, k);\n        if (r <= a or b <= l) return dat[k];\n        if (a <= l and\
    \ r <= b) {\n            laz[k] = h(laz[k], x);\n            return g(dat[k],\
    \ p(laz[k], r - l));\n        }\n        return dat[k] = f(update(a, b, x, 2 *\
    \ k + 1, l, (l + r) / 2),\n                          update(a, b, x, 2 * k + 2,\
    \ (l + r) / 2, r));\n    }\n    M update(int a, int b, OM x) {\n        return\
    \ update(a, b, x, 0, 0, sz);\n    }\n    M query(int a, int b, int k, int l, int\
    \ r) {\n        eval(r - l, k);\n        if (r <= a or b <= l) return ID_M;\n\
    \        if (a <= l and r <= b) return dat[k];\n        M vl = query(a, b, 2 *\
    \ k + 1, l, (l + r) / 2);\n        M vr = query(a, b, 2 * k + 2, (l + r) / 2,\
    \ r);\n        return f(vl, vr);\n    }\n    M query(int a, int b) {\n       \
    \ return query(a, b, 0, 0, sz);\n    }\n    M operator[](const int &k) {\n   \
    \     return query(k, k + 1);\n    }\n    void print() {\n        for (int i =\
    \ 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';\n        cerr << endl;\n   \
    \ }\n};\n\ntemplate <typename M, typename OM, typename F, typename G, typename\
    \ H, typename P>\nauto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P\
    \ p) {\n    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h,\
    \ p);\n}\ntemplate <typename M, typename OM, typename F, typename G, typename\
    \ H, typename P>\nauto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H\
    \ h, P p) {\n    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f,\
    \ g, h, p);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segmenttree/lazysegmenttree.hpp
  requiredBy: []
  timestamp: '2020-09-27 22:42:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/399.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/GRL_5_E.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/yosupo/rangeaffinerangesum.test.cpp
documentation_of: datastructure/segmenttree/lazysegmenttree.hpp
layout: document
redirect_from:
- /library/datastructure/segmenttree/lazysegmenttree.hpp
- /library/datastructure/segmenttree/lazysegmenttree.hpp.html
title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## 概要

モノイドに対する区間更新区間取得を管理するデータ構造.

以下の3つの条件を満たすときに使える.

1. $g(f(a, b), c) = f(g(a, c), g(b, c))$
    * もしくは, $g(f(a, b), p(c, d)) = f(g(a, p(c, d / 2)), g(b, p(c, d / 2)))$
1. $g(g(a, b), c) = g(a, h(b, c))$
1. $g(a, id_{om}) = a$

## 計算量

* 構築 : $O(n)$
* クエリ : $O(\log n)$

## 使用例

* `auto seg = make_segtree(n, id_m, id_om, f, g, h, p)` : $n$要素の遅延セグメント木.
* `auto seg = make_segtree(v, id_m, id_om, f, g, h, p)` : $v$で初期化された遅延セグメント木.
* `seg.update(l, r, x)` : 半開区間$[l, r)$の更新クエリ.
* `seg.query(l, r)` : 半開区間$[l, r)$の取得クエリ.
* `seg[k]` : 半開区間$[k, k + 1)$の取得クエリ.
* `seg.print()` : 各要素の値をデバッグ出力.

### 引数について

* `id_m` : 要素の単位元.
* `id_om` : 作用素の単位元.
* `f` : 要素と要素をマージする関数.
* `g` : 要素と作用素をマージする関数.
* `h` : 作用素と作用素をマージする関数.
* `p` : $p(x, n) = g(x, x, \ldots, x) [xがn個]$なる$p$.

## 典型

パラメータを適宜変更すること.

* 区間更新の際の作用素の単位元`ID_OM`

### 区間加算・区間和

```cpp
using lint = long long;
using M = lint;
auto f = [](M a, M b) -> M { return a + b; };
auto p = [](M a, int b) -> M { return a * b; };
auto seg = make_segtree(N, M(0), M(0), f, f, f, p);
```

### 区間加算・区間最小

```cpp
using lint = long long;
using M = lint;
auto f = [](M a, M b) -> M { return min(a, b); };
auto g = [](M a, M b) -> M { return a + b; };
auto p = [](M a, int b) -> M { return a; };
auto seg = make_segtree(N, M(4e18), M(0), f, g, g, p);
```

### 区間更新・区間和

```cpp
using lint = long long;
using M = lint;
const M ID_OM(4e18);
auto f = [](M a, M b) -> M { return a + b; };
auto g = [](M a, M b) -> M { return b == ID_OM ? a : b; };
auto p = [](M a, int b) -> M { return a * b; };
auto seg = make_segtree(N, M(0), ID_OM, f, g, g, p);
```

### 区間更新・区間最小

```cpp
using lint = long long;
using M = lint;
const M ID_OM(4e18);
auto f = [](M a, M b) -> M { return min(a, b); };
auto g = [](M a, M b) -> M { return b == ID_OM ? a : b; };
auto p = [](M a, int b) -> M { return a; };
auto seg = make_segtree(N, M(4e18), ID_OM, f, g, g, p);
```
