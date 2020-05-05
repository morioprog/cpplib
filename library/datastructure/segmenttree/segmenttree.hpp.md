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


# :heavy_check_mark: セグメント木 <small>(datastructure/segmenttree/segmenttree.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#23b0293042a380c2b90b74c55c0e1d22">datastructure/segmenttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/segmenttree/segmenttree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 16:56:36+09:00




## 概要

モノイドに対する1点更新区間取得を管理するデータ構造.

### モノイド

以下を満たす代数的構造.

* 結合律 : $f(f(x, y), z) = f(x, f(y, z))$
* 単位元$e$の存在 : $f(x, e) = f(e, x) = x$

## 計算量

* 構築 : $O(n)$
* クエリ : $O(\log n)$

## 使用例

* `SegmentTree<int> seg(n, [](int a, int b){ return a + b; }, 0);` : 単位元$0$で初期化.
* `SegmentTree<int> seg(v, [](int a, int b){ return a + b; }, 0);` : `v`で初期化.
* `seg.update(k, x);` : $k$要素目を$x$に変更する.
* `seg.add(k, x);` : $k$要素目に$x$を加算する.
* `seg.query(l, r);` : 半開区間$[l, r)$のクエリ.
* `seg.print();` : セグメント木の中身をデバッグ出力.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/pointaddrangesum.test.cpp.html">test/yosupo/pointaddrangesum.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/vertexaddpathsum.test.cpp.html">test/yosupo/vertexaddpathsum.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/vertexaddsubtreesum.test.cpp.html">test/yosupo/vertexaddsubtreesum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief セグメント木
* @docs docs/datastructure/segmenttree/segmenttree.md
*/

template<typename T> struct SegmentTree {
    using F = function<T(T, T)>;
    vector<T> seg;
    int sz;
    const F func;
    const T IDENT;
    SegmentTree() {}
    SegmentTree(int n, const F f, const T &ID) : func(f), IDENT(ID) {
        sz = 1; while (sz < n) sz <<= 1;
        seg.assign(2 * sz - 1, IDENT);
    }
    SegmentTree(vector<T> v, const F f, const T &ID) : func(f), IDENT(ID) {
        int n = v.size();
        sz = 1; while (sz < n) sz <<= 1;
        seg.assign(2 * sz - 1, IDENT);
        for (int i = 0; i < n; ++i) seg[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) seg[i] = func(seg[2 * i + 1], seg[2 * i + 2]);
    }
    void update(int k, T x) {
        k += sz - 1;
        seg[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    void add(int k, T x) {
        k += sz - 1;
        seg[k] += x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = sz;
        if (r <= a || l >= b) return IDENT;
        if (l >= a && r <= b) return seg[k];
        T f_l = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T f_r = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(f_l, f_r);
    }
    void print() {
        for (int i = 0; i < 2 * sz - 1; ++i) {
            cerr << seg[i] << ' ';
            if (!((i + 2) & (i + 1))) cerr << endl;
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/segmenttree/segmenttree.hpp"
/**
* @brief セグメント木
* @docs docs/datastructure/segmenttree/segmenttree.md
*/

template<typename T> struct SegmentTree {
    using F = function<T(T, T)>;
    vector<T> seg;
    int sz;
    const F func;
    const T IDENT;
    SegmentTree() {}
    SegmentTree(int n, const F f, const T &ID) : func(f), IDENT(ID) {
        sz = 1; while (sz < n) sz <<= 1;
        seg.assign(2 * sz - 1, IDENT);
    }
    SegmentTree(vector<T> v, const F f, const T &ID) : func(f), IDENT(ID) {
        int n = v.size();
        sz = 1; while (sz < n) sz <<= 1;
        seg.assign(2 * sz - 1, IDENT);
        for (int i = 0; i < n; ++i) seg[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) seg[i] = func(seg[2 * i + 1], seg[2 * i + 2]);
    }
    void update(int k, T x) {
        k += sz - 1;
        seg[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    void add(int k, T x) {
        k += sz - 1;
        seg[k] += x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = sz;
        if (r <= a || l >= b) return IDENT;
        if (l >= a && r <= b) return seg[k];
        T f_l = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T f_r = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(f_l, f_r);
    }
    void print() {
        for (int i = 0; i < 2 * sz - 1; ++i) {
            cerr << seg[i] << ' ';
            if (!((i + 2) & (i + 1))) cerr << endl;
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

