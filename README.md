# AtCoder用開発環境

## ログイン確認
```bash
# ダウンロードの確認
acc check-oj
# accのログイン
acc login
# ojのログイン
oj login https://beta.atcoder.jp
```

## 問題データのダウンロード

1. TASK RUNNER->abc_dl or arc_dl
2. コンテスト名を入力(abc### or arc###)
3. `src/atcoder/abc/abc###` or `src/atcoder/arc/arc###`にテストデータと回答用cppファイルが作成される

## テストデータの実行

1. TASK RUNNER->test
2. テストデータが実行される

## 提出

1. 提出するファイルを開いた状態でTASK RUNNER->submit
2. 結果はAtCoderサイトの提出結果ページで確認できる
