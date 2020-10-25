---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import yaml\n\nINPUT_YAML = r'lib.yml'\nOUTPUT_TEX = r'library.tex'\nHEADER\
    \ = r'''\\documentclass[a4paper,10pt,twocolumn,notitlepage]{article}\n\\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}\n\
    \\usepackage{setspace}\n\\usepackage{listings, jlisting}\n\\usepackage{colortbl}\n\
    \\usepackage{amsmath}\n\\usepackage{amsfonts}\n\\title{Library for Competitive\
    \ Programming}\n\\author{morio\\_\\_}\n\\lstset{\n    language=C++,\n    numbers=left,\n\
    \    breaklines=true,\n    basicstyle=\\tiny\\ttfamily,\n    commentstyle={\\\
    ttfamily \\color[cmyk]{1,0.4,1,0}},\n    keywordstyle={\\ttfamily \\color[cmyk]{0.3,0.9,0,0}},\n\
    \    stringstyle={\\ttfamily \\color[rgb]{0.8,0,0}},\n    frame=tlRB,\n    framesep=5pt,\n\
    \    linewidth=0.95\\linewidth,\n    xleftmargin=1.0cm\n}\n\\begin{document}\n\
    \\maketitle\n\\begin{spacing}{0}\n    \\tableofcontents\n\\end{spacing}\n'''\n\
    FOOTER = r'\\end{document}'\n\ndef isfile(file):\n    return all(i in file for\
    \ i in ['name', 'prefix', 'path'])\n\ndef texify_tag(tag, name):\n    return '\\\
    \\{}{{{}}}\\n'.format(tag, name)\n\ndef texify_file(file, sec):\n    return texify_tag(sec,\
    \ file['name']) + '\\\\lstinputlisting{{{}}}\\n'.format(file['path'])\n\nif __name__\
    \ == '__main__':\n    with open(INPUT_YAML, 'r') as lib, open(OUTPUT_TEX, 'w')\
    \ as tex:\n        tex.write(HEADER)\n        yml = yaml.load(lib, Loader=yaml.SafeLoader)\n\
    \        for sec, v_subsec in yml.items():\n            tex.write(texify_tag('section',\
    \ sec))\n            for subsec in v_subsec:\n                if isfile(subsec):\n\
    \                    tex.write(texify_file(subsec, 'subsection'))\n          \
    \      else:\n                    for subsec_name, v_subsubsec in subsec.items():\n\
    \                        tex.write(texify_tag('subsection', subsec_name))\n  \
    \                      for subsubsec in v_subsubsec:\n                       \
    \     tex.write(texify_file(subsubsec, 'subsubsection'))\n        tex.write(FOOTER)\n"
  dependsOn: []
  isVerificationFile: false
  path: generate_tex.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: generate_tex.py
layout: document
redirect_from:
- /library/generate_tex.py
- /library/generate_tex.py.html
title: generate_tex.py
---
