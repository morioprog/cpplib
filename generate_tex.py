import yaml

INPUT_YAML = r'lib.yml'
OUTPUT_TEX = r'library.tex'
HEADER = r'''\documentclass[a4paper,10pt,twocolumn,notitlepage]{article}
\usepackage[top=10truemm,bottom=15truemm,left=10truemm,right=10truemm]{geometry}
\usepackage{setspace}
\usepackage{listings, jlisting}
\usepackage{colortbl}
\usepackage{amsmath}
\usepackage{amsfonts}
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
    %linewidth=0.95\linewidth,
    xleftmargin=1.0cm
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
