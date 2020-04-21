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


# :heavy_check_mark: test/yosupo/unionfind.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/unionfind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 01:48:03+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/unionfind/unionfind.hpp.html">UnionFind <small>(datastructure/unionfind/unionfind.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/short.hpp.html">template/short.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../template/short.hpp"
#include "../../datastructure/unionfind/unionfind.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            cout << uf.same(u, v) << endl;
        }
    }

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/unionfind.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#line 1 "template/short.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))
#line 1 "datastructure/unionfind/unionfind.hpp"
/**
* @brief UnionFind
* @docs docs/datastructure/unionfind/unionfind.md
*/

struct UnionFind {
    int sz;
    vector<int> parent;
    UnionFind(int sz) : sz(sz), parent(sz, -1) {}
    bool unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            --sz;
            return true;
        }
        return false;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};
#line 5 "test/yosupo/unionfind.test.cpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            cout << uf.same(u, v) << endl;
        }
    }

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

