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
