---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/rollinghash.md
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
    links: []
  bundledCode: "#line 1 \"string/rollinghash.hpp\"\n/**\n* @brief \u30ED\u30FC\u30EA\
    \u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n* @docs docs/string/rollinghash.md\n*/\n\
    \nusing hash_type = unsigned long long;\ntemplate <int mod, int base = 10007>\n\
    struct RollingHash {\n    vector<hash_type> hsh, pwr;\n    hash_type umod(hash_type\
    \ n) { return (n % mod + mod) % mod; }\n    RollingHash() {}\n    RollingHash(const\
    \ string &s) {\n        int sz = (int)s.size();\n        hsh.assign(sz + 1, 0);\n\
    \        pwr.assign(sz + 1, 0);\n        pwr[0] = 1;\n        for (int i = 0;\
    \ i < sz; ++i) {\n            if (sz > i) hsh[i + 1] = umod(hsh[i] * base + s[i]);\n\
    \            pwr[i + 1] = umod(pwr[i] * base);\n        }\n    }\n    // [l, r)\n\
    \    hash_type get(int l, int r) {\n        return umod(hsh[r] % mod + mod - hsh[l]\
    \ * pwr[r - l] % mod);\n    }\n    // h1 <- h2\n    hash_type join(hash_type h1,\
    \ hash_type h2, int h2_sz) {\n        return umod(h1 * pwr[h2_sz] + h2);\n   \
    \ }\n    // [idx, len_s) + [0, idx)\n    hash_type rotate(hash_type idx, int len_s)\
    \ {\n        return join(get(idx, len_s), get(0, idx), idx);\n    }\n};\nusing\
    \ RH1 = RollingHash<(int)1e9 + 7>;\nusing RH2 = RollingHash<(int)1e9 + 9>;\nusing\
    \ RH  = tuple<RH1, RH2>;\nusing H   = tuple<hash_type, hash_type>;\nRH init(const\
    \ string &s) {\n    return make_tuple(RH1(s), RH2(s));\n}\nH get(RH &rh, int l,\
    \ int r) {\n    return make_tuple(get<0>(rh).get(l, r), get<1>(rh).get(l, r));\n\
    }\nH rotate(RH &rh, int n, int sz) {\n    return make_tuple(get<0>(rh).rotate(n,\
    \ sz), get<1>(rh).rotate(n, sz));\n}\n"
  code: "/**\n* @brief \u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\n* @docs\
    \ docs/string/rollinghash.md\n*/\n\nusing hash_type = unsigned long long;\ntemplate\
    \ <int mod, int base = 10007>\nstruct RollingHash {\n    vector<hash_type> hsh,\
    \ pwr;\n    hash_type umod(hash_type n) { return (n % mod + mod) % mod; }\n  \
    \  RollingHash() {}\n    RollingHash(const string &s) {\n        int sz = (int)s.size();\n\
    \        hsh.assign(sz + 1, 0);\n        pwr.assign(sz + 1, 0);\n        pwr[0]\
    \ = 1;\n        for (int i = 0; i < sz; ++i) {\n            if (sz > i) hsh[i\
    \ + 1] = umod(hsh[i] * base + s[i]);\n            pwr[i + 1] = umod(pwr[i] * base);\n\
    \        }\n    }\n    // [l, r)\n    hash_type get(int l, int r) {\n        return\
    \ umod(hsh[r] % mod + mod - hsh[l] * pwr[r - l] % mod);\n    }\n    // h1 <- h2\n\
    \    hash_type join(hash_type h1, hash_type h2, int h2_sz) {\n        return umod(h1\
    \ * pwr[h2_sz] + h2);\n    }\n    // [idx, len_s) + [0, idx)\n    hash_type rotate(hash_type\
    \ idx, int len_s) {\n        return join(get(idx, len_s), get(0, idx), idx);\n\
    \    }\n};\nusing RH1 = RollingHash<(int)1e9 + 7>;\nusing RH2 = RollingHash<(int)1e9\
    \ + 9>;\nusing RH  = tuple<RH1, RH2>;\nusing H   = tuple<hash_type, hash_type>;\n\
    RH init(const string &s) {\n    return make_tuple(RH1(s), RH2(s));\n}\nH get(RH\
    \ &rh, int l, int r) {\n    return make_tuple(get<0>(rh).get(l, r), get<1>(rh).get(l,\
    \ r));\n}\nH rotate(RH &rh, int n, int sz) {\n    return make_tuple(get<0>(rh).rotate(n,\
    \ sz), get<1>(rh).rotate(n, sz));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
## 概要

文字列をハッシュとして管理する. ハッシュ値の衝突に注意.

## 計算量

* 構築 : $O(|s|)$
* クエリ : $O(1)$

## 使用例

* `RH rh = init(s)` : 文字列$s$でローリングハッシュを構築.
* `get(rh, l, r)` : 半開区間$[l, r)$のハッシュ値を取得.
* `rotate(rh, idx, len_s)` : 文字列を`idx`の位置でrotateしたものを返す.

## ToDo

* 回文判定
