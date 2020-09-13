## 概要

> わっけわかんねえほど沢山の制約ドパァな問題を解く一般的なテク

条件を読ませて, 張るべき辺を返す.

## 使用例

- `moyasu_umeru<int> mu(V)` : $V$頂点のグラフを定義.
  - コストの型 : `int`
- `mu.red_blue_penalty(r, b, pena)` : 頂点$r$を赤く, 頂点$b$を青く塗ったら罰金$pena$.
- `mu.red_penalty(r, pena)` : 頂点$r$を赤く塗ったら罰金$pena$.
- `mu.blue_penalty(b, pena)` : 頂点$b$を赤く塗ったら罰金$pena$.
- `mu.red_reward(r, rwrd)` : 頂点$r$を赤く塗ったら賞金$rwrd$.
- `mu.blue_reward(b, rwrd)` : 頂点$b$を青く塗ったら賞金$rwrd$.
- `mu.reds_reward(v_r, rwrd)` : 頂点群$v_r$を全て赤く塗ったら賞金$rwrd$.
- `mu.blues_reward(v_b, rwrd)` : 頂点群$v_b$を青て赤く塗ったら賞金$rwrd$.
- `mu.edges` : 張るべき辺.
- `mu.margin` : 無条件で得られる賞金.
