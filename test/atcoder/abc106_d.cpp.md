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
  bundledCode: "#line 1 \"test/atcoder/abc106_d.cpp\"\n#define IGNORE\n\n// #define\
    \ PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\n\n// #include\
    \ \"../../template/main.hpp\"\n// #include \"../../datastructure/cumulativesum/cumulativesum2d.hpp\"\
    \n\nsigned main() {\n \n    int N, M, Q;\n    cin >> N >> M >> Q;\n \n    vector<vector<int>>\
    \ v(N + 1, vector<int>(N + 1, 0));\n    while (M--) {\n        int L, R;\n   \
    \     cin >> L >> R;\n        v[L][R]++;\n    }\n \n    CumulativeSum2D<int> acc(v);\n\
    \ \n    while (Q--) {\n        int p, q;\n        cin >> p >> q;\n        print(acc.query(p,\
    \ p, q + 1, q + 1));\n    }\n \n}\n"
  code: "#define IGNORE\n\n// #define PROBLEM \"https://atcoder.jp/contests/abc106/tasks/abc106_d\"\
    \n\n// #include \"../../template/main.hpp\"\n// #include \"../../datastructure/cumulativesum/cumulativesum2d.hpp\"\
    \n\nsigned main() {\n \n    int N, M, Q;\n    cin >> N >> M >> Q;\n \n    vector<vector<int>>\
    \ v(N + 1, vector<int>(N + 1, 0));\n    while (M--) {\n        int L, R;\n   \
    \     cin >> L >> R;\n        v[L][R]++;\n    }\n \n    CumulativeSum2D<int> acc(v);\n\
    \ \n    while (Q--) {\n        int p, q;\n        cin >> p >> q;\n        print(acc.query(p,\
    \ p, q + 1, q + 1));\n    }\n \n}\n"
  dependsOn: []
  isVerificationFile: false
  path: test/atcoder/abc106_d.cpp
  requiredBy: []
  timestamp: '2020-04-23 01:10:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc106_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc106_d.cpp
- /library/test/atcoder/abc106_d.cpp.html
title: test/atcoder/abc106_d.cpp
---
