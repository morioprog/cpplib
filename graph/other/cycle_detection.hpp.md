---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/13.test.cpp
    title: test/yukicoder/13.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/other/cycle_detection.md
    document_title: "\u9589\u8DEF\u691C\u51FA"
    links: []
  bundledCode: "#line 1 \"graph/other/cycle_detection.hpp\"\n/**\n* @brief \u9589\u8DEF\
    \u691C\u51FA\n* @docs docs/graph/other/cycle_detection.md\n*/\n\ntemplate <typename\
    \ T>\nvector<int> cycle_detection(const Graph<T> &g, bool directed = false) {\n\
    \    vector<int> cycle, color(g.V, 0);\n    auto dfs = [&](auto &&f, int cur,\
    \ int prv, int &frm) -> bool {\n        color[cur] = 1;\n        for (auto &nxt\
    \ : g.mat[cur]) {\n            if (not directed and nxt == prv) continue;\n  \
    \          if (color[nxt] == 0) {\n                if (f(f, nxt, cur, frm)) {\n\
    \                    cycle.emplace_back(cur);\n                    return frm\
    \ != cur;\n                } else if (not cycle.empty())\n                   \
    \ return false;\n            } else if (color[nxt] == 1) {\n                cycle.emplace_back(cur);\n\
    \                frm = nxt;\n                return true;\n            }\n   \
    \     }\n        color[cur] = 2;\n        return false;\n    };\n    int frm =\
    \ -1;\n    for (int i = 0; i < g.V; ++i) {\n        if (color[i] == 0) {\n   \
    \         dfs(dfs, i, -1, frm);\n            if (not cycle.empty()) {\n      \
    \          reverse(cycle.begin(), cycle.end());\n                break;\n    \
    \        }\n        }\n    }\n    return cycle;\n}\n"
  code: "/**\n* @brief \u9589\u8DEF\u691C\u51FA\n* @docs docs/graph/other/cycle_detection.md\n\
    */\n\ntemplate <typename T>\nvector<int> cycle_detection(const Graph<T> &g, bool\
    \ directed = false) {\n    vector<int> cycle, color(g.V, 0);\n    auto dfs = [&](auto\
    \ &&f, int cur, int prv, int &frm) -> bool {\n        color[cur] = 1;\n      \
    \  for (auto &nxt : g.mat[cur]) {\n            if (not directed and nxt == prv)\
    \ continue;\n            if (color[nxt] == 0) {\n                if (f(f, nxt,\
    \ cur, frm)) {\n                    cycle.emplace_back(cur);\n               \
    \     return frm != cur;\n                } else if (not cycle.empty())\n    \
    \                return false;\n            } else if (color[nxt] == 1) {\n  \
    \              cycle.emplace_back(cur);\n                frm = nxt;\n        \
    \        return true;\n            }\n        }\n        color[cur] = 2;\n   \
    \     return false;\n    };\n    int frm = -1;\n    for (int i = 0; i < g.V; ++i)\
    \ {\n        if (color[i] == 0) {\n            dfs(dfs, i, -1, frm);\n       \
    \     if (not cycle.empty()) {\n                reverse(cycle.begin(), cycle.end());\n\
    \                break;\n            }\n        }\n    }\n    return cycle;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/other/cycle_detection.hpp
  requiredBy: []
  timestamp: '2020-08-29 18:48:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/13.test.cpp
documentation_of: graph/other/cycle_detection.hpp
layout: document
redirect_from:
- /library/graph/other/cycle_detection.hpp
- /library/graph/other/cycle_detection.hpp.html
title: "\u9589\u8DEF\u691C\u51FA"
---
## 概要

閉路検出.

### 計算量

$O(E + V)$

## 使用例

- `cycle_detection(g)` : グラフ`g`の閉路上の頂点を順番に返す.
  - 閉路がないなら`vector<int>()`を返す.
