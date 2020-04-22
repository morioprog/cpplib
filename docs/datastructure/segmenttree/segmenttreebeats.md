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
