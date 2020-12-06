---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.segmenttree.test.cpp
    title: test/aoj/DSL_2_B.segmenttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pointaddrangesum.test.cpp
    title: test/yosupo/pointaddrangesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertexaddpathsum.test.cpp
    title: test/yosupo/vertexaddpathsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertexaddsubtreesum.test.cpp
    title: test/yosupo/vertexaddsubtreesum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/segmenttree/segmenttree.md
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"datastructure/segmenttree/segmenttree.hpp\"\n/**\n* @brief\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @docs docs/datastructure/segmenttree/segmenttree.md\n\
    */\n\ntemplate <typename T, typename F>\nstruct SegmentTree {\n    int N;\n  \
    \  const int sz;\n    const T ID;\n    const F f;\n    vector<T> cbt;\n    SegmentTree(int\
    \ n, T ID, F func)\n        : sz(n), ID(ID), f(func) { init(sz); }\n    SegmentTree(vector<T>\
    \ V, T ID, F func)\n        : sz(V.size()), ID(ID), f(func) {\n        init(sz);\n\
    \        for (int i = 0; i < sz; ++i)\n            cbt[i + N] = V[i];\n      \
    \  for (int i = N - 1; i >= 1; --i)\n            cbt[i] = f(cbt[i << 1 | 0], cbt[i\
    \ << 1 | 1]);\n    }\n    void init(int n) {\n        N = 1;\n        while (N\
    \ < n) N <<= 1;\n        cbt.assign(N << 1, ID);\n    }\n    void update(int idx,\
    \ T val) {\n        assert(0 <= idx and idx < sz);\n        idx += N;\n      \
    \  cbt[idx] = val;\n        while (idx >>= 1) cbt[idx] = f(cbt[idx << 1 | 0],\
    \ cbt[idx << 1 | 1]);\n    }\n    T query(int l, int r) {\n        assert(0 <=\
    \ l and l <= r and r <= sz);\n        T ret_l = ID, ret_r = ID;\n        l +=\
    \ N, r += N;\n        while (l < r) {\n            if (l & 1) ret_l = f(ret_l,\
    \ cbt[l++]);\n            if (r & 1) ret_r = f(cbt[--r], ret_r);\n           \
    \ l >>= 1, r >>= 1;\n        }\n        return f(ret_l, ret_r);\n    }\n    T\
    \ query_all() { return cbt[1]; }\n    template <typename CF>\n    int rightmost(CF\
    \ check, int l = 0) {\n        assert(0 <= l and l <= sz);\n        assert(check(ID));\n\
    \        if (l == sz) return sz;\n        l += N;\n        T acc = ID;\n     \
    \   do {\n            while (l % 2 == 0) l >>= 1;\n            if (not check(f(acc,\
    \ cbt[l]))) {\n                while (l < N) {\n                    l = 2 * l;\n\
    \                    if (check(f(acc, cbt[l]))) acc = f(acc, cbt[l++]);\n    \
    \            }\n                return l - N;\n            }\n            acc\
    \ = f(acc, cbt[l++]);\n        } while ((l & -l) != l);\n        return sz;\n\
    \    }\n    template <typename CF>\n    int leftmost(CF check, int r = INT_MIN)\
    \ {\n        if (r == INT_MIN) r = sz;\n        assert(0 <= r and r <= sz);\n\
    \        assert(check(ID));\n        if (r == 0) return 0;\n        r += N;\n\
    \        T acc = ID;\n        do {\n            --r;\n            while (r > 1\
    \ and (r % 2)) r >>= 1;\n            if (not check(f(cbt[r], acc))) {\n      \
    \          while (r < N) {\n                    r = 2 * r + 1;\n             \
    \       if (check(f(cbt[r], acc))) acc = f(cbt[r--], acc);\n                }\n\
    \                return r + 1 - N;\n            }\n            acc = f(cbt[r],\
    \ acc);\n        } while ((r & -r) != r);\n        return 0;\n    }\n    T const&\
    \ operator[](int idx) const { return cbt[idx + N]; }\n    void print() {\n   \
    \     for (int i = 1; i < 2 * N; ++i) {\n            cerr << cbt[i] << ' ';\n\
    \            if (!(i & (i + 1))) cerr << endl;\n        }\n    }\n};\n\ntemplate\
    \ <typename T, typename F>\nauto make_segment_tree(int N, T ID, F func) {\n  \
    \  return SegmentTree<T, F>(N, ID, func);\n}\ntemplate <typename T, typename F>\n\
    auto make_segment_tree(vector<T> V, T ID, F func) {\n    return SegmentTree<T,\
    \ F>(V, ID, func);\n}\n"
  code: "/**\n* @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n* @docs docs/datastructure/segmenttree/segmenttree.md\n\
    */\n\ntemplate <typename T, typename F>\nstruct SegmentTree {\n    int N;\n  \
    \  const int sz;\n    const T ID;\n    const F f;\n    vector<T> cbt;\n    SegmentTree(int\
    \ n, T ID, F func)\n        : sz(n), ID(ID), f(func) { init(sz); }\n    SegmentTree(vector<T>\
    \ V, T ID, F func)\n        : sz(V.size()), ID(ID), f(func) {\n        init(sz);\n\
    \        for (int i = 0; i < sz; ++i)\n            cbt[i + N] = V[i];\n      \
    \  for (int i = N - 1; i >= 1; --i)\n            cbt[i] = f(cbt[i << 1 | 0], cbt[i\
    \ << 1 | 1]);\n    }\n    void init(int n) {\n        N = 1;\n        while (N\
    \ < n) N <<= 1;\n        cbt.assign(N << 1, ID);\n    }\n    void update(int idx,\
    \ T val) {\n        assert(0 <= idx and idx < sz);\n        idx += N;\n      \
    \  cbt[idx] = val;\n        while (idx >>= 1) cbt[idx] = f(cbt[idx << 1 | 0],\
    \ cbt[idx << 1 | 1]);\n    }\n    T query(int l, int r) {\n        assert(0 <=\
    \ l and l <= r and r <= sz);\n        T ret_l = ID, ret_r = ID;\n        l +=\
    \ N, r += N;\n        while (l < r) {\n            if (l & 1) ret_l = f(ret_l,\
    \ cbt[l++]);\n            if (r & 1) ret_r = f(cbt[--r], ret_r);\n           \
    \ l >>= 1, r >>= 1;\n        }\n        return f(ret_l, ret_r);\n    }\n    T\
    \ query_all() { return cbt[1]; }\n    template <typename CF>\n    int rightmost(CF\
    \ check, int l = 0) {\n        assert(0 <= l and l <= sz);\n        assert(check(ID));\n\
    \        if (l == sz) return sz;\n        l += N;\n        T acc = ID;\n     \
    \   do {\n            while (l % 2 == 0) l >>= 1;\n            if (not check(f(acc,\
    \ cbt[l]))) {\n                while (l < N) {\n                    l = 2 * l;\n\
    \                    if (check(f(acc, cbt[l]))) acc = f(acc, cbt[l++]);\n    \
    \            }\n                return l - N;\n            }\n            acc\
    \ = f(acc, cbt[l++]);\n        } while ((l & -l) != l);\n        return sz;\n\
    \    }\n    template <typename CF>\n    int leftmost(CF check, int r = INT_MIN)\
    \ {\n        if (r == INT_MIN) r = sz;\n        assert(0 <= r and r <= sz);\n\
    \        assert(check(ID));\n        if (r == 0) return 0;\n        r += N;\n\
    \        T acc = ID;\n        do {\n            --r;\n            while (r > 1\
    \ and (r % 2)) r >>= 1;\n            if (not check(f(cbt[r], acc))) {\n      \
    \          while (r < N) {\n                    r = 2 * r + 1;\n             \
    \       if (check(f(cbt[r], acc))) acc = f(cbt[r--], acc);\n                }\n\
    \                return r + 1 - N;\n            }\n            acc = f(cbt[r],\
    \ acc);\n        } while ((r & -r) != r);\n        return 0;\n    }\n    T const&\
    \ operator[](int idx) const { return cbt[idx + N]; }\n    void print() {\n   \
    \     for (int i = 1; i < 2 * N; ++i) {\n            cerr << cbt[i] << ' ';\n\
    \            if (!(i & (i + 1))) cerr << endl;\n        }\n    }\n};\n\ntemplate\
    \ <typename T, typename F>\nauto make_segment_tree(int N, T ID, F func) {\n  \
    \  return SegmentTree<T, F>(N, ID, func);\n}\ntemplate <typename T, typename F>\n\
    auto make_segment_tree(vector<T> V, T ID, F func) {\n    return SegmentTree<T,\
    \ F>(V, ID, func);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segmenttree/segmenttree.hpp
  requiredBy: []
  timestamp: '2020-09-27 22:42:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertexaddpathsum.test.cpp
  - test/yosupo/vertexaddsubtreesum.test.cpp
  - test/yosupo/pointaddrangesum.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_B.segmenttree.test.cpp
  - test/aoj/GRL_5_D.test.cpp
