---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.test.cpp
    title: test/aoj/ALDS1_14_D.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/suffixarray.md
    document_title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (Suffix Array)"
    links: []
  bundledCode: "#line 1 \"string/suffixarray.hpp\"\n/**\n* @brief \u63A5\u5C3E\u8F9E\
    \u914D\u5217 (Suffix Array)\n* @docs docs/string/suffixarray.md\n*/\n\nstruct\
    \ SuffixArray {\n    vector<int> sa;\n    string s;\n    SuffixArray(string &s)\n\
    \        : s(s) {\n        sa.resize(s.size());\n        iota(begin(sa), end(sa),\
    \ 0);\n        sort(begin(sa), end(sa), [&](int a, int b) {\n            return\
    \ (s[a] == s[b]) ? a > b : s[a] < s[b];\n        });\n        vector<int> cls(s.size()),\
    \ c(s.begin(), s.end()), cnt(s.size());\n        for (int l = 1; l < s.size();\
    \ l <<= 1) {\n            for (int i = 0; i < s.size(); i++) {\n             \
    \   if (i > 0 and c[sa[i - 1]] == c[sa[i]] and sa[i - 1] + l < s.size() and c[sa[i\
    \ - 1] + l / 2] == c[sa[i] + l / 2]) {\n                    cls[sa[i]] = cls[sa[i\
    \ - 1]];\n                } else {\n                    cls[sa[i]] = i;\n    \
    \            }\n            }\n            iota(begin(cnt), end(cnt), 0);\n  \
    \          copy(begin(sa), end(sa), begin(c));\n            for (int i = 0; i\
    \ < s.size(); i++) {\n                int s1 = c[i] - l;\n                if (s1\
    \ >= 0) sa[cnt[cls[s1]]++] = s1;\n            }\n            cls.swap(c);\n  \
    \      }\n    }\n    bool lt_substr(const string &t, int si = 0, int ti = 0) {\n\
    \        int sn = (int)s.size(), tn = (int)t.size();\n        while (si < sn and\
    \ ti < tn) {\n            if (s[si] < t[ti]) return true;\n            if (s[si]\
    \ > t[ti]) return false;\n            ++si, ++ti;\n        }\n        return si\
    \ >= sn and ti < tn;\n    }\n    int lower_bound(const string &t) {\n        int\
    \ low = -1, high = (int)sa.size();\n        while (high - low > 1) {\n       \
    \     int mid = (low + high) / 2;\n            if (lt_substr(t, sa[mid]))\n  \
    \              low = mid;\n            else\n                high = mid;\n   \
    \     }\n        return high;\n    }\n    pair<int, int> lower_upper_bound(string\
    \ &t) {\n        int idx = lower_bound(t);\n        int low = idx - 1, high =\
    \ (int)sa.size();\n        t.back()++;\n        while (high - low > 1) {\n   \
    \         int mid = (low + high) / 2;\n            if (lt_substr(t, sa[mid]))\n\
    \                low = mid;\n            else\n                high = mid;\n \
    \       }\n        --t.back();\n        return make_pair(idx, high);\n    }\n\
    \    void print() {\n        for (int i = 0; i < sa.size(); ++i) {\n         \
    \   cerr << i << \" : \" << s.substr(sa[i]) << endl;\n        }\n    }\n};\n"
  code: "/**\n* @brief \u63A5\u5C3E\u8F9E\u914D\u5217 (Suffix Array)\n* @docs docs/string/suffixarray.md\n\
    */\n\nstruct SuffixArray {\n    vector<int> sa;\n    string s;\n    SuffixArray(string\
    \ &s)\n        : s(s) {\n        sa.resize(s.size());\n        iota(begin(sa),\
    \ end(sa), 0);\n        sort(begin(sa), end(sa), [&](int a, int b) {\n       \
    \     return (s[a] == s[b]) ? a > b : s[a] < s[b];\n        });\n        vector<int>\
    \ cls(s.size()), c(s.begin(), s.end()), cnt(s.size());\n        for (int l = 1;\
    \ l < s.size(); l <<= 1) {\n            for (int i = 0; i < s.size(); i++) {\n\
    \                if (i > 0 and c[sa[i - 1]] == c[sa[i]] and sa[i - 1] + l < s.size()\
    \ and c[sa[i - 1] + l / 2] == c[sa[i] + l / 2]) {\n                    cls[sa[i]]\
    \ = cls[sa[i - 1]];\n                } else {\n                    cls[sa[i]]\
    \ = i;\n                }\n            }\n            iota(begin(cnt), end(cnt),\
    \ 0);\n            copy(begin(sa), end(sa), begin(c));\n            for (int i\
    \ = 0; i < s.size(); i++) {\n                int s1 = c[i] - l;\n            \
    \    if (s1 >= 0) sa[cnt[cls[s1]]++] = s1;\n            }\n            cls.swap(c);\n\
    \        }\n    }\n    bool lt_substr(const string &t, int si = 0, int ti = 0)\
    \ {\n        int sn = (int)s.size(), tn = (int)t.size();\n        while (si <\
    \ sn and ti < tn) {\n            if (s[si] < t[ti]) return true;\n           \
    \ if (s[si] > t[ti]) return false;\n            ++si, ++ti;\n        }\n     \
    \   return si >= sn and ti < tn;\n    }\n    int lower_bound(const string &t)\
    \ {\n        int low = -1, high = (int)sa.size();\n        while (high - low >\
    \ 1) {\n            int mid = (low + high) / 2;\n            if (lt_substr(t,\
    \ sa[mid]))\n                low = mid;\n            else\n                high\
    \ = mid;\n        }\n        return high;\n    }\n    pair<int, int> lower_upper_bound(string\
    \ &t) {\n        int idx = lower_bound(t);\n        int low = idx - 1, high =\
    \ (int)sa.size();\n        t.back()++;\n        while (high - low > 1) {\n   \
    \         int mid = (low + high) / 2;\n            if (lt_substr(t, sa[mid]))\n\
    \                low = mid;\n            else\n                high = mid;\n \
    \       }\n        --t.back();\n        return make_pair(idx, high);\n    }\n\
    \    void print() {\n        for (int i = 0; i < sa.size(); ++i) {\n         \
    \   cerr << i << \" : \" << s.substr(sa[i]) << endl;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffixarray.hpp
  requiredBy: []
  timestamp: '2020-08-25 21:33:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_D.test.cpp
documentation_of: string/suffixarray.hpp
layout: document
redirect_from:
- /library/string/suffixarray.hpp
- /library/string/suffixarray.hpp.html
title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (Suffix Array)"
---
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
