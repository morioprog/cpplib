---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertexaddpathsum.test.cpp
    title: test/yosupo/vertexaddpathsum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertexaddsubtreesum.test.cpp
    title: test/yosupo/vertexaddsubtreesum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/399.test.cpp
    title: test/yukicoder/399.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/hldecomposition.md
    document_title: "HL\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"graph/tree/hldecomposition.hpp\"\n/**\n* @brief HL\u5206\
    \u89E3\n* @docs docs/graph/tree/hldecomposition.md\n*/\n\ntemplate <typename T>\n\
    struct HLDecomposition : Graph<T> {\n    using Graph<T>::Graph;\n    using Graph<T>::mat;\n\
    \    using Graph<T>::V;\n    vector<int> sub, dep, par, head, in, out, rev;\n\
    \    vector<T> dst;\n    void build(const int root = 0) {\n        sub.assign(V,\
    \ 0);\n        dep.assign(V, 0);\n        par.assign(V, 0);\n        head.assign(V,\
    \ 0);\n        in.assign(V, 0);\n        out.assign(V, 0);\n        rev.assign(V,\
    \ 0);\n        dst.assign(V, T(0));\n        dfs_sz(root, -1, 0, T(0));\n    \
    \    int t = 0;\n        dfs_hld(root, -1, t);\n    }\n    int get(int u) const\
    \ { return in[u]; }\n    int lca(int u, int v) const {\n        for (;; v = par[head[v]])\
    \ {\n            // u\u3088\u308A\u3082v\u3092\u5F8C\u306B\u6765\u308B\u3088\u3046\
    \u306B\u3057\u3066, v\u3092\u4E0A\u306B\u62BC\u3057\u4E0A\u3052\u3066\u3044\u304F\
    \n            if (in[u] > in[v]) swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n        }\n    }\n    T dist(int u, int v) const {\n        return\
    \ dst[u] + dst[v] - 2 * dst[lca(u, v)];\n    }\n    pair<int, int> get_subtree(int\
    \ u, bool isEdge = false) const {\n        return make_pair(in[u] + isEdge, out[u]);\n\
    \    }\n    vector<pair<int, int>> get_path(int u, int v, bool isEdge = false)\
    \ {\n        vector<pair<int, int>> ret;\n        for (;; v = par[head[v]]) {\n\
    \            if (in[u] > in[v]) swap(u, v);\n            if (head[u] == head[v])\
    \ break;\n            ret.emplace_back(in[head[v]], in[v] + 1);\n        }\n \
    \       ret.emplace_back(in[u] + isEdge, in[v] + 1);\n        return ret;\n  \
    \  }\n    void dfs_sz(int cur, int prv, int depth, T weight) {\n        sub[cur]\
    \ = 1;\n        dep[cur] = depth;\n        par[cur] = prv;\n        dst[cur] =\
    \ weight;\n        // 0\u756A\u76EE\u3092heavy-path\u306B\u3059\u308B\u305F\u3081\
    \u306E\u6BD4\u8F03\u5BFE\u8C61\u3092\u8A2D\u5B9A\n        if (mat[cur].size()\
    \ && mat[cur][0] == prv)\n            swap(mat[cur][0], mat[cur].back());\n  \
    \      for (auto& nxt : mat[cur]) {\n            if (nxt == prv) continue;\n \
    \           dfs_sz(nxt, cur, depth + 1, weight + nxt.cst);\n            sub[cur]\
    \ += sub[nxt];\n            if (sub[mat[cur][0]] < sub[nxt]) swap(mat[cur][0],\
    \ nxt);\n        }\n    }\n    void dfs_hld(int cur, int prv, int& times) {\n\
    \        in[cur]      = times++;\n        rev[in[cur]] = cur;\n        for (auto&\
    \ nxt : mat[cur]) {\n            if (nxt == prv) continue;\n            // cur-nxt\u304C\
    heavy-path\u4E0A\u306A\u3089head\u306F\u540C\u3058\n            head[nxt] = mat[cur][0]\
    \ == nxt ? head[cur] : nxt;\n            dfs_hld(nxt, cur, times);\n        }\n\
    \        out[cur] = times;\n    }\n};\n"
  code: "/**\n* @brief HL\u5206\u89E3\n* @docs docs/graph/tree/hldecomposition.md\n\
    */\n\ntemplate <typename T>\nstruct HLDecomposition : Graph<T> {\n    using Graph<T>::Graph;\n\
    \    using Graph<T>::mat;\n    using Graph<T>::V;\n    vector<int> sub, dep, par,\
    \ head, in, out, rev;\n    vector<T> dst;\n    void build(const int root = 0)\
    \ {\n        sub.assign(V, 0);\n        dep.assign(V, 0);\n        par.assign(V,\
    \ 0);\n        head.assign(V, 0);\n        in.assign(V, 0);\n        out.assign(V,\
    \ 0);\n        rev.assign(V, 0);\n        dst.assign(V, T(0));\n        dfs_sz(root,\
    \ -1, 0, T(0));\n        int t = 0;\n        dfs_hld(root, -1, t);\n    }\n  \
    \  int get(int u) const { return in[u]; }\n    int lca(int u, int v) const {\n\
    \        for (;; v = par[head[v]]) {\n            // u\u3088\u308A\u3082v\u3092\
    \u5F8C\u306B\u6765\u308B\u3088\u3046\u306B\u3057\u3066, v\u3092\u4E0A\u306B\u62BC\
    \u3057\u4E0A\u3052\u3066\u3044\u304F\n            if (in[u] > in[v]) swap(u, v);\n\
    \            if (head[u] == head[v]) return u;\n        }\n    }\n    T dist(int\
    \ u, int v) const {\n        return dst[u] + dst[v] - 2 * dst[lca(u, v)];\n  \
    \  }\n    pair<int, int> get_subtree(int u, bool isEdge = false) const {\n   \
    \     return make_pair(in[u] + isEdge, out[u]);\n    }\n    vector<pair<int, int>>\
    \ get_path(int u, int v, bool isEdge = false) {\n        vector<pair<int, int>>\
    \ ret;\n        for (;; v = par[head[v]]) {\n            if (in[u] > in[v]) swap(u,\
    \ v);\n            if (head[u] == head[v]) break;\n            ret.emplace_back(in[head[v]],\
    \ in[v] + 1);\n        }\n        ret.emplace_back(in[u] + isEdge, in[v] + 1);\n\
    \        return ret;\n    }\n    void dfs_sz(int cur, int prv, int depth, T weight)\
    \ {\n        sub[cur] = 1;\n        dep[cur] = depth;\n        par[cur] = prv;\n\
    \        dst[cur] = weight;\n        // 0\u756A\u76EE\u3092heavy-path\u306B\u3059\
    \u308B\u305F\u3081\u306E\u6BD4\u8F03\u5BFE\u8C61\u3092\u8A2D\u5B9A\n        if\
    \ (mat[cur].size() && mat[cur][0] == prv)\n            swap(mat[cur][0], mat[cur].back());\n\
    \        for (auto& nxt : mat[cur]) {\n            if (nxt == prv) continue;\n\
    \            dfs_sz(nxt, cur, depth + 1, weight + nxt.cst);\n            sub[cur]\
    \ += sub[nxt];\n            if (sub[mat[cur][0]] < sub[nxt]) swap(mat[cur][0],\
    \ nxt);\n        }\n    }\n    void dfs_hld(int cur, int prv, int& times) {\n\
    \        in[cur]      = times++;\n        rev[in[cur]] = cur;\n        for (auto&\
    \ nxt : mat[cur]) {\n            if (nxt == prv) continue;\n            // cur-nxt\u304C\
    heavy-path\u4E0A\u306A\u3089head\u306F\u540C\u3058\n            head[nxt] = mat[cur][0]\
    \ == nxt ? head[cur] : nxt;\n            dfs_hld(nxt, cur, times);\n        }\n\
    \        out[cur] = times;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/hldecomposition.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/399.test.cpp
  - test/aoj/GRL_5_C.test.cpp
  - test/aoj/GRL_5_E.test.cpp
  - test/aoj/GRL_5_D.test.cpp
  - test/yosupo/vertexaddsubtreesum.test.cpp
  - test/yosupo/vertexaddpathsum.test.cpp
