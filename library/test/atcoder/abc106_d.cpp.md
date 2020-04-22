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


# :warning: test/atcoder/abc106_d.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e8ba03245cc911ba95395348d53122a0">test/atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/atcoder/abc106_d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 01:10:40+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE

// #define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

// #include "../../template/main.hpp"
// #include "../../datastructure/cumulativesum/cumulativesum2d.hpp"

signed main() {
 
    int N, M, Q;
    cin >> N >> M >> Q;
 
    vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
    while (M--) {
        int L, R;
        cin >> L >> R;
        v[L][R]++;
    }
 
    CumulativeSum2D<int> acc(v);
 
    while (Q--) {
        int p, q;
        cin >> p >> q;
        print(acc.query(p, p, q + 1, q + 1));
    }
 
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/atcoder/abc106_d.cpp"
#define IGNORE

// #define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

// #include "../../template/main.hpp"
// #include "../../datastructure/cumulativesum/cumulativesum2d.hpp"

signed main() {
 
    int N, M, Q;
    cin >> N >> M >> Q;
 
    vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
    while (M--) {
        int L, R;
        cin >> L >> R;
        v[L][R]++;
    }
 
    CumulativeSum2D<int> acc(v);
 
    while (Q--) {
        int p, q;
        cin >> p >> q;
        print(acc.query(p, p, q + 1, q + 1));
    }
 
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

