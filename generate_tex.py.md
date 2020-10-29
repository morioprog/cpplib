---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://dev.classmethod.jp/articles/pandoc-markdown2html/#toc-6
    - https://github.com/pandoc/pandoc-action-example
    - https://tex.stackexchange.com/questions/161549/scaling-inline-code-to-the-current-font-size/161551#161551
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 85, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import yaml\nimport os\nimport subprocess\n\nINPUT_YAML = r'lib.yml'\nOUTPUT_TEX\
    \ = r'library.tex'\nHEADER = r'''\\documentclass[a4paper,8pt,twocolumn,notitlepage]{article}\n\
    \\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}\n\
    \\usepackage{setspace}\n\\usepackage{listings, jlisting}\n\\usepackage{colortbl}\n\
    \\usepackage{amsmath}\n\\usepackage{amsfonts}\n\\usepackage{url}\n\\usepackage[dvipdfmx,\
    \ colorlinks=false]{hyperref}\n\\usepackage{pxjahyper}\n\\usepackage{xcolor}\n\
    \\usepackage{textcomp}\n\\title{Library for Competitive Programming}\n\\author{morio\\\
    _\\_}\n% https://tex.stackexchange.com/questions/161549/scaling-inline-code-to-the-current-font-size/161551#161551\n\
    \\makeatletter\n\\lstdefinestyle{mystyle}{\n  basicstyle=%\n    \\ttfamily\n \
    \   \\lst@ifdisplaystyle\\scriptsize\\fi\n}\n\\makeatother\n\\lstset{\n    language=C++,\n\
    \    numbers=left,\n    breaklines=true,\n    basicstyle=\\tiny\\ttfamily,\n \
    \   commentstyle={\\ttfamily \\color[cmyk]{1,0.4,1,0}},\n    keywordstyle={\\\
    ttfamily \\color[cmyk]{0.3,0.9,0,0}},\n    stringstyle={\\ttfamily \\color[rgb]{0.8,0,0}},\n\
    \    frame=tlRB,\n    framesep=5pt,\n    linewidth=0.95\\linewidth,\n    xleftmargin=1.0cm,\n\
    \    upquote=false,\n    style=mystyle\n}\n\\def\\tightlist{\\itemsep1pt\\parskip0pt\\\
    parsep0pt}\n\\newcommand{\\passthrough}[1]{\\lstset{mathescape=false}#1\\lstset{mathescape=true}}\n\
    \\begin{document}\n\\maketitle\n\\begin{spacing}{0}\n    \\tableofcontents\n\\\
    end{spacing}\n'''\nFOOTER = r'\\end{document}'\nPANDOC_COMMAND = \"docker run\
    \ --rm -v \\\"$(pwd):/data\\\" -u $(id -u):$(id -g) pandoc/latex -r markdown-auto_identifiers\
    \ --listings {md} -o {tex}\"\n\n\ndef isfile(file):\n    return all(i in file\
    \ for i in ['name', 'prefix', 'path'])\n\n\ndef texify_tag(tag, name):\n    return\
    \ '\\\\{}{{{}}}\\n'.format(tag, name)\n\n\ndef texify_file(file):\n    return\
    \ '\\\\lstinputlisting{{{}}}\\n'.format(file['path'])\n\n# https://dev.classmethod.jp/articles/pandoc-markdown2html/#toc-6\n\
    # https://github.com/pandoc/pandoc-action-example\n# docker run --rm --volume\
    \ \"$(pwd):/data\" --user $(id -u):$(id -g) pandoc/latex README.md -o README.pdf\n\
    \n\nif __name__ == '__main__':\n    with open(INPUT_YAML, 'r') as lib, open(OUTPUT_TEX,\
    \ 'w') as tex:\n        tex.write(HEADER)\n        yml = yaml.load(lib, Loader=yaml.SafeLoader)\n\
    \        for sec, v_subsec in yml.items():\n            tex.write(texify_tag('section',\
    \ sec))\n            for subsec in v_subsec:\n                if isfile(subsec):\n\
    \                    tex.write(texify_tag('subsection', subsec['name']))\n   \
    \                 subsec_base = \"docs/\" + \\\n                        subsec['path'][:-4]\
    \   # \u62E1\u5F35\u5B50(.hpp)\u3092\u9664\u304F\n                    subsec_md\
    \ = subsec_base + \".md\"\n                    subsec_tex = subsec_base + \".tex\"\
    \n                    if os.path.exists(subsec_md):\n                        subprocess.call(\n\
    \                            PANDOC_COMMAND.format(\n                        \
    \        md=subsec_md,\n                                tex=subsec_tex\n     \
    \                       ), shell=True)\n                        subprocess.call(\n\
    \                            r'sed -i -r \"s/\\\\\\\\subsubsection(.*)$/\\\\\\\
    \\paragraph*\\1\\\\\\\\mbox{}\\\\\\\\\\\\\\\\/g\" ' +\n                      \
    \      subsec_tex,\n                            shell=True\n                 \
    \       )\n                        subprocess.call(\n                        \
    \    r'sed -i -r \"s/\\\\\\\\subsection(.*)$/\\\\\\\\subsubsection*\\1/g\" ' +\n\
    \                            subsec_tex,\n                            shell=True\n\
    \                        )\n                        tex.write(\"\\\\input{{{}}}\\\
    n\".format(subsec_tex))\n                    tex.write(texify_file(subsec))\n\
    \                else:\n                    for subsec_name, v_subsubsec in subsec.items():\n\
    \                        tex.write(texify_tag('subsection', subsec_name))\n  \
    \                      for subsubsec in v_subsubsec:\n                       \
    \     tex.write(texify_tag(\n                                'subsubsection',\
    \ subsubsec['name']))\n                            subsubsec_base = \"docs/\"\
    \ + subsubsec['path'][:-4]\n                            subsubsec_md = subsubsec_base\
    \ + \".md\"\n                            subsubsec_tex = subsubsec_base + \".tex\"\
    \n                            if os.path.exists(subsubsec_md):\n             \
    \                   subprocess.call(\n                                    PANDOC_COMMAND.format(\n\
    \                                        md=subsubsec_md,\n                  \
    \                      tex=subsubsec_tex\n                                   \
    \ ), shell=True)\n                                subprocess.call(\n         \
    \                           r'sed -i -r \"s/\\\\\\\\subsubsection(.*)$/\\\\\\\\\
    subparagraph*\\1\\\\\\\\mbox{}\\\\\\\\\\\\\\\\/g\" ' +\n                     \
    \               subsubsec_tex,\n                                    shell=True\n\
    \                                )\n                                subprocess.call(\n\
    \                                    r'sed -i -r \"s/\\\\\\\\subsection(.*)$/\\\
    \\\\\\paragraph*\\1\\\\\\\\mbox{}\\\\\\\\\\\\\\\\/g\" ' +\n                  \
    \                  subsubsec_tex,\n                                    shell=True\n\
    \                                )\n                                tex.write(\n\
    \                                    \"\\\\input{{{}}}\\n\".format(subsubsec_tex))\n\
    \                            tex.write(texify_file(subsubsec))\n        tex.write(FOOTER)\n"
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
