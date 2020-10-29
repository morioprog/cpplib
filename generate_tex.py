import yaml
import os
import subprocess

INPUT_YAML = r'lib.yml'
OUTPUT_TEX = r'library.tex'
HEADER = r'''\documentclass[8pt,a4paper,10pt,twocolumn,notitlepage]{article}
\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}
\usepackage{setspace}
\usepackage{listings, jlisting}
\usepackage{colortbl}
\usepackage{amsmath}
\usepackage{amsfonts}
\usepackage{url}
\usepackage[dvipdfmx, colorlinks=false]{hyperref}
\usepackage{pxjahyper}
\usepackage{xcolor}
\usepackage{textcomp}
\title{Library for Competitive Programming}
\author{morio\_\_}
% https://tex.stackexchange.com/questions/161549/scaling-inline-code-to-the-current-font-size/161551#161551
\makeatletter
\lstdefinestyle{mystyle}{
  basicstyle=%
    \ttfamily
    \lst@ifdisplaystyle\scriptsize\fi
}
\makeatother
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
    linewidth=0.95\linewidth,
    xleftmargin=1.0cm,
    upquote=false,
    style=mystyle
}
\def\tightlist{\itemsep1pt\parskip0pt\parsep0pt}
\newcommand{\passthrough}[1]{\lstset{mathescape=false}#1\lstset{mathescape=true}}
\begin{document}
\maketitle
\begin{spacing}{0}
    \tableofcontents
\end{spacing}
'''
FOOTER = r'\end{document}'
PANDOC_COMMAND = "docker run --rm -v \"$(pwd):/data\" -u $(id -u):$(id -g) pandoc/latex -r markdown-auto_identifiers --listings {md} -o {tex}"


def isfile(file):
    return all(i in file for i in ['name', 'prefix', 'path'])


def texify_tag(tag, name):
    return '\\{}{{{}}}\n'.format(tag, name)


def texify_file(file):
    return '\\lstinputlisting{{{}}}\n'.format(file['path'])

# https://dev.classmethod.jp/articles/pandoc-markdown2html/#toc-6
# https://github.com/pandoc/pandoc-action-example
# docker run --rm --volume "$(pwd):/data" --user $(id -u):$(id -g) pandoc/latex README.md -o README.pdf


if __name__ == '__main__':
    with open(INPUT_YAML, 'r') as lib, open(OUTPUT_TEX, 'w') as tex:
        tex.write(HEADER)
        yml = yaml.load(lib, Loader=yaml.SafeLoader)
        for sec, v_subsec in yml.items():
            tex.write(texify_tag('section', sec))
            for subsec in v_subsec:
                if isfile(subsec):
                    tex.write(texify_tag('subsection', subsec['name']))
                    subsec_base = "docs/" + \
                        subsec['path'][:-4]   # 拡張子(.hpp)を除く
                    subsec_md = subsec_base + ".md"
                    subsec_tex = subsec_base + ".tex"
                    if os.path.exists(subsec_md):
                        subprocess.call(
                            PANDOC_COMMAND.format(
                                md=subsec_md,
                                tex=subsec_tex
                            ), shell=True)
                        subprocess.call(
                            r'sed -i -r "s/\\\\subsubsection(.*)$/\\\\paragraph*\1\\\\mbox{}\\\\\\\\/g" ' +
                            subsec_tex,
                            shell=True
                        )
                        subprocess.call(
                            r'sed -i -r "s/\\\\subsection(.*)$/\\\\subsubsection*\1/g" ' +
                            subsec_tex,
                            shell=True
                        )
                        tex.write("\\input{{{}}}\n".format(subsec_tex))
                    tex.write(texify_file(subsec))
                else:
                    for subsec_name, v_subsubsec in subsec.items():
                        tex.write(texify_tag('subsection', subsec_name))
                        for subsubsec in v_subsubsec:
                            tex.write(texify_tag(
                                'subsubsection', subsubsec['name']))
                            subsubsec_base = "docs/" + subsubsec['path'][:-4]
                            subsubsec_md = subsubsec_base + ".md"
                            subsubsec_tex = subsubsec_base + ".tex"
                            if os.path.exists(subsubsec_md):
                                subprocess.call(
                                    PANDOC_COMMAND.format(
                                        md=subsubsec_md,
                                        tex=subsubsec_tex
                                    ), shell=True)
                                subprocess.call(
                                    r'sed -i -r "s/\\\\subsubsection(.*)$/\\\\subparagraph*\1\\\\mbox{}\\\\\\\\/g" ' +
                                    subsubsec_tex,
                                    shell=True
                                )
                                subprocess.call(
                                    r'sed -i -r "s/\\\\subsection(.*)$/\\\\paragraph*\1\\\\mbox{}\\\\\\\\/g" ' +
                                    subsubsec_tex,
                                    shell=True
                                )
                                tex.write(
                                    "\\input{{{}}}\n".format(subsubsec_tex))
                            tex.write(texify_file(subsubsec))
        tex.write(FOOTER)
