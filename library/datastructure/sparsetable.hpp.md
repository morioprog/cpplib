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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Sparse Table <small>(datastructure/sparsetable.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/sparsetable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

静的な数列に対する区間取得クエリを定数時間で答えられるデータ構造.

渡す二項演算$f$は結合律と冪等律を満たす必要がある.

* 結合律 : $f(f(x, y), z) = f(x, f(y, z))$
* 冪等律 : $f(x, x) = x$

## 計算量

* 構築 : $O(n\log n)$
* 区間取得 : $O(1)$

## 使用例

* `SparseTable<int> st(v, [](int a, int b){ return min(a, b); })` : 区間最小クエリを処理するSparse Tableを構築.
* `st.query(l, r)` : 半開区間$[l, r)$の区間取得クエリ.


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.test.cpp.html">test/yosupo/staticrmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Sparse Table
* @docs docs/datastructure/sparsetable.md
*/

template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    using F = function<T(T, T)>;
    const F f;
    SparseTable() {}
    SparseTable(const vector<T> &v, const F f)
        : f(f) {
        int b = 0, sz = v.size();
        while ((1 << b) <= sz) ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < sz; ++i) st[0][i] = v[i];
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= (1 << b); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(const int l, const int r) const {
        int b = 31 - __builtin_clz(r - l);
        return f(st[b][l], st[b][r - (1 << b)]);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/sparsetable.hpp"
/**
* @brief Sparse Table
* @docs docs/datastructure/sparsetable.md
*/

template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    using F = function<T(T, T)>;
    const F f;
    SparseTable() {}
    SparseTable(const vector<T> &v, const F f)
        : f(f) {
        int b = 0, sz = v.size();
        while ((1 << b) <= sz) ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < sz; ++i) st[0][i] = v[i];
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= (1 << b); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(const int l, const int r) const {
        int b = 31 - __builtin_clz(r - l);
        return f(st[b][l], st[b][r - (1 << b)]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

