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


# :warning: test/atcoder/abc157_d.unionfind.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e8ba03245cc911ba95395348d53122a0">test/atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/atcoder/abc157_d.unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 21:05:07+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE

// @note uf.size()のverify (UnionFind)

// #define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

// #include "../../template/main.hpp"
// #include "../../datastructure/unionfind/unionfind.hpp"

signed main() {

    int N, M, K;
    cin >> N >> M >> K;

    UnionFind uf(N);

    vector<vector<int>> frd(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        frd[A].emplace_back(B);
        frd[B].emplace_back(A);
        uf.unite(A, B);
    }

    vector<int> res(N);
    for (int i = 0; i < N; ++i) res[i] = uf.size(i);
    for (int i = 0; i < N; ++i) res[i] -= frd[i].size() + 1;
    for (int i = 0; i < K; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        if (uf.same(A, B)) {
            res[A]--;
            res[B]--;
        }
    }

    for (int i = 0; i < N; ++i) cout << res[i] << " \n"[i == N - 1];

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/atcoder/abc157_d.unionfind.cpp"
#define IGNORE

// @note uf.size()のverify (UnionFind)

// #define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

// #include "../../template/main.hpp"
// #include "../../datastructure/unionfind/unionfind.hpp"

signed main() {

    int N, M, K;
    cin >> N >> M >> K;

    UnionFind uf(N);

    vector<vector<int>> frd(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        frd[A].emplace_back(B);
        frd[B].emplace_back(A);
        uf.unite(A, B);
    }

    vector<int> res(N);
    for (int i = 0; i < N; ++i) res[i] = uf.size(i);
    for (int i = 0; i < N; ++i) res[i] -= frd[i].size() + 1;
    for (int i = 0; i < K; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        if (uf.same(A, B)) {
            res[A]--;
            res[B]--;
        }
    }

    for (int i = 0; i < N; ++i) cout << res[i] << " \n"[i == N - 1];

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

