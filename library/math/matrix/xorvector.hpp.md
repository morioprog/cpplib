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


# :warning: Xor Vector <small>(math/matrix/xorvector.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a9839e7477a4d9c748aee996b52a14d5">math/matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/matrix/xorvector.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

掃き出せる`vector<long long>`.

## 計算量

* 掃き出し法 : $O(nb)$ ($b$はビットサイズ)

## 使用例

* `XorVector vec(n)` : 最大サイズ$n$の`vector`を定義.
* `vec.emplace(m)` : $m$を追加.
* `vec.find(m)` : いくつかの要素のXORが$m$になるかを返す.
* `vec.gaussian_elimination()` : 掃き出し法.
* `vec.print()` : デバッグ出力.

## 問題例

* [ABC141F - Xor Sum 3](https://atcoder.jp/contests/abc141/tasks/abc141_f)
* [AGC045A - Xor Battle](https://atcoder.jp/contests/agc045/tasks/agc045_a)
* [codeFlyer D - 数列 XOR](https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Xor Vector
* @docs docs/math/matrix/xorvector.md
*/

struct XorVector {
    bool dirty = false;
    int rank, N;
    vector<long long> span;
    XorVector(int N)
        : rank(0), N(N), span(N, 0) {}
    void emplace(ll num) {
        span[rank++] = num;
        dirty        = true;
    }
    bool find(ll num) {
        if (num == 0) return true;
        if (dirty) gaussian_elimination();
        for (int i = 0; i < rank; ++i) {
            if (span[i] == 0LL) break;
            num = min(num, num ^ span[i]);
        }
        return num == 0LL;
    }
    void gaussian_elimination() {
        rank = 0;
        for (int col = 63; col >= 0; --col) {
            int pivot = -1;
            for (int row = rank; row < N; ++row)
                if (span[row] >> col & 1) {
                    pivot = row;
                    break;
                }
            if (pivot == -1) continue;
            swap(span[pivot], span[rank]);
            for (int row = 0; row < N; ++row)
                if (row != rank and span[row] >> col & 1) span[row] ^= span[rank];
            ++rank;
        }
        dirty = false;
    }
    void print() {
        for (int i = 0; i < rank; ++i) cerr << bitset<64>(span[i]) << endl;
        cerr << endl;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/matrix/xorvector.hpp"
/**
* @brief Xor Vector
* @docs docs/math/matrix/xorvector.md
*/

struct XorVector {
    bool dirty = false;
    int rank, N;
    vector<long long> span;
    XorVector(int N)
        : rank(0), N(N), span(N, 0) {}
    void emplace(ll num) {
        span[rank++] = num;
        dirty        = true;
    }
    bool find(ll num) {
        if (num == 0) return true;
        if (dirty) gaussian_elimination();
        for (int i = 0; i < rank; ++i) {
            if (span[i] == 0LL) break;
            num = min(num, num ^ span[i]);
        }
        return num == 0LL;
    }
    void gaussian_elimination() {
        rank = 0;
        for (int col = 63; col >= 0; --col) {
            int pivot = -1;
            for (int row = rank; row < N; ++row)
                if (span[row] >> col & 1) {
                    pivot = row;
                    break;
                }
            if (pivot == -1) continue;
            swap(span[pivot], span[rank]);
            for (int row = 0; row < N; ++row)
                if (row != rank and span[row] >> col & 1) span[row] ^= span[rank];
            ++rank;
        }
        dirty = false;
    }
    void print() {
        for (int i = 0; i < rank; ++i) cerr << bitset<64>(span[i]) << endl;
        cerr << endl;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

