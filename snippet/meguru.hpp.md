---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u3081\u3050\u308B\u5F0F\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"snippet/meguru.hpp\"\n/**\n * @brief \u3081\u3050\u308B\u5F0F\
    \u4E8C\u5206\u63A2\u7D22\n */\n\nusing T = long long;\nauto check = [&](T mid)\
    \ -> bool {\n    $3\n};\n\nT ok = ${1:0}, ng = ${2:1e9};\n// for (int _ = 0; _\
    \ < 1000; ++_) {\nwhile (abs(ok - ng) > 1) {\n    T mid = (ok + ng) / 2;\n   \
    \ (check(mid) ? ok : ng) = mid;\n}\n"
  code: "/**\n * @brief \u3081\u3050\u308B\u5F0F\u4E8C\u5206\u63A2\u7D22\n */\n\n\
    using T = long long;\nauto check = [&](T mid) -> bool {\n    $3\n};\n\nT ok =\
    \ ${1:0}, ng = ${2:1e9};\n// for (int _ = 0; _ < 1000; ++_) {\nwhile (abs(ok -\
    \ ng) > 1) {\n    T mid = (ok + ng) / 2;\n    (check(mid) ? ok : ng) = mid;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: snippet/meguru.hpp
  requiredBy: []
  timestamp: '2020-06-02 02:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/meguru.hpp
layout: document
redirect_from:
- /library/snippet/meguru.hpp
- /library/snippet/meguru.hpp.html
title: "\u3081\u3050\u308B\u5F0F\u4E8C\u5206\u63A2\u7D22"
---
