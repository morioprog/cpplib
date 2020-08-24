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


# :x: Combination (Inverse) <small>(math/combination/inverse.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#54907edcdfa59aabac4f72caf192990b">math/combination</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/combination/inverse.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-07 16:44:35+09:00




## 概要

$C$, $P$, $H$を逆元を用いて求める.

## 計算量

* 前計算 : $O(n)$
* クエリ : $O(1)$

## 使用例

* `Combination<modint> comb` : 準備
* `comb.C(n, r)` : $C(n, r)$に答える
* `comb.getFact(m)` : $m!$に答える


## Verified with

* :x: <a href="../../../verify/test/yukicoder/117.test.cpp.html">test/yukicoder/117.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Combination (Inverse)
 * @docs docs/math/combination/inverse.md
 */

template<typename T>
struct Combination {
    using u32 = unsigned int;
    using i64 = long long;
    Combination() {}
    Combination(u32 n) { init(n); }
    vector<T> fact, finv, invs;
    void init(u32 n) {
        u32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (u32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * T(i);
        finv[n] = T(1) / fact[n];
        for (u32 i = n; i >= m; --i) finv[i - 1] = finv[i] * T(i);
        for (u32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    T getFact(u32 n) { init(n); return fact[n]; }
    T getFinv(u32 n) { init(n); return finv[n]; }
    T getInvs(u32 n) { init(n); return invs[n]; }
    T C(i64 n, i64 r) {
        if (r == 0) return T(1);
        if (r <  0) return T(0);
        if (n <  0) return T(r & 1 ? -1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return T(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    T P(i64 n, i64 r) {
        if (n < r || r < 0) return T(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    T H(i64 n, i64 r) {
        if (n < 0 || r < 0) return T(0);
        if (!n && !r) return T(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/combination/inverse.hpp"
/**
 * @brief Combination (Inverse)
 * @docs docs/math/combination/inverse.md
 */

template<typename T>
struct Combination {
    using u32 = unsigned int;
    using i64 = long long;
    Combination() {}
    Combination(u32 n) { init(n); }
    vector<T> fact, finv, invs;
    void init(u32 n) {
        u32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (u32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * T(i);
        finv[n] = T(1) / fact[n];
        for (u32 i = n; i >= m; --i) finv[i - 1] = finv[i] * T(i);
        for (u32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    T getFact(u32 n) { init(n); return fact[n]; }
    T getFinv(u32 n) { init(n); return finv[n]; }
    T getInvs(u32 n) { init(n); return invs[n]; }
    T C(i64 n, i64 r) {
        if (r == 0) return T(1);
        if (r <  0) return T(0);
        if (n <  0) return T(r & 1 ? -1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return T(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    T P(i64 n, i64 r) {
        if (n < r || r < 0) return T(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    T H(i64 n, i64 r) {
        if (n < 0 || r < 0) return T(0);
        if (!n && !r) return T(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

