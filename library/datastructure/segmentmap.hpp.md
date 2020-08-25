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


# :warning: 区間をmapで管理するやつ <small>(datastructure/segmentmap.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/segmentmap.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:20:34+09:00


* see: <a href="https://satanic0258.github.io/snippets/data-structure/SegmentMap.html">https://satanic0258.github.io/snippets/data-structure/SegmentMap.html</a>


## 概要

**閉**区間を`map`で管理するやつ.

## 計算量

* 各クエリ : $O(\log n)$

## 使用例

* `SegmentMap mp(flg = true)` : 「区間を`map`で管理するやつ」を準備.
  * `flg` : $[l, c]$と$[c + 1, r]$をマージするかどうか.
* `mp.get(p)` : $p$を含む区間を返す. (存在しないなら`mp.end()`)
* `mp.insert(l, r)` : 閉区間$[l, r]$を追加する.
* `mp.remove(l, r)` : 閉区間$[l, r]$を取り除く.
* `mp.same(p, q)` : $2$点$p$, $q$が同じ区間にあれば`true`.


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief 区間をmapで管理するやつ
* @note 閉区間であることに注意
* @docs docs/datastructure/segmentmap.md
* @see https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
*/

struct SegmentMap : public map<long long, long long> {
    bool flg_merge;
    SegmentMap(bool flg_merge = true)
        : flg_merge(flg_merge) {}
    auto get(long long p) const {
        auto itr = upper_bound(p);
        if (itr == begin() or (--itr)->second < p) return end();
        return itr;
    }
    void insert(long long l, long long r) {
        auto itr_l = upper_bound(l), itr_r = upper_bound(r + flg_merge);
        if (itr_l != begin()) {
            if ((--itr_l)->second < l - flg_merge) ++itr_l;
        }
        if (itr_l != itr_r) {
            l = min(l, itr_l->first);
            r = max(r, prev(itr_r)->second);
            erase(itr_l, itr_r);
        }
        (*this)[l] = r;
    }
    void remove(long long l, long long r) {
        auto itr_l = upper_bound(l), itr_r = upper_bound(r);
        if (itr_l != begin()) {
            if ((--itr_l)->second < l) ++itr_l;
        }
        if (itr_l == itr_r) return;
        int tl = min(l, itr_l->first), tr = max(r, prev(itr_r)->second);
        erase(itr_l, itr_r);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    bool same(long long p, long long q) const {
        const auto&& itr = get(p);
        return itr != end() and itr->first <= q and q <= itr->second;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/segmentmap.hpp"
/**
* @brief 区間をmapで管理するやつ
* @note 閉区間であることに注意
* @docs docs/datastructure/segmentmap.md
* @see https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
*/

struct SegmentMap : public map<long long, long long> {
    bool flg_merge;
    SegmentMap(bool flg_merge = true)
        : flg_merge(flg_merge) {}
    auto get(long long p) const {
        auto itr = upper_bound(p);
        if (itr == begin() or (--itr)->second < p) return end();
        return itr;
    }
    void insert(long long l, long long r) {
        auto itr_l = upper_bound(l), itr_r = upper_bound(r + flg_merge);
        if (itr_l != begin()) {
            if ((--itr_l)->second < l - flg_merge) ++itr_l;
        }
        if (itr_l != itr_r) {
            l = min(l, itr_l->first);
            r = max(r, prev(itr_r)->second);
            erase(itr_l, itr_r);
        }
        (*this)[l] = r;
    }
    void remove(long long l, long long r) {
        auto itr_l = upper_bound(l), itr_r = upper_bound(r);
        if (itr_l != begin()) {
            if ((--itr_l)->second < l) ++itr_l;
        }
        if (itr_l == itr_r) return;
        int tl = min(l, itr_l->first), tr = max(r, prev(itr_r)->second);
        erase(itr_l, itr_r);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    bool same(long long p, long long q) const {
        const auto&& itr = get(p);
        return itr != end() and itr->first <= q and q <= itr->second;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

