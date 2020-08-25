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


# :heavy_check_mark: 1次元累積和 <small>(datastructure/cumulativesum/cumulativesum.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#053d19836570d3243deead9fd40452d5">datastructure/cumulativesum</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/cumulativesum/cumulativesum.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

静的な配列に対する区間和クエリに答える.

## 計算量

* 構築 : $O(n)$
* クエリ : $O(1)$

## 使用例

* `CumulativeSum<int> acc(v)` : `v`で累積和を構築.
* `acc.query(l, r)` : 半開区間$[l, r)$のクエリ.
* `acc[k]` : 元の配列の$k$要素目.
* `acc.print()` : 累積和の中身をデバッグ出力.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/staticrangesum.test.cpp.html">test/yosupo/staticrangesum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 1次元累積和
* @docs docs/datastructure/cumulativesum/cumulativesum.md
*/

template <typename T>
struct CumulativeSum {
    int sz;
    vector<T> data;
    CumulativeSum(const vector<T> &v, const T margin = 0)
        : sz(v.size()), data(1, margin) {
        for (int i = 0; i < sz; ++i) data.emplace_back(data[i] + v[i]);
    }
    T query(const int &l, const int &r) const {
        if (l >= r) return 0;
        return data[min(r, sz)] - data[max(l, 0)];
    }
    T operator[](const int &k) const {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << data[i] << ' ';
        cerr << endl;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/cumulativesum/cumulativesum.hpp"
/**
* @brief 1次元累積和
* @docs docs/datastructure/cumulativesum/cumulativesum.md
*/

template <typename T>
struct CumulativeSum {
    int sz;
    vector<T> data;
    CumulativeSum(const vector<T> &v, const T margin = 0)
        : sz(v.size()), data(1, margin) {
        for (int i = 0; i < sz; ++i) data.emplace_back(data[i] + v[i]);
    }
    T query(const int &l, const int &r) const {
        if (l >= r) return 0;
        return data[min(r, sz)] - data[max(l, 0)];
    }
    T operator[](const int &k) const {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << data[i] << ' ';
        cerr << endl;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

