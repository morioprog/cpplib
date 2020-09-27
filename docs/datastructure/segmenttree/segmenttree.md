## 概要

モノイドに対する 1 点更新区間取得を管理するデータ構造.

### モノイド

以下を満たす代数的構造.

- 結合律 : $f(f(x, y), z) = f(x, f(y, z))$
- 単位元$e$の存在 : $f(x, e) = f(e, x) = x$

## 計算量

- 構築 : $O(n)$
- クエリ : $O(\log n)$

## 使用例

- `auto seg = make_segment_tree(n, [](int a, int b){ return a + b; }, 0)` : 単位元$0$で初期化.
- `auto seg = make_segment_tree(v, [](int a, int b){ return a + b; }, 0)` : `v`で初期化.
- `seg.update(k, x)` : $k$要素目を$x$に変更する.
- `seg.query(l, r)` : 半開区間$[l, r)$のクエリ.
- `seg.query_all()` : 半開区間$[0, sz)$のクエリ.
- `seg.rightmost(check, l = 0)` : 半開区間$[l, sz)$の中で, `check(query(l, r))`が`true`となる最右の$r$を返す.
  - `check(ID)`は`true`である必要がある.
- `seg.leftmost(check, r = sz)` : 半開区間$[0, r)$の中で, `check(query(l, r))`が`true`となる最左の$l$を返す.
  - `check(ID)`は`true`である必要がある.
- `seg.print()` : セグメント木の中身をデバッグ出力.