documentation_of: datastructure/segmenttree/segmenttree.hpp
layout: document
redirect_from:
- /library/datastructure/segmenttree/segmenttree.hpp
- /library/datastructure/segmenttree/segmenttree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## 概要

モノイドに対する 1 点更新区間取得を管理するデータ構造.

### モノイド

以下を満たす代数的構造.

- 結合律 : $f(f(x, y), z) = f(x, f(y, z))$
- 単位元$e$の存在 : $f(x, e) = f(e, x) = x$

## 計算量

- 構築 : $O(n)$
- クエリ : $O(\log n)$

## 使用例

- `auto seg = make_segment_tree(n, [](int a, int b){ return a + b; }, 0)` : 単位元$0$で初期化.
- `auto seg = make_segment_tree(v, [](int a, int b){ return a + b; }, 0)` : `v`で初期化.
- `seg.update(k, x)` : $k$要素目を$x$に変更する.
- `seg.query(l, r)` : 半開区間$[l, r)$のクエリ.
- `seg.query_all()` : 半開区間$[0, sz)$のクエリ.
- `seg.rightmost(check, l = 0)` : 半開区間$[l, sz)$の中で, `check(query(l, r))`が`true`となる最右の$r$を返す.
  - `check(ID)`は`true`である必要がある.
- `seg.leftmost(check, r = sz)` : 半開区間$[0, r)$の中で, `check(query(l, r))`が`true`となる最左の$l$を返す.
  - `check(ID)`は`true`である必要がある.
- `seg.print()` : セグメント木の中身をデバッグ出力.
