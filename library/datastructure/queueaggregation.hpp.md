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


# :warning: Queue Aggregation <small>(datastructure/queueaggregation.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/queueaggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-08 23:44:37+09:00




## 概要

全体をfoldしたものを$O(1)$で答えられるQueue.

渡す二項演算$f$は結合律を満たす必要がある.

* 結合律 : $f(f(x, y), z) = f(x, f(y, z))$

## 計算量

$O(1)$

## 使用例

* `QueueAggregation<int> swag([](int a, int b){ return min(a, b); })` : 最小クエリを処理するSWAG.
* `swag.push(x)` : $x$をpush.
* `swag.pop()` : SWAGからpop.
* `swag.query()` : 全体をfold.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Queue Aggregation
* @docs docs/datastructure/queueaggregation.md
*/

template <typename T> struct QueueAggregation {
    using F = function<T(T, T)>;
    stack<pair<T, T>> st_f, st_b;   // {val, sum}
    F func;
    QueueAggregation(const F f) : func(f) {}
    bool empty() const { return st_f.empty() and st_b.empty(); }
    int   size() const { return st_f.size()   +  st_b.empty(); }
    T query() {
        assert(not empty());
        if (st_f.empty()) return st_b.top().second;
        if (st_b.empty()) return st_f.top().second;
        return func(st_f.top().second, st_b.top().second);
    }
    void push(const T &x) {
        if (st_b.empty()) {
            st_b.emplace(x, x);
        } else {
            T merged = func(st_b.top().second, x);
            st_b.emplace(x, merged);
        }
    }
    void pop() {
        assert(not empty());
        if (st_f.empty()) {
            st_f.emplace(st_b.top().first, st_b.top().first);
            st_b.pop();
            while (not st_b.empty()) {
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

template <typename T> struct QueueAggregation {
    using F = function<T(T, T)>;
    stack<pair<T, T>> st_f, st_b;   // {val, sum}
    F func;
    QueueAggregation(const F f) : func(f) {}
    bool empty() const { return st_f.empty() and st_b.empty(); }
    int   size() const { return st_f.size()   +  st_b.empty(); }
    T query() {
        assert(not empty());
        if (st_f.empty()) return st_b.top().second;
        if (st_b.empty()) return st_f.top().second;
        return func(st_f.top().second, st_b.top().second);
    }
    void push(const T &x) {
        if (st_b.empty()) {
            st_b.emplace(x, x);
        } else {
            T merged = func(st_b.top().second, x);
            st_b.emplace(x, merged);
        }
    }
    void pop() {
        assert(not empty());
        if (st_f.empty()) {
            st_f.emplace(st_b.top().first, st_b.top().first);
            st_b.pop();
            while (not st_b.empty()) {
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

