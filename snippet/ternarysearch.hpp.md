---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E09\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"snippet/ternarysearch.hpp\"\n/**\n * @brief \u4E09\u5206\
    \u63A2\u7D22\n */\n\nusing T = double;\nauto f_trn = [&](T c) -> T {\n    $3\n\
    };\n\nT l = ${1:0}, r = ${2:1e9};\nfor (int _ = 0; _ < 100; ++_) {\n    T c1 =\
    \ (l * 2 + r) / 3;\n    T c2 = (l + r * 2) / 3;\n    if (f_trn(c1) > f_trn(c2))\
    \ l = c1;\n    else r = c2;\n}\n"
  code: "/**\n * @brief \u4E09\u5206\u63A2\u7D22\n */\n\nusing T = double;\nauto f_trn\
    \ = [&](T c) -> T {\n    $3\n};\n\nT l = ${1:0}, r = ${2:1e9};\nfor (int _ = 0;\
    \ _ < 100; ++_) {\n    T c1 = (l * 2 + r) / 3;\n    T c2 = (l + r * 2) / 3;\n\
    \    if (f_trn(c1) > f_trn(c2)) l = c1;\n    else r = c2;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: snippet/ternarysearch.hpp
  requiredBy: []
  timestamp: '2020-06-02 02:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/ternarysearch.hpp
layout: document
redirect_from:
- /library/snippet/ternarysearch.hpp
- /library/snippet/ternarysearch.hpp.html
title: "\u4E09\u5206\u63A2\u7D22"
---
