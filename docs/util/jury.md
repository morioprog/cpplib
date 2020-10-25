## 概要

インタラクティブ問題の大枠.

## 使用例

* `auto jury = Jury<int, bool, 20>()` : Juryを準備.
  * `jury.query(n)` : 質問クエリ.
  * `jury.answer(x)` : 解答クエリ.
    * 実行したら`exit(0)`で終了するようにするべき.
