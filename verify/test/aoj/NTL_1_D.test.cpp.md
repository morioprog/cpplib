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


# :heavy_check_mark: test/aoj/NTL_1_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/NTL_1_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-22 01:00:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/math/prime/euler_totient.hpp.html">Euler's totient function (オイラーのφ関数) <small>(math/prime/euler_totient.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/short.hpp.html">template/short.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include "../../template/short.hpp"
#include "../../math/prime/euler_totient.hpp"

signed main() {

    int N;  cin >> N;
    cout << euler_totient(N) << endl;

}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/NTL_1_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#line 1 "template/short.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))
#line 1 "math/prime/euler_totient.hpp"
/**
* @brief Euler's totient function (オイラーのφ関数)
* @docs docs/math/prime/euler_totient.md
*/

long long euler_totient(long long n) {
    long long ret = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        ret -= ret / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ret -= ret / n;
    return ret;
}
#line 5 "test/aoj/NTL_1_D.test.cpp"

signed main() {

    int N;  cin >> N;
    cout << euler_totient(N) << endl;

}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

