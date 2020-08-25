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


# :warning: インタラクティブ問題 <small>(util/jury.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/jury.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00




## 概要

インタラクティブ問題の大枠.

## 使用例

* `auto jury = Jury<int, bool, 20>()` : Juryを準備.
  * `jury.query(n)` : 質問クエリ.
  * `jury.answer(x)` : 解答クエリ.
    * 実行したら`exit(0)`で終了するようにするべき.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief インタラクティブ問題
* @docs docs/util/jury.md
*/

template <typename T, typename R, int QMX>
struct Jury {
    int query_cnt;
    map<T, R> memo;
    T N;
    Jury()
        : query_cnt(0) {
        // N = rand();
#ifdef LOCAL
        cerr << "N : " << N << endl;
#endif
    }
    Jury(T _N)
        : query_cnt(0) {
        N = _N;
#ifdef LOCAL
        cerr << "N : " << N << endl;
#endif
    }
    R query(T X) {
        if (memo.count(X)) return memo[X];
        if (++query_cnt > QMX) {
            cerr << "Query Limit Exceeded" << endl;
            exit(1);
        }
#ifdef LOCAL
        cerr << query_cnt << " : " << X << endl;
        // return memo[n] = ...;
#else
        // cout << "? " << X << endl;
        // int rsp;  cin >> rsp;
        // return memo[n] = rsp;
#endif
    }
    void answer(T X) {
#ifdef LOCAL
        if (X == N) {
            cerr << "AC : " << X << endl;
        } else {
            cerr << "WA : " << X << " " << N << endl;
        }
        // exit(0);
#else
        // cout << "! " << X << endl;
        exit(0);
#endif
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/jury.hpp"
/**
* @brief インタラクティブ問題
* @docs docs/util/jury.md
*/

template <typename T, typename R, int QMX>
struct Jury {
    int query_cnt;
    map<T, R> memo;
    T N;
    Jury()
        : query_cnt(0) {
        // N = rand();
#ifdef LOCAL
        cerr << "N : " << N << endl;
#endif
    }
    Jury(T _N)
        : query_cnt(0) {
        N = _N;
#ifdef LOCAL
        cerr << "N : " << N << endl;
#endif
    }
    R query(T X) {
        if (memo.count(X)) return memo[X];
        if (++query_cnt > QMX) {
            cerr << "Query Limit Exceeded" << endl;
            exit(1);
        }
#ifdef LOCAL
        cerr << query_cnt << " : " << X << endl;
        // return memo[n] = ...;
#else
        // cout << "? " << X << endl;
        // int rsp;  cin >> rsp;
        // return memo[n] = rsp;
#endif
    }
    void answer(T X) {
#ifdef LOCAL
        if (X == N) {
            cerr << "AC : " << X << endl;
        } else {
            cerr << "WA : " << X << " " << N << endl;
        }
        // exit(0);
#else
        // cout << "! " << X << endl;
        exit(0);
#endif
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

