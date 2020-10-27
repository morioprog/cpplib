## 概要

モノイドに対する区間更新区間取得を管理するデータ構造.

以下の 3 つの条件を満たすときに使える.

1. $g(f(a, b), c) = f(g(a, c), g(b, c))$
   - もしくは, $g(f(a, b), p(c, d)) = f(g(a, p(c, d / 2)), g(b, p(c, d / 2)))$
1. $g(g(a, b), c) = g(a, h(b, c))$
1. $g(a, id_{om}) = a$

## 計算量

- 構築 : $O(n)$
- クエリ : $O(\log n)$

## 使用例

- `auto seg = make_segtree(n, id_m, id_om, f, g, h, p)` : $n$要素の遅延セグメント木.
- `auto seg = make_segtree(v, id_m, id_om, f, g, h, p)` : $v$で初期化された遅延セグメント木.
- `seg.update(l, r, x)` : 半開区間$[l, r)$の更新クエリ.
- `seg.query(l, r)` : 半開区間$[l, r)$の取得クエリ.
- `seg[k]` : 半開区間$[k, k + 1)$の取得クエリ.
- `seg.print()` : 各要素の値をデバッグ出力.

### 引数について

- `id_m` : 要素の単位元.
- `id_om` : 作用素の単位元.
- `f` : 要素と要素をマージする関数.
- `g` : 要素と作用素をマージする関数.
- `h` : 作用素と作用素をマージする関数.
- `p` : $p(x, n) = g(x, x, \ldots, x) [x$が$n$個$]$なる$p$.

## 典型

パラメータを適宜変更すること.

- 区間更新の際の作用素の単位元`ID_OM`

### 区間加算・区間和

```cpp
using lint = long long;
using M = lint;
auto f = [](M a, M b) -> M { return a + b; };
auto p = [](M a, int b) -> M { return a * b; };
auto seg = make_segtree(N, M(0), M(0), f, f, f, p);
```

### 区間加算・区間最小

```cpp
using lint = long long;
using M = lint;
auto f = [](M a, M b) -> M { return min(a, b); };
auto g = [](M a, M b) -> M { return a + b; };
auto p = [](M a, int b) -> M { return a; };
auto seg = make_segtree(N, M(4e18), M(0), f, g, g, p);
```

### 区間更新・区間和

```cpp
using lint = long long;
using M = lint;
const M ID_OM(4e18);
auto f = [](M a, M b) -> M { return a + b; };
auto g = [](M a, M b) -> M { return b == ID_OM ? a : b; };
auto p = [](M a, int b) -> M { return a * b; };
auto seg = make_segtree(N, M(0), ID_OM, f, g, g, p);
```

### 区間更新・区間最小

```cpp
using lint = long long;
using M = lint;
const M ID_OM(4e18);
auto f = [](M a, M b) -> M { return min(a, b); };
auto g = [](M a, M b) -> M { return b == ID_OM ? a : b; };
auto p = [](M a, int b) -> M { return a; };
auto seg = make_segtree(N, M(4e18), ID_OM, f, g, g, p);
```
