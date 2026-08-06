# 常用技巧與資料結構：Google 面試代表題路線

主要來源：靈茶山艾府〈常用資料結構題單〉

來源：https://leetcode.cn/discuss/post/3583665/fen-xiang-gun-ti-dan-chang-yong-shu-ju-j-bvmv/

定位：這是目前「滑動窗口與雙指針」主線完成後的擴充路線。原始題單作為查漏補缺的題庫，不按數百題順序逐題完成；每個模組先掌握 3–6 題代表題，再依錯題紀錄決定是否加練。

完成狀態仍只以 `profile.yaml`、`mistakes.yaml` 與 `sessions/` 中實際觀察到的作答為準。

## Phase A：枚舉、前綴和與 Hash Map

建議順序：

1. 1 — Two Sum
2. 121 — Best Time to Buy and Sell Stock
3. 1014 — Best Sightseeing Pair
4. 560 — Subarray Sum Equals K
5. 974 — Subarray Sums Divisible by K
6. 525 — Contiguous Array
7. 304 — Range Sum Query 2D — Immutable
8. 1074 — Number of Submatrices That Sum to Target

核心能力：

- 「枚舉右，維護左」：處理右端點前，資料結構只代表左側已看過的狀態。
- 分清查詢與插入順序，避免把當前元素錯當成自己的搭配對象。
- 把子陣列條件改寫為兩個前綴狀態之差。
- 說明 `cnt[0] = 1` 代表的空前綴。
- 將一維前綴和方法遷移到二維矩陣。

通關門檻：能從暴力枚舉所有區間，推導到「枚舉右端點 + 查找所需左前綴」，並準確說明 invariant。

## Phase B：Stack、解析與單調結構

建議順序：

1. 20 — Valid Parentheses
2. 155 — Min Stack
3. 394 — Decode String
4. 735 — Asteroid Collision
5. 239 — Sliding Window Maximum
6. 862 — Shortest Subarray with Sum at Least K

核心能力：

- 說清 stack 內每個元素的語意，而不只是背模板。
- 區分「相鄰消除」、「巢狀解析」與「維護候選答案」三種使用情境。
- 單調 deque 中保存下標，並同時處理過期與支配關係。

## Phase C：Heap 與動態 Top-K

建議順序：

1. 703 — Kth Largest Element in a Stream
2. 23 — Merge k Sorted Lists
3. 253 — Meeting Rooms II（若可使用會員題；否則改做 2406）
4. 621 — Task Scheduler
5. 295 — Find Median from Data Stream
6. 480 — Sliding Window Median

核心能力：

- 知道為何 heap 大小應限制在 `k`，以及 heap top 代表什麼。
- 分清「同時存在的最小資源數」、「事件排序」與「動態第 K 大」。
- 能解釋雙 heap 的分區 invariant，以及 lazy deletion 的必要性。

## Phase D：Trie 與位元 Trie

建議順序：

1. 208 — Implement Trie
2. 211 — Design Add and Search Words Data Structure
3. 212 — Word Search II
4. 3043 — Find the Length of the Longest Common Prefix
5. 421 — Maximum XOR of Two Numbers in an Array

核心能力：

- Trie node、edge、terminal flag 的精確語意。
- 能分析複雜度應以字串總長度，而非單純字串數量表示。
- 在 XOR Trie 中逐位選擇相反 bit，並說明貪心正確性。

## Phase E：Disjoint Set Union

建議順序：

1. 684 — Redundant Connection
2. 990 — Satisfiability of Equality Equations
3. 721 — Accounts Merge
4. 1202 — Smallest String With Swaps
5. 399 — Evaluate Division（帶權並查集延伸）

核心能力：

- `find`、path compression、union by size/rank。
- 分清節點、集合代表元與集合附加資訊。
- 能辨識「動態合併等價類」而不是把所有圖題都硬套 DSU。

## Phase F：Fenwick Tree、Segment Tree 與離線查詢

建議順序：

1. 307 — Range Sum Query — Mutable
2. 315 — Count of Smaller Numbers After Self
3. 493 — Reverse Pairs
4. 2407 — Longest Increasing Subsequence II
5. 3165 — Maximum Sum of Subsequence With Non-adjacent Elements

核心能力：

- 從 prefix query + point update 推導 Fenwick Tree。
- 理解離散化只改變順序表示，不改變大小關係。
- Segment Tree node 必須保存可結合（merge）的區間資訊。
- 先定義 merge invariant，再寫 build、query、update。

## Phase G：差分、掃描線與區間事件

建議順序：

1. 1094 — Car Pooling
2. 1109 — Corporate Flight Bookings
3. 56 — Merge Intervals
4. 2406 — Divide Intervals Into Minimum Number of Groups
5. 850 — Rectangle Area II

核心能力：

- 將區間更新轉為端點事件，再用前綴累積還原狀態。
- 明確處理閉區間與半開區間。
- 掃描線中分開處理事件排序、活躍集合與相鄰座標寬度。

## Phase H：綜合設計題

建議順序：

1. 146 — LRU Cache
2. 460 — LFU Cache
3. 432 — All O(1) Data Structure
4. 1206 — Design Skiplist

核心能力：

- 先列出每個 API 的目標複雜度。
- 用 invariant 解釋多個資料結構如何同步。
- 對 iterator、刪除、容量為零、相同頻率與更新既有 key 做邊界測試。

## 每題訓練流程

1. Clarify：確認輸入、輸出、限制與可否修改輸入。
2. Brute force：提出可工作的直接解法與精確複雜度。
3. Bottleneck：指出重複計算或昂貴操作。
4. Invariant：一句話定義資料結構在每輪代表什麼。
5. Implement：使用 C++17 獨立完成。
6. Test：至少 normal、boundary、adversarial 三類案例。
7. Retell：不用看程式，在兩分鐘內重述推導與複雜度。

## 選題規則

- 一次只安排一題主題題，外加至多一題 follow-up variation。
- 優先複習 `mistakes.yaml` 中到期或重複出錯的概念。
- 同一模組若兩題能獨立完成並清楚證明 invariant，可跳過相似基礎題。
- 若仍需 Hint 2 以上，先做同模板的較小變形，不急著進入高難題。
- 不因讀過題解、排入日程或使用者曾看過題目而標記完成。
