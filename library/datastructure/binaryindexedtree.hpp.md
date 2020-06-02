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


# :heavy_check_mark: Binary Indexed Tree <small>(datastructure/binaryindexedtree.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/binaryindexedtree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 10:45:19+09:00




## 概要

一点加算クエリと区間和クエリを対数時間で行うデータ構造.

## 計算量

* 構築 : $O(n)$
* 区間取得 : $O(\log n)$
* 二分探索 : $O(\log n)$

## 使用例

* `BinaryIndexedTree<int> bit(N)` : 要素数$N$のBIT
* `bit.add(k, x)` : $k$要素目に$x$を加算.
* `bit.sum(k)` : 閉区間$[0, k]$の和を求める
* `bit.sum(l, r)` : 半開区間$[l, r)$の和を求める
* `bit.lower_bound(x)` : `bit.sum(i) >= x`なる最小の$i$を求める


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.binaryindexedtree.test.cpp.html">test/aoj/DSL_2_B.binaryindexedtree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Binary Indexed Tree
* @docs docs/datastructure/binaryindexedtree.md
*/

template<typename T> struct BinaryIndexedTree {
    vector< T > data;
    BinaryIndexedTree(int sz) { data.assign(++sz, 0); }
    T sum(int k) {
        if (k < 0) return T(0);
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    T sum(int l, int r) {
        assert(l <= r);
        return sum(r - 1) - sum(l - 1);
    }
    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int n = data.size(), x = 0, r = 1;
        while (r < n) r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n and data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/binaryindexedtree.hpp"
/**
* @brief Binary Indexed Tree
* @docs docs/datastructure/binaryindexedtree.md
*/

template<typename T> struct BinaryIndexedTree {
    vector< T > data;
    BinaryIndexedTree(int sz) { data.assign(++sz, 0); }
    T sum(int k) {
        if (k < 0) return T(0);
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    T sum(int l, int r) {
        assert(l <= r);
        return sum(r - 1) - sum(l - 1);
    }
    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int n = data.size(), x = 0, r = 1;
        while (r < n) r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n and data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

