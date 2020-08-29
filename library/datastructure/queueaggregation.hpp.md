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


# :heavy_check_mark: Queue Aggregation <small>(datastructure/queueaggregation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/queueaggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-29 20:31:38+09:00




## 概要

全体を二項演算$f$で畳み込んだものを$O(1)$で答えられるキュー.

渡す$f$は結合律を満たす必要がある.

- 結合律 : $f(f(x, y), z) = f(x, f(y, z))$

## 計算量

$O(1)$

## 使用例

- `QueueAggregation<int> swag([](int a, int b){ return min(a, b); })` : 最小クエリを処理する SWAG.
- `swag.emplace(x)` : $x$を追加.
- `swag.pop()` : `swag`から`pop`.
- `swag.query()` : 全体を$f$で畳んだ結果.


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/1036.test.cpp.html">test/yukicoder/1036.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Queue Aggregation
* @docs docs/datastructure/queueaggregation.md
*/

template <typename T>
struct QueueAggregation {
    using F = function<T(T, T)>;
    stack<pair<T, T>> st_f, st_b;  // {val, sum}
    const F func;
    const T IDENT;
    QueueAggregation(const F f, const T IDENT)
        : func(f), IDENT(IDENT) {
        st_f.emplace(IDENT, IDENT);
        st_b.emplace(IDENT, IDENT);
    }
    // remove sentinel
    int size() const { return (int)st_f.size() + (int)st_b.size() - 2; }
    bool empty() const { return size() == 0; }
    T query() {
        return func(st_f.top().second, st_b.top().second);
    }
    void emplace(const T &x) {
        T merged = func(st_b.top().second, x);
        st_b.emplace(x, merged);
    }
    void pop() {
        assert(not empty());
        if (st_f.size() == 1) {  // <=> st_f.empty()
            st_f.emplace(st_b.top().first, st_b.top().first);
            st_b.pop();
            while (st_b.size() != 1) {
                T merged = func(st_b.top().first, st_f.top().second);
                st_f.emplace(st_b.top().first, merged);
                st_b.pop();
            }
        }
        st_f.pop();
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/queueaggregation.hpp"
/**
* @brief Queue Aggregation
* @docs docs/datastructure/queueaggregation.md
*/

template <typename T>
struct QueueAggregation {
    using F = function<T(T, T)>;
    stack<pair<T, T>> st_f, st_b;  // {val, sum}
    const F func;
    const T IDENT;
    QueueAggregation(const F f, const T IDENT)
        : func(f), IDENT(IDENT) {
        st_f.emplace(IDENT, IDENT);
        st_b.emplace(IDENT, IDENT);
    }
    // remove sentinel
    int size() const { return (int)st_f.size() + (int)st_b.size() - 2; }
    bool empty() const { return size() == 0; }
    T query() {
        return func(st_f.top().second, st_b.top().second);
    }
    void emplace(const T &x) {
        T merged = func(st_b.top().second, x);
        st_b.emplace(x, merged);
    }
    void pop() {
        assert(not empty());
        if (st_f.size() == 1) {  // <=> st_f.empty()
            st_f.emplace(st_b.top().first, st_b.top().first);
            st_b.pop();
            while (st_b.size() != 1) {
                T merged = func(st_b.top().first, st_f.top().second);
                st_f.emplace(st_b.top().first, merged);
                st_b.pop();
            }
        }
        st_f.pop();
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

