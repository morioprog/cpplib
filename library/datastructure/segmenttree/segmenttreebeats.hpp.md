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


# :heavy_check_mark: Segment Tree Beats <small>(datastructure/segmenttree/segmenttreebeats.hpp)</small>

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#23b0293042a380c2b90b74c55c0e1d22">datastructure/segmenttree</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/segmenttree/segmenttreebeats.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-23 06:04:07+09:00




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


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo/rangechminchmaxaddrangesum.test.cpp.html">test/yosupo/rangechminchmaxaddrangesum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
* @brief Segment Tree Beats
* @docs docs/datastructure/segmenttree/segmenttreebeats.md
*/

struct SegmentTreeBeats {
    static const long long INF = 1LL << 60;
    struct Node {
        Node *left, *right;
        long long max_v, smax_v, max_c;
        long long min_v, smin_v, min_c;
        long long sum;
        long long len, ladd, lval;

        Node() : left(0), right(0), ladd(0), lval(INF) {}

        void init(long long x) {
            max_v = min_v = sum = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = 1;
        }

        void init_empty() {
            max_v = smax_v = -INF;
            min_v = smin_v = INF;
            max_c = min_c = 0;
        }

        void update_max(long long x) {
            sum += (x - max_v) * max_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) max_v = smin_v = x;
            else                      max_v = x;
            if (lval != INF and x < lval) lval = x;
        }

