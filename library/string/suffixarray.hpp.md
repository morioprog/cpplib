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


# :heavy_check_mark: 接尾辞配列 (Suffix Array) <small>(string/suffixarray.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/suffixarray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 21:33:23+09:00




## 概要

文字列の接尾辞を管理する. 文字列検索などが行える.

## 計算量

- 構築 : $O(n\log n)$
  - $O(n)$で構築するアルゴリズムもある.
- クエリ
  - `lower_upper_bound` : $O(p\log n)$
    - $p$ : パターン長
  - `lcp` : TODO (蟻本 p.340)

## 使用例

- `SuffixArray sa(s)` : 文字列$s$で接尾辞配列を構築.
- `sa.lower_upper_bound(t)` : 文字列$t$を検索.
  - 返り値: $t$を含む`sa.sa`内の区間.


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_D.test.cpp.html">test/aoj/ALDS1_14_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 接尾辞配列 (Suffix Array)
* @docs docs/string/suffixarray.md
*/

struct SuffixArray {
    vector<int> sa;
    string s;
    SuffixArray(string &s)
        : s(s) {
        sa.resize(s.size());
        iota(begin(sa), end(sa), 0);
        sort(begin(sa), end(sa), [&](int a, int b) {
            return (s[a] == s[b]) ? a > b : s[a] < s[b];
        });
        vector<int> cls(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for (int l = 1; l < s.size(); l <<= 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i > 0 and c[sa[i - 1]] == c[sa[i]] and sa[i - 1] + l < s.size() and c[sa[i - 1] + l / 2] == c[sa[i] + l / 2]) {
                    cls[sa[i]] = cls[sa[i - 1]];
                } else {
                    cls[sa[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(sa), end(sa), begin(c));
            for (int i = 0; i < s.size(); i++) {
                int s1 = c[i] - l;
                if (s1 >= 0) sa[cnt[cls[s1]]++] = s1;
            }
            cls.swap(c);
        }
    }
    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while (si < sn and ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn and ti < tn;
    }
    int lower_bound(const string &t) {
        int low = -1, high = (int)sa.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, sa[mid]))
                low = mid;
            else
                high = mid;
        }
        return high;
    }
    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)sa.size();
        t.back()++;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, sa[mid]))
                low = mid;
            else
                high = mid;
        }
        --t.back();
        return make_pair(idx, high);
    }
    void print() {
        for (int i = 0; i < sa.size(); ++i) {
            cerr << i << " : " << s.substr(sa[i]) << endl;
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/suffixarray.hpp"
/**
* @brief 接尾辞配列 (Suffix Array)
* @docs docs/string/suffixarray.md
*/

struct SuffixArray {
    vector<int> sa;
    string s;
    SuffixArray(string &s)
        : s(s) {
        sa.resize(s.size());
        iota(begin(sa), end(sa), 0);
        sort(begin(sa), end(sa), [&](int a, int b) {
            return (s[a] == s[b]) ? a > b : s[a] < s[b];
        });
        vector<int> cls(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for (int l = 1; l < s.size(); l <<= 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i > 0 and c[sa[i - 1]] == c[sa[i]] and sa[i - 1] + l < s.size() and c[sa[i - 1] + l / 2] == c[sa[i] + l / 2]) {
                    cls[sa[i]] = cls[sa[i - 1]];
                } else {
                    cls[sa[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(sa), end(sa), begin(c));
            for (int i = 0; i < s.size(); i++) {
                int s1 = c[i] - l;
                if (s1 >= 0) sa[cnt[cls[s1]]++] = s1;
            }
            cls.swap(c);
        }
    }
    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while (si < sn and ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn and ti < tn;
    }
    int lower_bound(const string &t) {
        int low = -1, high = (int)sa.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, sa[mid]))
                low = mid;
            else
                high = mid;
        }
        return high;
    }
    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)sa.size();
        t.back()++;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, sa[mid]))
                low = mid;
            else
                high = mid;
        }
        --t.back();
        return make_pair(idx, high);
    }
    void print() {
        for (int i = 0; i < sa.size(); ++i) {
            cerr << i << " : " << s.substr(sa[i]) << endl;
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

