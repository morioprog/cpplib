# cpplib

[![verify](https://github.com/morioprog/cpplib/workflows/verify/badge.svg?branch=master)](https://github.com/morioprog/cpplib/actions?query=workflow%3Averify+branch%3Amaster)
[![makepdf](https://github.com/morioprog/cpplib/workflows/makepdf/badge.svg)](https://github.com/morioprog/cpplib/actions?query=workflow%3Amakepdf+branch%3Amaster)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://morioprog.github.io/cpplib/)

競プロのライブラリ

## ライブラリ追加手順

1. ライブラリ本体(`<PATH>.hpp`)を追加

    コード冒頭にこれを書く.

    ```cpp
    /**
    * @brief <LIBRARY NAME>
    * @docs docs/<PATH>.md
    */
    ```

1. `docs/<PATH>.md`を作成

    ```md
    ## 概要

    ## 計算量

    ## 使用例

    ```

1. `lib.yml`に追記

    ```yml
    セクション名:
      - name: セクション直下に配置するライブラリ
        prefix: [VSCodeでスニペットを呼び出すためのprefix]
        path: ライブラリへのパス
      - サブセクション名:
        - name: サブセクション直下に配置するライブラリ
          prefix: [...]
          path: ...
    ```

1. `test/*.test.cpp`を作成

    ```cpp
    #define PROBLEM "..."

    #include "../../template/main.hpp"
    #include "../../..."

    signed main() {



    }
    ```
