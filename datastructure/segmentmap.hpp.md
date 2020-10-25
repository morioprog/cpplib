---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/datastructure/segmentmap.md
    document_title: "\u533A\u9593\u3092map\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
    links:
    - https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
  bundledCode: "#line 1 \"datastructure/segmentmap.hpp\"\n/**\n* @brief \u533A\u9593\
    \u3092map\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064\n* @note \u9589\u533A\u9593\
    \u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\n* @docs docs/datastructure/segmentmap.md\n\
    * @see https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    */\n\nstruct SegmentMap : public map<long long, long long> {\n    bool flg_merge;\n\
    \    SegmentMap(bool flg_merge = true)\n        : flg_merge(flg_merge) {}\n  \
    \  auto get(long long p) const {\n        auto itr = upper_bound(p);\n       \
    \ if (itr == begin() or (--itr)->second < p) return end();\n        return itr;\n\
    \    }\n    void insert(long long l, long long r) {\n        auto itr_l = upper_bound(l),\
    \ itr_r = upper_bound(r + flg_merge);\n        if (itr_l != begin()) {\n     \
    \       if ((--itr_l)->second < l - flg_merge) ++itr_l;\n        }\n        if\
    \ (itr_l != itr_r) {\n            l = min(l, itr_l->first);\n            r = max(r,\
    \ prev(itr_r)->second);\n            erase(itr_l, itr_r);\n        }\n       \
    \ (*this)[l] = r;\n    }\n    void remove(long long l, long long r) {\n      \
    \  auto itr_l = upper_bound(l), itr_r = upper_bound(r);\n        if (itr_l !=\
    \ begin()) {\n            if ((--itr_l)->second < l) ++itr_l;\n        }\n   \
    \     if (itr_l == itr_r) return;\n        int tl = min(l, itr_l->first), tr =\
    \ max(r, prev(itr_r)->second);\n        erase(itr_l, itr_r);\n        if (tl <\
    \ l) (*this)[tl] = l - 1;\n        if (r < tr) (*this)[r + 1] = tr;\n    }\n \
    \   bool same(long long p, long long q) const {\n        const auto&& itr = get(p);\n\
    \        return itr != end() and itr->first <= q and q <= itr->second;\n    }\n\
    };\n"
  code: "/**\n* @brief \u533A\u9593\u3092map\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064\
    \n* @note \u9589\u533A\u9593\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\n\
    * @docs docs/datastructure/segmentmap.md\n* @see https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    */\n\nstruct SegmentMap : public map<long long, long long> {\n    bool flg_merge;\n\
    \    SegmentMap(bool flg_merge = true)\n        : flg_merge(flg_merge) {}\n  \
    \  auto get(long long p) const {\n        auto itr = upper_bound(p);\n       \
    \ if (itr == begin() or (--itr)->second < p) return end();\n        return itr;\n\
    \    }\n    void insert(long long l, long long r) {\n        auto itr_l = upper_bound(l),\
    \ itr_r = upper_bound(r + flg_merge);\n        if (itr_l != begin()) {\n     \
    \       if ((--itr_l)->second < l - flg_merge) ++itr_l;\n        }\n        if\
    \ (itr_l != itr_r) {\n            l = min(l, itr_l->first);\n            r = max(r,\
    \ prev(itr_r)->second);\n            erase(itr_l, itr_r);\n        }\n       \
    \ (*this)[l] = r;\n    }\n    void remove(long long l, long long r) {\n      \
    \  auto itr_l = upper_bound(l), itr_r = upper_bound(r);\n        if (itr_l !=\
    \ begin()) {\n            if ((--itr_l)->second < l) ++itr_l;\n        }\n   \
    \     if (itr_l == itr_r) return;\n        int tl = min(l, itr_l->first), tr =\
    \ max(r, prev(itr_r)->second);\n        erase(itr_l, itr_r);\n        if (tl <\
    \ l) (*this)[tl] = l - 1;\n        if (r < tr) (*this)[r + 1] = tr;\n    }\n \
    \   bool same(long long p, long long q) const {\n        const auto&& itr = get(p);\n\
    \        return itr != end() and itr->first <= q and q <= itr->second;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segmentmap.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/segmentmap.hpp
layout: document
redirect_from:
- /library/datastructure/segmentmap.hpp
- /library/datastructure/segmentmap.hpp.html
title: "\u533A\u9593\u3092map\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
---
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
