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


# :heavy_check_mark: LR Priority Queue <small>(datastructure/lr/lrprique.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f558c0e940d1b94729e8802fdbca4ee">datastructure/lr</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/lr/lrprique.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 18:58:38+09:00




## 概要

$k$番目の値を高速に取り出せるデータ構造.

## 計算量

- 追加 : $O(\log n)$
- 取得 : $O(\log n)$
  - $f$次第ではオーダーが壊れる
    - 「$k$が固定」や「中央値」は大丈夫

## 使用例

- `LRPrique<ll> lr([](int sz) -> int { return (sz + 1) / 2; })` : 中央値を管理する.
- `LRPrique<ll> lr([](int sz) -> int { return 3; })` : 下から$3$番目の数を管理する.
- `lr.emplace(x)` : $x$を挿入.
- `lr.get()` : $f(sz)$番目の数を取得.


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/649.test.lrprique.cpp.html">test/yukicoder/649.test.lrprique.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief LR Priority Queue
* @docs docs/datastructure/lr/lrprique.md
*/

template <typename T>
struct LRPrique {
    using F = function<int(int)>;
    const F f;
    const T err;
    priority_queue<T> L;
    priority_queue<T, vector<T>, greater<>> R;
    int L_sz, R_sz;
    T L_sum, R_sum;
    // f(sz) -> size of L
    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }
    LRPrique(F f, T err = numeric_limits<T>::max())
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
        T ret = L.top();
        L.pop();
        --L_sz;
        L_sum -= ret;
        return ret;
    }
    T R_pop() {
        T ret = R.top();
        R.pop();
        --R_sz;
        R_sum -= ret;
        return ret;
    }
    void emplace(T x) {
        if (R.empty() or R.top() > x)
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
        return L.top();
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/lr/lrprique.hpp"
/**
* @brief LR Priority Queue
* @docs docs/datastructure/lr/lrprique.md
*/

template <typename T>
struct LRPrique {
    using F = function<int(int)>;
    const F f;
    const T err;
    priority_queue<T> L;
    priority_queue<T, vector<T>, greater<>> R;
    int L_sz, R_sz;
    T L_sum, R_sum;
    // f(sz) -> size of L
    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }
    LRPrique(F f, T err = numeric_limits<T>::max())
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
        T ret = L.top();
        L.pop();
        --L_sz;
        L_sum -= ret;
        return ret;
    }
    T R_pop() {
        T ret = R.top();
        R.pop();
        --R_sz;
        R_sum -= ret;
        return ret;
    }
    void emplace(T x) {
        if (R.empty() or R.top() > x)
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
        return L.top();
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

