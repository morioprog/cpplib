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


# :heavy_check_mark: UnionFind <small>(datastructure/unionfind/unionfind.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#30b7082b479ad4b7861d398d23468641">datastructure/unionfind</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/unionfind/unionfind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 01:48:03+09:00




## 概要

連結成分を管理するデータ構造. [素集合データ構造](https://ja.wikipedia.org/wiki/%E7%B4%A0%E9%9B%86%E5%90%88%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0).

## 計算量

$O(\alpha (n))$

## 使用例

* `UnionFind uf(V)` : $V$頂点のUnionFindを定義.
* `uf.unite(x, y)` : $x$と$y$を連結にする.
* `uf.same(x, y)` : $x$と$y$が連結かを返す.
* `uf.size(x)` : $x$の属する連結成分の大きさを返す.
* `uf.size()` : 連結成分の個数を返す.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief UnionFind
* @docs docs/datastructure/unionfind/unionfind.md
*/

struct UnionFind {
    int sz;
    vector<int> parent;
    UnionFind(int sz) : sz(sz), parent(sz, -1) {}
    bool unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            --sz;
            return true;
        }
        return false;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/unionfind/unionfind.hpp"
/**
* @brief UnionFind
* @docs docs/datastructure/unionfind/unionfind.md
*/

struct UnionFind {
    int sz;
    vector<int> parent;
    UnionFind(int sz) : sz(sz), parent(sz, -1) {}
    bool unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            --sz;
            return true;
        }
        return false;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

