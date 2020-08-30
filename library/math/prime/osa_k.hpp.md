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


# :heavy_check_mark: osa_k法 <small>(math/prime/osa_k.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#284ec5e6a3c30a992cd88179b43d3dce">math/prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime/osa_k.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 18:59:45+09:00


* see: <a href="https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409">https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_1_C.osa_k.test.cpp.html">test/aoj/ALDS1_1_C.osa_k.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief osa_k法
* @docs docs/math/prime/osa_k.hpp
* @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
*/

struct osa_k {
    int N;
    vector<int> min_prime;
    osa_k(int _N)
        : N(_N + 1), min_prime(N) {
        iota(min_prime.begin(), min_prime.end(), 0);
        for (int p = 2; p * p <= N; ++p) {
            if (min_prime[p] != p) continue;
            for (int i = 2 * p; i <= N; i += p) {
                if (min_prime[i] != i) continue;
                min_prime[i] = p;
            }
        }
    }
    bool is_prime(int x) {
        assert(x <= N);
        if (x <= 1) return false;
        return min_prime[x] == x;
    }
    map<int, int> prime_factor(int x) {
        assert(x <= N);
        map<int, int> pf;
        while (x > 1) {
            pf[min_prime[x]]++;
            x /= min_prime[x];
        }
        return pf;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime/osa_k.hpp"
/**
* @brief osa_k法
* @docs docs/math/prime/osa_k.hpp
* @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
*/

struct osa_k {
    int N;
    vector<int> min_prime;
    osa_k(int _N)
        : N(_N + 1), min_prime(N) {
        iota(min_prime.begin(), min_prime.end(), 0);
        for (int p = 2; p * p <= N; ++p) {
            if (min_prime[p] != p) continue;
            for (int i = 2 * p; i <= N; i += p) {
                if (min_prime[i] != i) continue;
                min_prime[i] = p;
            }
        }
    }
    bool is_prime(int x) {
        assert(x <= N);
        if (x <= 1) return false;
        return min_prime[x] == x;
    }
    map<int, int> prime_factor(int x) {
        assert(x <= N);
        map<int, int> pf;
        while (x > 1) {
            pf[min_prime[x]]++;
            x /= min_prime[x];
        }
        return pf;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

