---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/util/jury.md
    document_title: "\u30A4\u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u554F\u984C"
    links: []
  bundledCode: "#line 1 \"util/jury.hpp\"\n/**\n* @brief \u30A4\u30F3\u30BF\u30E9\u30AF\
    \u30C6\u30A3\u30D6\u554F\u984C\n* @docs docs/util/jury.md\n*/\n\ntemplate <typename\
    \ T, typename R, int QMX>\nstruct Jury {\n    int query_cnt;\n    map<T, R> memo;\n\
    \    T N;\n    Jury()\n        : query_cnt(0) {\n        // N = rand();\n#ifdef\
    \ LOCAL\n        cerr << \"N : \" << N << endl;\n#endif\n    }\n    Jury(T _N)\n\
    \        : query_cnt(0) {\n        N = _N;\n#ifdef LOCAL\n        cerr << \"N\
    \ : \" << N << endl;\n#endif\n    }\n    R query(T X) {\n        if (memo.count(X))\
    \ return memo[X];\n        if (++query_cnt > QMX) {\n            cerr << \"Query\
    \ Limit Exceeded\" << endl;\n            exit(1);\n        }\n#ifdef LOCAL\n \
    \       cerr << query_cnt << \" : \" << X << endl;\n        // return memo[n]\
    \ = ...;\n#else\n        // cout << \"? \" << X << endl;\n        // int rsp;\
    \  cin >> rsp;\n        // return memo[n] = rsp;\n#endif\n    }\n    void answer(T\
    \ X) {\n#ifdef LOCAL\n        if (X == N) {\n            cerr << \"AC : \" <<\
    \ X << endl;\n        } else {\n            cerr << \"WA : \" << X << \" \" <<\
    \ N << endl;\n        }\n        // exit(0);\n#else\n        // cout << \"! \"\
    \ << X << endl;\n        exit(0);\n#endif\n    }\n};\n"
  code: "/**\n* @brief \u30A4\u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u554F\u984C\
    \n* @docs docs/util/jury.md\n*/\n\ntemplate <typename T, typename R, int QMX>\n\
    struct Jury {\n    int query_cnt;\n    map<T, R> memo;\n    T N;\n    Jury()\n\
    \        : query_cnt(0) {\n        // N = rand();\n#ifdef LOCAL\n        cerr\
    \ << \"N : \" << N << endl;\n#endif\n    }\n    Jury(T _N)\n        : query_cnt(0)\
    \ {\n        N = _N;\n#ifdef LOCAL\n        cerr << \"N : \" << N << endl;\n#endif\n\
    \    }\n    R query(T X) {\n        if (memo.count(X)) return memo[X];\n     \
    \   if (++query_cnt > QMX) {\n            cerr << \"Query Limit Exceeded\" <<\
    \ endl;\n            exit(1);\n        }\n#ifdef LOCAL\n        cerr << query_cnt\
    \ << \" : \" << X << endl;\n        // return memo[n] = ...;\n#else\n        //\
    \ cout << \"? \" << X << endl;\n        // int rsp;  cin >> rsp;\n        // return\
    \ memo[n] = rsp;\n#endif\n    }\n    void answer(T X) {\n#ifdef LOCAL\n      \
    \  if (X == N) {\n            cerr << \"AC : \" << X << endl;\n        } else\
    \ {\n            cerr << \"WA : \" << X << \" \" << N << endl;\n        }\n  \
    \      // exit(0);\n#else\n        // cout << \"! \" << X << endl;\n        exit(0);\n\
    #endif\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: util/jury.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:20:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/jury.hpp
layout: document
redirect_from:
- /library/util/jury.hpp
- /library/util/jury.hpp.html
title: "\u30A4\u30F3\u30BF\u30E9\u30AF\u30C6\u30A3\u30D6\u554F\u984C"
---
## 概要

インタラクティブ問題の大枠.

## 使用例

* `auto jury = Jury<int, bool, 20>()` : Juryを準備.
  * `jury.query(n)` : 質問クエリ.
  * `jury.answer(x)` : 解答クエリ.
    * 実行したら`exit(0)`で終了するようにするべき.
