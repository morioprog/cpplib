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


# :heavy_check_mark: 重み付きUnionFind <small>(datastructure/unionfind/weightedunionfind.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#30b7082b479ad4b7861d398d23468641">datastructure/unionfind</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/unionfind/weightedunionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00


* see: <a href="https://qiita.com/drken/items/cce6fc5c579051e64fab">https://qiita.com/drken/items/cce6fc5c579051e64fab</a>


## 概要

連結成分と**ノード間の距離**を管理するデータ構造.

## 計算量

$O(\alpha (n))$

## 使用例

* `WeightedUnionFind uf(V)` : $V$頂点の重み付きUnionFindを定義.
* `uf.unite(x, y, w)` : $x$と$y$を連結にする.
  * このとき, $\mathrm{weight}(y) = \mathrm{weight}(x) + w$となるようにする.
* `uf.same(x, y)` : $x$と$y$が連結かを返す.
* `uf.size(x)` : $x$の属する連結成分の大きさを返す.
* `uf.size()` : 連結成分の個数を返す.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1330.test.cpp.html">test/aoj/1330.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/unionfind.weightedunionfind.test.cpp.html">test/yosupo/unionfind.weightedunionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 重み付きUnionFind
* @docs docs/datastructure/unionfind/weightedunionfind.md
* @see https://qiita.com/drken/items/cce6fc5c579051e64fab
*/

template <typename T>
struct WeightedUnionFind {
    int sz;
    vector<int> parent;
    vector<T> diff_weight;
    WeightedUnionFind(int sz)
        : sz(sz), parent(sz, -1), diff_weight(sz, T(0)) {}
    // weight(y) = weight(x) + w
    bool unite(int x, int y, T w) {
        w += weight(x) - weight(y);
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y), w = -w;
            --sz;
            parent[x] += parent[y];
            parent[y]      = x;
            diff_weight[y] = w;
        }
        return true;
    }
    int find(int x) {
        if (parent[x] < 0) return x;
        int ret = find(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = ret;
    }
    T weight(int x) {
        find(x);
        return diff_weight[x];
    }
    T diff(int x, int y) { return weight(y) - weight(x); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/unionfind/weightedunionfind.hpp"
/**
* @brief 重み付きUnionFind
* @docs docs/datastructure/unionfind/weightedunionfind.md
* @see https://qiita.com/drken/items/cce6fc5c579051e64fab
*/

template <typename T>
struct WeightedUnionFind {
    int sz;
    vector<int> parent;
    vector<T> diff_weight;
    WeightedUnionFind(int sz)
        : sz(sz), parent(sz, -1), diff_weight(sz, T(0)) {}
    // weight(y) = weight(x) + w
    bool unite(int x, int y, T w) {
        w += weight(x) - weight(y);
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y), w = -w;
            --sz;
            parent[x] += parent[y];
            parent[y]      = x;
            diff_weight[y] = w;
        }
        return true;
    }
    int find(int x) {
        if (parent[x] < 0) return x;
        int ret = find(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = ret;
    }
    T weight(int x) {
        find(x);
        return diff_weight[x];
    }
    T diff(int x, int y) { return weight(y) - weight(x); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

