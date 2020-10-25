---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc106/tasks/abc106_d
  bundledCode: "#line 1 \"test/atcoder/abc157_d.weightedunionfind.cpp\"\n#define IGNORE\n\
    \n// @note uf.size()\u306Everify (\u91CD\u307F\u4ED8\u304DUnionFind)\n\n// #define\
    \ PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\n\n// #include\
    \ \"../../template/main.hpp\"\n// #include \"../../datastructure/unionfind/weightedunionfind.hpp\"\
    \n\nsigned main() {\n\n    int N, M, K;\n    cin >> N >> M >> K;\n\n    WeightedUnionFind<int>\
    \ uf(N);\n\n    vector<vector<int>> frd(N);\n\n    for (int i = 0; i < M; ++i)\
    \ {\n        int A, B;\n        cin >> A >> B;\n        --A, --B;\n        frd[A].emplace_back(B);\n\
    \        frd[B].emplace_back(A);\n        uf.unite(A, B, 0);\n    }\n\n    vector<int>\
    \ res(N);\n    for (int i = 0; i < N; ++i) res[i] = uf.size(i);\n    for (int\
    \ i = 0; i < N; ++i) res[i] -= frd[i].size() + 1;\n    for (int i = 0; i < K;\
    \ ++i) {\n        int A, B;\n        cin >> A >> B;\n        --A, --B;\n     \
    \   if (uf.same(A, B)) {\n            res[A]--;\n            res[B]--;\n     \
    \   }\n    }\n\n    for (int i = 0; i < N; ++i) cout << res[i] << \" \\n\"[i ==\
    \ N - 1];\n\n}\n"
  code: "#define IGNORE\n\n// @note uf.size()\u306Everify (\u91CD\u307F\u4ED8\u304D\
    UnionFind)\n\n// #define PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\
    \n\n// #include \"../../template/main.hpp\"\n// #include \"../../datastructure/unionfind/weightedunionfind.hpp\"\
    \n\nsigned main() {\n\n    int N, M, K;\n    cin >> N >> M >> K;\n\n    WeightedUnionFind<int>\
    \ uf(N);\n\n    vector<vector<int>> frd(N);\n\n    for (int i = 0; i < M; ++i)\
    \ {\n        int A, B;\n        cin >> A >> B;\n        --A, --B;\n        frd[A].emplace_back(B);\n\
    \        frd[B].emplace_back(A);\n        uf.unite(A, B, 0);\n    }\n\n    vector<int>\
    \ res(N);\n    for (int i = 0; i < N; ++i) res[i] = uf.size(i);\n    for (int\
    \ i = 0; i < N; ++i) res[i] -= frd[i].size() + 1;\n    for (int i = 0; i < K;\
    \ ++i) {\n        int A, B;\n        cin >> A >> B;\n        --A, --B;\n     \
    \   if (uf.same(A, B)) {\n            res[A]--;\n            res[B]--;\n     \
    \   }\n    }\n\n    for (int i = 0; i < N; ++i) cout << res[i] << \" \\n\"[i ==\
    \ N - 1];\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: test/atcoder/abc157_d.weightedunionfind.cpp
  requiredBy: []
  timestamp: '2020-08-24 21:05:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc157_d.weightedunionfind.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc157_d.weightedunionfind.cpp
- /library/test/atcoder/abc157_d.weightedunionfind.cpp.html
title: test/atcoder/abc157_d.weightedunionfind.cpp
---
