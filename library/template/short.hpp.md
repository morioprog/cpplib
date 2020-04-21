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


# :heavy_check_mark: template/short.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#66f6181bcb4cff4cd38fbc804a036db6">template</a>
* <a href="{{ site.github.repository_url }}/blob/master/template/short.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-21 14:05:17+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ITP1_1_A.short.test.cpp.html">test/aoj/ITP1_1_A.short.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_A.test.cpp.html">test/aoj/NTL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_B.test.cpp.html">test/aoj/NTL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "template/short.hpp"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n)    for (ll (i) = 0;   (i) < (n); ++(i))
#define FOR(i, a, b) for (ll (i) = (a); (i) < (b); ++(i))

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

