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


# :heavy_check_mark: test/aoj/NTL_1_E.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_E.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 01:19:00+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/extgcd.hpp.html">拡張ユークリッドの互除法 <small>(math/extgcd.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/short.hpp.html">template/short.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../template/short.hpp"
#include "../../math/extgcd.hpp"

signed main() {

    long long A, B, X, Y;
    cin >> A >> B;
    extgcd(A, B, X, Y);
    cout << X << ' ' << Y << endl;

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_E.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#line 1 "template/short.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))
#line 1 "math/extgcd.hpp"
/**
* @brief 拡張ユークリッドの互除法
* @docs docs/math/extgcd.md
*/

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
#line 5 "test/aoj/NTL_1_E.test.cpp"

signed main() {

    long long A, B, X, Y;
    cin >> A >> B;
    extgcd(A, B, X, Y);
    cout << X << ' ' << Y << endl;

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

