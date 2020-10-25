---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/rangechminchmaxaddrangesum.test.cpp
    title: test/yosupo/rangechminchmaxaddrangesum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/segmenttree/segmenttreebeats.md
    document_title: Segment Tree Beats
    links: []
  bundledCode: "#line 1 \"datastructure/segmenttree/segmenttreebeats.hpp\"\n/**\n\
    * @brief Segment Tree Beats\n* @docs docs/datastructure/segmenttree/segmenttreebeats.md\n\
    */\n\n// clang-format off\nstruct SegmentTreeBeats {\n    static const long long\
    \ INF = 1LL << 60;\n    struct Node {\n        Node *left, *right;\n        long\
    \ long max_v, smax_v, max_c;\n        long long min_v, smin_v, min_c;\n      \
    \  long long sum;\n        long long len, ladd, lval;\n\n        Node() : left(0),\
    \ right(0), ladd(0), lval(INF) {}\n\n        void init(long long x) {\n      \
    \      max_v = min_v = sum = x;\n            smax_v = -INF; smin_v = INF;\n  \
    \          max_c = min_c = 1;\n        }\n\n        void init_empty() {\n    \
    \        max_v = smax_v = -INF;\n            min_v = smin_v = INF;\n         \
    \   max_c = min_c = 0;\n        }\n\n        void update_max(long long x) {\n\
    \            sum += (x - max_v) * max_c;\n            /* */if (max_v ==  min_v)\
    \ max_v =  min_v = x;\n            else if (max_v == smin_v) max_v = smin_v =\
    \ x;\n            else                      max_v = x;\n            if (lval !=\
    \ INF and x < lval) lval = x;\n        }\n\n        void update_min(long long\
    \ x) {\n            sum += (x - min_v) * min_c;\n            /* */if (max_v ==\
    \  min_v) max_v =  min_v = x;\n            else if (max_v == smin_v) min_v = smax_v\
    \ = x;\n            else                      min_v = x;\n            if (lval\
    \ != INF and lval < x) lval = x;\n        }\n\n        void addall(long long x)\
    \ {\n            max_v += x;\n            if (smax_v != -INF) smax_v += x;\n \
    \           min_v += x;\n            if (smin_v != INF) smin_v += x;\n       \
    \     sum += len * x;\n            if (lval != INF) lval += x;\n            else\
    \             ladd += x;\n        }\n\n        void updateall(long long x) {\n\
    \            max_v = min_v = x;\n            smax_v = -INF; smin_v = INF;\n  \
    \          max_c = min_c = len;\n            sum = len * x;\n            lval\
    \ = x; ladd = 0;\n        }\n\n        void push() {\n            if (lval !=\
    \ INF) {\n                 left -> updateall(lval);\n                right ->\
    \ updateall(lval);\n                lval = INF;\n                return;\n   \
    \         }\n            if (ladd != 0) {\n                 left -> addall(ladd);\n\
    \                right -> addall(ladd);\n                ladd = 0;\n         \
    \   }\n            if (max_v < left -> max_v)   left -> update_max(max_v);\n \
    \           if (left -> min_v < min_v)   left -> update_min(min_v);\n        \
    \    if (max_v < right -> max_v) right -> update_max(max_v);\n            if (right\
    \ -> min_v < min_v) right -> update_min(min_v);\n        }\n\n        void update()\
    \ {\n            sum = left -> sum + right -> sum;\n            if (left -> max_v\
    \ < right -> max_v) {\n                max_v = right -> max_v;\n             \
    \   max_c = right -> max_c;\n                smax_v = max(left -> max_v, right\
    \ -> smax_v);\n            } else if (left -> max_v > right -> max_v) {\n    \
    \            max_v = left -> max_v;\n                max_c = left -> max_c;\n\
    \                smax_v = max(left -> smax_v, right -> max_v);\n            }\
    \ else {\n                max_v = left -> max_v;\n                max_c = left\
    \ -> max_c + right -> max_c;\n                smax_v = max(left -> smax_v, right\
    \ -> smax_v);\n            }\n            if (left -> min_v < right -> min_v)\
    \ {\n                min_v = left -> min_v;\n                min_c = left -> min_c;\n\
    \                smin_v = min(left -> smin_v, right -> min_v);\n            }\
    \ else if (left -> min_v > right -> min_v) {\n                min_v = right ->\
    \ min_v;\n                min_c = right -> min_c;\n                smin_v = min(left\
    \ -> min_v, right -> smin_v);\n            } else {\n                min_v = left\
    \ -> min_v;\n                min_c = left -> min_c + right -> min_c;\n       \
    \         smin_v = min(left -> smin_v, right -> smin_v);\n            }\n    \
    \    }\n    };\n\n    int n, n0;\n    Node *root;\n\n    void _update_min(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a || nd -> max_v <= x) return;\n        if (a <= l && r <= b && nd -> smax_v\
    \ < x) {\n            nd -> update_max(x);\n            return;\n        }\n \
    \       nd -> push();\n        _update_min(x, a, b, nd ->  left, l, (l + r) >>\
    \ 1);\n        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);\n        nd\
    \ -> update();\n    }\n\n    void _update_max(long long x, int a, int b, Node\
    \ *nd, int l, int r) {\n        if (b <= l || r <= a || x <= nd -> min_v) return;\n\
    \        if (a <= l && r <= b && x < nd -> smin_v) {\n            nd -> update_min(x);\n\
    \            return;\n        }\n        nd -> push();\n        _update_max(x,\
    \ a, b, nd ->  left, l, (l + r) >> 1);\n        _update_max(x, a, b, nd -> right,\
    \ (l + r) >> 1, r);\n        nd -> update();\n    }\n\n    void _add_val(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a) return;\n        if (a <= l && r <= b) {\n            nd -> addall(x);\n\
    \            return;\n        }\n        nd -> push();\n        _add_val(x, a,\
    \ b, nd ->  left, l, (l + r) >> 1);\n        _add_val(x, a, b, nd -> right, (l\
    \ + r) >> 1, r);\n        nd -> update();\n    }\n\n    void _update_val(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a) return;\n        if (a <= l && r <= b) {\n            nd -> updateall(x);\n\
    \            return;\n        }\n        nd -> push();\n        _update_val(x,\
    \ a, b, nd ->  left, l, (l + r) >> 1);\n        _update_val(x, a, b, nd -> right,\
    \ (l + r) >> 1, r);\n        nd -> update();\n    }\n\n    long long _query_max(int\
    \ a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <= a) return -INF;\n\
    \        if (a <= l && r <= b) return nd -> max_v;\n        nd -> push();\n  \
    \      long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);\n      \
    \  long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);\n        return\
    \ max(lv, rv);\n    }\n\n    long long _query_min(int a, int b, Node *nd, int\
    \ l, int r) {\n        if (b <= l || r <= a) return INF;\n        if (a <= l &&\
    \ r <= b) return nd -> min_v;\n        nd -> push();\n        long long lv = _query_min(a,\
    \ b, nd ->  left, l, (l + r) >> 1);\n        long long rv = _query_min(a, b, nd\
    \ -> right, (l + r) >> 1, r);\n        return min(lv, rv);\n    }\n\n    long\
    \ long _query_sum(int a, int b, Node *nd, int l, int r) {\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return nd -> sum;\n    \
    \    nd -> push();\n        long long lv = _query_sum(a, b, nd ->  left, l, (l\
    \ + r) >> 1);\n        long long rv = _query_sum(a, b, nd -> right, (l + r) >>\
    \ 1, r);\n        return lv + rv;\n    }\n\n    SegmentTreeBeats(int n, long long\
    \ val = 0) : n(n) {\n        n0 = 1; while (n0 < n) n0 <<= 1;\n        Node *nds\
    \ = new Node[2 * n0];\n        root = nds;\n        nds[0].len = n0;\n       \
    \ for (int i = 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n\
    \            nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len =\
    \ nds[2 * i + 2].len = nds[i].len >> 1;\n        }\n        for (int i = 0; i\
    \ <  n; ++i) nds[n0 - 1 + i].init(val);\n        for (int i = n; i < n0; ++i)\
    \ nds[n0 - 1 + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n\n    SegmentTreeBeats(const vector<long long> &v) : n((int)v.size())\
    \ {\n        n0 = 1; while (n0 < n) n0 <<= 1;\n        Node *nds = new Node[2\
    \ * n0];\n        root = nds;\n        nds[0].len = n0;\n        for (int i =\
    \ 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n        \
    \    nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len = nds[2 *\
    \ i + 2].len = nds[i].len >> 1;\n        }\n        for (int i = 0; i <  n; ++i)\
    \ nds[n0 - 1 + i].init(v[i]);\n        for (int i = n; i < n0; ++i) nds[n0 - 1\
    \ + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n\n    void update_min(int a, int b, long long x) { _update_min(x, a, b,\
    \ root, 0, n0); }\n    void update_max(int a, int b, long long x) { _update_max(x,\
    \ a, b, root, 0, n0); }\n    void    add_val(int a, int b, long long x) {    _add_val(x,\
    \ a, b, root, 0, n0); }\n    void update_val(int a, int b, long long x) { _update_val(x,\
    \ a, b, root, 0, n0); }\n    long long query_max(int a, int b) { return _query_max(a,\
    \ b, root, 0, n0); }\n    long long query_min(int a, int b) { return _query_min(a,\
    \ b, root, 0, n0); }\n    long long query_sum(int a, int b) { return _query_sum(a,\
    \ b, root, 0, n0); }\n};\n// clang-format on\n"
  code: "/**\n* @brief Segment Tree Beats\n* @docs docs/datastructure/segmenttree/segmenttreebeats.md\n\
    */\n\n// clang-format off\nstruct SegmentTreeBeats {\n    static const long long\
    \ INF = 1LL << 60;\n    struct Node {\n        Node *left, *right;\n        long\
    \ long max_v, smax_v, max_c;\n        long long min_v, smin_v, min_c;\n      \
    \  long long sum;\n        long long len, ladd, lval;\n\n        Node() : left(0),\
    \ right(0), ladd(0), lval(INF) {}\n\n        void init(long long x) {\n      \
    \      max_v = min_v = sum = x;\n            smax_v = -INF; smin_v = INF;\n  \
    \          max_c = min_c = 1;\n        }\n\n        void init_empty() {\n    \
    \        max_v = smax_v = -INF;\n            min_v = smin_v = INF;\n         \
    \   max_c = min_c = 0;\n        }\n\n        void update_max(long long x) {\n\
    \            sum += (x - max_v) * max_c;\n            /* */if (max_v ==  min_v)\
    \ max_v =  min_v = x;\n            else if (max_v == smin_v) max_v = smin_v =\
    \ x;\n            else                      max_v = x;\n            if (lval !=\
    \ INF and x < lval) lval = x;\n        }\n\n        void update_min(long long\
    \ x) {\n            sum += (x - min_v) * min_c;\n            /* */if (max_v ==\
    \  min_v) max_v =  min_v = x;\n            else if (max_v == smin_v) min_v = smax_v\
    \ = x;\n            else                      min_v = x;\n            if (lval\
    \ != INF and lval < x) lval = x;\n        }\n\n        void addall(long long x)\
    \ {\n            max_v += x;\n            if (smax_v != -INF) smax_v += x;\n \
    \           min_v += x;\n            if (smin_v != INF) smin_v += x;\n       \
    \     sum += len * x;\n            if (lval != INF) lval += x;\n            else\
    \             ladd += x;\n        }\n\n        void updateall(long long x) {\n\
    \            max_v = min_v = x;\n            smax_v = -INF; smin_v = INF;\n  \
    \          max_c = min_c = len;\n            sum = len * x;\n            lval\
    \ = x; ladd = 0;\n        }\n\n        void push() {\n            if (lval !=\
    \ INF) {\n                 left -> updateall(lval);\n                right ->\
    \ updateall(lval);\n                lval = INF;\n                return;\n   \
    \         }\n            if (ladd != 0) {\n                 left -> addall(ladd);\n\
    \                right -> addall(ladd);\n                ladd = 0;\n         \
    \   }\n            if (max_v < left -> max_v)   left -> update_max(max_v);\n \
    \           if (left -> min_v < min_v)   left -> update_min(min_v);\n        \
    \    if (max_v < right -> max_v) right -> update_max(max_v);\n            if (right\
    \ -> min_v < min_v) right -> update_min(min_v);\n        }\n\n        void update()\
    \ {\n            sum = left -> sum + right -> sum;\n            if (left -> max_v\
    \ < right -> max_v) {\n                max_v = right -> max_v;\n             \
    \   max_c = right -> max_c;\n                smax_v = max(left -> max_v, right\
    \ -> smax_v);\n            } else if (left -> max_v > right -> max_v) {\n    \
    \            max_v = left -> max_v;\n                max_c = left -> max_c;\n\
    \                smax_v = max(left -> smax_v, right -> max_v);\n            }\
    \ else {\n                max_v = left -> max_v;\n                max_c = left\
    \ -> max_c + right -> max_c;\n                smax_v = max(left -> smax_v, right\
    \ -> smax_v);\n            }\n            if (left -> min_v < right -> min_v)\
    \ {\n                min_v = left -> min_v;\n                min_c = left -> min_c;\n\
    \                smin_v = min(left -> smin_v, right -> min_v);\n            }\
    \ else if (left -> min_v > right -> min_v) {\n                min_v = right ->\
    \ min_v;\n                min_c = right -> min_c;\n                smin_v = min(left\
    \ -> min_v, right -> smin_v);\n            } else {\n                min_v = left\
    \ -> min_v;\n                min_c = left -> min_c + right -> min_c;\n       \
    \         smin_v = min(left -> smin_v, right -> smin_v);\n            }\n    \
    \    }\n    };\n\n    int n, n0;\n    Node *root;\n\n    void _update_min(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a || nd -> max_v <= x) return;\n        if (a <= l && r <= b && nd -> smax_v\
    \ < x) {\n            nd -> update_max(x);\n            return;\n        }\n \
    \       nd -> push();\n        _update_min(x, a, b, nd ->  left, l, (l + r) >>\
    \ 1);\n        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);\n        nd\
    \ -> update();\n    }\n\n    void _update_max(long long x, int a, int b, Node\
    \ *nd, int l, int r) {\n        if (b <= l || r <= a || x <= nd -> min_v) return;\n\
    \        if (a <= l && r <= b && x < nd -> smin_v) {\n            nd -> update_min(x);\n\
    \            return;\n        }\n        nd -> push();\n        _update_max(x,\
    \ a, b, nd ->  left, l, (l + r) >> 1);\n        _update_max(x, a, b, nd -> right,\
    \ (l + r) >> 1, r);\n        nd -> update();\n    }\n\n    void _add_val(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a) return;\n        if (a <= l && r <= b) {\n            nd -> addall(x);\n\
    \            return;\n        }\n        nd -> push();\n        _add_val(x, a,\
    \ b, nd ->  left, l, (l + r) >> 1);\n        _add_val(x, a, b, nd -> right, (l\
    \ + r) >> 1, r);\n        nd -> update();\n    }\n\n    void _update_val(long\
    \ long x, int a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <=\
    \ a) return;\n        if (a <= l && r <= b) {\n            nd -> updateall(x);\n\
    \            return;\n        }\n        nd -> push();\n        _update_val(x,\
    \ a, b, nd ->  left, l, (l + r) >> 1);\n        _update_val(x, a, b, nd -> right,\
    \ (l + r) >> 1, r);\n        nd -> update();\n    }\n\n    long long _query_max(int\
    \ a, int b, Node *nd, int l, int r) {\n        if (b <= l || r <= a) return -INF;\n\
    \        if (a <= l && r <= b) return nd -> max_v;\n        nd -> push();\n  \
    \      long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);\n      \
    \  long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);\n        return\
    \ max(lv, rv);\n    }\n\n    long long _query_min(int a, int b, Node *nd, int\
    \ l, int r) {\n        if (b <= l || r <= a) return INF;\n        if (a <= l &&\
    \ r <= b) return nd -> min_v;\n        nd -> push();\n        long long lv = _query_min(a,\
    \ b, nd ->  left, l, (l + r) >> 1);\n        long long rv = _query_min(a, b, nd\
    \ -> right, (l + r) >> 1, r);\n        return min(lv, rv);\n    }\n\n    long\
    \ long _query_sum(int a, int b, Node *nd, int l, int r) {\n        if (b <= l\
    \ || r <= a) return 0;\n        if (a <= l && r <= b) return nd -> sum;\n    \
    \    nd -> push();\n        long long lv = _query_sum(a, b, nd ->  left, l, (l\
    \ + r) >> 1);\n        long long rv = _query_sum(a, b, nd -> right, (l + r) >>\
    \ 1, r);\n        return lv + rv;\n    }\n\n    SegmentTreeBeats(int n, long long\
    \ val = 0) : n(n) {\n        n0 = 1; while (n0 < n) n0 <<= 1;\n        Node *nds\
    \ = new Node[2 * n0];\n        root = nds;\n        nds[0].len = n0;\n       \
    \ for (int i = 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n\
    \            nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len =\
    \ nds[2 * i + 2].len = nds[i].len >> 1;\n        }\n        for (int i = 0; i\
    \ <  n; ++i) nds[n0 - 1 + i].init(val);\n        for (int i = n; i < n0; ++i)\
    \ nds[n0 - 1 + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n\n    SegmentTreeBeats(const vector<long long> &v) : n((int)v.size())\
    \ {\n        n0 = 1; while (n0 < n) n0 <<= 1;\n        Node *nds = new Node[2\
    \ * n0];\n        root = nds;\n        nds[0].len = n0;\n        for (int i =\
    \ 0; i < n0 - 1; ++i) {\n            nds[i].left = &nds[2 * i + 1];\n        \
    \    nds[i].right = &nds[2 * i + 2];\n            nds[2 * i + 1].len = nds[2 *\
    \ i + 2].len = nds[i].len >> 1;\n        }\n        for (int i = 0; i <  n; ++i)\
    \ nds[n0 - 1 + i].init(v[i]);\n        for (int i = n; i < n0; ++i) nds[n0 - 1\
    \ + i].init_empty();\n        for (int i = n0 - 2; i >= 0; i--) nds[i].update();\n\
    \    }\n\n    void update_min(int a, int b, long long x) { _update_min(x, a, b,\
    \ root, 0, n0); }\n    void update_max(int a, int b, long long x) { _update_max(x,\
    \ a, b, root, 0, n0); }\n    void    add_val(int a, int b, long long x) {    _add_val(x,\
    \ a, b, root, 0, n0); }\n    void update_val(int a, int b, long long x) { _update_val(x,\
    \ a, b, root, 0, n0); }\n    long long query_max(int a, int b) { return _query_max(a,\
    \ b, root, 0, n0); }\n    long long query_min(int a, int b) { return _query_min(a,\
    \ b, root, 0, n0); }\n    long long query_sum(int a, int b) { return _query_sum(a,\
    \ b, root, 0, n0); }\n};\n// clang-format on\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/segmenttree/segmenttreebeats.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/rangechminchmaxaddrangesum.test.cpp
