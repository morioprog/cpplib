---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: generate_tex.py

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/generate_tex.py">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import yaml

INPUT_YAML = r'lib.yml'
OUTPUT_TEX = r'library.tex'
HEADER = r'''\documentclass[a4paper,10pt,onecolumn,notitlepage]{article}
\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}
\usepackage{setspace}
\usepackage{listings, jlisting}
\usepackage{colortbl}
\title{Library for Competitive Programming}
\author{morio\_\_}
\lstset{
    language=C++,
    numbers=left,
    breaklines=true,
    basicstyle=\tiny\ttfamily,
    commentstyle={\ttfamily \color[cmyk]{1,0.4,1,0}},
    keywordstyle={\ttfamily \color[cmyk]{0.3,0.9,0,0}},
    stringstyle={\ttfamily \color[rgb]{0.8,0,0}},
    frame=tlRB,
    framesep=5pt,
}
\begin{document}
\maketitle
\begin{spacing}{0}
    \tableofcontents
\end{spacing}
'''
FOOTER = r'\end{document}'

def isfile(file):
    return all(i in file for i in ['name', 'prefix', 'path'])

def texify_tag(tag, name):
    return '\\{}{{{}}}\n'.format(tag, name)

def texify_file(file, sec):
    return texify_tag(sec, file['name']) + '\\lstinputlisting{{{}}}\n'.format(file['path'])

if __name__ == '__main__':
    with open(INPUT_YAML, 'r') as lib, open(OUTPUT_TEX, 'w') as tex:
        tex.write(HEADER)
        yml = yaml.load(lib, Loader=yaml.SafeLoader)
        for sec, v_subsec in yml.items():
            tex.write(texify_tag('section', sec))
            for subsec in v_subsec:
                if isfile(subsec):
                    tex.write(texify_file(subsec, 'subsection'))
                else:
                    for subsec_name, v_subsubsec in subsec.items():
                        tex.write(texify_tag('subsection', subsec_name))
                        for subsubsec in v_subsubsec:
                            tex.write(texify_file(subsubsec, 'subsubsection'))
        tex.write(FOOTER)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py", line 84, in bundle
    raise NotImplementedError
NotImplementedError

```
{% endraw %}

<a href="../index.html">Back to top page</a>

