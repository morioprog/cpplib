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


# :warning: 2次元累積和 <small>(datastructure/cumulativesum/cumulativesum2d.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#053d19836570d3243deead9fd40452d5">datastructure/cumulativesum</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/cumulativesum/cumulativesum2d.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 17:52:09+09:00




## 概要

静的な2次元配列に対する矩形和クエリに答える.

## 計算量

* 構築 : $O(hw)$
* クエリ : $O(1)$

## 使用例

* `CumulativeSum2D<int> acc(v)` : `v`で2次元累積和を構築.
* `acc.query(a, b, c, d)` : 矩形$[a, b]$から$(c, d)$までのクエリ.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 2次元累積和
* @docs docs/datastructure/cumulativesum/cumulativesum2d.md
*/

template<class T> struct CumulativeSum2D {
    int H, W;
    vector<vector<T>> data;
    CumulativeSum2D(const vector<vector<T>> &v)
        : H(v.size()), W(v[0].size()) {
        data.assign(H + 1, vector<T>(W + 1, 0));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                data[i + 1][j + 1] = v[i][j] + data[i + 1][j] + data[i][j + 1] - data[i][j];
            }
        }
    }
    T query(int sx, int sy, int gx, int gy) {
        return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy];
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/cumulativesum/cumulativesum2d.hpp"
/**
* @brief 2次元累積和
* @docs docs/datastructure/cumulativesum/cumulativesum2d.md
*/

template<class T> struct CumulativeSum2D {
    int H, W;
    vector<vector<T>> data;
    CumulativeSum2D(const vector<vector<T>> &v)
        : H(v.size()), W(v[0].size()) {
        data.assign(H + 1, vector<T>(W + 1, 0));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                data[i + 1][j + 1] = v[i][j] + data[i + 1][j] + data[i][j + 1] - data[i][j];
            }
        }
    }
    T query(int sx, int sy, int gx, int gy) {
        return data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy];
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

