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


# :question: 遅延セグメント木 <small>(datastructure/segmenttree/lazysegmenttree.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#23b0293042a380c2b90b74c55c0e1d22">datastructure/segmenttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/segmenttree/lazysegmenttree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




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


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_G.test.cpp.html">test/aoj/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_I.test.cpp.html">test/aoj/DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_E.test.cpp.html">test/aoj/GRL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo/rangeaffinerangesum.test.cpp.html">test/yosupo/rangeaffinerangesum.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/399.test.cpp.html">test/yukicoder/399.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 遅延セグメント木
* @docs docs/datastructure/segmenttree/lazysegmenttree.md
*/

template <typename M, typename OM, typename F, typename G, typename H, typename P>
struct LazySegmentTree {
    int sz;
    F f;
    G g;
    H h;
    P p;
    const M ID_M;
    const OM ID_OM;
    vector<M> dat;
    vector<OM> laz;
    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }
    LazySegmentTree(const vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) {
        int n = v.size();
        build(n);
        for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
    void build(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(2 * sz - 1, ID_M);
        laz.assign(2 * sz - 1, ID_OM);
    }
    void eval(int len, int k) {
        if (laz[k] == ID_OM) return;
        if (2 * k + 1 < 2 * sz - 1) {
            laz[2 * k + 1] = h(laz[2 * k + 1], laz[k]);
            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = ID_OM;
    }
    M update(int a, int b, OM x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return dat[k];
        if (a <= l and r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                          update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    M update(int a, int b, OM x) {
        return update(a, b, x, 0, 0, sz);
    }
    M query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return ID_M;
        if (a <= l and r <= b) return dat[k];
        M vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        M vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    M query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }
    M operator[](const int &k) {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';
        cerr << endl;
    }
};

template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h, p);
}
template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f, g, h, p);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/segmenttree/lazysegmenttree.hpp"
/**
* @brief 遅延セグメント木
* @docs docs/datastructure/segmenttree/lazysegmenttree.md
*/

template <typename M, typename OM, typename F, typename G, typename H, typename P>
struct LazySegmentTree {
    int sz;
    F f;
    G g;
    H h;
    P p;
    const M ID_M;
    const OM ID_OM;
    vector<M> dat;
    vector<OM> laz;
    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }
    LazySegmentTree(const vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) {
        int n = v.size();
        build(n);
        for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
    void build(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(2 * sz - 1, ID_M);
        laz.assign(2 * sz - 1, ID_OM);
    }
    void eval(int len, int k) {
        if (laz[k] == ID_OM) return;
        if (2 * k + 1 < 2 * sz - 1) {
            laz[2 * k + 1] = h(laz[2 * k + 1], laz[k]);
            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = ID_OM;
    }
    M update(int a, int b, OM x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return dat[k];
        if (a <= l and r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                          update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    M update(int a, int b, OM x) {
        return update(a, b, x, 0, 0, sz);
    }
    M query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return ID_M;
        if (a <= l and r <= b) return dat[k];
        M vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        M vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    M query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }
    M operator[](const int &k) {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';
        cerr << endl;
    }
};

template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h, p);
}
template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f, g, h, p);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

