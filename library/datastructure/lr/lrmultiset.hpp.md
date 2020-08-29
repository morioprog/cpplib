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


# :heavy_check_mark: LR MultiSet <small>(datastructure/lr/lrmultiset.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f558c0e940d1b94729e8802fdbca4ee">datastructure/lr</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/lr/lrmultiset.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 18:58:38+09:00




## 概要

$k$番目の値を高速に取り出せるデータ構造. 削除を行えるが定数倍が少し重い.

## 計算量

- 追加 : $O(\log n)$
- 削除 : $O(\log n)$
- 取得 : $O(\log n)$
  - $k$が固定, 中央値
  - $f$次第ではオーダーが壊れる

## 使用例

- `LRMultiSet<ll> lr([](int sz) -> int { return (sz + 1) / 2; })` : 中央値を管理する.
- `LRMultiSet<ll> lr([](int sz) -> int { return 3; })` : 下から$3$番目の数を管理する.
- `lr.emplace(x)` : $x$を挿入.
- `lr.erase(x)` : $x$を削除.
- `lr.get()` : $f(sz)$番目の数を取得.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/649.test.lrmultiset.cpp.html">test/yukicoder/649.test.lrmultiset.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief LR MultiSet
* @docs docs/datastructure/lr/lrmultiset.md
*/

template <typename T>
struct LRMultiSet {
    using F = function<int(int)>;
    const F f;
    const T err;
    multiset<T> L, R;
    int L_sz, R_sz;
    T L_sum, R_sum;
    // f(sz) -> size of L
    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }
    LRMultiSet(F f, T err = numeric_limits<T>::max())
        : f(f), err(err), L_sz(0), R_sz(0), L_sum(0), R_sum(0) {}
    void L_push(T x) {
        ++L_sz;
        L_sum += x;
        L.emplace(x);
    }
    void R_push(T x) {
        ++R_sz;
        R_sum += x;
        R.emplace(x);
    }
    T L_pop() {
        T ret = L_get_max();
        L.erase(prev(L.end()));
        --L_sz;
        L_sum -= ret;
        return ret;
    }
    T R_pop() {
        T ret = R_get_min();
        R.erase(R.begin());
        --R_sz;
        R_sum -= ret;
        return ret;
    }
    T L_get_min() {
        if (L.empty()) return err;
        return *L.begin();
    }
    T L_get_max() {
        if (L.empty()) return err;
        return *prev(L.end());
    }
    T R_get_min() {
        if (R.empty()) return err;
        return *R.begin();
    }
    T R_get_max() {
        if (R.empty()) return err;
        return *prev(R.end());
    }
    void erase(T x) {
        auto itr_l = L.find(x);
        if (itr_l != L.end()) {
            --L_sz;
            L_sum -= x;
            L.erase(itr_l);
            return;
        }
        auto itr_r = R.find(x);
        if (itr_r != R.end()) {
            --R_sz;
            R_sum -= x;
            R.erase(itr_r);
            return;
        }
        assert(false);
    }
    void emplace(T x) {
        if (R.empty() or R_get_min() > x)
            L_push(x);
        else
            R_push(x);
    }
    void flatten() {
        int gL_sz = f(L_sz + R_sz);
        while (L.size() < gL_sz) {
            T tp = R_pop();
            L_push(tp);
        }
        while (L.size() > gL_sz) {
            T tp = L_pop();
            R_push(tp);
        }
    }
    T get() {
        int gL_sz = f(L_sz + R_sz);
        if (gL_sz > L_sz + R_sz) return err;
        flatten();
        return L_get_max();
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/lr/lrmultiset.hpp"
/**
* @brief LR MultiSet
* @docs docs/datastructure/lr/lrmultiset.md
*/

template <typename T>
struct LRMultiSet {
    using F = function<int(int)>;
    const F f;
    const T err;
    multiset<T> L, R;
    int L_sz, R_sz;
    T L_sum, R_sum;
    // f(sz) -> size of L
    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }
    LRMultiSet(F f, T err = numeric_limits<T>::max())
        : f(f), err(err), L_sz(0), R_sz(0), L_sum(0), R_sum(0) {}
    void L_push(T x) {
        ++L_sz;
        L_sum += x;
        L.emplace(x);
    }
    void R_push(T x) {
        ++R_sz;
        R_sum += x;
        R.emplace(x);
    }
    T L_pop() {
        T ret = L_get_max();
        L.erase(prev(L.end()));
        --L_sz;
        L_sum -= ret;
        return ret;
    }
    T R_pop() {
        T ret = R_get_min();
        R.erase(R.begin());
        --R_sz;
        R_sum -= ret;
        return ret;
    }
    T L_get_min() {
        if (L.empty()) return err;
        return *L.begin();
    }
    T L_get_max() {
        if (L.empty()) return err;
        return *prev(L.end());
    }
    T R_get_min() {
        if (R.empty()) return err;
        return *R.begin();
    }
    T R_get_max() {
        if (R.empty()) return err;
        return *prev(R.end());
    }
    void erase(T x) {
        auto itr_l = L.find(x);
        if (itr_l != L.end()) {
            --L_sz;
            L_sum -= x;
            L.erase(itr_l);
            return;
        }
        auto itr_r = R.find(x);
        if (itr_r != R.end()) {
            --R_sz;
            R_sum -= x;
            R.erase(itr_r);
            return;
        }
        assert(false);
    }
    void emplace(T x) {
        if (R.empty() or R_get_min() > x)
            L_push(x);
        else
            R_push(x);
    }
    void flatten() {
        int gL_sz = f(L_sz + R_sz);
        while (L.size() < gL_sz) {
            T tp = R_pop();
            L_push(tp);
        }
        while (L.size() > gL_sz) {
            T tp = L_pop();
            R_push(tp);
        }
    }
    T get() {
        int gL_sz = f(L_sz + R_sz);
        if (gL_sz > L_sz + R_sz) return err;
        flatten();
        return L_get_max();
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