        void update_min(long long x) {
            sum += (x - min_v) * min_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) min_v = smax_v = x;
            else                      min_v = x;
            if (lval != INF and lval < x) lval = x;
        }

        void addall(long long x) {
            max_v += x;
            if (smax_v != -INF) smax_v += x;
            min_v += x;
            if (smin_v != INF) smin_v += x;
            sum += len * x;
            if (lval != INF) lval += x;
            else             ladd += x;
        }

        void updateall(long long x) {
            max_v = min_v = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = len;
            sum = len * x;
            lval = x; ladd = 0;
        }

        void push() {
            if (lval != INF) {
                 left -> updateall(lval);
                right -> updateall(lval);
                lval = INF;
                return;
            }
            if (ladd != 0) {
                 left -> addall(ladd);
                right -> addall(ladd);
                ladd = 0;
            }
            if (max_v < left -> max_v)   left -> update_max(max_v);
            if (left -> min_v < min_v)   left -> update_min(min_v);
            if (max_v < right -> max_v) right -> update_max(max_v);
            if (right -> min_v < min_v) right -> update_min(min_v);
        }

        void update() {
            sum = left -> sum + right -> sum;
            if (left -> max_v < right -> max_v) {
                max_v = right -> max_v;
                max_c = right -> max_c;
                smax_v = max(left -> max_v, right -> smax_v);
            } else if (left -> max_v > right -> max_v) {
                max_v = left -> max_v;
                max_c = left -> max_c;
                smax_v = max(left -> smax_v, right -> max_v);
            } else {
                max_v = left -> max_v;
                max_c = left -> max_c + right -> max_c;
                smax_v = max(left -> smax_v, right -> smax_v);
            }
            if (left -> min_v < right -> min_v) {
                min_v = left -> min_v;
                min_c = left -> min_c;
                smin_v = min(left -> smin_v, right -> min_v);
            } else if (left -> min_v > right -> min_v) {
                min_v = right -> min_v;
                min_c = right -> min_c;
                smin_v = min(left -> min_v, right -> smin_v);
            } else {
                min_v = left -> min_v;
                min_c = left -> min_c + right -> min_c;
                smin_v = min(left -> smin_v, right -> smin_v);
            }
        }
    };

    int n, n0;
    Node *root;

    void _update_min(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || nd -> max_v <= x) return;
        if (a <= l && r <= b && nd -> smax_v < x) {
            nd -> update_max(x);
            return;
        }
        nd -> push();
        _update_min(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_max(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || x <= nd -> min_v) return;
        if (a <= l && r <= b && x < nd -> smin_v) {
            nd -> update_min(x);
            return;
        }
        nd -> push();
        _update_max(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_max(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _add_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> addall(x);
            return;
        }
        nd -> push();
        _add_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _add_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> updateall(x);
            return;
        }
        nd -> push();
        _update_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    long long _query_max(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return -INF;
        if (a <= l && r <= b) return nd -> max_v;
        nd -> push();
        long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);
        return max(lv, rv);
    }

    long long _query_min(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return nd -> min_v;
        nd -> push();
        long long lv = _query_min(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_min(a, b, nd -> right, (l + r) >> 1, r);
        return min(lv, rv);
    }

    long long _query_sum(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return nd -> sum;
        nd -> push();
        long long lv = _query_sum(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_sum(a, b, nd -> right, (l + r) >> 1, r);
        return lv + rv;
    }

    SegmentTreeBeats(int n, long long val = 0) : n(n) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(val);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    SegmentTreeBeats(const vector<long long> &v) : n((int)v.size()) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(v[i]);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    void update_min(int a, int b, long long x) { _update_min(x, a, b, root, 0, n0); }
    void update_max(int a, int b, long long x) { _update_max(x, a, b, root, 0, n0); }
    void    add_val(int a, int b, long long x) {    _add_val(x, a, b, root, 0, n0); }
    void update_val(int a, int b, long long x) { _update_val(x, a, b, root, 0, n0); }
    long long query_max(int a, int b) { return _query_max(a, b, root, 0, n0); }
    long long query_min(int a, int b) { return _query_min(a, b, root, 0, n0); }
    long long query_sum(int a, int b) { return _query_sum(a, b, root, 0, n0); }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "datastructure/segmenttree/segmenttreebeats.hpp"
/**
* @brief Segment Tree Beats
* @docs docs/datastructure/segmenttree/segmenttreebeats.md
*/

struct SegmentTreeBeats {
    static const long long INF = 1LL << 60;
    struct Node {
        Node *left, *right;
        long long max_v, smax_v, max_c;
        long long min_v, smin_v, min_c;
        long long sum;
        long long len, ladd, lval;

        Node() : left(0), right(0), ladd(0), lval(INF) {}

        void init(long long x) {
            max_v = min_v = sum = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = 1;
        }

        void init_empty() {
            max_v = smax_v = -INF;
            min_v = smin_v = INF;
            max_c = min_c = 0;
        }

        void update_max(long long x) {
            sum += (x - max_v) * max_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) max_v = smin_v = x;
            else                      max_v = x;
            if (lval != INF and x < lval) lval = x;
        }

        void update_min(long long x) {
            sum += (x - min_v) * min_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) min_v = smax_v = x;
            else                      min_v = x;
            if (lval != INF and lval < x) lval = x;
        }

        void addall(long long x) {
            max_v += x;
            if (smax_v != -INF) smax_v += x;
            min_v += x;
            if (smin_v != INF) smin_v += x;
            sum += len * x;
            if (lval != INF) lval += x;
            else             ladd += x;
        }

        void updateall(long long x) {
            max_v = min_v = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = len;
            sum = len * x;
            lval = x; ladd = 0;
        }

        void push() {
            if (lval != INF) {
                 left -> updateall(lval);
                right -> updateall(lval);
                lval = INF;
                return;
            }
            if (ladd != 0) {
                 left -> addall(ladd);
                right -> addall(ladd);
                ladd = 0;
            }
            if (max_v < left -> max_v)   left -> update_max(max_v);
            if (left -> min_v < min_v)   left -> update_min(min_v);
            if (max_v < right -> max_v) right -> update_max(max_v);
            if (right -> min_v < min_v) right -> update_min(min_v);
        }

        void update() {
            sum = left -> sum + right -> sum;
            if (left -> max_v < right -> max_v) {
                max_v = right -> max_v;
                max_c = right -> max_c;
                smax_v = max(left -> max_v, right -> smax_v);
            } else if (left -> max_v > right -> max_v) {
                max_v = left -> max_v;
                max_c = left -> max_c;
                smax_v = max(left -> smax_v, right -> max_v);
            } else {
                max_v = left -> max_v;
                max_c = left -> max_c + right -> max_c;
                smax_v = max(left -> smax_v, right -> smax_v);
            }
            if (left -> min_v < right -> min_v) {
                min_v = left -> min_v;
                min_c = left -> min_c;
                smin_v = min(left -> smin_v, right -> min_v);
            } else if (left -> min_v > right -> min_v) {
                min_v = right -> min_v;
                min_c = right -> min_c;
                smin_v = min(left -> min_v, right -> smin_v);
            } else {
                min_v = left -> min_v;
                min_c = left -> min_c + right -> min_c;
                smin_v = min(left -> smin_v, right -> smin_v);
            }
        }
    };

    int n, n0;
    Node *root;

    void _update_min(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || nd -> max_v <= x) return;
        if (a <= l && r <= b && nd -> smax_v < x) {
            nd -> update_max(x);
            return;
        }
        nd -> push();
        _update_min(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_max(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || x <= nd -> min_v) return;
        if (a <= l && r <= b && x < nd -> smin_v) {
            nd -> update_min(x);
            return;
        }
        nd -> push();
        _update_max(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_max(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _add_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> addall(x);
            return;
        }
        nd -> push();
        _add_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _add_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> updateall(x);
            return;
        }
        nd -> push();
        _update_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    long long _query_max(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return -INF;
        if (a <= l && r <= b) return nd -> max_v;
        nd -> push();
        long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);
        return max(lv, rv);
    }

    long long _query_min(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return nd -> min_v;
        nd -> push();
        long long lv = _query_min(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_min(a, b, nd -> right, (l + r) >> 1, r);
        return min(lv, rv);
    }

    long long _query_sum(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return nd -> sum;
        nd -> push();
        long long lv = _query_sum(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_sum(a, b, nd -> right, (l + r) >> 1, r);
        return lv + rv;
    }

    SegmentTreeBeats(int n, long long val = 0) : n(n) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(val);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    SegmentTreeBeats(const vector<long long> &v) : n((int)v.size()) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(v[i]);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    void update_min(int a, int b, long long x) { _update_min(x, a, b, root, 0, n0); }
    void update_max(int a, int b, long long x) { _update_max(x, a, b, root, 0, n0); }
    void    add_val(int a, int b, long long x) {    _add_val(x, a, b, root, 0, n0); }
    void update_val(int a, int b, long long x) { _update_val(x, a, b, root, 0, n0); }
    long long query_max(int a, int b) { return _query_max(a, b, root, 0, n0); }
    long long query_min(int a, int b) { return _query_min(a, b, root, 0, n0); }
    long long query_sum(int a, int b) { return _query_sum(a, b, root, 0, n0); }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

