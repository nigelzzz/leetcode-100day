# Google Interview Coach

這個目錄是 Hermes 長期演算法面試教練的資料來源。

## 核心規則

- 說明使用繁體中文，程式碼使用 C++17。
- 前 25–30 分鐘不提供完整解法或實作。
- 每題依序練習 Clarify → Brute force → Optimize → Coding → Testing → Review → Retell。
- 每次至少說明時間／空間複雜度並提出三個 edge cases。
- 錯誤依 1、3、7、21 天間隔複習。
- Claude Code 負責教學與溝通評估；Codex 負責編譯、測試、找 bug 與 code review；兩者只能在本人完成嘗試或明確放棄後介入完整解答。

## 目錄

- `profile.yaml`：目標、偏好、弱點摘要與課程設定。
- `mistakes.yaml`：錯題及待複習日期的唯一正式紀錄。
- `sessions/`：每日 Lab、Mock 與評分紀錄。
- `solutions/`：本人寫的 C++ 解答。
- `templates/session-log.yaml`：每次訓練完成後使用的紀錄模板。

## 使用方式

1. 收到每日 Lab 後，在目前 Hermes 對話開始作答。
2. 要提示時只說「提示 1／2／3」；除非明確說放棄，教練不應揭露完整解法。
3. 將程式碼存到 `solutions/<leetcode-number>.cpp`。
4. 完成後請 Hermes 執行 Claude 教學 review 與 Codex 測試／code review。
5. Hermes 更新 `mistakes.yaml`、`profile.yaml`，並在 `sessions/` 新增紀錄。

排程時區：Asia/Taipei。
