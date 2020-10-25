---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.osa_k.test.cpp
    title: test/aoj/ALDS1_1_C.osa_k.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/prime/osa_k.hpp
    document_title: "osa_k\u6CD5"
    links:
    - https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
  bundledCode: "#line 1 \"math/prime/osa_k.hpp\"\n/**\n* @brief osa_k\u6CD5\n* @docs\
    \ docs/math/prime/osa_k.hpp\n* @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    */\n\nstruct osa_k {\n    int N;\n    vector<int> min_prime;\n    osa_k(int _N)\n\
    \        : N(_N + 1), min_prime(N) {\n        iota(min_prime.begin(), min_prime.end(),\
    \ 0);\n        for (int p = 2; p * p <= N; ++p) {\n            if (min_prime[p]\
    \ != p) continue;\n            for (int i = 2 * p; i <= N; i += p) {\n       \
    \         if (min_prime[i] != i) continue;\n                min_prime[i] = p;\n\
    \            }\n        }\n    }\n    bool is_prime(int x) {\n        assert(x\
    \ <= N);\n        if (x <= 1) return false;\n        return min_prime[x] == x;\n\
    \    }\n    map<int, int> prime_factor(int x) {\n        assert(x <= N);\n   \
    \     map<int, int> pf;\n        while (x > 1) {\n            pf[min_prime[x]]++;\n\
    \            x /= min_prime[x];\n        }\n        return pf;\n    }\n};\n"
  code: "/**\n* @brief osa_k\u6CD5\n* @docs docs/math/prime/osa_k.hpp\n* @see https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409\n\
    */\n\nstruct osa_k {\n    int N;\n    vector<int> min_prime;\n    osa_k(int _N)\n\
    \        : N(_N + 1), min_prime(N) {\n        iota(min_prime.begin(), min_prime.end(),\
    \ 0);\n        for (int p = 2; p * p <= N; ++p) {\n            if (min_prime[p]\
    \ != p) continue;\n            for (int i = 2 * p; i <= N; i += p) {\n       \
    \         if (min_prime[i] != i) continue;\n                min_prime[i] = p;\n\
    \            }\n        }\n    }\n    bool is_prime(int x) {\n        assert(x\
    \ <= N);\n        if (x <= 1) return false;\n        return min_prime[x] == x;\n\
    \    }\n    map<int, int> prime_factor(int x) {\n        assert(x <= N);\n   \
    \     map<int, int> pf;\n        while (x > 1) {\n            pf[min_prime[x]]++;\n\
    \            x /= min_prime[x];\n        }\n        return pf;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime/osa_k.hpp
  requiredBy: []
  timestamp: '2020-08-30 18:59:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C.osa_k.test.cpp
documentation_of: math/prime/osa_k.hpp
layout: document
redirect_from:
- /library/math/prime/osa_k.hpp
- /library/math/prime/osa_k.hpp.html
title: "osa_k\u6CD5"
---