documentation_of: datastructure/segmenttree/segmenttreebeats.hpp
layout: document
redirect_from:
- /library/datastructure/segmenttree/segmenttreebeats.hpp
- /library/datastructure/segmenttree/segmenttreebeats.hpp.html
title: Segment Tree Beats
---
## 概要

区間`chmin`, 区間`chmax`などができるデータ構造.

* <https://codeforces.com/blog/entry/57319>
* <https://smijake3.hatenablog.com/entry/2019/04/28/021457>
* <https://gist.github.com/tjkendev/20e7f96b9262f7a5d739bdc978c075bd>

## 計算量

* 構築 : $O(n)$
* クエリ : $O(\log n)$

## 使用例

* `SegmentTreeBeats seg(n, e)` : $n$要素の$e$で初期化.
* `SegmentTreeBeats seg(v)` : $v$で初期化.
* `seg.update_min(l, r, x)` : 半開区間$[l, r)$を$x$に`chmin`.
* `seg.update_max(l, r, x)` : 半開区間$[l, r)$を$x$に`chmax`.
* `seg.add_val(l, r, x)` : 半開区間$[l, r)$に$x$を加算.
* `seg.update_val(l, r, x)` : 半開区間$[l, r)$を$x$に変更.
* `seg.query_max(l, r)` : 半開区間$[l, r)$の最大値クエリ.
* `seg.query_min(l, r)` : 半開区間$[l, r)$の最小値クエリ.
* `seg.query_sum(l, r)` : 半開区間$[l, r)$の総和クエリ.
