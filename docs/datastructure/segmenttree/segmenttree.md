## 概要

モノイドに対する1点更新区間取得を管理するデータ構造.

### モノイド

以下を満たす代数的構造.

* 結合律 : $f(f(x, y), z) = f(x, f(y, z))$
* 単位元$e$の存在 : $f(x, e) = f(e, x) = x$

## 計算量

* 構築 : $O(n)$
* クエリ : $O(\log n)$

## 使用例

* `SegmentTree<int> seg(n, [](int a, int b){ return a + b; }, 0);` : 単位元$0$で初期化.
* `SegmentTree<int> seg(v, [](int a, int b){ return a + b; }, 0);` : `v`で初期化.
* `seg.update(k, x);` : $k$要素目を$x$に変更する.
* `seg.add(k, x);` : $k$要素目に$x$を加算する.
* `seg.query(l, r);` : 半開区間$[l, r)$のクエリ.
* `seg.print();` : セグメント木の中身をデバッグ出力.