documentation_of: graph/tree/hldecomposition.hpp
layout: document
redirect_from:
- /library/graph/tree/hldecomposition.hpp
- /library/graph/tree/hldecomposition.hpp.html
title: "HL\u5206\u89E3"
---
## 概要

木上のクエリを効率よく捌くための前処理.

## 計算量

* 構築 : $O(N)$
* クエリ : $O(\log N)$

## 変数

頂点$0$を根とした根付き木として計算する.

* `sub`  : 部分木のサイズ
* `dep`  : 深さ (0-origin)
* `dst`  : 根からの距離 (重みが$1$なら`dep`と同じ)
* `par`  : 親の頂点番号
* `head` : 属するheavy-pathの最初の頂点番号
* `in`   : オイラーツアーしたときの左端
* `out`  : オイラーツアーしたときの右端
* `rev`  : `in`の逆写像

## 使用例

* `HLDecomposition<int> hld(V)` : 頂点数$V$のグラフを生成
  * 入力はグラフを参照
* `hld.build(r = 0)` : 頂点$r$を根として構築
* `hld.lca(u, v)` : $u$と$v$の最小共通祖先を取得
* `hld.dist(u, v)`  : パスの距離を取得
* `hld.get_path(u, v)` : $u, v$間のパスに対応する頂点番号ペア群 (半開区間)
  * 辺属性なら第3引数を`true`にする
* `hld.get_subtree(u)` : $u$を根とする部分木の頂点番号ペア (半開区間)
  * 辺属性なら第2引数を`true`にする
