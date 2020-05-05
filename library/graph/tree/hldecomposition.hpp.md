---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :question: HL分解 <small>(graph/tree/hldecomposition.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#28790b6202284cbbffc9d712b59f4b80">graph/tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/tree/hldecomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 16:33:08+09:00




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


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_E.test.cpp.html">test/aoj/GRL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/vertexaddpathsum.test.cpp.html">test/yosupo/vertexaddpathsum.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/vertexaddsubtreesum.test.cpp.html">test/yosupo/vertexaddsubtreesum.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/399.test.cpp.html">test/yukicoder/399.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief HL分解
* @docs docs/graph/tree/hldecomposition.md
*/

template<typename T>
struct HLDecomposition : Graph<T> {
    using Graph<T>::Graph;
    using Graph<T>::mat;
    using Graph<T>::V;
    vector<int> sub, dep, par, head, in, out, rev;
    vector<T> dst;
    void build(const int root = 0) {
        sub.assign(V, 0);
        dep.assign(V, 0);
        par.assign(V, 0);
        head.assign(V, 0);
        in.assign(V, 0);
        out.assign(V, 0);
        rev.assign(V, 0);
        dst.assign(V, T(0));
        dfs_sz(root, -1, 0, T(0));
        int t = 0;
        dfs_hld(root, -1, t);
    }
    int get(int u) const { return in[u]; }
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            // uよりもvを後に来るようにして, vを上に押し上げていく
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }
    T dist(int u, int v) const {
        return dst[u] + dst[v] - 2 * dst[lca(u, v)];
    }
    pair<int, int> get_subtree(int u, bool isEdge = false) const {
        return make_pair(in[u] + isEdge, out[u]);
    }
    vector<pair<int, int>> get_path(int u, int v, bool isEdge = false) {
        vector<pair<int, int>> ret;
        for(;; v = par[head[v]]) {
			if (in[u] > in[v]) swap(u, v);
			if (head[u] == head[v]) break;
			ret.emplace_back(in[head[v]], in[v] + 1);
		}
		ret.emplace_back(in[u] + isEdge, in[v] + 1);
		return ret;
    }
    void dfs_sz(int cur, int prv, int depth, T weight) {
        sub[cur] = 1;
        dep[cur] = depth;
        par[cur] = prv;
        dst[cur] = weight;
        // 0番目をheavy-pathにするための比較対象を設定
        if (mat[cur].size() && mat[cur][0] == prv)
            swap(mat[cur][0], mat[cur].back());
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            dfs_sz(nxt, cur, depth + 1, weight + nxt.cst);
            sub[cur] += sub[nxt];
            if (sub[mat[cur][0]] < sub[nxt]) swap(mat[cur][0], nxt);
        }
    }
    void dfs_hld(int cur, int prv, int& times) {
        in[cur] = times++;
        rev[in[cur]] = cur;
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            // cur-nxtがheavy-path上ならheadは同じ
            head[nxt] = mat[cur][0] == nxt ? head[cur] : nxt;
            dfs_hld(nxt, cur, times);
        }
        out[cur] = times;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/tree/hldecomposition.hpp"
/**
* @brief HL分解
* @docs docs/graph/tree/hldecomposition.md
*/

template<typename T>
struct HLDecomposition : Graph<T> {
    using Graph<T>::Graph;
    using Graph<T>::mat;
    using Graph<T>::V;
    vector<int> sub, dep, par, head, in, out, rev;
    vector<T> dst;
    void build(const int root = 0) {
        sub.assign(V, 0);
        dep.assign(V, 0);
        par.assign(V, 0);
        head.assign(V, 0);
        in.assign(V, 0);
        out.assign(V, 0);
        rev.assign(V, 0);
        dst.assign(V, T(0));
        dfs_sz(root, -1, 0, T(0));
        int t = 0;
        dfs_hld(root, -1, t);
    }
    int get(int u) const { return in[u]; }
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            // uよりもvを後に来るようにして, vを上に押し上げていく
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }
    T dist(int u, int v) const {
        return dst[u] + dst[v] - 2 * dst[lca(u, v)];
    }
    pair<int, int> get_subtree(int u, bool isEdge = false) const {
        return make_pair(in[u] + isEdge, out[u]);
    }
    vector<pair<int, int>> get_path(int u, int v, bool isEdge = false) {
        vector<pair<int, int>> ret;
        for(;; v = par[head[v]]) {
			if (in[u] > in[v]) swap(u, v);
			if (head[u] == head[v]) break;
			ret.emplace_back(in[head[v]], in[v] + 1);
		}
		ret.emplace_back(in[u] + isEdge, in[v] + 1);
		return ret;
    }
    void dfs_sz(int cur, int prv, int depth, T weight) {
        sub[cur] = 1;
        dep[cur] = depth;
        par[cur] = prv;
        dst[cur] = weight;
        // 0番目をheavy-pathにするための比較対象を設定
        if (mat[cur].size() && mat[cur][0] == prv)
            swap(mat[cur][0], mat[cur].back());
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            dfs_sz(nxt, cur, depth + 1, weight + nxt.cst);
            sub[cur] += sub[nxt];
            if (sub[mat[cur][0]] < sub[nxt]) swap(mat[cur][0], nxt);
        }
    }
    void dfs_hld(int cur, int prv, int& times) {
        in[cur] = times++;
        rev[in[cur]] = cur;
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            // cur-nxtがheavy-path上ならheadは同じ
            head[nxt] = mat[cur][0] == nxt ? head[cur] : nxt;
            dfs_hld(nxt, cur, times);
        }
        out[cur] = times;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

